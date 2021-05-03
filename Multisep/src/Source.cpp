#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat image;
    image = imread("HappyFish.jpg");
    if(image.empty()){
        cout << "No data" << endl;
    }
    namedWindow("Goddamn Hippies", WINDOW_AUTOSIZE );
    imshow("Goddamn Hippies", image );

    waitKey(0);


    return 0;
}
