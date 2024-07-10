//C++
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//OpenCv
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


using namespace cv;

# define PI           3.14159265358979323846

Mat fondo();

//Sprites Mario
void marioParado(Mat,int,int);
void marioCaminando(Mat,int,int);
void marioSaltando(Mat,int,int);

void marioParadoGrande(Mat,int,int);
void marioCaminandoGrande(Mat,int,int);

//Sprites Goomba
void goomba1(Mat,int,int);
void goomba2(Mat,int,int);

//Sprite Koopa
void koopa1(Mat,int,int);
void koopa2(Mat,int,int);

//Sprite Planta Piraña
void planta1(Mat,int,int);
void planta2(Mat,int,int);

//Sprite homgo
void hongo(Mat,int,int);

//Animaciones
void caminarMario(Mat,int*,int*,int*);
void saltarMario(Mat,int*,int*,int*,float*,int*,int*);
void caminarGoomba(Mat,int*,int*);
void caminarKoopa(Mat,int*,int*);
void morderPlanta(Mat,int*);
void crecer(Mat,int,int);
void caminarMarioGrande(Mat,int*,int*);


int main(){
	Mat img = fondo();
	
	//Primera Pantalla
	int xM=0,yM=475;
	int xN=800;
	int rad = 0,xMed=0,yMed=0;
	float grd=PI;
	
	for (int i = 1; i <= 93; i++){
		Mat img = fondo();
		
		//Movimiento de Mario
		if(xM+18<=xN-100){
			caminarMario(img,&xM,&yM,&i);
			
			xMed=xN;
			yMed=yM;
			rad=xN-xM;
		}
		else{
			if(yM<=475)
				saltarMario(img,&xMed,&yMed,&rad,&grd,&xM,&yM);
			else
				caminarMario(img,&xM,&yM,&i);
		}
		
		//Movimiento de Goomba
		caminarGoomba(img,&xN,&i);
		
		//Animacion
		imshow("Animacion",img);
		if(waitKey(50)==0)
			break;
	}
	
	//Segunda pantalla
	img = fondo();
	xM=0;
	yM=475;
	xN=800;
	rad=0;
	xMed=0;
	yMed=0;
	grd=PI;
	
	for (int i = 1; i < 100; i++){
		img = fondo();
		
		//Movimiento de Mario
		if(xM+18<=xN-100){
			caminarMario(img,&xM,&yM,&i);
			
			xMed=xN;
			yMed=yM;
			rad=xN-xM;
		}
		else{
			if(yM<=475)
				saltarMario(img,&xMed,&yMed,&rad,&grd,&xM,&yM);
			else{
				if(xM+18>=600)
					saltarMario(img,&xMed,&yMed,&rad,&grd,&xM,&yM);
				else{
					rad=700-xM;
					xMed=700;
					yMed=475;
					grd=PI;
					caminarMario(img,&xM,&yM,&i);
				}
			}	
		}
			
		caminarKoopa(img,&xN,&i);
		morderPlanta(img,&i);
		
		//Animacion
		imshow("Animacion",img);
		if(waitKey(50)==0)
			break;
	}

	//Tercera pantalla
	img = fondo();
	xM=0;
	yM=475;
	int xH=800;
	bool arriba=true;
	
	for (int i = 1; i < 100; i++){
		img = fondo();
		
		if(xM>=xH){
			if(arriba){
				crecer(img,xM,yM);
				arriba=false;
			}
			caminarMarioGrande(img,&xM,&i);
		}else{
			caminarMario(img,&xM,&yM,&i);
			hongo(img,xH,460);
			xH-=10;
		}
		
		//Animacion
		imshow("Animacion",img);
		if(waitKey(50)==0)
			break;
	}
	
	//Fin
	putText(img, "GAME OVER", Point(150,img.rows/2), FONT_HERSHEY_DUPLEX, 3, CV_RGB(196,7,7), 2);
	namedWindow("Animacion",WINDOW_AUTOSIZE);
	imshow("Animacion",img);
	waitKey(0);
	return 0;
}
//Animacion Mario Caminando
void caminarMarioGrande(Mat img,int* x,int* ani){
	if(*ani%2==0)
		marioParadoGrande(img,*x/2,225);
	else
		marioCaminandoGrande(img,*x/2,225);
	*x+=10;
}

//Animacion Crecer
void crecer(Mat img,int x,int y){
	for (int i = 1; i <= 8; i++){
		img = fondo();
		
			if(i%2==0)
				marioCaminando(img,x,y);
			else
				marioCaminandoGrande(img,x/2,220);
		imshow("Animacion",img);
		if(waitKey(200)==0)
			break;
	}
}

//Animacion Mario Saltando
void saltarMario(Mat img,int* x,int* y,int* rad,float* grd,int* xM,int* yM){
	*xM = *x + (*rad*cos(*grd));
	*yM = *y - (200*sin(*grd));
	marioSaltando(img,*xM,*yM);
	*grd-=0.1;
}

//Animacion Mario Caminando
void caminarMario(Mat img,int* x,int* y,int* ani){
	if(*ani%2==0)
		marioParado(img,*x,*y);
	else
		marioCaminando(img,*x,*y);
	*x+=10;
}

