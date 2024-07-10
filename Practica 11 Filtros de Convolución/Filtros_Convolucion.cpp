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

//Matriz Impulso
int mtzConv[3][3]={{1	,1	,1},
				   {1	,1	,1},
				   {1	,1	,1}};

//Escalamiento
Mat escalar(Mat,int);			
	   
//Convolucion
void convolucion(Mat,Mat,int*,int*);

//Centro
void centro(Mat,Mat,int*,int*);

//Bordes
void bordeIzquierdo(Mat,Mat,int*,int*);
void bordeDerecho(Mat,Mat,int*,int*);
void bordeSuperior(Mat,Mat,int*,int*);
void bordeInferior(Mat,Mat,int*,int*);

//Esquinas
void esquinaSupIzq(Mat,Mat,int*,int*);
void esquinaSupDer(Mat,Mat,int*,int*);
void esquinaInfIzq(Mat,Mat,int*,int*);
void esquinaInfDer(Mat,Mat,int*,int*);

int main(){
	Mat img = imread("imagen.jpg",0);
	Mat esc = escalar(img,2);
	Mat conv1 = escalar(img,2);
	
	//Primer Filtro
	for (int y = 0; y < esc.rows; y++){
		for (int x = 0; x < esc.cols; x++){
			convolucion(esc,conv1,&x,&y);
		}
	}

	namedWindow("Original",WINDOW_AUTOSIZE);
	imshow("Original",img);
	
	namedWindow("Escalada",WINDOW_AUTOSIZE);
	imshow("Escalada",esc);
	
	namedWindow("Filtro Convolucion",WINDOW_AUTOSIZE);
	imshow("Filtro Convolucion",conv1);
	waitKey(0);
	
	return 0;
}

//Escalamiento
Mat escalar(Mat img,int esc){
	Mat conv = Mat((img.rows)*2,(img.cols)*2,CV_8UC1,CV_RGB(0,0,0));
	
	for (int i = 0; i < img.rows; i++){
		for (int j = 0; j < img.cols; j++){
			conv.at<uchar>(i*esc,j*esc)=img.at<uchar>(i,j);
		}
	}
	
	return conv;
}

//Condiciones para el borde 0
void convolucion(Mat img,Mat conv,int* x,int* y){
	if(*x==0)
		if(*y==0)
			//Esquina Superior Izquierda
			esquinaSupIzq(img,conv,x,y);
		else
			if(*y==img.rows-1)
				//Esquina Inferior Izquierda
				esquinaInfIzq(img,conv,x,y);
			else
				//Borde Izquierdo
				bordeIzquierdo(img,conv,x,y);
	else
		if(*x==img.cols-1)
			if(*y==0)
				//Esquina Superior Derecha
				esquinaSupDer(img,conv,x,y);
			else
				if(*y==img.rows-1)
					//Esquina Inferior Derecha
					esquinaInfDer(img,conv,x,y);
				else
					//Borde Derecha
					bordeDerecho(img,conv,x,y);
		else
			if(*y==0)
				//Borde Superior
				bordeSuperior(img,conv,x,y);
			else
				if(*y==img.rows-1)
					//Borde Inferior
					bordeInferior(img,conv,x,y);
				else
					//Centro
					centro(img,conv,x,y);
}

//Centro
void centro(Mat img,Mat conv,int* x,int* y){
	int sum = 0;
	
	sum+=mtzConv[0][0]*img.at<uchar>(*y-1,*x-1);
	sum+=mtzConv[0][1]*img.at<uchar>(*y-1,*x);
	sum+=mtzConv[0][2]*img.at<uchar>(*y-1,*x+1);

	sum+=mtzConv[1][0]*img.at<uchar>(*y,*x-1);
	sum+=mtzConv[1][1]*img.at<uchar>(*y,*x);
	sum+=mtzConv[1][2]*img.at<uchar>(*y,*x+1);

	sum+=mtzConv[2][0]*img.at<uchar>(*y+1,*x-1);
	sum+=mtzConv[2][1]*img.at<uchar>(*y+1,*x);
	sum+=mtzConv[2][2]*img.at<uchar>(*y+1,*x+1);

	if(sum>255)
		conv.at<uchar>(*y,*x)=255;
	else
		if(sum<0)
			conv.at<uchar>(*y,*x)=0;
		else
			conv.at<uchar>(*y,*x)=sum;	
}

//Bordes
void bordeIzquierdo(Mat img,Mat conv,int* x,int* y){
	int sum = 0;
	
	sum+=mtzConv[0][1]*img.at<uchar>(*y-1,*x);
	sum+=mtzConv[0][2]*img.at<uchar>(*y-1,*x+1);

	sum+=mtzConv[1][1]*img.at<uchar>(*y,*x);
	sum+=mtzConv[1][2]*img.at<uchar>(*y,*x+1);

	sum+=mtzConv[2][1]*img.at<uchar>(*y+1,*x);
	sum+=mtzConv[2][2]*img.at<uchar>(*y+1,*x+1);

	if(sum>255)
		conv.at<uchar>(*y,*x)=255;
	else
		if(sum<0)
			conv.at<uchar>(*y,*x)=0;
		else
			conv.at<uchar>(*y,*x)=sum;
}

