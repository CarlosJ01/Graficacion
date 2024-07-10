#include <GL/glut.h>
#include <stdio.h>

double angulo=0.f;
double mov=0.0, mova=0.3;

void iniciar();
void refresco();
void primitivas();
	
int main(int argc, char **args) {
  glutInit(&argc, args);
  //glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Demo Dibujo");
  iniciar();
  glutDisplayFunc(primitivas);
  glutIdleFunc(refresco);	
  glutMainLoop();
  return 0;
}

void iniciar() {  
	glClearColor(1,1,1,1);
	glPointSize(7);
	glLineWidth(3);
	glColor3f(1.f,0,0);
	glOrtho(800, 0, 600,0,-1,1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void primitivas() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Punto
	glBegin(GL_POINTS);
		glColor3f(1,0,0);
		glVertex2f (0.0, 0.0);
	glEnd();
	
	//Lineas
	glBegin(GL_LINES);
		glColor3f(0,1,0);
		glVertex2f(0,0);
		glVertex2f(0.5,0.5);
	glEnd();

	//Triangulos
	glBegin(GL_TRIANGLES);
		glColor3f(0,0,1);
		glVertex2f(1,0);
		glVertex2f(0.5,0);
		glVertex2f(0.75,-0.5);
	glEnd();
	
	//Cuadrado
	glBegin (GL_QUADS);
		glColor3f(1,0,1);
		glVertex2f(0.5,0);
		glVertex2f(1,0);
		glVertex2f(1,0.5);
		glVertex2f(0.5,0.5);
	glEnd ();

	glBegin (GL_POLYGON);
		glColor3f(0,1,1);
		glVertex2f(-0.5,-0.5);
		glVertex2f(-0.5,1);
		glVertex2f(-1,0.5);
		glVertex2f(-0.75,1);
		glVertex2f(-1,-0.5);
	glEnd ();

	glutSwapBuffers();
}

void refresco(){
	angulo+=0.1;	
	if(mov>=0.5){	
		mov=0.5;	
		mova+=0.01;	
	}else{
		mov+=0.001;
	}
	glutPostRedisplay();
}
