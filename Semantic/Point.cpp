//
// Created by littlechai on 22-12-9.
//

#include <cmath>
#include "Point.h"

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

void Point::transform(double origin_x, double origin_y, double rot_angle, double scale_x, double scale_y) {
    x *= scale_x;
    y *= scale_y;

    double x_temp = x * cos(rot_angle) + y * sin(rot_angle);
    y = y * cos(rot_angle) - x * sin(rot_angle);
    x = x_temp;

    x += origin_x;
    y += origin_y;
}