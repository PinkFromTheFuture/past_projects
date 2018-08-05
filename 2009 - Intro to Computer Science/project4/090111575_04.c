/* Universidade de Brasilia
 * Instituto de Ciencias Exatas
 * Departamento de Ciencia da Computacao
 *
 * Computação Basica – 02/2009
 *
 * Aluno(a): Eduardo Furtado Sa Correa
 * Matricula: 09/0111575
 * Turma: A
 * Versao do compilador: gcc version 3.4.5 (mingw-vista special)
 *
 * Descricao: Ferramenta para cadastro imobiliario com armazenamento de dados em disco e uso de registros
 * Obs: Este aplicativo le/grava seus dados na pasta de seu executavel.
 */
#include <stdio.h>
#include <string.h>

typedef struct{
    /*atributos de um imovel*/
    char END[41],OBS[51],DATA[9];
    float METROS,PRECO;
    char CTGR,GARAGEM;
    int COD,TIPO,NQUARTOS;
} imovel;

void ordpreco(imovel imo[],int cont){ /*funcao que ordena vetor de struct por ordem decrescente da sua variavel preco*/
    /*argumentos: um vetor de struct e o numero de structs guardados nele*/
    int flag,i;
    imovel aux;
    flag = 1;
    while (flag){ /*ordena preco*/
        flag = 0;
        for ( i = 0; i < cont-1 ; i++){
            if (imo[i].PRECO < imo[i+1].PRECO){
                flag = 1;
                aux = imo[i];
                imo[i] = imo[i+1];
                imo[i+1] = aux;
            }
        }
    }
}

void ordtipo(imovel imo[],int cont){ /*funcao que ordena vetor de struct por ordem crescente de sua variavel tipo*/
    /*argumentos: um vetor de struct e o numero de structs guardados nele*/
    int flag,i;
    imovel aux;
    flag = 1;
    while (flag){ /*ordena tipo*/
        flag = 0;
        for ( i = 0; i < cont-1 ; i++){
            if (imo[i].TIPO > imo[i+1].TIPO){
                flag = 1;
                aux = imo[i];
                imo[i] = imo[i+1];
                imo[i+1] = aux;
            }
        }
    }
}

int tipo(){ /*funcao que le a variavel TIPO do usuario, e retorna o valor lido, caso seja valido*/
    int TIPO;
    printf("Tipo (1-apartamento, 2-casa, 3-lote, 4-loja): ");
    scanf("%d",&TIPO);
    getchar();
    while( (TIPO != 1) && (TIPO != 2) && (TIPO != 3) && (TIPO != 4) ){
        /*esse loop testa se o valor da variavel TIPO entrada e valido*/
        printf("O tipo do imovel deve ser somente 1, 2, 3, ou 4, sendo que 1 significa apartamento,");
        printf(" 2 significa casa, 3 significa lote, e 4 significa loja.\nTipo: ");
        scanf("%d",&TIPO);
        getchar();
    }
    return TIPO;
}

char ctgr(){ /*funcao que le a variavel CTGR do usuario, e retorna o valor lido, caso seja valido*/
    char CTGR;
    printf("Categoria (\"V\" para venda, ou \"A\" para aluguel): ");
    scanf("%c",&CTGR);
    getchar();
    while( (CTGR != 'v') && (CTGR != 'V') && (CTGR != 'A') && (CTGR != 'a') ){
        /*esse loop testa se o valor da variavel CTGR entrada e valido*/
        printf("Categoria deve ser \"V\" para venda, ou \"A\" para aluguel.\nCategoria: ");
        scanf("%c",&CTGR);
        getchar();
    }
    /*essa tansformacao e necessaria aqui para otimizar depois, na hora de ordenar*/
    if(CTGR == 'V'){
        CTGR = 'v';
    }else{
        if(CTGR == 'A'){
            CTGR = 'a';
        }
    }
    return CTGR;
}

