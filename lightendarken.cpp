#include <opencv2/opencv.hpp>
#include "lightendarken.h"

using namespace cv;
using namespace std;

void lightendarken(Mat & image, int pixelValue) {
	Size size = image.size();
	for (int i = 0; i < size.height; i++) {
		for (int j = 0; j < size.width; j++) {
			for (int c = 0; c < image.channels(); c++) {
				image.at<Vec3b>(i, j)[c] += pixelValue;
			}
		}
	}
}



