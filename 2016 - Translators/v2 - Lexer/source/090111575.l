/* 	Segundo trabalho de tradutores (2016.2)
	Implementação do Analisador Léxico

	eduardo furtado - 09/0111575
	eduardoxfurtado@gmail.com
*/

/* exemplo para execução ( leia o arquivo leia-me.txt !)
	cd /home/pink/Dropbox/CURSOS/Tradutores/entrega2/
	sh ./090111575.sh 090111575.l codigo_correto1.cstr

	manual:
	flex -o 090111575.l.yy.c 090111575.l;gcc 090111575.l.yy.c -lfl -o 090111575.l.o; ./090111575.l.o < codigo_correto1.cstr
	windows:
	cd C:\Dropbox\CURSOS\Tradutores\Entrega2
	flex -o 090111575.l.yy.c 090111575.l & gcc 090111575.l.yy.c -lfl -o 090111575.l.o & 090111575.l.o < codigo_correto1.cstr
*/

%{	/* declarações begin */
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	/* need this for the call to atof() below */
	#include <math.h>

	#define MAX_IDENTIFIER_LENGTH 255
	#define MAX_STRING_LENGTH 9999

	/* 	estrutura para armazenar os tokens. */
	typedef struct {
		int int_val;
		char str_val[MAX_IDENTIFIER_LENGTH];
		int length;

		/* provavelmente vou precisar de um identificador pra quando for montar a tabela de simbolos */
		int identificador;
	} TokenValue;
	#define YYSTYPE TokenValue

	/* Constantes para cada tipo de token */
	#define RESERVED 					1
	#define OPERATOR 					2
	#define DELIMITATOR 				3
	#define IDENTIFIER 					4
	#define END_INSTRUCTION 			5
	#define COMPARE 					6
	#define ERROR_IDENTIFIER 			7
	#define NUMERIC 					8
	#define IGNORE 						9
	#define ERROR_COMMENT_UNCLOSED 		10
	#define STRING 						11
	#define ERROR_STRING_UNCLOSED 		12
	#define ERROR_STRING_TOO_BIG 		13
	#define ERROR_IDENTIFIER_TOO_BIG 	14

	/*variáveis globais*/
	int g_line_counter   = 1;
	int g_error_counter  = 0;
	int g_column_counter = 1;
	int g_line_counter_for_uncloseds   = 1;
	int g_column_counter_for_uncloseds = 1;
	char g_aux_str[MAX_STRING_LENGTH];
	int g_result_from_parse_string;

	/*declaração das funções usadas*/
	int parse_multiple_line_comments();
	int parse_single_line_comments();
	int parse_string();

%}	/* declarações end	 */

/* Recomendado por um veterano... :) */
/* Na seção de declarações, você pode passar opções para o flex... */
/* bison-bridge - declara variavel inicial yyval para integracao com o bison */
/* noyywrap - remove a necessidade de implementacao do yywrap (seja la o que for esse yywrap) */
/* o noyywrap significa que não vai ter reentrancia*/
%option bison-bridge noyywrap

/*	Macros begin	*/
digit     	[0-9]
letter    	[A-Za-z]
ID       	[a-z][a-z0-9]*
/*	Macros end 		*/

%%	/* regras begin	*/
\n 			{ yylval->length = 0; g_line_counter++; g_column_counter = 1; yylval->length = 0; return IGNORE;}
" " 		{ yylval->length = strlen(yytext); return IGNORE;}
\s 			{ yylval->length = strlen(yytext); return IGNORE;}
\t 			{ yylval->length = strlen(yytext); return IGNORE;}

"/*"		{ yylval->length = strlen(yytext); return parse_multiple_line_comments(); }
"//"		{ yylval->length = strlen(yytext); return parse_single_line_comments(); }

"="			{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return OPERATOR; }
"*"			{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return OPERATOR; }
"/"			{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return OPERATOR; }
"+"			{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return OPERATOR; }
"-"			{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return OPERATOR; }
"."			{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return OPERATOR; }

"=="		{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return COMPARE; }
"<"			{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return COMPARE; }
">"			{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return COMPARE; }
"<="		{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return COMPARE; }
">="		{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return COMPARE; }
"!="		{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return COMPARE; }


[0-9]+		{ yylval->length = strlen(yytext); yylval->int_val = atoi(yytext); return NUMERIC; }

"("			{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return DELIMITATOR; }
")"			{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return DELIMITATOR; }
"["			{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return DELIMITATOR; }
"]"			{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return DELIMITATOR; }
"{"			{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return DELIMITATOR; }
"}"			{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return DELIMITATOR; }
","			{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return DELIMITATOR; }

