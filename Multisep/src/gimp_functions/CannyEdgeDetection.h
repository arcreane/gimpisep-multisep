#ifndef CANNY_EDGE_DETECTION_H
#define CANNY_EDGE_DETECTION_H
#include <opencv2/opencv.hpp>

cv::Mat detectEdge(cv::Mat image, int firstThreshold, int secondThreshold);

cv::Mat cannyEdgeDetection(std::string windowName, cv::Mat image, int& save);

#endif
