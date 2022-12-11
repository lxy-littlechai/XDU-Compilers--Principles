#include <iostream>
#include "Scanner.h"
int main() {
  Scanner scanner;
  scanner.init_scanner("../test.txt");
  scanner.start_scanner();
  scanner.close_scanner();
    system("pause");
  return 0;
}
