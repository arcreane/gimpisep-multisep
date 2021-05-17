#include "MyImage.h"
#include "tinyfiledialogs/tinyfiledialogs.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <sstream>
#include "services/CheckInt.h"
#include "gimp_functions/lighten_darken.h"
using namespace cv;


MyImage::MyImage() {
		m_pathImage = tinyfd_openFileDialog("", "", 0, NULL, "image files", 0);

		m_name = "Image file";
		m_originalImage = imread(m_pathImage, IMREAD_COLOR);
		m_image = m_originalImage.clone();
		m_save = 0;
		
}   // constructor


void MyImage::to_lighten_darken(std::string windowName) {
		m_image = show_lighten_darken(windowName, m_originalImage, m_save);
}

void MyImage::to_save() {
	m_pathImage = tinyfd_saveFileDialog("", "", 0, NULL, "image files");
	imwrite(m_pathImage, m_image);

}



