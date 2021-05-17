#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

Mat lighten_darken(Mat image, int pixelValue) {
	Mat image_modified;
	image.convertTo(image_modified, -1, 1, pixelValue);
	return image_modified;
}


void show_lighten_darken(string windowName, Mat image) {
	int brightnessValue = 0, darknessValue = 0, value = 0, close = 0, save = 0;
	Mat image_modified;
	namedWindow(windowName, WINDOW_AUTOSIZE);
	while (close != 1) {
		createTrackbar("Brightness", windowName, &brightnessValue, 255);
		createTrackbar("Darkness", windowName, &darknessValue, 255);
		createTrackbar("Save", windowName, &save, 1);
		createTrackbar("Close", windowName, &close, 1);

		value = brightnessValue - darknessValue;
		cout << value << endl;

		image_modified = lighten_darken(image, value);
		imshow(windowName, image_modified);
		waitKey(50);
	}

	if (save == 1) {
		// voir tinyfiledialogs
	}
	destroyWindow(windowName);
	// faire une fonction sauvegarder ? ou return la dernière image ?


}





