#include "opencv2/video/tracking.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include <stdio.h>
#include <iostream>
#include <ctype.h>
#include <math.h>
#include <string.h>

//g++ -Wall %f -o %e `pkg-config --cflags --libs opencv`
using namespace cv;
using namespace std;

Point2f point;
bool addRemovePt = false;

std::string numCom="";
char ope = ' ';

void tablero(Mat);
float distancia(Point,Point);
std::string borrar(std::string);
std::string opciones(std::string,int);
std::string operaciones(std::string);

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

    namedWindow( "LK Camara", 1 );
    
    Mat gray, prevGray, image, frame;
    vector<Point2f> points[2];
    vector<Point2f> operaciones[2];
    int j=0, i=0;
    
    //Numero que se crea
    std::string num="";

    if( points[0].empty() ){
		//Pocision de los numeros
		for(i=0; i<4; i++)
			for(j=0; j<3; j++)
				points[0].push_back(Point2f(435+(j*70),135+(i*70)));
		
		//points[0].push_back(Point2f(470,345));
		//points[0].push_back(Point2f(575,345));
		
		//Posicion de las operaciones e Igual
		for(i=0; i<5; i++)
				points[0].push_back(Point2f(85,56+(i*73)));
		
		//Pocision del igual
		//points[0].push_back(Point2f(85,385));

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
		
			calcOpticalFlowPyrLK(prevGray, gray, points[0], points[1], status, err, winSize, 1, termcrit, 0, 0.001);
	  
			tablero(image);
			
			size_t i, k;
			float dis;
	  
			for( i = k = 0; i < points[0].size() ; i++ ) {
				points[1][k++] = points[1][i];
				
				circle( image, points[1][i], 1, Scalar(255,255,255), -1, 8);
				//circle( image, points[0][i], 10, Scalar(255,255,255), 2, 1);
				
				dis=distancia(points[0][i],points[1][i]);//Calcula la distancia
				//printf("%f\n",dis);
				if(dis>=10)//Rango de operaciones
					num=opciones(num,i);
					
				//Imprime el numero
				putText(image,num,Point(0,image.rows-5), FONT_HERSHEY_DUPLEX, 1, CV_RGB(255,255,255), 1.5);
				cout<<numCom<<" "<<ope<<" "<<num<<endl;
			}
			
			points[1].resize(k);
		}
		
		imshow("LK Camara", image);
		char c = (char)waitKey(10);
		
		if( c == 27 )
			break;
        
		//std::swap(points[1], points[0]);
		swap(prevGray, gray);
	}

    return 0;
}

//Calcula la distancia entre dos puntos
float distancia(Point pnt1,Point pnt2){
	//return sqrt(pow((pnt1.x - pnt2.x),2) + pow((pnt1.y - pnt2.y),2));
	return abs(pnt1.y - pnt2.y);;	
}

//Opciones que se tienen
std::string opciones(std::string num,int ind){
	
	switch(ind){
		case 0:
			num+='1';
			break;
			
		case 1:
			num+='2';
			break;
			
		case 2:
			num+='3';
			break;
			
		case 3:
			num+='4';
			break;
			
		case 4:
			num+='5';
			break;
			
		case 5:
			num+='6';
			break;
			
		case 6:
			num+='7';
			break;
			
		case 7:
			num+='8';
			break;
			
		case 8:
			num+='9';
			break;
		
		case 9:
			num="";
			break;
			
		case 10:
			num+='0';
			break;
			
		case 11:
			num=borrar(num);
			break;
			
		case 12:
			if(ope !='+'){
				numCom=num;
				ope='+';
				num="";
			}
			break;
		
		case 13:
			if(ope !='-'){
				numCom=num;
				ope='-';
				num="";
			}
			break;
	
		case 14:
			if(ope !='*'){
				numCom=num;
				ope='*';
				num="";
			}
			break;
			
		case 15:
			if(ope !='/'){
				numCom=num;
				ope='/';
				num="";
			}
			break;
		
		case 16:
			if(ope !='=')
				num=operaciones(num);
			break;
	}
	
	return num;
}

//Realiza las operaciones
std::string operaciones(std::string num){
	
	std::string res;
	float rsl=0;
	float num1 = std::atof(numCom.c_str()); 
	float num2 = std::atof(num.c_str());
	
	switch(ope){
		case '+':
			rsl=num1+num2;
			break;
			
		case '-':
			rsl=num1-num2;
			break;
			
		case '*':
			rsl=num1*num2;
			break;
			
		case '/':
			if(num2!=0)
				rsl=num1/num2;
			else
				res="Error";
			break;
	}
	
	res=std::to_string(rsl);
	num="";
	numCom="";
	ope='=';
	
	cout<<"RESULTADO: "<<res<<endl;
	return res;
}