/*INICIO funcao para leitura e validacao dos dados dos imoveis*/
/*retirada do trabalho 2 e modificada para funcionar com struct, e nao mais vetores.*/
imovel cadastra(){ /*retorna um struct*/
    imovel imo;
    /*inicio da leitura dos dados de entrada*/
    printf("\nCodigo do imovel: ");
    scanf("%d",&imo.COD);
    getchar();
    while(imo.COD <= 0){
        printf("Codigo do imovel (nao entre valores negativos ou zero): ");
        scanf("%d",&imo.COD);
        getchar();
    }
    imo.CTGR = ctgr(); /*foi feita uma funcao para essas leituras, pois ela pode ser usada em outras partes do codigo*/
    imo.TIPO = tipo();
    imo.END[0] = '\0';
    printf("Endereco: ");
    scanf("%[^\n]s",imo.END);
    getchar();
    while ( strlen(imo.END) == 0 ){
        printf("Erro! O campo foi deixado em branco!\nEndereco: ");
        scanf("%[^\n]s",imo.END);
        getchar();
    }

    printf("Numero de quartos (digitar 0 para kitinete, lote, e loja): ");
    scanf("%d",&imo.NQUARTOS);
    getchar();
    while( (imo.NQUARTOS != 0 ) && ( (imo.TIPO == 3) || (imo.TIPO == 4) )){
        printf("Numero de quartos para lote ou loja deve ser 0 (zero). Tente novamente: ");
        scanf("%d",&imo.NQUARTOS);
        getchar();
    }
    while ( imo.NQUARTOS < 0 ){
        printf("Numero de quartos deve ser um valor positivo. Tente novamente: ");
        scanf("%d",&imo.NQUARTOS);
        getchar();
    }

    printf("Garagem (S/N):  ");
    scanf("%c",&imo.GARAGEM);
    getchar();
    while( (imo.GARAGEM != 's') && (imo.GARAGEM != 'S') && (imo.GARAGEM != 'n') && (imo.GARAGEM != 'N') ){
        /*esse loop testa se o valor da variavel imo.GARAGEM entrada e valido*/
        printf("Garagem deve ser somente \"S\", \"s\", \"N\", ou \"n\".\nGaragem: ");
        scanf("%c",&imo.GARAGEM);
        getchar();
    }

    printf("Metragem: ");
    scanf("%f",&imo.METROS);
    getchar();
    while( imo.METROS < 0 ){
        /*esse loop testa se o valor da variavel imo.METROS entrada e valido*/
        printf("Metragem deve ser um valor positivo.\nMetragem: ");
        scanf("%f",&imo.METROS);
        getchar();
    }

    printf("Preco: ");
    scanf("%f",&imo.PRECO);
    getchar();
    while( imo.PRECO < 0 ){
        /*esse loop testa se o valor da variavel imo.PRECO entrada e valido*/
        printf("Preco deve ser um valor positivo.\nPreco: ");
        scanf("%f",&imo.PRECO);
        getchar();
    }

    printf("Observacoes: ");
    scanf("%[^\n]s",imo.OBS);
    getchar();

    printf("Data de cadastro (DD/MM/AA): ");
    scanf("%s",imo.DATA);
    getchar();
    /*fim da leitura dos dados de entrada*/
    return imo;
}/*FIM funcao para leitura e validacao dos dados dos imoveis*/

/*INICIO funcao que pergunta ao usuario se deseja fazer nova acao*/
char looper(char opt[15]){ /*recebe uma string. ex: "incluir","pesquisar","excluir"*/
    char LOOPER;
    do{
        printf("\nDeseja fazer nova %s? (S/N): ",opt);
        scanf("%c",&LOOPER);
        getchar();
        printf("\n");
        if((LOOPER != 's') && (LOOPER != 'n') && (LOOPER != 'S') && (LOOPER != 'N')){
            printf("\nErro! Digite 'S' para sim ou 'N' para nao\n");
        }
    } while ((LOOPER != 's') && (LOOPER != 'n') && (LOOPER != 'S') && (LOOPER != 'N'));
    return LOOPER; /*retorna a opcao validada*/
}/*FIM funcao que pergunta ao usuario se deseja fazer nova acao*/

