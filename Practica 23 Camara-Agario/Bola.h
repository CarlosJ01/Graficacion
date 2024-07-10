//Clase para el Juego

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

# define PI           3.14159265358979323846

//Clase Padre Bola
class Bola {
	public:
		Point posicion;
		int radio;
		bool vida;
		Scalar color;
		
		Bola(){
		}

		void pintar(Mat img){
			circle(img,posicion,radio,color,-1,3);
		}
};

class Presa : public Bola {
	public:
		//Id que lo diferencia en el arreglo
		int id;
		//Grado hacia donde se menea
		float grado;
		int tipo;
		
		//Limites para que rebote
		void limites(int limX, int limY){
			srand(time(NULL));
			if (this->posicion.x <= 0){
				this->grado=(((rand()%181)+270)*PI)/180;
				return;
			}
			if(this->posicion.x >= limX){
				this->grado=(((rand()%181)+90)*PI)/180;
				return;
			}
			if(this->posicion.y <= 0){
				this->grado=(((rand()%181)+180)*PI)/180;
				return;
			}
			if(this->posicion.y >= limY){
				this->grado=((rand()%181)*PI)/180;
				return;
			}
		}
	
		Presa(){
		}
		
		Presa(int id, Point posicion,int radio,Scalar color,float grado, int tipo){
			this->id = id;
			this->posicion = posicion;
			this->radio = radio;
			this->color = color;
			this->grado=grado;
			this->vida = true;
			this->tipo = tipo;
		}
		
		void mover(int limX,int limY){
			limites(limX,limY);
			this->posicion=Point( this->posicion.x + (3*cos(this->grado)) , this->posicion.y - (3*sin(this->grado)) );
		}
		
		bool getVida(){
			return this->vida;
		}
		
		int getRadio(){
			return this->radio;
		}
};

class Depredador : public Bola{
	public:
	Depredador(){
	}
	
	Depredador(Point posicion,int radio,Scalar color){
		this->posicion = posicion;
		this->radio = radio;
		this->color = color;
		this->vida = true;
	}
	
	void mover(Mat img, Point pnt){
		this->posicion=pnt;
		pintar(img);
	}
	
	void comer(Presa *bolitas,int lng){
		float d;//Almacena la distacia entre las bolitas
		for (int i = 0; i < lng; i++){
			if(bolitas[i].vida){ //Si esta viva
				//Distacia entre las dos bolitas
				d = sqrt(pow((bolitas[i].posicion.x - this->posicion.x),2) + pow((bolitas[i].posicion.y - this->posicion.y),2));
				if (d <= this->radio-3){//Si la distacia es menor o igual a su radio - 10
					if(this->radio >= bolitas[i].radio){ // Si el tamaño de la bolita actual es mayor a la encontrada
						if(bolitas[i].tipo == 0){ // Si el tipo es 0 entoces crese
							this->radio+=bolitas[i].radio*0.6;
							bolitas[i].vida=false;
						}else{//Sino entonces decrese
							this->radio-=bolitas[i].radio*0.4;
							bolitas[i].vida=false;
						}
					}
				}
			}
		}
	}
	
	int getRadio(){
		return this->radio;
	}
	
	void setRadio(int rdo){
		this->radio=rdo;
	}
};
