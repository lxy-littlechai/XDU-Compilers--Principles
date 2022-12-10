//
// Created by littlechai on 22-12-8.
//
#include <iostream>
#include <memory>
#include "Parser.h"
#include "ExceptionLog.h"

void Parser::init_Parser(std::string filename) {
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
}

Token Parser::fetchToken() {
    Token token = scanner.getToken();
//    std::cout << token.token << std::endl;
    try  {
        if(token.tokenType == TokenType::ERR_TOKEN) {
            std::string errMsg = "Error in tokenType when fetchToken\n"
                            + token.token + "is ERR_TOKEN";
            throw ExceptionLog(scanner.row, scanner.column, errMsg);
        }
    } catch (ExceptionLog &e) {
        e.log();
    }
    return token;
}

void Parser::matchToken(TokenType tokenType) {
    try {
        if(token.tokenType != tokenType) {
            std::string errMsg = "Error in tokenType when matchToken\n"
                                 "now token is "+ token.token + "\n";
            throw ExceptionLog(scanner.row, scanner.column, errMsg);
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
    matchToken(TokenType::SCALE);
    matchToken(TokenType::IS);
    matchToken(TokenType::L_BRACKET);
    x_ptr = expression();
    matchToken(TokenType::COMMA);
    y_ptr = expression();
    matchToken(TokenType::R_BRACKET);

}

void Parser::rotType() {
    matchToken(TokenType::ROT);
    matchToken(TokenType::IS);
    angle_ptr = expression();
}

void Parser::forType() {
    matchToken(TokenType::FOR);
    matchToken(TokenType::T);
    matchToken(TokenType::FROM);
    start_ptr = expression();
    matchToken(TokenType::TO);
    end_ptr = expression();
    matchToken(TokenType::STEP);
    step_ptr = expression();
    matchToken(TokenType::DRAW);
    matchToken(TokenType::L_BRACKET);
    x_ptr = expression();
    matchToken(TokenType::COMMA);
    y_ptr = expression();
    matchToken(TokenType::R_BRACKET);
}

// expression -> Term {(PLUS | MINUS) Term }
std::shared_ptr<TreeNode> Parser::expression() {
    auto left =  std::make_shared<TreeNode>();
    auto right = std::make_shared<TreeNode>();

    left = Term();
    while(token.tokenType == TokenType::PLUS || token.tokenType == TokenType::MINUS) {
        TokenType token_tmp = token.tokenType;
        matchToken(token.tokenType);
        right = Term();

        left = buildTreeNode(token_tmp, left, right);
    }
    return left;
}

// Term -> Factor { (MUL | DIV) Factor}
std::shared_ptr<TreeNode> Parser::Term() {
    auto left =  std::make_shared<TreeNode>();
    auto right = std::make_shared<TreeNode>();

    left = Factor();
    while (token.tokenType == TokenType::MUL || token.tokenType == TokenType::DIV) {
        TokenType token_tmp = token.tokenType;
        matchToken(token.tokenType);
        right = Factor();

        left = buildTreeNode(token_tmp, left, right);
    }
    return left;
}

// Factor -> ((PLUS | MINUS) Factor) | Component      one number PLUS or MINUS
std::shared_ptr<TreeNode> Parser::Factor() {
    auto left =  std::make_shared<TreeNode>();
    auto right = std::make_shared<TreeNode>();

    if(token.tokenType == TokenType::PLUS) {
        matchToken(TokenType::PLUS);
        right = Factor();
    }
    else if(token.tokenType == TokenType::MINUS) {
        matchToken(TokenType::MINUS);
        left->tokenType = TokenType::CONST_ID;
        left->constValue = 0;
        right = Factor();
        right = buildTreeNode(TokenType::MINUS, left, right);
    }
    else {
        right = Component();
    }
    return right;
}

// Component -> Atom [POWER Component]
std::shared_ptr<TreeNode> Parser::Component() {
    auto left =  std::make_shared<TreeNode>();
    auto right = std::make_shared<TreeNode>();

    left = Atom();
    if(token.tokenType == TokenType::POWER) {
        matchToken(TokenType::POWER);
        right = Component();
        left = buildTreeNode(TokenType::POWER, left, right);
    }
    return left;
}

// Atom -> CONST_ID | T | FUNC L_BRACKET expression R_BRACKET
std::shared_ptr<TreeNode> Parser::Atom() {
    auto t = token;
    auto node = std::make_shared<TreeNode>();

    try  {
        switch (token.tokenType) {
            case TokenType::CONST_ID: {
                matchToken(TokenType::CONST_ID);
                node = buildTreeNode(TokenType::CONST_ID, t.value);
                break;
            }
            case TokenType::T: {
                matchToken(TokenType::T);
                node = buildTreeNode(TokenType::T, t.value);
                break;
            }
            case TokenType::FUNC: {
                matchToken(TokenType::FUNC);
                matchToken(TokenType::L_BRACKET);
                auto tmp = expression();
                node = buildTreeNode(TokenType::FUNC, t.func, tmp);
                matchToken(TokenType::R_BRACKET);
                break;
            }
            default: {

                break;
            }
        }
    } catch (ExceptionLog &e) {
        e.log();
    }
    return node;
}


std::shared_ptr<TreeNode>
Parser::buildTreeNode(TokenType tokenType, std::shared_ptr<TreeNode> left, std::shared_ptr<TreeNode> right) {
    auto node = std::make_shared<TreeNode>();
    node->tokenType = tokenType;
    node->operatorNode.Lchild = left;
    node->operatorNode.Rchild = right;
    return node;
}

std::shared_ptr<TreeNode> Parser::buildTreeNode(TokenType tokenType, double value) {
    auto node = std::make_shared<TreeNode>();
    node->tokenType = tokenType;

    if(tokenType == TokenType::CONST_ID) {
        node->constValue = value;
    }
    else {
        node->var = &value;
    }
    return node;
}

std::shared_ptr<TreeNode> Parser::buildTreeNode(TokenType tokenType, std::shared_ptr<Func> func, std::shared_ptr<TreeNode> t) {
    auto node = std::make_shared<TreeNode>();
    node->tokenType = tokenType;
    node->funcNode.func = func;
    node->funcNode.child = t;
    return node;
}

void Parser::outputDebugMsg(std::string msg) {
    std::cout << msg << std::endl;
}

void Parser::outputSyntaxTree(std::shared_ptr<TreeNode> root, int height) {
    for(int i = 1;i <= height;i ++) {
        std::cout << " ";
    }
    switch (root->tokenType){
        case PLUS: {
            std::cout << "+" <<std::endl;
            break;
        }
        case MINUS: {
            std::cout << "-" <<std::endl;
            break;
        }

        case MUL: {
            std::cout << "*" <<std::endl;
            break;
        }
        case DIV: {
            std::cout << "/" <<std::endl;
            break;
        }
        case POWER: {
            std::cout << "**" <<std::endl;
            break;
        }
        case FUNC: {
            std::cout << "func" <<std::endl;
            break;
        }
        case CONST_ID: {
            std::cout << root->constValue <<std::endl;
            break;
        }
        case T: {
            std::cout << "T" <<std::endl;
            break;
        }
        default: {
            std::cout << "#" <<std::endl;
            break;
        }

    }

}