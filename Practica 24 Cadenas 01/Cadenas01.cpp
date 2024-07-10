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

//Mi librerio de cadena
#include "Cadena.h"

using namespace cv;
using namespace std;

//Imagen
Mat img;
//Pila de todos los estados de la matriz
vector<int> matrizes[36];

//Crea los ojetos cadena
void ingresarCadenas(Cadena*);

//Crea la matriz segun las cadenas 
void crearMatriz(Cadena*);

//Muestra el Mat a base de la matriz
void mostrarImagen(int*,Cadena*);

//No estorba la cabeza o cola de la cadena con un elemento de otra o pared
bool libre(Elemento);

//Metodos recursivos mover
void pasosCabezaMorado(Cadena,Cadena,Cadena,Cadena,char);
void pasosCabezaNaranja(Cadena,Cadena,Cadena,Cadena,char);
void pasosCabezaVerde(Cadena,Cadena,Cadena,Cadena,char);
void pasosCabezaAzul(Cadena,Cadena,Cadena,Cadena,char);

void pasosColaMorado(Cadena,Cadena,Cadena,Cadena,char);
void pasosColaNaranja(Cadena,Cadena,Cadena,Cadena,char);
void pasosColaVerde(Cadena,Cadena,Cadena,Cadena,char);
void pasosColaAzul(Cadena,Cadena,Cadena,Cadena,char);

int main(){
	//Arreglo de las cadenas
	Cadena cadenas[4];
	ingresarCadenas(cadenas);
	crearMatriz(cadenas);
	
	pasosCabezaMorado(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '^');
	pasosCabezaMorado(cadenas[0], cadenas[1], cadenas[2], cadenas[3], 'v');
	pasosCabezaMorado(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '<');
	pasosCabezaMorado(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '>');
	
	cout<<"Fin"<<endl;
	
	waitKey(0);
	return 0;
}
//Metodos recursivos para la cabeza de la cadena
void pasosCabezaMorado(Cadena mora, Cadena nara, Cadena verd, Cadena azul, char opc){
	cout<<"Cabeza Morado "<<opc<<endl;
	
	mora.moverCabeza(opc);
	Elemento cbz = mora.getCadeza();
	
	if(libre(cbz)){
		Cadena cadenas[4];
		cadenas[0] = mora;
		cadenas[1] = nara;
		cadenas[2] = verd;
		cadenas[3] = azul;
		crearMatriz(cadenas);
	
		pasosCabezaMorado(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '^');
		pasosCabezaMorado(cadenas[0], cadenas[1], cadenas[2], cadenas[3], 'v');
		pasosCabezaMorado(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '<');
		pasosCabezaMorado(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '>');
		
		pasosCabezaAzul(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '^');
		pasosCabezaAzul(cadenas[0], cadenas[1], cadenas[2], cadenas[3], 'v');
		pasosCabezaAzul(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '<');
		pasosCabezaAzul(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '>');
	}
}

void pasosCabezaAzul(Cadena mora, Cadena nara, Cadena verd, Cadena azul, char opc){
	cout<<"Cabeza Azul "<<opc<<endl;
	
	azul.moverCabeza(opc);
	Elemento cbz = azul.getCadeza();
	
	if(libre(cbz)){
		Cadena cadenas[4];
		cadenas[0] = mora;
		cadenas[1] = nara;
		cadenas[2] = verd;
		cadenas[3] = azul;
		crearMatriz(cadenas);
	
		pasosCabezaAzul(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '^');
		pasosCabezaAzul(cadenas[0], cadenas[1], cadenas[2], cadenas[3], 'v');
		pasosCabezaAzul(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '<');
		pasosCabezaAzul(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '>');
		
		pasosCabezaVerde(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '^');
		pasosCabezaVerde(cadenas[0], cadenas[1], cadenas[2], cadenas[3], 'v');
		pasosCabezaVerde(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '<');
		pasosCabezaVerde(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '>');
	}
}

void pasosCabezaVerde(Cadena mora, Cadena nara, Cadena verd, Cadena azul, char opc){
	cout<<"Cabeza Verde "<<opc<<endl;
	
	verd.moverCabeza(opc);
	Elemento cbz = verd.getCadeza();
	
	if(libre(cbz)){
		Cadena cadenas[4];
		cadenas[0] = mora;
		cadenas[1] = nara;
		cadenas[2] = verd;
		cadenas[3] = azul;
		crearMatriz(cadenas);
	
		pasosCabezaVerde(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '^');
		pasosCabezaVerde(cadenas[0], cadenas[1], cadenas[2], cadenas[3], 'v');
		pasosCabezaVerde(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '<');
		pasosCabezaVerde(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '>');
		
		pasosCabezaNaranja(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '^');
		pasosCabezaNaranja(cadenas[0], cadenas[1], cadenas[2], cadenas[3], 'v');
		pasosCabezaNaranja(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '<');
		pasosCabezaNaranja(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '>');
	}
}

