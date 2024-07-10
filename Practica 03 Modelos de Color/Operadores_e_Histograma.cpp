#include <iostream>
#include <stdlib.h>

//OpenCv
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

//Imprimir
void imprimir(Mat,Mat,Mat,Mat,Mat,Mat,Mat);

//Operadores puntuales
void operadoresPuntuales(Mat,Mat,Mat,Mat,Mat,Mat);

//Histograma
Mat histograma(Mat);

int main(){
	//Imagen Original
	Mat img = imread("imagen.jpeg",0);
	
	//Copias
	Mat ope1 = Mat(img.rows,img.cols,CV_8UC1,Scalar(255));
	Mat ope2 = Mat(img.rows,img.cols,CV_8UC1,Scalar(255));
	Mat ope3 = Mat(img.rows,img.cols,CV_8UC1,Scalar(255));
	Mat ope4 = Mat(img.rows,img.cols,CV_8UC1,Scalar(255));
	Mat ope5 = Mat(img.rows,img.cols,CV_8UC1,Scalar(255));
	
	//Operadores imagen-Binarisacio-Negativo-NegroBalncoGris-Negro-Blanco
	operadoresPuntuales(img,ope1,ope2,ope3,ope4,ope5);
	
	//Histograma 
	Mat hst = histograma(img);
	
	//Imprimir
	imprimir(img,ope1,ope2,ope3,ope4,ope5,hst);

	return 0;
}
//Operadores Puntuales
void operadoresPuntuales(Mat img,Mat bin,Mat nega,Mat negaBlanGris,Mat neg,Mat blan){
	for(int i=0;i<img.rows;i++){
		for(int j=0;j<img.cols;j++){
			//-----------------------------Binario----------------------
			if((img.at<uchar>(i,j))<128)
				bin.at<uchar>(i,j)=0;
			else
				bin.at<uchar>(i,j)=255;
			//----------------------------------------------------------
			
			//--------------------------Negativo------------------------
			nega.at<uchar>(i,j)=255-img.at<uchar>(i,j);	
			//----------------------------------------------------------
			
			//------------------------Negro-Blanco-Gris-----------------
			if((img.at<uchar>(i,j))<=85)
				negaBlanGris.at<uchar>(i,j)=0;
			else
				if((img.at<uchar>(i,j))>=170)
					negaBlanGris.at<uchar>(i,j)=255;
				else
					negaBlanGris.at<uchar>(i,j)=127;
			//----------------------------------------------------------
			
			//------------------------Negro-----------------------------
			if((img.at<uchar>(i,j))<=170)
				neg.at<uchar>(i,j)=0;
			else
				neg.at<uchar>(i,j)=255;
			//----------------------------------------------------------
			
			//-----------------------Blanco-----------------------------
			if((img.at<uchar>(i,j))<=85)
				blan.at<uchar>(i,j)=0;
			else
				blan.at<uchar>(i,j)=255;
			//----------------------------------------------------------
		}
	}
		
			
}
//Histograma
Mat histograma(Mat img){
	//Matriz que cuenta
	int hstNum[256];
	int i,j;
	for (i=0;i<256;i++)
		hstNum[i]=0;
	
	//Ralizar el histograma
	for(i=0;i<img.rows;i++)
		for(j=0;j<img.cols;j++)
			hstNum[img.at<uchar>(i,j)]++;
	
	//Obtenemos el mayor numero
	int may=0;
	for (i=0;i<256;i++){
		if(hstNum[i]>may)
			may=hstNum[i];
		printf("%d -> %d \n",i,hstNum[i]);
	}
	
	//Escala
	int esc=may/512+1;
	
	//Imagen del histograma
	Mat hst=Mat(512,768,CV_8UC1,Scalar(0));
	
	//Pintar la imagen
	int ind=0, cont=0;
	for(j=0;j<hst.cols;j++){
		int ini=hst.rows-(hstNum[ind]/esc);//Donde empieza la barra
		for(i=0;i<hst.rows;i++)
			if(i<ini)//Fondo
				hst.at<uchar>(i,j)=255-ind;
			else//Barra
				hst.at<uchar>(i,j)=ind;
		cont++;//Para pintar varias columnas de un mismo color y altura
		if(cont>3){//Solo pintar 3 Columnas de un de un mismo color y altura
			cont=1;
			ind++;//Recorre el histograma y al siguiente color
		}
	}
	return hst;
}

//Imprimir
void imprimir(Mat img1,Mat img2,Mat img3,Mat img4,Mat img5,Mat img6,Mat hst){
	namedWindow("Histograma",WINDOW_AUTOSIZE);
	imshow("Histograma",hst);
	
	namedWindow("Yoda",WINDOW_AUTOSIZE);
	imshow("Yoda",img1);
	
	namedWindow("Binario",WINDOW_AUTOSIZE);
	imshow("Binario",img2);
	
	namedWindow("Negativo",WINDOW_AUTOSIZE);
	imshow("Negativo",img3);
	
	namedWindow("Negro-Blanco-Gris",WINDOW_AUTOSIZE);
	imshow("Negro-Blanco-Gris",img4);
	
	namedWindow("Negro",WINDOW_AUTOSIZE);
	imshow("Negro",img5);
	
	namedWindow("Blanco",WINDOW_AUTOSIZE);
	imshow("Blanco",img6);
	
	waitKey(0);
}
