#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;

float angle=0.0;
float lx=0.0f,lz=-1.0f;
float x=0.0f,z=5.0f;

void arbol(){
	glPushMatrix();
		glColor3ub(176,109,17);
		glutSolidCube(1.0f);
		glTranslatef(0.0f, 1.0f, 0.0f);
		glutSolidCube(1.0f);
		glTranslatef(0.0f, 1.0f, 0.0f);
		glutSolidCube(1.0f);
		glTranslatef(0.0f,0.5f, 0.0f);
		glRotatef(270.0f, 1.0f, 0.0f,0.0f);
		glColor3ub(14,164,61);
		glutSolidCone(3.0f,5.0f,10,2);
	glPopMatrix();
}

void drawSnowMan() {
	glColor3ub(168,109,11);
	glTranslatef(0.0f ,1.0f, 0.0f);
	glutSolidSphere(1.0f,50,50);

	glTranslatef(0.0f, 1.25f, 0.0f);
	glutSolidSphere(0.5f,50,50);
	
	glTranslatef(0.75f ,-2.0f, 0.0f);
	glutSolidSphere(0.40f,30,30);
	
	glTranslatef(-2*0.75f ,0.0f, 0.0f);
	glutSolidSphere(0.40f,30,30);
	
	glTranslatef(-0.1f ,1.25f, 0.0f);
	glutSolidSphere(0.40f,30,30);
	
	glTranslatef(2*0.80f ,0.0f, 0.0f);
	glutSolidSphere(0.40f,30,30);
	
	glTranslatef(-0.25f ,1.1f, 0.0f);
	glutSolidSphere(0.25f,30,30);
	glTranslatef(-4*0.25f ,0.0f, 0.0f);
	glutSolidSphere(0.25f,30,30);
	
	glTranslatef(2*0.25f ,-0.30f, 0.5f);
	glPushMatrix();
		glColor3ub(0,0,0);
		glTranslatef(0.15f, 0.0f, 0.0f);
		glutSolidSphere(0.1f,20,2);
		
		glTranslatef(-2*0.15f, 0.0f, 0.0f);
		glutSolidSphere(0.1f,20,2);
	glPopMatrix();
	
	glTranslatef(-1.0f, -3.0f, -5.0f);
	arbol();
}

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	gluLookAt(	x, 1.0f, z,
			x+lx, 1.0f,  z+lz,
			0.0f, 1.0f,  0.0f);

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
		glVertex3f(-100.0f, 0.0f, -100.0f);
		glVertex3f(-100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f, -100.0f);
	glEnd();

	for(int i =-3; i < 3; i++){
		for(int j=-3; j < 3; j++) {
			glPushMatrix();
			glTranslatef(i*10.0, 0, j*10.0);
			drawSnowMan();
			glPopMatrix();
		}
	}
	
	glBegin(GL_LINES);
		glColor3ub(255,0,0);
		glVertex3f(-10000,0,0);
		glVertex3f(0,0,0);
		glVertex3f(10000,0,0);
	glEnd();
	
	glBegin(GL_LINES);
		glColor3ub(0,255,0);
		glVertex3f(0,-10000,0);
		glVertex3f(0,0,0);
		glVertex3f(0,10000,0);
	glEnd();
	
	glBegin(GL_LINES);
		glColor3ub(0,0,255);
		glVertex3f(0,0,-10000);
		glVertex3f(0,0,0);
		glVertex3f(0,0,10000);
	glEnd();
	
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
	float fraction = 0.3f;
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
	
	cout<<angle<<"\t"<<x<<"\t"<<z<<endl;
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("GLUTH Prueba");

	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutSpecialFunc(processSpecialKeys);

	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 1;
}
