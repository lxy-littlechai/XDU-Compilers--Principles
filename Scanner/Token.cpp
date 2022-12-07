//
// Created by 16117 on 2022/12/7.
//

#include "Token.h"
const static Token TokenTable[] = {
        Token(CONST_ID, "PI", 3.1415926535),
        Token(CONST_ID, "E", 2.71828),
        Token(T, "T", 0.0),
        Token(ORIGIN, "ORIGIN", 0.0),
        Token(SCALE, "SCALE", 0.0),
        Token(ROT, "ROT", 0.0),
        Token(IS, "IS", 0.0),
        Token(FOR, "FOR", 0.0),
        Token(FROM, "FROM", 0.0),
        Token(T, "T", 0.0),
        Token(STEP, "STEP", 0.0),
        Token(DRAW, "DRAW", 0.0),
        Token(FUNC, "COS", 0.0),
        Token(FUNC, "SIN", 0.0),
        Token(FUNC, "LN", 0.0),
        Token(FUNC, "EXP", 0.0),
        Token(FUNC, "SQRT", 0.0),
        Token(FUNC, "TAN", 0.0),

};

Token::Token() {
    tokenType = TokenType::NO_TOKEN;
    token = "";
    value = 0;

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