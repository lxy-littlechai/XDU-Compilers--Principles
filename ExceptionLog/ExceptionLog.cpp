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
        std::cout << "---------------------------" << std::endl;
        std::cout << "ErrType: " << errType << std::endl;
        std::cout << "ErrRow:  " << errRow << " ErrorColumn " << errColumn << " " << std::endl;
    } else {
        std::cout << message << std::endl;
    }


}