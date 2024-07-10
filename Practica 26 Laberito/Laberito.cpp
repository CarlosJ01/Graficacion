//C++
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

//OpenCv
#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

# define PI           3.14159265358979323846

using namespace cv;
using namespace std;

void pintarRectangulo(Mat,Point,Point,int,float);
Point pintarLinea(Mat,Point,int,float);

void pintarRectangulo(Mat,Point,Point,int,float,Scalar);
Point pintarLinea(Mat,Point,int,float,Scalar);

int main(){
	Mat img = Mat(600,1000,CV_8UC3,CV_RGB(0,0,0));
	
	//Contorno
	pintarRectangulo(img, Point(490,500), Point(490,530), 500, 25, CV_RGB(160, 96, 11));
	pintarRectangulo(img, Point(490,500), Point(490,530), 500, 155, CV_RGB(160, 96, 11));
	pintarLinea(img, Point(36,288), 500, 25);
	pintarLinea(img, Point(943,288), 500, 155);
	pintarLinea(img, Point(36,288), 45, 25, CV_RGB(160, 96, 11));
	pintarLinea(img, Point(943,288), 45, 155, CV_RGB(160, 96, 11));
	
	//Techo
	pintarRectangulo(img, Point(490,480), Point(490,460), 453, 25);
	pintarRectangulo(img, Point(490,480), Point(490,460), 170, 155);
	pintarRectangulo(img, Point(267,356), Point(267,376), 207, 155);
	pintarRectangulo(img, Point(267,356), Point(267,376), 40, 25);
	Point pnt = Point(303,339);
	pnt = pintarLinea(img, pnt, 50, 155);
	pnt = pintarLinea(img, pnt, 30, 25);
	pnt = pintarLinea(img, pnt, 30, 155);
	pnt = pintarLinea(img, pnt, 30, 205);
	pnt = pintarLinea(img, pnt, 85, 155);
	pnt = pintarLinea(img, pnt, 150, 25);
	pnt = pintarLinea(img, pnt, 50, 335);
	pnt = pintarLinea(img, pnt, 70, 205);
	pnt = pintarLinea(img, pnt, 100, 335);
	pnt = pintarLinea(img, pnt, 30, 205);
	pnt = pintarLinea(img, pnt, 190, 335);
	pnt = pintarLinea(img, pnt, 260, 25);
	pnt = pintarLinea(img, pnt, 100, 155);
	pnt = pintarLinea(img, pnt, 30, 205);
	pnt = pintarLinea(img, pnt, 50, 155);
	pnt = pintarLinea(img, pnt, 30, 25);
	pnt = pintarLinea(img, pnt, 30, 155);
	pnt = pintarLinea(img, pnt, 30, 205);
	pnt = pintarLinea(img, pnt, 100, 155);
	pnt = pintarLinea(img, pnt, 70, 205);
	pnt = pintarLinea(img, pnt, 50, 335);
	pnt = pintarLinea(img, pnt, 30, 25);
	pnt = pintarLinea(img, pnt, 30, 335);
	pnt = pintarLinea(img, pnt, 110, 205);
	pnt = pintarLinea(img, pnt, 70, 335);
	pnt = pintarLinea(img, pnt, 30, 205);
	pnt = pintarLinea(img, pnt, 30, 335);
	pnt = pintarLinea(img, pnt, 30, 25);
	pnt = pintarLinea(img, pnt, 50, 335);
	pnt = pintarLinea(img, pnt, 100, 25);
	pnt = pintarLinea(img, pnt, 50, 155);
	pnt = pintarLinea(img, pnt, 30, 205);
	pnt = pintarLinea(img, pnt, 30, 335);
	pnt = pintarLinea(img, pnt, 40, 205);
	pnt = pintarLinea(img, pnt, 70, 155);
	pnt = pintarLinea(img, pnt, 40, 25);
	pnt = pintarLinea(img, pnt, 20, 335);
	pnt = pintarLinea(img, pnt, 30, 25);
	pnt = pintarLinea(img, pnt, 30, 155);
	pnt = pintarLinea(img, pnt, 20, 25);
	pnt = pintarLinea(img, pnt, 100, 335);
	pnt = pintarLinea(img, pnt, 30, 25);
	pnt = pintarLinea(img, pnt, 50, 335);
	pnt = pintarLinea(img, pnt, 220, 205);
	pnt = pintarLinea(img, pnt, 130, 155);
	pnt = pintarLinea(img, pnt, 30, 25);
	pnt = pintarLinea(img, pnt, 100, 155);
	pnt = pintarLinea(img, pnt, 85, 25);
	pnt = pintarLinea(img, pnt, 20, 155);
	pnt = pintarLinea(img, pnt, 25, 205);
	pnt = pintarLinea(img, pnt, 50, 155);
	pnt = pintarLinea(img, pnt, 210, 25);
	pnt = pintarLinea(img, pnt, 50, 335);
	pnt = pintarLinea(img, pnt, 30, 205);
	pnt = pintarLinea(img, pnt, 30, 335);
	pnt = pintarLinea(img, pnt, 30, 25);
	pnt = pintarLinea(img, pnt, 300, 335);
	pnt = pintarLinea(img, pnt, 380, 205);
	pnt = pintarLinea(img, pnt, 130, 155);
	pintarLinea(img, pnt, 37, 205);
	
	//Paredes
	pnt = Point(284,304);
	pnt = pintarLinea(img, pnt, 20, 270);
	pintarLinea(img, pnt, 5, 205);
	pnt = Point(285,203);
	pnt = pintarLinea(img, pnt, 20, 270);
	pintarLinea(img, pnt, 25, 335);
	pintarLinea(img, pnt, 125, 205);
	pnt = Point(266,253);
	pnt = pintarLinea(img, pnt, 20, 270);
	pintarLinea(img, pnt, 75, 335);
	pintarRectangulo(img, Point(500,387), Point(500,407), 190, 155);
	pintarRectangulo(img, Point(500,387), Point(500,407), 260, 25);
	pnt = Point(597,211);
	pnt = pintarLinea(img, pnt, 20, 270);
	pintarLinea(img, pnt, 5, 205);
	pintarRectangulo(img, Point(431,217), Point(431,237), 50, 155);
	pintarRectangulo(img, Point(431,217), Point(431,237), 30, 25);
	pnt = Point(458,204);
	pnt = pintarLinea(img, pnt, 20, 270);
	pintarLinea(img, pnt, 5, 335);
	pnt = Point(385,262);
	pnt = pintarLinea(img, pnt, 20, 270);
	pintarLinea(img, pnt, 45, 335);
	pintarRectangulo(img, Point(447,315), Point(447,335), 30, 155);
	pintarRectangulo(img, Point(447,315), Point(447,335), 30, 25);
	pintarRectangulo(img, Point(519,323), Point(519,343), 50, 155);
	pintarRectangulo(img, Point(519,323), Point(519,343), 100, 25);
	pnt = Point(535,270);
	pnt = pintarLinea(img, pnt, 20, 270);
	pintarLinea(img, pnt, 5, 335);
	pnt = Point(497,251);
	pnt = pintarLinea(img, pnt, 20, 270);
	pintarLinea(img, pnt, 15, 205);
	pintarRectangulo(img, Point(515,259), Point(515,279), 20, 155);
	pintarRectangulo(img, Point(515,259), Point(515,279), 30, 25);
	pnt = Point(532,224);
	pnt = pintarLinea(img, pnt, 18, 270);
	pintarRectangulo(img, Point(622,266), Point(622,286), 30, 25);
	pintarRectangulo(img, Point(622,266), Point(622,286), 100, 155);
	pnt = Point(649,253);
	pnt = pintarLinea(img, pnt, 20, 270);
	pintarLinea(img, pnt, 25, 335);
	pnt = Point(403,298);
	pnt = pintarLinea(img, pnt, 20, 270);
	pintarLinea(img, pnt, 5, 205);
	pnt = Point(389,219);
	pnt = pintarLinea(img, pnt, 20, 270);
	pintarLinea(img, pnt, 60, 205);
	pnt = Point(491,109);
	pnt = pintarLinea(img, pnt, 20, 270);
	pintarLinea(img, pnt, 25, 335);
	pintarLinea(img, pnt, 186, 205);
	pintarRectangulo(img, Point(535,154), Point(535,174), 30, 25);
	pintarRectangulo(img, Point(535,154), Point(535,174), 30, 155);	
	pnt = Point(562,141);
	pnt = pintarLinea(img, pnt, 20, 270);
	pintarLinea(img, pnt, 275, 335);
	
	namedWindow("Laberito Isometrico",WINDOW_AUTOSIZE);
	imshow("Laberito Isometrico",img);
	waitKey(0);
	return 0;
}

