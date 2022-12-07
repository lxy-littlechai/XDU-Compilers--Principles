#include <iostream>
#include "Scanner.h"
int main() {
    Scanner scanner;
    scanner.init_scanner("E:\\University\\Coding Space\\XDU-Compilers--Principles\\Scanner\\test.txt");
    scanner.start_scanner();
    scanner.close_scanner();
    return 0;
}
