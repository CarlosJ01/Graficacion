#include "opencv2/video/tracking.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include <stdio.h>
#include <iostream>
#include <ctype.h>
#include <math.h>
#include <string.h>

//Mi Clase para los jugadores y bolitas
#include "Bola.h"

#define length(x) (sizeof(x)/sizeof(x[0]))

using namespace cv;
using namespace std;

Point2f point;
bool addRemovePt = false;

void creaPresas(Presa*,int);
void moverPresas(Presa*,int, Mat);
bool movio(Point,Point);
int vivos(Presa*,int);
void revivir(Presa*,int);
bool gameOver(Depredador,Presa*,int);

int main(int argc, char** argv ){
	VideoCapture cap;
    TermCriteria termcrit(TermCriteria::COUNT|TermCriteria::EPS,20,0.03);
    Size subPixWinSize(10,10), winSize(31,31);

	CommandLineParser parser(argc, argv, "{@input||}{help h||}");
    string input = parser.get<string>("@input");
  
	if( input.empty() )
        cap.open(0);
    else if( input.size() == 1 && isdigit(input[0]) )
			cap.open(input[0] - '0');
		else
			cap.open(input);

    if( !cap.isOpened() ){
		cout << "Could not initialize capturing...\n";
        return 0;
    }

    namedWindow( "LK Agario", 1 );
    
    Mat gray, prevGray, image, frame;
    vector<Point2f> points[2];
    vector<Point2f> operaciones[2];
    int j=0, i=0;
    
    //Posiciones x y y del jugador
    float xJgdr = 320;
    float yJgdr = 240;
    //Arreglo de presas
    Presa presas[30];
    creaPresas(presas,length(presas));
    
    //Jugador "Depredador"
    Depredador jugador = Depredador(Point(xJgdr,yJgdr), 20, CV_RGB(156,29,7));
    
    if( points[0].empty() ){
		for(i=0; i<11; i++)
			for(j=0; j<22; j++)
				points[0].push_back(Point2f(325+(j*15),330+(i*15)));
		/*
		for(i=0; i<17; i++)
			for(j=0; j<23; j++)
				points[0].push_back(Point2f(0+(j*30),0+(i*30)));
		*/
	}
	
	for(;;){
		cap >> frame;
		flip(frame, frame, 1);
      
		if( frame.empty() )
			break;
      
		frame.copyTo(image);
		cvtColor(image, gray, COLOR_BGR2GRAY);
		
		if( !points[0].empty() ){
			vector<uchar> status;
			vector<float> err;
		
			if(prevGray.empty())
				gray.copyTo(prevGray);
		
			calcOpticalFlowPyrLK(prevGray, gray, points[0], points[1], status, err, winSize,3, termcrit, 0, 0.01);
			
			double cont=0;
			
			double promX = 0;
			double promY = 0;
			
			size_t i, k;
			for( i = k = 0; i < points[0].size() ; i++ ) {
				points[1][k++] = points[1][i];
				
				//Malla
				circle( image, points[1][i], 1, Scalar(0,255,0), -1, 8);//Punto
				if((i+1)%22 != 0)//Filas
					line(image,points[1][i],points[1][i+1], Scalar(0,255,0),1, 8,0);
				if(i<=points[0].size()-23)//Columnas
					line(image,points[1][i],points[1][i+22], Scalar(0,255,0),1, 8,0);
				
				//Si un punto se movio
				if(movio(points[0][i],points[1][i])){
					cont++;//Incrementa un cotador
					promX+= points[0][i].x - points[1][i].x;//Incrementamos un contador en lo que se movio en x
					promY+= points[0][i].y - points[1][i].y;//Incrementamos un contador en lo que se movio en y
				}
				
			}
			
			//Si hay elemntos que se movieron
			if(cont != 0){
				promX/=cont;//Promedio de movimiento en x
				promY/=cont;//Promedio de movimiento en y
				
				//Desplasamos lo que se movieron en x e y, en promedio
				xJgdr += promX*-10;
				yJgdr += promY*-10;
				
				//Limites de la pantalla
				if(xJgdr<=0)
					xJgdr=0;
				else if(xJgdr>=image.cols)
					xJgdr=image.cols;
				
				if(yJgdr<=0)
					yJgdr=0;
				else if(yJgdr>=image.rows)
					yJgdr=image.rows;		
			}
			
			points[1].resize(k);
		}
		
		moverPresas(presas,length(presas),image);//Mueve y pinta las presas
		jugador.mover(image,Point(xJgdr,yJgdr));//Mueve al jugador
		jugador.comer(presas,length(presas));//Condiciones y acciones de comer
		
		//Control de radio muy grande
		if(jugador.getRadio() >= 200)
			jugador.setRadio(15);
			
		//Revivir a los caidos
		if(vivos(presas,length(presas)) <= 3)
			revivir(presas,length(presas));
		
		//Game Over Ya no se puede comer
		if(gameOver(jugador, presas, length(presas)))
			putText(image, "GAME OVER", Point(50,image.rows/2), FONT_HERSHEY_DUPLEX, 3, CV_RGB(196,7,7), 2);
		
		imshow("LK Agario", image);
		char c = (char)waitKey(10);
		
		if( c == 27 )
			break;
        
        swap(prevGray, gray);
	}

    return 0;
}

bool movio(Point pnt1,Point pnt2){
	if( sqrt(pow((pnt1.x - pnt2.x),2) + pow((pnt1.y - pnt2.y),2)) == 0)
		return false;
	else
		return true;
}

void creaPresas(Presa* bolitas,int lng){
	srand(time(NULL));
	for (int i = 0; i < lng; i++)
		switch(rand()%2){
			case 0:
				bolitas[i] = Presa(i,Point((rand()%640),(rand()%480)), (rand()%26)+5,CV_RGB(20,11,203),((rand()%361)*PI)/180,0);
				break;
			case 1:
				bolitas[i] = Presa(i,Point((rand()%640),(rand()%480)), (rand()%21)+5,CV_RGB(197,11,203),((rand()%361)*PI)/180,1);
				break;
		}
}

void moverPresas(Presa* bolitas,int lng,Mat img){
	for (int i = 0; i < lng; i++)
		if(bolitas[i].getVida()){			
			bolitas[i].mover(img.cols,img.rows);
			bolitas[i].pintar(img);
		}
}

int vivos(Presa* bolitas,int lng){
	int cont=0;
	for (int i = 0; i < lng; i++)
		if(bolitas[i].getVida())
			cont++;
	return cont;
}

void revivir(Presa* bolitas,int lng){
	for (int i = 0; i < lng; i++)
		if(!(bolitas[i].getVida()))
			switch(rand()%2){	
				case 0:
					bolitas[i] = Presa(i,Point((rand()%640),(rand()%480)), (rand()%26)+5,CV_RGB(20,11,203),((rand()%361)*PI)/180,0);
					break;
				case 1:
					bolitas[i] = Presa(i,Point((rand()%640),(rand()%480)), (rand()%21)+5,CV_RGB(197,11,203),((rand()%361)*PI)/180,1);
					break;
			}
}

bool gameOver(Depredador jgd,Presa* bolitas,int lng){
	int menor = 1000;
	for (int i = 0; i < lng; i++)
		if(bolitas[i].getVida() && bolitas[i].getRadio() < menor)
			menor = bolitas[i].getRadio();
	
	if(menor > jgd.getRadio())
		return true;
	
	return false; 
}
