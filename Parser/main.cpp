#include <iostream>
#include "Parser.h"

int main() {
  std::string fileName = "../test.txt";
  Parser parser;
  parser.init_Parser(fileName);
  parser.start_Parser();
  parser.close_Parser();
  system("pause");
  return 0;
}
