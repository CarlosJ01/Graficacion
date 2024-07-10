//Examen Departamental
//Carlos Jahir Castro Cázares

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
using namespace std;

//Matriz, Filas y columnas
const int fils = 5;
const int cols = 5;
bool mtz[5][5] = {{true, true, false, false, false},
				  {true, true, true,  true,  true},
				  {true, true, true,  true,  true},
				  {true, true, true,  true,  true},
				  {false, false, true, true, true}};
//Estructura de para cordenasa
struct Cordenada{
	int i=-1;
	int j=-1;
};

//Pila de Cordenadas por donde pasa la linea
vector<Cordenada> cordenadas;

//Imagen para la animacion
Mat img; 

bool mover(int,int,int);
int numPasos(int,int,char);
void pintar(int);
void despintar(int);
bool gane();
void jugar(int,int);
void pintarMatriz(int);

void pedirDatos(int*,int*);
void inicioAleatorio(int*,int*);
			  
int main(){
	int i = 0;
	int j = 0;
	
	img = Mat(520,520,CV_8UC3,CV_RGB(220,168,7));
	namedWindow("Juego",WINDOW_AUTOSIZE);
	
	//Aleatorio
	inicioAleatorio(&i,&j);
	
	//Pide los datos
	//pedirDatos(&i,&j);
	
	jugar(i,j);
	
	imshow("Juego",img);
	waitKey(0);
	return 0;
}

//Metodo para empezar a jugar con un punto
void jugar(int i,int j){
	int num = 0;
	mtz[i][j]=false;
	
	pintarMatriz(0);
	waitKey(0);
	
	num = numPasos(i,j,'^');//Arriba
	if(mover(i-num,j,num) == false){
		num = numPasos(i,j,'v');//Abajo
		if(mover(i+num,j,num)==false){
			num = numPasos(i,j,'<');//Izquierda
			if(mover(i,j-num,num) == false){
				num = numPasos(i,j,'>');//Derecha
				if(mover(i,j+num,num) == false){
					printf("No hay Solucion");
					putText(img, "PERDIO", Point(110,img.rows/2), FONT_HERSHEY_DUPLEX, 3, CV_RGB(196,7,7), 3);
					return;
				}
			}
		}
	}
	printf("Encontro la Solucion");
	putText(img, "GANO", Point(140,img.rows/2), FONT_HERSHEY_DUPLEX, 3, CV_RGB(196,7,7), 3);
}

//Metodo recursivo para buscar caminos
bool mover(int i,int j,int tam){
	int num = 0;
	bool b1,b2,b3,b4;
	if(i>=0 && i<fils && j>=0 && j<cols)//Si esta en los limites de la matriz
		if(mtz[i][j]){//Si en esa pocion esta libre entonces mueve
			pintar(tam);//Pinta la linea por donde pasa
			
			num = numPasos(i,j,'^');//Arriba
			b1 = mover(i-num,j,num);
			
			num = numPasos(i,j,'v');//Abajo
			b2 = mover(i+num,j,num); 
			
			num = numPasos(i,j,'<');//Izquierda
			b3 = mover(i,j-num,num);
			
			num = numPasos(i,j,'>');//Derecha
			b4 = mover(i,j+num,num);
			
			if(!b1 && !b2 && !b3 && !b4)//Si ya no se puede mover
				if(gane()) //Comprueba si gano
					return true;//Si gano retorna true y termina la recursividad
				else{//Si todabia no gana
					despintar(tam);//Despinta la linea hecha
					return false;//Reorna false para pasar al paso anterior
				} 
			else//Si ya se lanzo un true por ganar entoces lanza otro para seguir
				return true;//Lanza true para seguir terminando la recursividad
		}
	return false;//Reorna false para pasar al paso anterior
}

//Pinta los cuadros por donde paso la linea
void pintar(int num){
	int tam = cordenadas.size() - 1;
	if(tam!=-1){
		for(int i=0; i<num; i++)
			mtz[cordenadas[tam-i].i][cordenadas[tam-i].j]=false;
		pintarMatriz(1);
	}		
}

