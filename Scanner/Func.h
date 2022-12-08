//
// Created by 16117 on 2022/12/8.
//

#ifndef PLOTTER_INTERPRETER_FUNC_H
#define PLOTTER_INTERPRETER_FUNC_H

#include <cmath>

class Func {
public:
    virtual double call(double num) {
        return num;
    }
};

class Cos: public Func {
public:
    double call(double num) override {
        return cos(num);
    }
};

class Sin: public Func {
public:
    double call(double num) override {
        return sin(num);
    }
};

class Tan: public Func {
public:
    double call(double num) override {
        return tan(num);
    }
};

class Ln: public Func {
public:
    double call(double num) override {
        return log(num);
    }
};

class Exp: public Func {
public:
    double call(double num) override {
        return exp(num);
    }
};

class Sqrt: public Func {
public:
    double call(double num) override {
        return sqrt(num);
    }
};


#endif //PLOTTER_INTERPRETER_FUNC_H
