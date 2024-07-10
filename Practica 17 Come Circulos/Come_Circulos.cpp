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

//Clases Propias
#include "Bolita.h"

using namespace cv;

#define length(x) (sizeof(x)/sizeof(x[0]))

void creaBolitas(Bolita*,int);//Crea las bolitas en las que enpieza
Mat pintarBolitas(Bolita*,int);//Dibuja las bolitas en un lienzo y lo regresa
void comer(Bolita*,int);//LLama a comer a cada bolita
void mover(Bolita*,int);//Mueve cada bolita
int vivos(Bolita*,int);//Cuenta el numero de volitas vivas y el indice de la bolita mayor
void revivir(Bolita*,int);//Revive a las bolitas muertas

int main(){
	Mat img;
	Bolita bolitas[100];

	creaBolitas(bolitas,length(bolitas));
	img = pintarBolitas(bolitas,length(bolitas));
	putText(img, "Precione una Tecla", Point(150,img.rows/2), FONT_HERSHEY_DUPLEX, 3, CV_RGB(196,7,7), 2);
	
	namedWindow("Juego",WINDOW_AUTOSIZE);
	imshow("Juego",img);
	waitKey(0);

	while(true){
		mover(bolitas,length(bolitas));
		comer(bolitas,length(bolitas));
		
		if(vivos(bolitas,length(bolitas))<=1)
			revivir(bolitas,length(bolitas));
		
		imshow("Juego", pintarBolitas(bolitas,length(bolitas)) );
		if(waitKey(30) == 27)
			break;
	}
	return 0;
}

void creaBolitas(Bolita* bolitas,int lng){
	srand(time(NULL));
	for (int i = 0; i < lng; i++)
		bolitas[i] = Bolita(i,Point((rand()%1201)+50,(rand()%501)+50),(rand()%6)+15,CV_RGB(rand()%256,rand()%256,rand()%256),((rand()%361)*PI)/180);
}

Mat pintarBolitas(Bolita* bolitas,int lng){
	Mat img = Mat(600,1300,CV_8UC3,CV_RGB(0,0,0));
	
	//Pinta todas
	for (int i = 0; i < lng; i++)
		if(bolitas[i].getVida())
			bolitas[i].pintar(img);
			
	//Explotan las mas grandes
	for (int i = 0; i < lng; i++)
		if(bolitas[i].getRadio()>=200 && bolitas[i].getVida()){ //Si su radio es mayor o igual a 100 explota
			
			//Animacion de explotar
			for (int j = 0; j < 10; j++){
				if(j%2==0)
					bolitas[i].setColor(CV_RGB(151,14,14));
				else
					bolitas[i].setColor(CV_RGB(255,255,255));
				
				bolitas[i].pintar(img);
				imshow("Juego",img);
				if(waitKey(200) == 27)
					break;
			}
			
			bolitas[i].explotar();//Explota
		}
			
			
	return img;
}

void comer(Bolita* bolitas,int lng){
	for (int i = 0; i < lng; i++)
		if(bolitas[i].getVida())
			bolitas[i].comer(bolitas,lng);		
}

void mover(Bolita* bolitas,int lng){
	for (int i = 0; i < lng; i++)
		if(bolitas[i].getVida())
			bolitas[i].mover(1300,600);
}

int vivos(Bolita* bolitas,int lng){
	int cont=0;
	for (int i = 0; i < lng; i++)
		if(bolitas[i].getVida())
			cont++;
	return cont;
}

void revivir(Bolita* bolitas,int lng){
	for (int i = 0; i < lng; i++)
		if(!(bolitas[i].getVida()))
			bolitas[i] = Bolita(i,Point((rand()%1201)+50,(rand()%501)+50),(rand()%6)+15,CV_RGB(rand()%256,rand()%256,rand()%256),((rand()%361)*PI)/180);
}
