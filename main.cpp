#include <iostream>
#include "Semantic/Semantic.h"

int main() {
    std::string fileName = "/home/littlechai/University/XDU-Compilers--Principles/circle.txt";
    Semantic semantic;
    semantic.init_Semantic(fileName);
    semantic.start_Semantic();
    semantic.close_Semantic();

    return 0;
}