//Pinta el tablero "Interfas"
void tablero(Mat img){
	//Tablero
	//x->640
	//y->480
	//Numeros
	rectangle(img,Point(400,100),Point(610,380),CV_RGB(175,9,9),2,8,0);
	line(img,Point(400,170),Point(610,170),CV_RGB(175,9,9),2,8,0);
	line(img,Point(400,240),Point(610,240),CV_RGB(175,9,9),2,8,0);
	line(img,Point(400,310),Point(610,310),CV_RGB(175,9,9),2,8,0);
	
	line(img,Point(470,100),Point(470,380),CV_RGB(175,9,9),2,8,0);
	line(img,Point(540,100),Point(540,380),CV_RGB(175,9,9),2,8,0);
	
	putText(img,"1",Point(415,160),FONT_HERSHEY_DUPLEX, 2, CV_RGB(234,173,11), 5);
	putText(img,"2",Point(485,160),FONT_HERSHEY_DUPLEX, 2, CV_RGB(234,173,11), 5);
	putText(img,"3",Point(555,160),FONT_HERSHEY_DUPLEX, 2, CV_RGB(234,173,11), 5);
	
	putText(img,"4",Point(415,230),FONT_HERSHEY_DUPLEX, 2, CV_RGB(234,173,11), 5);
	putText(img,"5",Point(485,230),FONT_HERSHEY_DUPLEX, 2, CV_RGB(234,173,11), 5);
	putText(img,"6",Point(555,230),FONT_HERSHEY_DUPLEX, 2, CV_RGB(234,173,11), 5);
	
	putText(img,"7",Point(415,300),FONT_HERSHEY_DUPLEX, 2, CV_RGB(234,173,11), 5);
	putText(img,"8",Point(485,300),FONT_HERSHEY_DUPLEX, 2, CV_RGB(234,173,11), 5);
	putText(img,"9",Point(555,300),FONT_HERSHEY_DUPLEX, 2, CV_RGB(234,173,11), 5);
	
	putText(img,"AC",Point(405,360),FONT_HERSHEY_DUPLEX, 1.5, CV_RGB(234,173,11), 3);
	putText(img,"0",Point(485,370),FONT_HERSHEY_DUPLEX, 2, CV_RGB(234,173,11), 5);
	putText(img,"<=",Point(550,355),FONT_HERSHEY_DUPLEX, 1, CV_RGB(234,173,11), 3);
	
	//Operaciones e Igual
	rectangle(img,Point(50,30),Point(120,380),CV_RGB(175,9,9),2,8,0);
	line(img,Point(50,100),Point(120,100),CV_RGB(175,9,9),2,8,0);
	line(img,Point(50,170),Point(120,170),CV_RGB(175,9,9),2,8,0);
	line(img,Point(50,240),Point(120,240),CV_RGB(175,9,9),2,8,0);
	line(img,Point(50,310),Point(120,310),CV_RGB(175,9,9),2,8,0);
	
	putText(img,"+",Point(60,85),FONT_HERSHEY_DUPLEX, 2, CV_RGB(234,173,11), 5);
	putText(img,"-",Point(60,150),FONT_HERSHEY_DUPLEX, 2, CV_RGB(234,173,11), 5);
	putText(img,"*",Point(70,235),FONT_HERSHEY_DUPLEX, 2, CV_RGB(234,173,11), 5);
	putText(img,"/",Point(70,285),FONT_HERSHEY_DUPLEX, 1, CV_RGB(234,173,11), 5);
	putText(img,"=",Point(60,370),FONT_HERSHEY_DUPLEX, 2, CV_RGB(234,173,11), 3);	
	
	//Igual
	//rectangle(img,Point(50,350),Point(120,420),CV_RGB(175,9,9),2,8,0);
	//putText(img,"=",Point(60,405),FONT_HERSHEY_DUPLEX, 2, CV_RGB(234,173,11), 3);

	//Pantalla de numeros
	Point Cuadro[4]={Point(0,img.rows-30), Point(img.cols,img.rows-30), Point(img.cols,img.rows), Point(0,img.rows)};  
	fillConvexPoly(img,Cuadro,4,CV_RGB(0,0,0),8,0);
}

std::string borrar(std::string num){
		std::string nvoNum="";
		
		for (int i = 0; i < (int) std::strlen(num.c_str())-1 ; i++){
			nvoNum+='0';
			nvoNum[i]=num[i];
		}
		
		return nvoNum;
}
