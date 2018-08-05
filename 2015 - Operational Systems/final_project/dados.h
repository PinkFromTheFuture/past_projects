#ifndef DADOS_MOD
#define DADOS_MOD


#define MATRICULA 100033571
#define QUANTUM 10
#define TIPOAGENDAMENTO 1
#define TIPOCANCELAMENTO 2
#define TIPOKILLSERVER 3
#define TIPOLISTARPROCESSOS 4
#include <vector>
/*CONSTANTES DE TIPO DE MENSAGEM*/
typedef enum {
	Agendamento = 1,
	Remocao,
	Cancelamento,
	Listagem
}TiposMensagem;

/*Tipo mensagem, esse tipo de mensagem será usado para conversa entre programas como o agendador, o escalonador
removedor e etc*/
typedef struct{
	long int mtype;  
	long int jobId;
	char executavel[300];
	unsigned int vezes;
	unsigned int hora;
	unsigned int min;
} t_msg;

typedef struct t_processo{
	long int jobId;  
	char executavel[300];
	unsigned int vezes;
	unsigned int deltaHora;
	unsigned int deltaMin;
	unsigned int horaInsercao;
	unsigned int minInsercao;
	unsigned int minstamp;
	unsigned int startHora;
	unsigned int startMinuto;
	std::vector <int> pid;
	bool estaExecutando;
	struct t_processo* prox;
} t_processo;

typedef struct t_estatisticaProcesso{
	long int jobId; 
	int pid;
	char executavel[300];
	unsigned int horaInicio;
	unsigned int minInicio;
	unsigned int horaStart;
	unsigned int minStart;
	unsigned int horaFinal;
	unsigned int minFinal;
	struct t_estatisticaProcesso* prox;
} t_estatisticaProcesso;

/*DECLARAÇÕES DE FUNÇÕES DO IPCS*/
void exit(int algo);
int fork();
void sleep (int seg);
/*DECLARAÇÕES DE FUNÇÕES DO IPCS*/

/*DECLARAÇÕES DE CONSTANTES*/
char EComercial[2] = "&";
unsigned int const size_msg = sizeof(t_msg)-sizeof(long);
unsigned int const size_processo = sizeof(t_processo);
unsigned int const size_estatistica = sizeof(t_estatisticaProcesso);
#endif
