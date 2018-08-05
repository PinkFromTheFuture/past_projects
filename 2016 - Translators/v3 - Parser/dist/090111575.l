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

	#include "090111575.tab.h" // to get the token types that we return

	#define MAX_IDENTIFIER_LENGTH 255
	#define MAX_STRING_LENGTH 9999

	/* 	estrutura para armazenar os tokens. */
	// typedef struct {
	// 	int int_value;
	// 	char str_value[MAX_IDENTIFIER_LENGTH];
	// 	int length;

	// 	 provavelmente vou precisar de um identificador pra quando for montar a tabela de simbolos 
	// 	int identificador;
	// } TokenValue;
	// #define YYSTYPE TokenValue

	/* Constantes para cada tipo de token */
	#define RESERVED 					1
	#define DELIMITATOR 				3
	#define END_INSTRUCTION 			5
	#define ERROR_IDENTIFIER 			7
	#define IGNORE 						9
	#define ERROR_COMMENT_UNCLOSED 		10
	#define ERROR_STRING_UNCLOSED 		12
	#define ERROR_STRING_TOO_BIG 		13
	#define ERROR_IDENTIFIER_TOO_BIG 	14
	#define ERROR_INVALID_CHARACTER 	15

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
	void print_error(int error_number, char * token);

%}	/* declarações end	 */

/* Recomendado por um veterano... :) */
/* Na seção de declarações, você pode passar opções para o flex... */
/* noyywrap - remove a necessidade de implementacao do yywrap (seja la o que for esse yywrap) */
/* o noyywrap significa que não vai ter reentrancia*/
%option noyywrap
/* opção abaixo remove o seguinte warning: 'yyunput' defined but not used [-Wunused-function]*/
%option nounput

/*	Macros begin	*/
digit     	[0-9]
letter    	[A-Za-z]
ID       	[a-z][a-z0-9]*
/* fim de linha */
NEWLINE  "\n"|"\r"|"\r\n"
/* espaços em braco*/
BLANCS  [ \t\v\f]
/*	Macros end 		*/

%%	/* regras begin	*/
{NEWLINE}	{ g_line_counter++; g_column_counter = 1;}
{BLANCS}+	{ g_column_counter += strlen(yytext); }

"/*"		{ g_column_counter += strlen(yytext); parse_multiple_line_comments(); }
"//"		{ g_column_counter += strlen(yytext); parse_single_line_comments(); }

"="			{ g_column_counter += strlen(yytext); yylval.char_value = yytext[0]; return '='; }
"*"			{ g_column_counter += strlen(yytext); yylval.char_value = yytext[0]; return '*'; }
"/"			{ g_column_counter += strlen(yytext); yylval.char_value = yytext[0]; return '/'; }
"+"			{ g_column_counter += strlen(yytext); yylval.char_value = yytext[0]; return '+'; }
"-"			{ g_column_counter += strlen(yytext); yylval.char_value = yytext[0]; return '-'; }
"."			{ g_column_counter += strlen(yytext); yylval.char_value = yytext[0]; return '.'; }
":"			{ g_column_counter += strlen(yytext); yylval.char_value = yytext[0]; return ':'; }

"=="		{ g_column_counter += strlen(yytext); strcpy(yylval.str_value, yytext); return EqualTo; }
"<"			{ g_column_counter += strlen(yytext); strcpy(yylval.str_value, yytext); return LessThan; }
">"			{ g_column_counter += strlen(yytext); strcpy(yylval.str_value, yytext); return GreaterThan; }
"<="		{ g_column_counter += strlen(yytext); strcpy(yylval.str_value, yytext); return LessThanOrEqualTo; }
">="		{ g_column_counter += strlen(yytext); strcpy(yylval.str_value, yytext); return GreaterThanOrEqualTo; }
"!="		{ g_column_counter += strlen(yytext); strcpy(yylval.str_value, yytext); return NotEqualTo; }


[0-9]+		{ g_column_counter += strlen(yytext); strcpy(yylval.str_value, yytext); return NUMBER; }

"("			{ g_column_counter += strlen(yytext); strcpy(yylval.str_value, yytext); return '('; }
")"			{ g_column_counter += strlen(yytext); strcpy(yylval.str_value, yytext); return ')'; }
"{"			{ g_column_counter += strlen(yytext); strcpy(yylval.str_value, yytext); return '{'; }
"}"			{ g_column_counter += strlen(yytext); strcpy(yylval.str_value, yytext); return '}'; }
","			{ g_column_counter += strlen(yytext); strcpy(yylval.str_value, yytext); return ','; }

