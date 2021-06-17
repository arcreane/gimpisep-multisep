#ifndef DILATE_ERODE_H
#define DILATE_ERODE_H
#include <opencv2/opencv.hpp>

cv::Mat dilatation(cv::Mat image, int value);

cv::Mat erosion(cv::Mat image, int value);

cv::Mat dilate_erosion(std::string windowName, cv::Mat image, int& save);

#endif