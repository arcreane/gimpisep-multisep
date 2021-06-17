#include "../services/checkInt.h"
#include <iostream>
#include <fstream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat resizing(string windowName, Mat img, int& save) {

    //Variables

	Mat imageModified;
	int resizeX = 9, resizeY = 9, close = 0;
	namedWindow(windowName, WINDOW_AUTOSIZE);
    
	while (close != 1) {
		createTrackbar("X factor", windowName, &resizeX, 99);
		createTrackbar("Y factor", windowName, &resizeY, 99);

		createTrackbar("Save", windowName, &save, 1);        
		createTrackbar("Close", windowName, &close, 1);
		
		cv::resize(img, imageModified, Size(), (resizeX+1) / 10.0, (resizeY+1) / 10.0, INTER_LINEAR);
	
		imshow(windowName, imageModified);
		waitKey(50);
	}

	destroyWindow(windowName);
    return imageModified;
}
