#include <opencv2/opencv.hpp>
#include <iostream>
#include <sstream>

#include "gimp_functions/lighten_darken.h"


using namespace cv;
using namespace std;

int main()
{

	//cout << "Welcome in your favorite image editor" << endl;
	//cout << "Choose what you want to do with your image" << endl;
	//cout << "Enter the int associated with your choice" << endl;
	//cout << "1 - Dilatation / Erosion" << endl;
	//cout << "2 - Resizing" << endl;
	//cout << "3 - Lighten / Darken" << endl;
	//cout << "4 - Panorama / Stitching" << endl;
	//cout << "5 - Canny Edge Detection" << endl;
	//int userChoice;
	//cin >> userChoice;
	//while (cin.fail()) {
	//	cout << "This is not an int..." << endl;
	//	cin.clear();
	//	cin.ignore(256, '\n');
	//	cin >> userChoice;
	//}


	//switch (userChoice) {
	//case 1 :
	//	cout << "1 - Dilatation / Erosion" << endl;
	//	break;
	//case 2:
	//	cout << "2 - Resizing" << endl;
	//	break;
	//case 3:
	//	cout << "3 - Lighten / Darken" << endl;
	//	break;
	//case 4:
	//	cout << "4 - Panorama / Stitching" << endl;
	//	break;
	//case 5:
	//	cout << "5 - Canny Edge Detection" << endl;
	//	break;
	//default:
	//	cout << "This is not a valid option" << endl;
	//	break;
	//}
	//String waitingTime;
	//cin >> waitingTime;

	Mat image, image2;
	image = imread("HappyFish.jpg", IMREAD_COLOR);
	image2 = imread("HappyFish.jpg", IMREAD_COLOR);
	if (image.empty()) {
		cout << "No data" << endl;
	}
	//namedWindow("Goddamn Hippies", WINDOW_AUTOSIZE );
	//imshow("Goddamn Hippies", image );

	Size size = image.size();




	imshow("Happy Fish", image);
	lighten_darken(image, 150);
	imshow("Happy Fish lighten", image);
	lighten_darken(image2, -80);
	imshow("Happy Fish darken", image2);

	waitKey(0);


    return 0;
}
