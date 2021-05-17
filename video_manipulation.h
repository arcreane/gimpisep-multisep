#include <opencv2/opencv.hpp>

#ifndef VIDEO_MANIPULATION_H
#define VIDEO_MANIPULATION_H

int video_bright(cv::VideoCapture cap, int alpha, int beta);   // return -1 if video not read

#endif