//Animacion Goomba Caminando
void caminarGoomba(Mat img,int* x,int* ani){
	if(*ani%2==0)
		goomba1(img,*x,475);
	else
		goomba2(img,*x,475);
	*x-=5;
}

//Animacion Caminar Koopa
void caminarKoopa(Mat img,int* x,int* ani){
	if(*ani%2==0)
		koopa1(img,*x,475);
	else
		koopa2(img,*x,475);
	*x-=13;
}

//Animacion de morder planta piraña
void morderPlanta(Mat img,int* ani){
	if(*ani%2==0)
		planta1(img,700,475);
	else
		planta2(img,700,475);
}

//------------------------------------Sprites----------------------------------------------------------------------------------
//Sprite homgo
void hongo(Mat img,int x,int y){
	//Cabeza
	Point cabeza[6]={Point(x+30,y+20), Point(x+30,y), Point(x+15,y-10), Point(x-15,y-10), Point(x-30,y), Point(x-30,y+20)};  
	fillConvexPoly(img,cabeza,6,CV_RGB(202,9,9),8,0);
	
	//Circulo
	circle(img,Point(x,y+5),10,CV_RGB(255,255,255),-1,3);
	
	//Cara
	Point cara[4]={Point(x-20,y+20), Point(x+20,y+20), Point(x+15,y+40), Point(x-15,y+40)};  
	fillConvexPoly(img,cara,4,CV_RGB(232,206,146),8,0);
	
	//Ojos
	line(img,Point(x-5,y+25),Point(x-5,y+35),CV_RGB(0,0,0),4,8,0);
	line(img,Point(x+5,y+25),Point(x+5,y+35),CV_RGB(0,0,0),4,8,0);
	
}

//Sprite Planta Piraña
void planta1(Mat img,int x,int y){
	//Tallo
	Point tallo[4]={Point(x-5,y-50), Point(x+5,y-50), Point(x+5,y-10), Point(x-5,y-10)};  
	fillConvexPoly(img,tallo,4,CV_RGB(9,237,88),8,0);
	
	//Hojas
	Point hojaIzq[4]={Point(x-5,y-10), Point(x-10,y-25), Point(x-25,y-30), Point(x-20,y-15)};  
	fillConvexPoly(img,hojaIzq,4,CV_RGB(9,237,88),8,0);
	
	Point hojaDer[4]={Point(x+5,y-10), Point(x+10,y-25), Point(x+25,y-30), Point(x+20,y-15)};  
	fillConvexPoly(img,hojaDer,4,CV_RGB(9,237,88),8,0);
	
	//Cabeza
	circle(img,Point(x,y-75),25,CV_RGB(207,9,9),-1,3);
	
	//Tuberia
	Point tuberia1[4]={Point(x-30,y-10), Point(x+30,y-10), Point(x+30,y+10), Point(x-30,y+10)};  
	fillConvexPoly(img,tuberia1,4,CV_RGB(15,151,63),8,0);
	
	Point tuberia2[4]={Point(x-20,y+10), Point(x+20,y+10), Point(x+20,y+50), Point(x-20,y+50)};  
	fillConvexPoly(img,tuberia2,4,CV_RGB(15,151,63),8,0);
}
void planta2(Mat img,int x,int y){
	//Tallo
	Point tallo[4]={Point(x-5,y-50), Point(x+5,y-50), Point(x+5,y-10), Point(x-5,y-10)};  
	fillConvexPoly(img,tallo,4,CV_RGB(9,237,88),8,0);
	
	//Hojas
	Point hojaIzq[4]={Point(x-5,y-10), Point(x-10,y-25), Point(x-25,y-30), Point(x-20,y-15)};  
	fillConvexPoly(img,hojaIzq,4,CV_RGB(9,237,88),8,0);
	
	Point hojaDer[4]={Point(x+5,y-10), Point(x+10,y-25), Point(x+25,y-30), Point(x+20,y-15)};  
	fillConvexPoly(img,hojaDer,4,CV_RGB(9,237,88),8,0);
	
	//Cabeza
	circle(img,Point(x,y-75),25,CV_RGB(207,9,9),-1,3);
	
	//x=img.cols/2 + (rad*cos(grd));
	//y=img.rows/2 - (rad*sin(grd));
		
	//Boca
	Point boca[4]={Point(x,y-75), Point(x+(25*cos(PI/4)),y-75-(25*sin(PI/4))),Point(x,y-100),Point(x+(25*cos(3*PI/4)),y-75-(25*sin(3*PI/4)))};  
	fillConvexPoly(img,boca,4,CV_RGB(0,0,0),8,0);
	
	//Tuberia
	Point tuberia1[4]={Point(x-30,y-10), Point(x+30,y-10), Point(x+30,y+10), Point(x-30,y+10)};  
	fillConvexPoly(img,tuberia1,4,CV_RGB(15,151,63),8,0);
	
	Point tuberia2[4]={Point(x-20,y+10), Point(x+20,y+10), Point(x+20,y+50), Point(x-20,y+50)};  
	fillConvexPoly(img,tuberia2,4,CV_RGB(15,151,63),8,0);
}

