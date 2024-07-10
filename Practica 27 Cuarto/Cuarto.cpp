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

void pintarRectangulo(Mat,Point,Point,int,float,Scalar);
Point pintarLinea(Mat,Point,int,float,Scalar);

int main(){
	Mat img = Mat(600,1000,CV_8UC3,CV_RGB(150,149,145));
	
	//Paredes y Piso
	pintarRectangulo(img, Point(530,540), Point(530,590), 400, 25, CV_RGB(166,140,7));
	pintarRectangulo(img, Point(530,540), Point(530,590), 400, 155, CV_RGB(166,140,7));	
	
	Point pnt = Point(167,370);
	pintarLinea(img, pnt, 10, 335, CV_RGB(240,202,10));
	pnt = pintarLinea(img, pnt, 200, 90, CV_RGB(240,202,10));
	pintarLinea(img, pnt, 10, 335, CV_RGB(240,202,10));
	pnt = pintarLinea(img, pnt, 400, 20, CV_RGB(240,202,10));
	pnt = pintarLinea(img, pnt, 373, 340, CV_RGB(240,202,10));
	pintarLinea(img, pnt, 10, 205, CV_RGB(240,202,10));
	pnt = pintarLinea(img, pnt, 210, 270, CV_RGB(240,202,10));
	pintarLinea(img, pnt, 10, 205, CV_RGB(240,202,10));
	pnt = Point(177,375);
	pnt = pintarLinea(img, pnt, 200, 90, CV_RGB(240,202,10));
	pnt = pintarLinea(img, pnt, 390, 20, CV_RGB(240,202,10));
	pintarLinea(img, pnt, 200, 270, CV_RGB(240,202,10));
	pnt = pintarLinea(img, pnt, 363, 340, CV_RGB(240,202,10));
	pintarLinea(img, pnt, 210, 270, CV_RGB(240,202,10));
	pnt = Point(177,375);
	pnt = pintarLinea(img, pnt, 390, 20, CV_RGB(240,202,10));
	pintarLinea(img, pnt, 363, 339, CV_RGB(240,202,10));
	
	//Alfombra
	pnt = Point(530,530);
	pnt = pintarLinea(img, pnt, 80, 25, CV_RGB(166,7,118));
	pnt = pintarLinea(img, pnt, 130, 155, CV_RGB(166,7,118));
	pnt = pintarLinea(img, pnt, 80, 205, CV_RGB(166,7,118));
	pintarLinea(img, pnt, 130, 335, CV_RGB(166,7,118));

	//Cofre
	pintarRectangulo(img, Point(700,img.rows/2), Point(700,img.rows/2+50), 70, 25, CV_RGB(75,63,17));
	pintarRectangulo(img, Point(700,img.rows/2), Point(700,img.rows/2+50), 150, 155, CV_RGB(75,63,17));
	pnt = Point(564,236);
	pnt = pintarLinea(img, pnt, 70, 25, CV_RGB(75,63,17));
	pintarLinea(img, pnt, 150, 335, CV_RGB(75,63,17));
	
	//Cama
	pintarRectangulo(img, Point(640,460), Point(640,440), 240, 25, CV_RGB(182,79,13));
	pintarRectangulo(img, Point(640,460), Point(640,440), 80, 155, CV_RGB(182,79,13));
	pintarRectangulo(img, Point(640,410), Point(640,440), 240, 25, CV_RGB(223,5,5));
	pintarRectangulo(img, Point(640,410), Point(640,440), 80, 155, CV_RGB(223,5,5));
	pnt = Point(567,376);
	pnt = pintarLinea(img, pnt, 240, 25, CV_RGB(223,5,5));
	pintarLinea(img, pnt, 80, 335, CV_RGB(223,5,5));
	pintarRectangulo(img, Point(702,312), Point(748,291), 80, 335, CV_RGB(223,255,255));
	pintarRectangulo(img, Point(820,324), Point(774,345), 30, 270, CV_RGB(223,255,255));
	pintarRectangulo(img, Point(757,295), Point(784,282), 60, 335, CV_RGB(255,255,255));
	
	//Mesa
	pnt = Point(250,img.rows/2);
	pintarLinea(img, pnt, 70, 270, CV_RGB(138,93,4));
	pnt = pintarLinea(img, pnt, 70, 335, CV_RGB(138,93,4));
	pintarLinea(img, pnt, 70, 270, CV_RGB(138,93,4));
	pnt = pintarLinea(img, pnt, 200, 25, CV_RGB(138,93,4));
	pintarLinea(img, pnt, 70, 270, CV_RGB(138,93,4));
	pnt = pintarLinea(img, pnt, 70, 155, CV_RGB(138,93,4));
	pintarLinea(img, pnt, 70, 270, CV_RGB(138,93,4));
	pnt = pintarLinea(img, pnt, 200, 205, CV_RGB(138,93,4));
	
	//Estante
	pnt = Point(200,230);
	pnt = pintarLinea(img, pnt, 50, 335, CV_RGB(98,70,14));
	pnt = pintarLinea(img, pnt, 150, 25, CV_RGB(98,70,14));
	pnt = pintarLinea(img, pnt, 20, 90, CV_RGB(98,70,14));
	pnt = pintarLinea(img, pnt, 150, 25, CV_RGB(98,70,14));
	pnt = pintarLinea(img, pnt, 50, 155, CV_RGB(98,70,14));
	pnt = pintarLinea(img, pnt, 150, 205, CV_RGB(98,70,14));
	pnt = pintarLinea(img, pnt, 20, 270, CV_RGB(98,70,14));
	pnt = pintarLinea(img, pnt, 150, 205, CV_RGB(98,70,14));
	
	//Ventana
	pintarRectangulo(img, Point(570,80), Point(851,182), 80, 270, CV_RGB(14,194,203));
	
	namedWindow("Cuarto Isometrico",WINDOW_AUTOSIZE);
	imshow("Cuarto Isometrico",img);
	waitKey(0);
	return 0;
}

void pintarRectangulo(Mat img,Point pnt1,Point pnt2,int tam,float grd, Scalar clr){
	grd = (grd*PI)/180;
	Point nvo1 = Point(pnt1.x + tam*cos(grd), pnt1.y - tam*sin(grd));
	Point nvo2 = Point(pnt2.x + tam*cos(grd), pnt2.y - tam*sin(grd));
	
	line(img,pnt1, pnt2, clr, 2, 8, 0);
	line(img, nvo1, nvo2, clr, 2, 8, 0);
	line(img, nvo1, pnt1, clr, 2, 8, 0);
	line(img, nvo2, pnt2, clr, 2, 8, 0);
}

Point pintarLinea(Mat img, Point pnt, int tam, float grd, Scalar clr){
	grd = (grd*PI)/180;
	Point nvo = Point(pnt.x + tam*cos(grd), pnt.y - tam*sin(grd));
	
	line(img,pnt, nvo, clr, 2, 8, 0);
	return nvo;
}
