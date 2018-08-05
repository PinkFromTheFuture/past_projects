/** EDUARDO FURTADO SÁ CORRÊA - 09/0111575
rm ./hough_pvc; g++ hough_pvc.cpp -o hough_pvc `pkg-config --cflags --libs opencv`; ./hough_pvc
 * */

 #define CV_NO_BACKWARD_COMPATIBILITY

 
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>


#include <opencv2/opencv.hpp>

#include <stdlib.h>
#include <math.h>
#include <cv.h>
#include <highgui.h>


using namespace cv;
using namespace std;

//função que vai retornar a imagem com as as linhas e circulos detectados
Mat magica (Mat src) {
	//variáveis
	Mat tempLines;
	Mat tempCircles;
	Mat saida;
	int i;
	vector<Vec4i> lines;
	vector<Vec3f> circles;
	
	cvtColor (src, tempLines, CV_BGR2GRAY);
	cvtColor (src, tempCircles, CV_BGR2GRAY);
	src.copyTo (saida);


	//linhas
    Canny(tempLines, tempLines, 50, 200, 3);
    //~ Canny(tempLines, tempLines, 100, 650, 5);
    //~ Canny(tempLines, tempLines, 150, 300, 3 );
	//~ HoughLinesP (tempLines, lines, 1, CV_PI/180, 75, 75, 10);
	HoughLinesP(tempLines, lines, 1, CV_PI/180, 50, 50, 10 );
	//-Canny( tempLines, tempLines, 100, 300, 3 );
	//-HoughLinesP( tempLines, lines, 1, CV_PI/180, 50, 50, 10 );
		
    for( i = 0; i < lines.size(); i++ ) {
    	Vec4i l = lines[i];
    	//~ line( saida		, Point(l[0], l[1])	, Point(l[2]	  , l[3]), Scalar(255,0,0), 3);
		line( saida, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(255,0,0), 3, CV_AA);
    }


/// Reduce the noise so we avoid false circle detection
  GaussianBlur( tempCircles, tempCircles, Size(9, 9), 2, 2 );
  /// Apply the Hough Transform to find the circles
  //~ HoughCircles( src_gray, circles, CV_HOUGH_GRADIENT, 1     , src_gray.rows/8, 200    	, 40  ,       0   , 0 ); //para circulos.jpg
  //~ HoughCircles( tempCircles, circles, CV_HOUGH_GRADIENT, 1     , tempCircles.rows/8, 1    	, 80  ,       0   , 0 ); //homer
    HoughCircles( tempCircles, circles, CV_HOUGH_GRADIENT, 1     , tempCircles.rows/8, 100    	, 55  ,       0   , 0 );
  //~ HoughCircles( src_gray, circles, CV_HOUGH_GRADIENT, 1     , src_gray.rows/8, 1    	, 100  ,       0   , 0 ); //mafalda?
  //~ HoughCircles( src_gray, circles, CV_HOUGH_GRADIENT, 1     , src_gray.rows/8, 200    	, 100  ,       0   , 0 ); //default?
  //-GaussianBlur( tempCircles, tempCircles, Size(3, 3), 2, 2 );
	//-HoughCircles( tempCircles, circles, CV_HOUGH_GRADIENT, 1, tempCircles.rows/8, 200, 100, 0, 0 );
		
		
//HoughCircles( input   , Output , circles          , method, dp             , minDist	, arg1, minR, maxR)
//~ Parameters:	
//~ image – 8-bit, single-channel, grayscale input image.
//~ circles – Output vector of found circles. Each vector is encoded as a 3-element floating-point vector  (x, y, radius) .
//~ circle_storage – In C function this is a memory storage that will contain the output sequence of found circles.
//~ method – Detection method to use. Currently, the only implemented method is CV_HOUGH_GRADIENT , which is basically 21HT , described in [Yuen90].
//~ dp – Inverse ratio of the accumulator resolution to the image resolution. For example, if dp=1 , the accumulator has the same resolution as the input image. If dp=2 , the accumulator has half as big width and height.
//~ minDist – Minimum distance between the centers of the detected circles. If the parameter is too small, multiple neighbor circles may be falsely detected in addition to a true one. If it is too large, some circles may be missed.
//~ arg1 – First method-specific parameter. In case of CV_HOUGH_GRADIENT , it is the higher threshold of the two passed to the Canny() edge detector (the lower one is twice smaller).
//~ minRadius – Minimum circle radius.
//~ maxRadius – Maximum circle radius.

  /// Draw the circles detected
  for( size_t i = 0; i < circles.size(); i++ )
  {
      Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
      int radius = cvRound(circles[i][2]);
      // circle center
      circle( saida, center, 3, Scalar(0,255,0), -1, 8, 0 );
      // circle outline
      circle( saida, center, radius, Scalar(0,0,255), 3, 8, 0 );
   }

	return saida;
}


