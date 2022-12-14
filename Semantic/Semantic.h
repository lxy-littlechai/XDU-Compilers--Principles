//
// Created by littlechai on 22-12-9.
//

#ifndef PLOTTER_INTERPRETER_SEMANTIC_H
#define PLOTTER_INTERPRETER_SEMANTIC_H

#include <iostream>
#include <memory>
#include "Parser.h"
#include "Point.h"

class Semantic: private Parser {
public:
    Semantic();
    void init_Semantic(std::string fileName);
    void start_Semantic();
    void close_Semantic();

private:

    /** get specific expression value in sentence **/
    double getExpressionValue(const std::shared_ptr<TreeNode> &root);
    void originType() override;
    void rotType() override;
    void scaleType() override;
    void forType() override;
    void sizeType() override;
    void colorType() override;

    /** bind the T to the var **/
    void bindVar(const std::shared_ptr<TreeNode> &root);

    double var;
    double origin_x, origin_y;
    double rot_angle;
    double scale_x, scale_y;
    int size;
    Color color;
};


#endif //PLOTTER_INTERPRETER_SEMANTIC_H
