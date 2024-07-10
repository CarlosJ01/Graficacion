//C++
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <list>

//OpenCv
#include <opencv2/core/core.hpp> 
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

//Estructura para aguardar la posion de un elemento de la cadena
struct Elemento{
	int i;
	int j;
};

class Cadena{
	public:
		int id;//Id posicion de la cadena en el arreglo
		list<Elemento> elementos;//Elementos de la cadena
		Scalar color;//Color de la cadena
		
		//Constructores
		Cadena(){
		}
		
		Cadena(int id, Scalar clr){
			this->id = id;
			this->color = clr;		
		}
		
		//Ingresar un elemento a la cadena nueva
		void ingresarElemento(Elemento ele){
			elementos.push_back(ele);
		}
		
		//Poner los valores a la matriz
		void ponerMatriz(int* mtz){
			list<Elemento>::iterator it = elementos.begin();
			while( it != elementos.end() ){
				Elemento ele = *it;
				*(mtz+(ele.i*6)+ele.j) = this->id;
				it++;
			}
		}
		
		//Mover la cabeza de la cadena a una direccion
		void moverCabeza(char opc){
			Elemento ele = elementos.front();
			Elemento nvo;
			
			switch(opc){
				case '^':
					nvo.i = ele.i - 1;
					nvo.j = ele.j;
					break;
				case 'v':
					nvo.i = ele.i + 1;
					nvo.j = ele.j;
					break;
				case '<':
					nvo.i = ele.i;
					nvo.j = ele.j - 1;
					break;
				case '>':
					nvo.i = ele.i;
					nvo.j = ele.j + 1;
					break;
			}
			
			//~ cout<<"Elementos :"<<elementos.size()<<endl;
			//~ printf("Anterior i: %d, j: %d\n",ele.i,ele.j);
			//~ printf("Nuevo i: %d, j: %d\n\n",nvo.i,nvo.j);
			
			this->elementos.push_front(nvo);
			this->elementos.pop_back();
		}
		
		//Mover la cola de la cadena a una direccion
		void moverCola(char opc){
			Elemento ele = elementos.back();
			Elemento nvo;
			
			switch(opc){
				case '^':
					nvo.i = ele.i - 1;
					nvo.j = ele.j;
					break;
				case 'v':
					nvo.i = ele.i + 1;
					nvo.j = ele.j;
					break;
				case '<':
					nvo.i = ele.i;
					nvo.j = ele.j - 1;
					break;
				case '>':
					nvo.i = ele.i;
					nvo.j = ele.j + 1;
					break;
			}
			
			//~ cout<<"Elementos :"<<elementos.size()<<endl;
			//~ printf("Anterior i: %d, j: %d\n",ele.i,ele.j);
			//~ printf("Nuevo i: %d, j: %d\n\n",nvo.i,nvo.j);
			
			this->elementos.push_back(nvo);
			this->elementos.pop_front();
		}
		
		//Regresa la cabeza de la cadena
		Elemento getCadeza(){
			return elementos.front();
		}
		
		//Regresa la cola de la cadena
		Elemento getCola(){
			return elementos.back();
		}
};
