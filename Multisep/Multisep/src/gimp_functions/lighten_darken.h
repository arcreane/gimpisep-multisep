#ifndef LIGHTEN_DARKEN_H
#define LIGHTEN_DARKEN_H

cv::Mat lighten_darken(cv::Mat image, int pixelValue);   // the function modifies the brightness and not the contrast

cv::Mat show_lighten_darken(std::string windowName, cv::Mat image, int& save);

#endif