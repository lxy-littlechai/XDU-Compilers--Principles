//
// Created by 16117 on 2022/12/7.
//

#ifndef SCANNER_FUNC_H
#define SCANNER_FUNC_H
#include <cmath>

enum Func_type {
    SIN, COS, TAN, LN, EXP, SQRT, NOFUNC
};

class Func {
public:
    double (*call)(double num);

    Func() = default;
    Func(Func_type func_type);

    static double sin(double num);
    static double cos(double num);
    static double ln(double num);
    static double exp(double num);
    static double sqrt(double num);
    static double tan(double num);

};


#endif //SCANNER_FUNC_H
