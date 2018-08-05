#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <sys/shm.h>
#include <ctime>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>
#include "dados.h"
#include <sys/wait.h>


void insereListaProcesso( t_processo **lista, t_msg *registro){
	t_processo *novo = (t_processo*)malloc(size_processo);
	t_processo *aux = (t_processo*)*lista;
	std::time_t tempoCorrente;
	struct tm * tempoInfo;
	unsigned int i;
	
	time(&tempoCorrente);
	tempoInfo = localtime(&tempoCorrente); //PEGA O TEMPO ATUAL DE FORMA SEPARADA
	if(aux == NULL ){
		//Insere na cabeca da lista o novo valor
		*lista = novo;
		(*lista)->jobId =  0 ;
		(*lista)->vezes = registro->vezes;
		(*lista)->deltaHora = registro->hora;
		(*lista)->deltaMin = registro->min;
		(*lista)->minstamp = (registro->hora * 60) + registro->min + (tempoInfo->tm_hour * 60) + tempoInfo->tm_min;
		(*lista)->horaInsercao = tempoInfo->tm_hour;
		(*lista)->minInsercao = tempoInfo->tm_min;
		(*lista)->startHora = 99;
		(*lista)->startMinuto = 99;
		strcpy((*lista)->executavel,registro->executavel);
		(*lista)->prox = NULL;
		for (i = 0; i < registro->vezes; ++i)
		{
			(*lista)->pid.push_back(0);
		}
	}else{	
		//Atribui para a nova ficha os valores
		strcpy(novo->executavel,registro->executavel);
		novo->vezes = registro->vezes;
		novo->deltaHora = registro->hora;
		novo->deltaMin = registro->min;
		novo->horaInsercao = tempoInfo->tm_hour;
		novo->minInsercao = tempoInfo->tm_min;
		novo->minstamp = (registro->hora * 60) + registro->min + (tempoInfo->tm_hour * 60) + tempoInfo->tm_min;
		novo->startHora = 99;
		novo->startMinuto = 99;
		novo->prox = NULL;
		for (i = 0; i < registro->vezes; ++i)
		{
			novo->pid.push_back(0);
		}
		//Reinicia o contador
		i = 1;
		// Procura o lugar onde colocar a nova ficha
		while(aux->prox != NULL ){
			i ++;
			aux = aux->prox;
		}
		//Coloca o id do job
		novo->jobId = i;
		// coloca 
 		novo->prox = aux->prox;
		aux->prox = novo;
	}	
	return;
}

void imprimeListaEstatistica(t_estatisticaProcesso **cabeca){
    t_estatisticaProcesso *aux = *cabeca;
    printf("\tSERVER MESSAGE: imprimindo estatisticas\n");
    while(aux != NULL){
    	//debug printf("no imprime lista\n");
		printf("Processo PID:%u  \tNome do file executavel: %s\ttempo de submissao %u:%u\tinicio da execucao %u:%u  \tHora Final %u:%u\n"
																	,aux->pid // tProcesso PID
																	,aux->executavel // tNome do file executavel
																	,aux->horaInicio // ttempo de submissao
																	,aux->minInicio // ttempo de submissao
																	,aux->horaStart
																	,aux->minStart
																	,aux->horaFinal
																	,aux->minFinal);
		aux = aux->prox;	
	}
	// getchar();
	// system("clear");

	printf("\nbye! \n");
	return;
}

