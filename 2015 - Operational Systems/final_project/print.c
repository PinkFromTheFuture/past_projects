#include<stdio.h>
#include <time.h>
int main(){
	time_t tempoCorrente;
	struct tm *tempoInicio ;
	time(&tempoCorrente);
	int i;
	tempoInicio = localtime(&tempoCorrente);
	for (i = 0; i < 25; ++i)
	{
	  	// time(&tempoCorrente);
		// tempoAtual = localtime(&tempoCorrente);
		// printf("\n\tPID = %d\tDeltatime = %d:%d\t tempoInicio = %d:%d\n", getpid(),tempoAtual->tm_hour,tempoAtual->tm_min, tempoInicio->tm_hour,tempoInicio->tm_min);
		printf("PRINT TASK:\tPID = %d\t tempoInicio = %d:%d\n", getpid(), tempoInicio->tm_hour,tempoInicio->tm_min);
		sleep(5);	
	}	
	return 0;
}
