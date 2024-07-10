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

using namespace cv;

int mtz[8][8];

void llenar();
void pasarMatriz(Mat);
void color(Mat,int,int,int,int,int);

int main(){
	Mat img = Mat(400,400,CV_8UC1,Scalar(128));
	
	llenar();
	pasarMatriz(img);

	namedWindow("Tablero",WINDOW_AUTOSIZE);
	imshow("Tablero",img);
	waitKey(0);

	return 0;
}

void llenar(){
	int sum;

	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			sum=i+j;
			if (sum%2 != 0)
				mtz[i][j]=0;
			else
				mtz[i][j]=1;	
		}
	}
	
	srand(time(NULL));
	mtz[rand()%8][rand()%8] = 2;
}

void pasarMatriz(Mat img){
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if(mtz[i][j] == 0)
				color(img,i*50,j*50,(i+1)*50,(j+1)*50,255);
			else
			if(mtz[i][j] == 1)
				color(img,i*50,j*50,(i+1)*50,(j+1)*50,0);
			else
				color(img,i*50,j*50,(i+1)*50,(j+1)*50,128);
		}
	}
}

void color(Mat img,int filIni,int colIni,int filFin,int colFin,int clr){
	for(int i=filIni;i<filFin;i++)
		for(int j=colIni;j<colFin;j++)
			img.at<uchar>(i,j)=clr;
}
