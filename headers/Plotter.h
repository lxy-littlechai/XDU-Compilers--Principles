//
// Created by littlechai on 22-12-9.
//

#ifndef PLOTTER_INTERPRETER_PLOTTER_H
#define PLOTTER_INTERPRETER_PLOTTER_H

#include <memory>
#include "Point.h"
#include <iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

class Plotter {
public:
    static std::shared_ptr<Plotter> getInstance();
    void draw(Point p);
    void show();

private:
    Plotter();
    cv::Mat picture;
};


#endif //PLOTTER_INTERPRETER_PLOTTER_H
