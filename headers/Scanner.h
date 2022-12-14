//
// Created by 16117 on 2022/12/7.
//

#ifndef SCANNER_SCANNER_H
#define SCANNER_SCANNER_H
#include <iostream>
#include <fstream>
#include <string>
#include "Token.h"

class Scanner {
public:
    int row, column;
    std::ifstream file;
    std::string fileName;

    void init_scanner(std::string fileName);
    void start_scanner();
    void close_scanner();
    char getChar();
    Token getToken();
};


#endif //SCANNER_SCANNER_H
