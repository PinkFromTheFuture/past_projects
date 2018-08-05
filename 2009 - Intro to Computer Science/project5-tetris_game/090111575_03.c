/* Universidade de Brasília
 * Instituto de Ciências Exatas
 * Departamento de Ciência da Computação
 *
 * Computação Básica – 02/2009
 *
 * Aluno(a): Eduardo Furtado Sá Corrêa
 * Matrícula: 09/0111575
 * Turma: A
 * Versão do compilador: gcc version 3.4.5 (mingw-vista special)
 *
 * Descrição: Jogo de tetris da disciplica de CB
 * Obs: Este aplicativo le o arquivo "sequencias.txt" do mesmo diretorio de seu executavel
 */
#ifdef _WIN32
#include <windows.h>
#else
#include <time.h>
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*INICIO funcao que mostra na tela o que o usuario ve quando abre o jogo*/
void inicial(char jogo[][21]){
    int i;
    printf("  *** CBetris 2009-2 ***\n");
    printf("  +--------------------+");
    printf("\n");
    for(i=0;i<6;i++){
        printf("  |%s|\n",jogo[i]);

    }
    printf("=>+%s+<=\n",jogo[6]);
    for(i=7;i<15;i++){
        printf("  |%s|\n",jogo[i]);
    }
    printf("  +--------------------+");
    printf("\nTecle <enter> para iniciar o jogo");
}
/*FIM funcao que mostra na tela o que o usuario ve quando abre o jogo*/

/*INICIO funcao chamda sempre que o jogo for renderizado*/
void mostra(char jogo[][21],int pontos){
    int i;

    system("cls || clear");
    printf("  *** CBetris 2009-2 ***\t\tPONTUACAO: %d\n",pontos);
    printf("  +--------------------+");
    printf("\n");
    for(i=0;i<6;i++){
        printf("  |%s|\n",jogo[i]);
    }
    printf("=>+%s+<=\n",jogo[6]);
    for(i=7;i<15;i++){
        printf("  |%s|\n",jogo[i]);
    }
    printf("  +--------------------+");
    printf("\nR-rotar D-direita E-esquerda C-cair");
    printf("\nACAO: ");
}
/*FIM funcao chamda sempre que o jogo for renderizado*/

/*INICIO funcao que insere uma peca nova na matriz*/
void insert(char jogo[][21],char seq[],int *x1,int *x2,int *y1,int *y2,int *axis){
    int i = 0,len;
    len = strlen(seq);

    /* cada peca inserida na matriz jogo, vindo da matriz que guarda as pecas recebe
     * pares de coordenadas e uma quinta para sua orientacao */
    *x1 = 10;
    *x2 = 10;
    *y1 = len-1;
    *y2 = 0;
    *axis = 0;
    for(i=0;i<len;i++){
        jogo[i][10] = seq[i];
    }
}
/*FIM funcao que insere uma peca nova na matriz*/

/*INICIO funcao que enche a matriz do jogo de X quando o jogador perde*/
void fail(char jogo[][21]){
    int i,j;
    for(i=0;i<15;i++){
        for(j=0;j<20;j++){
            jogo[i][j] = 'X'; /*preenche tudo com X*/
        }
    }
}
/*FIM funcao que enche a matriz do jogo de X quando o jogador perde*/

/*INICIO funcao que verifica se completou linhas, depois se o jogador perdeu*/
int check(char jogo[][21], int *pontos){
    int i,j=0,k;

    for(j = 14; j>6;j--){
        i = 0;
        while ( (jogo[j][i] != 32 ) && (i <20 )){
            i++;
        }
        if ( i == 20){

            for(i=0;i<20;i++){
                jogo[j][i] = 'X';
            }
            *pontos = *pontos + 100;
            mostra(jogo,*pontos);
            #ifdef _WIN32
            Sleep(50);
            #else
            nanosleep(50*1000000);
            #endif
            for(i=j;i>3;i--){
                for(k=0;k<20;k++){
                    jogo[i][k] = jogo[i-1][k];
                }
            }
            return 0;
        }
    }
    i=0;
    while ( (jogo[6][i] == 32 ) && (i <20 )){ /*verifica se passou da altura maxima permitida*/
        i++;
    }
    if(i!=20){
        fail(jogo);
        *pontos = 0;
        mostra(jogo,*pontos);
        printf("\n*** YOU LOSE!!!Tecle <enter> para sair");
        return -1;
    }
    return 1;
}
/*INICIO funcao que verifica se completou linhas, depois se o jogador perdeu*/

