#include <QDebug>
#include <QString>
#include "interlang.h"

std::string InterLang::rPolishExpress = "";
std::string InterLang::PolishExpress = "";
std::vector<std::string> InterLang::rPolishList;
std::stack<std::string> InterLang::TACStack;
std::vector<InterLang::TAC> InterLang::TACList;

bool InterLang::isOperator(char input) {
    return  (input == '+' || input == '-' || input == '*' || input == '/' || input == '%');
}

void InterLang::constructTAC() {
    for (unsigned int i = 0; i < rPolishList.size(); i++) {
        // 是数字或常量
        if (isdigit(rPolishList[i][0]) || rPolishList[i][0] == '.' || rPolishList[i] == "PI" || rPolishList[i][0] == 'e') {
            TACStack.push(rPolishList[i]);
        }
        // 是双目运算符
        else if (isOperator(rPolishList[i][0])) {
            std::string z = TACStack.top(); TACStack.pop();
            std::string y = TACStack.top(); TACStack.pop();
            TAC t;
            t.op = rPolishList[i][0], t.y = y, t.z = z, t.x = "T" + std::to_string(InterLang::TACList.size() + 1);
            InterLang::TACList.push_back(t);
            TACStack.push(t.x);
        }
        // 是括号
        else if (rPolishList[i][0] == '(' || rPolishList[i][0] == ')') {
            continue;
        }
        // 是函数
        else {
            std::string y = TACStack.top(); TACStack.pop();
            TAC t;
            t.op = rPolishList[i], t.y = y, t.x = "T" + std::to_string(InterLang::TACList.size() + 1);
            InterLang::TACList.push_back(t);
            TACStack.push(t.x);
        }
    }
    InterLang::PolishExpress = getTx(InterLang::TACList.size());
}

std::string InterLang::getTx(int idx) {
    std::string str = "";
    std::string x = "T" + std::to_string(idx);
    for (auto& ele : InterLang::TACList) {
        if (ele.x == x) {
            str += ele.op + " ";
            if (ele.y[0] == 'T' && ele.z[0] == 'T') {
                str += getTx(ele.y[1] - '0') + getTx(ele.z[1] - '0');
            } else if (ele.y[0] == 'T' && ele.z[0] != 'T') {
                str += getTx(ele.y[1] - '0');
                if (ele.z != "null") str += ele.z + " ";
            } else if (ele.y[0] != 'T' && ele.z[0] == 'T') {
                if (ele.y != "null") str += ele.y + " ";
                str += getTx(ele.z[1] - '0');
            } else {
                if (ele.y != "null") str += ele.y + " ";
                if (ele.z != "null") str += ele.z + " ";
            }
            break;
        }
    }
    return str;
}

QString InterLang::getTACtext(InterLang::TAC& t) {
    QString TACtext = "(" + QString::fromStdString(t.op) + ", " + QString::fromStdString(t.y) + ", " + QString::fromStdString(t.z) + ", " + QString::fromStdString(t.x) + ")";
    return TACtext;
}
