#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <opencv2/imgproc/imgproc.hpp>//Libreria para primitivas de dibujo
#include <math.h>//Libreria para fuciones matematicas

using namespace cv;

# define PI           3.14159265358979323846  /* pi */

void puntos(Mat,Point[],int,int);

int main(){
	int rad=0;
	int num=0;
	
	//Datos para controlar el tamaño y se vea bien
	do{
		printf("Ingresa el radio entre 1 y 300: ");
		scanf("%d",&rad);
		printf("Ingresa el numero de puntos entre 2 y 360: ");
		scanf("%d",&num);
		printf("\n------------------------------------------------------\n");
	}while(rad<=0 || rad>300 || num<=1 || num>360);
	
	//Fondo y arreglo de puntos
	Mat fondo = Mat((rad*2)+25,(rad*2)+25,CV_8UC3,CV_RGB(132,9,13));
	Point pts[num];
	
	//Genera los puntos y dibuja puntos
	puntos(fondo,pts,rad,num);
	
	//Tiempo de Animacion entre mas puntos mas velos
	int tmp=0;
	if(num>50)
		tmp=1;
	else
		if(num>10)
			tmp=10;
		else
			tmp=100;
			
	//Dibujar las lineas
	for(int i=0;i<(int)(sizeof(pts)/sizeof(Point));i++)
		for(int j=0;j<(int)(sizeof(pts)/sizeof(Point));j++)
			if(j!=i){
				line(fondo,pts[i],pts[j],CV_RGB(220,180,20),1,8,0);
				
				//Animacion de lineas
				namedWindow("Circulo",WINDOW_AUTOSIZE);
				imshow("Circulo",fondo);
				
				if(waitKey(tmp)==0)
					break;
			}
	
	imshow("Circulo",fondo);
	waitKey(0);
	return 0;
}

void puntos(Mat img,Point pts[],int rad,int num){
	float x,y;
	float grd=0;//Grados
	float incre=(2*PI)/num;//Incremento de grados
	
	//Recorre el arreglo,genera los puntos y los pone en el arreglo
	for(int i=0;i<num;i++,grd+=incre){
		x=img.cols/2 + (rad*cos(grd));
		y=img.rows/2 - (rad*sin(grd));
		pts[i]=Point(x,y);
		
		circle(img,pts[i],1,CV_RGB(220,180,20),-1,3);
		
		//Animacion de circulos
		namedWindow("Circulo",WINDOW_AUTOSIZE);
		imshow("Circulo",img);
		if(waitKey(50)==0)
			break;
	}
}
