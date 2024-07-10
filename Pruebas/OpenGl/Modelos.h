//Open CV
#include "opencv2/opencv.hpp"

//Open GL
#include <GL/glut.h>

//Librerias Extras
#include <math.h>
#include <stdio.h>
#include <pthread.h>

using namespace cv;
using namespace std;

# define PI           3.14159265358979323846

void glCircle(float px, float py, float pz, float r, int num){
	float x,y;
	float grd=0;
	float incre=(2*PI)/num;	
	glBegin(GL_POLYGON);
		for(int i=0; i<num; i++,grd+=incre){
			x=px + (r*cos(grd));
			y=py - (r*sin(grd));
			glVertex3f(x, y, pz);
		}
	glEnd();
}

void glCircleM(float px, float py, float pz, float r, int num){
	float x,y;
	float grd=0;
	float incre=(1.05*PI)/num;	
	glBegin(GL_POLYGON);
		for(int i=0; i<num; i++,grd+=incre){
			x=px + (r*cos(grd));
			y=py - (r*sin(grd));
			glVertex3f(x, y, pz);
		}
	glEnd();
}

void glCircleM2(float px, float py, float pz, float r, int num){
	float x,y;
	float grd=0;
	float incre=(1.05*PI)/num;	
	glBegin(GL_POLYGON);
		for(int i=0; i<num; i++,grd+=incre){
			x=px - (r*cos(grd));
			y=py + (r*sin(grd));
			glVertex3f(x, y, pz);
		}
	glEnd();
}

void centroPokemon(){
	//Paredes
	glColor3ub(245, 240, 240);
	glBegin(GL_QUADS);
		glVertex3f(-3,3,0);
		glVertex3f(-3,0,0);
		glVertex3f(3,0,0);
		glVertex3f(3,3,0);
		
		glVertex3f(3,3,0);
		glVertex3f(3,0,0);
		glVertex3f(3,0,-5);
		glVertex3f(3,3,-5);
		
		glVertex3f(-3,3,0);
		glVertex3f(-3,0,0);
		glVertex3f(-3,0,-5);
		glVertex3f(-3,3,-5);
		
		glVertex3f(-3,3,-5);
		glVertex3f(-3,0,-5);
		glVertex3f(3,0,-5);
		glVertex3f(3,3,-5);
	glEnd();
	
	//Techo
	glColor3ub(221,45,17);
	glBegin(GL_QUADS);
		glVertex3f(-2,4.5,0);
		glVertex3f(-3.5,3,0);
		glVertex3f(3.5,3,0);
		glVertex3f(2,4.5,0);
		
		glVertex3f(2,4.5,0);
		glVertex3f(3.5,3,0);
		glVertex3f(3.5,3,-5);
		glVertex3f(2,4.5,-5);
		
		glVertex3f(2,4.5,-5);
		glVertex3f(3.5,3,-5);
		glVertex3f(-3.5,3,-5);
		glVertex3f(-2,4.5,-5);
		
		glVertex3f(-2,4.5,-5);
		glVertex3f(-3.5,3,-5);
		glVertex3f(-3.5,3,0);
		glVertex3f(-2,4.5,0);
		
		glVertex3f(-3.5,3,0);
		glVertex3f(3.5,3,0);
		glVertex3f(3.5,3,-5);
		glVertex3f(-3.5,3,-5);
		
		glVertex3f(-2,4.5,0);
		glVertex3f(2,4.5,0);
		glVertex3f(2,4.5,-5);
		glVertex3f(-2,4.5,-5);
	glEnd();
	
	//Puerta
	glBegin (GL_POLYGON);
		glVertex3f(-1.3f ,0.0f, 0.01f);
		glVertex3f(-1.3f ,2.3f, 0.01f);
		glVertex3f(-0.8f ,2.8f, 0.01f);
		glVertex3f( 0.8f ,2.8f, 0.01f);
		glVertex3f( 1.3f ,2.3f, 0.01f);
		glVertex3f( 1.3f ,0.0f, 0.01f);
	glEnd ();
	
	glColor3ub(22,229,239);
	glBegin (GL_POLYGON);
		glVertex3f(-1.0f ,0.0f, 0.03f);
		glVertex3f(-1.0f ,2.0f, 0.03f);
		glVertex3f(-0.5f ,2.5f, 0.03f);
		glVertex3f( 0.5f ,2.5f, 0.03f);
		glVertex3f( 1.0f ,2.0f, 0.03f);
		glVertex3f( 1.0f ,0.0f, 0.03f);
	glEnd ();
	
	glColor3ub(0,0,0);
	glLineWidth(5);
	glBegin(GL_LINES);
		glVertex3f(0.0f ,2.5f, 0.04f);
		glVertex3f(0.0f ,0.0f, 0.04f);
	glEnd();
	
	//Logo
	glColor3ub(255,0,0);
	glCircle(0,3.75,0.01,0.5,30);
	glColor3ub(255,255,255);
	glCircleM(0,3.75,0.02,0.5,30);
	glColor3ub(0,0,0);
	glCircle(0,3.75,0.03,0.3,30);
	glColor3ub(255,255,255);
	glCircle(0,3.75,0.04,0.2,30);
}

void tiendaPokemon(){
	//Paredes
	glColor3ub(245, 240, 240);
	glBegin(GL_QUADS);
		glVertex3f(-3,3,0);
		glVertex3f(-3,0,0);
		glVertex3f(3,0,0);
		glVertex3f(3,3,0);
		
		glVertex3f(3,3,0);
		glVertex3f(3,0,0);
		glVertex3f(3,0,-5);
		glVertex3f(3,3,-5);
		
		glVertex3f(-3,3,0);
		glVertex3f(-3,0,0);
		glVertex3f(-3,0,-5);
		glVertex3f(-3,3,-5);
		
		glVertex3f(-3,3,-5);
		glVertex3f(-3,0,-5);
		glVertex3f(3,0,-5);
		glVertex3f(3,3,-5);
	glEnd();
	
	//Techo
	glColor3ub(9,128,187);
	glBegin(GL_QUADS);
		glVertex3f(-2,4.5,0);
		glVertex3f(-3.5,3,0);
		glVertex3f(3.5,3,0);
		glVertex3f(2,4.5,0);
		
		glVertex3f(2,4.5,0);
		glVertex3f(3.5,3,0);
		glVertex3f(3.5,3,-5);
		glVertex3f(2,4.5,-5);
		
		glVertex3f(2,4.5,-5);
		glVertex3f(3.5,3,-5);
		glVertex3f(-3.5,3,-5);
		glVertex3f(-2,4.5,-5);
		
		glVertex3f(-2,4.5,-5);
		glVertex3f(-3.5,3,-5);
		glVertex3f(-3.5,3,0);
		glVertex3f(-2,4.5,0);
		
		glVertex3f(-3.5,3,0);
		glVertex3f(3.5,3,0);
		glVertex3f(3.5,3,-5);
		glVertex3f(-3.5,3,-5);
		
		glVertex3f(-2,4.5,0);
		glVertex3f(2,4.5,0);
		glVertex3f(2,4.5,-5);
		glVertex3f(-2,4.5,-5);
	glEnd();
	
	//Puerta
	glBegin (GL_POLYGON);
		glVertex3f(-1.3f ,0.0f, 0.01f);
		glVertex3f(-1.3f ,2.3f, 0.01f);
		glVertex3f(-0.8f ,2.8f, 0.01f);
		glVertex3f( 0.8f ,2.8f, 0.01f);
		glVertex3f( 1.3f ,2.3f, 0.01f);
		glVertex3f( 1.3f ,0.0f, 0.01f);
	glEnd ();
	
	glColor3ub(22,229,239);
	glBegin (GL_POLYGON);
		glVertex3f(-1.0f ,0.0f, 0.03f);
		glVertex3f(-1.0f ,2.0f, 0.03f);
		glVertex3f(-0.5f ,2.5f, 0.03f);
		glVertex3f( 0.5f ,2.5f, 0.03f);
		glVertex3f( 1.0f ,2.0f, 0.03f);
		glVertex3f( 1.0f ,0.0f, 0.03f);
	glEnd ();
	
	glColor3ub(0,0,0);
	glLineWidth(5);
	glBegin(GL_LINES);
		glVertex3f(0.0f ,2.5f, 0.04f);
		glVertex3f(0.0f ,0.0f, 0.04f);
	glEnd();
	
	//Logo
	glColor3ub(255,0,0);
	glCircle(0,3.75,0.01,0.5,30);
	glColor3ub(255,255,255);
	glCircleM(0,3.75,0.02,0.5,30);
	glColor3ub(0,0,0);
	glCircle(0,3.75,0.03,0.3,30);
	glColor3ub(255,255,255);
	glCircle(0,3.75,0.04,0.2,30);
}

void gimnacioPokemon(){
	glScalef(2.0f, 1.5f, 1.5f);
	glPushMatrix();
		//Paredes
		glColor3ub(245, 240, 240);
		glBegin(GL_QUADS);
			glVertex3f(-3,3,0);
			glVertex3f(-3,0,0);
			glVertex3f(3,0,0);
			glVertex3f(3,3,0);
			
			glVertex3f(3,3,0);
			glVertex3f(3,0,0);
			glVertex3f(3,0,-5);
			glVertex3f(3,3,-5);
			
			glVertex3f(-3,3,0);
			glVertex3f(-3,0,0);
			glVertex3f(-3,0,-5);
			glVertex3f(-3,3,-5);
			
			glVertex3f(-3,3,-5);
			glVertex3f(-3,0,-5);
			glVertex3f(3,0,-5);
			glVertex3f(3,3,-5);
		glEnd();
		
		//Techo
		glColor3ub(211,138,11);
		glBegin(GL_QUADS);
			glVertex3f(-2,4.5,0);
			glVertex3f(-3.5,3,0);
			glVertex3f(3.5,3,0);
			glVertex3f(2,4.5,0);
			
			glVertex3f(2,4.5,0);
			glVertex3f(3.5,3,0);
			glVertex3f(3.5,3,-5);
			glVertex3f(2,4.5,-5);
			
			glVertex3f(2,4.5,-5);
			glVertex3f(3.5,3,-5);
			glVertex3f(-3.5,3,-5);
			glVertex3f(-2,4.5,-5);
			
			glVertex3f(-2,4.5,-5);
			glVertex3f(-3.5,3,-5);
			glVertex3f(-3.5,3,0);
			glVertex3f(-2,4.5,0);
			
			glVertex3f(-3.5,3,0);
			glVertex3f(3.5,3,0);
			glVertex3f(3.5,3,-5);
			glVertex3f(-3.5,3,-5);
			
			glVertex3f(-2,4.5,0);
			glVertex3f(2,4.5,0);
			glVertex3f(2,4.5,-5);
			glVertex3f(-2,4.5,-5);
		glEnd();
		
		//Puerta
		glBegin (GL_POLYGON);
			glVertex3f(-1.3f ,0.0f, 0.01f);
			glVertex3f(-1.3f ,2.3f, 0.01f);
			glVertex3f(-0.8f ,2.8f, 0.01f);
			glVertex3f( 0.8f ,2.8f, 0.01f);
			glVertex3f( 1.3f ,2.3f, 0.01f);
			glVertex3f( 1.3f ,0.0f, 0.01f);
		glEnd ();
	
		glColor3ub(22,229,239);
		glBegin (GL_POLYGON);
			glVertex3f(-1.0f ,0.0f, 0.03f);
			glVertex3f(-1.0f ,2.0f, 0.03f);
			glVertex3f(-0.5f ,2.5f, 0.03f);
			glVertex3f( 0.5f ,2.5f, 0.03f);
			glVertex3f( 1.0f ,2.0f, 0.03f);
			glVertex3f( 1.0f ,0.0f, 0.03f);
		glEnd ();
	
		glColor3ub(0,0,0);
		glLineWidth(5);
		glBegin(GL_LINES);
			glVertex3f(0.0f ,2.5f, 0.04f);
			glVertex3f(0.0f ,0.0f, 0.04f);
		glEnd();
	
		//Logo
		glColor3ub(255,0,0);
		glCircle(0,3.75,0.01,0.5,30);
		glColor3ub(255,255,255);
		glCircleM(0,3.75,0.02,0.5,30);
		glColor3ub(0,0,0);
		glCircle(0,3.75,0.03,0.3,30);
		glColor3ub(255,255,255);
		glCircle(0,3.75,0.04,0.2,30);
	glPopMatrix();
}