void insereListaEstatistica( t_estatisticaProcesso **lista, t_processo *registro,int pid)
{
	t_estatisticaProcesso *novo = (t_estatisticaProcesso*)malloc(size_estatistica);
	t_estatisticaProcesso *aux = (t_estatisticaProcesso*)*lista;
	std::time_t tempoCorrente;
	struct tm * tempoInfo;

	//debugprintf("\tINSERINDO ESTATISTISCA###############\n");
	time(&tempoCorrente);
	tempoInfo = localtime(&tempoCorrente); //PEGA O TEMPO ATUAL DE FORMA SEPARADA
	if(aux == NULL )
	{
		//debugprintf("\tIF ESTAT\n");
		//Insere na cabeca da lista o novo valor
		*lista = novo;
		(*lista)->pid = pid;
		(*lista)->horaInicio = registro->horaInsercao;
		(*lista)->minInicio = registro->minInsercao;
		(*lista)->horaFinal = tempoInfo->tm_hour;
		(*lista)->minFinal = tempoInfo->tm_min;
		(*lista)->horaStart = registro->startHora;
		(*lista)->minStart = registro->startMinuto;
		
		strcpy((*lista)->executavel,registro->executavel);
		(*lista)->prox = NULL;
		//CONTAR QUANTOS VEZES FORAM EXECUTADAS
		
	}
	else
	{	
		//debugprintf("\tELSE ESTAT\n");
		//Atribui para a nova ficha os valores
		strcpy(novo->executavel,registro->executavel);
		novo->horaInicio = registro->horaInsercao;
		novo->pid = pid;
		novo->minInicio = registro->minInsercao;
		novo->horaFinal = tempoInfo->tm_hour;
		novo->minFinal = tempoInfo->tm_min;
		novo->horaStart = registro->startHora;
		novo->minStart = registro->startMinuto;
		novo->prox = NULL;
		//CONTAR QUANTOS VEZES FORAM EXECUTADAS
		// Procura o lugar onde colocar a nova ficha
		while(aux->prox != NULL)
		{
			aux = aux->prox;
		}
		// coloca 
 		novo->prox = aux->prox;
		aux->prox = novo;
	}	

	//debugprintf("\tSAINDO ESTAT\n");
	return;
}

void dummy(int signal){}

void imprimeListaProcesso(t_processo **cabeca){
    t_processo *aux = *cabeca;

    printf("job\tarq_exec\t\thh:mm\tvezes\tincr\n");
    while(aux != NULL){
		printf("%lu\t%s%19u:%u\t%u\t%u:%u\n"
					  ,aux->jobId
					  ,aux->executavel
					  ,aux->horaInsercao
					  ,aux->minInsercao
					  ,aux->vezes
					  ,aux->deltaHora
					  ,aux->deltaMin);

		aux = aux->prox;	
	}
	// getchar();
	// system("clear");
	return;
}

void debug_imprimeListaProcesso(t_processo **cabeca){
    t_processo *aux = *cabeca;
    unsigned int j = 0;


    printf("job\tarq_exec\t\thh:mm\tvezes\tincr\n");
    while(aux != NULL){
    	//debug printf("no imprime lista\n");
    	for (j = 0; j < aux->pid.size(); ++j)
    	{
			printf("\tProcesso\tjobId=%lu\tpid=%d\t deltaHora %u:%u x %u\t minstamp\t%u\n"
						  ,aux->jobId
						  ,aux->pid[j]
						  ,aux->deltaHora
						  ,aux->deltaMin
						  ,aux->vezes
						  ,aux->minstamp);
		}
		aux = aux->prox;	
	}
	// getchar();
	// system("clear");
	return;
}

void listaProcessosCancelados(t_processo **cabeca)
{
	unsigned int i;
	t_processo *aux = *cabeca;

	while(aux != NULL )
	{
		for (i = 0; i < aux->pid.size(); ++i)
		{
			if (aux->pid[i] >= 0)
			{
				printf("\tSERVER MESSAGE: processo do jobID=%lu, pid=%d,\texec=%s - NAO SERA EXECUTADO!\n",aux->jobId, aux->pid[i],aux->executavel);
			}
		}
		aux = aux->prox;
	}
}


// Funcao que remove a ficha da lista de processos na posicao int posicao
int removerListaProcesso(t_processo **listaProcesso,t_estatisticaProcesso **listaEstatistica, int numero_da_lista, int unsigned posicao_no_vetor){
	t_processo *aux = *listaProcesso;
	int i;
	int retorno = 0;
	// /*debug*/ printf("no removerlista\n");

	if(numero_da_lista != 0){
		// /*debug*/ printf("no if do remover\n");
		//loop que vai para a posicao necessaria
		for(aux = *listaProcesso, i = 0; i < (numero_da_lista - 1) && aux->prox != NULL ; i++,aux = aux->prox){
			// /*debug*/ printf("for remover lista i =%d\n", i);
		}
		
		// se for a ultima posicao, re
		if (posicao_no_vetor == aux->prox->pid.size() - 1 )
		{
			// /*debug*/ printf("if if\n");
			//remove
			//INSERE NA LISTA DE ESTATISTICA!
			insereListaEstatistica(listaEstatistica,aux->prox, aux->prox->pid[posicao_no_vetor]);
			aux->prox = aux->prox->prox;
			retorno++;

		}
		else
		{
			// /*debug*/  printf("if else\n");
			insereListaEstatistica(listaEstatistica,aux->prox, aux->prox->pid[posicao_no_vetor]);
			aux->prox->pid[posicao_no_vetor] = -1;
		}
		
	}
	else{
		// /*debug:*/printf("no else do remover\n");

		if (posicao_no_vetor == aux->pid.size() - 1 )
		{
			// /*debug*/  printf("else if\n");
			// cabeca da lista eh agora outro
			//INSERE NA LISTA DE ESTATISTICA!
			insereListaEstatistica(listaEstatistica,*listaProcesso, aux->prox->pid[posicao_no_vetor]);
			*listaProcesso = aux->prox;
			retorno++;

		}
		else
		{
			// /*debug*/ printf("else else\n");
			insereListaEstatistica(listaEstatistica,aux->prox, aux->prox->pid[posicao_no_vetor]);
			aux->pid[posicao_no_vetor] = -1;
		}
	}
	// /*debug*/ printf("removi!\n");
	return retorno;
}

