
// Created by 16117 on 2022/12/7.
//

#include <string>
#include <iomanip>
#include "Scanner.h"
#include "../ExceptionLog/ExceptionLog.h"


void Scanner::init_scanner(std::string fileName) {
    try {
        file.open(fileName);
//        if(!file.is_open()) {
//            throw new ExceptionLog("文件打开失败");
//        }


    } catch (ExceptionLog &e) {
 //       e.log();
    }

}

void Scanner::start_scanner() {
    Token token;
    std::cout.width(8);
    std::cout << std::setw(20) << "记号类别"
              << std::setw(20) << "字符串"
              << std::setw(20) << "常数值"
              << std::endl;
    while(true) {
        token = getToken();

        if(token.tokenType != TokenType::NO_TOKEN) {
            std::cout << std::setw(20) << token.tokenType
                      << std::setw(20) << token.token
                      << std::setw(20) << token.value
                      << std::endl;
        }
        else {
            break;
        }

    }
}

Token Scanner::getToken() {
    Token token;
    char ch;
    std::string buffer = "";


    while ((ch = getChar())) {  //filter space, enter, tab

        if(ch == EOF) {
            token.tokenType = TokenType::NO_TOKEN;
            return token;
        }
        else if(ch == '\n') {
            row ++;
        }
        else if(!std::isspace(ch)) {
            break;
        }
    }
    buffer += ch;


    if(std::isalpha(ch)) {  //letter -> reserve key, parameter, function
        while ((ch = file.peek())) {
            if(std::isalpha(ch)) {  //letter
                ch = getChar();
                buffer += ch;
            }
            else {
                break;
            }
        }
        token = Token::judgeToken(buffer);
        token.token = buffer;
        return token;
    }
    else if(std::isdigit(ch)) { //letter -> integer or decimal
        while ((ch = file.peek())) {
            if(std::isdigit(ch)) {
                ch = getChar();
                buffer += ch;
            }
            else {
                break;
            }
        }
        if(ch == '.') { //decimal
           buffer += ch;
            while ((ch = file.peek())) {
                if(std::isdigit(ch)) {
                    ch = getChar();
                    buffer += ch;
                }
                else {
                    break;
                }
            }
        }

        token.tokenType = TokenType::CONST_ID;
        token.token = buffer;
        token.value = std::stof(buffer);
        return token;
    }
    else {  // operator
        switch (ch) {
            case ',': {
                token.tokenType = TokenType::COMMA;
                break ;
            }
            case ';': {
                token.tokenType = TokenType::SEMICO;
                break ;
            }
            case '(': {
                token.tokenType = TokenType::L_BRACKET;
                break;
            }
            case ')': {
                token.tokenType = TokenType::R_BRACKET;
                break;
            }
            case '+': {
                token.tokenType = TokenType::PLUS;
                break;
            }
            case '-': {
                ch = file.peek();
                if(ch == '-') {
                    while((ch = getChar()) && ch != '\n' && ch != EOF);
                    return getToken();
                }
                else {
                    token.tokenType = TokenType::MINUS;
                    break;
                }
            }
            case '*': {
                ch = file.peek();
                if(ch == '*') {
                    ch = getChar();
                    token.tokenType = TokenType::POWER;
                }
                else {
                    token.tokenType = TokenType::MUL;
                }
                break;
            }
            case '/': {
                ch = file.get();
                if(ch == '/') {
                    while((ch = file.get()) && ch != '\n' && ch != EOF);
                    return getToken();
                }
            }
            default: {
                token.tokenType = TokenType::ERR_TOKEN;
                break;
            }
        }
        token.token = buffer;
    }
    return token;
}

void Scanner::close_scanner() {
    file.close();
}

char Scanner::getChar() {
    char ch = file.get();
    if(std::isalpha(ch)) {
        return toupper(ch);
    }
    return ch;
}


