#include <windows.h>
#include <QApplication>
#include "error.h"

std::string errMessage = "";
int errNum = 0;
bool lp_left_is_Num = false;
bool rp_right_is_Num = false;

void error(int id)  {
    switch (id) {
    case 1:errMessage = "错误: 存在不合法的符号!\n";break;
    case 2:errMessage = "错误: '('左边不能直接接数字，缺失运算符!\n";break;
    case 3:errMessage = "错误: ')'右边不能直接接数字，缺失运算符!\n";break;
    case 4:errMessage = "错误: 除数不能为0!\n";break;
    case 5:errMessage = "错误: sqrt运算数必须>=0!\n";break;
    case 6:errMessage = "错误: log底数必须>0且!=1!\n";break;
    case 7:errMessage = "错误: 表达式缺数字,函数或'('!\n";break;
    case 8:errMessage = "错误: 表达式缺'('!\n";break;
    case 9:errMessage = "错误: 表达式缺')'!\n";break;
    case 10:errMessage = "错误: '(' 与 ')' 个数不匹配!\n";break;
    case 11:errMessage = "错误: 常量或函数前缺少运算符!\n";break;
    case 12:break;//为自定义提示文本预留的异常
    case 13:errMessage = "错误: 未知错误!\n";break;
    }
    errNum++;
    #ifdef Q_OS_WIN
        QApplication::beep();
    #endif
    throw std::runtime_error(errMessage);
}