void removeForcadoProcesso(t_processo **listaProcesso,t_processo *registro){
	t_processo *auxProc= *listaProcesso;
	// /*debug*/ printf("\tSERVER MESSAGE: reorganizando lista!\n");
	if(*listaProcesso == registro ){
		// /*debug*/ printf("\tSERVER MESSAGE: IF!\n");

		(*listaProcesso) = (*listaProcesso)->prox;
	}
	else{
		// /*debug*/ printf("\tSERVER MESSAGE: ELSE!\n");
		while(registro != auxProc->prox && auxProc->prox != NULL){
			auxProc = auxProc->prox;
		}
		if(auxProc!=NULL){
			// /*debug*/  printf("\tSERVER MESSAGE: IF 2!\n");
			t_processo *freeProc = auxProc->prox;
			auxProc->prox = auxProc->prox->prox;
			free(freeProc);
		}
		else
			printf("\tSERVER MESSAGE: nao foi encontrado tal processo\n");
	}
	// /*debug*/ printf("\tSERVER MESSAGE: FECHOU A REORGANIZACAO!\n");

	return;

}


//FUNCAO QUE DESTROI E INSERE TODO O RESTO NA LISTA
void destroiListaProcesso(t_processo **listaProcesso,t_estatisticaProcesso **listaEstatistica){
	t_processo *auxProc ;
	listaProcessosCancelados(listaProcesso);
	while(*listaProcesso != NULL ){
		auxProc = *listaProcesso;
		removeForcadoProcesso(listaProcesso,auxProc);
		// /*debug*/printf("\tSERVER MESSAGE: \tcabeca da LISTA%p!\n",auxProc);
	}
	return;
}


//FUNCAO QUE DESTROI E INSERE PELO ID JOB !
void destroiProcessoJobId(t_processo **listaProcesso,t_estatisticaProcesso **listaEstatistica,  long int jobId){
	t_processo *auxProc = *listaProcesso ;
	while(auxProc->jobId != jobId && auxProc != NULL){
		auxProc = auxProc->prox;
	}
	if(auxProc == NULL){
		printf("\tSYSTEM MESSAGE: erro nao existe processo com esse jobid!\n");
	}else{
		// /*debug*/printf("\tSERVER MESSAGE: COLOCADO NA ESTAT!\n");
		removeForcadoProcesso(listaProcesso,auxProc);
	}
	printf("\tSERVER MESSAGE: removido job!\n");
	return;
}



void retiraProcessosFinalizados(t_processo **cabeca,t_estatisticaProcesso **listaEstatistica,unsigned tamanhoLista){
	t_processo *aux ;
	unsigned i;
	unsigned j;  
	int wait_pid_status = -1;
	bool flagRemover = true;
	//debugprintf("V#################VERIFICA SE REMOVE!\n");
	while(flagRemover){
		flagRemover = false;
		for (i = 0,aux = *cabeca; i < tamanhoLista && !flagRemover; ++i,aux = aux->prox)
		{
			for (j = 0; j < aux->pid.size() && !flagRemover; ++j)
			{
				//debugprintf("\t______________________i = %d\tj=%d\n",i,j );
				if (aux->pid[j] > 0){
					waitpid(aux->pid[j], &wait_pid_status, WNOHANG);
				}
				// Se um processo filho i terminou retira da lista
				//debug printf("->>>>>>>>>>>>>>>%d\n", wait_pid_status);
				if(WIFEXITED(wait_pid_status) ){
					//debug printf("chamando a remover lista com i=%d, j=%u, do aux->pid[j] = %d\n", i,j, aux->pid[j] );
					tamanhoLista -=removerListaProcesso(cabeca,listaEstatistica, i, j);	
					flagRemover = true;
					wait_pid_status = -1;

				}	
			}
		}
		//debugprintf("\tFINAL DOS FORS FLAG = %d\ttamanhoLista\t%d\ti=%d\tj=%d\n",flagRemover,tamanhoLista,i,j);
	}
	//debugprintf("\tACABOU A VERIFICACAO\n");
	return ;
}




