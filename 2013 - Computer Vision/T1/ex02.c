#include "highgui.h"
#include "cv.h"
#include "stdio.h" 

#define LIVE_EFECTS

int main( int argc, char** argv ) 
{ 
    CvCapture* capture = 0;
    capture = cvCaptureFromCAM(0);
    
    if(!capture)
    {
        printf("Could not initialize capturing...\n");
        return -1;
    }
    cvNamedWindow("video", CV_WINDOW_AUTOSIZE);
    while(1)
    {
     IplImage* frame = 0;
     frame = cvQueryFrame(capture);
     if(!frame)
            break;

	#ifdef LIVE_EFECTS
	cvErode(frame, frame, 0, 20); // ADD this line
	#endif
    cvShowImage("video", frame);
    int c = cvWaitKey(20);
    if((char)c==27 )
        break;
    }
     cvReleaseCapture(&capture);
}


