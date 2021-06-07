#include <opencv2/opencv.hpp>
#include <iostream>
#include <sstream>
#include "services/CheckInt.h"

#include "MyImage.h"

using namespace cv;
using namespace std;

int main()
{
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
		MyImage workedImage = MyImage();

		switch (userChoice) {
		case 1:
			cout << "1 - Dilatation / Erosion" << endl;
			workedImage.to_dilate_erode("Worked Image");
			break;
		case 2:
			cout << "2 -Resizing" << endl;

			break;
		case 3:
			cout << "3 - Lighten / Darken" << endl;
			workedImage.to_lighten_darken("Worked Image");
			workedImage.to_save();
			break;
		case 4:
			cout << "4 - Panorama / Stitching" << endl;
			workedImage.to_stitch_panorama("Worked Image");
			break;
		case 5:
			cout << "5 - Canny Edge Detection" << endl;
			break;
		case -1:
			cout << "See you next time !" << endl;
			break;
		default:
			cout << "\nThis is not a valid option !" << endl;
			break;
		}
	} while (userChoice != -1);
	return 0;
}
