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
        std::cout << "��������: " << errType << std::endl;
        std::cout << "������������: �� " << errRow << " �У��� " << errColumn << " ��" << std::endl;
    } else {
        std::cout << message << std::endl;
    }


}