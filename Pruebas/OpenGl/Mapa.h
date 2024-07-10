#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#include "Modelos.h"

# define PI           3.14159265358979323846
using namespace std;

void ciudadAzafran(){
	glColor3ub(77, 86, 86);
	glBegin(GL_QUADS);
		glVertex3f(-55.0f, 0.0f, -25.0f);
		glVertex3f(-55.0f, 0.0f,  65.0f);
		glVertex3f( 55.0f, 0.0f,  65.0f);
		glVertex3f( 55.0f, 0.0f, -25.0f);
	glEnd();
	
	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
		glVertex3f(-55.0f, 0.01f, 15.0f);
		glVertex3f(-55.0f, 0.01f, 30.0f);
		glVertex3f( 55.0f, 0.01f, 30.0f);
		glVertex3f( 55.0f, 0.01f, 15.0f);
	glEnd();
	
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
		glVertex3f(-55.0f, 0.02f, 22.0f);
		glVertex3f(-55.0f, 0.02f, 23.0f);
		glVertex3f( 55.0f, 0.02f, 23.0f);
		glVertex3f( 55.0f, 0.02f, 22.0f);
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

void ciudadCeleste(){
	glColor3ub(77, 86, 86);
	glBegin(GL_QUADS);
		glVertex3f(-15.0f, 0.0f, -20.0f);
		glVertex3f(-15.0f, 0.0f,  20.0f);
		glVertex3f( 20.0f, 0.0f,  20.0f);
		glVertex3f( 20.0f, 0.0f, -20.0f);
	glEnd();
	
	//Centro	
	glPushMatrix();
		centroPokemon();
		
		glTranslatef(-7, 0, 0);
		casa(204, 211, 174, 67, 202, 192);
	
		glTranslatef(20,0,0);
		gimnacioPokemon();
	glPopMatrix();
	
	//Atras
	glPushMatrix();
		glTranslatef(-7, 0, -15);
		casa(204, 211, 174, 67, 202, 192);
		
		glTranslatef(7, 0, 0);
		casa(204, 211, 174, 67, 202, 192);
		
		glTranslatef(10, 0, 0);
		casa(204, 211, 174, 67, 202, 192);
	glPopMatrix();
	
	//Delante
	glPushMatrix();
		glTranslatef(15, 0, 15);
		casa(204, 211, 174, 67, 202, 192);
		
		glTranslatef(-10, 0, 0);
		tiendaPokemon();
		
		glTranslatef(-13, 0, 0);
		glScalef(2.0f, 1.5f, 1.5f);
		casa(249, 238, 104, 137, 62, 24);
	glPopMatrix();
}

void ciudadVerde(){
	glColor3ub(77, 86, 86);
	glBegin(GL_QUADS);
		glVertex3f(-23.0f, 0.0f, -25.0f);
		glVertex3f(-23.0f, 0.0f,  23.0f);
		glVertex3f( 15.0f, 0.0f,  23.0f);
		glVertex3f( 15.0f, 0.0f, -25.0f);
	glEnd();
	
	//Centro	
	glPushMatrix();
		glTranslatef(5, 0, -10);
		gimnacioPokemon();
		glTranslatef(5, 0, 10);
		glTranslatef(-15, 0, 0);
		casa(83, 46, 22, 96, 199, 112);
	glPopMatrix();
	
	//Atras
	glPushMatrix();
		glTranslatef(5, 0, -10);
		glTranslatef(-15, 0, 0);
		casa(83, 46, 22, 96, 199, 112);
		
		glTranslatef(0, 0, -10);
		casa(83, 46, 22, 96, 199, 112);
	glPopMatrix();
	
	//Delante
	glPushMatrix();
		glTranslatef(10, 0, 10);
		tiendaPokemon();
		glTranslatef(-20, 0, 10);
		centroPokemon();
	glPopMatrix();
}

void ciudadPlateada(){
	glColor3ub(77, 86, 86);
	glBegin(GL_QUADS);
		glVertex3f(-22.0f, 0.0f, -38.0f);
		glVertex3f(-22.0f, 0.0f,  13.0f);
		glVertex3f( 12.0f, 0.0f,  13.0f);
		glVertex3f( 12.0f, 0.0f, -38.0f);
	glEnd();
	
	//Centro	
	glPushMatrix();
		glTranslatef(3, 0, 3);
		tiendaPokemon();
		
		glTranslatef(5, 0, -10);
		casa(46, 159, 135, 36, 76, 71);
		
		glTranslatef(-18, 0, 0);
		gimnacioPokemon();
	glPopMatrix();
	
	//Atras
	glPushMatrix();
		glTranslatef(-10, 0, -30);
		glScalef(4.0f, 2.0f, 2.0f);
		casa(127, 112, 104, 182, 95, 143);
	glPopMatrix();
	
	//Delante
	glPushMatrix();
		glTranslatef(-5, 0, 10);
		centroPokemon();
		
		glTranslatef(-10, 0, 0);
		casa(46, 159, 135, 36, 76, 71);
	glPopMatrix();
}

void puebloLavanda(){
	glColor3ub(77, 86, 86);
	glBegin(GL_QUADS);
		glVertex3f(-25.0f, 0.0f, -33.0f);
		glVertex3f(-25.0f, 0.0f,  18.0f);
		glVertex3f( 22.0f, 0.0f,  18.0f);
		glVertex3f( 22.0f, 0.0f, -33.0f);
	glEnd();
	
	//Atras
	glPushMatrix();
		glTranslatef(-20, 0, -10);
		tiendaPokemon();
		glTranslatef(10, 0, 0);
		centroPokemon();
		glTranslatef(20, 0, 0);
		edificio();
	glPopMatrix();
	
	//Delante
	glPushMatrix();
		glTranslatef(-10, 0, 8);
		casa(56, 40, 64, 176, 136, 200);
		
		glTranslatef(10, 0, 0);
		casa(56, 40, 64, 176, 136, 200);
		
		glTranslatef(-5, 0, 7);
		casa(56, 40, 64, 176, 136, 200);
	glPopMatrix();
}

void bosque(){
	int i;
	glPushMatrix();
		glTranslatef(-130,0,-120);
		for (i = 0; i < 38; i++){
			arbol();
			glTranslatef(7,0,0);
		}
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-130,0,125);
		for (i = 0; i < 38; i++){
			arbol();
			glTranslatef(7,0,0);
		}
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-130,0,-120);
		for (i = 0; i < 36; i++){
			arbol();
			glTranslatef(0,0,7);
		}
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(125, 0, -120);
		for (i = 0; i < 36; i++){
			arbol();
			glTranslatef(0,0,7);
		}
	glPopMatrix();
}