void casa(int R1, int G1, int B1, int R2, int G2, int B2){
	//Paredes
	glColor3ub(R1, G1, B1);
	glBegin(GL_QUADS);
		glVertex3f(-2.5,3,0);
		glVertex3f(-2.5,0,0);
		glVertex3f(2.5,0,0);
		glVertex3f(2.5,3,0);
			
		glVertex3f(2.5,3,0);
		glVertex3f(2.5,0,0);
		glVertex3f(2.5,0,-3);
		glVertex3f(2.5,3,-3);
			
		glVertex3f(-2.5,3,0);
		glVertex3f(-2.5,0,0);
		glVertex3f(-2.5,0,-3);
		glVertex3f(-2.5,3,-3);
			
		glVertex3f(-2.5,3,-3);
		glVertex3f(-2.5,0,-3);
		glVertex3f(2.5,0,-3);
		glVertex3f(2.5,3,-3);
	glEnd();
	
	//Madera
	glColor3ub(182, 142, 19);
	glBegin(GL_QUADS);
		glVertex3f(-1.5f, 3.0f ,0.01f);
		glVertex3f(-1.5f, 0.0f ,0.01f);
		glVertex3f(-1.0f, 0.0f ,0.01f);
		glVertex3f(-1.0f, 3.0f ,0.01f);
		
		
		glVertex3f(1.5f, 3.0f ,0.01f);
		glVertex3f(1.5f, 0.0f ,0.01f);
		glVertex3f(1.0f, 0.0f ,0.01f);
		glVertex3f(1.0f, 3.0f ,0.01f);
		
		glVertex3f(-1.5f, 3.0f ,-3.01f);
		glVertex3f(-1.5f, 0.0f ,-3.01f);
		glVertex3f(-1.0f, 0.0f ,-3.01f);
		glVertex3f(-1.0f, 3.0f ,-3.01f);
		
		glVertex3f(1.5f, 3.0f ,-3.01f);
		glVertex3f(1.5f, 0.0f ,-3.01f);
		glVertex3f(1.0f, 0.0f ,-3.01f);
		glVertex3f(1.0f, 3.0f ,-3.01f);
	glEnd();
	
	glBegin (GL_POLYGON);
		glVertex3f(-2.5f, 3.0f, 0.0f);
		glVertex3f(-1.0f, 4.0f, 0.0f);
		glVertex3f(1.0f, 4.0f, 0.0f);
		glVertex3f(2.5f, 3.0f, 0.0f);
		
		//~ glVertex3f(-2.5f, 3.0f, -3.0f);
		//~ glVertex3f(-1.0f, 4.0f, -3.0f);
		//~ glVertex3f(1.0f, 4.0f, -3.0f);
		//~ glVertex3f(2.5f, 3.0f, -3.0f);
	glEnd();
	
	//Puerta
	glColor3ub(103,148,167);
	glBegin(GL_QUADS);
		glVertex3f(-0.5f, 1.75f ,0.01f);
		glVertex3f(-0.5f, 0.0f ,0.01f);
		glVertex3f(0.5f, 0.0f ,0.01f);
		glVertex3f(0.5f, 1.75f ,0.01f);
	glEnd();
	
	//Ventana
	glColor3ub(22, 135, 151);
	glCircle(0,2.4,0.01,0.5,30);
	
	//Chimenea
	glColor3ub(144, 159, 178);
	glBegin(GL_QUADS);
		glVertex3f(0.5f, 5.5f ,-1.0f);
		glVertex3f(0.5f, 0.0f ,-1.0f);
		glVertex3f(1.5f, 0.0f ,-1.0f);
		glVertex3f(1.5f, 5.5f ,-1.0f);
		
		glVertex3f(1.5f, 5.5f ,-1.0f);
		glVertex3f(1.5f, 0.0f ,-1.0f);
		glVertex3f(1.5f, 0.0f ,-2.0f);
		glVertex3f(1.5f, 5.5f ,-2.0f);
		
		glVertex3f(1.5f, 5.5f ,-2.0f);
		glVertex3f(1.5f, 0.0f ,-2.0f);
		glVertex3f(0.5f, 0.0f ,-2.0f);
		glVertex3f(0.5f, 5.5f ,-2.0f);
		
		glVertex3f(0.5f, 5.5f ,-2.0f);
		glVertex3f(0.5f, 0.0f ,-2.0f);
		glVertex3f(0.5f, 0.0f ,-1.0f);
		glVertex3f(0.5f, 5.5f ,-1.0f);
	glEnd();
	
	//Techo
	glColor3ub(R2, G2, B2);
	glBegin(GL_POLYGON);
		glVertex3f(-3.0f, 3.0f, -0.01f);
		glVertex3f(-2.5f, 3.0f, -0.01f);
		glVertex3f(-1.0f, 4.0f, -0.01f);
		glVertex3f(1.0f, 4.0f, -0.01f);
		glVertex3f(2.5f, 3.0f, -0.01f);
		glVertex3f(3.0f, 3.0f, -0.01f);
		glVertex3f(3.0f, 3.25f, -0.01f);
		glVertex3f(2.5f, 3.25f, -0.01f);
		glVertex3f(1.0f, 4.25f, -0.01f);
		glVertex3f(-1.0f, 4.25f, -0.01f);
		glVertex3f(-2.5f, 3.25f, -0.01f);
		glVertex3f(-3.0f, 3.25f, -0.01f);
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex3f(-3.0f, 3.0f, -3.0f);
		glVertex3f(-2.5f, 3.0f, -3.0f);
		glVertex3f(-1.0f, 4.0f, -3.0f);
		glVertex3f(1.0f, 4.0f, -3.0f);
		glVertex3f(2.5f, 3.0f, -3.0f);
		glVertex3f(3.0f, 3.0f, -3.0f);
		glVertex3f(3.0f, 3.25f, -3.0f);
		glVertex3f(2.5f, 3.25f, -3.0f);
		glVertex3f(1.0f, 4.25f, -3.0f);
		glVertex3f(-1.0f, 4.25f, -3.0f);
		glVertex3f(-2.5f, 3.25f, -3.0f);
		glVertex3f(-3.0f, 3.25f, -3.0f);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3f(-3.0f, 3.0f, -0.01f);
		glVertex3f( 3.0f, 3.0f, -0.01f);
		glVertex3f( 3.0f, 3.0f, -3.0f);
		glVertex3f(-3.0f, 3.0f, -3.0f);
		
		glVertex3f(-3.0f, 3.0f, -0.01f);
		glVertex3f(-3.0f, 3.0f, -3.0f);
		glVertex3f(-3.0f, 3.25f, -3.0f);
		glVertex3f(-3.0f, 3.25f, -0.01f);
		
		glVertex3f(3.0f, 3.0f, -0.01f);
		glVertex3f(3.0f, 3.0f, -3.0f);
		glVertex3f(3.0f, 3.25f, -3.0f);
		glVertex3f(3.0f, 3.25f, -0.01f);
		
		//-------------------------------
		//~ glVertex3f(-3.0f, 3.25f, -0.01f);
		//~ glVertex3f(-2.5f, 3.25f, -0.01f);
		//~ glVertex3f(-2.5f, 3.25f, -3.0f);
		//~ glVertex3f(-3.0f, 3.25f, -3.0f);
		
		//~ glVertex3f(3.0f, 3.25f, -0.01f);
		//~ glVertex3f(2.5f, 3.25f, -0.01f);
		//~ glVertex3f(2.5f, 3.25f, -3.0f);
		//~ glVertex3f(3.0f, 3.25f, -3.0f);
		//------------------------------
		
		glVertex3f(-2.5f, 3.25f, -0.01f);
		glVertex3f(-1.0f, 4.25f, -0.01f);
		glVertex3f(-1.0f, 4.25f, -3.0f);
		glVertex3f(-2.5f, 3.25f, -3.0f);
		
		glVertex3f(2.5f, 3.25f, -0.01f);
		glVertex3f(1.0f, 4.25f, -0.01f);
		glVertex3f(1.0f, 4.25f, -3.0f);
		glVertex3f(2.5f, 3.25f, -3.0f);
		
	glEnd();
}

void edificio(){
	//Paredes
	glColor3ub(102, 99, 93);
	glBegin(GL_QUADS);
		glVertex3f(-7.0f, 23.0f, 0.0f);
		glVertex3f(-7.0f, 0.0f, 0.0f);
		glVertex3f(7.0f, 0.0f, 0.0f);
		glVertex3f(7.0f, 23.0f, 0.0f);
		
		glVertex3f(10.0f, 23.0f, -5.0f);
		glVertex3f(10.0f, 0.0f, -5.0f);
		glVertex3f(10.0f, 0.0f, -15.0f);
		glVertex3f(10.0f, 23.0f, -15.0f);
		
		glVertex3f(-10.0f, 23.0f, -5.0f);
		glVertex3f(-10.0f, 0.0f, -5.0f);
		glVertex3f(-10.0f, 0.0f, -15.0f);
		glVertex3f(-10.0f, 23.0f, -15.0f);
		
		glVertex3f(7.0f, 23.0f, -20.0f);
		glVertex3f(7.0f, 0.0f, -20.0f);
		glVertex3f(-7.0f, 0.0f, -20.0f);
		glVertex3f(-7.0f, 23.0f, -20.0f);
	glEnd();
	
	//Esquinas
	glColor3ub(74, 35, 90);
	glBegin(GL_QUADS);
		glVertex3f(7.0f, 23.0f, 0.0f);
		glVertex3f(7.0f, 0.0f, 0.0f);
		glVertex3f(10.0f, 0.0f, -5.0f);
		glVertex3f(10.0f, 23.0f, -5.0f);
		
		glVertex3f(-7.0f, 23.0f, 0.0f);
		glVertex3f(-7.0f, 0.0f, 0.0f);
		glVertex3f(-10.0f, 0.0f, -5.0f);
		glVertex3f(-10.0f, 23.0f, -5.0f);
		
		glVertex3f(10.0f, 23.0f, -15.0f);
		glVertex3f(10.0f, 0.0f, -15.0f);
		glVertex3f(7.0f, 0.0f, -20.0f);
		glVertex3f(7.0f, 23.0f, -20.0f);
		
		glVertex3f(-10.0f, 23.0f, -15.0f);
		glVertex3f(-10.0f, 0.0f, -15.0f);
		glVertex3f(-7.0f, 0.0f, -20.0f);
		glVertex3f(-7.0f, 23.0f, -20.0f);
	glEnd();
	
	//Ventanas
	glColor3ub(240, 233, 9);
	glBegin(GL_QUADS);
		for (int i = 0; i < 18; i++){
			glVertex3f(-6.5f, 22.5f-(1.0f*i), 0.01f);
			glVertex3f(-6.5f, 22.0f-(1.0f*i), 0.01f);
			glVertex3f( 6.5f, 22.0f-(1.0f*i), 0.01f);
			glVertex3f( 6.5f, 22.5f-(1.0f*i), 0.01f);
		}
		
		for (int i = 0; i < 18; i++){
			glVertex3f(-6.5f, 22.5f-(1.0f*i), -20.01f);
			glVertex3f(-6.5f, 22.0f-(1.0f*i), -20.01f);
			glVertex3f( 6.5f, 22.0f-(1.0f*i), -20.01f);
			glVertex3f( 6.5f, 22.5f-(1.0f*i), -20.01f);
		}
		
		for (int i = 0; i < 18; i++){
			glVertex3f(-10.01f, 22.5f-(1.0f*i), -5.0f);
			glVertex3f(-10.01f, 22.0f-(1.0f*i), -5.0f);
			glVertex3f(-10.01f, 22.0f-(1.0f*i), -15.0f);
			glVertex3f(-10.01f, 22.5f-(1.0f*i), -15.0f);
		}
		
		for (int i = 0; i < 18; i++){
			glVertex3f(10.01f, 22.5f-(1.0f*i), -5.0f);
			glVertex3f(10.01f, 22.0f-(1.0f*i), -5.0f);
			glVertex3f(10.01f, 22.0f-(1.0f*i), -15.0f);
			glVertex3f(10.01f, 22.5f-(1.0f*i), -15.0f);
		}
	glEnd();
	
	//Entrada
	glColor3ub(82, 80, 75);
	glBegin(GL_QUADS);
		glVertex3f(-5.0f, 4.0f, 2.0f);
		glVertex3f(-5.0f, 0.0f, 2.0f);
		glVertex3f(5.0f,  0.0f, 2.0f);
		glVertex3f(5.0f,  4.0f, 2.0f);
		
		glVertex3f(5.0f,  4.0f, 2.0f);
		glVertex3f(5.0f,  0.0f, 2.0f);
		glVertex3f(6.5f,  0.0f, 0.0f);
		glVertex3f(6.5f,  4.0f, 0.0f);
		
		glVertex3f(-5.0f,  4.0f, 2.0f);
		glVertex3f(-5.0f,  0.0f, 2.0f);
		glVertex3f(-6.5f,  0.0f, 0.0f);
		glVertex3f(-6.5f,  4.0f, 0.0f);
	glEnd();
	
	//Cinta
	glColor3ub(164, 16, 16);
	glBegin(GL_QUADS);
		glVertex3f(-5.0f, 1.5f, 2.01f);
		glVertex3f(-5.0f, 0.0f, 2.01f);
		glVertex3f(5.0f,  0.0f, 2.01f);
		glVertex3f(5.0f,  1.5f, 2.01f);
		
		glVertex3f(5.0f,  1.5f, 2.01f);
		glVertex3f(5.0f,  0.0f, 2.01f);
		glVertex3f(6.5f,  0.0f, 0.01f);
		glVertex3f(6.5f,  1.5f, 0.01f);
		
		glVertex3f(-5.0f,  1.5f, 2.01f);
		glVertex3f(-5.0f,  0.0f, 2.01f);
		glVertex3f(-6.5f,  0.0f, 0.01f);
		glVertex3f(-6.5f,  1.5f, 0.01f);
	glEnd();
	
	//Puerta
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
		glVertex3f(-2.0f, 0.0f, 2.02f);
		glVertex3f(-2.0f, 2.5f, 2.02f);
		glVertex3f( 2.0f, 2.5f, 2.02f);
		glVertex3f( 2.0f, 0.0f, 2.02f);
		
		glVertex3f( 2.3f, 0.0f, 2.02f);
		glVertex3f( 2.3f, 2.8f, 2.02f);
		glVertex3f(-2.3f, 2.8f, 2.02f);
		glVertex3f(-2.3f, 0.0f, 2.02f);
	glEnd();
	
	glColor3ub(36, 113, 163);
	glBegin(GL_QUADS);
		glVertex3f(-2.0f, 2.5f, 2.03f);
		glVertex3f(-2.0f, 0.0f, 2.03f);
		glVertex3f( 2.0f, 0.0f, 2.03f);
		glVertex3f( 2.0f, 2.5f, 2.03f);
	glEnd();
	
	glColor3ub(0, 0, 0);
	glLineWidth(5);
	glBegin(GL_LINES);
		glVertex3f(0.0f, 2.5f, 2.04f);
		glVertex3f(0.0f, 0.0f, 2.04f);
	glEnd();
}

