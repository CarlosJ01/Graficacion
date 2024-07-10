#include "opencv2/video/tracking.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/opencv.hpp"
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

using namespace cv;
using namespace std;
VideoCapture cap(0);
float angle=0.0;
float lx=0.0f,lz=-1.0f;
float x=0.0f,z=5.0f;
float distancia=0.0, distancia2=0.0;

Mat gray, prevGray, image, frame;
vector<Point2f> points[2];
TermCriteria termcrit;
Size subPixWinSize(10,10), winSize(31,31);

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


void renderScene(void) {

	Mat frame;
  
     cap >> frame;
     
    // glEnable(GL_TEXTURE_RECTANGLE_ARB);
     
//Lucas Canade     
   
      //}

     
     frame.copyTo(image);
     cvtColor(image, gray, COLOR_BGR2GRAY);
     
      if( !points[0].empty() )
      {
		vector<uchar> status;
		vector<float> err;
		if(prevGray.empty())
	    gray.copyTo(prevGray);
	  calcOpticalFlowPyrLK(prevGray, gray, points[0], points[1], status, err, winSize,3, termcrit, 0, 0.001);
	  size_t i, k;
	  for( i = k = 0; i < 1/*points[0].size()*/; i++ ) {
	    points[1][k++] = points[1][i];
	    circle( image, points[1][i], 3, Scalar(255,0,0), -1, 8);
	    
	    line(image, points[0][i], points[1][i], Scalar(225,0,0), 2, 8,0 );
	    distancia2 =sqrt(((points[1][0].x - points[0][0].x)*(points[1][0].x - points[0][0].x)) + ((points[1][0].y - points[0][0].y)*(points[1][0].y - points[0][0].y)));  
	    printf("distancia %f \n", distancia2);
	    printf(" x=%f y=%f \n",points[1][0].x, points[1][0].y );
		
		
	     
	  }
	  points[1].resize(k);
        }

     imshow("LK Demo", image);
	 waitKey(10);	
            


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(	x, 1.0f, z+distancia2,
			x+lx, 1.0f,  z+lz,
			0.0f, 1.0f,  0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
		glVertex3f(-100.0f, 0.0f, -100.0f);
		glVertex3f(-100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f, -100.0f);
	glEnd();

	for(int i = -3; i < 3; i++)
		for(int j=-3; j < 3; j++) {
			glPushMatrix();
			glTranslatef(i*5.0,0,j * 5.0);
			drawSnowMan();
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

	float fraction = 0.1f;

	switch (key) {
		case GLUT_KEY_LEFT :
			angle -= 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_RIGHT :
			angle += 0.01f;
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

 
 int j=0, i=0;	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	 TermCriteria termcrit(TermCriteria::COUNT|TermCriteria::EPS,20,0.03);
    Size subPixWinSize(10,10), winSize(31,31);

	for(j=0; j< 1; j++){
	    points[0].push_back(Point2f(100+(i*30),100+(j*30)));
	}
	
	glutCreateWindow("Luz GLUTH");
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutSpecialFunc(processSpecialKeys);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();

	return 1;
}