void pasosCabezaNaranja(Cadena mora, Cadena nara, Cadena verd, Cadena azul, char opc){
	cout<<"Cabeza Naranja "<<opc<<endl;
	
	nara.moverCabeza(opc);
	Elemento cbz = nara.getCadeza();
	
	if(libre(cbz)){
		Cadena cadenas[4];
		cadenas[0] = mora;
		cadenas[1] = nara;
		cadenas[2] = verd;
		cadenas[3] = azul;
		crearMatriz(cadenas);
	
		pasosCabezaNaranja(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '^');
		pasosCabezaNaranja(cadenas[0], cadenas[1], cadenas[2], cadenas[3], 'v');
		pasosCabezaNaranja(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '<');
		pasosCabezaNaranja(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '>');
		
		pasosColaNaranja(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '^');
		pasosColaNaranja(cadenas[0], cadenas[1], cadenas[2], cadenas[3], 'v');
		pasosColaNaranja(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '<');
		pasosColaNaranja(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '>');
	}
}

void pasosColaMorado(Cadena mora, Cadena nara, Cadena verd, Cadena azul, char opc){
	cout<<"Cola Morado "<<opc<<endl;
	
	mora.moverCola(opc);
	Elemento cla = mora.getCola();
	
	if(libre(cla)){
		Cadena cadenas[4];
		cadenas[0] = mora;
		cadenas[1] = nara;
		cadenas[2] = verd;
		cadenas[3] = azul;
		crearMatriz(cadenas);
		
		pasosColaMorado(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '^');
		pasosColaMorado(cadenas[0], cadenas[1], cadenas[2], cadenas[3], 'v');
		pasosColaMorado(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '<');
		pasosColaMorado(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '>');
	
	}
}

void pasosColaAzul(Cadena mora, Cadena nara, Cadena verd, Cadena azul, char opc){
	cout<<"Cola Azul "<<opc<<endl;
	
	azul.moverCola(opc);
	Elemento cla = azul.getCola();
	
	if(libre(cla)){
		Cadena cadenas[4];
		cadenas[0] = mora;
		cadenas[1] = nara;
		cadenas[2] = verd;
		cadenas[3] = azul;
		crearMatriz(cadenas);
		
		pasosColaAzul(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '^');
		pasosColaAzul(cadenas[0], cadenas[1], cadenas[2], cadenas[3], 'v');
		pasosColaAzul(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '<');
		pasosColaAzul(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '>');
		
		pasosColaVerde(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '^');
		pasosColaVerde(cadenas[0], cadenas[1], cadenas[2], cadenas[3], 'v');
		pasosColaVerde(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '<');
		pasosColaVerde(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '>');
	}
}

void pasosColaVerde(Cadena mora, Cadena nara, Cadena verd, Cadena azul, char opc){
	cout<<"Cola Verde "<<opc<<endl;
	
	verd.moverCola(opc);
	Elemento cla = verd.getCola();
	
	if(libre(cla)){
		Cadena cadenas[4];
		cadenas[0] = mora;
		cadenas[1] = nara;
		cadenas[2] = verd;
		cadenas[3] = azul;
		crearMatriz(cadenas);
	
		pasosColaVerde(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '^');
		pasosColaVerde(cadenas[0], cadenas[1], cadenas[2], cadenas[3], 'v');
		pasosColaVerde(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '<');
		pasosColaVerde(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '>');
		
		pasosColaMorado(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '^');
		pasosColaMorado(cadenas[0], cadenas[1], cadenas[2], cadenas[3], 'v');
		pasosColaMorado(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '<');
		pasosColaMorado(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '>');
	}
}

void pasosColaNaranja(Cadena mora, Cadena nara, Cadena verd, Cadena azul, char opc){
	cout<<"Cola Naranja "<<opc<<endl;
	
	nara.moverCola(opc);
	Elemento cla = nara.getCola();
	
	if(libre(cla)){
		Cadena cadenas[4];
		cadenas[0] = mora;
		cadenas[1] = nara;
		cadenas[2] = verd;
		cadenas[3] = azul;
		crearMatriz(cadenas);
		
		pasosColaNaranja(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '^');
		pasosColaNaranja(cadenas[0], cadenas[1], cadenas[2], cadenas[3], 'v');
		pasosColaNaranja(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '<');
		pasosColaNaranja(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '>');
		
		pasosColaAzul(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '^');
		pasosColaAzul(cadenas[0], cadenas[1], cadenas[2], cadenas[3], 'v');
		pasosColaAzul(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '<');
		pasosColaAzul(cadenas[0], cadenas[1], cadenas[2], cadenas[3], '>');
	}
}

