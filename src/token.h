#ifndef TOKEN_H
#define TOKEN_H

#include <QWidget>
#include <functional>
#include <optional>
#include <stdexcept>
#include <string>
#include <tuple>
#include <unordered_map>
#include <variant>

enum class TokenType {
    Number,  // 数字，包括0~9的数字
    Symbo,   // 符号，英文字母a-z,A-Z，包括PI、e、函数
    Nul,     // 空
    Neg,     // 负号
    Plus = '+',
    Minus = '-',
    Mul = '*',
    Div = '/',
    Mod = '%',
    Lp = '(',
    Rp = ')',
};

// 定义token结构体
struct Token {
    TokenType type = TokenType::Nul;                // 种别码
    std::variant<double, std::string> value = 0.0;  // 属性值
};

using FunType = std::function<double(double)>;

/// @brief 查找符号在符号表中的具体定义
/// @param symbo名称
/// @return 数值或函数
std::optional<std::variant<double, FunType>> findSymboValue(std::string symbo);

/// @brief 从所给输入串中识别出一个单词并打包为token
/// @param input输入串
/// @return token和剩余输入串
std::tuple<Token, std::string> tokenize(std::string input);

#endif  // TOKEN_H