int main(int argc, char** argv){

	
    const char* filename = argc >= 3 ? argv[2] : "homer.jpg";
    const int velocidade_reproducao = 1; //1= default. quanto maior, mais rapido.
	Mat src;
	bool isVideo;
	bool isCam = false;
	VideoCapture capture;
	
	Mat dst, cdst;
	int fps = 30, key;

	///----------------------------------------------------------------------------------------------------

	cout << "\nEduardo Furtado S. C. - 09/0111575 - UnB, PVC 2/2013 - Prof. F. Vidal"
			"\n******************************************************************************"
			"\nThis program demonstrates line and circle finding with the Hough transform.\n"
            "Usage:\n"
            "./hough_pvc <type> <filename>\n"
			"Type 0 = image. Type 1 = video\n"
            "If no parameters are entered it uses your webcam\n"
            "******************************************************************************\n\n"
            "Detected lines are drawn in blue, circles in red with their center in green\n"
            "\n>>>aperte qualquer tecla para sair<<<\n" << endl;

            
	///----------------------------------------------------------------------------------------------------

	
    if (argc == 3) {
		if(strstr(argv[1], "1") ){ //1 é pra arquivo de VIDEO
			isVideo = true;
			capture.release();
			capture.open (filename);
			if (!capture.isOpened()){
				cout << "can not open video " << filename << endl;
				return -1;
			}
			capture >> src;
			waitKey (30);
			fps = capture.get(CV_CAP_PROP_FPS); //detecto o fps do vídeo
		}else{ //se é IMAGEM...
			isVideo = false;
			src = imread (filename, 1);
			if (!src.data) {
				cout << "can not open image " << filename << endl;
				return -1;	
			}
			waitKey (30);
		}
	}else{ //se não é imagem, nem vídeo, abre a WEBCAM...
		isVideo = true;
		isCam=true;
		capture.open(0);
		if (!capture.isOpened()){
			cout << "can not open your webcam :(" << endl;
			return -1;
		}
		cout << "SMILE! you are being recorded. :)" << endl;
		capture >> src;
		waitKey (30);
		
		//~ fps=30;
	}


	///----------------------------------------------------------------------------------------------------
	
	//deixo bonitinho as janelas de saida, ou seja, bem posicionadas
	cvNamedWindow( "source", 1 );
    cvMoveWindow( "source", 0, 0 );
    cvNamedWindow( "hough", 1 );
    cvMoveWindow( "hough", 625, 0 );

    ///----------------------------------------------------------------------------------------------------

	do{
		
		dst = magica(src); //faz para cada frame do vídeo ou imagem.
		//mostra as coisas...
		imshow("source", src);
		imshow("hough", dst);
		
		//~ src<<capture;
		capture>>src;
		if (!src.data) break;
		if(isCam){
			flip( src, src, 1 );
		}

		if(waitKey(30) >0 ) {
			break;
		}
		
	} while (isVideo);
	if(!isVideo)
		waitKey();

    return 0;
}