//Debolber a la matriz a su estado anterior en un numero de pasos
void despintar(int num){
	Cordenada crd;
	if(cordenadas.size() != 0){
		for(int i=1; i<=num; i++){
			crd = cordenadas.back();
			cordenadas.pop_back();
			mtz[crd.i][crd.j]=true;
		}
		pintarMatriz(1);
	}
}

//Saber cuanto se tiene que desplazar hasta llegar al borde o aun obstaculo
int numPasos(int i,int j,char dir){
	int cont=0;
	Cordenada crd;
	
	while(true){
		switch(dir){
			case '^':
					i--;
					break;
			case '>':
					j++;
					break;
			case 'v':
					i++;
					break;
			case '<':
					j--;
					break;
		}
		
		if(mtz[i][j] == false || i<0 || i>=fils || j<0 || j>=cols){
			if(cont==0)
				return 1;
			return cont;
		}
		
		crd.i=i;
		crd.j=j;
		cordenadas.push_back(crd);
		cont++;
	} 
}

//Saber si la matriz esta llena de false
bool gane(){
	for (int i = 0; i < fils; i++)
		for (int j = 0; j < cols; j++)
			if(mtz[i][j])
				return false;
	return true;
}

//Pasa la matriz boleana a un Mat y lo anima
void pintarMatriz(int opc){
	img = Mat(520,520,CV_8UC3,CV_RGB(220,168,7));
	
	//Recuadros del juego
	for (int i = 0; i < fils; i++){
		for (int j = 0; j < cols; j++){
			if(mtz[i][j]){
				Point ver[4] = {Point(10+(100*j),10+(100*i)), Point(110+(100*j),10+(100*i)), Point(110+(100*j),110+(100*i)), Point(10+(100*j),110+(100*i))};
				fillConvexPoly(img,ver,4,CV_RGB(255,255,255),8,0);
			}
			else{
				Point ver[4] = {Point(10+(100*j),10+(100*i)), Point(110+(100*j),10+(100*i)), Point(110+(100*j),110+(100*i)), Point(10+(100*j),110+(100*i))};
				fillConvexPoly(img,ver,4,CV_RGB(0,0,0),8,0);
			}	
		}
	}
	
	//Barreras
	Point bar1[4] = {Point(210,10), Point(510,10), Point(510,110), Point(210,110)};
	fillConvexPoly(img,bar1,4,CV_RGB(140,8,8),8,0);
	
	Point bar2[4] = {Point(10,410), Point(210,410), Point(210,510), Point(10,510)};
	fillConvexPoly(img,bar2,4,CV_RGB(140,8,8),8,0);
	// Lineas
	for(int i=0; i<4; i++)
		line(img,Point(110+(100*i),10),Point(110 +(100*i),510),CV_RGB(220,168,7),5,8,0);
	
	for(int i=0; i<4; i++)
		line(img,Point(10,110+(100*i)),Point(510,110+(100*i)),CV_RGB(220,168,7),5,8,0);
	
	if(opc == 0)
		putText(img, "Preciona una tecla", Point(30,img.rows/2), FONT_HERSHEY_DUPLEX, 1.5, CV_RGB(196,7,7), 2);	
	
	imshow("Juego",img);
	waitKey(250);
}

//Pedir el pinto inicial a usuario
void pedirDatos(int* i,int* j){
	int ni,nj;
	do{
		printf("Ingresa la fila y columna donde va a empezar \n");
		printf("Ingresa la Fila : ");
		scanf("%d",&ni);
		printf("Ingresa la Columna : ");
		scanf("%d",&nj);
		printf("\n------------------------------------------------------\n");
	}while(ni<0 || ni>=fils || nj<0 || nj>=cols || (ni==0 && nj==2) || (ni==0 && nj==3) || (ni==0 && nj==4) || (ni==4 && nj==0) || (ni==4 && nj==1) );
	
	*i=ni;
	*j=nj;
}

//Punto inicial aleatorio
void inicioAleatorio(int* i,int* j){
	int ni,nj;
	srand(time(NULL));
	ni = rand()%5;
	if(ni == 0)
		nj=rand()%2;
	else
		if(ni == 4)
			nj=rand()%3+2;
		else
			nj=rand()%5;
	
	*i=ni;
	*j=nj;
}
