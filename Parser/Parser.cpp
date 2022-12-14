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
                            + token.token + " is ERR_TOKEN";
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
            case TokenType::SIZE: {
                sizeType();
                break;
            }
            case TokenType::COLOR: {
                colorType();
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

void Parser::sizeType() {
    matchToken(TokenType::SIZE);
    matchToken(TokenType::IS);
    size_ptr = expression();
}

void Parser::colorType() {
    matchToken(TokenType::COLOR);
    matchToken(TokenType::IS);
    matchToken(TokenType::L_BRACKET);
    color_ptr.R_ptr = expression();
    matchToken(TokenType::COMMA);
    color_ptr.G_ptr = expression();
    matchToken(TokenType::COMMA);
    color_ptr.B_ptr = expression();
    matchToken(TokenType::R_BRACKET);

}

// expression -> Term {(PLUS | MINUS) Term }
std::shared_ptr<TreeNode> Parser::expression() {
    auto left =  std::make_shared<TreeNode>();
    auto right = std::make_shared<TreeNode>();

    left = Term();
    while(token.tokenType == TokenType::PLUS || token.tokenType == TokenType::MINUS) {
        Token token_tmp = token;
        matchToken(token.tokenType);
        right = Term();

        left = buildTreeNode(token_tmp.tokenType, token_tmp.token, left, right);
    }
    std::cout << "-------- SyntaxTree ---------" << std::endl;
    outputExpression(left);
    outputDebugMsg("\n");
    outputSyntaxTree(left, 0);
    return left;
}

// Term -> Factor { (MUL | DIV) Factor}
std::shared_ptr<TreeNode> Parser::Term() {
    auto left =  std::make_shared<TreeNode>();
    auto right = std::make_shared<TreeNode>();

    left = Factor();
    while (token.tokenType == TokenType::MUL || token.tokenType == TokenType::DIV) {
        Token token_tmp = token;
        matchToken(token.tokenType);
        right = Factor();

        left = buildTreeNode(token_tmp.tokenType, token_tmp.token, left, right);
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
        right = buildTreeNode(TokenType::MINUS, "-", left, right);
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
        left = buildTreeNode(TokenType::POWER, "**", left, right);
    }
    return left;
}

// Atom -> CONST_ID | T | FUNC L_BRACKET expression R_BRACKET | L_BRACKET expression R_BRACKET
std::shared_ptr<TreeNode> Parser::Atom() {
    auto t = token;
    auto node = std::make_shared<TreeNode>();

    try  {
        switch (token.tokenType) {
            case TokenType::CONST_ID: {
                matchToken(TokenType::CONST_ID);
                node = buildTreeNode(TokenType::CONST_ID, t.token, t.value);
                break;
            }
            case TokenType::T: {
                matchToken(TokenType::T);
                node = buildTreeNode(TokenType::T, t.token, t.value);
                break;
            }
            case TokenType::FUNC: {
                matchToken(TokenType::FUNC);
                matchToken(TokenType::L_BRACKET);
                auto tmp = expression();
                node = buildTreeNode(TokenType::FUNC, t.token, t.func, tmp);
                matchToken(TokenType::R_BRACKET);
                break;
            }
            case TokenType::L_BRACKET: {
                matchToken(TokenType::L_BRACKET);
                auto tmp = expression();
                node = buildTreeNode(TokenType::FUNC, t.token, t.func, tmp);
                matchToken(TokenType::R_BRACKET);
                break;
            }
            default: {
                throw ExceptionLog(scanner.row, scanner.column, "Err Sentence");
            }
        }
    } catch (ExceptionLog &e) {
        e.log();
    }
    return node;
}


std::shared_ptr<TreeNode>
Parser::buildTreeNode(TokenType tokenType, std::string token, std::shared_ptr<TreeNode> left, std::shared_ptr<TreeNode> right) {
    auto node = std::make_shared<TreeNode>();
    node->tokenType = tokenType;
    node->token = token;
    node->operatorNode.Lchild = left;
    node->operatorNode.Rchild = right;
    return node;
}

std::shared_ptr<TreeNode> Parser::buildTreeNode(TokenType tokenType, std::string token, double value) {
    auto node = std::make_shared<TreeNode>();
    node->tokenType = tokenType;
    node->token = token;
    if(tokenType == TokenType::CONST_ID) {
        node->constValue = value;
    }
    else {
        node->var = &value;
    }
    return node;
}

std::shared_ptr<TreeNode> Parser::buildTreeNode(TokenType tokenType, std::string token, std::shared_ptr<Func> func, std::shared_ptr<TreeNode> t) {
    auto node = std::make_shared<TreeNode>();
    node->tokenType = tokenType;
    node->token = token;
    node->funcNode.func = func;
    node->funcNode.child = t;
    return node;
}

void Parser::outputDebugMsg(std::string msg) {
    std::cout << msg << std::endl;
}

void Parser::outputExpression(const std::shared_ptr<TreeNode> &root) {
    switch (root->tokenType) {
        case TokenType::PLUS: {
            outputExpression(root->operatorNode.Lchild);
            std::cout << root->token;
            outputExpression(root->operatorNode.Rchild);
            break;
        }
        case TokenType::MINUS: {
            outputExpression(root->operatorNode.Lchild);
            std::cout << root->token;
            outputExpression(root->operatorNode.Rchild);
            break;
        }
        case TokenType::MUL: {
            outputExpression(root->operatorNode.Lchild);
            std::cout << root->token;
            outputExpression(root->operatorNode.Rchild);
            break;
        }
        case TokenType::DIV: {
            outputExpression(root->operatorNode.Lchild);
            std::cout << root->token;
            outputExpression(root->operatorNode.Rchild);
            break;
        }
        case TokenType::POWER: {
            outputExpression(root->operatorNode.Lchild);
            std::cout << root->token;
            outputExpression(root->operatorNode.Rchild);
            break;
        }
        case TokenType::FUNC: {
            std::cout << root->token << "(";
            outputExpression(root->funcNode.child);
            std::cout << ")";
            break;
        }
        case TokenType::CONST_ID: {
            std::cout << root->token;
            break;
        }
        case TokenType::T: {
            std::cout << root->token;
            break;
        }
        default: {
            break;
        }
    }

}

void Parser::outputSyntaxTree(const std::shared_ptr<TreeNode> &root, int height) {


    for(int i = 1;i <= height;i ++) {
        std::cout << "   ";
    }
    std::cout << root->token << std::endl;

    if(root->tokenType == TokenType::CONST_ID || root->tokenType == TokenType::T) {
        return;
    }
    else if(root->tokenType == TokenType::FUNC) {
        outputSyntaxTree(root->funcNode.child, height+1);
    }
    else {
        outputSyntaxTree(root->operatorNode.Lchild, height+1);
        outputSyntaxTree(root->operatorNode.Rchild, height+1);
    }

}