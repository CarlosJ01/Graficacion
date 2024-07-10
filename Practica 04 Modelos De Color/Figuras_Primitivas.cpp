#include <iostream>
#include <stdlib.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <opencv2/imgproc/imgproc.hpp>//Libreria para primitivas de dibujo
#include <math.h>//Libreria para fuciones matematicas

using namespace cv;

//***********************************************************
//*** Documentacion de los metodos en PDF en esta carpeta ***
//***********************************************************

int main(){
	Mat img = Mat(450,450,CV_8UC3,Scalar(0,0,0));
	
	int cont=1;
	
	for(int i=0;i<400;i++){
		img = Mat(425,425,CV_8UC3,Scalar(13,9,132));
		
		//Ciculos
		circle(img,Point(i,i),30,Scalar(200,0,0),-1,3);
		
		circle(img,Point(225,225),25,Scalar(0,20,100),-1,3);
		
		//Lineas
		switch (cont) {
			case 1:
				line(img,Point(225,225),Point(225,200),Scalar(20,180,220),1,8,0);
				break;
			case 2:
				line(img,Point(225,225),Point(245,225),Scalar(20,180,220),1,8,0);
				break;
			case 3:
				line(img,Point(225,225),Point(225,245),Scalar(20,180,220),1,8,0);
				break;
			case 4:
				line(img,Point(225,225),Point(200,225),Scalar(20,180,220),1,8,0);
				cont=0;
				break;
        }
		cont++;
		
		if(i<200){
			//Rectangulo
			rectangle(img,Point(10,10),Point(10+2*i,10+i),CV_RGB(229,20,187));
			//Texto
			putText(img, "Hola", Point(100,0+i), FONT_HERSHEY_SCRIPT_COMPLEX, 3, CV_RGB(39,229,20), 2);
		}else{
			//Rectangulo
			rectangle(img,Point(10,10),Point(10+i,10+2*i),CV_RGB(229,20,187));
			//Texto
			putText(img, "Hola", Point(0+i,100), FONT_HERSHEY_SCRIPT_COMPLEX, 3, CV_RGB(39,229,20), 2);
		}


		//Flecha
		arrowedLine(img,Point(0,0),Point(img.cols/2,img.rows/2),CV_RGB(255,255,255));

		//elipse
		ellipse(img,Point(i,i),Size(100,150),45,0,360,CV_RGB(0,0,0),1,8,0);
		
		//Polinomio
		Point ver[3]={Point(100,100),Point(50,200),Point(150,200)};
		fillConvexPoly(img,ver,3,CV_RGB(128,128,128),8,0);

		namedWindow("Plano",WINDOW_AUTOSIZE);
		imshow("Plano",img);
	
		if(waitKey(50)==0)
			break;
	}
	imshow("Plano",img);
	waitKey(0);
	
	return 0;
}
