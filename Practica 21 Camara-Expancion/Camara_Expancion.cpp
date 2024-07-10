#include "opencv2/video/tracking.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include <stdio.h>
#include <iostream>
#include <ctype.h>
//g++ -Wall %f -o %e `pkg-config --cflags --libs opencv`
//x->640
//y->480

using namespace cv;
using namespace std;

Point2f point;
bool addRemovePt = false;

void dibujarCirculo(Mat,Point,Point);

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
    
    if( points[0].empty() ){
		points[0].push_back(Point2f(320,400));
	    points[0].push_back(Point2f(220,400));
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
			for( i = k = 0; i < points[0].size() ; i++ ){
				points[1][k++] = points[1][i];
				
				
				if(points[1][i].x<=0)
					points[1][i].x=0;
				 else if(points[1][i].x>=image.cols)
					points[1][i].x=image.cols;
				
				if(points[1][i].y<=0)
					points[1][i].y=0;
				else if(points[1][i].y>=image.rows)
					points[1][i].y=image.rows;
				
				circle( image, points[1][i], 5, CV_RGB(255,255,255), -1, 8);
				
			}
			
			dibujarCirculo(image,points[1][0],points[1][1]);
			line(image,points[1][0],points[1][1],CV_RGB(230,234,11),1,8,0);
			
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


void dibujarCirculo(Mat img, Point pnt1, Point pnt2){
	float dis = sqrt(pow((pnt1.x - pnt2.x),2) + pow((pnt1.y - pnt2.y),2));
	printf("%f\n",dis);
	dis/=30;
	circle(img, Point(320,240),10*dis, CV_RGB(234,11,11), 1, 8);
	//rectangle(img,Point(100,50),Point(540*dis,250*dis),CV_RGB(234,11,11),3,8,0);
}
