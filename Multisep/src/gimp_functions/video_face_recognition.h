#ifndef VIDEO_FACE_RECOGNITION_H
#define VIDEO_FACE_RECOGNITION_H
#include <opencv2/opencv.hpp>

// Function for Face Detection
int video_face_recognition(cv::VideoCapture& cap);

void detectAndDisplay(cv::Mat frame);


#endif