//Sprites Koompa
void koopa1(Mat img,int x,int y){
	//Cuello
	Point cuello[4]={Point(x-20,y-10), Point(x-10,y-10), Point(x-10,y+20), Point(x-20,y+20)};  
	fillConvexPoly(img,cuello,4,CV_RGB(242,229,22),8,0);
	
	//Cabeza
	Point cabeza[4]={Point(x-30,y-40), Point(x-10,y-40), Point(x-10,y-10), Point(x-30,y-10)};  
	fillConvexPoly(img,cabeza,4,CV_RGB(242,229,22),8,0);
	
	//Ojo
	Point ojo[4]={Point(x-25,y-35), Point(x-23,y-35), Point(x-23,y-25), Point(x-25,y-25)};  
	fillConvexPoly(img,ojo,4,CV_RGB(0,0,0),8,0);

	//Boca
	Point boca[3]={Point(x-30,y-20), Point(x-20,y-20), Point(x-30,y-10)};  
	fillConvexPoly(img,boca,3,CV_RGB(0,0,0),8,0);
	 
	//Caparazon
	Point caparazon[8]={Point(x+10,y+20), Point(x+15,y+10), Point(x+15,y-10), Point(x+10,y-20), Point(x-10,y-20), Point(x-15,y-10), Point(x-15,y+10),Point(x-10,y+20)};  
	fillConvexPoly(img,caparazon,8,CV_RGB(34,151,15),8,0);
	
	//Pies
	Point pieIzq[4]={Point(x-25,y+20), Point(x-10,y+20), Point(x-10,y+30), Point(x-25,y+30)};  
	fillConvexPoly(img,pieIzq,4,CV_RGB(242,229,22),8,0);
	
	Point pieDer[4]={Point(x+10,y+20), Point(x+25,y+20), Point(x+25,y+30), Point(x+10,y+30)};  
	fillConvexPoly(img,pieDer,4,CV_RGB(242,229,22),8,0);
}
void koopa2(Mat img,int x,int y){
	//Cuello
	Point cuello[4]={Point(x-20,y-10), Point(x-10,y-10), Point(x-10,y+30), Point(x-20,y+30)};  
	fillConvexPoly(img,cuello,4,CV_RGB(242,229,22),8,0);
	
	//Cabeza
	Point cabeza[4]={Point(x-30,y-40), Point(x-10,y-40), Point(x-10,y-10), Point(x-30,y-10)};  
	fillConvexPoly(img,cabeza,4,CV_RGB(242,229,22),8,0);
	
	//Ojo
	Point ojo[4]={Point(x-25,y-35), Point(x-23,y-35), Point(x-23,y-25), Point(x-25,y-25)};  
	fillConvexPoly(img,ojo,4,CV_RGB(0,0,0),8,0);
	
	//Pies
	Point pieDer[4]={Point(x,y+20), Point(x+10,y+20), Point(x+10,y+30), Point(x,y+30)};  
	fillConvexPoly(img,pieDer,4,CV_RGB(242,229,22),8,0);
	
	//Caparazon
	Point caparazon[8]={Point(x+10,y+20), Point(x+15,y+10), Point(x+15,y-10), Point(x+10,y-20), Point(x-10,y-20), Point(x-15,y-10), Point(x-15,y+10),Point(x-10,y+20)};  
	fillConvexPoly(img,caparazon,8,CV_RGB(34,151,15),8,0);
}

