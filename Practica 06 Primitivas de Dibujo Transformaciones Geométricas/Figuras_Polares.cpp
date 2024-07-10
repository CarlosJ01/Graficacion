//C++
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//OpenCv
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

# define PI           3.14159265358979323846

void figura01(Mat,int);
void figura02(Mat,int);
void figura03(Mat,int);
void figura04(Mat,int);
void figura05(Mat,int);
void figura06(Mat,int);
void figura07(Mat,int);
void figura08(Mat,int);
void figura09(Mat,int);
void figura10(Mat,int);

int main(){
	Mat fgr = Mat(500,500,CV_8UC3,CV_RGB(236,16,200));

	//Figura 01
	figura01(fgr,100);
	
	//Figura 02
	fgr = Mat(500,500,CV_8UC3,CV_RGB(236,213,16));
	figura02(fgr,100);

	//Figura 03
	fgr = Mat(500,500,CV_8UC3,CV_RGB(165,91,21));
	figura03(fgr,100);

	//Figura 04
	fgr = Mat(500,500,CV_8UC3,CV_RGB(20,229,42));
	figura04(fgr,200);

	//Figura 05
	fgr = Mat(500,500,CV_8UC3,CV_RGB(16,236,193));
	figura05(fgr,75);

	//Figura 06
	fgr = Mat(500,500,CV_8UC3,CV_RGB(16,89,236));
	figura06(fgr,50);

	//Figura 07
	fgr = Mat(500,500,CV_8UC3,CV_RGB(153,16,236));
	figura07(fgr,150);

	//Figura 08
	fgr = Mat(500,650,CV_8UC3,CV_RGB(236,113,16));
	figura08(fgr,75);

	//Figura 09
	fgr = Mat(500,500,CV_8UC3,CV_RGB(122,119,119));
	figura09(fgr,200);

	//Figura 10
	fgr = Mat(500,500,CV_8UC3,CV_RGB(175,9,29));
	figura10(fgr,200);
	
	imshow("Figuras",fgr);
	waitKey(0);
	return 0;
}

void figura01(Mat fgr,int a){
	float grd,x,y;
	for (grd = 0;grd<(2*PI);grd+=0.01){
		x = fgr.cols/2 + a*(1+sin(grd))*cos(grd);
		y = fgr.rows/2 + a*(1+sin(grd))*sin(grd);
		circle(fgr,Point(x,y),1,CV_RGB(255,255,255),-1,3);
		
		namedWindow("Figuras",WINDOW_AUTOSIZE);
		imshow("Figuras",fgr);
		if(waitKey(10)==0)
			break;
	}
}

void figura02(Mat fgr,int a){
	float grd,x,y;
	for (grd = 0;grd<(2*PI);grd+=0.01){
		x = fgr.cols/2 + a*(1-cos(grd))*cos(grd);
		y = fgr.rows/2 + a*(1-cos(grd))*sin(grd);
		circle(fgr,Point(x,y),1,CV_RGB(255,255,255),-1,3);
		
		namedWindow("Figuras",WINDOW_AUTOSIZE);
		imshow("Figuras",fgr);
		if(waitKey(10)==0)
			break;
	}
}

void figura03(Mat fgr,int a){
	float grd,x,y;
	for (grd = 0;grd<PI;grd+=0.01){
		x = fgr.cols/2 + a*(2*sin(3*grd))*cos(grd);
		y = fgr.rows/2 + a*(2*sin(3*grd))*sin(grd);
		circle(fgr,Point(x,y),1,CV_RGB(255,255,255),-1,3);
		
		namedWindow("Figuras",WINDOW_AUTOSIZE);
		imshow("Figuras",fgr);
		if(waitKey(10)==0)
			break;
	}
}