//Crear los objetos cadenas del arreglo
void ingresarCadenas(Cadena* cadenas){
	Elemento ele;
		
	//Cadena Morada
	cadenas[0] = Cadena(1,CV_RGB(149,10,189));
	ele.i = 0;
	ele.j = 4;
	cadenas[0].ingresarElemento(ele);
	ele.i = 1;
	ele.j = 4;
	cadenas[0].ingresarElemento(ele);
	ele.i = 2;
	ele.j = 4;
	cadenas[0].ingresarElemento(ele);
	ele.i = 3;
	ele.j = 4;
	cadenas[0].ingresarElemento(ele);
	ele.i = 4;
	ele.j = 4;
	cadenas[0].ingresarElemento(ele);
	
	//Cadena Naranja
	cadenas[1] = Cadena(2, CV_RGB(241,150,8));
	ele.i = 4;
	ele.j = 0;
	cadenas[1].ingresarElemento(ele);
	ele.i = 5;
	ele.j = 0;
	cadenas[1].ingresarElemento(ele);
	
	
	//Cadena Verde
	cadenas[2] = Cadena(3, CV_RGB(22,197,5));
	ele.i = 4;
	ele.j = 3;
	cadenas[2].ingresarElemento(ele);
	ele.i = 4;
	ele.j = 2;
	cadenas[2].ingresarElemento(ele);
	ele.i = 4;
	ele.j = 1;
	cadenas[2].ingresarElemento(ele);
	
	//Cadena Azul
	cadenas[3] = Cadena(4, CV_RGB(8,84,207));
	ele.i = 2;
	ele.j = 3;
	cadenas[3].ingresarElemento(ele);
	ele.i = 2;
	ele.j = 2;
	cadenas[3].ingresarElemento(ele);
	ele.i = 2;
	ele.j = 1;
	cadenas[3].ingresarElemento(ele);
	ele.i = 2;
	ele.j = 0;
	cadenas[3].ingresarElemento(ele);
}

//Pone las cadenas en la matriz y crea una limpia
void crearMatriz(Cadena* cadenas){
	//Matriz tablero
	int mtz[6][6] = {{ 0,  0,  0,  0,  0,  0},
					 {-1, -1, -1, -1,  0, -1},
					 { 0,  0,  0,  0,  0, -1},
					 {-1, -1,  0, -1,  0, -1},
					 { 0,  0,  0,  0,  0,  0},
					 { 0, -1, -1, -1, -1,  0}};
	
	//Poner los valores de las cadenas a la matriz	 
	for (int i = 0; i < 4; i++)
		cadenas[i].ponerMatriz(*mtz);
	
	//Ingresar la matriz a la pila
	int cont = 0;
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 6; j++){
			matrizes[cont].push_back(mtz[i][j]);
			cont++;
		}
	}
	
	//Muestra la matriz
	mostrarImagen(*mtz,cadenas);
}

//Muestra el Mat a base de la matriz
void mostrarImagen(int* mtz,Cadena* cadenas){
	img = Mat(620,620,CV_8UC3,CV_RGB(158,96,11));
	
	//Pinta tablero
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 6; j++){
			if(*(mtz+(i*6)+j) >= 0){
				//Pinta recuadros
				Point ver[4] = {Point(10+(100*j),10+(100*i)), Point(110+(100*j),10+(100*i)), Point(110+(100*j),110+(100*i)), Point(10+(100*j),110+(100*i))};
				fillConvexPoly(img,ver,4,CV_RGB(255,255,255),8,0);
				rectangle(img, ver[0], ver[2],CV_RGB(0,0,0), 2, 8, 0);
				
				//Pinta esferas
				switch(*(mtz+(i*6)+j)){
					case 1:
						circle(img, Point(10+(100*j)+50,10+(100*i)+50), 50, cadenas[0].color, -1, 3);
						break;
					case 2:
						circle(img, Point(10+(100*j)+50,10+(100*i)+50), 50, cadenas[1].color, -1, 3);
						break;
					case 3:
						circle(img, Point(10+(100*j)+50,10+(100*i)+50), 50, cadenas[2].color, -1, 3);
						break;
					case 4:
						circle(img, Point(10+(100*j)+50,10+(100*i)+50), 50, cadenas[3].color, -1, 3);
						break;
				}
			}
		}
	}
	
	imshow("Cadenas 01",img);
	waitKey(100);
	cout<<"-----------------------------------------------------------"<<endl;
}

//Saber si el espacio donde se esta esta libre
bool libre(Elemento ele){
	if(ele.i>=0 && ele.i < 6 && ele.j>=0 && ele.j<6)//Si esta dentro de la matriz
		if(matrizes[(ele.i*6)+ele.j].back() == 0)//Y el espacio esta libre
			return true;
			
	return false;
}
