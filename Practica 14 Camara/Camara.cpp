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


//Sprites Mario
void marioParado(Mat,int,int);
void marioCaminando(Mat,int,int);

//Animaciones
void caminarMario(Mat,int*,int*,int*);

int main(){
	
	VideoCapture cap(0);
	if (!cap.isOpened())
		return -1;
		
	Mat frames;
	Mat img = imread("Logo.png",1);
	
	int x=0;
	int y=455;
	int ani=1;
	
	for (;;){
		cap >> frames;
		flip(frames, frames, 1);
		img.copyTo(frames(Rect(200,10,img.cols,img.rows)));
		
		caminarMario(frames,&x,&y,&ani);
		
		if(x>=frames.cols)
			x=0;
		
		ani++;
		imshow("Camara",frames);
		if(waitKey(16) == 27)
			break;
	}
	
	return 0;
}

//Animacion Mario Caminando
void caminarMario(Mat img,int* x,int* y,int* ani){
	if(*ani%2==0)
		marioParado(img,*x,*y);
	else
		marioCaminando(img,*x,*y);
	*x+=5;
}


//Sprites mario
void marioCaminando(Mat img,int x,int y){
	//Camisa
	Point verCamisa[4]={Point(x-10,y-10), Point(x+10,y-10), Point(x+10,y+10), Point(x-10,y+10)};
	fillConvexPoly(img,verCamisa,4,CV_RGB(10,80,242),8,0);
	
	Point verPlayera[3]={Point(x-10,y-10), Point(x+10,y-10), Point(x+10,y)};
	fillConvexPoly(img,verPlayera,3,CV_RGB(242,10,10),8,0);
	
	//Pantalon
	Point verPantIzq[4]={Point(x-10,y+10), Point(x,y+10), Point(x-4,y+20), Point(x-14,y+20)};
	fillConvexPoly(img,verPantIzq,4,CV_RGB(10,80,242),8,0);
	
	Point verPantDer[4]={Point(x,y+10), Point(x+10,y+10), Point(x+14,y+20), Point(x+4,y+20)};
	fillConvexPoly(img,verPantDer,4,CV_RGB(10,80,242),8,0);
	
	//Zapatos
	Point verZapIzq[4]={Point(x-14,y+20), Point(x,y+20), Point(x,y+25), Point(x-14,y+25)};
	fillConvexPoly(img,verZapIzq,4,CV_RGB(104,57,13),8,0);
	
	Point verZapDer[4]={Point(x+4,y+20), Point(x+18,y+20), Point(x+18,y+25), Point(x+4,y+25)};
	fillConvexPoly(img,verZapDer,4,CV_RGB(104,57,13),8,0);
	
	//Mangas
	Point verMangaIzq[4]={Point(x-15,y-10), Point(x,y-10), Point(x,y), Point(x-15,y)};
	fillConvexPoly(img,verMangaIzq,4,CV_RGB(242,10,10),8,0);
	
	Point verMangaDer[4]={Point(x+10,y-10), Point(x+15,y-10), Point(x+15,y), Point(x+10,y)};
	fillConvexPoly(img,verMangaDer,4,CV_RGB(242,10,10),8,0);
	
	//Mano
	Point verManoIzq[4]={Point(x-18,y-10), Point(x-15,y-10), Point(x-15,y), Point(x-18,y)};
	fillConvexPoly(img,verManoIzq,4,CV_RGB(238,185,135),8,0);
	
	Point verManoDer[4]={Point(x+10,y-10), Point(x+18,y-10), Point(x+18,y), Point(x+10,y)};
	fillConvexPoly(img,verManoDer,4,CV_RGB(238,185,135),8,0);
	
	//Cabeza
	circle(img,Point(x,y-25),15,CV_RGB(238,185,135),-1,3);
	
	//Ojo
	Point verOjo[4]={Point(x+3,y-35), Point(x+6,y-35), Point(x+6,y-25), Point(x+3,y-25)};
	fillConvexPoly(img,verOjo,4,CV_RGB(0,0,0),8,0);
	
	//Nariz
	Point verNariz[4]={Point(x+3,y-25), Point(x+18,y-25), Point(x+18,y-20), Point(x+3,y-20)};
	fillConvexPoly(img,verNariz,4,CV_RGB(238,185,135),8,0);
	
	//Bigote
	Point verBigote[4]={Point(x+3,y-20), Point(x+15,y-20), Point(x+15,y-15), Point(x+3,y-15)};
	fillConvexPoly(img,verBigote,4,CV_RGB(0,0,0),8,0);
	
	//Cabello
	Point verCabello[4]={Point(x-15,y-40), Point(x-10,y-40), Point(x-10,y-20), Point(x-15,y-20)};
	fillConvexPoly(img,verCabello,4,CV_RGB(0,0,0),8,0);
	
	//Sombrero
	Point verSombrero[4]={Point(x-15,y-40), Point(x+18,y-40), Point(x+18,y-35), Point(x-15,y-35)};
	fillConvexPoly(img,verSombrero,4,CV_RGB(242,10,10),8,0);
	
	Point verGorra[4]={Point(x-15,y-50), Point(x+10,y-50), Point(x+10,y-40), Point(x-15,y-40)};
	fillConvexPoly(img,verGorra,4,CV_RGB(242,10,10),8,0);
	
	circle(img,Point(x+3,y-45),3,CV_RGB(255,255,255),-1,3);
}
void marioParado(Mat img,int x,int y){
	//Camisa
	Point verCamisa[4]={Point(x-10,y-10), Point(x+10,y-10), Point(x+10,y+10), Point(x-10,y+10)};
	fillConvexPoly(img,verCamisa,4,CV_RGB(10,80,242),8,0);
	
	Point verPlayera[3]={Point(x-10,y-10), Point(x+10,y-10), Point(x+10,y)};
	fillConvexPoly(img,verPlayera,3,CV_RGB(242,10,10),8,0);
	
	//Pantalon
	Point verPantalon[4]={Point(x-7,y+10), Point(x+7,y+10), Point(x+7,y+20), Point(x-7,y+20)};
	fillConvexPoly(img,verPantalon,4,CV_RGB(10,80,242),8,0);
	
	//Zapatos
	Point verZapato[4]={Point(x-7,y+20), Point(x+10,y+20), Point(x+10,y+25), Point(x-7,y+25)};
	fillConvexPoly(img,verZapato,4,CV_RGB(104,57,13),8,0);
	
	//Manga
	Point verManga[4]={Point(x-10,y-10), Point(x,y-10), Point(x,y), Point(x-10,y)};
	fillConvexPoly(img,verManga,4,CV_RGB(242,10,10),8,0);
	
	//Mano
	Point verMano[4]={Point(x-10,y), Point(x+3,y), Point(x+3,y+7), Point(x-10,y+7)};
	fillConvexPoly(img,verMano,4,CV_RGB(238,185,135),8,0);
	
	//Cabeza
	circle(img,Point(x,y-25),15,CV_RGB(238,185,135),-1,3);
	
	//Ojo
	Point verOjo[4]={Point(x+3,y-35), Point(x+6,y-35), Point(x+6,y-25), Point(x+3,y-25)};
	fillConvexPoly(img,verOjo,4,CV_RGB(0,0,0),8,0);
	
	//Nariz
	Point verNariz[4]={Point(x+3,y-25), Point(x+18,y-25), Point(x+18,y-20), Point(x+3,y-20)};
	fillConvexPoly(img,verNariz,4,CV_RGB(238,185,135),8,0);
	
	//Bigote
	Point verBigote[4]={Point(x+3,y-20), Point(x+15,y-20), Point(x+15,y-15), Point(x+3,y-15)};
	fillConvexPoly(img,verBigote,4,CV_RGB(0,0,0),8,0);
	
	//Cabello
	Point verCabello[4]={Point(x-15,y-40), Point(x-10,y-40), Point(x-10,y-20), Point(x-15,y-20)};
	fillConvexPoly(img,verCabello,4,CV_RGB(0,0,0),8,0);
	
	//Sombrero
	Point verSombrero[4]={Point(x-15,y-40), Point(x+18,y-40), Point(x+18,y-35), Point(x-15,y-35)};
	fillConvexPoly(img,verSombrero,4,CV_RGB(242,10,10),8,0);
	
	Point verGorra[4]={Point(x-15,y-50), Point(x+10,y-50), Point(x+10,y-40), Point(x-15,y-40)};
	fillConvexPoly(img,verGorra,4,CV_RGB(242,10,10),8,0);
	
	circle(img,Point(x+3,y-45),3,CV_RGB(255,255,255),-1,3);
}
