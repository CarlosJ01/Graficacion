#include <iostream>
#include <stdlib.h>

//OpenCv
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

//Compilador
//g++ -Wall %f -o %e `pkg-config --cflags --libs opencv`

using namespace cv;

//Colores
const int clrNegro = 0;
const int clrBlanco = 255;
const int clrAmarillo = 153;
const int clrPiel = 204;
const int clrGris = 75;
const int clrAzul = 52;

//Escala
const int fil = 408;
const int col = 408;
const int esc = 17; //Escala al dibujo 1(24 x 24)-17(408x408)

//Prototipos de Funciones
void pintBlanco(Mat);
void pintAmarillo(Mat);
void pintPiel(Mat);
void pintGris(Mat);
void pintAzul(Mat);

void pintar(Mat,int,int,int,int,int);

int main(){
	//Matriz
	Mat imgVb=Mat(fil,col,CV_8UC1,Scalar(clrNegro));
	
	//Pintar
	pintBlanco(imgVb);
	pintAmarillo(imgVb);
	pintPiel(imgVb);
	pintGris(imgVb);
	pintAzul(imgVb);
	
	//Imprimir
	namedWindow("Vault-Boy",WINDOW_AUTOSIZE);
	imshow("Vault-Boy",imgVb);
	waitKey(0);
	
	return 0;
}

//Pintar segmentos azules
void pintAzul(Mat img){
	pintar(img,10,4,13,7,clrAzul);
	pintar(img,11,7,13,8,clrAzul);
	pintar(img,12,8,14,9,clrAzul);
	pintar(img,13,9,14,10,clrAzul);
	pintar(img,14,9,17,12,clrAzul);
	pintar(img,14,13,17,17,clrAzul);
	pintar(img,13,15,14,16,clrAzul);
	pintar(img,12,16,14,17,clrAzul);
	pintar(img,11,17,13,18,clrAzul);
	pintar(img,11,18,14,20,clrAzul);
	pintar(img,13,20,15,22,clrAzul);
	pintar(img,19,7,22,10,clrAzul);
	pintar(img,19,10,21,11,clrAzul);
	pintar(img,19,11,20,12,clrAzul);
	pintar(img,19,13,20,14,clrAzul);
	pintar(img,19,14,21,15,clrAzul);
	pintar(img,19,15,22,19,clrAzul);
	pintar(img,10,18,11,19,clrAzul);
	pintar(img,11,20,13,21,clrAzul);
	pintar(img,18,9,19,18,clrAzul);
}

//Pintar segmentos grises
void pintGris(Mat img){
	pintar(img,21,5,22,7,clrGris);
	pintar(img,22,3,23,10,clrGris);
	pintar(img,21,19,22,21,clrGris);
	pintar(img,22,15,23,23,clrGris);
}

//Pintar segmentos color piel
void pintPiel(Mat img){
	//Cara
	pintar(img,5,11,7,15,clrPiel);
	pintar(img,7,10,10,12,clrPiel);
	pintar(img,6,9,7,11,clrPiel);
	pintar(img,6,8,10,9,clrPiel);
	pintar(img,9,9,11,10,clrPiel);
	pintar(img,9,12,10,14,clrPiel);
	pintar(img,7,13,9,17,clrPiel);
	pintar(img,6,15,7,16,clrPiel);
	pintar(img,6,17,8,18,clrPiel);
	pintar(img,9,15,10,17,clrPiel);
	pintar(img,10,14,11,16,clrPiel);
	pintar(img,11,10,12,15,clrPiel);
	
	//Manos
	pintar(img,10,2,13,4,clrPiel);
	pintar(img,9,3,10,4,clrPiel);
	pintar(img,15,19,17,22,clrPiel);
}

//Pintar segmentos amarillos
void pintAmarillo(Mat img){
	//Pelo
	pintar(img,3,6,4,8,clrAmarillo);
	pintar(img,4,7,6,10,clrAmarillo);
	pintar(img,3,9,4,10,clrAmarillo);
	pintar(img,2,10,5,15,clrAmarillo);
	pintar(img,3,15,6,17,clrAmarillo);
	pintar(img,2,15,3,16,clrAmarillo);
	pintar(img,6,16,7,17,clrAmarillo);
	pintar(img,5,10,6,11,clrAmarillo);
	
	//Ropa
	pintar(img,10,7,11,8,clrAmarillo);
	pintar(img,11,8,12,9,clrAmarillo);
	pintar(img,12,9,13,10,clrAmarillo);
	pintar(img,13,10,14,15,clrAmarillo);
	pintar(img,12,15,13,16,clrAmarillo);
	pintar(img,11,16,12,17,clrAmarillo);
	pintar(img,10,17,11,18,clrAmarillo);
	pintar(img,14,12,17,13,clrAmarillo);
	pintar(img,17,9,18,17,clrAmarillo);
	
}

//Pintar segmentos en blanco
void pintBlanco(Mat img){
	pintar(img,0,0,8,5,clrBlanco);
	pintar(img,6,5,8,7,clrBlanco);
	pintar(img,8,4,9,7,clrBlanco);
	pintar(img,8,0,24,1,clrBlanco);
	pintar(img,8,1,10,2,clrBlanco);
	pintar(img,8,2,9,3,clrBlanco);
	pintar(img,4,5,6,6,clrBlanco);
	pintar(img,0,5,2,10,clrBlanco);
	pintar(img,2,5,3,6,clrBlanco);
	pintar(img,2,8,3,9,clrBlanco);
	pintar(img,13,1,24,2,clrBlanco);
	pintar(img,14,2,18,8,clrBlanco);
	pintar(img,18,2,21,5,clrBlanco);
	pintar(img,21,2,22,3,clrBlanco);
	pintar(img,18,5,20,6,clrBlanco);
	pintar(img,18,6,19,7,clrBlanco);
	pintar(img,20,12,21,13,clrBlanco);
	pintar(img,21,11,24,14,clrBlanco);
	pintar(img,0,10,1,24,clrBlanco);
	pintar(img,1,19,10,24,clrBlanco);
	pintar(img,1,17,3,19,clrBlanco);
	pintar(img,3,18,6,19,clrBlanco);
	pintar(img,1,16,2,17,clrBlanco);
	pintar(img,10,22,13,24,clrBlanco);
	pintar(img,10,21,11,22,clrBlanco);
	pintar(img,8,18,9,19,clrBlanco);
	pintar(img,13,23,22,24,clrBlanco);
	pintar(img,18,21,21,23,clrBlanco);
	pintar(img,17,22,18,23,clrBlanco);
	pintar(img,18,20,20,21,clrBlanco);
	pintar(img,18,19,19,20,clrBlanco);
	pintar(img,17,18,18,19,clrBlanco);
}

//Pinta una parte de la matriz de un color
void pintar(Mat img,int filIni,int colIni,int filFin,int colFin,int clr){
	//Escalar
	filIni*=esc;
	colIni*=esc;
	filFin*=esc;
	colFin*=esc;
	
	//Pintar
	for(int i=filIni;i<filFin;i++)
		for(int j=colIni;j<colFin;j++)
			img.at<uchar>(i,j)=clr;
}
