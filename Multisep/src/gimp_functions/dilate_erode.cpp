#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat image, dilateImage, erodeImage, kernel;
int size_dilatation = 0;
int size_erosion = 0;


static void Dilatation(int, void*){
    int n = 2 * size_dilatation + 1;
    kernel = getStructuringElement(MORPH_RECT, Size(n, n), Size(size_dilatation, size_dilatation));
    dilate(image, dilateImage, kernel);
    imshow("Dilatation images", dilateImage);
}

static void Erosion(int, void*){
    int n = 2 * size_erosion + 1;
    kernel = getStructuringElement(MORPH_RECT, Size(n, n), Size(size_erosion, size_erosion));
    erode(image, erodeImage, kernel);
    imshow("Erosion images", erodeImage);
}

//int main(int argc, char* argv[])
//{
//    image = imread("../images/HappyFish.jpg");
//    if(image.empty()){
//        cout << "No data find" << endl;
//        return -1;
//    }
//
//    namedWindow("Dilatation images", WINDOW_AUTOSIZE);
//    namedWindow("Erosion images", WINDOW_AUTOSIZE);
//     
//    createTrackbar("Kernel 2n+1", "Dilatation images", &size_dilatation, 10, Dilatation );
//    createTrackbar("Kernel 2n+1", "Erosion images", &size_erosion, 10, Erosion );
//    Dilatation(0, 0);
//    Erosion(0, 0);
//
//    waitKey(0);
//    return 0;
//    
//}
