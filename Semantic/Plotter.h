//
// Created by littlechai on 22-12-9.
//

#ifndef PLOTTER_INTERPRETER_PLOTTER_H
#define PLOTTER_INTERPRETER_PLOTTER_H

#include <iostream>
#include <memory>
#include "Point.h"

class Plotter {
 public:
  static std::shared_ptr<Plotter> getInstance();
  void draw(Point p);
  void show();

 private:
  Plotter();
  HWND hwnd;
  HDC hdc;
};

#endif  // PLOTTER_INTERPRETER_PLOTTER_H