"\""		{ 	g_result_from_parse_string = parse_string();

				/*if (g_result_from_parse_string != ERROR_STRING_TOO_BIG)
					strcpy(yylval->str_val, g_aux_str); */

				if (g_result_from_parse_string != ERROR_STRING_UNCLOSED)
					yylval->length = strlen(g_aux_str);
				else
					yylval->length = 0;

				return g_result_from_parse_string;
}

";"			{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return END_INSTRUCTION; }

"if"		{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return RESERVED; }
"else" 		{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return RESERVED; }
"while"		{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return RESERVED; }
"int"		{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return RESERVED; }
"float"		{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return RESERVED; }
"string"	{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return RESERVED; }
"void"		{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return RESERVED; }
"return"	{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return RESERVED; }

[_a-zA-Z][_a-zA-Z0-9]* {
	yylval->length = strlen(yytext);
	if (yylval->length > MAX_IDENTIFIER_LENGTH)
	{
		g_error_counter++;
		strcpy(g_aux_str, yytext);
		return ERROR_IDENTIFIER_TOO_BIG;
	}
	else
	{
		strcpy(yylval->str_val, yytext);
		return IDENTIFIER;
	}
}

[0-9]+[_a-zA-Z]+[_a-zA-Z0-9]* {
	g_error_counter++; strcpy(yylval->str_val, yytext); yylval->length = strlen(yytext); return ERROR_IDENTIFIER;
}

.			{ g_error_counter++; yylval->length = strlen(yytext); return *yytext; }
%%	/* regras end	 */

/* regras abaixo: fiquei na duvida se colocava ou não. Decidi não colocar :)
"!"			{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return OPERATOR; }
"~"			{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return OPERATOR; }
"&&"		{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return COMPARE; }
"||"		{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return COMPARE; }
"|"			{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return OPERATOR; }
"char" 		{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return RESERVED; }
"'"			{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return DELIMITATOR; }

alterado pra tirpo string, não mostro mais apenas como delimitador:
"\""		{ yylval->length = strlen(yytext); strcpy(yylval->str_val, yytext); return DELIMITATOR; }
*/

int parse_multiple_line_comments()
{
    int c;
    int flag_is_multiple_line_comments = 0;
    g_line_counter_for_uncloseds = g_line_counter;
    g_column_counter_for_uncloseds = g_column_counter;

    while ( (flag_is_multiple_line_comments!=1) && ((c = input()) != EOF) )
    {
    	/*incremento o contador de colunas porque foi lido um novo caractere:*/
    	g_column_counter++;
        /*printf(">%c<", c);*/
        if (c == '*')
        {
        	/*busco pelo seguinte caractere, para ver se fecha*/
            while ((c = input()) == '*');
            /*incremento o contador de colunas porque foi lido um novo caractere:*/
            g_column_counter++;
            if (c == '/')
            {
                flag_is_multiple_line_comments=1;
            }
        }
        else if (c == '\n')
        {
        	/* printf("\nline counter = %d\n", g_line_counter); */
        	g_line_counter++;
        	/* reinicia o contador de colunas porque pulou uma linha*/
        	g_column_counter = 1;
        }
    }

    if(flag_is_multiple_line_comments==0)
    {
    	g_error_counter++;
    	/*printf("L%d.C%d - erro: '/*' Comentário não finalizado",g_line_counter,g_column_counter);*/
    	return ERROR_COMMENT_UNCLOSED;
    }
    else
    {
    	return IGNORE;
    }
}

int parse_single_line_comments()
{
	int c;
	int flag_is_single_line_comments_done = 0;

	while ( (flag_is_single_line_comments_done!=1) && ((c = input()) != EOF) )
    {
    	/*incremento o contador de colunas porque foi lido um novo caractere:*/
    	g_column_counter++;
        /*printf(">%c<", c);*/
		if (c == '\n')
        {
        	/* printf("\nline counter = %d\n", g_line_counter); */
        	g_line_counter++;
        	/* reinicia o contador de colunas porque pulou uma linha*/
        	g_column_counter = 1;
        	/*atualiza a flag, pra sair daqui!*/
        	flag_is_single_line_comments_done = 1;
        }
    }

    return IGNORE;
}

