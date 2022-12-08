//
// Created by littlechai on 22-12-8.
//

#ifndef PLOTTER_INTERPRETER_PARSER_H
#define PLOTTER_INTERPRETER_PARSER_H

#include <memory>
#include <string>
#include "Scanner.h"
#include "Token.h"
#include "ExceptionLog.h"
#include "TreeNode.h"


class Parser {
public:
    Token fetchToken();
    void matchToken(TokenType);

    /** expose interface **/
    void init_Parser(std::string filename);
    void start_Parser();
    void close_Parser();

private:
    /** main function to match specific sentence **/
    void judgeSentenceType();
    void originType();
    void rotType();
    void scaleType();
    void forType();

    /**
        match rules
        to remove Left Recursion & Left Factor
     **/
    std::unique_ptr<TreeNode>  expression();
    std::unique_ptr<TreeNode>  Term();
    std::unique_ptr<TreeNode>  Factor();
    std::unique_ptr<TreeNode>  Component();
    std::unique_ptr<TreeNode>  Atom();


    /** output debug message **/
    void outputDebugMsg(std::string msg);

private:
    Scanner scanner;
    Token token;
    std::unique_ptr<TreeNode>  start_ptr;
    std::unique_ptr<TreeNode>  end_ptr;
    std::unique_ptr<TreeNode>  step_ptr;
    std::unique_ptr<TreeNode>  x_ptr;
    std::unique_ptr<TreeNode>  y_ptr;
    std::unique_ptr<TreeNode>  angle_ptr;


};


#endif //PLOTTER_INTERPRETER_PARSER_H