/*INICIO  da funcao que roda a peca */
void rotar(char jogo[][21],int *x1,int *x2,int *y1,int *y2,int *axis){
    char aux;
    int i;
    if(*axis == 0){ /*entra aqui se ela estiver na vertical*/
        if( *y1 - *y2 + *x2 < 20 ){ /*entra aqui se for possivel girar a peca */
            aux = jogo[*y1][*x1];
            for(i=*y2;i<=*y1;i++){
                jogo[i][*x1] = 32;
                jogo[1][*x1+*y1-i] = aux;
            }
            *x2 = *x2+*y1;
            *y1 = 1;
            *y2 = *y1;
            *axis = 1;
            return;
        }
    }else{ /*entra aqui se estiver na horizontal*/
        aux = jogo[*y1][*x1];
        for(i=*x1;i<=*x2;i++){
            jogo[*y2][i] = 32;
            jogo[*y1-1][*x1] = aux;
            *y1 = *y1 + 1;
        }
        *y1 = *y1 - 2;
        *y2 = 0;
        *x2 = *x1;
        *axis = 0;
        return ;
    }
}
/*FIM da funcao que roda a peca */

/*INICIO funcao que move a peca para a direita*/
void direita(char jogo[][21],int *x1,int *x2,int *y1,int *y2){
    char aux;
    int i;

    if(*x2 == 19){
        return;
    }
    aux = jogo[*y1][*x1];
    for(i=*x2;i>=*x1;i--){
        jogo[*y1][i] = 32;
        jogo[*y1][i+1] = aux;
    }
    for(i=*y2;i<=*y1;i++){
        jogo[i][*x1] = 32;
        jogo[i][*x1+1] = aux;
    }
    *x1 = *x1+1;
    *x2 = *x2+1;
}
/*FIM funcao que move a peca para a direita*/

/*INICIO funcao que move a peca para a esquerda*/
void esquerda(char jogo[][21],int *x1,int *x2,int *y1,int *y2){
    char aux;
    int i;

    if(*x1 == 0){
        return;
    }
    aux = jogo[*y1][*x1];
    for(i=*x1;i<=*x2;i++){
        jogo[*y1][i-1] = aux;
        jogo[*y1][i] = 32;
    }
    for(i=*y2;i<=*y1;i++){
        jogo[*y1-i][*x1] = 32;
        jogo[i][*x1-1] = aux;
    }
    *x1 = *x1-1;
    *x2 = *x2-1;
}
/*FIM funcao que move a peca para a esquerda*/

/*INICIO funcao que faz a peca cair*/
int cair(char jogo[][21], int *pontos,char seq[],int *x1,int *x2,int *y1,int *y2,int *axis){
    int linha = 6,cont = 1,i,lose,j;
    char aux = jogo[*y1][*x1];

    if(*axis == 0){
        while ( (jogo[linha][*x1] == 32 ) && (linha<17)){
            linha++;
        }
        linha--;
        j = *y1;
        for(i=*y2;i<linha-*y1;i++){
            jogo[i][*x1] = 32;
            j++;
            jogo[j][*x1] = aux;
            #ifdef _WIN32
            Sleep(10); /* Para Windows */
            #else
            nanosleep(10*1000000); /* Outros */
            #endif
            mostra(jogo,*pontos);

        }
    }else{
        linha = 5;
        while((cont != 0) && (linha < 17)) {
            linha++;
            cont = 1;
            for(i=*x1;i<=*x2;i++){
                if(jogo[linha][i] != 32 ){
                    cont = 0;
                }
            }
        }
        for(j=*y2;j<linha-*y1;j++){
            for(i=*x1;i<=*x2;i++){
                jogo[j][i] = 32;
                jogo[j+1][i] = aux;
            }
            #ifdef _WIN32
            Sleep(10);
            #else
            nanosleep(10*1000000);
            #endif
            mostra(jogo,*pontos);
        }
    }
    do{
        lose = check(jogo,pontos);
    }while (lose == 0);
    return lose;
}
/*FIM funcao que faz a peca cair*/