void ligaPokemon(){
	//Paredes
	glColor3ub(211, 84, 0);
	glBegin(GL_QUADS);
		glVertex3f(-10.0f, 8.0f, 0.0f);
		glVertex3f(-10.0f, 0.0f, 0.0f);
		glVertex3f( 10.0f, 0.0f, 0.0f);
		glVertex3f( 10.0f, 8.0f, 0.0f);
		
		glVertex3f( 10.0f, 8.0f, 0.0f);
		glVertex3f( 10.0f, 0.0f, 0.0f);
		glVertex3f( 10.0f, 0.0f, -15.0f);
		glVertex3f( 10.0f, 8.0f, -15.0f);
		
		glVertex3f(-10.0f, 8.0f, 0.0f);
		glVertex3f(-10.0f, 0.0f, 0.0f);
		glVertex3f(-10.0f, 0.0f, -15.0f);
		glVertex3f(-10.0f, 8.0f, -15.0f);
		
		glVertex3f(-10.0f, 8.0f, -15.0f);
		glVertex3f(-10.0f, 0.0f, -15.0f);
		glVertex3f( 10.0f, 0.0f, -15.0f);
		glVertex3f( 10.0f, 8.0f, -15.0f);
	glEnd();
	
	//Cintas
	glColor3ub(95, 106, 106);
	glBegin(GL_QUADS);
		glVertex3f(-10.0f, 1.0f, 0.01f);
		glVertex3f(-10.0f, 0.0f, 0.01f);
		glVertex3f( 10.0f, 0.0f, 0.01f);
		glVertex3f( 10.0f, 1.0f, 0.01f);
		
		glVertex3f( 10.01f, 1.0f, 0.0f);
		glVertex3f( 10.01f, 0.0f, 0.0f);
		glVertex3f( 10.01f, 0.0f, -15.0f);
		glVertex3f( 10.01f, 1.0f, -15.0f);
		
		glVertex3f(-10.01f, 1.0f, 0.0f);
		glVertex3f(-10.01f, 0.0f, 0.0f);
		glVertex3f(-10.01f, 0.0f, -15.0f);
		glVertex3f(-10.01f, 1.0f, -15.0f);
		
		glVertex3f(-10.0f, 1.0f, -15.01f);
		glVertex3f(-10.0f, 0.0f, -15.01f);
		glVertex3f( 10.0f, 0.0f, -15.01f);
		glVertex3f( 10.0f, 1.0f, -15.01f);
	glEnd();
	
	//Techo
	glBegin(GL_QUADS);
		glVertex3f(-10.0f, 8.0f, 1.01f);
		glVertex3f(10.0f, 8.0f, 1.01f);
		glVertex3f(10.0f, 8.0f, -15.01f);
		glVertex3f(-10.0f, 8.0f, -15.01f);
		
		glVertex3f(-10.0f, 9.0f, 1.0f);
		glVertex3f(-10.0f, 8.0f, 1.0f);
		glVertex3f( 10.0f, 8.0f, 1.0f);
		glVertex3f( 10.0f, 9.0f, 1.0f);
		
		glVertex3f( 10.0f, 9.0f, 1.0f);
		glVertex3f( 10.0f, 8.0f, 1.0f);
		glVertex3f( 10.0f, 8.0f, -15.0f);
		glVertex3f( 10.0f, 9.0f, -15.0f);
		
		glVertex3f(-10.0f, 9.0f, 1.0f);
		glVertex3f(-10.0f, 8.0f, 1.0f);
		glVertex3f(-10.0f, 8.0f, -15.0f);
		glVertex3f(-10.0f, 9.0f, -15.0f);
		
		glVertex3f(-10.0f, 9.0f, -15.0f);
		glVertex3f(-10.0f, 8.0f, -15.0f);
		glVertex3f( 10.0f, 8.0f, -15.0f);
		glVertex3f( 10.0f, 9.0f, -15.0f);
	glEnd();
	
	//Columnas
	glColor3ub(166, 172, 175);
	glBegin(GL_QUADS);
		glVertex3f(-8.0f, 8.0f, 0.01f);
		glVertex3f(-8.0f, 0.0f, 0.01f);
		glVertex3f(-7.0f, 0.0f, 1.01f);
		glVertex3f(-7.0f, 8.0f, 1.01f);
		
		glVertex3f(-7.0f, 8.0f, 1.01f);
		glVertex3f(-7.0f, 0.0f, 1.01f);
		glVertex3f(-6.0f, 0.0f, 1.01f);
		glVertex3f(-6.0f, 8.0f, 1.01f);
		
		glVertex3f(-6.0f, 8.0f, 1.01f);
		glVertex3f(-6.0f, 0.0f, 1.01f);
		glVertex3f(-5.0f, 0.0f, 0.01f);
		glVertex3f(-5.0f, 8.0f, 0.01f);
		
		glVertex3f(8.0f, 8.0f, 0.01f);
		glVertex3f(8.0f, 0.0f, 0.01f);
		glVertex3f(7.0f, 0.0f, 1.01f);
		glVertex3f(7.0f, 8.0f, 1.01f);
		
		glVertex3f(7.0f, 8.0f, 1.01f);
		glVertex3f(7.0f, 0.0f, 1.01f);
		glVertex3f(6.0f, 0.0f, 1.01f);
		glVertex3f(6.0f, 8.0f, 1.01f);
		
		glVertex3f(6.0f, 8.0f, 1.01f);
		glVertex3f(6.0f, 0.0f, 1.01f);
		glVertex3f(5.0f, 0.0f, 0.01f);
		glVertex3f(5.0f, 8.0f, 0.01f);
	glEnd();
	
	//Puertas
	glColor3ub(183, 149, 11);
	glBegin (GL_POLYGON);
		glVertex3f(2.5f, 5.0f, 2.02f);
		glVertex3f(2.5f, 0.0f, 2.02f);
		glVertex3f(5.0f, 0.0f, 0.01f);
		glVertex3f(5.0f, 5.0f, 0.01f);
	glEnd();
	
	glBegin (GL_POLYGON);
		glVertex3f(-2.5f, 5.0f, 2.02f);
		glVertex3f(-2.5f, 0.0f, 2.02f);
		glVertex3f(-5.0f, 0.0f, 0.01f);
		glVertex3f(-5.0f, 5.0f, 0.01f);
	glEnd();
	
	glBegin (GL_POLYGON);
		glVertex3f(-2.5f, 7.0f, 2.02f);
		glVertex3f(-2.5f, 0.0f, 2.02f);
		glVertex3f( 2.5f, 0.0f, 2.02f);
		glVertex3f( 2.5f, 7.0f, 2.02f);
		glVertex3f( 0.0f, 8.0f, 2.02f);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3f(-2.5f, 7.0f, 2.02f);
		glVertex3f(-2.5f, 5.0f, 2.02f);
		glVertex3f(-2.5f, 5.0f, 0.01f);
		glVertex3f(-2.5f, 7.0f, 0.01f);
		
		glVertex3f(2.5f, 7.0f, 2.02f);
		glVertex3f(2.5f, 5.0f, 2.02f);
		glVertex3f(2.5f, 5.0f, 0.01f);
		glVertex3f(2.5f, 7.0f, 0.01f);
	glEnd();
	
	glColor3ub(36, 113, 163);
	glBegin (GL_POLYGON);
		glVertex3f(-1.5f, 4.0f, 2.03f);
		glVertex3f(-1.5f, 0.0f, 2.03f);
		glVertex3f( 1.5f, 0.0f, 2.03f);
		glVertex3f( 1.5f, 4.0f, 2.03f);
		glVertex3f( 0.0f, 5.0f, 2.03f);
	glEnd();
	
	//Logo
	glColor3ub(255,0,0);
	glCircle(0, 6.3, 2.03,1,30);
	glColor3ub(255,255,255);
	glCircleM(0, 6.3, 2.04,1,30);
	glColor3ub(0,0,0);
	glCircle(0, 6.3, 2.05,0.5,30);
	glColor3ub(255,255,255);
	glCircle(0, 6.3, 2.06,0.3,30);
}

