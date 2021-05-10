#include <opencv2/opencv.hpp>

using namespace cv;

void lighten_darken(Mat & image, int pixelValue) {
	image.convertTo(image, -1, 1, pixelValue);
}