void pintarRectangulo(Mat img,Point pnt1,Point pnt2,int tam,float grd){
	grd = (grd*PI)/180;
	Point nvo1 = Point(pnt1.x + tam*cos(grd), pnt1.y - tam*sin(grd));
	Point nvo2 = Point(pnt2.x + tam*cos(grd), pnt2.y - tam*sin(grd));
	
	line(img,pnt1, pnt2, CV_RGB(0,255,0), 2, 8, 0);
	line(img, nvo1, nvo2, CV_RGB(0,255,0), 2, 8, 0);
	line(img, nvo1, pnt1, CV_RGB(0,255,0), 2, 8, 0);
	line(img, nvo2, pnt2, CV_RGB(0,255,0), 2, 8, 0);
}

Point pintarLinea(Mat img, Point pnt, int tam, float grd){
	grd = (grd*PI)/180;
	Point nvo = Point(pnt.x + tam*cos(grd), pnt.y - tam*sin(grd));
	
	line(img,pnt, nvo, CV_RGB(0,255,0), 2, 8, 0);

	return nvo;
}

void pintarRectangulo(Mat img,Point pnt1,Point pnt2,int tam,float grd, Scalar clr){
	grd = (grd*PI)/180;
	Point nvo1 = Point(pnt1.x + tam*cos(grd), pnt1.y - tam*sin(grd));
	Point nvo2 = Point(pnt2.x + tam*cos(grd), pnt2.y - tam*sin(grd));
	
	line(img,pnt1, pnt2, clr, 3, 8, 0);
	line(img, nvo1, nvo2, clr, 3, 8, 0);
	line(img, nvo1, pnt1, clr, 3, 8, 0);
	line(img, nvo2, pnt2, clr, 3, 8, 0);
}

Point pintarLinea(Mat img, Point pnt, int tam, float grd, Scalar clr){
	grd = (grd*PI)/180;
	Point nvo = Point(pnt.x + tam*cos(grd), pnt.y - tam*sin(grd));
	
	line(img,pnt, nvo, clr, 3, 8, 0);

	return nvo;
}
