#include "MyVideo.h"
#include "gimp_functions/video_bright_contrast.h"
#include "tinyfiledialogs/tinyfiledialogs.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <sstream>

using namespace cv;
using namespace std;

MyVideo::MyVideo()
{
	m_pathVideo = tinyfd_openFileDialog("", "", 0, NULL, "image files", 0);
	m_save = 0;

} // constructor


int MyVideo::to_bright_contrast() {   // -1 --> the video has not been read correctly
	//open the video file for reading
	VideoCapture cap(m_pathVideo);
	video_bright_contrast(cap, m_parameters);

	if (m_parameters[0] == 1) {		// if save == 1
		to_save();
	}

	return 0;
}


void MyVideo::to_save()
{
	VideoCapture cap(m_pathVideo);

	// Default resolutions of the frame are obtained.The default resolutions are system dependent.
	int frame_width = cap.get(CAP_PROP_FRAME_WIDTH);
	int frame_height = cap.get(CAP_PROP_FRAME_HEIGHT);

	// Define the codec and create VideoWriter object.The output is stored in 'outcpp.avi' file.
	m_pathVideo = tinyfd_saveFileDialog("", "", 0, NULL, "image files");
	VideoWriter video_to_save(m_pathVideo, VideoWriter::fourcc('M', 'J', 'P', 'G'), 10, Size(frame_width, frame_height));   // " .avi" file

	float contrastValue = (float)m_parameters[1] / 100;
	int brightnessValue = m_parameters[2];

	while (1) {

		Mat frame, modified_frame;
		// Capture frame-by-frame
		cap >> frame;

		// If the frame is empty, break immediately
		if (frame.empty()) {
			break;
		}

		//modify the brightness and the contrast
		frame.convertTo(modified_frame, -1, contrastValue, brightnessValue);   // modify the contrast and brightness


		// Write the modified_frame into the file m_pathVideo
		video_to_save.write(modified_frame);

		// Press  ESC on keyboard to  exit
		char c = (char)waitKey(1);
		if (c == 27)
			break;
	}

	// When everything done, release the video capture and write object
	video_to_save.release();
}
