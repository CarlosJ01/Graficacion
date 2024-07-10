#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

# define PI           3.14159265358979323846
using namespace std;
void drawSnowMan() {

	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0.0f ,0.75f, 0.0f);
	glutSolidSphere(0.75f,20,20);
	glTranslatef(0.0f, 1.0f, 0.0f);
	glutSolidSphere(0.25f,20,20);
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0.05f, 0.10f, 0.18f);
	glutSolidSphere(0.05f,10,10);
	glTranslatef(-0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.05f,10,10);
	glPopMatrix();

	glColor3f(1.0f, 0.5f , 0.5f);
	glutSolidCone(0.08f,0.5f,10,2);
}

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
		glVertex3f(-1.3f ,0.0f, 0.1f);
		glVertex3f(-1.3f ,2.3f, 0.1f);
		glVertex3f(-0.8f ,2.8f, 0.1f);
		glVertex3f( 0.8f ,2.8f, 0.1f);
		glVertex3f( 1.3f ,2.3f, 0.1f);
		glVertex3f( 1.3f ,0.0f, 0.1f);
	glEnd ();
	
	glColor3ub(22,229,239);
	glBegin (GL_POLYGON);
		glVertex3f(-1.0f ,0.0f, 0.3f);
		glVertex3f(-1.0f ,2.0f, 0.3f);
		glVertex3f(-0.5f ,2.5f, 0.3f);
		glVertex3f( 0.5f ,2.5f, 0.3f);
		glVertex3f( 1.0f ,2.0f, 0.3f);
		glVertex3f( 1.0f ,0.0f, 0.3f);
	glEnd ();
	
	glColor3ub(0,0,0);
	glBegin(GL_LINES);
		glVertex3f(0.0f ,2.5f, 0.31f);
		glVertex3f(0.0f ,0.0f, 0.31f);
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
		glVertex3f(-1.3f ,0.0f, 0.1f);
		glVertex3f(-1.3f ,2.3f, 0.1f);
		glVertex3f(-0.8f ,2.8f, 0.1f);
		glVertex3f( 0.8f ,2.8f, 0.1f);
		glVertex3f( 1.3f ,2.3f, 0.1f);
		glVertex3f( 1.3f ,0.0f, 0.1f);
	glEnd ();
	
	glColor3ub(22,229,239);
	glBegin (GL_POLYGON);
		glVertex3f(-1.0f ,0.0f, 0.3f);
		glVertex3f(-1.0f ,2.0f, 0.3f);
		glVertex3f(-0.5f ,2.5f, 0.3f);
		glVertex3f( 0.5f ,2.5f, 0.3f);
		glVertex3f( 1.0f ,2.0f, 0.3f);
		glVertex3f( 1.0f ,0.0f, 0.3f);
	glEnd ();
	
	glColor3ub(0,0,0);
	glBegin(GL_LINES);
		glVertex3f(0.0f ,2.5f, 0.31f);
		glVertex3f(0.0f ,0.0f, 0.31f);
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
	glScalef(3.0f, 2.0f, 3.0f);
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
			glVertex3f(-1.3f ,0.0f, 0.1f);
			glVertex3f(-1.3f ,2.3f, 0.1f);
			glVertex3f(-0.8f ,2.8f, 0.1f);
			glVertex3f( 0.8f ,2.8f, 0.1f);
			glVertex3f( 1.3f ,2.3f, 0.1f);
			glVertex3f( 1.3f ,0.0f, 0.1f);
		glEnd ();
		
		glColor3ub(22,229,239);
		glBegin (GL_POLYGON);
			glVertex3f(-1.0f ,0.0f, 0.3f);
			glVertex3f(-1.0f ,2.0f, 0.3f);
			glVertex3f(-0.5f ,2.5f, 0.3f);
			glVertex3f( 0.5f ,2.5f, 0.3f);
			glVertex3f( 1.0f ,2.0f, 0.3f);
			glVertex3f( 1.0f ,0.0f, 0.3f);
		glEnd ();
		
		glColor3ub(0,0,0);
		glBegin(GL_LINES);
			glVertex3f(0.0f ,2.5f, 0.31f);
			glVertex3f(0.0f ,0.0f, 0.31f);
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
