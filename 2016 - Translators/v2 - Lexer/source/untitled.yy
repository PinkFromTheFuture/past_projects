%{
	// digo o que vou usar
	#include <studio.h>

	// define o tipo de informação que vamos passar pra ele:
	#define YYSTYPE double

	// geramos esta funcao com o flex, que eh padrao
	extern int yylex();

	// definimos uma funcao de erro
	void yyerror (char const *);
%}

// define um novo não-terminal (tokens) chamado NUM
%token NUM

%% /*regras gramaticais*/

// aqui comeca a minha gramatica, uma palavras válida é zero ou mais linhas de entrada

input:
	// string vazia
	| input line
;

// linha é uma linha vazia ou uma expressao seguida de quebra de linha
line:
	'\n'
	| exp '\n' { printf ("% 10g\n", $1); }
;

// define recursivamente as possíveis expressões
exp:
	NUM { $$ = $1; }
	| exp exp '+' { $$ = $1 + $2; }
	| exp exp '-' { $$ = $1 - $2; }
	| exp exp '*' { $$ = $1 * $2; }
	| exp exp '/' { $$ = $1 / $2; }