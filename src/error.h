#ifndef ERROR_H
#define ERROR_H

#include <stdexcept>  //异常处理
#include <string>

extern std::string errMessage;
extern int errNum;

//判断"("左边是否是数字 若是数字则为true，否则为false
extern bool lp_left_is_Num;

//判断")"右边是否是数字 若是数字则为true，否则为false
extern bool rp_right_is_Num;

extern void error(int id);

#endif  // ERROR_H
