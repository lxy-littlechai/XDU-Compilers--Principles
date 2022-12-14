//
// Created by 16117 on 2022/12/7.
//

#ifndef PLOTTER_INTERPRETER_EXCEPTIONLOG_H
#define PLOTTER_INTERPRETER_EXCEPTIONLOG_H
#include <exception>
#include <string>

class ExceptionLog{
public:
    ExceptionLog() = default;
    ExceptionLog(std::string message);
    ExceptionLog(int errRow, int errColumn, std::string errType);
    void log();

private:
    int errRow, errColumn;
    std::string errType, message;
};


#endif //PLOTTER_INTERPRETER_EXCEPTIONLOG_H
