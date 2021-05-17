#include <opencv2/opencv.hpp>
#include <iostream>
#include <sstream>
#include "services/CheckInt.h"

#include "gimp_functions/lighten_darken.h"


using namespace cv;
using namespace std;

int main()
{

	Mat image, image2;
	image = imread("HappyFish.jpg", IMREAD_COLOR);
	if (image.empty()) {
		cout << "No data" << endl;
	}
	int userChoice;

	do {
		cout << "\nWelcome in your favorite image editor" << endl;
		cout << "Choose what you want to do with your image" << endl;
		cout << "Enter the int associated with your choice" << endl;
		cout << "1 - Dilatation / Erosion" << endl;
		cout << "2 - Resizing" << endl;
		cout << "3 - Lighten / Darken" << endl;
		cout << "4 - Panorama / Stitching" << endl;
		cout << "5 - Canny Edge Detection" << endl;
		cout << "-1 - To exit\n" << endl;

		userChoice = checkInt();
		int value;   // used in case 3

		switch (userChoice) {
		case 1:
			cout << "1 - Dilatation / Erosion" << endl;
			break;
		case 2:
			cout << "2 - Resizing" << endl;

			break;
		case 3:
			cout << "3 - Lighten / Darken" << endl;
			cout << "Please input a value (-255 to 255) to lighten or darken the image" << endl;

			// Ne fonctionne pas dans la boucle, mais fonctionne bien en dehors
			//cin >> value;
			//cout <<" your value : " << value << endl;
			//lighten_darken(image, value);
			//lighten_darken(image, value);
			//namedWindow("Happy Fish");
			//imshow("Happy Fish", image);

			break;
		case 4:
			cout << "4 - Panorama / Stitching" << endl;
			break;
		case 5:
			cout << "5 - Canny Edge Detection" << endl;
			break;
		case -1:
			cout << "See you next time !" << endl;
			break;
		default:
			cout << "This is not a valid option" << endl;
			break;
		}
	} while (userChoice != -1);

	//string waitingtime;
	//cin >> waitingtime;


	cout << "Please input a value (-255 to 255) to lighten or darken the image" << endl;
	int value;
	cin >> value;
	cout << " your value : " << value << endl;
	lighten_darken(image, value);
	namedWindow("Happy Fish");
	imshow("Happy Fish", image);


	waitKey(0);
	return 0;
}
