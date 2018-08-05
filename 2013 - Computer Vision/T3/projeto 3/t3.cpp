#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdlib.h>

using namespace cv;

//==============================================================
int main(int argc, char* argv[])
{
	Mat frame, gray, previousgray, flow, drawFlow;
	
	VideoCapture capture( "highwayI_raw.avi");
	
	namedWindow("Original", WINDOW_AUTOSIZE);
	cvMoveWindow("Original", 0, 0);
	
	namedWindow("Optical Flow", WINDOW_AUTOSIZE);
	cvMoveWindow("Optical Flow", 0, 300);
	/*
	namedWindow("Bg Subtracted", WINDOW_AUTOSIZE);
	cvMoveWindow("Bg Subtracted", 390, 0);
	
	namedWindow("Detecção de sombras", WINDOW_AUTOSIZE);
	cvMoveWindow("Detecção de sombras", 720, 0);*/
	
	if(capture.isOpened())
	{
		while(1)
		{
			capture >> frame;
			if(!frame.data) break;
			
			cvtColor(frame, gray, CV_BGR2GRAY);
			if (previousgray.data) {
			
				// Calcular o fluxo optico
				calcOpticalFlowFarneback(previousgray, gray, flow, 0.5, 3, 15, 15, 5, 1.2, OPTFLOW_USE_INITIAL_FLOW);
				frame.copyTo(drawFlow);
				for ( int i = 0; i < drawFlow.rows; i++ )
					for( int j = 0; j < drawFlow.cols; j += (drawFlow.step)) {
						const Point2f& fxy = flow.at<Point2f>(j,i);
						line(drawFlow, Point(j,i), Point(cvRound(j+fxy.y), cvRound(i+fxy.x)), CV_RGB(0, 0, 255));
						circle(drawFlow, Point(j,i), 2, CV_RGB(255, 0, 0), -1);
					}

				imshow("Optical Flow", drawFlow);
			}
			
			gray.copyTo(previousgray);
			
			imshow("Original", frame);
			
			if(waitKey(66) == 27) break;
			
		}
	}
	
	return 0;
	
}
