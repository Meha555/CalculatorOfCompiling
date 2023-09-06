#ifndef PARSER_H
#define PARSER_H

#include <QWidget>
#include <string>
#include <tuple>
/*
 * 文法G[E]：
 * E->TE'                    (0)
 * E'->+TE'|-TE'|ε           (1/2/3)
 * T->FT'                    (4)
 * T'->*FT'|/FT'|%FT'|ε      (5/6/7/8)
 * F->(E)|fun(E)|num|PI|e|ε  (9/10/11/12/13/14)
 */

//解析是逐个解析 所以返回还是用tuple来返回多个值(token)

/// @brief 解析并计算因子的值(对应文法9/10/11/12/13/14)
/// @param input输入串
/// @return 数值和剩余输入串
std::tuple<double, std::string> parseFactor(std::string input);

/// @brief 解析并计算项的值(对应文法4/5/6/7/8)
/// @param input输入串
/// @return 数值和剩余输入串
std::tuple<double, std::string> parseTerm(std::string input);

/// @brief 解析并计算表达式的值(对应文法0/1/2/3)
/// @param input输入串
/// @return 数值和剩余输入串
std::tuple<double, std::string> parseExpress(std::string input);

extern bool isNegative; // 标记负数

#endif  // PARSER_H
