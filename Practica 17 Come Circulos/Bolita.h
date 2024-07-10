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

class Bolita {
	private:
		int id;
		Point posicion;
		int radio;
		bool vida;
		Scalar color;
		float grado;

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

	public:
		Bolita(){
		}

		Bolita(int id,Point posicion,int radio,Scalar color,float grado){
			this->id = id;
			this->posicion = posicion;
			this->radio = radio;
			this->color = color;
			this->vida = true;
			this->grado=grado;
		}

		void pintar(Mat img){
			circle(img,posicion,radio,color,-1,3);
		}

		void comer(Bolita *bolitas,int lng){
			float d;//Almacena la distacia entre las bolitas

			for (int i = 0; i < lng; i++){
				if((bolitas[i].id != this->id) && bolitas[i].vida){ //Si no es la misma bolita y esta viva
					d = sqrt(pow((bolitas[i].posicion.x - this->posicion.x),2) + pow((bolitas[i].posicion.y - this->posicion.y),2)); //Distacia entre las dos bolitas
					
					if (d <= this->radio-10){	//Si la distacia es igual a su radio
						if(this->radio > bolitas[i].radio){ // Si el tamaño de la bolita actual es mayor a la encontrada
							//Crece la bolita actual y muere la encontrada
							this->radio+=bolitas[i].radio*0.5;
							bolitas[i].vida=false;
						}else{
							if(this->radio < bolitas[i].radio){// Si el tamaño de la bolita actual es menor a la encontrada
								//Crece la bolita encontrada y muere la actual
								bolitas[i].radio+=this->radio*0.5;
								this->vida=false;
							}else{//Si son inguales
								//Se mueren ambas
								bolitas[i].vida=false;
								this->vida=false;
							}
						}	
					}
					
				}	
			}

		}
		
		void mover(int limX,int limY){
			limites(limX,limY);
			this->posicion=Point( this->posicion.x + (10*cos(this->grado)) , this->posicion.y - (10*sin(this->grado)) );
		}
		
		void explotar(){
			this->vida=false;
		}
		
		bool getVida(){
			return this->vida;
		}
		
		int getRadio(){
			return this->radio;
		}
		
		void setColor(Scalar color){
			this->color=color;
		}
};
