//
// Created by littlechai on 22-12-9.
//

#include "Semantic.h"
#include "../headers/Plotter.h"
#include "../headers/Point.h"
#include "../headers/Token.h"

Semantic::Semantic() {
  var = 0;
  origin_x = origin_y = 0;
  rot_angle = 0;
  scale_x = scale_y = 0;
}

void Semantic::init_Semantic(std::string fileName) {
  Parser::init_Parser(fileName);
}

void Semantic::start_Semantic() {
  Parser::start_Parser();
  Plotter::getInstance()->show();
}

void Semantic::close_Semantic() {
  Parser::close_Parser();
}

double Semantic::getExpressionValue(const std::shared_ptr<TreeNode>& root) {
  switch (root->tokenType) {
    case PLUS: {
      return getExpressionValue(root->operatorNode.Lchild) +
             getExpressionValue(root->operatorNode.Rchild);
    }
    case MINUS: {
      return getExpressionValue(root->operatorNode.Lchild) -
             getExpressionValue(root->operatorNode.Rchild);
    }
    case MUL: {
      return getExpressionValue(root->operatorNode.Lchild) *
             getExpressionValue(root->operatorNode.Rchild);
    }
    case DIV: {
      return getExpressionValue(root->operatorNode.Lchild) /
             getExpressionValue(root->operatorNode.Rchild);
    }
    case POWER: {
      return pow(getExpressionValue(root->operatorNode.Lchild),
                 getExpressionValue(root->operatorNode.Rchild));
    }
    case FUNC: {
      double tmp = getExpressionValue(root->funcNode.child);
      return root->funcNode.func->call(tmp);
    }
    case CONST_ID: {
      return root->constValue;
    }
    case T: {
      return *(root->var);
    }
    default: {
      return 0;
    }
  }
}

void Semantic::originType() {
  Parser::originType();
  origin_x = getExpressionValue(x_ptr);
  origin_y = getExpressionValue(y_ptr);
}

void Semantic::rotType() {
  Parser::rotType();
  rot_angle = getExpressionValue(angle_ptr);
}

void Semantic::forType() {
  Parser::forType();
  double start = getExpressionValue(start_ptr);
  double end = getExpressionValue(end_ptr);
  double step = getExpressionValue(step_ptr);

  bindVar(x_ptr);
  bindVar(y_ptr);
  for (var = start; var <= end; var += step) {
    double x = getExpressionValue(x_ptr);
    double y = getExpressionValue(y_ptr);
    Point p(x, y);
    p.transform(origin_x, origin_y, rot_angle, scale_x, scale_y);
    Plotter::getInstance()->draw(p);
  }
}

void Semantic::scaleType() {
  Parser::scaleType();
  scale_x = getExpressionValue(x_ptr);
  scale_y = getExpressionValue(y_ptr);
}

void Semantic::bindVar(const std::shared_ptr<TreeNode>& root) {
  switch (root->tokenType) {
    case PLUS: {
      bindVar(root->operatorNode.Lchild);
      bindVar(root->operatorNode.Rchild);
      break;
    }
    case MINUS: {
      bindVar(root->operatorNode.Lchild);
      bindVar(root->operatorNode.Rchild);
      break;
    }
    case MUL: {
      bindVar(root->operatorNode.Lchild);
      bindVar(root->operatorNode.Rchild);
      break;
    }
    case DIV: {
      bindVar(root->operatorNode.Lchild);
      bindVar(root->operatorNode.Rchild);
      break;
    }
    case POWER: {
      bindVar(root->operatorNode.Lchild);
      bindVar(root->operatorNode.Rchild);
      break;
    }
    case FUNC: {
      bindVar(root->funcNode.child);
      break;
    }
    case CONST_ID: {
      break;
    }
    case T: {
      root->var = &var;
      break;
    }
    default: {
      break;
    }
  }
}
