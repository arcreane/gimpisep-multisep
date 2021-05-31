#ifndef DILATE_ERODE_H
#define DILATE_ERODE_H
#include <opencv2/opencv.hpp>

int dilate_erosion(std::string windowName, cv::Mat image, int& save);

#endif