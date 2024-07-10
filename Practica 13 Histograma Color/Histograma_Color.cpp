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

int** valores(Mat);
void dibujarHistogramas(int **);
void combinarHistogramas(Mat,Mat,Mat);
void histogramaRGB(int **,int*,int*,int*);

int main(){
	Mat img = imread("Imagen1.jpg",1);
	//Mat img = imread("Imagen2.jpg",1);
	//Mat img = imread("Imagen3.jpg",1);
	int** mtz = valores(img);
	
	namedWindow("Imagen",WINDOW_AUTOSIZE);
	imshow("Imagen",img);
	
	dibujarHistogramas(mtz);

	waitKey(0);
	return 0;
}

int** valores(Mat img){
	Vec3b pxl; //Vector por pixel
	
	//Matriz que aguarda los valores del RGB
	int **mtz = new int*[3];
	for(int i = 0; i < 3; i++)
  		mtz[i] = new int[256];

	for(int i = 0; i < 3; i++) 
  		for (int j = 0; j < 256; j++)
  			mtz[i][j]=0;

	//Contamos
	for (int i = 0; i < img.rows; i++){
		for (int j = 0; j < img.cols; j++){
			pxl = img.at<Vec3b>(i,j);
			mtz[0][pxl[2]]++;//R
			mtz[1][pxl[1]]++;//G
			mtz[2][pxl[0]]++;//B
		}
	}

	return mtz;
}

void dibujarHistogramas(int ** mtz){
	Mat R = Mat(512,512,CV_8UC3,CV_RGB(255,255,255));
	Mat G = Mat(512,512,CV_8UC3,CV_RGB(255,255,255));
	Mat B = Mat(512,512,CV_8UC3,CV_RGB(255,255,255));

	//Obtenemos el mayor numero
	int mayR=0,maxR=0;
	int mayG=0,maxG=0;
	int mayB=0,maxB=0;

	for (int i=0;i<256;i++){
		if(mtz[0][i]>= mayR){
			mayR=mtz[0][i];
			maxR=i;
		}	
		if(mtz[1][i]>= mayG){
			mayG=mtz[1][i];
			maxG=i;
		}
		if(mtz[2][i]>= mayB){
			mayB=mtz[2][i];
			maxB=i;
		}
	}

	//Optenemos la escala y pintamos
	int escR = mayR/512 + 1;
	int escG = mayG/512 + 1;
	int escB = mayB/512 + 1;

	int cont=0;
	for (int i = 0; i < 512; i++){
		line(R,Point(i,512-(mtz[0][cont])/escR),Point(i,512),CV_RGB(cont,0,0),1,8,0);
		line(G,Point(i,512-(mtz[1][cont])/escG),Point(i,512),CV_RGB(0,cont,0),1,8,0);
		line(B,Point(i,512-(mtz[2][cont])/escB),Point(i,512),CV_RGB(0,0,cont),1,8,0);
		if(i%2!=0)
			cont++;
	}
	
	imshow("Color",Mat(100,100,CV_8UC3,CV_RGB(maxR,maxG,maxB)));
	
	imshow("R",R);
	imshow("G",G);
	imshow("B",B);
	
	combinarHistogramas(R,G,B);
	histogramaRGB(mtz,&escR,&escG,&escB);
	
	printf("Color En Promedio Mas Repetido:\n");
	printf("R: %d -> %d\n",maxR,mayR);
	printf("G: %d -> %d\n",maxG,mayG);
	printf("B: %d -> %d\n",maxB,mayB);
}

void combinarHistogramas(Mat R,Mat G,Mat B){
	Mat RGB = Mat(512,512,CV_8UC3,CV_RGB(255,255,255));
	for (int i = 0; i < RGB.rows; i++){
		for (int j = 0; j < RGB.cols; j++){
			Vec3b pxl;
			pxl[2]=(R.at<Vec3b>(i,j))[2];//R
			pxl[1]=(G.at<Vec3b>(i,j))[1];//G
			pxl[0]=(B.at<Vec3b>(i,j))[0];//B
			RGB.at<Vec3b>(i,j)=pxl;
		}
	}

	imshow("RGB Combina Histogramas",RGB);
}

void histogramaRGB(int ** mtz,int* escR,int* escG,int* escB){
	Mat R = Mat(512,512,CV_8UC3,CV_RGB(0,0,0));
	Mat G = Mat(512,512,CV_8UC3,CV_RGB(0,0,0));
	Mat B = Mat(512,512,CV_8UC3,CV_RGB(0,0,0));

	int cont=0;
	for (int i = 0; i < 512; i++){
		line(R,Point(i,512-(mtz[0][cont])/ *escR),Point(i,512),CV_RGB(255,0,0),1,8,0);
		line(G,Point(i,512-(mtz[1][cont])/ *escG),Point(i,512),CV_RGB(0,255,0),1,8,0);
		line(B,Point(i,512-(mtz[2][cont])/ *escB),Point(i,512),CV_RGB(0,0,255),1,8,0);
		if(i%2!=0)
			cont++;
	}

	Mat RGB = Mat(512,512,CV_8UC3,CV_RGB(255,255,255));
	for (int i = 0; i < RGB.rows; i++){
		for (int j = 0; j < RGB.cols; j++){
			Vec3b pxl;
			pxl[2]=(R.at<Vec3b>(i,j))[2];//R
			pxl[1]=(G.at<Vec3b>(i,j))[1];//G
			pxl[0]=(B.at<Vec3b>(i,j))[0];//B
			RGB.at<Vec3b>(i,j)=pxl;
		}
	}
	
	imshow("RGB Combina Colores",RGB);
}
