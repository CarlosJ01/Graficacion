#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#include "Mapa.h"

float angl=0.0f;
float angle=1.5f;
float lx=0.9995f,lz=0.0292f;
float x=0.0f,z=20.0f, y=1.0f;
int opc = 0;
float ax = x;
float az = z;

using namespace std;

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(x, y, z,
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
	
	glPushMatrix();
		glTranslatef(x+(3.0f*cos(angl)), 0.0f, z-(3.0f*sin(angl)));
		glScalef(0.5f, 0.5f, 0.5f);
		glRotatef(((angl*180.0f)/PI)+90.0f, 0.0f, 1.0f,0.0f);
		if(ax != x || az != z){
			opc++;
			if(opc == 3)
				opc = 1;
		}else{
			opc = 0;
		}
		ax = x;
		az = z;
		red(opc);
	glPopMatrix();
	
	glPushMatrix();
		ciudadAzafran();
	glPopMatrix();
	
	//~ printf("ax: %f x: %f\t",ax,x);
	//~ printf("az: %f z: %f\n",az,z);
	//~ printf("lx: %f\t lz: %f\t lx*-100:%f\n",lx,lz,x+lx*-100);
	
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
			angl -= 0.1f;//(2*PI)/70;
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
		case GLUT_KEY_F5 :
			y += fraction; 
			break;
		case GLUT_KEY_F6 :
			y -= fraction;
			break;
	}
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("Luz GLUTH");

	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutSpecialFunc(processSpecialKeys);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.5215, 0.7568, 0.9137, 0);
	glutMainLoop();

	return 1;
}
