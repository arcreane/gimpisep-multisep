#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat image;
    image = imread("../images/pokemon.jpg");
    if(image.empty()){
        cout << "No data" << endl;
        return -1;
    }
    namedWindow("Goddamn Hippies", WINDOW_AUTOSIZE );
    imshow("Goddamn Hippies", image );

    waitKey(0);

    return 0;
}