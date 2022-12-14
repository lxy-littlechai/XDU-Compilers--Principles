//
// Created by littlechai on 22-12-9.
//
#include <iostream>
#include "Plotter.h"

Plotter::Plotter() {
    picture = cv::Mat(600, 1000, CV_8UC3,cv::Scalar(255, 255, 255, 0.5));
}

std::shared_ptr<Plotter> Plotter::getInstance() {
    static std::shared_ptr<Plotter> instance = std::shared_ptr<Plotter>(new Plotter());
    return instance;
}

void Plotter::draw(Point p) {

    cv::Point center = cv::Point (p.x, p.y);
    cv::circle(picture, center, p.size, cv::Scalar(p.color.R,p.color.G,p.color.B), -1);
}

void Plotter::show() {
    cv::imshow("test", picture);
    cv::waitKey(0);
}