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
 * Descrição: Ferramenta para cadastro imobiliario
 */
#include <stdio.h>
#include <string.h>

int main(){ /*inicio do metodo principal*/
    /*Inicio da declaracao de variaveis*/
    char LOOPER = 's'; /*usada para dar continuidade ao programa*/
    /*inicio da declaracao das variaveis de leitura*/
    char END[50][41],OBS[50][51],DATA[50][9];
    float METROS[50],PRECO[50];
    char CTGR[50],GARAGEM[50];
    int COD[50],TIPO[50],NQUARTOS[50];
    /*fim da declaracao das variaveis de leitura*/
    int i,flag = 1,j,SAIDA = 0;
    /*inicio da declaracao das variaveis auxiliares*/
    char TIPO_STR[4][13];
    int auxCONT[8] = {};
    int NTOTAL = 0,VENDA=0, ALUGUEL=0;
    float PVENDA=0, PALUGUEL=0;
    char auxSTR[51];
    char auxCHAR;
    float auxFLOAT;
    int auxINT;
    float auxMETROS[8] = {};
    int auxCOD[8];
    /*fim da declaracao das variaveis auxiliares*/
    /*Fim da declaracao de variaveis*/

    while (((LOOPER == 's') || (LOOPER == 'S')) && (NTOTAL<51)){ /*o programa fica todo dentro desse loop*/

        /*inicio da leitura dos dados de entrada*/
        printf("*** Imovel %d ***",NTOTAL+1);
        printf("\nCodigo do imovel: ");
        scanf("%d",&COD[NTOTAL]);
        getchar();
        while(COD[NTOTAL] <= 0){
            printf("Codigo do imovel (nao entre valores negativos ou zero): ");
            scanf("%d",&COD[NTOTAL]);
            getchar();
        }

        printf("Categoria (\"V\" para venda, ou \"A\" para aluguel): ");
        scanf("%c",&CTGR[NTOTAL]);
        getchar();
        while( (CTGR[NTOTAL] != 'v') && (CTGR[NTOTAL] != 'V') && (CTGR[NTOTAL] != 'A') && (CTGR[NTOTAL] != 'a') ){
            /*esse loop testa se o valor da variavel CTGR entrada e valido*/
            printf("Categoria deve ser \"V\" para venda, ou \"A\" para aluguel.\nCategoria: ");
            scanf("%c",&CTGR[NTOTAL]);
            getchar();
        }
        /*essa tansformacao e necessaria aqui para otimizar depois, na hora de ordenar*/
        if(CTGR[NTOTAL] == 'V'){
            CTGR[NTOTAL] = 'v';
        }else{
            if(CTGR[NTOTAL] == 'A'){
                CTGR[NTOTAL] = 'a';
            }
        }


        printf("Tipo (1-apartamento, 2-casa, 3-lote, 4-loja): ");
        scanf("%d",&TIPO[NTOTAL]);
        getchar();
        while( (TIPO[NTOTAL] != 1) && (TIPO[NTOTAL] != 2) && (TIPO[NTOTAL] != 3) && (TIPO[NTOTAL] != 4) ){
            /*esse loop testa se o valor da variavel TIPO entrada e valido*/
            printf("O tipo do imovel deve ser somente 1, 2, 3, ou 4, sendo que 1 significa apartamento,");
            printf(" 2 significa casa, 3 significa lote, e 4 significa loja.\nTipo: ");
            scanf("%d",&TIPO[NTOTAL]);
            getchar();
        }

        END[NTOTAL][0] = '\0';
        printf("Endereco: ");
        scanf("%[^\n]s",END[NTOTAL]);
        getchar();
        while ( strlen(END[NTOTAL]) == 0 ){
            printf("Erro! O campo foi deixado em branco!\nEndereco: ");
            scanf("%[^\n]s",END[NTOTAL]);
            getchar();
        }

        printf("Numero de quartos (digitar 0 para kitinete, lote, e loja): ");
        scanf("%d",&NQUARTOS[NTOTAL]);
        getchar();
        while( (NQUARTOS[NTOTAL] != 0 ) && ( (TIPO[NTOTAL] == 3) || (TIPO[NTOTAL] == 4) )){
            printf("Numero de quartos para lote ou loja deve ser 0 (zero). Tente novamente: ");
            scanf("%d",&NQUARTOS[NTOTAL]);
            getchar();
        }
        while ( NQUARTOS[NTOTAL] < 0 ){
            printf("Numero de quartos deve ser um valor positivo. Tente novamente: ");
            scanf("%d",&NQUARTOS[NTOTAL]);
            getchar();
        }

        printf("Garagem (S/N):  ");
        scanf("%c",&GARAGEM[NTOTAL]);
        getchar();
        while( (GARAGEM[NTOTAL] != 's') && (GARAGEM[NTOTAL] != 'S') && (GARAGEM[NTOTAL] != 'n') && (GARAGEM[NTOTAL] != 'N') ){
            /*esse loop testa se o valor da variavel GARAGEM entrada e valido*/
            printf("Garagem deve ser somente \"S\", \"s\", \"N\", ou \"n\".\nGaragem: ");
            scanf("%c",&GARAGEM[NTOTAL]);
            getchar();
        }

        printf("Metragem: ");
        scanf("%f",&METROS[NTOTAL]);
        getchar();
        while( METROS[NTOTAL] < 0 ){
            /*esse loop testa se o valor da variavel METROS entrada e valido*/
            printf("Metragem deve ser um valor positivo.\nMetragem: ");
            scanf("%f",&METROS[NTOTAL]);
            getchar();
        }

        printf("Preco: ");
        scanf("%f",&PRECO[NTOTAL]);
        getchar();
        while( PRECO[NTOTAL] < 0 ){
            /*esse loop testa se o valor da variavel PRECO entrada e valido*/
            printf("Preco deve ser um valor positivo.\nPreco: ");
            scanf("%f",&PRECO[NTOTAL]);
            getchar();
        }

        printf("Observacoes: ");
        scanf("%[^\n]s",OBS[NTOTAL]);
        getchar();

        printf("Data de cadastro (DD/MM/AA): ");
        scanf("%s",DATA[NTOTAL]);
        getchar();
        /*fim da leitura dos dados de entrada*/

        /*inicio do loop que pergunta ao usuario se deseja incluir mais imoveis no cadastro*/
        do{
            printf("\nDeseja incluir mais imoveis no cadastro? (S/N): ");
            scanf("%c",&LOOPER);
            getchar();
            printf("\n");
            if((LOOPER != 's') && (LOOPER != 'n') && (LOOPER != 'S') && (LOOPER != 'N')){
                printf("\nErro! Digite 'S' para sim ou 'N' para nao\n");
            }
        } while ((LOOPER != 's') && (LOOPER != 'n') && (LOOPER != 'S') && (LOOPER != 'N'));
        /*fim do loop que pergunta ao usuario se deseja incluir mais imoveis no cadastro*/
        NTOTAL++;
    }/*fim do loop principal do programa. nada mais sera perguntado ao usuario*/

    /*inicio dos testes*/
    for ( i = 0 ; i < NTOTAL; i++){
        if ((CTGR[i] == 'v') || (CTGR[i] == 'V')){
            VENDA++;
            if(TIPO[i] == 1){
                auxCONT[0]++;
                if(METROS[i] > auxMETROS[0]){
                    auxMETROS[0] = METROS[i];
                    auxCOD[0] = COD[i];
                }
            }else{
                if(TIPO[i] == 2){
                    auxCONT[1]++;
                    if(METROS[i] > auxMETROS[1]){
                        auxMETROS[1] = METROS[i];
                        auxCOD[1] = COD[i];
                    }
                }else{
                    if(TIPO[i] == 3){
                        auxCONT[2]++;
                        if(METROS[i] > auxMETROS[2]){
                            auxMETROS[2] = METROS[i];
                            auxCOD[2] = COD[i];
                        }
                    }else{
                        if(TIPO[i] == 4){
                            auxCONT[3]++;
                            if(METROS[i] > auxMETROS[3]){
                                auxMETROS[3] = METROS[i];
                                auxCOD[3] = COD[i];
                            }
                        }
                    }
                }
            }
        }else{
            if ((CTGR[i] == 'a') || (CTGR[i] == 'A')){
                ALUGUEL++;
                if(TIPO[i] == 1){
                    auxCONT[4]++;
                    if(METROS[i] > auxMETROS[4]){
                        auxMETROS[4] = METROS[i];
                        auxCOD[4] = COD[i];
                    }
                }else{
                    if(TIPO[i] == 2){
                        auxCONT[5]++;
                        if(METROS[i] > auxMETROS[5]){
                            auxMETROS[5] = METROS[i];
                            auxCOD[5] = COD[i];
                        }
                    }else{
                        if(TIPO[i] == 3){
                            auxCONT[6]++;
                            if(METROS[i] > auxMETROS[6]){
                                auxMETROS[6] = METROS[i];
                                auxCOD[6] = COD[i];
                            }
                        }else{
                            if(TIPO[i] == 4){
                                auxCONT[7]++;
                                if(METROS[i] > auxMETROS[7]){
                                    auxMETROS[7] = METROS[i];
                                    auxCOD[7] = COD[i];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    PVENDA = (VENDA *100) / NTOTAL;
    PALUGUEL = (ALUGUEL*100) /NTOTAL;
    /*fim dos testes*/

    /*inicio das ordenacoes, tipo booble sort*/
    flag = 1;
    while (flag){ /*ordena preco*/
        flag = 0;
        for ( i = 0; i < NTOTAL-1 ; i++){
            if (PRECO[i] < PRECO[i+1]){
                flag = 1;
                strcpy(auxSTR,END[i]);;
                strcpy(END[i],END[i+1]);
                strcpy(END[i+1],auxSTR);

                strcpy(auxSTR,OBS[i]);;
                strcpy(OBS[i],OBS[i+1]);
                strcpy(OBS[i+1],auxSTR);

                strcpy(auxSTR,DATA[i]);;
                strcpy(DATA[i],DATA[i+1]);
                strcpy(DATA[i+1],auxSTR);

                auxFLOAT = PRECO[i];
                PRECO[i] = PRECO[i+1];
                PRECO[i+1] = auxFLOAT;

                auxFLOAT = METROS[i];
                METROS[i] = METROS[i+1];
                METROS[i+1] = auxFLOAT;

                auxINT = COD[i];
                COD[i] = COD[i+1];
                COD[i+1] = auxINT;

                auxINT = NQUARTOS[i];
                NQUARTOS[i] = NQUARTOS[i+1];
                NQUARTOS[i+1] = auxINT;

                auxINT = TIPO[i];
                TIPO[i] = TIPO[i+1];
                TIPO[i+1] = auxINT;

                auxCHAR = CTGR[i];
                CTGR[i] = CTGR[i+1];
                CTGR[i+1] = auxCHAR;

                auxCHAR = GARAGEM[i];
                GARAGEM[i] = GARAGEM[i+1];
                GARAGEM[i+1] = auxCHAR;
            }
        }
    }

    flag = 1;
    while (flag){ /*ordena tipo*/
        flag = 0;
        for ( i = 0; i < NTOTAL-1 ; i++){
            if (TIPO[i] > TIPO[i+1]){
                flag = 1;
                strcpy(auxSTR,END[i]);;
                strcpy(END[i],END[i+1]);
                strcpy(END[i+1],auxSTR);

                strcpy(auxSTR,OBS[i]);;
                strcpy(OBS[i],OBS[i+1]);
                strcpy(OBS[i+1],auxSTR);

                strcpy(auxSTR,DATA[i]);;
                strcpy(DATA[i],DATA[i+1]);
                strcpy(DATA[i+1],auxSTR);

                auxFLOAT = PRECO[i];
                PRECO[i] = PRECO[i+1];
                PRECO[i+1] = auxFLOAT;

                auxFLOAT = METROS[i];
                METROS[i] = METROS[i+1];
                METROS[i+1] = auxFLOAT;

                auxINT = COD[i];
                COD[i] = COD[i+1];
                COD[i+1] = auxINT;

                auxINT = NQUARTOS[i];
                NQUARTOS[i] = NQUARTOS[i+1];
                NQUARTOS[i+1] = auxINT;

                auxINT = TIPO[i];
                TIPO[i] = TIPO[i+1];
                TIPO[i+1] = auxINT;

                auxCHAR = CTGR[i];
                CTGR[i] = CTGR[i+1];
                CTGR[i+1] = auxCHAR;

                auxCHAR = GARAGEM[i];
                GARAGEM[i] = GARAGEM[i+1];
                GARAGEM[i+1] = auxCHAR;
            }
        }
    }

    flag = 1;
    while (flag){ /*ordena categoria*/
        flag = 0;
        for ( i = 0; i < NTOTAL-1 ; i++){

            if (CTGR[i] - 48 < CTGR[i+1] - 48){
                flag = 1;
                strcpy(auxSTR,END[i]);;
                strcpy(END[i],END[i+1]);
                strcpy(END[i+1],auxSTR);

                strcpy(auxSTR,OBS[i]);;
                strcpy(OBS[i],OBS[i+1]);
                strcpy(OBS[i+1],auxSTR);

                strcpy(auxSTR,DATA[i]);;
                strcpy(DATA[i],DATA[i+1]);
                strcpy(DATA[i+1],auxSTR);

                auxFLOAT = PRECO[i];
                PRECO[i] = PRECO[i+1];
                PRECO[i+1] = auxFLOAT;

                auxFLOAT = METROS[i];
                METROS[i] = METROS[i+1];
                METROS[i+1] = auxFLOAT;

                auxINT = COD[i];
                COD[i] = COD[i+1];
                COD[i+1] = auxINT;

                auxINT = NQUARTOS[i];
                NQUARTOS[i] = NQUARTOS[i+1];
                NQUARTOS[i+1] = auxINT;

                auxINT = TIPO[i];
                TIPO[i] = TIPO[i+1];
                TIPO[i+1] = auxINT;

                auxCHAR = CTGR[i];
                CTGR[i] = CTGR[i+1];
                CTGR[i+1] = auxCHAR;

                auxCHAR = GARAGEM[i];
                GARAGEM[i] = GARAGEM[i+1];
                GARAGEM[i+1] = auxCHAR;
            }
        }
    }
    /*fim das ordenacoes*/

    /*inicio da apresentacao dos dados referentes aos imoveis cadastrados*/
    strcpy(TIPO_STR[0], "APARTAMENTO");
    strcpy(TIPO_STR[1], "CASA");
    strcpy(TIPO_STR[2], "LOTE");
    strcpy(TIPO_STR[3], "LOJA");
    for(j = 0; j < 4; j++){
        if( VENDA > 0 ){
            if (j == 0){
                printf("****************************************************************\n");
                printf("*** CATEGORIA: VENDA ***\n");
                printf("****************************************************************\n\n");
            }
            if( auxCONT[j] > 0 ) {
                printf("TIPO %d: %s\n",j+1,TIPO_STR[j]);
                printf("CODIGO:\t\tENDERECO\t\t\t\tPRECO\n");
                for( i = 0; i< auxCONT[j]; i++){
                    printf("%d\t\t%s\t\t%.2f\n",COD[SAIDA],END[SAIDA],PRECO[SAIDA]);
                    SAIDA++;
                }

                printf("\nTotal de imoveis do tipo %d: %d\n",j+1,auxCONT[j]);
                printf("Codigo do imovel tipo %d de maior metragem: %d \n",j+1,auxCOD[j]);
                printf("Tecle ENTER para prosseguir...\n");
                getchar();
            }
        }
    }
    for(j = 4; j < 8; j++){
        if( ALUGUEL > 0 ){
            if (j == 4){
                printf("****************************************************************\n");
                printf("*** CATEGORIA: ALUGUEL ***\n");
                printf("****************************************************************\n\n");
            }
            if( auxCONT[j] > 0 ) {
                printf("TIPO %d: %s\n",j+1,TIPO_STR[j-4]);
                printf("CODIGO:\t\tENDERECO\t\t\t\tPRECO\n");
                for( i = 0; i< auxCONT[j]; i++){
                    printf("%d\t\t%s\t\t%.2f\n",COD[SAIDA],END[SAIDA],PRECO[SAIDA]);
                    SAIDA++;
                }

                printf("\nTotal de imoveis do tipo %d: %d\n",j+1,auxCONT[j]);
                printf("Codigo do imovel tipo %d de maior metragem: %d \n",j+1,auxCOD[j]);
                printf("Tecle ENTER para prosseguir...\n");
                getchar();
            }
        }
    }

    printf("****************************************************************\n");
    printf("*** DADOS GERAIS REF. CADASTRO COMPLETO ***\n");
    printf("****************************************************************\n\n");
    printf("NUMERO TOTAL DE IMOVEIS CADASTRADOS: %d",NTOTAL);
    printf("\n");
    printf("\nVENDA: %d - %.2f%% do total",VENDA,PVENDA);
    printf("\nApartamento: %d",auxCONT[0]);
    printf("\nCasa: %d",auxCONT[1]);
    printf("\nLote: %d",auxCONT[2]);
    printf("\nLoja: %d",auxCONT[3]);
    printf("\n");
    printf("\nALUGUEL: %d - %.2f%% do total ",ALUGUEL,PALUGUEL);
    printf("\nApartamento: %d",auxCONT[4]);
    printf("\nCasa: %d",auxCONT[5]);
    printf("\nLote: %d",auxCONT[6]);
    printf("\nLoja: %d",auxCONT[7]);
    printf("\n\n****************************************************************\n");
    /*fim da apresentacao dos daods referentes aos imoveis cadastrados*/

    getchar();
    return 0;
}/*fim do metodo principal*/
