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

Mat sol();
void orbita(Mat,int,int,float);
void planeta(Mat,int,int,int,float,Scalar);


//Astros con añanidos
void cometa(Mat,int);
void saturno(Mat,int,int,float);
void tierra(Mat,int,int,float);
void cinturonAsteroides(Mat,int,int,float);

int main(){
	Mat img = sol();
	float grad=0 ,grad1=0, grad2=0 ,grad3=0 ,grad4=0 ,grad5=0 ,grad6=0 ,grad7=0 ,grad8=0 ,grad9=0;
	int com=0;
	
	while(true){
		//Pintar orbitas
		img=sol();
		while(grad<2*PI){
			orbita(img,110,110,grad);//Mercurio
			orbita(img,130,120,grad);//Venus
			orbita(img,160,140,grad);//Tierra
			orbita(img,190,160,grad);//Marte
			
			cinturonAsteroides(img,220,180,grad);
			
			orbita(img,250,200,grad);//Jupiter
			orbita(img,300,230,grad);//Saturno
			orbita(img,350,250,grad);//Urano
			orbita(img,375,275,grad);//Neptuno
			
			orbita(img,400,400,grad);//Planetoide
			
			grad+=0.01;
		}
		grad=0;

		planeta(img,3,110,110,grad1,CV_RGB(169,165,160));//Mercurio
		planeta(img,6,130,120,grad2+(2*PI/9),CV_RGB(240,126,5));//Venus
		tierra(img,160,140,grad3-(4*PI/9));//Tierra
		planeta(img,5,190,160,grad4+(2*PI/3),CV_RGB(240,5,5));//Marte
		
		planeta(img,20,250,200,grad5+(8*PI/9),CV_RGB(246,161,70));//Jupiter
		saturno(img,300,230,grad6+(10*PI/9));//Saturno
		planeta(img,10,350,250,grad7-(4*PI/3),CV_RGB(9,246,232));//Urano
		planeta(img,10,375,275,grad8+(14*PI/9),CV_RGB(19,91,245));//Neptuno
		
		planeta(img,3,400,400,grad9+(PI/8),CV_RGB(191,194,201));//Planetoide
		cometa(img,com);//Cometa
		
		//Velocidad de los Planetas
		grad1+=0.1;
		grad2+=0.05;
		grad3+=0.025;
		grad4+=0.0125;
		grad5+=0.003125;
		grad6+=0.0015625;
		grad7+=0.00078125;
		grad8+=0.000590625;
		grad9+=0.0003;
		com++;
		
		//Animacion
		imshow("Sistema Solar",img);
		if(waitKey(50)==0)
			break;
	}
	
	return 0;
}
//Tierra con luna
void tierra(Mat img,int rX,int rY,float grd){
	float x = img.cols/2 + (rX*cos(grd));
	float y = img.rows/2 - (rY*sin(grd));
	circle(img,Point(x,y),7,CV_RGB(5,136,240),-1,3);//Tierra
	
	circle(img,Point( x + (15*cos(8*grd)) , y - (15*sin(8*grd)) ),2,CV_RGB(255,255,255),-1,3);//Luna
}

//Cinturon de Asteroides
void cinturonAsteroides(Mat img,int rX,int rY,float grd){
	
	circle(img,Point( img.cols/2 + ((rX-5)*cos(grd)) , img.rows/2 - ((rY-5)*sin(grd)) ),rand()%3,CV_RGB(142,143,145),-1,3);
	circle(img,Point( img.cols/2 + (rX*cos(grd)) , img.rows/2 - (rY*sin(grd)) ),rand()%3,CV_RGB(142,143,145),-1,3);
	circle(img,Point( img.cols/2 + ((rX+5)*cos(grd)) , img.rows/2 - ((rY+5)*sin(grd)) ),rand()%3,CV_RGB(142,143,145),-1,3);	
}

//Saturno con anillo
void saturno(Mat img,int rX,int rY,float grd){
	float x = img.cols/2 + (rX*cos(grd));
	float y = img.rows/2 - (rY*sin(grd));
	circle(img,Point(x,y),15,CV_RGB(229,191,134),-1,3);//Saturno
	
	//Anillos
	for (float i=0; i < 2*PI; i+=0.01){
		circle(img,Point( x + (30*cos(i)) , y - (12*sin(i)) ),0.5,CV_RGB(10,209,10),-1,3);
		circle(img,Point( x + (33*cos(i)) , y - (15*sin(i)) ),0.5,CV_RGB(209,10,203),-1,3);
		circle(img,Point( x + (36*cos(i)) , y - (18*sin(i)) ),0.5,CV_RGB(17,234,162),-1,3);
	}
		
}

//Cometa
void cometa(Mat img,int cor){
	Point ver[3]={Point(cor+3,cor+10-3),Point(cor-3,cor+10+3),Point(cor-6,cor+10-6)};
	fillConvexPoly(img,ver,3,CV_RGB(1,102,143),8,0);
	circle(img,Point(cor,cor+10),3,CV_RGB(1,102,143),-1,3);
}

//Pinta el platena
void planeta(Mat img,int tam,int rX,int rY,float grd,Scalar clr){
	circle(img,Point( img.cols/2 + (rX*cos(grd)) , img.rows/2 - (rY*sin(grd)) ),tam,clr,-1,3);	
}

//Pinta la Orbita
void orbita(Mat img,int rX,int rY,float grd){
	circle(img,Point( img.cols/2 + (rX*cos(grd)) , img.rows/2 - (rY*sin(grd)) ),0.1,CV_RGB(255,255,255),-1,3);	
}

//Fondo limpio y sol
Mat sol(){
	Mat img = imread("fondo.jpg",1);
	circle(img,Point(img.cols/2,img.rows/2),100,CV_RGB(197,172,15),-1,3);
	return img;
}