void bordeDerecho(Mat img,Mat conv,int* x,int* y){
	int sum = 0;
	
	sum+=mtzConv[0][0]*img.at<uchar>(*y-1,*x-1);
	sum+=mtzConv[0][1]*img.at<uchar>(*y-1,*x);

	sum+=mtzConv[1][0]*img.at<uchar>(*y,*x-1);
	sum+=mtzConv[1][1]*img.at<uchar>(*y,*x);

	sum+=mtzConv[2][0]*img.at<uchar>(*y+1,*x-1);
	sum+=mtzConv[2][1]*img.at<uchar>(*y+1,*x);

	if(sum>255)
		conv.at<uchar>(*y,*x)=255;
	else
		if(sum<0)
			conv.at<uchar>(*y,*x)=0;
		else
			conv.at<uchar>(*y,*x)=sum;	
}

void bordeSuperior(Mat img,Mat conv,int* x,int* y){
	int sum = 0;
	
	sum+=mtzConv[1][0]*img.at<uchar>(*y,*x-1);
	sum+=mtzConv[1][1]*img.at<uchar>(*y,*x);
	sum+=mtzConv[1][2]*img.at<uchar>(*y,*x+1);

	sum+=mtzConv[2][0]*img.at<uchar>(*y+1,*x-1);
	sum+=mtzConv[2][1]*img.at<uchar>(*y+1,*x);
	sum+=mtzConv[2][2]*img.at<uchar>(*y+1,*x+1);

	if(sum>255)
		conv.at<uchar>(*y,*x)=255;
	else
		if(sum<0)
			conv.at<uchar>(*y,*x)=0;
		else
			conv.at<uchar>(*y,*x)=sum;	
}

void bordeInferior(Mat img,Mat conv,int* x,int* y){
	int sum = 0;
	
	sum+=mtzConv[0][0]*img.at<uchar>(*y-1,*x-1);
	sum+=mtzConv[0][1]*img.at<uchar>(*y-1,*x);
	sum+=mtzConv[0][2]*img.at<uchar>(*y-1,*x+1);

	sum+=mtzConv[1][0]*img.at<uchar>(*y,*x-1);
	sum+=mtzConv[1][1]*img.at<uchar>(*y,*x);
	sum+=mtzConv[1][2]*img.at<uchar>(*y,*x+1);

	if(sum>255)
		conv.at<uchar>(*y,*x)=255;
	else
		if(sum<0)
			conv.at<uchar>(*y,*x)=0;
		else
			conv.at<uchar>(*y,*x)=sum;	
}

//Esquinas
void esquinaSupIzq(Mat img,Mat conv,int* x,int* y){
	int sum = 0;

	sum+=mtzConv[1][1]*img.at<uchar>(*y,*x);
	sum+=mtzConv[1][2]*img.at<uchar>(*y,*x+1);

	sum+=mtzConv[2][1]*img.at<uchar>(*y+1,*x);
	sum+=mtzConv[2][2]*img.at<uchar>(*y+1,*x+1);

	if(sum>255)
		conv.at<uchar>(*y,*x)=255;
	else
		if(sum<0)
			conv.at<uchar>(*y,*x)=0;
		else
			conv.at<uchar>(*y,*x)=sum;	
}

void esquinaSupDer(Mat img,Mat conv,int* x,int* y){
	int sum = 0;
	
	sum+=mtzConv[1][0]*img.at<uchar>(*y,*x-1);
	sum+=mtzConv[1][1]*img.at<uchar>(*y,*x);
	
	sum+=mtzConv[2][0]*img.at<uchar>(*y+1,*x-1);
	sum+=mtzConv[2][1]*img.at<uchar>(*y+1,*x);
	
	if(sum>255)
		conv.at<uchar>(*y,*x)=255;
	else
		if(sum<0)
			conv.at<uchar>(*y,*x)=0;
		else
			conv.at<uchar>(*y,*x)=sum;	
}

void esquinaInfIzq(Mat img,Mat conv,int* x,int* y){
	int sum = 0;
	
	sum+=mtzConv[0][1]*img.at<uchar>(*y-1,*x);
	sum+=mtzConv[0][2]*img.at<uchar>(*y-1,*x+1);

	sum+=mtzConv[1][1]*img.at<uchar>(*y,*x);
	sum+=mtzConv[1][2]*img.at<uchar>(*y,*x+1);

	if(sum>255)
		conv.at<uchar>(*y,*x)=255;
	else
		if(sum<0)
			conv.at<uchar>(*y,*x)=0;
		else
			conv.at<uchar>(*y,*x)=sum;	
}

void esquinaInfDer(Mat img,Mat conv,int* x,int* y){
	int sum = 0;
	
	sum+=mtzConv[0][0]*img.at<uchar>(*y-1,*x-1);
	sum+=mtzConv[0][1]*img.at<uchar>(*y-1,*x);

	sum+=mtzConv[1][0]*img.at<uchar>(*y,*x-1);
	sum+=mtzConv[1][1]*img.at<uchar>(*y,*x);

	if(sum>255)
		conv.at<uchar>(*y,*x)=255;
	else
		if(sum<0)
			conv.at<uchar>(*y,*x)=0;
		else
			conv.at<uchar>(*y,*x)=sum;	
}
