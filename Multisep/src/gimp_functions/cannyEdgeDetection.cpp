#include "../services/checkInt.h"
#include <iostream>
#include <fstream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat detectEdge(Mat image, int firstThreshold, int secondThreshold) {

	Mat imageModified, imageBlured;

	GaussianBlur(image, imageBlured, Size(5, 5), 0, 0);

	Canny(imageBlured, imageModified, firstThreshold, secondThreshold);

	return imageModified;
}

Mat cannyEdgeDetection(string windowName, Mat img, int& save) {

	Mat image_modified;

	int firstThreshold = 0, secondThreshold = 100, close = 0;
	namedWindow(windowName, WINDOW_AUTOSIZE);

	while (close != 1) {
		createTrackbar("First Threshold", windowName, &firstThreshold, 100);
		createTrackbar("Second Threshold", windowName, &secondThreshold, 200);

		createTrackbar("Save", windowName, &save, 1);
		createTrackbar("Close", windowName, &close, 1);

		image_modified = detectEdge(img, firstThreshold, secondThreshold);

		imshow(windowName, image_modified);
		waitKey(50);
	}

	destroyWindow(windowName);

	return image_modified;

}
