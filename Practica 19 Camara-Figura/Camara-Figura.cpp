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
    Mat fgr = imread("imagen.jpg",1);
    
    if( points[0].empty() ) {
	    points[0].push_back(Point2f(320,240));
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
			
			calcOpticalFlowPyrLK(prevGray, gray, points[0], points[1], status, err, winSize,3, termcrit, 0, 0.0001);
			
			size_t i, k;
			for( i = k = 0; i < points[0].size() ; i++ ) {
				points[1][k++] = points[1][i];
				
				//Condiciones Esquinas
				if(points[1][i].x<=0){
					points[1][i].x=0;
				}
				 else if(points[1][i].x+fgr.cols>=image.cols){
					 points[1][i].x=image.cols-fgr.cols;
				}
				
				if(points[1][i].y<=0){
					points[1][i].y=0;
				}
				else if(points[1][i].y+fgr.rows>=image.rows){
					points[1][i].y=image.rows-fgr.rows;
				}
				
				fgr.copyTo(image(Rect(points[1][i].x, points[1][i].y, fgr.cols, fgr.rows)));
				
				printf(" x=%f y=%f \n",points[1][i].x, points[1][i].y );
			}
	  
			points[1].resize(k);
		}

      imshow("LK Demo", image);
      
      char c = (char)waitKey(10);
      if( c == 27 )
		break;
		
      std::swap(points[1], points[0]);
      swap(prevGray, gray);
   }

    return 0;
}
