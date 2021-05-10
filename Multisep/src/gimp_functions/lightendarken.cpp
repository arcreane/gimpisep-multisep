#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void lightendarken(Mat & image, int pixelValue) {
	Size size = image.size();
	Vec3b pixelValuesVec = cv::Vec3b(pixelValue, pixelValue, pixelValue);
	for (int i = 0; i < size.height; i++) {
		for (int j = 0; j < size.width; j++) {
			//for (int c = 0; c < image.channels(); c++) {
				image.at<Vec3b>(i, j) = image.at<Vec3b>(i, j) + pixelValuesVec;
				// correct the pixel if there is an overflow
				//if (image.at<Vec3b>(i, j)[c] > 255) {
				//	image.at<Vec3b>(i, j)[c] = 255;
				//}
				//else if (image.at<Vec3b>(i, j)[c] < 0) {
				//	image.at<Vec3b>(i, j)[c] = 0;
				//}
			//}
		}
	}
}


//void maxMat(Mat image) {
//	Size size = image.size();
//	int maxV = 0;
//	for (int i = 0; i < size.height; i++) {
//		for (int j = 0; j < size.width; j++) {
//			//if(max(image.at<Vec3b>(i, j).val)>maxV)
//		}
//	}
//}



