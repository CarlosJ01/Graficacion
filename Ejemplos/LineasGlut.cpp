#include <GL/glut.h>
#include <stdio.h>

double angulo=0.f;
double mov=0.0, mova=0.3;

void iniciar() {
  
  glClearColor(1,1,1,1);
  glPointSize(7);
  glLineWidth(3);
  glColor3f(1.f,0,0);
  glOrtho(800, 0, 600,0,-1,1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void dibujar() {
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_TRIANGLES);
  glVertex2f(2.5, 0.1);
  glVertex2f(0.5, 0.5);
  glVertex2f(0.3,0.5);
  glEnd();

 
  glBegin(GL_POINTS);
  glVertex2f(2.5, 0.1);
  glEnd();
 
  

	glPushMatrix();
	glTranslatef(mov,mova,0);
	glScaled(2,2,0);
	glRotated(angulo, 0,0,1);
	glBegin(GL_QUADS);
	glColor3f(0.3,0.2,0.2);	
	glVertex2f(0.0,0.00);
	glVertex2f(0.02,0.0);
	glVertex2f(0.02,0.02);
	glVertex2f(0.0,0.02);
	glEnd();
	glPopMatrix();
  
  
  glPushMatrix(); 
  glColor3f(0.4, 0.5, 1.0);
  glRotated(angulo, 0, 0, 1);	
  glBegin(GL_TRIANGLES);
  glVertex2f(0.5, 0.1);
  glVertex2f(0.5, 0.5);
  glVertex2f(0.3,0.5);
  glEnd();
  glPopMatrix();
  

  glPushMatrix();
  glBegin(GL_POINTS);
  glVertex2f(0.1, 0.1);
  glEnd();
  glPopMatrix();

  
  glPushMatrix(); 
  glTranslatef(-0.75,-0.75,0.0);
  glScalef(1.0, 1.0, 1.0); 
  glRotatef(angulo, 0, 1, 1);
  glColor3f(0.9, 0.5, 1.0);
  glutWireSphere(0.2, 15, 15);
  glPopMatrix();


  //glFlush();
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


int main(int argc, char **args) {
  glutInit(&argc, args);
  //glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Demo Dibujo");
  iniciar();
  glutDisplayFunc(dibujar);
  glutIdleFunc(refresco);	
  glutMainLoop();
  return 0;
}
