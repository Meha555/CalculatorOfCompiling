#include <QDebug>
#include <QtMath>
#include "error.h"
#include "mainwindow.h"
#include "token.h"

/* 符号表(非数字就是符号)
 * 索引值是string
 * 值为variant：数值 或 函数
 */
static std::unordered_map<std::string, std::variant<double, FunType>> SymboTab{
    {"PI", M_PI},                                     // 常量
    {"e", M_E},                                       // 常量
    {"sin", [](double val) { return sin(val); }},     // 函数
    {"cos", [](double val) { return cos(val); }},     // 函数
    {"tan", [](double val) { return tan(val); }},     // 函数
    {"log", [](double val) { return log10(val); }},   // 函数
    {"ln", [](double val) { return log(val); }},      // 函数
    {"sqrt", [](double val) { return sqrt(val); }},   // 函数
    {"pow", [](double val) { return pow(val, 2); }},  // 函数
};

/// @brief 解析符号(符号常量和函数)
/// @param input输入串
/// @return 符号和剩余输入串
static std::tuple<std::string, std::string> parseSymbo(std::string input) {
    std::string symbo;
    while (1) {
        // 输入字符串到头了，退出死循环
        if (input.empty()) {
            break;
        }
        // 得到第一个字符
        char ch = input.front();
        if (isalpha(ch)) {  // 如果是字母
            symbo.push_back(ch);
            input.erase(input.begin());  // 在输入串中删除已经读入的字母
        } else {
            break;
        }
    }
    return {symbo, input};
}

/// @brief 解析数字
/// @param input输入串
/// @return 数值和剩余输入串
static std::tuple<double, std::string> parseNumber(std::string input) {
    std::string numstr;
    bool firstDot = true;  // 表示第一次遇到小数点(避免1.2.3这种情况)

    while (1) {
        if (input.empty()) {
            break;
        }
        char ch = input.front();

        // 如果是数字或第一次出现的小数点，那么就读入
        if (/*(ch >= '0' && ch <= '9')*/ isdigit(ch) || (ch == '.' && firstDot == true)) {
            numstr.push_back(ch);
            input.erase(input.begin());  // 在输入字符串中删除已经读入的数字或"."
            if (ch == '.') {             // 更新firstDot标记
                firstDot = false;
            }
        } else {
            break;
        }
    }
    // stod用于将字符转化为数字
    return {std::stod(numstr), input};
}

/// @brief 查找符号在符号表中的具体定义，返回token的属性(数值或函数)
/// @param symbo名称
/// @return 数值 或 函数
std::optional<std::variant<double, FunType>> findSymboValue(std::string symbo) {
    if (auto iter = SymboTab.find(symbo); iter != SymboTab.end()) {
        // 返回它的具体取值
        return {iter->second};  // 查找到了，返回token的属性
    }
    return std::nullopt;  // 没有查找到，返回空，等同于{}
}

/// @brief 为单词生成token(种别码,属性值)并返回该token和剩余输入串
/// @param input
/// @return token和剩余输入串
std::tuple<Token, std::string> tokenize(std::string input) {
    Token tk;
    char ch;
    do {
    if (input.empty()) {  // 输入为空
        tk.type = TokenType::Nul;
        return {tk, ""};
    } else {
        // 拿到输入串input最开头的字符
        ch = input.front();  // 取最前面的字符
        // 并且把这个字符从input的开头去掉，表示已经读取掉了
        input.erase(input.begin());
        qDebug() << "tokenize->拿到输入串最开头的字符: " << ch;
    }
    } while (ch == ' ');

    // 根据第一个非空格的字符生产相应的token用于返回
    switch (ch) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '(':
        case ')':
            tk.type = TokenType(ch);
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            tk.type = TokenType::Number;
            // 把ch重新添加到input的开头
            // 比如开头为1.0
            input.insert(input.begin(), ch);
            // 把这个字符串中的数字变成真正的数值
            std::tie(tk.value, input) = parseNumber(input);
            qDebug() << "tokenize->parseNumber: " << QString::fromStdString(input);
            break;
        default:
            // 判断是否是a-z,A-Z的字符
            if (isalpha(ch)) {
                tk.type = TokenType::Symbo;
                // 把ch重新添加到input的开头
                input.insert(input.begin(), ch);
                // 解析出这个symbo
                std::tie(tk.value, input) = parseSymbo(input);
                qDebug() << "tokenize->parseSymbo: " << QString::fromStdString(input);
            } else {
                error(1);
            }
            break;
    }
    return {tk, input};
}