//Sprites Goomba
void goomba1(Mat img,int x,int y){
	//Cabeza
	Point cabeza[5]={Point(x-20,y+15), Point(x+20,y+15), Point(x+15,y), Point(x,y-10), Point(x-15,y)};  
	fillConvexPoly(img,cabeza,5,CV_RGB(144,78,16),8,0);
	
	//Ojos
	Point ojoIzq[4]={Point(x-10,y-5), Point(x,y), Point(x,y+10), Point(x-10,y+10)};
	fillConvexPoly(img,ojoIzq,4,CV_RGB(255,255,255),8,0);
	
	Point ojoDer[4]={Point(x,y), Point(x+10,y-5), Point(x+10,y+10), Point(x,y+10)};
	fillConvexPoly(img,ojoDer,4,CV_RGB(255,255,255),8,0);
	
	line(img,Point(x-5,y-3),Point(x-5,y+10),CV_RGB(0,0,0),2,8,0);
	line(img,Point(x+5,y-3),Point(x+5,y+10),CV_RGB(0,0,0),2,8,0);
	
	//Cejas
	line(img,Point(x+10,y-5),Point(x,y),CV_RGB(0,0,0),4,8,0);
	line(img,Point(x,y),Point(x-10,y-5),CV_RGB(0,0,0),4,8,0);
	
	//Cuerpo
	Point cuerpo[5]={Point(x-10,y+15), Point(x+10,y+15), Point(x+10,y+20), Point(x,y+25), Point(x-5,y+28)};
	fillConvexPoly(img,cuerpo,5,CV_RGB(202,155,111),8,0);
	
	//Pies
	Point pieIzq[4]={Point(x,y+25), Point(x-15,y+10), Point(x-20,y+20), Point(x-5,y+30)};
	fillConvexPoly(img,pieIzq,4,CV_RGB(0,0,0),8,0);
	
	Point pieDer[4]={Point(x,y+25), Point(x+10,y+20), Point(x+15,y+25), Point(x+5,y+30)};
	fillConvexPoly(img,pieDer,4,CV_RGB(0,0,0),8,0);

}
void goomba2(Mat img,int x,int y){
	//Cabeza
	Point cabeza[5]={Point(x-20,y+15), Point(x+20,y+15), Point(x+15,y), Point(x,y-10), Point(x-15,y)};  
	fillConvexPoly(img,cabeza,5,CV_RGB(144,78,16),8,0);
	
	//Ojos
	Point ojoIzq[4]={Point(x-10,y-5), Point(x,y), Point(x,y+10), Point(x-10,y+10)};
	fillConvexPoly(img,ojoIzq,4,CV_RGB(255,255,255),8,0);
	
	Point ojoDer[4]={Point(x,y), Point(x+10,y-5), Point(x+10,y+10), Point(x,y+10)};
	fillConvexPoly(img,ojoDer,4,CV_RGB(255,255,255),8,0);
	
	line(img,Point(x-5,y-3),Point(x-5,y+10),CV_RGB(0,0,0),2,8,0);
	line(img,Point(x+5,y-3),Point(x+5,y+10),CV_RGB(0,0,0),2,8,0);
	
	//Cejas
	line(img,Point(x+10,y-5),Point(x,y),CV_RGB(0,0,0),4,8,0);
	line(img,Point(x,y),Point(x-10,y-5),CV_RGB(0,0,0),4,8,0);
	
	//Cuerpo
	Point cuerpo[5]={Point(x-10,y+15), Point(x+10,y+15), Point(x+10,y+20), Point(x,y+25), Point(x-5,y+28)};
	fillConvexPoly(img,cuerpo,5,CV_RGB(202,155,111),8,0);
	
	//Pies
	Point pieIzq[4]={Point(x,y+25), Point(x-10,y+20), Point(x-15,y+25), Point(x-5,y+30)};
	fillConvexPoly(img,pieIzq,4,CV_RGB(0,0,0),8,0);
	
	Point pieDer[4]={Point(x,y+25), Point(x+15,y+10), Point(x+20,y+20), Point(x+5,y+30)};
	fillConvexPoly(img,pieDer,4,CV_RGB(0,0,0),8,0);

}

