//
// Created by 16117 on 2022/12/7.
//

#include "Func.h"
Func::Func(Func_type func_type) {
    switch (func_type) {
        case SIN:
            call = sin;
            break;
        case COS:
            call = cos;
            break;
        case TAN:
            call = tan;
            break;
        case LN:
            call = ln;
            break;
        case EXP:
            call = exp;
            break;
        case SQRT:
            call = sqrt;
            break;
        default:
            call = nullptr;
            break;

    }
}

double Func::sin(double num) {
    return std::sin(num);
}
double Func::cos(double num) {
    return std::cos(num);
}
double Func::ln(double num) {
    return std::log(num);
}
double Func::exp(double num) {
    return std::exp(num);
}
double Func::sqrt(double num) {
    return std::sqrt(num);
}
double Func::tan(double num) {
    return std::tan(num);
}