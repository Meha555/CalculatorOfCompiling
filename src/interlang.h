#ifndef INTERLANG_H
#define INTERLANG_H

#include <QString>
#include <stack>
#include <string>
#include <vector>
#include "token.h"

namespace InterLang {

// 三地址码类型 (op, y, z, x)
struct TAC {
    std::string op, y, z, x;
    TAC() { op = y = z = x = "null"; }
};

extern std::string rPolishExpress;            // 逆波兰式
extern std::string PolishExpress;             // 前缀表达式
extern std::vector<std::string> rPolishList;  // 符号栈
extern std::stack<std::string> TACStack;      // 三地址码栈
extern std::vector<InterLang::TAC> TACList;   // 三地址码列表
void constructTAC();   // 构造三地址码列表
QString getTACtext(InterLang::TAC&);
std::string getTx(int);
bool isOperator(char);

}  // namespace InterLang

#endif  // INTERLANG_H