//Sprites mario
void marioCaminando(Mat img,int x,int y){
	//Camisa
	Point verCamisa[4]={Point(x-10,y-10), Point(x+10,y-10), Point(x+10,y+10), Point(x-10,y+10)};
	fillConvexPoly(img,verCamisa,4,CV_RGB(10,80,242),8,0);
	
	Point verPlayera[3]={Point(x-10,y-10), Point(x+10,y-10), Point(x+10,y)};
	fillConvexPoly(img,verPlayera,3,CV_RGB(242,10,10),8,0);
	
	//Pantalon
	Point verPantIzq[4]={Point(x-10,y+10), Point(x,y+10), Point(x-4,y+20), Point(x-14,y+20)};
	fillConvexPoly(img,verPantIzq,4,CV_RGB(10,80,242),8,0);
	
	Point verPantDer[4]={Point(x,y+10), Point(x+10,y+10), Point(x+14,y+20), Point(x+4,y+20)};
	fillConvexPoly(img,verPantDer,4,CV_RGB(10,80,242),8,0);
	
	//Zapatos
	Point verZapIzq[4]={Point(x-14,y+20), Point(x,y+20), Point(x,y+25), Point(x-14,y+25)};
	fillConvexPoly(img,verZapIzq,4,CV_RGB(104,57,13),8,0);
	
	Point verZapDer[4]={Point(x+4,y+20), Point(x+18,y+20), Point(x+18,y+25), Point(x+4,y+25)};
	fillConvexPoly(img,verZapDer,4,CV_RGB(104,57,13),8,0);
	
	//Mangas
	Point verMangaIzq[4]={Point(x-15,y-10), Point(x,y-10), Point(x,y), Point(x-15,y)};
	fillConvexPoly(img,verMangaIzq,4,CV_RGB(242,10,10),8,0);
	
	Point verMangaDer[4]={Point(x+10,y-10), Point(x+15,y-10), Point(x+15,y), Point(x+10,y)};
	fillConvexPoly(img,verMangaDer,4,CV_RGB(242,10,10),8,0);
	
	//Mano
	Point verManoIzq[4]={Point(x-18,y-10), Point(x-15,y-10), Point(x-15,y), Point(x-18,y)};
	fillConvexPoly(img,verManoIzq,4,CV_RGB(238,185,135),8,0);
	
	Point verManoDer[4]={Point(x+10,y-10), Point(x+18,y-10), Point(x+18,y), Point(x+10,y)};
	fillConvexPoly(img,verManoDer,4,CV_RGB(238,185,135),8,0);
	
	//Cabeza
	circle(img,Point(x,y-25),15,CV_RGB(238,185,135),-1,3);
	
	//Ojo
	Point verOjo[4]={Point(x+3,y-35), Point(x+6,y-35), Point(x+6,y-25), Point(x+3,y-25)};
	fillConvexPoly(img,verOjo,4,CV_RGB(0,0,0),8,0);
	
	//Nariz
	Point verNariz[4]={Point(x+3,y-25), Point(x+18,y-25), Point(x+18,y-20), Point(x+3,y-20)};
	fillConvexPoly(img,verNariz,4,CV_RGB(238,185,135),8,0);
	
	//Bigote
	Point verBigote[4]={Point(x+3,y-20), Point(x+15,y-20), Point(x+15,y-15), Point(x+3,y-15)};
	fillConvexPoly(img,verBigote,4,CV_RGB(0,0,0),8,0);
	
	//Cabello
	Point verCabello[4]={Point(x-15,y-40), Point(x-10,y-40), Point(x-10,y-20), Point(x-15,y-20)};
	fillConvexPoly(img,verCabello,4,CV_RGB(0,0,0),8,0);
	
	//Sombrero
	Point verSombrero[4]={Point(x-15,y-40), Point(x+18,y-40), Point(x+18,y-35), Point(x-15,y-35)};
	fillConvexPoly(img,verSombrero,4,CV_RGB(242,10,10),8,0);
	
	Point verGorra[4]={Point(x-15,y-50), Point(x+10,y-50), Point(x+10,y-40), Point(x-15,y-40)};
	fillConvexPoly(img,verGorra,4,CV_RGB(242,10,10),8,0);
	
	circle(img,Point(x+3,y-45),3,CV_RGB(255,255,255),-1,3);
}
void marioParado(Mat img,int x,int y){
	//Camisa
	Point verCamisa[4]={Point(x-10,y-10), Point(x+10,y-10), Point(x+10,y+10), Point(x-10,y+10)};
	fillConvexPoly(img,verCamisa,4,CV_RGB(10,80,242),8,0);
	
	Point verPlayera[3]={Point(x-10,y-10), Point(x+10,y-10), Point(x+10,y)};
	fillConvexPoly(img,verPlayera,3,CV_RGB(242,10,10),8,0);
	
	//Pantalon
	Point verPantalon[4]={Point(x-7,y+10), Point(x+7,y+10), Point(x+7,y+20), Point(x-7,y+20)};
	fillConvexPoly(img,verPantalon,4,CV_RGB(10,80,242),8,0);
	
	//Zapatos
	Point verZapato[4]={Point(x-7,y+20), Point(x+10,y+20), Point(x+10,y+25), Point(x-7,y+25)};
	fillConvexPoly(img,verZapato,4,CV_RGB(104,57,13),8,0);
	
	//Manga
	Point verManga[4]={Point(x-10,y-10), Point(x,y-10), Point(x,y), Point(x-10,y)};
	fillConvexPoly(img,verManga,4,CV_RGB(242,10,10),8,0);
	
	//Mano
	Point verMano[4]={Point(x-10,y), Point(x+3,y), Point(x+3,y+7), Point(x-10,y+7)};
	fillConvexPoly(img,verMano,4,CV_RGB(238,185,135),8,0);
	
	//Cabeza
	circle(img,Point(x,y-25),15,CV_RGB(238,185,135),-1,3);
	
	//Ojo
	Point verOjo[4]={Point(x+3,y-35), Point(x+6,y-35), Point(x+6,y-25), Point(x+3,y-25)};
	fillConvexPoly(img,verOjo,4,CV_RGB(0,0,0),8,0);
	
	//Nariz
	Point verNariz[4]={Point(x+3,y-25), Point(x+18,y-25), Point(x+18,y-20), Point(x+3,y-20)};
	fillConvexPoly(img,verNariz,4,CV_RGB(238,185,135),8,0);
	
	//Bigote
	Point verBigote[4]={Point(x+3,y-20), Point(x+15,y-20), Point(x+15,y-15), Point(x+3,y-15)};
	fillConvexPoly(img,verBigote,4,CV_RGB(0,0,0),8,0);
	
	//Cabello
	Point verCabello[4]={Point(x-15,y-40), Point(x-10,y-40), Point(x-10,y-20), Point(x-15,y-20)};
	fillConvexPoly(img,verCabello,4,CV_RGB(0,0,0),8,0);
	
	//Sombrero
	Point verSombrero[4]={Point(x-15,y-40), Point(x+18,y-40), Point(x+18,y-35), Point(x-15,y-35)};
	fillConvexPoly(img,verSombrero,4,CV_RGB(242,10,10),8,0);
	
	Point verGorra[4]={Point(x-15,y-50), Point(x+10,y-50), Point(x+10,y-40), Point(x-15,y-40)};
	fillConvexPoly(img,verGorra,4,CV_RGB(242,10,10),8,0);
	
	circle(img,Point(x+3,y-45),3,CV_RGB(255,255,255),-1,3);
}
void marioSaltando(Mat img,int x,int y){
	//Camisa
	Point verCamisa[4]={Point(x-10,y-10), Point(x+10,y-10), Point(x+10,y+10), Point(x-10,y+10)};
	fillConvexPoly(img,verCamisa,4,CV_RGB(10,80,242),8,0);
	
	Point verPlayera[3]={Point(x-10,y-10), Point(x+10,y-10), Point(x+10,y)};
	fillConvexPoly(img,verPlayera,3,CV_RGB(242,10,10),8,0);
	
	//Pantalon
	Point verPantIzq[4]={Point(x-10,y+10), Point(x,y+10), Point(x-4,y+20), Point(x-14,y+20)};
	fillConvexPoly(img,verPantIzq,4,CV_RGB(10,80,242),8,0);
	
	Point verPantDer[4]={Point(x-5,y+10), Point(x+20,y+10), Point(x+20,y+20), Point(x-5,y+20)};
	fillConvexPoly(img,verPantDer,4,CV_RGB(10,80,242),8,0);
	
	//Zapatos
	Point verZapIzq[4]={Point(x-14,y+20), Point(x,y+20), Point(x,y+25), Point(x-14,y+25)};
	fillConvexPoly(img,verZapIzq,4,CV_RGB(104,57,13),8,0);
	
	Point verZapDer[4]={Point(x+20,y+20), Point(x+25,y+20), Point(x+25,y+5), Point(x+20,y+5)};
	fillConvexPoly(img,verZapDer,4,CV_RGB(104,57,13),8,0);
	
	//Mangas
	Point verMangaIzq[4]={Point(x-15,y-10), Point(x,y-10), Point(x,y), Point(x-15,y)};
	fillConvexPoly(img,verMangaIzq,4,CV_RGB(242,10,10),8,0);
	
	Point verMangaDer[4]={Point(x+10,y), Point(x+20,y), Point(x+20,y-20), Point(x+10,y-20)};
	fillConvexPoly(img,verMangaDer,4,CV_RGB(242,10,10),8,0);
	
	//Mano
	Point verManoIzq[4]={Point(x-18,y-10), Point(x-15,y-10), Point(x-15,y), Point(x-18,y)};
	fillConvexPoly(img,verManoIzq,4,CV_RGB(238,185,135),8,0);
	
	Point verManoDer[4]={Point(x+10,y-20), Point(x+10,y-25), Point(x+15,y-25), Point(x+15,y-20)};
	fillConvexPoly(img,verManoDer,4,CV_RGB(238,185,135),8,0);
	
	//Cabeza
	circle(img,Point(x,y-25),15,CV_RGB(238,185,135),-1,3);
	
	//Ojo
	Point verOjo[4]={Point(x+3,y-35), Point(x+6,y-35), Point(x+6,y-25), Point(x+3,y-25)};
	fillConvexPoly(img,verOjo,4,CV_RGB(0,0,0),8,0);
	
	//Nariz
	Point verNariz[4]={Point(x+3,y-25), Point(x+18,y-25), Point(x+18,y-20), Point(x+3,y-20)};
	fillConvexPoly(img,verNariz,4,CV_RGB(238,185,135),8,0);
	
	//Bigote
	Point verBigote[4]={Point(x+3,y-20), Point(x+15,y-20), Point(x+15,y-15), Point(x+3,y-15)};
	fillConvexPoly(img,verBigote,4,CV_RGB(0,0,0),8,0);
	
	//Cabello
	Point verCabello[4]={Point(x-15,y-40), Point(x-10,y-40), Point(x-10,y-20), Point(x-15,y-20)};
	fillConvexPoly(img,verCabello,4,CV_RGB(0,0,0),8,0);
	
	//Sombrero
	Point verSombrero[4]={Point(x-15,y-40), Point(x+18,y-40), Point(x+18,y-35), Point(x-15,y-35)};
	fillConvexPoly(img,verSombrero,4,CV_RGB(242,10,10),8,0);
	
	Point verGorra[4]={Point(x-15,y-50), Point(x+10,y-50), Point(x+10,y-40), Point(x-15,y-40)};
	fillConvexPoly(img,verGorra,4,CV_RGB(242,10,10),8,0);
	
	circle(img,Point(x+3,y-45),3,CV_RGB(255,255,255),-1,3);
}

