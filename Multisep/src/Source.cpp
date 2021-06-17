#include <opencv2/opencv.hpp>
#include <iostream>
#include <sstream>
#include "services/checkInt.h"

#include "MyImage.h"
#include "MyVideo.h"

using namespace cv;
using namespace std;

int main()
{
	int userChoice, fileChoice;

	cout << "\nWelcome to your favorite image editor" << endl;

	do {

		cout << "Press 1 to work with an image" << endl;
		cout << "Press 2 to work with a video" << endl;
		cout << "-1 - To exit\n" << endl;

		fileChoice = checkInt();
		if (fileChoice == 1) {

			do {
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
				if (userChoice != -1) {
					workedImage.browseImage();
				}

				switch (userChoice) {
					case 1:
						cout << "1 - Dilatation / Erosion" << endl;
						workedImage.to_dilate_erode("Worked Image");
						break;
					case 2:
						cout << "2 -Resizing" << endl;
						workedImage.to_resize("Worked Image");
						break;
					case 3:
						cout << "3 - Lighten / Darken" << endl;
						workedImage.to_lighten_darken("Worked Image");
						break;
					case 4:
						cout << "4 - Panorama / Stitching" << endl;
						cout << "Please select 2 images" << endl;
						workedImage.to_stitch_panorama("Worked Image");
						break;
					case 5:
						cout << "5 - Canny Edge Detection" << endl;
						break;
					case -1:
						break;
					default:
						cout << "\nThis is not a valid option !" << endl;
						break;
				}
				if (workedImage.getM_save() == 1) {
					workedImage.to_save();
				}
			} while (userChoice != -1);

		} if (fileChoice == 2) {
			cout << "Choose what you want to do with your video" << endl;
			cout << "1 - Bright / Contrast" << endl;
			cout << "2 - Face recognition" << endl;
			cout << "-1 - To exit\n" << endl;

			userChoice = checkInt();
			MyVideo workedVideo = MyVideo();
			if (userChoice != -1) {
				workedVideo.browseVideo();
			}

			switch (userChoice) {
			case 1:
				cout << "1 - Dilatation / Erosion" << endl;
				workedVideo.to_bright_contrast();
				break;
			case 2:
				cout << "2 - Face recognition" << endl;
				workedVideo.to_face_recognition();
				break;
			case -1:
				break;
			default:
				cout << "\nThis is not a valid option !" << endl;
				break;
			}
		}
	} while (fileChoice != -1);

	cout << "See you next time !" << endl;
	return 0;
}