void figura04(Mat fgr,int a){
	float grd,x,y;
	for (grd = 0;grd<(2*PI);grd+=0.01){
		x = fgr.cols/2 + a*sin(2*grd)*cos(grd);
		y = fgr.rows/2 + a*sin(2*grd)*sin(grd);
		circle(fgr,Point(x,y),1,CV_RGB(255,255,255),-1,3);
		
		namedWindow("Figuras",WINDOW_AUTOSIZE);
		imshow("Figuras",fgr);
		if(waitKey(10)==0)
			break;
	}
}

void figura05(Mat fgr,int a){
	float grd,x,y;
	for (grd = 0;grd<(2*PI);grd+=0.01){
		x = fgr.cols/2 + a*(1-(2*sin(3*grd)))*cos(grd);
		y = fgr.rows/2 + a*(1-(2*sin(3*grd)))*sin(grd);
		circle(fgr,Point(x,y),1,CV_RGB(255,255,255),-1,3);
		
		namedWindow("Figuras",WINDOW_AUTOSIZE);
		imshow("Figuras",fgr);
		if(waitKey(10)==0)
			break;
	}
}

void figura06(Mat fgr,int a){
	float grd,x,y;
	for (grd = 0;grd<(2*PI);grd+=0.01){
		x = fgr.cols/2 + a*(2-(3*sin(2*grd)))*cos(grd);
		y = fgr.rows/2 + a*(2-(3*sin(2*grd)))*sin(grd);
		circle(fgr,Point(x,y),1,CV_RGB(255,255,255),-1,3);
		
		namedWindow("Figuras",WINDOW_AUTOSIZE);
		imshow("Figuras",fgr);
		if(waitKey(10)==0)
			break;
	}
}

void figura07(Mat fgr,int a){
	float grd,x,y;
	for (grd = 0;grd<(2*PI);grd+=0.01){
		x = fgr.cols/2 + a*(0.5+cos(grd))*cos(grd);
		y = fgr.rows/2 + a*(0.5+cos(grd))*sin(grd);
		circle(fgr,Point(x,y),1,CV_RGB(255,255,255),-1,3);
		
		namedWindow("Figuras",WINDOW_AUTOSIZE);
		imshow("Figuras",fgr);
		if(waitKey(10)==0)
			break;
	}
}

void figura08(Mat fgr,int a){
	float grd,x,y;
	for (grd = 0;grd<(2*PI);grd+=0.01){
		x = fgr.cols/2 + a*(sqrt(16*cos(2*grd)))*cos(grd);
		y = fgr.rows/2 + a*(sqrt(16*cos(2*grd)))*sin(grd);
		circle(fgr,Point(x,y),1,CV_RGB(255,255,255),-1,3);
		
		namedWindow("Figuras",WINDOW_AUTOSIZE);
		imshow("Figuras",fgr);
		if(waitKey(10)==0)
			break;
	}
}

void figura09(Mat fgr,int a){
	float grd,x,y;
	for (grd = 0;grd<(2*PI);grd+=0.01){
		x = fgr.cols/2 + a*(sin(10*grd))*cos(grd);
		y = fgr.rows/2 + a*(sin(10*grd))*sin(grd);
		circle(fgr,Point(x,y),1,CV_RGB(255,255,255),-1,3);
		
		namedWindow("Figuras",WINDOW_AUTOSIZE);
		imshow("Figuras",fgr);
		if(waitKey(10)==0)
			break;
	}
}

void figura10(Mat fgr,int a){
	float grd,x,y;
	for (grd = 0;grd<(4*PI);grd+=0.01){
		x = fgr.cols/2 + a*(cos((7*grd)/2))*cos(grd)+1;
		y = fgr.rows/2 + a*(cos((7*grd)/2))*sin(grd)+1;
		circle(fgr,Point(x,y),1,CV_RGB(255,255,255),-1,3);
		
		namedWindow("Figuras",WINDOW_AUTOSIZE);
		imshow("Figuras",fgr);
		if(waitKey(10)==0)
			break;
	}
}

