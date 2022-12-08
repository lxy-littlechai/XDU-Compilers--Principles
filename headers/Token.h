//
// Created by 16117 on 2022/12/7.
//

#ifndef SCANNER_TOKEN_H
#define SCANNER_TOKEN_H
#include <string>
#include "Func.h"

enum TokenType {
    /* reserve key */
    ORIGIN, SCALE, ROT, IS,
    To, STEP, DRAW, FOR, FROM,
    /* constant & parameter & FUNC*/
    CONST_ID, T, FUNC,
    /* separator */
    SEMICO, L_BRACKET, R_BRACKET, COMMA,
    /* operator */
    PLUS, MINUS, MUL, DIV, POWER,
    /* special */
    NO_TOKEN, ERR_TOKEN,
};

class Token {
public:
    TokenType tokenType;
    std::string token;     //input string
    double value;           //record constant_id
    Func func;

    Token();
    Token(TokenType tokenType, std::string token, double value, Func func);
    static Token judgeToken(std::string str);

};




#endif //SCANNER_TOKEN_H
