#include <opencv2/opencv.hpp>

#ifndef DEF_MYIMAGE
#define DEF_MYIMAGE

class MyImage
{
	public:
		MyImage();   // constructor
		void to_lighten_darken(std::string windowName);
		void to_dilate_erode(std::string windowName);
		void to_stitch_panorama(std::string windowName);
		void to_save();

	private:
		char const* m_pathImage;
		int m_save;
		cv::Mat m_image;
		cv::Mat m_originalImage;
		std::string m_name;
};


#endif

