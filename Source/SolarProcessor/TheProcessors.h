/*
SolarEye Processor build May 27, 2017.
By Gemeinschaft Team :
Muhammad S. Yahya S. (41578), Gofindo Saputra S. (41656), Edy Sutrisno (42532), Novega Ghufron A. (42502).
*/

#define _USE_MATH_DEFINES
#include <cmath>
#include <ctime>
#include <opencv2\opencv.hpp>

using namespace std;

double sunDistanceKM(int day){
	double r = (1 - 0.01672 * cos((0.9856 * (day - 4)) * M_PI / 180.0)); //persamaan mengitung jarak bumi-matahari (dalam AU) pada suatu hari
	r = r * 149597870.691; //konversi satuan jarak dari AU ke km
	return r;
	//Referensi : http://asprs.org/a/publications/proceedings/tampa2007/0079.pdf
}

double sunApprntDCalc(double r){
	double D = 2 * atan(1391400.0 / (2 * r)); //menghitung diameter visual matahari pada hari yang telah ditentukan (dalam radian)
	D = D * 3600 * (180 / M_PI); //konversi satuan sudut dari radian ke arcsec
	return D;
}

cv::Mat deteksiMatahari(cv::Mat frame, int etresh, int ctresh, bool *errorStatus, vector<cv::Vec3f>* circles){
	cv::Mat img, gframe;
	frame.copyTo(img);
	vector<cv::Vec3f> &circ = *circles; //alamat dari circ sama dengan pointer
	cv::cvtColor(img, gframe, cv::COLOR_BGR2GRAY); //konversi ke grayscale
	cv::GaussianBlur(gframe, gframe, cv::Size(9, 9), 2, 2); //mengurangi noise dengan blur
	cv::HoughCircles(gframe, circ, cv::HOUGH_GRADIENT, 1, gframe.rows / 8, etresh, ctresh, 0.05*gframe.rows, gframe.rows); //operasi deteksi lingkaran
	for (size_t i = 0; i < circ.size(); i++)
	{
		cv::Point center(cvRound(circ[i][0]), cvRound(circ[i][1]));
		int radius = cvRound(circ[i][2]);
		cv::circle(img, center, 3, cv::Scalar(0, 255, 0), -1, 8, 0); //gambarkan pusat lingkaran
		cv::circle(img, center, radius, cv::Scalar(0, 0, 255), 3, 8, 0); //gambarkan garis tepi lingkaran
	}
	if (circ.size() != 1){
		*errorStatus = 1;
	}
	else *errorStatus = 0;
	return img;
}