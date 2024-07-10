#include "opencv2/video/tracking.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/opencv.hpp"
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

using namespace cv;
using namespace std;

int opc = 0;
pthread_t musica, mus1, mus2;

void *Musica(void *args){
	while(true){
		system("canberra-gtk-play -f Ruta1.ogg");
	}
}
	
int main(int argc, char **argv) {
	pthread_create(&musica, NULL, Musica, NULL);
	
	while(true){
		cout<<"opcion :"<<endl;
		cin>>opc;
	}	
	return 1;
}