/*INICIO funcao que insere dados de um struct de imovel com atributos validados em um arquivo binario.*/
void incluir(char bin[20],int opt){ /*recebe endereco no disco para arquivo binario e opcao escolhida no menu*/
    imovel imo;
    FILE *fp;
    char LOOPER;
    if(opt == 1){ /*se opcao for 1, cria um cadastro novo. Destroi o anterior caso exista*/
        fp = fopen(bin, "w+b");
        do{
            imo = cadastra();
            fwrite(&imo,sizeof(imovel),1,fp);
            LOOPER = looper("inclusao");
        }while((LOOPER == 's') || (LOOPER =='S'));
    }else{ /*se ocao for 2, continua colocando os dados no fim do arquivo, ou cria um novo caso nao exista*/
        fp = fopen(bin, "r+b");
        if(fp == NULL){
            printf("\nO cadastro atual nao possui dados. Um novo foi criado.\n");
        }else{
	    fclose(fp);
	}
        fp = fopen(bin, "a+b");
        do{
            imo = cadastra();
            fwrite(&imo,sizeof(imovel),1,fp);
            LOOPER = looper("inclusao");
        }while((LOOPER == 's') || (LOOPER =='S'));
    }
    fclose(fp);
}/*FIM funcao que insere dados de um struct de imovel com atributos validados em um arquivo binario.*/

/*INICIO funcao que faz pesquisa nos dados pelo codigo de um imovel*/
char codigo(char bin[20]){
    FILE *fp;
    imovel imo[300];
    int i = 0,cod;

    fp = fopen(bin,"r+b");
    if(fp == NULL){
        printf("\nNao existem dados cadastrados\n\n");
        return 'n';
    }
    printf("\nDigite o codigo do imovel para pesquisa: ");
    scanf("%d",&cod);
    getchar();
    while(cod <= 0){
        printf("Codigo do imovel para pesquisa (nao entre valores negativos ou zero): ");
        scanf("%d",&cod);
        getchar();
    }
    while( fread(&imo[i],sizeof(imovel),1,fp) > 0){
        if(cod == imo[i].COD){
            printf("\nImovel encontrado:\n");
            printf("\nCodigo: %d",imo[i].COD);
            printf("\nCcategoria: %c",imo[i].CTGR);
            printf("\nTipo: %d",imo[i].TIPO);
            printf("\nEndereco: %s",imo[i].END);
            printf("\nNumero de quartos: %d",imo[i].NQUARTOS);
            printf("\nGaragem: %c",imo[i].GARAGEM);
            printf("\nMetragem: %.2f",imo[i].METROS);
            printf("\nPreco: %.2f",imo[i].PRECO);
            printf("\nObservacoes: %s",imo[i].OBS);
            printf("\nData do cadastro: %s\n",imo[i].DATA);
            printf("\nTecle <ENTER> para voltar ao menu principal...\n");
            getchar();
            fclose(fp);
            return 'n';
        }
        i++;
    }
    printf("\nCodigo nao encontrado no cadastro.");
    fclose(fp);
    return looper("pesquisar");
}/*FIM funcao que faz pesquisa nos dados pelo codigo de um imovel*/