void arbol(){
	//Tronco
	glColor3ub(120, 73, 15);
	glBegin(GL_QUADS);
		glVertex3f(-0.5f, 3.0f,  0.5f);
		glVertex3f(-0.5f, 0.0f,  0.5f);
		glVertex3f( 0.5f, 0.0f,  0.5f);
		glVertex3f( 0.5f, 3.0f,  0.5f);
		
		glVertex3f( 0.5f, 3.0f, 0.5f);
		glVertex3f( 0.5f, 0.0f, 0.5f);
		glVertex3f( 0.5f, 0.0f, -0.5f);
		glVertex3f( 0.5f, 3.0f, -0.5f);
		
		glVertex3f(-0.5f, 3.0f, 0.5f);
		glVertex3f(-0.5f, 0.0f, 0.5f);
		glVertex3f(-0.5f, 0.0f, -0.5f);
		glVertex3f(-0.5f, 3.0f, -0.5f);
		
		glVertex3f(-0.5f, 3.0f, -0.5f);
		glVertex3f(-0.5f, 0.0f, -0.5f);
		glVertex3f( 0.5f, 0.0f, -0.5f);
		glVertex3f( 0.5f, 3.0f, -0.5f);
	glEnd();
	
	//Hojas
	glColor3ub(15, 120, 23);
	glBegin(GL_QUADS);
		glVertex3f(-2.5f, 3.0f,  2.5f);
		glVertex3f(-2.5f, 2.0f,  2.5f);
		glVertex3f( 2.5f, 2.0f,  2.5f);
		glVertex3f( 2.5f, 3.0f,  2.5f);
		
		glVertex3f( 2.5f, 3.0f, 2.5f);
		glVertex3f( 2.5f, 2.0f, 2.5f);
		glVertex3f( 2.5f, 2.0f, -2.5f);
		glVertex3f( 2.5f, 3.0f, -2.5f);
		
		glVertex3f(-2.5f, 3.0f, 2.5f);
		glVertex3f(-2.5f, 2.0f, 2.5f);
		glVertex3f(-2.5f, 2.0f, -2.5f);
		glVertex3f(-2.5f, 3.0f, -2.5f);
		
		glVertex3f(-2.5f, 3.0f, -2.5f);
		glVertex3f(-2.5f, 2.0f, -2.5f);
		glVertex3f( 2.5f, 2.0f, -2.5f);
		glVertex3f( 2.5f, 3.0f, -2.5f);
		
		glVertex3f(-2.5f, 2.0f,  2.5f);
		glVertex3f( 2.5f, 2.0f,  2.5f);
		glVertex3f( 2.5f, 2.0f, -2.5f);
		glVertex3f(-2.5f, 2.0f, -2.5f);
		
		glVertex3f(-2.5f, 3.0f,  2.5f);
		glVertex3f( 2.5f, 3.0f,  2.5f);
		glVertex3f( 2.5f, 3.0f, -2.5f);
		glVertex3f(-2.5f, 3.0f, -2.5f);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3f(-1.5f, 4.0f,  1.5f);
		glVertex3f(-1.5f, 3.0f,  1.5f);
		glVertex3f( 1.5f, 3.0f,  1.5f);
		glVertex3f( 1.5f, 4.0f,  1.5f);
		
		glVertex3f( 1.5f, 4.0f, 1.5f);
		glVertex3f( 1.5f, 3.0f, 1.5f);
		glVertex3f( 1.5f, 3.0f, -1.5f);
		glVertex3f( 1.5f, 4.0f, -1.5f);
		
		glVertex3f(-1.5f, 4.0f, 1.5f);
		glVertex3f(-1.5f, 3.0f, 1.5f);
		glVertex3f(-1.5f, 3.0f, -1.5f);
		glVertex3f(-1.5f, 4.0f, -1.5f);
		
		glVertex3f(-1.5f, 4.0f, -1.5f);
		glVertex3f(-1.5f, 3.0f, -1.5f);
		glVertex3f( 1.5f, 3.0f, -1.5f);
		glVertex3f( 1.5f, 4.0f, -1.5f);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3f(-0.5f, 5.0f,  0.5f);
		glVertex3f(-0.5f, 4.0f,  0.5f);
		glVertex3f( 0.5f, 4.0f,  0.5f);
		glVertex3f( 0.5f, 5.0f,  0.5f);
		
		glVertex3f( 0.5f, 5.0f, 0.5f);
		glVertex3f( 0.5f, 4.0f, 0.5f);
		glVertex3f( 0.5f, 4.0f, -0.5f);
		glVertex3f( 0.5f, 5.0f, -0.5f);
		
		glVertex3f(-0.5f, 5.0f, 0.5f);
		glVertex3f(-0.5f, 4.0f, 0.5f);
		glVertex3f(-0.5f, 4.0f, -0.5f);
		glVertex3f(-0.5f, 5.0f, -0.5f);
		
		glVertex3f(-0.5f, 5.0f, -0.5f);
		glVertex3f(-0.5f, 4.0f, -0.5f);
		glVertex3f( 0.5f, 4.0f, -0.5f);
		glVertex3f( 0.5f, 5.0f, -0.5f);
	glEnd();
}

void montanias(){
	//Montañas
	glColor3ub(11, 160, 29);
	glBegin (GL_POLYGON);
		glVertex3f(-135.0f, 0.0f, -125.0f);
		glVertex3f(-75.0f, 20.0f, -125.0f);
		glVertex3f(-25.0f, 20.0f, -125.0f);
		glVertex3f( 0.0f, 30.0f, -125.0f);
		glVertex3f( 50.0f, 30.0f, -125.0f);
		glVertex3f( 130.0f, 0.0f, -125.0f);
	glEnd();
	
	glBegin (GL_POLYGON);
		glVertex3f(-135.0f, 0.0f, 130.0f);
		glVertex3f(-75.0f, 20.0f, 130.0f);
		glVertex3f(-25.0f, 20.0f, 130.0f);
		glVertex3f( 0.0f, 30.0f,  130.0f);
		glVertex3f( 50.0f, 30.0f, 130.0f);
		glVertex3f( 130.0f, 0.0f, 130.0f);
	glEnd();
	
	glBegin (GL_POLYGON);
		glVertex3f(-135.0f, 0.0f, -125.0f);
		glVertex3f(-135.0f, 20.0f, -75.0f);
		glVertex3f(-135.0f, 20.0f, -25.0f);
		glVertex3f(-135.0f, 30.0f, 0.0f);
		glVertex3f(-135.0f, 30.0f, 50.0f);
		glVertex3f(-135.0f, 0.0f,  130.0f);
	glEnd();
	
	glBegin (GL_POLYGON);
		glVertex3f( 130.0f, 0.0f, -125.0f);
		glVertex3f( 130.0f, 20.0f, -75.0f);
		glVertex3f( 130.0f, 20.0f, -25.0f);
		glVertex3f( 130.0f, 30.0f, 0.0f);
		glVertex3f( 130.0f, 30.0f, 50.0f);
		glVertex3f( 130.0f, 0.0f,  130.0f);
	glEnd();
	
	//Nieve
	glColor3ub(255, 255, 255);
	glBegin (GL_POLYGON);
		glVertex3f(-85.0f, 17.0f, -124.99f);
		glVertex3f(-75.0f, 20.0f, -124.99f);
		glVertex3f(-25.0f, 20.0f, -124.99f);
		glVertex3f( 0.0f, 30.0f, -124.99f);
		glVertex3f( 50.0f, 30.0f, -124.99f);
		glVertex3f( 60.0f, 27.0f, -124.99f);
	glEnd();
	
	glBegin (GL_POLYGON);
		glVertex3f(-85.0f, 17.0f, 129.99f);
		glVertex3f(-75.0f, 20.0f, 129.99f);
		glVertex3f(-25.0f, 20.0f, 129.99f);
		glVertex3f( 0.0f, 30.0f,  129.99f);
		glVertex3f( 50.0f, 30.0f, 129.99f);
		glVertex3f( 60.0f, 27.0f, 129.99f);
	glEnd();
	
	glBegin (GL_POLYGON);
		glVertex3f(-134.99f, 17.0f, -85.0f);
		glVertex3f(-134.99f, 20.0f, -75.0f);
		glVertex3f(-134.99f, 20.0f, -25.0f);
		glVertex3f(-134.99f, 30.0f, 0.0f);
		glVertex3f(-134.99f, 30.0f, 50.0f);
		glVertex3f(-134.99f, 27.0f,  60.0f);
	glEnd();
	
	glBegin (GL_POLYGON);
		glVertex3f(129.99f, 17.0f, -85.0f);
		glVertex3f(129.99f, 20.0f, -75.0f);
		glVertex3f(129.99f, 20.0f, -25.0f);
		glVertex3f(129.99f, 30.0f, 0.0f);
		glVertex3f(129.99f, 30.0f, 50.0f);
		glVertex3f(129.99f, 27.0f,  60.0f);
	glEnd();
}

