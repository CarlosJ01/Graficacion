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
    
    if( points[0].empty() )
	    points[0].push_back(Point2f(100,100));
	
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
			
			calcOpticalFlowPyrLK(prevGray, gray, points[0], points[1], status, err, winSize,3, termcrit, 0, 0.001);
			
			line(image,Point(image.cols/2,0),Point(image.cols/2,image.rows),CV_RGB(149,156,147),5,8,0);
			line(image,Point(0,image.rows/2),Point(image.cols,image.rows/2),CV_RGB(149,156,147),5,8,0);
			rectangle(image,Point(0,0),Point(image.cols,image.rows),CV_RGB(149,156,147),5,8,0);
			
			size_t i, k;
			for( i = k = 0; i < points[0].size() ; i++ ) {
				points[1][k++] = points[1][i];
				
				//Condiciones Esquinas
				if(points[1][i].x<=0){
					printf("Esquina Izquierda\n");//Esquina Izquierda
					points[1][i].x=image.cols-30;
				 }
				 else if(points[1][i].x>=image.cols){
					printf("Esquina Derecha\n");//Esquina Derecha
					points[1][i].x=30;
				}
				
				if(points[1][i].y<=0){
					printf("Esquina Superior\n"); //Esquina Superior
					points[1][i].y=image.rows-30;
				}
				else if(points[1][i].y>=image.rows){
					printf("Esquina Inferior\n"); //Esquina Esquina Inferior
					points[1][i].y=30;
				}
				
				//Condiciones de cuadrante
				if(points[1][i].x>=0 && points[1][i].x<=image.cols/2){
					if(points[1][i].y>=0 && points[1][i].y<=image.rows/2){
						circle( image, points[1][i], 20, CV_RGB(216,5,5), -1, 8);//Cuadrante 1
						printf("Cuadrante I\n");
					}else{
						circle( image, points[1][i], 20, CV_RGB(206,216,5), -1, 8);//Cuadrante 3
						printf("Cuadrante III\n");
					}
				}else{
					if(points[1][i].y>=0 && points[1][i].y<=image.rows/2){
						circle( image, points[1][i], 20, CV_RGB(21,112,222), -1, 8);//Cuadrante 2
						printf("Cuadrante II\n");
					}
					else{
						circle( image, points[1][i], 20, CV_RGB(53,180,16), -1, 8);//Cuadrante 4
						printf("Cuadrante VI\n");
					}	
				}
				
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
