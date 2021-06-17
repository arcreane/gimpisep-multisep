#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat dilatation(Mat image, int value){
	Mat image_modified;
    int n = 2 * value + 1;
    Mat kernel = getStructuringElement(MORPH_RECT, Size(n, n), Size(value, value));
    dilate(image, image_modified, kernel);
	return image_modified;
}

Mat erosion(Mat image, int value){
	Mat image_modified;
    int n = 2 * value + 1;
    Mat kernel = getStructuringElement(MORPH_RECT, Size(n, n), Size(value, value));
    erode(image, image_modified, kernel);
	return image_modified;
}

Mat dilate_erosion(string windowName, Mat img, int& save) 
{
	Mat image_modified;
    int close = 0;
	int mode = 0;
	int value = 0;
    namedWindow(windowName, WINDOW_AUTOSIZE);

    while(close !=1){
		createTrackbar("Mode", windowName, &mode, 1);
		createTrackbar("Kernel 2n+1", windowName, &value, 10);
        createTrackbar("Save", windowName, &save, 1);
		createTrackbar("Close", windowName, &close, 1);

		if (mode == 0) {
			image_modified = erosion(img,value);
		}
		else {
			image_modified = dilatation(img, value);
		}

		imshow(windowName, image_modified);
		waitKey(50);
    }

    destroyWindow(windowName);
    return image_modified; 
}
