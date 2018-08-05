#include <stdio.h>
#include <stdlib.h>     /* atoi */
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "dados.h"

int main(int argc, char *argv[]){
	int key_msg;
	int arg_minuto;
	int arg_hora;
	t_msg msg1;
	TiposMensagem tipo = Agendamento;
	if(argc != 4){
		printf("\n\tNumero de argumento invalido");
		exit(1);
	}else if(atoi(argv[1])<0){
		printf("\n\t Argumento invalido");
		exit(1);
	}else if(atoi(argv[3])<0){
		printf("\n\t Argumento invalido");
		exit(1);
	}

	arg_hora = atoi(strtok(argv[2], ":"));
	arg_minuto = atoi(strtok(NULL, ":"));
	if (arg_hora<0)
	{
		printf("\n\t Argumento invalido");
		exit(1);
	}else if (arg_minuto<0)
	{
		printf("\n\t Argumento invalido");
		exit(1);
	}

	msg1.mtype = 1;
	strcpy(msg1.executavel,argv[1]);	
	msg1.hora = arg_hora;
	msg1.min = arg_minuto;
	msg1.vezes = atoi(argv[3]);
	// /*debug*/ printf("\n\tMSG = %s",msg1.executavel);
	// /*debug*/ printf("\n\thoras = %d",msg1.hora);
	// /*debug*/ printf("\n\tmin = %d",msg1.min);
	// /*debug*/ printf("\n\tvezs = %d\n",msg1.vezes);
	key_msg = msgget(10,IPC_CREAT|0x1FF);	
	msgsnd(key_msg,&msg1,size_msg, tipo);
	return 0;
}

//args: 
// 0 -> ./executa_postergado
// 1 -> ./print
// 2 -> hh:mm
// 3 -> vezes