#include <opencv2/opencv.hpp>
#include <iostream>
#include "../services/CheckInt.h"

using namespace cv;
using namespace std;

int size_dilatation = 0;
int size_erosion = 0;
Mat image, kernel, image_modified;

static void Dilatation(int, void*){
    int n = 2 * size_dilatation + 1;
    Mat kernel = getStructuringElement(MORPH_RECT, Size(n, n), Size(size_dilatation, size_dilatation));
    dilate(image, image_modified, kernel);
    imshow("Modified images", image_modified);
}

static void Erosion(int, void*){
    int n = 2 * size_erosion + 1;
    Mat kernel = getStructuringElement(MORPH_RECT, Size(n, n), Size(size_erosion, size_erosion));
    erode(image, image_modified, kernel);
    imshow("Modified images", image_modified);
}

Mat dilate_erosion(string windowName, Mat img, int& save) 
{
    image = img;
    int close = 0;
    namedWindow(windowName, WINDOW_AUTOSIZE);

    while(close !=1){
        createTrackbar("Dilatation", windowName, &size_dilatation, 10, Dilatation );
        createTrackbar("Erosion", windowName, &size_erosion, 10, Erosion );
        createTrackbar("Save", windowName, &save, 1);
		createTrackbar("Close", windowName, &close, 1);

        imshow(windowName, image_modified);
    }

    destroyWindow(windowName);
    return image_modified; 
}
