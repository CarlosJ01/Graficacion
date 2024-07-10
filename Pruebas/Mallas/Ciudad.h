#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#include "Modelos.h"

# define PI           3.14159265358979323846
using namespace std;

void ciudad(){
	glColor3ub(215, 219, 221);
	glBegin(GL_QUADS);
		glVertex3f(-100.0f, -0.1f, -100.0f);
		glVertex3f(-100.0f, -0.1f,  100.0f);
		glVertex3f( 100.0f, -0.1f,  100.0f);
		glVertex3f( 100.0f, -0.1f, -100.0f);
	glEnd();
		
	//Centro	
	glPushMatrix();
		ligaPokemon();
		
		glTranslatef(-40,0,10);
		edificio();
		
		glTranslatef(20,0,0);
		edificio();
		
		glTranslatef(40,0,0);
		edificio();
		
		glTranslatef(20, 0,0);
		edificio();
		
		glTranslatef(-80, 0,25);
		glRotatef(180.0f, 0.0f, 1.0f,0.0f);
		edificio();
		for (int i = 0; i < 5; i++){
			edificio();
			glTranslatef(-20,0,0);
		}
	glPopMatrix();
	
	//Frontal
	glPushMatrix();
		glTranslatef(-40, 0,-20.5);
		glRotatef(180.0f, 0.0f, 1.0f,0.0f);
		for (int i = 0; i < 10; i++){
			casa(212, 190, 20, 94, 169, 100);
			glTranslatef(-7,0,0);
		}
		
		tiendaPokemon();
		glTranslatef(-7,0,0);
		
		for (int i = 0; i < 2; i++){
			casa(212, 190, 20, 94, 169, 100);
			glTranslatef(-7,0,0);
		}
	glPopMatrix();
	
	//Tracera
	glPushMatrix();
		glTranslatef(-40, 0, 58.5);
		for (int i = 0; i < 2; i++){
			casa(212, 190, 20, 94, 169, 100);
			glTranslatef(7,0,0);
		}
		
		glTranslatef(0,0,2);
		centroPokemon();
		glTranslatef(0,0,-2);
		glTranslatef(7,0,0);
		
		for (int i = 0; i < 10; i++){
			casa(212, 190, 20, 94, 169, 100);
			glTranslatef(7,0,0);
		}
	glPopMatrix();
}
