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
    double constValue;
    double* var;
    struct FuncNode {
        std::shared_ptr<TreeNode> child;
        std::shared_ptr<Func> func;
    } funcNode;

    struct OperatorNode {
        std::shared_ptr<TreeNode> Lchild, Rchild;
    } operatorNode;


};






#endif //PLOTTER_INTERPRETER_TREENODE_H
