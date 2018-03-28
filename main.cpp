#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;

int main() {
	Mat img = imread("C:/opencv/sources/samples/data/lena.jpg", 0);
	if (img.empty()) {
		std::cout << "not found" << std::endl;
		return -1;
	}

	double data[][3] = {
		{ 1, 2, 1 },
	    { 2, 4, 2 },
	    { 1, 2, 1 }
	};

	Mat dst = Mat::zeros(img.rows, img.cols, CV_8U);
	for (int j = 1; j < img.rows - 1; j++) {
		for (int i = 1; i < img.cols - 1; i++) {
			int tmp = 0;
			for (int jj = -1; jj < 2; jj++) {
				for (int ii = -1; ii < 2; ii++) {
					tmp += img.at<uchar>(j + jj, i + ii) * data[jj + 1][ii + 1];
				}
			}
			tmp = tmp / 16;
			if (tmp < 0) tmp = -tmp;
			if (tmp > 255) tmp = 255;
			dst.at<uchar>(j, i) = tmp;
		}
	}

	namedWindow("View", WINDOW_AUTOSIZE);
	imshow("View", img);
	namedWindow("FILTER", WINDOW_AUTOSIZE);
	imshow("FILTER", dst);
	waitKey(0);

	system("pause");
	return 0;
}