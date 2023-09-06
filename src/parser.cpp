#include <QDebug>
#include <sstream>
#include "error.h"
#include "interlang.h"
#include "parser.h"
#include "token.h"

bool isNegative = false;

/// @brief 解析并计算因子的值(对应文法9/10/11/12/13/14)
/// @param input输入串
/// @return 数值和剩余输入串
std::tuple<double, std::string> parseFactor(std::string input) {
    std::stringstream sstr;  // 为了处理浮点数和整数的输出
    Token tk;                // 当前因子的token
    // 解析并打包第一个token
    std::tie(tk, input) = tokenize(input);
    qDebug() << "parseFactor->tokenize: " << QString::fromStdString(input);
    double val = 0;  // 因子的数值
    // 根据种别码来解析单词的属性值，F -> num | fun(E) | PI | e
    switch (tk.type) {
        // 是数字，F -> num
        case TokenType::Number:
            val = std::get<double>(tk.value);
            sstr << val;
            InterLang::rPolishExpress += sstr.str() + " ";          //============逆波兰式============
            InterLang::rPolishList.emplace_back(sstr.str());  //============符号栈============
            sstr.clear();
            break;
        // 是符号，F -> fun(E) | PI | e
        case TokenType::Symbo: {  // 先搜索符号是否在符号表中有定义(是否是保留字)
            std::string sym = std::get<std::string>(tk.value);
            auto search = findSymboValue(sym);

            if (search != std::nullopt) {  // 如果查找到了
                // 情况1: symbo是常量(数字常量PI和e)，此时val等于symbo对应的常量数值
                if (std::holds_alternative<double>(search.value())) {
                    val = std::get<double>(search.value());    // 返回数字常量的值
                    InterLang::rPolishExpress += sym + " ";          //============逆波兰式============
                    InterLang::rPolishList.emplace_back(sym);  //============符号栈============
                }
                // 情况2: symbo是函数(sin(x)、sqrt(x)这样的)，此时是F -> fun(E)
                // 继续解析(E)并把解析出来的E作为symbo对应的函数参数
                // 并把函数计算出来的值赋给val
                else {
                    // 获取函数对象
                    auto fun = std::get<FunType>(search.value());
                    // 解析"("
                    std::tie(tk, input) = tokenize(input);
                    qDebug() << "parseFactor->tokenize: " << QString::fromStdString(input);
                    if (tk.type != TokenType::Lp) {
                        error(8);
                    }
                    // 解析表达式E
                    double v;
                    std::tie(v, input) = parseExpress(input);
                    qDebug() << "parseFactor->parseExpress: " << QString::fromStdString(input);
                    if (sym == "sqrt" && v < 0) {
                        error(4);
                    }
                    if ((sym == "log" || sym == "ln") && (v <= 0 || v == 1)) {
                        error(6);
                    }
                    // 解析")"
                    std::tie(tk, input) = tokenize(input);
                    qDebug() << "parseFactor->tokenize: " << QString::fromStdString(input);
                    if (tk.type != TokenType::Rp) {
                        error(9);
                    }
                    InterLang::rPolishExpress += sym + " ";          //============逆波兰式============
                    InterLang::rPolishList.emplace_back(sym);  //============符号栈============
                    val = fun(v);  // 保存函数运算结果的值
                }
            }
            // 找不到符号抛出异常
            else {
                errMessage = "错误: 存在未定义或非法符号 " + std::get<std::string>(tk.value) + "\n";
                error(12);
            }
            break;
        }
        // 是左括号"("，对应(1+3)这种情况: F -> (E)
        case TokenType::Lp:
            // 解析(E)里的E
            std::tie(val, input) = parseExpress(input);
            qDebug() << "parseFactor->parseExpress: " << QString::fromStdString(input);
            // 再解析一个")"
            std::tie(tk, input) = tokenize(input);
            qDebug() << "parseFactor->tokenize: " << QString::fromStdString(input);
            // 如果解析出来的不是")"则说明输入的这个表达式有错
            if (tk.type != TokenType::Rp) {
                error(9);
            }
            break;
//        case TokenType::Nul:
//            qDebug()<<"推出ε"<<endl;
//            break;
        // 都不是
        default:
            error(7);
            break;
    }
    return {val, input};  // 返回因子的解析结果
}