int parse_string(){
	int c;
	int flag_is_parse_string_done = 0;
	char string[MAX_STRING_LENGTH];
	size_t cur_len;

	/*inicializo a string auxiliar*/
	string[0] = '"';
	string[1] = '\0';

	g_line_counter_for_uncloseds = g_line_counter;
    g_column_counter_for_uncloseds = g_column_counter;

	while ( (flag_is_parse_string_done!=1) && ((c = input()) != EOF) )
    {
		if (c == '"')
        {
        	flag_is_parse_string_done = 1;
        }
        else if (c == '\n')
      	{
  			g_line_counter++;
  			/* reinicia o contador de colunas porque pulou uma linha*/
    		g_column_counter = 1;
    		/*adiciona o fechamento da string no fim dela:*/
    		/*if(cur_len+1 < MAX_STRING_LENGTH)
			{
			    string[cur_len+1] = '"';
			    string[cur_len+2] = '\0';
			}
			else
			{
			    strcpy(g_aux_str, string);
			    return ERROR_STRING_TOO_BIG;
			}*/
			strcpy(g_aux_str, string);
			g_error_counter++;
    		return ERROR_STRING_UNCLOSED;
      	}
  		cur_len = strlen(string);
		if(cur_len < MAX_STRING_LENGTH)
		{
		    string[cur_len] = c;
		    string[cur_len+1] = '\0';
		}
		else
		{
		    /*printf("\nfaltou espaco para armazenar a string lida!\n");*/
		    string[MAX_STRING_LENGTH-1] = '\0';
		    strcpy(g_aux_str, string);
		    g_error_counter++;
		    return ERROR_STRING_TOO_BIG;
		}
    }

    strcpy(g_aux_str, string);
    return STRING;
}

int main()
{
	int token;
	/* declaro yylval para passar por referência*/
	YYSTYPE yylval;

	printf("rodando analise lexica...\n");

	while ((token = yylex(&yylval)))
	{

		switch (token)
		{
			case IDENTIFIER:
				printf("L:%d:%d\tIdentificador: \t\t%s\n", g_line_counter, g_column_counter, yylval.str_val);
				break;
			case NUMERIC:
				printf("L:%d:%d\tNumero: \t\t%d\n", g_line_counter, g_column_counter, yylval.int_val);
				break;
			case OPERATOR:
				printf("L:%d:%d\tOperador binario \t%s\n", g_line_counter, g_column_counter, yylval.str_val);
				break;
			case COMPARE:
				printf("L:%d:%d\tExpressao relacional: \t%s\n", g_line_counter, g_column_counter, yylval.str_val);
				break;
			case RESERVED:
				printf("L:%d:%d\tReservada: \t\t%s\n", g_line_counter, g_column_counter, yylval.str_val);
				break;
			case DELIMITATOR:
				printf("L:%d:%d\tDelimitador: \t\t%s\n", g_line_counter, g_column_counter, yylval.str_val);
				break;
			case STRING:
				printf("L:%d:%d\tString: \t\t%s\n", g_line_counter, g_column_counter_for_uncloseds, g_aux_str);
				break;
			case END_INSTRUCTION:
				printf("L:%d:%d\tFim de instrucao: \t;\n", g_line_counter, g_column_counter);
				break;
			case ERROR_COMMENT_UNCLOSED:
				printf("\nERRO!\tL:%d:%d\tComentario nao fechado:\t/* (nao foi encontrado */)\n\n", g_line_counter_for_uncloseds, g_column_counter_for_uncloseds);
				break;
			case ERROR_STRING_UNCLOSED:
				printf("\nERRO!\tL:%d:%d\tString nao fechada:\t%s\n\n", g_line_counter_for_uncloseds, g_column_counter_for_uncloseds, g_aux_str);
				break;
			case ERROR_STRING_TOO_BIG:
				printf("\nERRO!\tL:%d:%d\tFaltou espaco para armazenar a string lida. Tamanho maximo:\t%d caracteres\n\n", g_line_counter, g_column_counter, MAX_STRING_LENGTH);
				break;
			case ERROR_IDENTIFIER:
				printf("\nERRO!\tL:%d:%d\tIdentificador invalido:\t%s\n\n", g_line_counter, g_column_counter, yylval.str_val);
				break;
			case ERROR_IDENTIFIER_TOO_BIG:
				printf("\nERRO!\tL:%d:%d\tIdentificador grande demais:\t%s (O maior tamanho permitido e: %d caracteres)\n\n", g_line_counter, g_column_counter, g_aux_str, MAX_IDENTIFIER_LENGTH);
				break;
			case IGNORE:
				break;
			default:
				printf("\nERRO!\tL:%d:%d\tCaractere invalido:\t%c\n\n", g_line_counter, g_column_counter, (char) token);
				break;
		}

		/* depois de mostar o g_column_counter eu somo a ele o length do token mostrado. esse contador é zerado a cada nova linha lida */
		g_column_counter += yylval.length;
	}

	printf("\nAnalise lexica: DONE! Numero de erros: %d\n\n", g_error_counter);

	/*printf("\nTO-DO: mudar o #define YYSTYPE TokenValue de union para struct. mas terminar de ler antes as consquencias!!!!!!\n");*/
	/*printf("\nTO-DO: mostrar tambem as colunas!!!!!\n");*/
	/* printf("\nTO-DO: identificar comentarios no codigo!!!!!\n"); */

	return 0;
}