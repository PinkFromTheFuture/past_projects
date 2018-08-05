/** Eduardo Furtado Sá Corrêa - 090111575
 * 
 * compilado em g++ (Ubuntu/Linaro 4.7.2-2ubuntu1) 4.7.2
 * com o seguinte comando:
 * g++ 090111575.cpp -o 090111575 `pkg-config --cflags --libs opencv`; ./090111575
 * 
 * */
 
#include "cv.h"
#include "highgui.h"

#include <iostream>

#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <stdlib.h>     /* abs (absolute value) (modulo)*/

using namespace std;

using namespace cv;


int main(){
	
	const int velocidade_reproducao = 1; //1= default. quanto maior, mais rapido.
	
	Mat frame;
	Mat frame_gray, old_frame_gray;
	Mat old_old;
	Mat diff, saida;
	int diferenca;
	int valordolimiardofundo = 25;
	int valordolimiar;
	int i,j,k;
	int a,b;
	int valordopixel;
	
	int histograma[16];
	int totalsemfundo;
	
	VideoCapture capture( "highwayI_raw.avi");
	
	//as janelas alinhadinahs, bonitinhas, onde vou exibir os videos
	namedWindow("Original", WINDOW_AUTOSIZE);
	cvMoveWindow("Original", 0, 0);
	
	namedWindow("Escala de cinza", WINDOW_AUTOSIZE);
	cvMoveWindow("Escala de cinza", 335, 0);
	
	namedWindow("Separação de fundo", WINDOW_AUTOSIZE);
	cvMoveWindow("Separação de fundo", 0, 275);
	
	namedWindow("Sombra em verde", WINDOW_AUTOSIZE);
	cvMoveWindow("Sombra em verde", 335, 275);
	
	

	
	if(capture.isOpened()) {
		int fps = capture.get(CV_CAP_PROP_FPS); //detecto o fps do vídeo
		capture >> frame; ////pego o primeiro frame
		cvtColor(frame, old_frame_gray, CV_RGB2GRAY); //old_frame_gray recebe o frame antigo em PB
		old_frame_gray.copyTo(old_old);
		while(1) {
			
			

			capture >> frame; //começo pegando um novo primeiro frame.
			if(!frame.data) break;
			cvtColor(frame, frame_gray, CV_RGB2GRAY); //passo essse novo primeiro frame para PB em frame_gray

			frame_gray.copyTo(diff);
			frame.copyTo(saida);
			for(k = 0; k < 16; k++){
				histograma[k]=0;
			}
			
			//tiro o fundo:
			for(i = 0; i < frame_gray.rows; ++i)	{
				for(j = 0; j < frame_gray.cols; ++j)	{
					
				
					diferenca = std::abs( frame_gray.at<uchar>(i,j) - old_frame_gray.at<uchar>(i,j) );	
							
					if( (diferenca < valordolimiardofundo) ){
						diff.at<uchar>(i,j) = 255;
					}	else{ //se entra no else é porque não faz parte do fundo
						
						diferenca = std::abs( frame_gray.at<uchar>(i,j) - old_old.at<uchar>(i,j) );
						if( (diferenca < valordolimiardofundo) ){ //faco de novo, segundo a tecnica vista para eliminar fundo
							diff.at<uchar>(i,j) = 255;
						}else{//agora trabalho com o que sobrou, o que não é fundo:				

							//calculo o histograma dos pixels que não estão no fundo:							
							a=0;
							b=16;
							valordopixel = frame_gray.at<uchar>(i,j);
							//printf("\npixel vale %d",valordopixel);
							for(k = 0; k < 16; k++){
								if( (valordopixel >= a) && (valordopixel < b) ){
									histograma[k]++;
								}
								a=b;
								b=b+16;
							}
							
							a=0;
							b=16;
							totalsemfundo=0;
							for(k = 0; k < 16; k++){
								//~ printf("\nde %d a %d = %d",a,b-1,histograma[k]);
								a=b;
								b=b+16;
								totalsemfundo=totalsemfundo+histograma[k];
							}
							//~ printf("\ntotalsemfundo: %d" , totalsemfundo);
							//~ getchar();
							
							totalsemfundo = totalsemfundo/2;
							
							
							totalsemfundo=totalsemfundo-histograma[0];
							k=1;
							while( totalsemfundo > 0 && k< 16) {
								totalsemfundo=totalsemfundo-histograma[k];
								k++;
							}
							//~ printf("\nachei k=%d",k);
							//~ k=k-1;
							
							valordolimiar = (k)*16;
							if( frame_gray.at<uchar>(i,j) < valordolimiar ){
								saida.at<cv::Vec3b>(i,j)[0] = 0;
								saida.at<cv::Vec3b>(i,j)[1] = 255;
								saida.at<cv::Vec3b>(i,j)[2] = 0;
							}
						}
							
					}

					
				}
			}
			
			
			
			
			old_frame_gray.copyTo(old_old);
			frame_gray.copyTo(old_frame_gray);

			
			
			//mostro os videos:
			imshow("Original", frame);
			imshow( "Escala de cinza", frame_gray ); 
			imshow( "Separação de fundo", diff ); 
			imshow( "Sombra em verde", saida ); 
			

			int key = waitKey(fps*velocidade_reproducao);
			if((char)key == 'q') { break; } //aperte q para sair.
		}
		
		
		
	}
	
	return 0;
}
	
