#include "opencv2/video/tracking.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include <stdio.h>
#include <iostream>
#include <ctype.h>
//g++ -Wall %f -o %e `pkg-config --cflags --libs opencv`
using namespace cv;
using namespace std;

Point2f point;
bool addRemovePt = false;

int main(int argc, char** argv )
{
	VideoCapture cap;
	TermCriteria termcrit(TermCriteria::COUNT|TermCriteria::EPS,20,0.03);
	Size subPixWinSize(10,10), winSize(31,31);

    CommandLineParser parser(argc, argv, "{@input||}{help h||}");
    string input = parser.get<string>("@input");
  
    if( input.empty() )
        cap.open(0);
    else if( input.size() == 1 && isdigit(input[0]) )
        cap.open(input[0] - '0');
    else
        cap.open(input);

    if( !cap.isOpened() ){
		cout << "Could not initialize capturing...\n";
		return 0;
    }

    namedWindow( "LK Demo", 1 );
        
    Mat gray, prevGray, image, frame;
    vector<Point2f> points[2];
    int j=0, i=0;

    if( points[0].empty() ) {
      //printf("No tengo nada de nada ");
	for(i=0; i<15; i++)
	  for(j=0; j<15; j++)
	    points[0].push_back(Point2f(100+(i*30),25+(j*30)));
	}
	
    for(;;){	
		cap >> frame;
		if( frame.empty() )
			break;
      
		flip(frame, frame, 1);
		frame.copyTo(image);
		cvtColor(image, gray, COLOR_BGR2GRAY);
      
		if( !points[0].empty() ) {
			vector<uchar> status;
			vector<float> err;
			
			if(prevGray.empty())
				gray.copyTo(prevGray);
			
			calcOpticalFlowPyrLK(prevGray, gray, points[0], points[1], status, err, winSize,3, termcrit, 0, 0.005);
			
			size_t i, k;
			for( i = k = 0; i < points[0].size() ; i++ ) {
				points[1][k++] = points[1][i];
				
				//Columnas de la malla
				if((i+1)%15 != 0)
					line(image,points[1][i],points[1][i+1], Scalar(255,255,255),1, 8,0);
				
				//Filas de la malla
				if(i<=points[0].size()-16)
					line(image,points[1][i],points[1][i+15], Scalar(255,255,255),1, 8,0);
	    
				printf(" x=%f y=%f \n",points[1][i].x, points[1][i].y );
			}
	  
			points[1].resize(k);
		}

      imshow("LK Demo", image);
      
      char c = (char)waitKey(10);
      if( c == 27 )
		break;
		
      //std::swap(points[1], points[0]);
      swap(prevGray, gray);
   }

    return 0;
}
