//
// Created by littlechai on 22-12-8.
//

#ifndef PLOTTER_INTERPRETER_TREENODE_H
#define PLOTTER_INTERPRETER_TREENODE_H

#include <memory>
#include "Token.h"
#include "Func.h"

class TreeNode {
public:
    TokenType tokenType;
    double constNode;
    double varNode;
    struct FuncNode {
        std::unique_ptr<TreeNode> child;
        Func func;
    } funcNode;

    struct OperatorNode {
        std::unique_ptr<TreeNode> Lchild, Rchild;
    } operatorNode;


};






#endif //PLOTTER_INTERPRETER_TREENODE_H