void red(int opc){
	float pi,pd,bi,bd;
	pi = pd = bi = bd = 0.0f;
	switch(opc){
		case 0:
			pi = pd = bi = bd = 0.0f;
			break;
		case 1:
			pi = bd = -45.0f;
			pd = bi =  0.0f;
			break;
		case 2:
			pi = bd =  0.0f;
			pd = bi = -45.0f;
			break;
	}
	//Cabeza
	glPushMatrix();
		glTranslatef(0.0f, 2.0f, 0.0f);
		glColor3ub(254, 240, 239);
		glBegin(GL_QUADS);
			glVertex3f(-0.375f, 0.75f,  0.0f);
			glVertex3f(-0.375f, 0.0f,  0.0f);
			glVertex3f( 0.375f, 0.0f,  0.0f);
			glVertex3f( 0.375f, 0.75f,  0.0f);
			
			glVertex3f( 0.375f, 0.75f,  0.0f);
			glVertex3f( 0.375f, 0.0f,   0.0f);
			glVertex3f( 0.375f, 0.0f,  -0.5f);
			glVertex3f( 0.375f, 0.75f, -0.5f);
			
			glVertex3f(-0.375f, 0.75f,  0.0f);
			glVertex3f(-0.375f, 0.0f,  0.0f);
			glVertex3f(-0.375f, 0.0f, -0.5f);
			glVertex3f(-0.375f, 0.75f, -0.5f);
			
			glVertex3f(-0.375f, 0.75f,  -0.5f);
			glVertex3f(-0.375f, 0.0f,  -0.5f);
			glVertex3f( 0.375f, 0.0f,  -0.5f);
			glVertex3f( 0.375f, 0.75f,  -0.5f);
		glEnd();
		
		glColor3ub(98, 96, 101);
		glBegin(GL_QUADS);
			glVertex3f(-0.375f, 0.75f,  0.0f);
			glVertex3f( 0.375f, 0.75f,  0.0f);
			glVertex3f( 0.375f, 0.75f, -0.5f);
			glVertex3f(-0.375f, 0.75f, -0.5f);
			
			glVertex3f(-0.375f, 0.75f,  -0.51f);
			glVertex3f(-0.375f, 0.25f,  -0.51f);
			glVertex3f( 0.375f, 0.25f,  -0.51f);
			glVertex3f( 0.375f, 0.75f,  -0.51f);
		glEnd();
		
		glBegin(GL_TRIANGLES);
			glVertex3f(-0.376f, 0.75f,  -0.51f);
			glVertex3f(-0.376f, 0.25f,  -0.51f);
			glVertex3f(-0.376f, 0.75f,   0.0f);
			
			glVertex3f(0.376f, 0.75f,  -0.51f);
			glVertex3f(0.376f, 0.25f,  -0.51f);
			glVertex3f(0.376f, 0.75f,   0.0f);
		glEnd();
		
		//Boca
		glColor3ub(0, 0, 0);
		glLineWidth(3);
		glBegin(GL_LINES);
			glVertex3f(-0.2f, 0.20f,  0.01f);
			glVertex3f( 0.2f, 0.20f,  0.01f);
		glEnd();
		
		//Nariz
		glLineWidth(3);
		glBegin(GL_LINES);
			glVertex3f( 0.0f, 0.50f,  0.01f);
			glVertex3f( 0.0f, 0.30f,  0.01f);
		glEnd();
		
		//Ojos
		glCircle(-0.15f, 0.5f, 0.01f, 0.05, 30);
		glCircle( 0.15f, 0.5f, 0.01f, 0.05, 30);
		
		//Gorra
		glColor3ub(206, 12, 6);
		glBegin(GL_QUADS);
			glVertex3f(-0.38f, 0.90f,  0.02f);
			glVertex3f(-0.38f, 0.60f,  0.02f);
			glVertex3f( 0.38f, 0.60f,  0.02f);
			glVertex3f( 0.38f, 0.90f,  0.02f);
			
			glVertex3f( 0.38f, 0.90f,  0.02f);
			glVertex3f( 0.38f, 0.60f,  0.02f);
			glVertex3f( 0.38f, 0.60f, -0.52f);
			glVertex3f( 0.38f, 0.90f, -0.52f);
			
			glVertex3f(-0.38f, 0.90f,  0.02f);
			glVertex3f(-0.38f, 0.60f,  0.02f);
			glVertex3f(-0.38f, 0.60f, -0.52f);
			glVertex3f(-0.38f, 0.90f, -0.52f);
			
			glVertex3f(-0.38f, 0.90f,  -0.52f);
			glVertex3f(-0.38f, 0.60f,  -0.52f);
			glVertex3f( 0.38f, 0.60f,  -0.52f);
			glVertex3f( 0.38f, 0.90f,  -0.52f);
			
			glVertex3f(-0.38f, 0.90f,  0.02f);
			glVertex3f( 0.38f, 0.90f,  0.02f);
			glVertex3f( 0.38f, 0.90f, -0.52f);
			glVertex3f(-0.38f, 0.90f, -0.52f);
		glEnd();
		
		glColor3ub(255, 255, 255);
		glBegin (GL_POLYGON);
			glVertex3f(-0.38f, 0.60f,  0.02f);
			glVertex3f(-0.15f, 0.60f,  0.22f);
			glVertex3f( 0.0f,  0.60f,  0.42f);
			glVertex3f( 0.15f, 0.60f,  0.22f);
			glVertex3f( 0.38f, 0.60f,  0.02f);
		glEnd();
		
		glCircleM2(0.0f, 0.70f, 0.03f, 0.2, 30);
		
		glColor3ub(206, 12, 6);
		glCircleM2(0.0f, 0.70f, 0.04f, 0.1, 30);
	glPopMatrix();
	
	//Cuerpo
	glPushMatrix();
		glTranslatef(0.0f, 1.0f, 0.0f);
		glScalef(1.0f, 0.5f, 1.0f);
		glColor3ub(206, 12, 6);
		glBegin(GL_QUADS);
			glVertex3f(-0.5f, 2.0f,  0.0f);
			glVertex3f(-0.5f, 0.0f,  0.0f);
			glVertex3f( 0.5f, 0.0f,  0.0f);
			glVertex3f( 0.5f, 2.0f,  0.0f);
			
			glVertex3f( 0.5f, 2.0f,  0.0f);
			glVertex3f( 0.5f, 0.0f,  0.0f);
			glVertex3f( 0.5f, 0.0f, -0.5f);
			glVertex3f( 0.5f, 2.0f, -0.5f);
			
			glVertex3f(-0.5f, 2.0f,  0.0f);
			glVertex3f(-0.5f, 0.0f,  0.0f);
			glVertex3f(-0.5f, 0.0f, -0.5f);
			glVertex3f(-0.5f, 2.0f, -0.5f);
			
			glVertex3f(-0.5f, 2.0f,  -0.5f);
			glVertex3f(-0.5f, 0.0f,  -0.5f);
			glVertex3f( 0.5f, 0.0f,  -0.5f);
			glVertex3f( 0.5f, 2.0f,  -0.5f);
			
			glVertex3f(-0.5f, 2.0f,  0.0f);
			glVertex3f( 0.5f, 2.0f,  0.0f);
			glVertex3f( 0.5f, 2.0f, -0.5f);
			glVertex3f(-0.5f, 2.0f, -0.5f);
		glEnd();
		
		glColor3ub(123, 226, 230);
		glBegin(GL_QUADS);
			glVertex3f(-0.5f, 0.0f,  0.0f);
			glVertex3f(-0.5f, 0.0f, -0.5f);
			glVertex3f( 0.5f, 0.0f, -0.5f);
			glVertex3f( 0.5f, 0.0f,  0.0f);
		glEnd();
		
		glColor3ub(255, 255, 255);
		glBegin(GL_QUADS);
			glVertex3f(-0.15f, 1.25f, 0.01f);
			glVertex3f(-0.15f, 0.0f, 0.01f);
			glVertex3f( 0.15f, 0.0f, 0.01f);
			glVertex3f( 0.15f, 1.25f, 0.01f);
		glEnd();
		
		glBegin (GL_POLYGON);
			glVertex3f(-0.15f, 1.25f, 0.01f);
			glVertex3f(-0.45f,  2.0f, 0.01f);
			glVertex3f( 0.45f,  2.0f, 0.01f);
			glVertex3f( 0.15f, 1.25f, 0.01f);
		glEnd();
		
		glColor3ub(0, 0, 0);
		glBegin(GL_TRIANGLES);
			glVertex3f(-0.25f, 2.0f, 0.02f);
			glVertex3f( 0.0f,  1.5f, 0.02f);
			glVertex3f( 0.25f, 2.0f, 0.02f);
		glEnd();
		
		glLineWidth(5);
		glBegin(GL_LINES);
			glVertex3f(0.0f, 2.0f, 0.02f);
			glVertex3f(0.0f, 0.0f, 0.02f);
		glEnd();
		
		glColor3ub(0, 0, 0);
		glBegin(GL_QUADS);
			glVertex3f(-0.52f, 0.1f,  0.02f);
			glVertex3f(-0.52f, 0.0f,  0.02f);
			glVertex3f( 0.52f, 0.0f,  0.02f);
			glVertex3f( 0.52f, 0.1f,  0.02f);
			
			glVertex3f( 0.52f, 0.1f,  0.02f);
			glVertex3f( 0.52f, 0.0f,  0.02f);
			glVertex3f( 0.52f, 0.0f, -0.52f);
			glVertex3f( 0.52f, 0.1f, -0.52f);
			
			glVertex3f(-0.52f, 0.1f,  0.02f);
			glVertex3f(-0.52f, 0.0f,  0.02f);
			glVertex3f(-0.52f, 0.0f, -0.52f);
			glVertex3f(-0.52f, 0.1f, -0.52f);
			
			glVertex3f(-0.52f, 0.1f,  -0.52f);
			glVertex3f(-0.52f, 0.0f,  -0.52f);
			glVertex3f( 0.52f, 0.0f,  -0.52f);
			glVertex3f( 0.52f, 0.1f,  -0.52f);
		glEnd();
		
		//Entre Pierna
		glColor3ub(123, 226, 230);
		glBegin (GL_POLYGON);
			glVertex3f(-0.52f, 0.0f,  0.0f);
			glVertex3f(-0.2f, -0.5f, 0.0f);
			glVertex3f( 0.2f, -0.5f, 0.0f);
			glVertex3f( 0.52f, 0.0f,  0.0f);
		glEnd();
		
		glBegin (GL_POLYGON);
			glVertex3f(-0.52f, 0.0f, -0.5f);
			glVertex3f(-0.2f, -0.5f, -0.5f);
			glVertex3f( 0.2f, -0.5f, -0.5f);
			glVertex3f( 0.52f, 0.0f, -0.5f);
		glEnd();
		
		//Mochila
		glColor3ub(243, 240, 134);
		glBegin(GL_POLYGON);
			glVertex3f(-0.3f, 2.0f,  -0.51f);
			glVertex3f(-0.5f, 1.5f,  -0.51f);
			
			glVertex3f(-0.5f, 0.5f,  -0.51f);
			glVertex3f(-0.3f, 0.0f,  -0.51f);
			
			glVertex3f( 0.3f, 0.0f,  -0.51f);
			glVertex3f( 0.5f, 0.5f,  -0.51f);
			
			glVertex3f( 0.5f, 1.5f,  -0.51f);
			glVertex3f( 0.3f, 2.0f,  -0.51f);
		glEnd();
		
		glLineWidth(5);
		glColor3ub(0, 0, 0);
		glBegin(GL_LINES);
			glVertex3f(-0.5f, 1.5f,  -0.52f);
			glVertex3f(-0.2f, 1.3f,  -0.52f);
			
			glVertex3f(-0.2f, 1.3f,  -0.52f);
			glVertex3f( 0.2f, 1.3f,  -0.52f);
			
			glVertex3f( 0.2f, 1.3f,  -0.52f);
			glVertex3f( 0.5f, 1.5f,  -0.52f);
		glEnd();
		glCircle( 0.0f, 1.45f,  -0.52f, 0.1, 20);
	glPopMatrix();
	
	//Pierna Izquierda
	glPushMatrix();
		glTranslatef(-0.25f, 1.0f, -0.25f);
		glRotatef(pi, 1.0f, 0.0f,0.0f);
		glColor3ub(123, 226, 230);
		glBegin(GL_QUADS);
			glVertex3f(-0.150f, 0.0f,  0.25f);
			glVertex3f(-0.150f,-1.0f,  0.25f);
			glVertex3f( 0.150f,-1.0f,  0.25f);
			glVertex3f( 0.150f, 0.0f,  0.25f);
			
			glVertex3f( 0.150f, 0.0f,  0.25f);
			glVertex3f( 0.150f,-1.0f,  0.25f);
			glVertex3f( 0.150f,-1.0f, -0.25f);
			glVertex3f( 0.150f, 0.0f, -0.25f);
			
			glVertex3f(-0.150f, 0.0f,  0.25f);
			glVertex3f(-0.150f,-1.0f,  0.25f);
			glVertex3f(-0.150f,-1.0f, -0.25f);
			glVertex3f(-0.150f, 0.0f, -0.25f);
			
			glVertex3f(-0.150f, 0.0f, -0.25f);
			glVertex3f(-0.150f,-1.0f, -0.25f);
			glVertex3f( 0.150f,-1.0f, -0.25f);
			glVertex3f( 0.150f, 0.0f, -0.25f);
		glEnd();
		
		glColor3ub(66, 78, 88);
		glBegin(GL_QUADS);
			glVertex3f(-0.150f, -0.80f, 0.251f);
			glVertex3f(-0.150f, -1.0f,  0.251f);
			glVertex3f( 0.150f, -1.0f,  0.251f);
			glVertex3f( 0.150f, -0.80f, 0.251f);
			
			glVertex3f( 0.151f, -0.80f, 0.251f);
			glVertex3f( 0.151f, -1.0f,  0.251f);
			glVertex3f( 0.151f, -1.0f, -0.251f);
			glVertex3f( 0.151f, -0.80f,-0.251f);
			
			glVertex3f(-0.151f, -0.80f, 0.251f);
			glVertex3f(-0.151f, -1.0f,  0.251f);
			glVertex3f(-0.151f, -1.0f, -0.251f);
			glVertex3f(-0.151f, -0.80f,-0.251f);
			
			glVertex3f(-0.150f, -0.80f, -0.251f);
			glVertex3f(-0.150f, -1.0f,  -0.251f);
			glVertex3f( 0.150f, -1.0f,  -0.251f);
			glVertex3f( 0.150f, -0.80f, -0.251f);
			
			glVertex3f(-0.150f, -1.0f,  0.251f);
			glVertex3f( 0.150f, -1.0f,  0.251f);
			glVertex3f( 0.150f, -1.0f, -0.251f);
			glVertex3f(-0.150f, -1.0f, -0.251f);
		glEnd();
	glPopMatrix();
	
	//Pierna Derecha
	glPushMatrix();
		glTranslatef( 0.25f, 1.0f, -0.25f);
		glRotatef(pd, 1.0f, 0.0f,0.0f);
		glColor3ub(123, 226, 230);
		glBegin(GL_QUADS);
			glVertex3f(-0.150f, 0.0f,  0.25f);
			glVertex3f(-0.150f,-1.0f,  0.25f);
			glVertex3f( 0.150f,-1.0f,  0.25f);
			glVertex3f( 0.150f, 0.0f,  0.25f);
			
			glVertex3f( 0.150f, 0.0f,  0.25f);
			glVertex3f( 0.150f,-1.0f,  0.25f);
			glVertex3f( 0.150f,-1.0f, -0.25f);
			glVertex3f( 0.150f, 0.0f, -0.25f);
			
			glVertex3f(-0.150f, 0.0f,  0.25f);
			glVertex3f(-0.150f,-1.0f,  0.25f);
			glVertex3f(-0.150f,-1.0f, -0.25f);
			glVertex3f(-0.150f, 0.0f, -0.25f);
			
			glVertex3f(-0.150f, 0.0f, -0.25f);
			glVertex3f(-0.150f,-1.0f, -0.25f);
			glVertex3f( 0.150f,-1.0f, -0.25f);
			glVertex3f( 0.150f, 0.0f, -0.25f);
		glEnd();
		
		glColor3ub(66, 78, 88);
		glBegin(GL_QUADS);
			glVertex3f(-0.150f, -0.80f, 0.251f);
			glVertex3f(-0.150f, -1.0f,  0.251f);
			glVertex3f( 0.150f, -1.0f,  0.251f);
			glVertex3f( 0.150f, -0.80f, 0.251f);
			
			glVertex3f( 0.151f, -0.80f, 0.251f);
			glVertex3f( 0.151f, -1.0f,  0.251f);
			glVertex3f( 0.151f, -1.0f, -0.251f);
			glVertex3f( 0.151f, -0.80f,-0.251f);
			
			glVertex3f(-0.151f, -0.80f, 0.251f);
			glVertex3f(-0.151f, -1.0f,  0.251f);
			glVertex3f(-0.151f, -1.0f, -0.251f);
			glVertex3f(-0.151f, -0.80f,-0.251f);
			
			glVertex3f(-0.150f, -0.80f, -0.251f);
			glVertex3f(-0.150f, -1.0f,  -0.251f);
			glVertex3f( 0.150f, -1.0f,  -0.251f);
			glVertex3f( 0.150f, -0.80f, -0.251f);
			
			glVertex3f(-0.150f, -1.0f,  0.251f);
			glVertex3f( 0.150f, -1.0f,  0.251f);
			glVertex3f( 0.150f, -1.0f, -0.251f);
			glVertex3f(-0.150f, -1.0f, -0.251f);
		glEnd();
	glPopMatrix();
	
	//Brazo Izqierdo
	glPushMatrix();
		glTranslatef(-0.65f, 2.0f, -0.25f);
		glRotatef(bi, 1.0f, 0.0f,0.0f);
		glColor3ub(254, 240, 239);
		glBegin(GL_QUADS);
			glVertex3f(-0.15f, 0.0f,  0.25f);
			glVertex3f(-0.15f,-1.0f,  0.25f);
			glVertex3f( 0.15f,-1.0f,  0.25f);
			glVertex3f( 0.15f, 0.0f,  0.25f);
			
			glVertex3f( 0.15f, 0.0f,  0.25f);
			glVertex3f( 0.15f,-1.0f,  0.25f);
			glVertex3f( 0.15f,-1.0f, -0.25f);
			glVertex3f( 0.15f, 0.0f, -0.25f);
			
			glVertex3f(-0.15f, 0.0f,  0.25f);
			glVertex3f(-0.15f,-1.0f,  0.25f);
			glVertex3f(-0.15f,-1.0f, -0.25f);
			glVertex3f(-0.15f, 0.0f, -0.25f);
			
			glVertex3f(-0.15f, 0.0f, -0.25f);
			glVertex3f(-0.15f,-1.0f, -0.25f);
			glVertex3f( 0.15f,-1.0f, -0.25f);
			glVertex3f( 0.15f, 0.0f, -0.25f);
			
			glVertex3f(-0.15f,-1.0f,  0.25f);
			glVertex3f( 0.15f,-1.0f,  0.25f);
			glVertex3f( 0.15f,-1.0f, -0.25f);
			glVertex3f(-0.15f,-1.0f, -0.25f);
		glEnd();
		
		glColor3ub(0, 0, 0);
		glBegin(GL_QUADS);
			glVertex3f(-0.151f, 0.0f,  0.251f);
			glVertex3f(-0.151f,-0.5f,  0.251f);
			glVertex3f( 0.151f,-0.5f,  0.251f);
			glVertex3f( 0.151f, 0.0f,  0.251f);
			
			glVertex3f( 0.151f, 0.0f,  0.251f);
			glVertex3f( 0.151f,-0.5f,  0.251f);
			glVertex3f( 0.151f,-0.5f, -0.251f);
			glVertex3f( 0.151f, 0.0f, -0.251f);
			
			glVertex3f(-0.151f, 0.0f,  0.251f);
			glVertex3f(-0.151f,-0.5f,  0.251f);
			glVertex3f(-0.151f,-0.5f, -0.251f);
			glVertex3f(-0.151f, 0.0f, -0.251f);
			
			glVertex3f(-0.151f, 0.0f, -0.251f);
			glVertex3f(-0.151f,-0.5f, -0.251f);
			glVertex3f( 0.151f,-0.5f, -0.251f);
			glVertex3f( 0.151f, 0.0f, -0.251f);
			
			glVertex3f(-0.151f, 0.0f,  0.251f);
			glVertex3f( 0.151f, 0.0f,  0.251f);
			glVertex3f( 0.151f, 0.0f, -0.251f);
			glVertex3f(-0.151f, 0.0f, -0.251f);
		glEnd();
		
		glBegin(GL_QUADS);
			glVertex3f(-0.151f,-0.8f,  0.251f);
			glVertex3f(-0.151f,-0.9f,  0.251f);
			glVertex3f( 0.151f,-0.9f,  0.251f);
			glVertex3f( 0.151f,-0.8f,  0.251f);
			
			glVertex3f( 0.151f,-0.8f,  0.251f);
			glVertex3f( 0.151f,-0.9f,  0.251f);
			glVertex3f( 0.151f,-0.9f, -0.251f);
			glVertex3f( 0.151f,-0.8f, -0.251f);
			
			glVertex3f(-0.151f,-0.8f,  0.251f);
			glVertex3f(-0.151f,-0.9f,  0.251f);
			glVertex3f(-0.151f,-0.9f, -0.251f);
			glVertex3f(-0.151f,-0.8f, -0.251f);
			
			glVertex3f(-0.151f,-0.8f, -0.251f);
			glVertex3f(-0.151f,-0.9f, -0.251f);
			glVertex3f( 0.151f,-0.9f, -0.251f);
			glVertex3f( 0.151f,-0.8f, -0.251f);
		glEnd();
	glPopMatrix();
	
	//Brazo Derecho
	glPushMatrix();
		glTranslatef(0.65f, 2.0f, -0.25f);
		glRotatef(bd, 1.0f, 0.0f,0.0f);
		glColor3ub(254, 240, 239);
		glBegin(GL_QUADS);
			glVertex3f(-0.15f, 0.0f,  0.25f);
			glVertex3f(-0.15f,-1.0f,  0.25f);
			glVertex3f( 0.15f,-1.0f,  0.25f);
			glVertex3f( 0.15f, 0.0f,  0.25f);
			
			glVertex3f( 0.15f, 0.0f,  0.25f);
			glVertex3f( 0.15f,-1.0f,  0.25f);
			glVertex3f( 0.15f,-1.0f, -0.25f);
			glVertex3f( 0.15f, 0.0f, -0.25f);
			
			glVertex3f(-0.15f, 0.0f,  0.25f);
			glVertex3f(-0.15f,-1.0f,  0.25f);
			glVertex3f(-0.15f,-1.0f, -0.25f);
			glVertex3f(-0.15f, 0.0f, -0.25f);
			
			glVertex3f(-0.15f, 0.0f, -0.25f);
			glVertex3f(-0.15f,-1.0f, -0.25f);
			glVertex3f( 0.15f,-1.0f, -0.25f);
			glVertex3f( 0.15f, 0.0f, -0.25f);
			
			glVertex3f(-0.15f,-1.0f,  0.25f);
			glVertex3f( 0.15f,-1.0f,  0.25f);
			glVertex3f( 0.15f,-1.0f, -0.25f);
			glVertex3f(-0.15f,-1.0f, -0.25f);
		glEnd();
		
		glColor3ub(0, 0, 0);
		glBegin(GL_QUADS);
			glVertex3f(-0.151f, 0.0f,  0.251f);
			glVertex3f(-0.151f,-0.5f,  0.251f);
			glVertex3f( 0.151f,-0.5f,  0.251f);
			glVertex3f( 0.151f, 0.0f,  0.251f);
			
			glVertex3f( 0.151f, 0.0f,  0.251f);
			glVertex3f( 0.151f,-0.5f,  0.251f);
			glVertex3f( 0.151f,-0.5f, -0.251f);
			glVertex3f( 0.151f, 0.0f, -0.251f);
			
			glVertex3f(-0.151f, 0.0f,  0.251f);
			glVertex3f(-0.151f,-0.5f,  0.251f);
			glVertex3f(-0.151f,-0.5f, -0.251f);
			glVertex3f(-0.151f, 0.0f, -0.251f);
			
			glVertex3f(-0.151f, 0.0f, -0.251f);
			glVertex3f(-0.151f,-0.5f, -0.251f);
			glVertex3f( 0.151f,-0.5f, -0.251f);
			glVertex3f( 0.151f, 0.0f, -0.251f);
			
			glVertex3f(-0.151f, 0.0f,  0.251f);
			glVertex3f( 0.151f, 0.0f,  0.251f);
			glVertex3f( 0.151f, 0.0f, -0.251f);
			glVertex3f(-0.151f, 0.0f, -0.251f);
		glEnd();
		
		glBegin(GL_QUADS);
			glVertex3f(-0.151f,-0.8f,  0.251f);
			glVertex3f(-0.151f,-0.9f,  0.251f);
			glVertex3f( 0.151f,-0.9f,  0.251f);
			glVertex3f( 0.151f,-0.8f,  0.251f);
			
			glVertex3f( 0.151f,-0.8f,  0.251f);
			glVertex3f( 0.151f,-0.9f,  0.251f);
			glVertex3f( 0.151f,-0.9f, -0.251f);
			glVertex3f( 0.151f,-0.8f, -0.251f);
			
			glVertex3f(-0.151f,-0.8f,  0.251f);
			glVertex3f(-0.151f,-0.9f,  0.251f);
			glVertex3f(-0.151f,-0.9f, -0.251f);
			glVertex3f(-0.151f,-0.8f, -0.251f);
			
			glVertex3f(-0.151f,-0.8f, -0.251f);
			glVertex3f(-0.151f,-0.9f, -0.251f);
			glVertex3f( 0.151f,-0.9f, -0.251f);
			glVertex3f( 0.151f,-0.8f, -0.251f);
		glEnd();
	glPopMatrix();
	
	waitKey(70);
}