//Sprite Mario Grande
void marioCaminandoGrande(Mat img,int x,int y){
	//Camisa
	Point verCamisa[4]={Point((x-10)*2,(y-10)*2), Point((x+10)*2,(y-10)*2), Point((x+10)*2,(y+10)*2), Point((x-10)*2,(y+10)*2)};
	fillConvexPoly(img,verCamisa,4,CV_RGB(10,80,242),8,0);
	
	Point verPlayera[3]={Point((x-10)*2,(y-10)*2), Point((x+10)*2,(y-10)*2), Point((x+10)*2,y*2)};
	fillConvexPoly(img,verPlayera,3,CV_RGB(242,10,10),8,0);
	
	//Pantalon
	Point verPantIzq[4]={Point((x-10)*2,(y+10)*2), Point(x*2,(y+10)*2), Point((x-4)*2,(y+20)*2), Point((x-14)*2,(y+20)*2)};
	fillConvexPoly(img,verPantIzq,4,CV_RGB(10,80,242),8,0);
	
	Point verPantDer[4]={Point(x*2,(y+10)*2), Point((x+10)*2,(y+10)*2), Point((x+14)*2,(y+20)*2), Point((x+4)*2,(y+20)*2)};
	fillConvexPoly(img,verPantDer,4,CV_RGB(10,80,242),8,0);
	
	//Zapatos
	Point verZapIzq[4]={Point((x-14)*2,(y+20)*2), Point(x*2,(y+20)*2), Point(x*2,(y+25)*2), Point((x-14)*2,(y+25)*2)};
	fillConvexPoly(img,verZapIzq,4,CV_RGB(104,57,13),8,0);
	
	Point verZapDer[4]={Point((x+4)*2,(y+20)*2), Point((x+18)*2,(y+20)*2), Point((x+18)*2,(y+25)*2), Point((x+4)*2,(y+25)*2)};
	fillConvexPoly(img,verZapDer,4,CV_RGB(104,57,13),8,0);
	
	//Mangas
	Point verMangaIzq[4]={Point((x-15)*2,(y-10)*2), Point(x*2,(y-10)*2), Point(x*2,y*2), Point((x-15)*2,y*2)};
	fillConvexPoly(img,verMangaIzq,4,CV_RGB(242,10,10),8,0);
	
	Point verMangaDer[4]={Point((x+10)*2,(y-10)*2), Point((x+15)*2,(y-10)*2), Point((x+15)*2,y*2), Point((x+10)*2,y*2)};
	fillConvexPoly(img,verMangaDer,4,CV_RGB(242,10,10),8,0);
	
	//Mano
	Point verManoIzq[4]={Point((x-18)*2,(y-10)*2), Point((x-15)*2,(y-10)*2), Point((x-15)*2,y*2), Point((x-18)*2,y*2)};
	fillConvexPoly(img,verManoIzq,4,CV_RGB(238,185,135),8,0);
	
	Point verManoDer[4]={Point((x+10)*2,(y-10)*2), Point((x+18)*2,(y-10)*2), Point((x+18)*2,y*2), Point((x+10)*2,y*2)};
	fillConvexPoly(img,verManoDer,4,CV_RGB(238,185,135),8,0);
	
	//Cabeza
	circle(img,Point(x*2,(y-25)*2),15*2,CV_RGB(238,185,135),-1,3);
	
	//Ojo
	Point verOjo[4]={Point((x+3)*2,(y-35)*2), Point((x+6)*2,(y-35)*2), Point((x+6)*2,(y-25)*2), Point((x+3)*2,(y-25)*2)};
	fillConvexPoly(img,verOjo,4,CV_RGB(0,0,0),8,0);
	
	//Nariz
	Point verNariz[4]={Point((x+3)*2,(y-25)*2), Point((x+18)*2,(y-25)*2), Point((x+18)*2,(y-20)*2), Point((x+3)*2,(y-20)*2)};
	fillConvexPoly(img,verNariz,4,CV_RGB(238,185,135),8,0);
	
	//Bigote
	Point verBigote[4]={Point((x+3)*2,(y-20)*2), Point((x+15)*2,(y-20)*2), Point((x+15)*2,(y-15)*2), Point((x+3)*2,(y-15)*2)};
	fillConvexPoly(img,verBigote,4,CV_RGB(0,0,0),8,0);
	
	//Cabello
	Point verCabello[4]={Point((x-15)*2,(y-40)*2), Point((x-10)*2,(y-40)*2), Point((x-10)*2,(y-20)*2), Point((x-15)*2,(y-20)*2)};
	fillConvexPoly(img,verCabello,4,CV_RGB(0,0,0),8,0);
	
	//Sombrero
	Point verSombrero[4]={Point((x-15)*2,(y-40)*2), Point((x+18)*2,(y-40)*2), Point((x+18)*2,(y-35)*2), Point((x-15)*2,(y-35)*2)};
	fillConvexPoly(img,verSombrero,4,CV_RGB(242,10,10),8,0);
	
	Point verGorra[4]={Point((x-15)*2,(y-50)*2), Point((x+10)*2,(y-50)*2), Point((x+10)*2,(y-40)*2), Point((x-15)*2,(y-40)*2)};
	fillConvexPoly(img,verGorra,4,CV_RGB(242,10,10),8,0);
	
	circle(img,Point((x+3)*2,(y-45)*2),3*2,CV_RGB(255,255,255),-1,3);
}
void marioParadoGrande(Mat img,int x,int y){
	//Camisa
	Point verCamisa[4]={Point((x-10)*2,(y-10)*2), Point((x+10)*2,(y-10)*2), Point((x+10)*2,(y+10)*2), Point((x-10)*2,(y+10)*2)};
	fillConvexPoly(img,verCamisa,4,CV_RGB(10,80,242),8,0);
	
	Point verPlayera[3]={Point((x-10)*2,(y-10)*2), Point((x+10)*2,(y-10)*2), Point((x+10)*2,y*2)};
	fillConvexPoly(img,verPlayera,3,CV_RGB(242,10,10),8,0);
	
	//Pantalon
	Point verPantalon[4]={Point((x-7)*2,(y+10)*2), Point((x+7)*2,(y+10)*2), Point((x+7)*2,(y+20)*2), Point((x-7)*2,(y+20)*2)};
	fillConvexPoly(img,verPantalon,4,CV_RGB(10,80,242),8,0);
	
	//Zapatos
	Point verZapato[4]={Point((x-7)*2,(y+20)*2), Point((x+10)*2,(y+20)*2), Point((x+10)*2,(y+25)*2), Point((x-7)*2,(y+25)*2)};
	fillConvexPoly(img,verZapato,4,CV_RGB(104,57,13),8,0);
	
	//Manga
	Point verManga[4]={Point((x-10)*2,(y-10)*2), Point(x*2,(y-10)*2), Point(x*2,y*2), Point((x-10)*2,y*2)};
	fillConvexPoly(img,verManga,4,CV_RGB(242,10,10),8,0);
	
	//Mano
	Point verMano[4]={Point((x-10)*2,y*2), Point((x+3)*2,y*2), Point((x+3)*2,(y+7)*2), Point((x-10)*2,(y+7)*2)};
	fillConvexPoly(img,verMano,4,CV_RGB(238,185,135),8,0);
	
	//Cabeza
	circle(img,Point(x*2,(y-25)*2),15*2,CV_RGB(238,185,135),-1,3);
	
	//Ojo
	Point verOjo[4]={Point((x+3)*2,(y-35)*2), Point((x+6)*2,(y-35)*2), Point((x+6)*2,(y-25)*2), Point((x+3)*2,(y-25)*2)};
	fillConvexPoly(img,verOjo,4,CV_RGB(0,0,0),8,0);
	
	//Nariz
	Point verNariz[4]={Point((x+3)*2,(y-25)*2), Point((x+18)*2,(y-25)*2), Point((x+18)*2,(y-20)*2), Point((x+3)*2,(y-20)*2)};
	fillConvexPoly(img,verNariz,4,CV_RGB(238,185,135),8,0);
	
	//Bigote
	Point verBigote[4]={Point((x+3)*2,(y-20)*2), Point((x+15)*2,(y-20)*2), Point((x+15)*2,(y-15)*2), Point((x+3)*2,(y-15)*2)};
	fillConvexPoly(img,verBigote,4,CV_RGB(0,0,0),8,0);
	
	//Cabello
	Point verCabello[4]={Point((x-15)*2,(y-40)*2), Point((x-10)*2,(y-40)*2), Point((x-10)*2,(y-20)*2), Point((x-15)*2,(y-20)*2)};
	fillConvexPoly(img,verCabello,4,CV_RGB(0,0,0),8,0);
	
	//Sombrero
	Point verSombrero[4]={Point((x-15)*2,(y-40)*2), Point((x+18)*2,(y-40)*2), Point((x+18)*2,(y-35)*2), Point((x-15)*2,(y-35)*2)};
	fillConvexPoly(img,verSombrero,4,CV_RGB(242,10,10),8,0);
	
	Point verGorra[4]={Point((x-15)*2,(y-50)*2), Point((x+10)*2,(y-50)*2), Point((x+10)*2,(y-40)*2), Point((x-15)*2,(y-40)*2)};
	fillConvexPoly(img,verGorra,4,CV_RGB(242,10,10),8,0);
	
	circle(img,Point((x+3)*2,(y-45)*2),3*2,CV_RGB(255,255,255),-1,3);
}

