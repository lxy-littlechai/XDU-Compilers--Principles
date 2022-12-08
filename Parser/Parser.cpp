//
// Created by littlechai on 22-12-8.
//
#include <iostream>
#include "Parser.h"

void Parser::init_Parser(std::string filename) {
    outputDebugMsg("in Parser");
    scanner.init_scanner(filename);
}

void Parser::start_Parser() {

    token = fetchToken();
    while(token.tokenType != TokenType::NO_TOKEN) {
        judgeSentenceType();
        matchToken(TokenType::SEMICO);
    }
}

void Parser::close_Parser() {
    scanner.close_scanner();
    outputDebugMsg("out Parser");
}

Token Parser::fetchToken() {
    Token token = scanner.getToken();
    try  {
        if(token.tokenType == TokenType::ERR_TOKEN) {
            throw ExceptionLog(scanner.row, scanner.column, "Error in tokenType");
        }
    } catch (ExceptionLog &e) {
        e.log();
    }
    return token;
}

void Parser::matchToken(TokenType tokenType) {
    try {
        if(token.tokenType != tokenType) {
            throw ExceptionLog(scanner.row, scanner.column, "Error in match tokenType");
        }
        token = fetchToken();
    } catch (ExceptionLog& e) {
        e.log();
    }
}

void Parser::judgeSentenceType() {
    try {
        switch (token.tokenType) {
            case TokenType::ORIGIN: {
                originType();
                break;
            }
            case TokenType::SCALE: {
                scaleType();
                break;
            }
            case TokenType::ROT: {
                rotType();
                break;
            }
            case TokenType::FOR: {
                forType();
                break;
            }
            default: {
                throw ExceptionLog(scanner.row, scanner.column, "Error in sentenceType");
            }
        }
    } catch (ExceptionLog &e) {
        e.log();
    }

}

void Parser::originType() {
    matchToken(TokenType::ORIGIN);
    matchToken(TokenType::IS);
    matchToken(TokenType::L_BRACKET);
    x_ptr = expression();
    matchToken(TokenType::COMMA);
    y_ptr = expression();
    matchToken(TokenType::R_BRACKET);
}

void Parser::scaleType() {

}

void Parser::rotType() {

}

void Parser::forType() {

}

std::unique_ptr<TreeNode> Parser::expression() {
    return nullptr;
}

void Parser::outputDebugMsg(std::string msg) {
    std::cout << msg << std::endl;
}