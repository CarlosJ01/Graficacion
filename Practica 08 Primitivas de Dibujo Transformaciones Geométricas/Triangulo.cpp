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

void dibujarTriangulo(Mat,Point,Point,Point);
void triangulo(Mat,Point,Point,Point,int);
Point puntoMedio(Point,Point);

int main(){
	Mat img = Mat(600,700,CV_8UC3,CV_RGB(197,172,15));

	//Puntos de las 3 esquinas
	Point izq = Point(10,img.rows-10);
	Point cnt = Point(img.cols/2,10);
	Point der = Point(img.cols-10,img.rows-10);

	//Hacer el triangulo
	triangulo(img,izq,cnt,der,6);

	namedWindow("Triangulo",WINDOW_AUTOSIZE);
	imshow("Triangulo",img);
	waitKey(0);

	return 0;
}

//Une los tres puntos con lineas (Dibuja el Triangulo)
void dibujarTriangulo(Mat img,Point izq,Point cnt,Point der){
	line(img,cnt,der,CV_RGB(0,0,0),1,8,0);
	line(img,der,izq,CV_RGB(0,0,0),1,8,0);
	line(img,izq,cnt,CV_RGB(0,0,0),1,8,0);
}

//Dibuja el triangulo
void triangulo(Mat img,Point izq,Point cnt,Point der,int nvl){
	//Si el nivel es diferente es diferente de 0  
	if(nvl != 0){
		//Calcula los puntos medios
		Point medCntDer = puntoMedio(cnt,der);
		Point medDerIzq = puntoMedio(der,izq);
		Point medIzqCnt = puntoMedio(izq,cnt);

		//Recursividad
		triangulo(img,medIzqCnt,cnt,medCntDer,nvl-1);
		triangulo(img,medDerIzq,medCntDer,der,nvl-1);
		triangulo(img,izq,medIzqCnt,medDerIzq,nvl-1);
	}
	//Si el nivel es 0 dibuja un triangulo entre los 3 puntos
	else{
		dibujarTriangulo(img,izq,cnt,der);
	}
}

//Calcula el puto medio entre 2 puntos
Point puntoMedio(Point pnt1,Point pnt2){
	return Point((pnt1.x + pnt2.x)/2,(pnt1.y + pnt2.y)/2);
}