/*INICIO funcao que faz pesquisa nos dados pelo tipo e categoria dos imoveis e imprime uma lista com o que foi encontrado*/
char tipocat(char bin[20]){
    FILE *fp;
    imovel imo[300];
    imovel aux;
    int i = 0,TIPO,cont  = 0;
    char CTGR;

    fp = fopen(bin,"r+b");
    if(fp == NULL){
        printf("\nNao existem dados cadastrados\n\n");
        return 'n';
    }
    CTGR = ctgr();
    TIPO = tipo();

    while( fread(&aux,sizeof(imovel),1,fp) > 0){
        if( ( (aux.CTGR == CTGR) || (aux.CTGR == CTGR-32) ) && (aux.TIPO == TIPO) ){
            imo[cont] = aux;
            cont++;
        }
        i++;
    }
    if(cont == 0){
        printf("\nNao estao cadastrados imoveis da categoria '%c' tipo '%d'.",CTGR,TIPO);
    }else{
        ordpreco(imo,cont);
        printf("\nImoveis encontrados:\n");
        printf("Codigo\tEndereco\t\t\t\tPreco\n");
        for(i=0;i<cont;i++){
            printf("%1d\t%-42s %-12.2f\n",imo[i].COD,imo[i].END,imo[i].PRECO);
        }
        printf("\nForam encontrados %d da categoria '%c' e tipo '%d'",cont,CTGR,TIPO);
    }
    fclose(fp);
    return looper("pesquisar");
}/*FIM funcao que faz pesquisa nos dados pelo tipo e categoria dos imoveis e imprime uma lista com o que foi encontrado*/

/*INICIO funcao que le dados de um arquivo binario e gera um arquivo de texto com a lista dos imoveis para venda*/
void texto(char bin[20], char txt[20]){
    FILE *fp;
    imovel imo[300],aux;
    int i = 0;
    int cont  = 0;


    fp = fopen(bin,"r+b");
    if(fp == NULL){
        printf("\nNao existem dados cadastrados\n\n");
        return;
    }
    while( fread(&aux,sizeof(imovel),1,fp) > 0){
        if( (aux.CTGR == 'v') || (aux.CTGR == 'V') ){
            imo[cont] = aux;
            cont++;
        }
        i++;
    }
    ordpreco(imo,cont);
    ordtipo(imo,cont);
    fclose(fp);
    fp = fopen(txt, "w+");
    fprintf(fp,"*** LISTAGEM DE IMOVEIS PARA VENDA ***\n\n");
    fprintf(fp,"TIPO\tCODIGO\tENDERECO\t\t\t\tPRECO\n");
    for(i=0;i<cont;i++){
        fprintf(fp,"%1d \t%-7d %-39s %.2f\n",imo[i].TIPO,imo[i].COD,imo[i].END,imo[i].PRECO);
    }
    printf("\nOperacao realizada com sucesso\nTecle <ENTER> para voltar ao menu inicial...\n");
    getchar();
    fclose(fp);
    return;
}/*FIM funcao que le dados de um arquivo binario e gera um arquivo de texto com a lista dos imoveis para venda*/

/*INICIO funcao principal*/
int main(){
    char bin[20] = "IMOVEIS.bin",txt[20] = "IMOVEIS_VENDA.txt";
    int opt;
    char LOOPER;

    do{ /*laco principal do programa. fica aqui enquanto nao receber 6, para sair*/
        printf("1. CRIAR E INICIAR CADASTRO NOVO"
                "\n2. INCLUIR DADOS NO CADASTRO EXISTENTE"
                "\n3. CONSULTAR O CADASTRO POR CODIGO DE IMOVEL"
                "\n4. CONSULTAR O CADASTRO POR CATEGORIA E TIPO DE IMOVEL"
                "\n5. GERAR ARQUIVO TXT DO CADASTRO DE VENDA"
                "\n6. SAIR \n-->> ");
        scanf("%d",&opt);
        getchar();
        switch(opt){
            case 1:
                incluir(bin,opt);
                break;
            case 2:
                incluir(bin,opt);
                break;
            case 3:
                do{
                    LOOPER = codigo(bin);
                }while((LOOPER == 's') || (LOOPER =='S'));
                break;
            case 4:
                do{
                    LOOPER = tipocat(bin);
                }while((LOOPER == 's') || (LOOPER =='S'));
                break;
            case 5:
                texto(bin,txt);
        }
    }while(opt!=6);
    printf("\nterminando.....\n");
    getchar();
    return 0;
}/*FIM funcao principal*/
