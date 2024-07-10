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
using namespace std;

//Convolucion Separable
int fila[3]={1,1,1};
int columna[3] = {1,1,1};

//Escalamiento
Mat escalar(Mat,int);			
//Poner Borde 0
Mat ponerBordeCero(Mat);
Mat quitarBordeCero(Mat);

//Convolucion Separable
void separableColumna(Mat,Mat,int,int);
void separableFila(Mat,Mat,int,int);

int main(){
	Mat img = imread("imagen.jpg",0);
	Mat flt;
	imshow("Original",img);
	
	//Escalamiento y Poner Borde 0
	img = escalar(img,2);
	img = ponerBordeCero(img);
	imshow("Escalamiento en 2 y Borde 0",img);
	
	//Convolucion Separable
	img.copyTo(flt);
	for (int y = 1; y < img.rows-1; y++)
		for (int x = 1; x < img.cols-1; x++)
			separableColumna(img,flt,x,y);
			
	flt.copyTo(img);
	for (int y = 1; y < img.rows-1; y++)
		for (int x = 1; x < img.cols-1; x++)
			separableFila(img,flt,x,y);
			
	//Quitar Borde 0
	flt = quitarBordeCero(flt);
	imshow("Convolucion Separable",flt);
	
	waitKey(0);
	return 0;
}

//Escalamiento
Mat escalar(Mat img,int esc){
	Mat nvoImg = Mat((img.rows)*2,(img.cols)*2,CV_8UC1,CV_RGB(0,0,0));
	
	for (int i = 0; i < img.rows; i++)
		for (int j = 0; j < img.cols; j++)
			nvoImg.at<uchar>(i*esc,j*esc)=img.at<uchar>(i,j);
			
	return nvoImg;
}

//Quitar y poner Borde 0
Mat ponerBordeCero(Mat img){
	Mat nvoImg = Mat(img.rows+2,img.cols+2,CV_8UC1,Scalar(0));
	
	for (int y = 0; y < img.rows; y++)
		for (int x = 0; x < img.cols; x++)
			nvoImg.at<uchar>(y+1,x+1)=img.at<uchar>(y,x);
			
	return nvoImg;
}

Mat quitarBordeCero(Mat img){
	Mat nvoImg = Mat(img.rows-2,img.cols-2,CV_8UC1,Scalar(0));
	
	for (int y = 1; y < img.rows-1; y++)
		for (int x = 1; x < img.cols-1; x++)
			nvoImg.at<uchar>(y-1,x-1)=img.at<uchar>(y,x);
			
	return nvoImg;
}

//Filtro convolucion separable Filas y Columnas
void separableColumna(Mat img, Mat flt, int x,int y){
	int sum = 0;
	sum += columna[0]*img.at<uchar>(y-1,x);
	sum += columna[1]*img.at<uchar>(y,x);
	sum += columna[2]*img.at<uchar>(y+1,x);
	
	if(sum >= 255)
		flt.at<uchar>(y,x)=255;
	else
		if(sum <= 0)
			flt.at<uchar>(y,x)=0;
		else
			flt.at<uchar>(y,x)=sum;	
}

void separableFila(Mat img, Mat flt, int x,int y){
	int sum = 0;
	sum += fila[0]*img.at<uchar>(y,x-1);
	sum += fila[1]*img.at<uchar>(y,x);
	sum += fila[2]*img.at<uchar>(y,x+1);
	
	if(sum >= 255)
		flt.at<uchar>(y,x)=255;
	else
		if(sum <= 0)
			flt.at<uchar>(y,x)=0;
		else
			flt.at<uchar>(y,x)=sum;	
}
