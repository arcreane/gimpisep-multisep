#include <opencv2/opencv.hpp>

#ifndef DEF_MYVIDEO
#define DEF_MYVIDEO

class MyVideo
{
public:
	MyVideo();   // constructor

	void to_bright_contrast();
	void to_face_recognition();
	void to_save();

private:
	char const* m_pathVideo;
	int m_save;
	int m_parameters[3] = {0, 0, 0};
};


#endif