void redReta(){
	//Cabeza
	glPushMatrix();
		glTranslatef(0.0f, 2.0f, 0.0f);
		glColor3ub(254, 240, 239);
		glBegin(GL_QUADS);
			glVertex3f(-0.375f, 0.75f,  0.0f);
			glVertex3f(-0.375f, 0.0f,  0.0f);
			glVertex3f( 0.375f, 0.0f,  0.0f);
			glVertex3f( 0.375f, 0.75f,  0.0f);
			
			glVertex3f( 0.375f, 0.75f,  0.0f);
			glVertex3f( 0.375f, 0.0f,   0.0f);
			glVertex3f( 0.375f, 0.0f,  -0.5f);
			glVertex3f( 0.375f, 0.75f, -0.5f);
			
			glVertex3f(-0.375f, 0.75f,  0.0f);
			glVertex3f(-0.375f, 0.0f,  0.0f);
			glVertex3f(-0.375f, 0.0f, -0.5f);
			glVertex3f(-0.375f, 0.75f, -0.5f);
			
			glVertex3f(-0.375f, 0.75f,  -0.5f);
			glVertex3f(-0.375f, 0.0f,  -0.5f);
			glVertex3f( 0.375f, 0.0f,  -0.5f);
			glVertex3f( 0.375f, 0.75f,  -0.5f);
		glEnd();
		
		glColor3ub(98, 96, 101);
		glBegin(GL_QUADS);
			glVertex3f(-0.375f, 0.75f,  0.0f);
			glVertex3f( 0.375f, 0.75f,  0.0f);
			glVertex3f( 0.375f, 0.75f, -0.5f);
			glVertex3f(-0.375f, 0.75f, -0.5f);
			
			glVertex3f(-0.375f, 0.75f,  -0.51f);
			glVertex3f(-0.375f, 0.25f,  -0.51f);
			glVertex3f( 0.375f, 0.25f,  -0.51f);
			glVertex3f( 0.375f, 0.75f,  -0.51f);
		glEnd();
		
		glBegin(GL_TRIANGLES);
			glVertex3f(-0.376f, 0.75f,  -0.51f);
			glVertex3f(-0.376f, 0.25f,  -0.51f);
			glVertex3f(-0.376f, 0.75f,   0.0f);
			
			glVertex3f(0.376f, 0.75f,  -0.51f);
			glVertex3f(0.376f, 0.25f,  -0.51f);
			glVertex3f(0.376f, 0.75f,   0.0f);
		glEnd();
		
		//Boca
		glColor3ub(0, 0, 0);
		glLineWidth(3);
		glBegin(GL_LINES);
			glVertex3f(-0.2f, 0.20f,  0.01f);
			glVertex3f( 0.2f, 0.20f,  0.01f);
		glEnd();
		
		//Nariz
		glLineWidth(3);
		glBegin(GL_LINES);
			glVertex3f( 0.0f, 0.50f,  0.01f);
			glVertex3f( 0.0f, 0.30f,  0.01f);
		glEnd();
		
		//Ojos
		glCircle(-0.15f, 0.5f, 0.01f, 0.05, 30);
		glCircle( 0.15f, 0.5f, 0.01f, 0.05, 30);
		
		//Gorra
		glColor3ub(206, 12, 6);
		glBegin(GL_QUADS);
			glVertex3f(-0.38f, 0.90f,  0.02f);
			glVertex3f(-0.38f, 0.60f,  0.02f);
			glVertex3f( 0.38f, 0.60f,  0.02f);
			glVertex3f( 0.38f, 0.90f,  0.02f);
			
			glVertex3f( 0.38f, 0.90f,  0.02f);
			glVertex3f( 0.38f, 0.60f,  0.02f);
			glVertex3f( 0.38f, 0.60f, -0.52f);
			glVertex3f( 0.38f, 0.90f, -0.52f);
			
			glVertex3f(-0.38f, 0.90f,  0.02f);
			glVertex3f(-0.38f, 0.60f,  0.02f);
			glVertex3f(-0.38f, 0.60f, -0.52f);
			glVertex3f(-0.38f, 0.90f, -0.52f);
			
			glVertex3f(-0.38f, 0.90f,  -0.52f);
			glVertex3f(-0.38f, 0.60f,  -0.52f);
			glVertex3f( 0.38f, 0.60f,  -0.52f);
			glVertex3f( 0.38f, 0.90f,  -0.52f);
			
			glVertex3f(-0.38f, 0.90f,  0.02f);
			glVertex3f( 0.38f, 0.90f,  0.02f);
			glVertex3f( 0.38f, 0.90f, -0.52f);
			glVertex3f(-0.38f, 0.90f, -0.52f);
		glEnd();
		
		glColor3ub(255, 255, 255);
		glBegin (GL_POLYGON);
			glVertex3f(-0.38f, 0.60f,  0.02f);
			glVertex3f(-0.15f, 0.60f,  0.22f);
			glVertex3f( 0.0f,  0.60f,  0.42f);
			glVertex3f( 0.15f, 0.60f,  0.22f);
			glVertex3f( 0.38f, 0.60f,  0.02f);
		glEnd();
		
		glCircleM2(0.0f, 0.70f, 0.03f, 0.2, 30);
		
		glColor3ub(206, 12, 6);
		glCircleM2(0.0f, 0.70f, 0.04f, 0.1, 30);
	glPopMatrix();
	
	//Cuerpo
	glPushMatrix();
		glTranslatef(0.0f, 1.0f, 0.0f);
		glScalef(1.0f, 0.5f, 1.0f);
		glColor3ub(206, 12, 6);
		glBegin(GL_QUADS);
			glVertex3f(-0.5f, 2.0f,  0.0f);
			glVertex3f(-0.5f, 0.0f,  0.0f);
			glVertex3f( 0.5f, 0.0f,  0.0f);
			glVertex3f( 0.5f, 2.0f,  0.0f);
			
			glVertex3f( 0.5f, 2.0f,  0.0f);
			glVertex3f( 0.5f, 0.0f,  0.0f);
			glVertex3f( 0.5f, 0.0f, -0.5f);
			glVertex3f( 0.5f, 2.0f, -0.5f);
			
			glVertex3f(-0.5f, 2.0f,  0.0f);
			glVertex3f(-0.5f, 0.0f,  0.0f);
			glVertex3f(-0.5f, 0.0f, -0.5f);
			glVertex3f(-0.5f, 2.0f, -0.5f);
			
			glVertex3f(-0.5f, 2.0f,  -0.5f);
			glVertex3f(-0.5f, 0.0f,  -0.5f);
			glVertex3f( 0.5f, 0.0f,  -0.5f);
			glVertex3f( 0.5f, 2.0f,  -0.5f);
			
			glVertex3f(-0.5f, 2.0f,  0.0f);
			glVertex3f( 0.5f, 2.0f,  0.0f);
			glVertex3f( 0.5f, 2.0f, -0.5f);
			glVertex3f(-0.5f, 2.0f, -0.5f);
		glEnd();
		
		glColor3ub(123, 226, 230);
		glBegin(GL_QUADS);
			glVertex3f(-0.5f, 0.0f,  0.0f);
			glVertex3f(-0.5f, 0.0f, -0.5f);
			glVertex3f( 0.5f, 0.0f, -0.5f);
			glVertex3f( 0.5f, 0.0f,  0.0f);
		glEnd();
		
		glColor3ub(255, 255, 255);
		glBegin(GL_QUADS);
			glVertex3f(-0.15f, 1.25f, 0.01f);
			glVertex3f(-0.15f, 0.0f, 0.01f);
			glVertex3f( 0.15f, 0.0f, 0.01f);
			glVertex3f( 0.15f, 1.25f, 0.01f);
		glEnd();
		
		glBegin (GL_POLYGON);
			glVertex3f(-0.15f, 1.25f, 0.01f);
			glVertex3f(-0.45f,  2.0f, 0.01f);
			glVertex3f( 0.45f,  2.0f, 0.01f);
			glVertex3f( 0.15f, 1.25f, 0.01f);
		glEnd();
		
		glColor3ub(0, 0, 0);
		glBegin(GL_TRIANGLES);
			glVertex3f(-0.25f, 2.0f, 0.02f);
			glVertex3f( 0.0f,  1.5f, 0.02f);
			glVertex3f( 0.25f, 2.0f, 0.02f);
		glEnd();
		
		glLineWidth(5);
		glBegin(GL_LINES);
			glVertex3f(0.0f, 2.0f, 0.02f);
			glVertex3f(0.0f, 0.0f, 0.02f);
		glEnd();
		
		glColor3ub(0, 0, 0);
		glBegin(GL_QUADS);
			glVertex3f(-0.52f, 0.1f,  0.02f);
			glVertex3f(-0.52f, 0.0f,  0.02f);
			glVertex3f( 0.52f, 0.0f,  0.02f);
			glVertex3f( 0.52f, 0.1f,  0.02f);
			
			glVertex3f( 0.52f, 0.1f,  0.02f);
			glVertex3f( 0.52f, 0.0f,  0.02f);
			glVertex3f( 0.52f, 0.0f, -0.52f);
			glVertex3f( 0.52f, 0.1f, -0.52f);
			
			glVertex3f(-0.52f, 0.1f,  0.02f);
			glVertex3f(-0.52f, 0.0f,  0.02f);
			glVertex3f(-0.52f, 0.0f, -0.52f);
			glVertex3f(-0.52f, 0.1f, -0.52f);
			
			glVertex3f(-0.52f, 0.1f,  -0.52f);
			glVertex3f(-0.52f, 0.0f,  -0.52f);
			glVertex3f( 0.52f, 0.0f,  -0.52f);
			glVertex3f( 0.52f, 0.1f,  -0.52f);
		glEnd();
		
		//Entre Pierna
		glColor3ub(123, 226, 230);
		glBegin (GL_POLYGON);
			glVertex3f(-0.52f, 0.0f,  0.0f);
			glVertex3f(-0.2f, -0.5f, 0.0f);
			glVertex3f( 0.2f, -0.5f, 0.0f);
			glVertex3f( 0.52f, 0.0f,  0.0f);
		glEnd();
		
		glBegin (GL_POLYGON);
			glVertex3f(-0.52f, 0.0f, -0.5f);
			glVertex3f(-0.2f, -0.5f, -0.5f);
			glVertex3f( 0.2f, -0.5f, -0.5f);
			glVertex3f( 0.52f, 0.0f, -0.5f);
		glEnd();
		
		//Mochila
		glColor3ub(243, 240, 134);
		glBegin(GL_POLYGON);
			glVertex3f(-0.3f, 2.0f,  -0.51f);
			glVertex3f(-0.5f, 1.5f,  -0.51f);
			
			glVertex3f(-0.5f, 0.5f,  -0.51f);
			glVertex3f(-0.3f, 0.0f,  -0.51f);
			
			glVertex3f( 0.3f, 0.0f,  -0.51f);
			glVertex3f( 0.5f, 0.5f,  -0.51f);
			
			glVertex3f( 0.5f, 1.5f,  -0.51f);
			glVertex3f( 0.3f, 2.0f,  -0.51f);
		glEnd();
		
		glLineWidth(5);
		glColor3ub(0, 0, 0);
		glBegin(GL_LINES);
			glVertex3f(-0.5f, 1.5f,  -0.52f);
			glVertex3f(-0.2f, 1.3f,  -0.52f);
			
			glVertex3f(-0.2f, 1.3f,  -0.52f);
			glVertex3f( 0.2f, 1.3f,  -0.52f);
			
			glVertex3f( 0.2f, 1.3f,  -0.52f);
			glVertex3f( 0.5f, 1.5f,  -0.52f);
		glEnd();
		glCircle( 0.0f, 1.45f,  -0.52f, 0.1, 20);
	glPopMatrix();
	
	//Pierna Izquierda
	glPushMatrix();
		glTranslatef(-0.25f, 1.0f, -0.25f);
		glColor3ub(123, 226, 230);
		glBegin(GL_QUADS);
			glVertex3f(-0.150f, 0.0f,  0.25f);
			glVertex3f(-0.150f,-1.0f,  0.25f);
			glVertex3f( 0.150f,-1.0f,  0.25f);
			glVertex3f( 0.150f, 0.0f,  0.25f);
			
			glVertex3f( 0.150f, 0.0f,  0.25f);
			glVertex3f( 0.150f,-1.0f,  0.25f);
			glVertex3f( 0.150f,-1.0f, -0.25f);
			glVertex3f( 0.150f, 0.0f, -0.25f);
			
			glVertex3f(-0.150f, 0.0f,  0.25f);
			glVertex3f(-0.150f,-1.0f,  0.25f);
			glVertex3f(-0.150f,-1.0f, -0.25f);
			glVertex3f(-0.150f, 0.0f, -0.25f);
			
			glVertex3f(-0.150f, 0.0f, -0.25f);
			glVertex3f(-0.150f,-1.0f, -0.25f);
			glVertex3f( 0.150f,-1.0f, -0.25f);
			glVertex3f( 0.150f, 0.0f, -0.25f);
		glEnd();
		
		glColor3ub(66, 78, 88);
		glBegin(GL_QUADS);
			glVertex3f(-0.150f, -0.80f, 0.251f);
			glVertex3f(-0.150f, -1.0f,  0.251f);
			glVertex3f( 0.150f, -1.0f,  0.251f);
			glVertex3f( 0.150f, -0.80f, 0.251f);
			
			glVertex3f( 0.151f, -0.80f, 0.251f);
			glVertex3f( 0.151f, -1.0f,  0.251f);
			glVertex3f( 0.151f, -1.0f, -0.251f);
			glVertex3f( 0.151f, -0.80f,-0.251f);
			
			glVertex3f(-0.151f, -0.80f, 0.251f);
			glVertex3f(-0.151f, -1.0f,  0.251f);
			glVertex3f(-0.151f, -1.0f, -0.251f);
			glVertex3f(-0.151f, -0.80f,-0.251f);
			
			glVertex3f(-0.150f, -0.80f, -0.251f);
			glVertex3f(-0.150f, -1.0f,  -0.251f);
			glVertex3f( 0.150f, -1.0f,  -0.251f);
			glVertex3f( 0.150f, -0.80f, -0.251f);
			
			glVertex3f(-0.150f, -1.0f,  0.251f);
			glVertex3f( 0.150f, -1.0f,  0.251f);
			glVertex3f( 0.150f, -1.0f, -0.251f);
			glVertex3f(-0.150f, -1.0f, -0.251f);
		glEnd();
	glPopMatrix();
	
	//Pierna Derecha
	glPushMatrix();
		glTranslatef( 0.25f, 1.0f, -0.25f);
		glColor3ub(123, 226, 230);
		glBegin(GL_QUADS);
			glVertex3f(-0.150f, 0.0f,  0.25f);
			glVertex3f(-0.150f,-1.0f,  0.25f);
			glVertex3f( 0.150f,-1.0f,  0.25f);
			glVertex3f( 0.150f, 0.0f,  0.25f);
			
			glVertex3f( 0.150f, 0.0f,  0.25f);
			glVertex3f( 0.150f,-1.0f,  0.25f);
			glVertex3f( 0.150f,-1.0f, -0.25f);
			glVertex3f( 0.150f, 0.0f, -0.25f);
			
			glVertex3f(-0.150f, 0.0f,  0.25f);
			glVertex3f(-0.150f,-1.0f,  0.25f);
			glVertex3f(-0.150f,-1.0f, -0.25f);
			glVertex3f(-0.150f, 0.0f, -0.25f);
			
			glVertex3f(-0.150f, 0.0f, -0.25f);
			glVertex3f(-0.150f,-1.0f, -0.25f);
			glVertex3f( 0.150f,-1.0f, -0.25f);
			glVertex3f( 0.150f, 0.0f, -0.25f);
		glEnd();
		
		glColor3ub(66, 78, 88);
		glBegin(GL_QUADS);
			glVertex3f(-0.150f, -0.80f, 0.251f);
			glVertex3f(-0.150f, -1.0f,  0.251f);
			glVertex3f( 0.150f, -1.0f,  0.251f);
			glVertex3f( 0.150f, -0.80f, 0.251f);
			
			glVertex3f( 0.151f, -0.80f, 0.251f);
			glVertex3f( 0.151f, -1.0f,  0.251f);
			glVertex3f( 0.151f, -1.0f, -0.251f);
			glVertex3f( 0.151f, -0.80f,-0.251f);
			
			glVertex3f(-0.151f, -0.80f, 0.251f);
			glVertex3f(-0.151f, -1.0f,  0.251f);
			glVertex3f(-0.151f, -1.0f, -0.251f);
			glVertex3f(-0.151f, -0.80f,-0.251f);
			
			glVertex3f(-0.150f, -0.80f, -0.251f);
			glVertex3f(-0.150f, -1.0f,  -0.251f);
			glVertex3f( 0.150f, -1.0f,  -0.251f);
			glVertex3f( 0.150f, -0.80f, -0.251f);
			
			glVertex3f(-0.150f, -1.0f,  0.251f);
			glVertex3f( 0.150f, -1.0f,  0.251f);
			glVertex3f( 0.150f, -1.0f, -0.251f);
			glVertex3f(-0.150f, -1.0f, -0.251f);
		glEnd();
	glPopMatrix();
	
	//Brazo Izqierdo
	glPushMatrix();
		glTranslatef(-0.65f, 2.0f, -0.25f);
		glColor3ub(254, 240, 239);
		glBegin(GL_QUADS);
			glVertex3f(-0.15f, 0.0f,  0.25f);
			glVertex3f(-0.15f,-1.0f,  0.25f);
			glVertex3f( 0.15f,-1.0f,  0.25f);
			glVertex3f( 0.15f, 0.0f,  0.25f);
			
			glVertex3f( 0.15f, 0.0f,  0.25f);
			glVertex3f( 0.15f,-1.0f,  0.25f);
			glVertex3f( 0.15f,-1.0f, -0.25f);
			glVertex3f( 0.15f, 0.0f, -0.25f);
			
			glVertex3f(-0.15f, 0.0f,  0.25f);
			glVertex3f(-0.15f,-1.0f,  0.25f);
			glVertex3f(-0.15f,-1.0f, -0.25f);
			glVertex3f(-0.15f, 0.0f, -0.25f);
			
			glVertex3f(-0.15f, 0.0f, -0.25f);
			glVertex3f(-0.15f,-1.0f, -0.25f);
			glVertex3f( 0.15f,-1.0f, -0.25f);
			glVertex3f( 0.15f, 0.0f, -0.25f);
			
			glVertex3f(-0.15f,-1.0f,  0.25f);
			glVertex3f( 0.15f,-1.0f,  0.25f);
			glVertex3f( 0.15f,-1.0f, -0.25f);
			glVertex3f(-0.15f,-1.0f, -0.25f);
		glEnd();
		
		glColor3ub(0, 0, 0);
		glBegin(GL_QUADS);
			glVertex3f(-0.151f, 0.0f,  0.251f);
			glVertex3f(-0.151f,-0.5f,  0.251f);
			glVertex3f( 0.151f,-0.5f,  0.251f);
			glVertex3f( 0.151f, 0.0f,  0.251f);
			
			glVertex3f( 0.151f, 0.0f,  0.251f);
			glVertex3f( 0.151f,-0.5f,  0.251f);
			glVertex3f( 0.151f,-0.5f, -0.251f);
			glVertex3f( 0.151f, 0.0f, -0.251f);
			
			glVertex3f(-0.151f, 0.0f,  0.251f);
			glVertex3f(-0.151f,-0.5f,  0.251f);
			glVertex3f(-0.151f,-0.5f, -0.251f);
			glVertex3f(-0.151f, 0.0f, -0.251f);
			
			glVertex3f(-0.151f, 0.0f, -0.251f);
			glVertex3f(-0.151f,-0.5f, -0.251f);
			glVertex3f( 0.151f,-0.5f, -0.251f);
			glVertex3f( 0.151f, 0.0f, -0.251f);
			
			glVertex3f(-0.151f, 0.0f,  0.251f);
			glVertex3f( 0.151f, 0.0f,  0.251f);
			glVertex3f( 0.151f, 0.0f, -0.251f);
			glVertex3f(-0.151f, 0.0f, -0.251f);
		glEnd();
		
		glBegin(GL_QUADS);
			glVertex3f(-0.151f,-0.8f,  0.251f);
			glVertex3f(-0.151f,-0.9f,  0.251f);
			glVertex3f( 0.151f,-0.9f,  0.251f);
			glVertex3f( 0.151f,-0.8f,  0.251f);
			
			glVertex3f( 0.151f,-0.8f,  0.251f);
			glVertex3f( 0.151f,-0.9f,  0.251f);
			glVertex3f( 0.151f,-0.9f, -0.251f);
			glVertex3f( 0.151f,-0.8f, -0.251f);
			
			glVertex3f(-0.151f,-0.8f,  0.251f);
			glVertex3f(-0.151f,-0.9f,  0.251f);
			glVertex3f(-0.151f,-0.9f, -0.251f);
			glVertex3f(-0.151f,-0.8f, -0.251f);
			
			glVertex3f(-0.151f,-0.8f, -0.251f);
			glVertex3f(-0.151f,-0.9f, -0.251f);
			glVertex3f( 0.151f,-0.9f, -0.251f);
			glVertex3f( 0.151f,-0.8f, -0.251f);
		glEnd();
	glPopMatrix();
	
	//Brazo Derecho
	glPushMatrix();
		glTranslatef(0.65f, 1.75f, -0.25f);
		glRotatef(-90.0f, 1.0f, 0.0f,0.0f);
		glColor3ub(254, 240, 239);
		glBegin(GL_QUADS);
			glVertex3f(-0.15f, 0.0f,  0.25f);
			glVertex3f(-0.15f,-1.0f,  0.25f);
			glVertex3f( 0.15f,-1.0f,  0.25f);
			glVertex3f( 0.15f, 0.0f,  0.25f);
			
			glVertex3f( 0.15f, 0.0f,  0.25f);
			glVertex3f( 0.15f,-1.0f,  0.25f);
			glVertex3f( 0.15f,-1.0f, -0.25f);
			glVertex3f( 0.15f, 0.0f, -0.25f);
			
			glVertex3f(-0.15f, 0.0f,  0.25f);
			glVertex3f(-0.15f,-1.0f,  0.25f);
			glVertex3f(-0.15f,-1.0f, -0.25f);
			glVertex3f(-0.15f, 0.0f, -0.25f);
			
			glVertex3f(-0.15f, 0.0f, -0.25f);
			glVertex3f(-0.15f,-1.0f, -0.25f);
			glVertex3f( 0.15f,-1.0f, -0.25f);
			glVertex3f( 0.15f, 0.0f, -0.25f);
			
			glVertex3f(-0.15f,-1.0f,  0.25f);
			glVertex3f( 0.15f,-1.0f,  0.25f);
			glVertex3f( 0.15f,-1.0f, -0.25f);
			glVertex3f(-0.15f,-1.0f, -0.25f);
		glEnd();
		
		glColor3ub(0, 0, 0);
		glBegin(GL_QUADS);
			glVertex3f(-0.151f, 0.0f,  0.251f);
			glVertex3f(-0.151f,-0.5f,  0.251f);
			glVertex3f( 0.151f,-0.5f,  0.251f);
			glVertex3f( 0.151f, 0.0f,  0.251f);
			
			glVertex3f( 0.151f, 0.0f,  0.251f);
			glVertex3f( 0.151f,-0.5f,  0.251f);
			glVertex3f( 0.151f,-0.5f, -0.251f);
			glVertex3f( 0.151f, 0.0f, -0.251f);
			
			glVertex3f(-0.151f, 0.0f,  0.251f);
			glVertex3f(-0.151f,-0.5f,  0.251f);
			glVertex3f(-0.151f,-0.5f, -0.251f);
			glVertex3f(-0.151f, 0.0f, -0.251f);
			
			glVertex3f(-0.151f, 0.0f, -0.251f);
			glVertex3f(-0.151f,-0.5f, -0.251f);
			glVertex3f( 0.151f,-0.5f, -0.251f);
			glVertex3f( 0.151f, 0.0f, -0.251f);
			
			glVertex3f(-0.151f, 0.0f,  0.251f);
			glVertex3f( 0.151f, 0.0f,  0.251f);
			glVertex3f( 0.151f, 0.0f, -0.251f);
			glVertex3f(-0.151f, 0.0f, -0.251f);
		glEnd();
		
		glBegin(GL_QUADS);
			glVertex3f(-0.151f,-0.8f,  0.251f);
			glVertex3f(-0.151f,-0.9f,  0.251f);
			glVertex3f( 0.151f,-0.9f,  0.251f);
			glVertex3f( 0.151f,-0.8f,  0.251f);
			
			glVertex3f( 0.151f,-0.8f,  0.251f);
			glVertex3f( 0.151f,-0.9f,  0.251f);
			glVertex3f( 0.151f,-0.9f, -0.251f);
			glVertex3f( 0.151f,-0.8f, -0.251f);
			
			glVertex3f(-0.151f,-0.8f,  0.251f);
			glVertex3f(-0.151f,-0.9f,  0.251f);
			glVertex3f(-0.151f,-0.9f, -0.251f);
			glVertex3f(-0.151f,-0.8f, -0.251f);
			
			glVertex3f(-0.151f,-0.8f, -0.251f);
			glVertex3f(-0.151f,-0.9f, -0.251f);
			glVertex3f( 0.151f,-0.9f, -0.251f);
			glVertex3f( 0.151f,-0.8f, -0.251f);
		glEnd();
		
		glRotatef(90.0f, 1.0f, 0.0f,0.0f);
		glTranslatef(0.0f, -3.75f, 1.0f);
		glColor3ub(255,0,0);
		glCircle(0,3.75,0.01,0.2,30);
		glColor3ub(255,255,255);
		glCircleM(0,3.75,0.02,0.2,30);
		glColor3ub(0,0,0);
		glCircle(0,3.75,0.03,0.1,30);
		glColor3ub(255,255,255);
		glCircle(0,3.75,0.04,0.05,30);
	glPopMatrix();
}
