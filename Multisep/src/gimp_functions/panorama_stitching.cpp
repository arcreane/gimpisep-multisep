#include <string>
#include "../tinyfiledialogs/tinyfiledialogs.h"
#include <opencv2/opencv.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"
#include <iostream>
#include "panorama_stitching.h"
#include <fstream>

using namespace std;
using namespace cv;

Mat panorama_stitching(string windowName, Mat image, int& save) {
	Stitcher::Mode mode = Stitcher::PANORAMA;
	Mat image_modified;
	int close = 0;

	string pathSecondImage;
	Mat secondImage;
	pathSecondImage = tinyfd_openFileDialog("", "", 0, NULL, "image files", 0);
	secondImage = imread(pathSecondImage, IMREAD_COLOR);

	vector<Mat> imgs;
	imgs.push_back(image);
	imgs.push_back(secondImage);
	Ptr<Stitcher> stitcher = Stitcher::create(mode);
	Stitcher::Status status = stitcher->stitch(imgs, image_modified);

	if (status != Stitcher::OK)
	{
		cout << "Can't stitch images, error code = " << int(status) << endl;
		image_modified = image;
	}
	else {

			while (close != 1) {
			createTrackbar("Save", windowName, &save, 1);
			createTrackbar("Close", windowName, &close, 1);
			imshow(windowName, image_modified);
			waitKey(50);
		}
	};
		
	destroyWindow(windowName);
	return image_modified;
}
