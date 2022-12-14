//
// Created by littlechai on 22-12-9.
//

#ifndef PLOTTER_INTERPRETER_POINT_H
#define PLOTTER_INTERPRETER_POINT_H
#include "Token.h"

struct Color {
    int R, G, B;
};

class Point {
public:
    Point(double x=0, double y=0, int size = 1, Color color = {0, 0, 0});
    void transform(double origin_x, double origin_y, double rot_angle, double scale_x, double scale_y);

    double x, y;
    int size;
    Color color;
};


#endif //PLOTTER_INTERPRETER_POINT_H
