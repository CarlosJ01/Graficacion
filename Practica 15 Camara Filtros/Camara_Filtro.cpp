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

void operadoresPuntuales(Mat);
void filtrosOpenCv(Mat);


int main(){
	
	VideoCapture cap(0);
	if (!cap.isOpened())
		return -1;

	Mat frames;

	for (;;){
		cap >> frames;
		flip(frames, frames, 1);
		
		operadoresPuntuales(frames);
		filtrosOpenCv(frames);

		imshow("Camara",frames);
		
		if(waitKey(16) == 27)
			break;
	}
	
	return 0;
}

//Operadores Puntuales
void operadoresPuntuales(Mat img){
	Mat bin;//Imagen binaria
	Mat neg;//Imagem Negativo

	Vec3b pxl; //Vector por pixel
	Vec3b pxlNeg; //Vector Negativo
	Vec3b pxlBin; //Vector Negativo

	img.copyTo(neg);
	cvtColor(img,bin,CV_RGB2GRAY);

	for(int i=0;i<img.rows;i++){
		for(int j=0;j<img.cols;j++){
			pxl = img.at<Vec3b>(i,j);
			//--------------------------Binario------------------------
			if((bin.at<uchar>(i,j))<128)
				bin.at<uchar>(i,j)=0;
			else
				bin.at<uchar>(i,j)=255;

			//--------------------------Negativo------------------------
			pxlNeg[0]=255-pxl[0];	
			pxlNeg[1]=255-pxl[1];
			pxlNeg[2]=255-pxl[2];
			neg.at<Vec3b>(i,j)=pxlNeg;
		}
	}

	imshow("Camara 1",bin);
	imshow("Camara 2",neg);
}

void filtrosOpenCv(Mat img){
	Mat fil1,fil2,fil3;

	//Escala de Grises
	cvtColor(img,fil1,CV_RGB2GRAY);

	Mat kernel = (Mat_<char>(3, 3) <<  0,  1, 0,
                                  	   1, -4, 1,
                                   	   0,  1, 0);

	filter2D(fil1,fil2,fil1.depth(),kernel);

	kernel = (Mat_<char>(3, 3) <<  1,  0, -1,
                                   2,  0, -2,
                                   1,  0, -1);

	filter2D(img,fil3,img.depth(),kernel);

	imshow("Camara 3",fil1);
	imshow("Camara 4",fil2);
	imshow("Camara 5",fil3);
}
