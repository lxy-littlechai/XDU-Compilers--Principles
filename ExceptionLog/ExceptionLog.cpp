//
// Created by 16117 on 2022/12/7.
//

#include "ExceptionLog.h"
#include <iostream>

ExceptionLog::ExceptionLog(std::string message) {
    this->message = message;
}

ExceptionLog::ExceptionLog(int errRow, int errColumn, std::string errType) {
    this->errRow = errRow;
    this->errColumn = errColumn;
    this->errType = errType;
}

void ExceptionLog::log() {

    if(message == "") {
        std::cout << "错误类型: " << errType << std::endl;
        std::cout << "错误所在行列: 第 " << errRow << " 行，第 " << errColumn << " 列" << std::endl;
    } else {
        std::cout << message << std::endl;
    }


}