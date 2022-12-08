#include <iostream>
#include "Parser.h"

int main() {
    std::string fileName = "/home/littlechai/University/XDU-Compilers--Principles/test.txt";
    Parser parser;
    parser.init_Parser(fileName);
    parser.start_Parser();
    parser.close_Parser();

    return 0;
}
