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


int dilate_erosion()
{
    image = imread("../images/HappyFish.jpg");
    if(image.empty()){
        cout << "No data find" << endl;
        return -1;
    }

    cout << "Welcome in the dilate/erode mode" << endl;
	cout << "Which mode do you want to use ?" << endl;
	cout << "1 - Dilatation" << endl;
	cout << "2 - Erosion" << endl;
    int userChoice;
	cin >> userChoice;
	while (cin.fail()) {
		cout << "This is not an int..." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> userChoice;
	}

    switch (userChoice) {
	case 1 :
		cout << "Welcome in the Dilatation mode" << endl;
        cout << "You can change the kernel size with the trackbar at the top of the window" << endl;
        namedWindow("Dilatation images", WINDOW_AUTOSIZE);
        createTrackbar("Kernel 2n+1", "Dilatation images", &size_dilatation, 10, Dilatation );
        Dilatation(0, 0);
        waitKey(0);
		break;
	case 2:
		cout << "Welcome in the Erosion mode" << endl;
        cout << "You can change the kernel size with the trackbar at the top of the window" << endl;
        namedWindow("Erosion images", WINDOW_AUTOSIZE);
        createTrackbar("Kernel 2n+1", "Erosion images", &size_erosion, 10, Erosion );
        Erosion(0, 0);
        waitKey(0);
		break;
	default:
		cout << "This is not a valid option" << endl;
		break;
	}
    
    return 0; 
}
