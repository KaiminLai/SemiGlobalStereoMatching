#include"SGMStereo.h"
#include<iostream>
#include<cstdlib>

int main(){
	Mat lImg = imread("im2.png", CV_LOAD_IMAGE_COLOR);
	Mat rImg = imread("im6.png", CV_LOAD_IMAGE_COLOR);
	if (!lImg.data || !rImg.data){
		printf("Error: can not open image\n");
		printf("\nPress any key to continue...\n");
		getchar();
		return -1;
	}
	int hei = lImg.rows;
	int wid = rImg.cols;
	Mat lDis = Mat::zeros(hei, wid, CV_32FC1);
	SGMStereo sgm;
	sgm.compute(lImg, rImg, lDis);
	imwrite("view_test.png", lDis);
	system("pause");
	return 0;

}
