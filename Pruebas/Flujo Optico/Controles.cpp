#include "opencv2/video/tracking.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/opencv.hpp"
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#include "dibujante.h"

using namespace cv;
using namespace std;

VideoCapture cap(0);
float angle=0.0;
float lx=0.0f,lz=-1.0f;
float x=0.0f,z=5.0f;
float distancia=0.0, distancia2=0.0;
int difX=0;
int difZ=0;

int pro1, pro2, pro3, pro4;

Mat gray, prevGray, image, frame;
vector<Point2f> points[2];
TermCriteria termcrit;
Size subPixWinSize(10,10), winSize(31,31);

void renderScene(void) {
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
	  
		calcOpticalFlowPyrLK(prevGray, gray, points[0], points[1], status, err, winSize,3, termcrit, 0, 0.01);//0.006
	  
		size_t i, k;
		int cont = 1;
		Scalar clr = Scalar(0,0,0);
		pro1 = pro2 = pro3 = pro4 = 0;
		
		difX=0;
		difZ=0;
		for( i = k = 0; i < points[0].size() ; i++, cont++) {
			points[1][k++] = points[1][i];
			
			if(i>=0 && i<=24){
				pro1 += sqrt(pow((points[1][i].x - points[0][i].x),2) + pow((points[1][i].y - points[0][i].y),2));
				clr = CV_RGB(255,255,255);
			}
			if(i>=25 && i<=49){
				pro2 += sqrt(pow((points[1][i].x - points[0][i].x),2) + pow((points[1][i].y - points[0][i].y),2));
				clr = CV_RGB(255,0,0);
			}
			if(i>=50 && i<=74){
				pro3 += sqrt(pow((points[1][i].x - points[0][i].x),2) + pow((points[1][i].y - points[0][i].y),2));
				clr = CV_RGB(0,255,0);
			}
			if(i>=75 && i<=99){
				pro4 += sqrt(pow((points[1][i].x - points[0][i].x),2) + pow((points[1][i].y - points[0][i].y),2));
				clr = CV_RGB(0,0,255);
			}
				
			//Malla
			if((i+1)%5 != 0)
				line(image,points[1][i],points[1][i+1], clr,1, 8,0);
			if(cont <= 20)
				line(image,points[1][i],points[1][i+5], clr,1, 8,0);	
			if(cont == 25)
				cont=0;
		}
		pro1 /= 25;
		pro2 /= 25;
		pro3 /= 25;
		pro4 /= 25;
		
		points[1].resize(k);
	}
	
	if(pro1>=7){	
		angle -= 0.1f;
		lx = sin(angle);
		lz = -cos(angle);
	}
	
	if(pro2>=7){
		angle += 0.1f;
		lx = sin(angle);
		lz = -cos(angle);
	}
		
		
	if(pro3>=7){
		x += lx * 1.0f;
		z += lz * 1.0f;
	}
	
	if(pro4>=7){
		x -= lx * 1.0f;
		z -= lz * 1.0f;
	}
	
	//~ printf("Promedio 1: %d \t",pro1);
	//~ printf("Promedio 2: %d \t",pro2);
	//~ printf("Promedio 3: %d \t",pro3);
	//~ printf("Promedio 4: %d \n",pro4);
	
	imshow("Controles", image);
	waitKey(10);
	swap(prevGray, gray);	
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(	x, 1.0f, z,
			x+lx, 1.0f,  z+lz,
			0.0f, 1.0f,  0.0f);
			
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
		glVertex3f(-100.0f, 0.0f, -100.0f);
		glVertex3f(-100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f, -100.0f);
	glEnd();

	for(int i = -3; i < 3; i++)
		for(int j=-3; j < 3; j++) {
			glPushMatrix();
			glTranslatef(i*30.0,0,j * 30.0);
			tiendaPokemon();
			glPopMatrix();
		}

	glutSwapBuffers();
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
	for(i=0; i<5; i++)
		for(j=0; j<5; j++)
			points[0].push_back(Point2f(40+(j*15),400+(i*10)));
			
	for(i=0; i<5; i++)
		for(j=0; j<5; j++)
			points[0].push_back(Point2f(140+(j*15),400+(i*10)));
	
	for(i=0; i<5; i++)
		for(j=0; j<5; j++)
			points[0].push_back(Point2f(445+(j*15),400+(i*10)));
	
	for(i=0; i<5; i++)
		for(j=0; j<5; j++)
			points[0].push_back(Point2f(545+(j*15),400+(i*10)));
	
	glutCreateWindow("Kanto");
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutSpecialFunc(processSpecialKeys);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	
	return 1;
}
