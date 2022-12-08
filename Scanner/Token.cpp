//
// Created by 16117 on 2022/12/7.
//

#include "Token.h"
const static Token TokenTable[] = {
        Token(CONST_ID, "PI", 3.1415926535, Func()),
        Token(CONST_ID, "E", 2.71828, Func()),
        Token(T, "T", 0.0, Func()),
        Token(ORIGIN, "ORIGIN", 0.0, Func()),
        Token(SCALE, "SCALE", 0.0, Func()),
        Token(ROT, "ROT", 0.0, Func()),
        Token(IS, "IS", 0.0, Func()),
        Token(FOR, "FOR", 0.0, Func()),
        Token(FROM, "FROM", 0.0, Func()),
        Token(TO, "TO", 0.0, Func()),
        Token(T, "T", 0.0, Func()),
        Token(STEP, "STEP", 0.0, Func()),
        Token(DRAW, "DRAW", 0.0, Func()),
        Token(FUNC, "COS", 0.0, Cos()),
        Token(FUNC, "SIN", 0.0, Sin()),
        Token(FUNC, "LN", 0.0, Ln()),
        Token(FUNC, "EXP", 0.0, Exp()),
        Token(FUNC, "SQRT", 0.0, Sqrt()),
        Token(FUNC, "TAN", 0.0, Tan()),

};

Token::Token() {
    tokenType = TokenType::NO_TOKEN;
    token = "";
    value = 0;

}

Token::Token(TokenType tokenType, std::string token, double value, Func func) {
    this->tokenType = tokenType;
    this->token = token;
    this->value = value;
    this->func = func;
}

Token Token::judgeToken(std::string str) {
    Token returnToken;
    for(auto token: TokenTable) {
        if(token.token == str) {
            returnToken = token;
            return returnToken;
        }
    }
    returnToken.tokenType = TokenType::ERR_TOKEN;
    return returnToken;
}