/// @brief 解析并计算项的值(对应文法4/5/6/7/8)
/// @param input输入串
/// @return 数值和剩余输入串
std::tuple<double, std::string> parseTerm(std::string input) {
    double val = 0;  // 项的数值
    // 翻译T -> FT'中的F
    std::tie(val, input) = parseFactor(input);
    qDebug() << "parseTerm->parseFactor: " << QString::fromStdString(input);

    // 翻译T -> FT'中的T'
    bool loop = true;
    while (loop) {
        Token op;
        std::string res;
        double term;
        // 翻译T' -> *FT' | /FT' | %FT' | ε 的第一个符号的token，即*|/|%|ε
        std::tie(op, res) = tokenize(input);
        qDebug() << "parseTerm->tokenize: " << QString::fromStdString(res);

        switch (op.type) {
            // 如果是*号
            case TokenType::Mul:
                // 解析*FT'中的F
                std::tie(term, input) = parseFactor(res);
                qDebug() << "parseTerm->parseFactor: " << QString::fromStdString(input);
                // 根据乘法的语义更新val的数值
                val *= term;
                InterLang::rPolishExpress += "* ";          //============逆波兰式============
                InterLang::rPolishList.emplace_back("*");  //============符号栈============
                break;
                // 如果是/号
            case TokenType::Div:
                // 解析/FT'H中的F
                std::tie(term, input) = parseFactor(res);
                qDebug() << "parseTerm->parseFactor: " << QString::fromStdString(input);
                if (term == 0.0) {  // 除数不能为0
                    error(4);
                }
                // 根据除法的语义更新val的数值
                val /= term;
                InterLang::rPolishExpress += "/ ";          //============逆波兰式============
                InterLang::rPolishList.emplace_back("/");  //============符号栈============
                break;
                //如果是%号
            case TokenType::Mod:
                std::tie(term, input) = parseFactor(res);
                if (term == 0.0) {  // 除数不能为0
                    error(4);
                }
                val = (int)val % (int)term;
                InterLang::rPolishExpress += "% ";          //============逆波兰式============
                InterLang::rPolishList.emplace_back("%");  //============符号栈============
                break;
            case TokenType::Lp:error(2);break;
            case TokenType::Symbo:error(11);break;
                // 如果都不是
            default:
                loop = false;
                break;
        }
    }
    return {val, input};  // 返回项的解析结果
}

/// @brief 解析并计算表达式的值(对应文法0/1/2/3)
/// @param input输入串
/// @return 数值和剩余输入串
std::tuple<double, std::string> parseExpress(std::string input) {
    double val = 0;  // 当前表达式的数值
    // 翻译E -> TE'中的T
    std::tie(val, input) = parseTerm(input);
    qDebug() << "parseExpress->parseTerm: " << QString::fromStdString(input);
    // 翻译E -> TE'中的E'
    bool loop = true;
    while (loop) {
        Token op;
        std::string res;
        double term;
        // 翻译E' -> +TE' | -TE' | ε 的第一个符号的token，即+|-|ε
        std::tie(op, res) = tokenize(input);
        qDebug() << "parseExpress->tokenize: " << QString::fromStdString(res);
        switch (op.type) {
            // 如果是+号
            case TokenType::Plus:
                // 解析+TE'中的T
                std::tie(term, input) = parseTerm(res);
                qDebug() << "parseExpress->parseTerm: " << QString::fromStdString(input);
                // 根据加法的语义更新val的数值
                val += term;
                InterLang::rPolishExpress += "+ ";          //============逆波兰式============
                InterLang::rPolishList.emplace_back("+");  //============符号栈============
                break;
                // 如果是-号，可能是负号
            case TokenType::Minus:
                //                isNegative = true;
                // 解析-TE'中的T
                std::tie(term, input) = parseTerm(res);
                qDebug() << "parseExpress->parseTerm: " << QString::fromStdString(input);
                // 根据减法的语义更新val的数值
                val -= term;
                InterLang::rPolishExpress += "- ";          //============逆波兰式============
                InterLang::rPolishList.emplace_back("-");  //============符号栈============
                break;
            case TokenType::Lp:error(2);break;
            case TokenType::Symbo:error(11);break;
                // 如果都不是
            default:
                // 退出循环
                loop = false;
                break;
        }
    }
    return {val, input};  // 返回表达式的解析结果
}