/*INICIO funcao que le a acao desejada do jogador e chama a funcao correspondente*/
int action(char jogo[][21], int *pontos,char seq[],int *x1,int *x2,int *y1,int *y2,int *axis){
    char ac; /*variavel digitada pelo usuario, determina qual a jogada dele*/
    int lose;

    scanf("%c",&ac);
    getchar();
    if( (ac != 'R') && (ac != 'r') && (ac != 'd') && (ac != 'D') &&
      (ac != 'e') && (ac != 'E') && (ac != 'c') && (ac != 'C')  ){
        return 0;
    }else{
        if((ac == 'R') || (ac == 'r')){
            rotar(jogo,x1,x2,y1,y2,axis);
            return 0;
        }else{
            if((ac == 'd') || (ac == 'D')){
                direita(jogo,x1,x2,y1,y2);
                return 0;
            }else{
                if((ac == 'E') || (ac == 'e')){
                    esquerda(jogo,x1,x2,y1,y2);
                    return 0;
                }else{
                    lose = cair(jogo,pontos,seq,x1,x2,y1,y2,axis);
                    return lose;
                }
            }
        }
    }
    return 0;
}
/*FIM funcao que le a acao desejada do jogador e chama a funcao correspondente*/

/*INICIO funcao que exporta as pecas do HD para a memoria RAM*/
int import(char seq[][10],char end[]){
    int j=0;
    FILE *fp; /*ponteiro para o arquivo contendo as pecas*/

    fp = fopen(end,"r+"); /*abre o arquivo*/
    if(fp == NULL){ /*entra aqui se o arquvio nao existir, e depois termina o programa*/
        printf("\n\nERRO!!! arquivo sequencias.txt nao encontrado!!!\n\nterminando execucao do programa..");
        fclose(fp);
    return 0;
    }
    while (fscanf(fp,"%s",seq[j]) > 0) {
        j++;
    }
    fclose(fp);
    return j; /*retorna o numero de pecas lidas*/
}
/*FIM funcao que exporta as pecas do HD para a memoria RAM*/


int main(){
    char jogo[15][21]; /*matriz principal do jogo*/
    char seq[200][10];  /*matriz que armazena na memoria as pecas*/
    char end[50] = "sequencias.txt"; /*para ler o arquivo sequencias.txt da pasta do executavel*/
    int i,j,pecas,acao, pontos =0; /*i,j sao auxiliares. pecas e pontos guardam esses valores*/
    int x1,x2,y1,y2,axis; /*variaveis de coordenada relacionado as pecas.*/
    /* axis = 0 se estiver na vertical. axis = 1 se peca na horizontal*/

    for(i=0;i<15;i++){ /*preenche a matriz principal com espacos em branco*/
        for(j=0;j<20;j++){
            jogo[i][j] = 32;
        }
        jogo[i][j] = '\0';
    }
    pecas = import(seq,end); /*import retorna o numero de pecas lidas*/
    if(pecas == 0){
        getchar();
        return 0;
        /*sai do programa se nao tiver pecas*/
    }
    inicial(jogo);
    getchar();
    for(i=0;i<pecas;i++){
        insert(jogo,seq[i],&x1,&x2,&y1,&y2,&axis);
        do{
            mostra(jogo,pontos);
            acao = action(jogo,&pontos,seq[i],&x1,&x2,&y1,&y2,&axis);
            /* action retorna -1 se o jogador perder*/
            /* action retorna 0 se o jogador mover uma peca*/
            /* action retorna 1 se o jogador fizer uma peca cair*/
            if(acao == (-1)){
                getchar();
                return 0;
                /*sai do programa se a altura passar do limite (perde o jogo)*/
            }
        }while (acao != 1);
    }
    mostra(jogo,pontos);
    printf("\n\n*** PARABENS!!! VOCE CHEGOU AO FIM DO JOGO COM %d PONTOS!!!",pontos);
    printf("\nTecle <enter> para sair\n\n");
    return 0;
}
