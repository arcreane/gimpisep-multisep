#include <opencv2/opencv.hpp>

#ifndef DEF_MYVIDEO
#define DEF_MYVIDEO

class MyVideo
{
public:
	MyVideo();   // constructor

	//void to_dilate_erode(std::string windowName);
	//void to_stitch_panorama(std::string windowName);
	int to_bright_contrast();
	void to_save();
	//void setM_video(cv::VideoCapture cap);

private:
	char const* m_pathVideo;
	int m_save;
	int m_parameters[3] = {0, 0, 0};
	//std::vector<int> m_parameters;
	cv::VideoCapture m_video;
	cv::VideoCapture m_originalVideo;
	std::string m_name;
};


#endif