//Pinta el fondo
Mat fondo(){
	//Cielo
	Mat img = Mat(600,800,CV_8UC3,CV_RGB(21,163,191));
	
	//arbustro
	circle(img,Point(650,500),30,CV_RGB(5,181,40),-1,3);
	circle(img,Point(680,500),30,CV_RGB(5,181,40),-1,3);
	circle(img,Point(710,500),30,CV_RGB(5,181,40),-1,3);
	
	//Tierra
	Point ver1[4]={Point(0,500), Point(800,500), Point(800,600), Point(0,600)};
	fillConvexPoly(img,ver1,4,CV_RGB(181,109,5),8,0);
	
	//Montaña
	Point ver2[3]={Point(50,500), Point(275,300), Point(500,500)};
	fillConvexPoly(img,ver2,3,CV_RGB(6,162,70),8,0);
	
	//Nubes
	circle(img,Point(100,100),30,CV_RGB(255,255,255),-1,3);
	circle(img,Point(130,100),30,CV_RGB(255,255,255),-1,3);
	circle(img,Point(160,100),30,CV_RGB(255,255,255),-1,3);
	
	circle(img,Point(400,150),30,CV_RGB(255,255,255),-1,3);
	circle(img,Point(430,150),30,CV_RGB(255,255,255),-1,3);
	circle(img,Point(460,150),30,CV_RGB(255,255,255),-1,3);
	
	circle(img,Point(700,50),30,CV_RGB(255,255,255),-1,3);
	circle(img,Point(730,50),30,CV_RGB(255,255,255),-1,3);
	circle(img,Point(760,50),30,CV_RGB(255,255,255),-1,3);
	
	return img;
}
