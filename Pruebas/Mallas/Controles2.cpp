#include "opencv2/video/tracking.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/opencv.hpp"
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#include "Ciudad.h"

using namespace cv;
using namespace std;

VideoCapture cap(0);
float angle=0.0;
float lx=0.0f,lz=-1.0f;
float x=0.0f,z=10.0f;
float distancia=0.0, distancia2=0.0;
int difX=0;
int difZ=0;

int proX, proY, proD;
int opc1 = 0;
int opc2 = 0;

Mat gray, prevGray, image, frame;
vector<Point2f> points[2];
TermCriteria termcrit;
Size subPixWinSize(10,10), winSize(31,31);

void controles();
void modelo();

void renderScene(void) {
	controles();
	modelo();
}

void changeSize(int w, int h) {
	if (h == 0)
		h = 1;
	float ratio =  w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45,ratio,1,100);
	glMatrixMode(GL_MODELVIEW);
}

void processSpecialKeys(int key, int xx, int yy) {
	float fraction = 0.5f;
	switch (key) {
		case GLUT_KEY_LEFT :
			angle -= 0.1f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_RIGHT :
			angle += 0.1f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_UP :
			x += lx * fraction;
			z += lz * fraction;
			break;
		case GLUT_KEY_DOWN :
			x -= lx * fraction;
			z -= lz * fraction;
			break;
	}
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
    Size subPixWinSize(10,10), winSize(31,31);
	TermCriteria termcrit(TermCriteria::COUNT|TermCriteria::EPS,20,0.03);
	
	//Puntos
	int i,j;
	for(i=0; i<20; i++)
		for(j=0; j<10; j++)
			points[0].push_back(Point2f(30+(j*10), 40+(i*15)));
					
	for(i=0; i<5; i++)
		for(j=0; j<40; j++)
			points[0].push_back(Point2f(230+(j*10), 400+(i*15)));
	
	for(i=0; i<5; i++)
		for(j=0; j<5; j++)
			points[0].push_back(Point2f(40+(j*20), 400+(i*15)));
	
	glutCreateWindow("Ciudad Azafran");
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutSpecialFunc(processSpecialKeys);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	
	return 1;
}

void controles(){
	Mat frame;
	cap >> frame;
	flip(frame, frame, 1);
	frame.copyTo(image);
	cvtColor(image, gray, COLOR_BGR2GRAY);
	
	if( !points[0].empty() ){
		vector<uchar> status;
		vector<float> err;
		
		if(prevGray.empty())
			gray.copyTo(prevGray);
	  
		calcOpticalFlowPyrLK(prevGray, gray, points[0], points[1], status, err, winSize,3, termcrit, 0, 0.01);
	  
		size_t i, k;
		proX = proY = proD = 0;
		
		for( i = k = 0; i < points[0].size() ; i++) {
			points[1][k++] = points[1][i];
			
			//Malla 1
			if(i>=0 && i<=199){
				proY += points[1][i].y - points[0][i].y;
				
				if((i+1)%10 != 0)
					line(image,points[1][i],points[1][i+1], CV_RGB(0,0,255),1, 8,0);
				if((i+1) <= 190)
					line(image,points[1][i],points[1][i+10], CV_RGB(0,0,255),1, 8,0);
			}
			
			//Malla 2
			if(i>=200 && i<=399){
				proX += points[1][i].x - points[0][i].x;
				
				if((i+1)%40 != 0)
					line(image,points[1][i],points[1][i+1], CV_RGB(0,255,0),1, 8,0);
				if((i+1) <= 360)
					line(image,points[1][i],points[1][i+40], CV_RGB(0,255,0),1, 8,0);		
			}
			
			//Malla 3
			if(i>=400 && i<=424){
				proD += sqrt(pow((points[1][i].x - points[0][i].x),2) + pow((points[1][i].y - points[0][i].y),2));
				if((i+1)%5 != 0)
					line(image,points[1][i],points[1][i+1], CV_RGB(255,0,0),1, 8,0);
				if((i+1) <= 420)
					line(image,points[1][i],points[1][i+5], CV_RGB(255,0,0),1, 8,0);
			}
			
		}
		proX /= 200;
		proY /= 200;
		proD /= 25;
		
		points[1].resize(k);
	}
	
	//~ printf("proX: %d\t",proX);
	//~ printf("proY: %d\t",pro);
	//~ printf("proD: %d\n",proX);
	
	//Detener
	if(proD >= 3){
		opc1 = 0;
		opc2 = 0;
	}
	
	//Caminar
	if((opc1 == 1 && proY > 0) || (opc1 == 2 && proY < 0))
		opc1=0;
	else{
		if(proY<0)
			opc1 = 1;
		else if(proY>0)	
			opc1 = 2;
	}
	
	if(opc1 == 1){
		x += lx * 0.3f;
		z += lz * 0.3f;
	}else if (opc1 == 2){
		x -= lx * 0.3f;
		z -= lz * 0.3f;
	}
	
	//Cabeza
	if((opc2 == 1 && proX > 0) || (opc2 == 2 && proX < 0))
		opc2=0;
	else{
		if(proX<0)
			opc2 = 1;
		else if(proX>0)	
			opc2 = 2;
	}
	if(opc2 == 1){
		angle -= 0.01f;
		lx = sin(angle);
		lz = -cos(angle);
	}else if (opc2 == 2){
		angle += 0.01f;
		lx = sin(angle);
		lz = -cos(angle);
	}
	
	imshow("Controles", image);
	waitKey(10);
	swap(prevGray, gray);
}

void modelo(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(	x, 1.0f, z,
			x+lx, 1.0f,  z+lz,
			0.0f, 1.0f,  0.0f);
			
	//Modelo del mapa
	glPushMatrix();
		ciudad();
	glPopMatrix();

	glutSwapBuffers();
}
