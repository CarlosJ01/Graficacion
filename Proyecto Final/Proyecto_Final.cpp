//Open CV
#include "opencv2/video/tracking.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/opencv.hpp"

//Open GL
#include <GL/glut.h>

//Librerias Extras
#include <math.h>
#include <stdio.h>
#include <pthread.h>
#include "Mapa.h"

using namespace cv;
using namespace std;

//Camara de open GL
float angle=1.5f;
float lx=0.9995f,lz=0.0292f;
float x=-127.0f,z=22.0f, y=1.0f;

//Controles Flujo Optico
int proX1, proY1, proX2, proY2, proD;
int opc1 = 0;
int opc2 = 0;

//Red
int opc = 0;
float ax = x;
float az = z;
float angl=0.0f;

//Camara
VideoCapture cap(0);
Mat gray, prevGray, image, frame;
vector<Point2f> points[2];
TermCriteria termcrit;
Size subPixWinSize(10,10), winSize(31,31);

//Metodos en hilos para los controles y la musica
void *musica(void *);
void *controles(void *);

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(	x, 1.0f, z,
			x+lx, 1.0f,  z+lz,
			0.0f, 1.0f,  0.0f);
			
	//Modelo del mapa
	glColor3ub(40, 180, 99);
	glBegin(GL_QUADS);
		glVertex3f(-135.0f, -0.01f, -125.0f);
		glVertex3f(-135.0f, -0.01f,  130.0f);
		glVertex3f( 130.0f, -0.01f,  130.0f);
		glVertex3f( 130.0f, -0.01f, -125.0f);
	glEnd();
	
	montanias();
	
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, 10.0f);
		glScalef(0.5f, 0.5f, 0.5f);
		redReta();
	glPopMatrix();
	
	glPushMatrix();
		ciudadAzafran();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-75, 0, -75);
		ciudadPlateada();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(75, 0, -75);
		ciudadCeleste();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-100, 0, 100);
		ciudadVerde();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(100, 0, 100);
		puebloLavanda();
	glPopMatrix();
	
	glPushMatrix();
		bosque();
	glPopMatrix();
	
	glPushMatrix();
		if(ax != x || az != z){
			opc++;
			if(opc == 3)
				opc = 1;
		}else{
			opc = 0;
		}
		ax = x;
		az = z;
		
		glTranslatef(x+(5.0f*cos(angl)), 0.0f, z-(5.0f*sin(angl)));
		glScalef(0.5f, 0.5f, 0.5f);
		glRotatef(((angl*180.0f)/PI)+90.0f, 0.0f, 1.0f,0.0f);
		
		red(opc);
	glPopMatrix();
	
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
			angl += 0.1f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_RIGHT :
			angle += 0.1f;
			angl -= 0.1f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_UP :
			ax = x;
			az = z;
			x += lx * fraction;
			z += lz * fraction;
			break;
		case GLUT_KEY_DOWN :
			ax = x;
			az = z;
			x -= lx * fraction;
			z -= lz * fraction;
			break;
	}
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(750,600);
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
	
	glutCreateWindow("Kanto");
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutSpecialFunc(processSpecialKeys);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.5215, 0.7568, 0.9137, 0);
	
	pthread_t hiloControles, hiloMusica;
	pthread_create(&hiloControles, NULL, controles, NULL);
	pthread_create(&hiloMusica, NULL, musica, NULL);
	
	printf("Malla Azul\t->\tMover adelante y atras\n");
	printf("Malla Verde\t->\tMover Cabeza\n");
	printf("Malla Roja\t->\tDetener movimiento\n");
	
	glutMainLoop();
	
	pthread_cancel(hiloControles);
	pthread_cancel(hiloMusica);
	return 1;
}

//Controles con flujo optico
void *controles(void *args){
	while(true){
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
			
			//Analizis del flujo
			size_t i, k;
			proX1 = proY1 = proX2 = proY2 = proD = 0;
			for( i = k = 0; i < points[0].size() ; i++) {
				points[1][k++] = points[1][i];
				
				//Malla 1 mover adelante y atras
				if(i>=0 && i<=199){
					proX1 += points[1][i].x - points[0][i].x;
					proY1 += points[1][i].y - points[0][i].y;
					
					if((i+1)%10 != 0)
						line(image,points[1][i],points[1][i+1], CV_RGB(0,0,255),1, 8,0);
					if((i+1) <= 190)
						line(image,points[1][i],points[1][i+10], CV_RGB(0,0,255),1, 8,0);
				}
			
				//Malla 2 mover la cabeza
				if(i>=200 && i<=399){
					proX2 += points[1][i].x - points[0][i].x;
					proY2 += points[1][i].y - points[0][i].y;
					
					if((i+1)%40 != 0)
						line(image,points[1][i],points[1][i+1], CV_RGB(0,255,0),1, 8,0);
					if((i+1) <= 360)
						line(image,points[1][i],points[1][i+40], CV_RGB(0,255,0),1, 8,0);		
				}
			
				//Malla 3 detener
				if(i>=400 && i<=424){
					proD += sqrt(pow((points[1][i].x - points[0][i].x),2) + pow((points[1][i].y - points[0][i].y),2));
					if((i+1)%5 != 0)
						line(image,points[1][i],points[1][i+1], CV_RGB(255,0,0),1, 8,0);
					if((i+1) <= 420)
						line(image,points[1][i],points[1][i+5], CV_RGB(255,0,0),1, 8,0);
				}
			}
			
			//Promedios para cada malla
			proX1 /= 200;
			proY1 /= 200;
			proX2 /= 200;
			proY2 /= 200;
			proD  /= 25;
		
			points[1].resize(k);
		}
		//~ printf("proX: %d\t",proX1);
		//~ printf("proY: %d\t",proY1);
		//~ printf("proD: %d\n",proD);
	
		//Detener
		if(proD >= 5){
			opc1 = 0;
			opc2 = 0;
		}
	
		//Caminar
		if(abs(proX1) > abs(proY1)){
			opc1=0;
		}
		else{
			if(proY1<0)
				opc1 = 1;
			else if(proY1>0)	
				opc1 = 2;
		}
	
		if(opc1 == 1){
			ax = x;
			az = z;
			x += lx * 0.3f;
			z += lz * 0.3f;
		}else if (opc1 == 2){
			ax = x;
			az = z;
			x -= lx * 0.3f;
			z -= lz * 0.3f;
		}
	
		//Cabeza
		if(abs(proY2) > abs(proX2)){
			opc2=0;
		}
		else{
			if(proX2<0)
				opc2 = 1;
			else if(proX2>0)	
				opc2 = 2;
		}
		
		if(opc2 == 1){
			angle -= 0.01f;
			angl += 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
		}else if (opc2 == 2){
			angle += 0.01f;
			angl -= 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
		}
			
		imshow("Controles", image);
		if( waitKey(10) == 27 )
			break;
			
		swap(prevGray, gray);
	}
	pthread_exit(args);
	return NULL;
}

//Musica de Fondo
void *musica(void *args){
	while(true)
		system("canberra-gtk-play -f Ruta1.ogg");
}
