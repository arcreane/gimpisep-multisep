#include <opencv2/opencv.hpp>
#include "video_bright_contrast.h"

using namespace cv;
using namespace std;


int video_bright_contrast(VideoCapture & cap, int parameters[]) {
        // if not success, exit program
    if (!cap.isOpened()) {
        return -1;
    }

    //namedWindow("Original image");
    string windowName = "Modified image";
    namedWindow(windowName, WINDOW_AUTOSIZE);

    //Create and open windows for above window names
    const int DEFAULT_brightnessValue = 255;
    int brightnessValue = DEFAULT_brightnessValue, contrast_int = 100, value = 0, save = 0, close = 0;
    float contrast = 0.0;

    while (close != 1) {

        createTrackbar("Brightness", windowName, &brightnessValue, 511);
        createTrackbar("Constrast", windowName, &contrast_int, 1000);
        createTrackbar("Save", windowName, &save, 1);
        createTrackbar("Close", windowName, &close, 1);
        value = brightnessValue - DEFAULT_brightnessValue;   // because the minimum value of the track bar is 0, we need negative value for darkness
        contrast = (float) contrast_int / 100;
        Mat frame, new_frame;
        // read a new frame from video

        cap >> frame;
        //Breaking the while loop at the end of the video
        if (frame.empty()) {
            break;
        }

        //modify the brightness and the contrast
        frame.convertTo(new_frame, -1, contrast, value);

        //Show above frames inside the created windows.
        //imshow("Original image", frame);
        imshow("Modified image", new_frame);

        //wait for for 10 ms until any key is pressed.
        //If the 'Esc' key is pressed, break the while loop.
        //If the any other key is pressed, continue the loop
        //If any key is not pressed within 10 ms, continue the loop
        if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by user. Stopping the video" << endl;
            break;
        }
    }

    parameters[0] = save;
    parameters[1] = contrast_int;   //need to divide it by 100, but we need an int in the array
    parameters[2] = value;          //brightness value
    
    destroyWindow(windowName);

    return 0;           // no error, we return 0
}

