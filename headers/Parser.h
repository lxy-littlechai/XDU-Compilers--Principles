//
// Created by littlechai on 22-12-8.
//

#ifndef PLOTTER_INTERPRETER_PARSER_H
#define PLOTTER_INTERPRETER_PARSER_H

#include <memory>
#include <string>
#include "Scanner.h"
#include "Token.h"
#include "TreeNode.h"

class Parser {
public:
    Token fetchToken();
    void matchToken(TokenType);

    /** expose interface **/
    void init_Parser(std::string filename);
    void start_Parser();
    void close_Parser();
    void outputSyntaxTree(std::shared_ptr<TreeNode> root, int height);

protected:
    /** main function to match specific sentence **/
    virtual void judgeSentenceType();
    virtual void originType();
    virtual void rotType();
    virtual void scaleType();
    virtual void forType();

    /**
        FOR T From start To end Step step_ptr Draw (x, y)
        ROT is angle
    **/
    std::shared_ptr<TreeNode>  start_ptr;
    std::shared_ptr<TreeNode>  end_ptr;
    std::shared_ptr<TreeNode>  step_ptr;
    std::shared_ptr<TreeNode>  x_ptr;
    std::shared_ptr<TreeNode>  y_ptr;
    std::shared_ptr<TreeNode>  angle_ptr;

private:
    /**
        match rules
        to remove Left Recursion & Left Factor
        LL(1) method, from the bottom to top, leftmost derivation !!!
     **/
    std::shared_ptr<TreeNode>  expression();
    std::shared_ptr<TreeNode>  Term();
    std::shared_ptr<TreeNode>  Factor();
    std::shared_ptr<TreeNode>  Component();
    std::shared_ptr<TreeNode>  Atom();

    /** build TreeNode **/
    std::shared_ptr<TreeNode> buildTreeNode(TokenType tokenType, std::shared_ptr<TreeNode> left, std::shared_ptr<TreeNode> right);
    std::shared_ptr<TreeNode> buildTreeNode(TokenType tokenType, double  value);
    std::shared_ptr<TreeNode> buildTreeNode(TokenType tokenType, std::shared_ptr<Func> func, std::shared_ptr<TreeNode> node);

    /** output debug message **/
    void outputDebugMsg(std::string msg);

    Scanner scanner;
    Token token;
};


#endif //PLOTTER_INTERPRETER_PARSER_H