/* PROGRAMA QUE VERIFICA A FILA DE MSGS, E TRATA A REQUISICAO!*/
int main(){
	t_processo *cabecaProcesso = NULL;
	t_processo *aux;
	t_estatisticaProcesso *cabecaEstatistica = NULL;
	t_msg msgrecebida;
	std::time_t tempoCorrente;
	struct tm * tempoInfo;
	int key_msg;
	int tamanhoLista;	
	int ppid;					// Parent Process ID
	int i;
	int w;
	unsigned int j;
	//debug unsigned alarm_return = 0;
	//debug unsigned int debug_var;
	bool flagPrimeiroRodou = false;
	
	signal(SIGALRM,dummy);				//ROTINA DE SIGNAL_ALRM
	key_msg = msgget(10,0x1FF);			//CRIAR FILA DE MSG

	printf("server is running...\n");
	while(1)
	{
		while(msgrcv(key_msg,&msgrecebida,size_msg,0,IPC_NOWAIT) > 0)
		{			//LOOP DE RECEBER MENSAGENS E INSERIR NA FILA PROCESSSOS
			if(msgrecebida.mtype == TIPOCANCELAMENTO)
			{	
				//FAZ VERIFICACAO SE RETIRA PROCESSOS!
				printf("\tSERVER MESSAGE: cancelando um job\n");
				destroiProcessoJobId(&cabecaProcesso,&cabecaEstatistica,msgrecebida.jobId);
			}
			else if(msgrecebida.mtype == TIPOAGENDAMENTO)
			{	
				printf("\tSERVER MESSAGE: agendando um job\n");
				insereListaProcesso(&cabecaProcesso,&msgrecebida);
			}
			else if(msgrecebida.mtype == TIPOLISTARPROCESSOS)
			{	
				printf("\tSERVER MESSAGE: lista a estrutura que contem os processos postergados\n");
				imprimeListaProcesso(&cabecaProcesso);
			}
			else if(msgrecebida.mtype == TIPOKILLSERVER)
			{
				printf("\tSERVER MESSAGE: fechando o server...\n");
				destroiListaProcesso(&cabecaProcesso,&cabecaEstatistica);
				imprimeListaEstatistica(&cabecaEstatistica);
				//FINALIZA SERVER
				return 0; 
			}
		}

		aux = cabecaProcesso;
		tamanhoLista = 0;
		while(aux != NULL)
		{
			time(&tempoCorrente);
			tempoInfo = localtime(&tempoCorrente); 					//PEGA O TEMPO ATUAL DE FORMA SEPARADA
			//debug debug_var = (unsigned) ((tempoInfo->tm_hour*60) + tempoInfo->tm_min);
			//debugprintf("_____________________aux->minstamp=%u, debug_var=%u, vezes = %d\n", aux->minstamp, debug_var, aux->vezes );
			if( aux->minstamp <= (unsigned) ((tempoInfo->tm_hour*60) + tempoInfo->tm_min) && aux->vezes > 0  )
			{
				//debugprintf("\tHORA DE EXECUTAR UM PROCESSO!\n");
				ppid = fork();
				// //debug printf("\tppid = %d \n",ppid);
				if(ppid == 0){	
					// //debug printf("end1\n");
					kill(getpid(),SIGSTOP);
					if(execl(aux->executavel,aux->executavel,EComercial, (char*)0) < 0){
						printf("Erro no execl! \n");
						exit(1);
					}
					else
					{
						if (aux->startHora == 99)
						{
							aux->startHora = tempoInfo->tm_hour;
							aux->startMinuto = tempoInfo->tm_min;
						}
						
					}
				}else{
					// /*debug*/ printf("end222222222222222222222222222222222222222222222222222\n");
					aux->vezes--;		
					aux->minstamp = ((tempoInfo->tm_hour*60) + tempoInfo->tm_min) + aux->deltaHora*60 + aux->deltaMin  ; //ATUALIZAR A PROX VEZ
					
					if (aux->startHora == 99)
					{
						aux->startHora = tempoInfo->tm_hour;
						aux->startMinuto = tempoInfo->tm_min;
					}

					// insereListaEstatistica(&cabecaEstatistica,aux,ppid);

					w=0;
					while(aux->pid[w] != 0)
					{
						w++;
					}
					aux->pid[w] = ppid;
					// //debug printf("\telse aux->pid = %u \n",aux->pid[w]);
				}
				// //debug printf("end\n");
			}
			tamanhoLista++;	
			aux = aux->prox;
			// //debug printf("\twhile(aux != NULL)FINAL\n");
		}
		
		
		
		// /*debug*/ printf("\tSAI DO LOOP DE EXEC\n");
		// /*debug*/ debug_imprimeListaProcesso(&cabecaProcesso);

		// //debug printf("logo apos imprimir lista\n");
		// round robin:
		aux = cabecaProcesso;
		if(aux != NULL)
		{
			flagPrimeiroRodou = false;
			// //debug printf("aux eh diferente de null!\n");
			for( i = 0; i < tamanhoLista; i++)
			{
				//debug printf("i=%d, aux->pid.size()=%lu\n", i, aux->pid.size());
				for (j = 0; j < aux->pid.size(); ++j)
				{

					// printf("\tProcesso\t%d\t deltaHora %u:%u x %u\t minstamp\t%u\tprox\t=%p\n"
					// 				,aux->pid[j]
					// 				,aux->deltaHora
					// 				,aux->deltaMin
					// 				,aux->vezes
					// 				,aux->minstamp
					// 				,aux->prox);
					// /*debug*/printf("\tCHECKANDO\ti = %d\tj=%d\n",i,j);
					
					if(aux->pid[j] > 0)
					{
						//Primeiro Processo de todos RODANDO?
						if(!flagPrimeiroRodou){
							//debug printf("0");
							//debug printf("@@@@@@@@@@@@@@@@1 mandei SIGCONT para aux pid[%u]=%d\n", j, aux->pid[j]);
							flagPrimeiroRodou =true;
							kill(aux->pid[j],SIGCONT);
							alarm(QUANTUM);
							pause();
						}
						//debug printf("1");
						//debug printf("@@@@@@@@@@@@@@@@1 mandei sigstop para aux pid[%u]=%d\n", j, aux->pid[j]);
						kill(aux->pid[j],SIGSTOP);

						while(aux->pid[j+1] <= 0 && j < aux->pid.size() - 1)
						{
							//debugprintf("while de pular coisas com j=%d\n", j);
							j++;
						}

						//se ainda tenho pids na lista atual de processos filhos
						if ( j < aux->pid.size() - 1)
						{
							//debug printf("2");
							//debug printf("@@@@@@@@@@@@@@@@2 (if) - mandei SIGCONT para aux pid[%u]=%d\n", j+1, aux->pid[j+1]);
							kill(aux->pid[j+1],SIGCONT);
						}
						else	
						{
							if (aux->prox != NULL && aux->prox->pid[0] > 0)
							{
								//debug printf("3");
								//debug printf("@@@@@@@@@@@@@@@@3 (else if)mandei SIGCONT para aux prox pid[0]=%d\n", aux->prox->pid[0]);
								// primeiro do vetor seguinte. o processo que está na proxima ficah do vetor
								kill(aux->prox->pid[0],SIGCONT);
							}
							// se entra no else eh porque chegou ao final, entao voltamos a dar um cont pra cabeca
							// else
							// {
							// 	//debug printf("4");
							// 	//debug printf("@@@@@@@@@@@@@@@@4 (else else)mandei SIGCONT para cabeca pid[0]=%d\n", cabeca->pid[0]);
							// 	// primeiro do vetor seguinte. o processo que está na proxima ficah do vetor
								
							// }
						}
						//debug printf("#############################ALARME!         begin\n");		
						alarm(QUANTUM);
						pause();
						//debug printf("alarm return:%u\n", alarm_return);
						//debug printf("#############################ALARME!         end\n");	
					}
				}
				if(aux->prox != NULL)
					aux = aux->prox;
			}
			retiraProcessosFinalizados(&cabecaProcesso,&cabecaEstatistica,tamanhoLista);
	
		}	
	}
	return 0 ;
}
