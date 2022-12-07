//
// Created by 16117 on 2022/12/7.
//

#include "Token.h"
const static Token TokenTable[] = {
        Token(CONST_ID, "PI", 3.1415926535, Func(Func_type::NOFUNC)),
        Token(CONST_ID, "E", 2.71828,Func(Func_type::NOFUNC)),
        Token(T, "T", 0.0,Func(Func_type::NOFUNC)),
        Token(ORIGIN, "ORIGIN", 0.0, Func(Func_type::NOFUNC)),
        Token(SCALE, "SCALE", 0.0, Func(Func_type::NOFUNC)),
        Token(ROT, "ROT", 0.0,Func(Func_type::NOFUNC)),
        Token(IS, "IS", 0.0,Func(Func_type::NOFUNC)),
        Token(FOR, "FOR", 0.0,Func(Func_type::NOFUNC)),
        Token(FROM, "FROM", 0.0,Func(Func_type::NOFUNC)),
        Token(T, "T", 0.0,Func(Func_type::NOFUNC)),
        Token(STEP, "STEP", 0.0,Func(Func_type::NOFUNC)),
        Token(DRAW, "DRAW", 0.0, Func(Func_type::NOFUNC)),
        Token(FUNC, "COS", 0.0,Func(Func_type::COS)),
        Token(FUNC, "SIN", 0.0, Func(Func_type::SIN)),
        Token(FUNC, "LN", 0.0,Func(Func_type::LN)),
        Token(FUNC, "EXP", 0.0, Func(Func_type::EXP)),
        Token(FUNC, "SQRT", 0.0, Func(Func_type::SQRT)),
        Token(FUNC, "TAN", 0.0, Func(Func_type::TAN)),

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