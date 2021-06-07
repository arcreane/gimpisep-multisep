#include <string>
#include "../tinyfiledialogs/tinyfiledialogs.h"
#include <opencv2/opencv.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"
#include <iostream>


using namespace std;
using namespace cv;

Mat panorama_stitching(String windowName, Mat image) {
	Stitcher::Mode mode = Stitcher::PANORAMA;
	Mat image_modified;

	String pathSecondImage;
	Mat secondImage;
	pathSecondImage = tinyfd_openFileDialog("", "", 0, NULL, "image files", 0);
	secondImage = imread(pathSecondImage, IMREAD_COLOR);

	vector<Mat> imgs;
	imgs.push_back(image);
	imgs.push_back(secondImage);
	Ptr<Stitcher> stitcher = Stitcher::create(mode);
	Stitcher::Status status = stitcher->stitch(imgs, image_modified);

	if (status != Stitcher::OK)
		{
			cout << "Can't stitch images, error code = " << int(status) << endl;
		}

	imshow(windowName, image_modified);
	waitKey(50);
	destroyWindow(windowName);
	return image_modified;
}

//bool divide_images = false;
//Stitcher::Mode mode = Stitcher::PANORAMA;
//vector<Mat> imgs;
//string result_name = "result.jpg";
//
//void printUsage(String argv[]);
//int parseCmdArgs(int argc, String argv[]);
//
//int panorama_stitching(int argc, String argv[])
//{
//	int retval = parseCmdArgs(argc, argv);
//	if (retval) return EXIT_FAILURE;
//	Mat pano;
//	Ptr<Stitcher> stitcher = Stitcher::create(mode);
//	Stitcher::Status status = stitcher->stitch(imgs, pano);
//	if (status != Stitcher::OK)
//	{
//		cout << "Can't stitch images, error code = " << int(status) << endl;
//		return EXIT_FAILURE;
//	}
//	imwrite(result_name, pano);
//	cout << "stitching completed successfully\n" << result_name << " saved!";
//	return EXIT_SUCCESS;
//}
//void printUsage(String argv[])
//{
//	cout <<
//		"Images stitcher.\n\n" << "Usage :\n" << argv[0] << " [Flags] img1 img2 [...imgN]\n\n"
//		"Flags:\n"
//		"  --d3\n"
//		"      internally creates three chunks of each image to increase stitching success\n"
//		"  --mode (panorama|scans)\n"
//		"      Determines configuration of stitcher. The default is 'panorama',\n"
//		"      mode suitable for creating photo panoramas. Option 'scans' is suitable\n"
//		"      for stitching materials under affine transformation, such as scans.\n"
//		"  --output <result_img>\n"
//		"      The default is 'result.jpg'.\n\n"
//		"Example usage :\n" << argv[0] << " --d3 --mode scans img1.jpg img2.jpg\n";
//}
//int parseCmdArgs(int argc, String argv[])
//{
//	if (argc == 1)
//	{
//		printUsage(argv);
//		return EXIT_FAILURE;
//	}
//	
//	else
//	{
//		Mat img = imread(samples::findFile(argv[i]));
//		if (img.empty())
//		{
//			cout << "Can't read image '" << argv[i] << "'\n";
//			return EXIT_FAILURE;
//		}
//		if (divide_images)
//		{
//			Rect rect(0, 0, img.cols / 2, img.rows);
//			imgs.push_back(img(rect).clone());
//			rect.x = img.cols / 3;
//			imgs.push_back(img(rect).clone());
//			rect.x = img.cols / 2;
//			imgs.push_back(img(rect).clone());
//			}
//		else
//			imgs.push_back(img);
//		}
//	}
//	return EXIT_SUCCESS;
//}