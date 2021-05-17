#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int video_bright(VideoCapture cap, int alpha, int beta) {
    // if not success, exit program

    if (!cap.isOpened()) {
        cout << "Error opening video stream or file" << endl;
        return -1;
    }


    //Defining window names

    //namedWindow("Original image");
    namedWindow("Modified image");

    //Create and open windows for above window names


    while (true)
    {
        Mat frame, new_frame;
        // read a new frame from video

        cap >> frame;
        //Breaking the while loop at the end of the video
        if (frame.empty()) {
            break;
        }

        //modify the brightness
        frame.convertTo(new_frame, -1, alpha, beta);

        //Show above frames inside the created windows.
        //imshow("Original image", frame);
        imshow("Modified image", new_frame);

        //wait for for 10 ms until any key is pressed.
        //If the 'Esc' key is pressed, break the while loop.
        //If the any other key is pressed, continue the loop
        //If any key is not pressed withing 10 ms, continue the loop
        if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by user. Stopping the video" << endl;
            break;
        }
    }
}







