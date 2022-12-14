//
// Created by 16117 on 2022/12/7.
//

#include "Token.h"
const static Token TokenTable[] = {
        Token(CONST_ID, "PI", 3.1415926535, std::make_shared<NoFunc>()),
        Token(CONST_ID, "E", 2.71828, std::make_shared<NoFunc>()),
        Token(T, "T", 0.0, std::make_shared<NoFunc>()),
        Token(ORIGIN, "ORIGIN", 0.0, std::make_shared<NoFunc>()),
        Token(SCALE, "SCALE", 0.0, std::make_shared<NoFunc>()),
        Token(ROT, "ROT", 0.0, std::make_shared<NoFunc>()),
        Token(IS, "IS", 0.0, std::make_shared<NoFunc>()),
        Token(FOR, "FOR", 0.0, std::make_shared<NoFunc>()),
        Token(FROM, "FROM", 0.0, std::make_shared<NoFunc>()),
        Token(TO, "TO", 0.0, std::make_shared<NoFunc>()),
        Token(T, "T", 0.0, std::make_shared<NoFunc>()),
        Token(COLOR, "COLOR", 0.0, std::make_shared<NoFunc>()),
        Token(SIZE, "SIZE", 0.0, std::make_shared<NoFunc>()),
        Token(STEP, "STEP", 0.0, std::make_shared<NoFunc>()),
        Token(DRAW, "DRAW", 0.0, std::make_shared<NoFunc>()),
        Token(FUNC, "COS", 0.0, std::make_shared<Cos>()),
        Token(FUNC, "SIN", 0.0, std::make_shared<Sin>()),
        Token(FUNC, "LN", 0.0, std::make_shared<Ln>()),
        Token(FUNC, "EXP", 0.0, std::make_shared<Exp>()),
        Token(FUNC, "SQRT", 0.0, std::make_shared<Sqrt>()),
        Token(FUNC, "TAN", 0.0, std::make_shared<Tan>()),

};

Token::Token() {
    tokenType = TokenType::NO_TOKEN;
    token = "";
    value = 0;

}

Token::Token(TokenType tokenType, std::string token, double value, std::shared_ptr<Func> func) {
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