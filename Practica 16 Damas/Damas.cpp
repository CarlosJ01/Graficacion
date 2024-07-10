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

//Estructura de una ficha
struct ficha{
	Point punto=Point(0,0);
	bool vacio=true;
};

//Crea un triangulo
Mat triangulo(struct ficha*);
//Jugar
void jugar(Mat,struct ficha*);
//DibujarTriangulo
void dibujarTriangulo(Mat,struct ficha*);
//Compara puntos
bool puntoIgual(struct ficha*,int,int,int*);

//Movimiento
int movimiento(struct ficha*,int);

int main(){
	ficha fichas[15];
	Mat img = triangulo(fichas);

	jugar(img,fichas);
	
	waitKey(0);
	return 0;
}

//Crea el triangulo
Mat triangulo(struct ficha* fichas){
	Mat img = Mat(300,450,CV_8UC3,CV_RGB(194,136,3));
	Point pnt;
	int x=(img.cols/2), y=50;
	int cont=0;

	for (int i = 1; i <= 5; i++){
		for (int j = 0; j < i; j++){
			pnt=Point(x,y);
			fichas[cont].punto=pnt;
			x=x+100;
			cont++;
		}
		x=img.cols/2-(50*i);
		y+=50;
	}

	return img;
}

//Jugar
void jugar(Mat img,struct ficha* fichas){
	srand(time(NULL));
	fichas[rand()%15].vacio=false; //Ficha en la que inicia
	dibujarTriangulo(img,fichas);

	namedWindow("Come solo",WINDOW_AUTOSIZE);
	imshow("Come solo",img);
	waitKey(1500);

	int contNeg;
	int contMov;
	do{
		contNeg=0;
		contMov=0;
		
		for (int i = 0; i < 15; i++){
			if(fichas[i].vacio==false){
				contNeg++;
				if(movimiento(fichas,i)==0){
					dibujarTriangulo(img,fichas);
					imshow("Come solo",img);
					if(waitKey(2000)==23)
						break;
				}else{
					contMov++;
				}
			}
		}
		
		printf("Fichas Negras : %d\t Fichas que no se pueden menear : %d\n",contNeg,contMov);
		
	} while (contNeg != contMov);
	printf("\n------------------- FIN DEL JUEGO -------------------\n");
}

//Diguja el triangulo
void dibujarTriangulo(Mat img,struct ficha* fichas){

	line(img,fichas[0].punto,fichas[14].punto,CV_RGB(128,128,128),3,8,0);
	line(img,fichas[0].punto,fichas[10].punto,CV_RGB(128,128,128),3,8,0);
	line(img,fichas[10].punto,fichas[14].punto,CV_RGB(128,128,128),3,8,0);
	line(img,fichas[1].punto,fichas[2].punto,CV_RGB(128,128,128),3,8,0);
	line(img,fichas[3].punto,fichas[5].punto,CV_RGB(128,128,128),3,8,0);
	line(img,fichas[6].punto,fichas[9].punto,CV_RGB(128,128,128),3,8,0);
	line(img,fichas[1].punto,fichas[13].punto,CV_RGB(128,128,128),3,8,0);
	line(img,fichas[2].punto,fichas[11].punto,CV_RGB(128,128,128),3,8,0);
	line(img,fichas[3].punto,fichas[12].punto,CV_RGB(128,128,128),3,8,0);
	line(img,fichas[5].punto,fichas[12].punto,CV_RGB(128,128,128),3,8,0);
	line(img,fichas[6].punto,fichas[11].punto,CV_RGB(128,128,128),3,8,0);
	line(img,fichas[9].punto,fichas[13].punto,CV_RGB(128,128,128),3,8,0);

	for (int i = 0; i < 15; i++){
		if(fichas[i].vacio)
			circle(img,fichas[i].punto,10,CV_RGB(255,255,255),-1,3);
		else
			circle(img,fichas[i].punto,10,CV_RGB(0,0,0),-1,3);
	}
}

//Movimiento de la ficha
int movimiento(struct ficha* fichas,int pos){
	int ind1;//Indice 1
	int ind2;//Indice 2

	//Superior Derecho
	if(puntoIgual(fichas,fichas[pos].punto.x+50,fichas[pos].punto.y-50, &ind1) && puntoIgual(fichas,fichas[pos].punto.x+100,fichas[pos].punto.y-100, &ind2)){
		fichas[ind2].vacio=false;
		fichas[ind1].vacio=false;
		fichas[pos].vacio=true;
		return 0;
	}

	//Superior Izquierdo
	if(puntoIgual(fichas,fichas[pos].punto.x-50,fichas[pos].punto.y-50, &ind1) && puntoIgual(fichas,fichas[pos].punto.x-100,fichas[pos].punto.y-100, &ind2)){
		fichas[ind2].vacio=false;
		fichas[ind1].vacio=false;
		fichas[pos].vacio=true;
		return 0;
	}

	//Inferior Derecho
	if(puntoIgual(fichas,fichas[pos].punto.x+50,fichas[pos].punto.y+50, &ind1) && puntoIgual(fichas,fichas[pos].punto.x+100,fichas[pos].punto.y+100, &ind2)){
		fichas[ind2].vacio=false;
		fichas[ind1].vacio=false;
		fichas[pos].vacio=true;
		return 0;
	}

	//Inferior Izquierdo
	if(puntoIgual(fichas,fichas[pos].punto.x-50,fichas[pos].punto.y+50, &ind1) && puntoIgual(fichas,fichas[pos].punto.x-100,fichas[pos].punto.y+100, &ind2)){
		fichas[ind2].vacio=false;
		fichas[ind1].vacio=false;
		fichas[pos].vacio=true;
		return 0;
	}

	//Derecha
	if(puntoIgual(fichas,fichas[pos].punto.x+100,fichas[pos].punto.y, &ind1) && puntoIgual(fichas,fichas[pos].punto.x+200,fichas[pos].punto.y, &ind2)){
		fichas[ind2].vacio=false;
		fichas[ind1].vacio=false;
		fichas[pos].vacio=true;
		return 0;
	}

	//Izquierda
	if(puntoIgual(fichas,fichas[pos].punto.x-100,fichas[pos].punto.y, &ind1) && puntoIgual(fichas,fichas[pos].punto.x-200,fichas[pos].punto.y, &ind2)){
		fichas[ind2].vacio=false;
		fichas[ind1].vacio=false;
		fichas[pos].vacio=true;
		return 0;
	}

	return 1;
}

//Compara puntos
bool puntoIgual(struct ficha* fichas,int x,int y,int* ind){
	for (int i = 0; i < 15; i++){
		if(fichas[i].punto.x == x && fichas[i].punto.y == y && fichas[i].vacio){
			*ind=i;
			return true;
		}
	}
	*ind=-1;
	return false;
}
