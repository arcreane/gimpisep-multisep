#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "video_face_recognition.h"

using namespace cv;
using namespace std;

// paths below have to be adapted
String face_cascade_path = "D:/Installs/opencv/data/haarcascades/haarcascade_frontalface_alt.xml";
String eyes_cascade_path = "D:/Installs/opencv/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml";


CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;
string window_name = "Capture - Face detection";

int video_face_recognition(VideoCapture& cap)
{
    Mat frame;

    //-- 1. Load the cascades
    if (!face_cascade.load(face_cascade_path)) {
        cout << "Error loading\n" << face_cascade_path << endl;
        return -1;
    };
    if (!eyes_cascade.load(eyes_cascade_path)) {
        cout << "Error loading\n" << eyes_cascade_path << endl;
        return -1;
    };

    //-- 2. Read the video stream
    while (true)
    {
        cap >> frame;

        //-- 3. Apply the classifier to the frame
        if (!frame.empty()){
            detectAndDisplay(frame);
        }
        else {
            break;
        }

        if (waitKey(1) == 27){
            cout << "Esc key is pressed by user. Stopping the video" << endl;
            break;
        }
    }
    destroyWindow(window_name);
    return 0;
}


void detectAndDisplay(Mat frame)
{
    std::vector<Rect> faces;
    Mat frame_gray;

    cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
    equalizeHist(frame_gray, frame_gray);

    //-- Detect faces
    face_cascade.detectMultiScale(frame_gray, faces, 1.2, 4, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

    for (size_t i = 0; i < faces.size(); i++)
    {
        Point center(faces[i].x + faces[i].width * 0.5, faces[i].y + faces[i].height * 0.5);
        ellipse(frame, center, Size(faces[i].width * 0.5, faces[i].height * 0.5), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);

        Mat faceROI = frame_gray(faces[i]);
        std::vector<Rect> eyes;

        //-- In each face, detect eyes
        eyes_cascade.detectMultiScale(faceROI, eyes, 1.2, 3, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

        for (size_t j = 0; j < eyes.size(); j++)
        {
            Point center(faces[i].x + eyes[j].x + eyes[j].width * 0.5, faces[i].y + eyes[j].y + eyes[j].height * 0.5);
            int radius = cvRound((eyes[j].width + eyes[j].height) * 0.25);
            circle(frame, center, radius, Scalar(255, 0, 0), 4, 8, 0);
        }
    }
    //-- Show what you got
    imshow(window_name, frame);
}