"\""		{ 	g_result_from_parse_string = parse_string();
				/*if (g_result_from_parse_string != ERROR_STRING_TOO_BIG)
					strcpy(yylval.str_value, g_aux_str); */

				if (g_result_from_parse_string == TEXT)
				{
					strcpy(yylval.str_value, g_aux_str);
					return g_result_from_parse_string;
				}
				else
				{
					print_error(g_result_from_parse_string, g_aux_str);
				}

}

";"			{ g_column_counter += strlen(yytext); strcpy(yylval.str_value, yytext); return ';'; }

"if"		{ g_column_counter += strlen(yytext); strcpy(yylval.str_value, yytext); return IF; }
"else" 		{ g_column_counter += strlen(yytext); strcpy(yylval.str_value, yytext); return ELSE; }
"while"		{ g_column_counter += strlen(yytext); strcpy(yylval.str_value, yytext); return WHILE; }
"int"		{ g_column_counter += strlen(yytext); strcpy(yylval.str_value, yytext); return INT; }
"string"	{ g_column_counter += strlen(yytext); strcpy(yylval.str_value, yytext); return STRING; }
"void"		{ g_column_counter += strlen(yytext); strcpy(yylval.str_value, yytext); return VOID; }
"return"	{ g_column_counter += strlen(yytext); strcpy(yylval.str_value, yytext); return RETURN; }

[_a-zA-Z][_a-zA-Z0-9]* {
	if (strlen(yytext) > MAX_IDENTIFIER_LENGTH)
	{
		g_error_counter++;
		strcpy(g_aux_str, yytext);
		print_error(ERROR_IDENTIFIER_TOO_BIG, yytext);
		g_column_counter += strlen(yytext);
	}
	else
	{
		strcpy(yylval.str_value, yytext);
		g_column_counter += strlen(yytext);
		return Identifier;
	}
}

[0-9]+[_a-zA-Z]+[_a-zA-Z0-9]* { print_error(ERROR_IDENTIFIER, yytext); g_column_counter += strlen(yytext);
	// g_error_counter++; strcpy(yylval.str_value, yytext); g_column_counter += strlen(yytext); return ERROR_IDENTIFIER;
}

.			{ g_error_counter++; g_column_counter += strlen(yytext); print_error(ERROR_INVALID_CHARACTER, yytext);}
%%	/* regras end	 */


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
    	//printf("L%d.C%d - erro: '/*' Comentário não finalizado",g_line_counter,g_column_counter);
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

int parse_string()
{
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
    return TEXT;
}

void print_error(int error_number, char * token)
{
	switch (error_number)
	{
		case ERROR_COMMENT_UNCLOSED:
			printf("\nERRO LEXICO!\tL:%d:%d\tComentario nao fechado:\t)\n\n", g_line_counter_for_uncloseds, g_column_counter_for_uncloseds);
			break;
		case ERROR_STRING_UNCLOSED:
			printf("\nERRO LEXICO!\tL:%d:%d\tString nao fechada:\t%s\n\n", g_line_counter_for_uncloseds, g_column_counter_for_uncloseds, g_aux_str);
			break;
		case ERROR_STRING_TOO_BIG:
			printf("\nERRO LEXICO!\tL:%d:%d\tFaltou espaco para armazenar a string lida. Tamanho maximo:\t%d caracteres\n\n", g_line_counter, g_column_counter, MAX_STRING_LENGTH);
			break;
		case ERROR_IDENTIFIER:
			printf("\nERRO LEXICO!\tL:%d:%d\tIdentificador invalido:\t%s\n\n", g_line_counter, g_column_counter, token);
			break;
		case ERROR_IDENTIFIER_TOO_BIG:
			printf("\nERRO LEXICO!\tL:%d:%d\tIdentificador grande demais:\t%s (O maior tamanho permitido e: %d caracteres)\n\n", g_line_counter, g_column_counter, g_aux_str, MAX_IDENTIFIER_LENGTH);
			break;
		case IGNORE:
			break;
		default:
			printf("\nERRO LEXICO!\tL:%d:%d\tCaractere invalido:\t%s\n\n", g_line_counter, g_column_counter, token);
			break;
	}
}

