#include <iostream>
#include "Scanner.h"

int main() {
    Scanner scanner;
    scanner.init_scanner("/home/littlechai/University/XDU-Compilers--Principles/test.txt");
    scanner.start_scanner();
    scanner.close_scanner();
    return 0;
}
