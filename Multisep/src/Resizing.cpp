#include <iostream>
#include <fstream>
#include <string>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {

    Mat source, scaleD, scaleU;
    string filename;
    ofstream fileC;
    string windowName = "test1";
    double resizeX;
    double resizeY;
    double choice;
    

    Mat image = imread("Happyfish.jpg");
    
    cout << "Do you want to :  \n 1 : Enlarge the picture \n 2 : Reduce the picture \n";
    cin >> choice;
    cout << "You chose option " << choice << "\n";

    if (choice == 1)
    {
        cout << "Type a number for X to resize : \n";
        cin >> resizeX;
        cout << "Your number for X is: \n" << resizeX << "\n";

        cout << "Type a number for Y to resize : \n";
        cin >> resizeY;
        cout << "Your number for Y is: \n" << resizeY << "\n";

        // Scaling factors
        double scaleX = resizeX;
        double scaleY = resizeY;

        //Resize
        cv::resize(image, scaleU, Size(), scaleX, scaleY, INTER_LINEAR);

        namedWindow("scalinupWindow", WINDOW_AUTOSIZE);
        imshow("scalinupWindow", scaleU);
    }

    else if (choice == 2)
    {
        cout << "Type a number for X to resize : \n";
        cin >> resizeX;
        cout << "Your number for X is: \n" << resizeX << "\n";

        cout << "Type a number for Y to resize : \n";
        cin >> resizeY;
        cout << "Your number for Y is: \n" << resizeY << "\n";

        // Scaling factors
        double scaleUpX = resizeX;
        double scaleUpY = resizeY;

        //Resize
        cv::resize(image, scaleD, Size(), scaleUpX, scaleUpY, INTER_LINEAR);

        namedWindow("scalinupWindow", WINDOW_AUTOSIZE);
        imshow("scalinupWindow", scaleD);
    }

    else {
        cout << "The number is not an option \n";
    }

    waitKey(0);

    return 0;
}