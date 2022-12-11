//
// Created by littlechai on 22-12-9.
//
#include "Plotter.h"
#include <iostream>

Plotter::Plotter() {}

std::shared_ptr<Plotter> Plotter::getInstance() {
  static std::shared_ptr<Plotter> instance =
      std::shared_ptr<Plotter>(new Plotter());
  return instance;
}

void Plotter::draw(Point p) {}

void Plotter::show() {
  _
}