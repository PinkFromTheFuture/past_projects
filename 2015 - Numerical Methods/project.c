/*Exemplo de compilacao no ambiente windows do Eduardo:
cd C:\Dropbox\CURSOS\Calculo Numerico - 1-2015\
cls & gcc projeto.c -o projeto -Wall & projeto.exe

Exemplo de compilacao no ambiente unix:
cd /home/pink/Dropbox/CURSOS/cn/; clear; gcc projeto.c -o projeto -Wall; ./projeto
*/

/* Eduardo Furtado Sa Correa    -> 09/0111575   */
/* Maria Florencia Grenier      -> 15/0082851   */
/* Wilson Barbosa               -> 13/0018694   */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define AUTO_LINHAS_POR_COLUNAS 4
#define AUTO_MAX_ITE 200
#define AUTO_ERRO 0.005

// funções do programa
void gaussJacobi();
void gaussSeidel();
void osDois();
void osDoisForcaBruta();
float precisao(float *aux_j, float *x, int n);
void mostrarSolucao(float *x, int n, int m, float pres);
int getMenor(int a, int b);

int main() {
    int opcao;

    //criaçao da tela inicial de apresentaçao
    printf("\n\n\n**********************************************");
    printf("\n*  Projeto de Calculo Numerico               *\n");
    printf("*  Prof.Luiza Taneguti                       *\n");
    printf("*  Turma B, integrantes:                     *\n");
    printf("*                                            *\n");
    printf("*  - Eduardo Furtado Sa Correa               *\n");
    printf("*  - Maria Florencia Grenier                 *\n");
    printf("*  - Wilson Barroso Neto                     *\n");
    printf("**********************************************\n\n\n");
    printf("presiona ENTER para continuar...");
    getchar();


    // Menú de escolha de opção
    label_menu_escolha_de_opcao:
    printf("\n[1]Gauss-Jacobi \n[2]Gauss-Seidell \n[3]Os dois metodos\n[4]Os dois metodos por forca bruta para o sistema do enunciado\n->");
    scanf("%d", &opcao);

    if(opcao == 1)
        gaussJacobi();
    else if(opcao == 2)
        gaussSeidel();
    else if(opcao == 3)
        osDois();
    else if(opcao == 4)
        osDoisForcaBruta();
    else
    {
       printf("\n Valor ingresado invalido \n");
       goto label_menu_escolha_de_opcao;
    }

    printf("\n\nDone!\nBye.\n\n");
    return 0;
}

void gaussJacobi(int mostrar) {

    int i,j;
    int m,n,l;
    float x[10];
    float a[10][10];
    float b[10];
    float c[10];
    // vetor auxiliar. supoe-se que o programa nao vai ter que enfrentar sistemas com mais de 20 incognitas
    // para que facilitar o desenvolvimento e não termos que explicar alocação de memória dinâmica para nosso
    // companheiro que não é programador.
    float aux[20];
    // float aux[n];
    float e;
    float pres;

    // Menú de carga de dados
    printf("\n Digite o numero de equacoes : \n");
    scanf("%d",&n);

    printf("\nDigite o numero maximo de iteracoes : \n");
    scanf("%d",&l);

    printf("\nDigite a precisao : \n");
    scanf("%f",&e);

    printf("\nDigite as constantes do lado direito das equacoes : \n");
    for(i=0;i<n;i++) {
        scanf("%f",&b[i]);
    }

    printf("\nDigite os coeficientes das incognitas em linhas : \n");
    for(i=0;i<n;i++) {
         for(j=0;j<n;j++) {
            scanf("%f",&a[i][j]);
            //guardo o chute como iter 0
            // r[0][i]= x[i];
        }
    }

    printf("\nDigite o CHUTE inicial : \n");
    for(i=0;i<n;i++) {
        scanf("%f",&x[i]);
    }


    /* Iterações de Gauss-Jacobi */
    m=1;
    label_gauss_jacobi_loop:
    for(i=0;i<n;i++) {
        //guardo en aux a iteração ANTERIOR
        aux[i]= x[i];
        c[i]=b[i];
        for(j=0;j<n;j++) {
            if(i!=j) {
                c[i]=c[i]-a[i][j]*x[j];
            }
        }
    }

    // resultado de X_i de la iteración m
    for(i=0;i<n;i++) {
        x[i]=c[i]/a[i][i];
        // r[m][i]= x[i];
    }
    m++;

    /*Calculo do erro*/
    pres=precisao(aux, x, n);
    // Se alcancei a precisão ou cheguei ao número máximo de iterações termino (NÃO entro no if), se não, continuo iterando (entro no if)
    if((m<=l) && (e <= pres) ){
        goto label_gauss_jacobi_loop;
    }
    else {
        mostrarSolucao(x,n,m,pres);
    }
}

void gaussSeidel(){

    int i,j,q;
    int m,n,l;
    float x[10];
    float a[10][10];
    float b[10];
    // vetor auxiliar. supoe-se que o programa nao vai ter que enfrentar sistemas com mais de 20 incognitas
    // para que facilitar o desenvolvimento e não termos que explicar alocação de memória dinâmica para nosso
    // companheiro que não é programador.
    float aux[20];
    // float aux[n];
    float e,c,pres;

    //Menú de carga de dados
    printf("\n Digite o numero de equacoes : \n");
    scanf("%d",&n);

    printf("\nDigite o numero maximo de iteracoes : \n");
    scanf("%d",&l);

    printf("\nDigite a precicao : \n");
    scanf("%f",&e);

    printf("\nDigite as constantes do lado direito das equacoes : \n");
    for(i=0;i<n;i++) {
        scanf("%f",&b[i]);
    }

    printf("\nDigite os coeficientes das incognitas em linhas : \n");
    for(i=0;i<n;i++) {
         for(j=0;j<n;j++) {
            scanf("%f",&a[i][j]);
        }
    }

    printf("\nDigite o CHUTE inicial : \n");
    for(i=0;i<n;i++) {
        scanf("%f",&x[i]);
        //guardo o chute como iter 0
        // r[0][i]= x[i];
    }

    /*Iteraciones de Gauss-Siedel*/
    m=1;
    label_iterar_funcao_GS:
    for(i=0;i<n;i++) {
        //guardo en aux la iteraçao ANTERIOR
        aux[i]= x[i];
        c=b[i];
        for(j=0;j<n;j++) {
            if(i!=j) {
                c=c-a[i][j]*x[j];
            }
        }
        // resultado de X_i de la iteración m
        x[i]=c/a[i][i];
    }

    for(q=0;q<n;q++) {
        // r[m][q]= x[q];
    }
    m++;

    /*Calculo do erro*/
    pres=precisao(aux, x, n);
    // Se alcancei a precisão ou cheguei ao número máximo de iterações termino (NÃO entro no if), se não, continuo iterando (entro no if)
    if((m<=l) && (e <= pres) )
    {
        // printf("\n Entrei no if, presisao= %f/n", pres);
        goto label_iterar_funcao_GS;
    }
    else {
        mostrarSolucao(x,n,m,pres);
    }
}

void osDois(){

    int i;
    int j;
    int q;
    int k;
    int mGJ;
    int mGS;
    int n;
    int l;
    int menor;

    float x[10];
    float y[10];
    float a[10][10];
    float b[10];

    float cGJ[10];
    float GJ[500][10];
    float GS[500][10];

    // vetor auxiliar. supoe-se que o programa nao vai ter que enfrentar sistemas com mais de 20 incognitas
    // para que facilitar o desenvolvimento e não termos que explicar alocação de memória dinâmica para nosso
    // companheiro que não é programador.
    float aux[20];
    float e;
    float cGS;
    float presGJ;
    float presGS;

    //Menú de carga de dados
    printf("\n Digite o numero de equacoes : \n");
    scanf("%d",&n);

    printf("\nDigite o numero maximo de iteracoes : \n");
    scanf("%d",&l);

    printf("\nDigite a precicao : \n");
    scanf("%f",&e);

    printf("\nDigite as constantes do lado direito das equacoes : \n");
    for(i=0;i<n;i++) {
        scanf("%f",&b[i]);
    }

    printf("\nDigite os coeficientes das incognitas em linhas : \n");
    for(i=0;i<n;i++) {
         for(j=0;j<n;j++) {
            scanf("%f",&a[i][j]);
        }
    }

    printf("\nDigite o CHUTE inicial : \n");
    for(i=0;i<n;i++) {
        scanf("%f",&x[i]);
        y[i]= x[i];
        //guardo o chute como iter 0
        GJ[0][i]= x[i];
        GS[0][i]= y[i];
    }


    //--------------------------------------------------------------------------------------
    /*Iteraciones de Gauss-Jacobi*/
    mGJ=1;

    label_os_dois_loop:
    for(i=0;i<n;i++) {
        //guardo en aux a iteraçao ANTERIOR
        aux[i]= x[i];
        cGJ[i]=b[i];
        for(j=0;j<n;j++) {
            if(i!=j) {
                cGJ[i]=cGJ[i]-a[i][j]*x[j];
            }
        }
    }

    // resultado de X_i de la iteración m
    for(i=0;i<n;i++) {
        x[i]=cGJ[i]/a[i][i];
        GJ[mGJ][i]= x[i];
    }
    mGJ++;

    /*Calculo do erro*/
    presGJ=precisao(aux, x, n);
    // Se alcancei a precisão ou cheguei ao número máximo de iterações termino (NÃO entro no if), se não, continuo iterando (entro no if)
    if((mGJ<=l) && (e <= presGJ) ){
        goto label_os_dois_loop;
    }

    //------------------------------------------------------------------------------------------
    /*Iteraciones de Gauss-Siedel*/
    mGS=1;
    label_iterar_gauss_seidel:

    for(i=0;i<n;i++) {
        //guardo en aux la iteraçao ANTERIOR
        aux[i]= y[i];
        cGS=b[i];
        for(j=0;j<n;j++) {
            if(i!=j) {
                cGS=cGS-a[i][j]*y[j];
            }
        }
        // resultado de X_i de la iteración m
        y[i]=cGS/a[i][i];

    }

    for(q=0;q<n;q++) {
        GS[mGS][q]= y[q];
    }
    mGS++;

    /*Calculo do erro*/
    presGS=precisao(aux, y, n);

    // Se alcancei a precisão ou cheguei ao número máximo de iterações termino (NÃO entro no if), se não, continuo iterando (entro no if)
    if((mGS<=l) && (e <= presGS) )
    {
        goto label_iterar_gauss_seidel;
    }

    menor = getMenor(mGJ, mGS);
    if ((e > presGS) && (e <= presGJ) && (mGS < l) )
    {
        printf("\n\ncaso em que apenas GS converge!");

        printf("\n\nconfiguracao:");printf("\n");
        for (i = 0; i < AUTO_LINHAS_POR_COLUNAS; ++i)
        {
            for (j = 0; j < AUTO_LINHAS_POR_COLUNAS; ++j)
            {
                printf("%.3f\t",a[i][j]);
            }
            printf("= %.3f\t",b[i]);
            printf("\n");
        }
        printf("\nITERACAO--------------- Gauss-Jacobi --------------- Gauss-Siedell --------------- Diferencias--------------- \n");

        for(i=0;i<menor;i++) {
            printf("   %d   :",i);
            for(j=0;j<n;j++) {
                printf(" %f ",GJ[i][j]);
            }
            printf("  ");
            for(k=0;k<n;k++) {
                printf(" %f ",GS[i][k]);
            }
            printf("  ");
            for(l=0;l<n;l++) {
                printf(" %f ",fabs(GJ[i][l]-GS[i][l]));
            }
            printf("\n");
        }
        if(mGJ > mGS){
            for(i=mGS;i<mGJ;i++) {
                printf("   %d   :",i);
                for(j=0;j<n;j++) {
                    printf(" %f ",GJ[i][j]);
                }
                printf("    ");
                for(k=0;k<n;k++) {
                    printf("     -    ");
                }
                printf("    ");
                for(l=0;l<n;l++) {
                    printf("     -    ");
                }
                printf("\n");
            }
        }else if(mGJ<mGS){
            for(i=mGJ;i<mGS;i++) {
                printf("   %d   :",i);
                for(j=0;j<n;j++) {
                    printf("     -    ");
                }
                printf("    ");
                for(k=0;k<n;k++) {
                    printf(" %f ",GS[i][j]);
                }
                printf("    ");
                for(l=0;l<n;l++) {
                    printf("     -    ");
                }
                printf("\n");
            }
        }
    }
    else
    {
        if ( (e <= presGS) && (e > presGJ) && (mGJ < l) )
        {
            printf("\n\ncaso em que apenas GJ converge!");

            printf("\nconfiguracao:");printf("\n");
            for (i = 0; i < AUTO_LINHAS_POR_COLUNAS; ++i)
            {
                for (j = 0; j < AUTO_LINHAS_POR_COLUNAS; ++j)
                {
                    printf("%.3f\t",a[i][j]);
                }
                printf("= %.3f\t",b[i]);
                printf("\n");
            }
            printf("\nITERACAO--------------- Gauss-Jacobi --------------- Gauss-Siedell --------------- Diferencias--------------- \n");

            for(i=0;i<menor;i++) {
                printf("   %d   :",i);
                for(j=0;j<n;j++) {
                    printf(" %f ",GJ[i][j]);
                }
                printf("  ");
                for(k=0;k<n;k++) {
                    printf(" %f ",GS[i][k]);
                }
                printf("  ");
                for(l=0;l<n;l++) {
                    printf(" %f ",fabs(GJ[i][l]-GS[i][l]));
                }
                printf("\n");
            }

            if(mGJ > mGS){

                for(i=mGS;i<mGJ;i++) {
                    printf("   %d   :",i);
                    for(j=0;j<n;j++) {
                        printf(" %f ",GJ[i][j]);
                    }
                    printf("    ");
                    for(k=0;k<n;k++) {
                        printf("     -    ");
                    }
                    printf("    ");
                    for(l=0;l<n;l++) {
                        printf("     -    ");
                    }
                    printf("\n");
                }
            }else if(mGJ<mGS){

                for(i=mGJ;i<mGS;i++) {
                    printf("   %d   :",i);
                    for(j=0;j<n;j++) {
                        printf("     -    ");
                    }
                    printf("    ");
                    for(k=0;k<n;k++) {
                        printf(" %f ",GS[i][j]);
                    }
                    printf("    ");
                    for(l=0;l<n;l++) {
                        printf("     -    ");
                    }
                    printf("\n");
                }
            }
        }
        else
        {
            if ((e > presGS) && (e > presGJ) && (mGJ < l) && (mGS < l) )
            {
                printf("\n\ncaso em que os dois convergem!");

                printf("\nconfiguracao:");printf("\n");
                for (i = 0; i < AUTO_LINHAS_POR_COLUNAS; ++i)
                {
                    for (j = 0; j < AUTO_LINHAS_POR_COLUNAS; ++j)
                    {
                        printf("%.3f\t",a[i][j]);
                    }
                    printf("= %.3f\t",b[i]);
                    printf("\n");
                }


                printf("\nITERACAO--------------- Gauss-Jacobi --------------- Gauss-Siedell --------------- Diferencias--------------- \n");

                for(i=0;i<menor;i++) {
                    printf("   %d   :",i);
                    for(j=0;j<n;j++) {
                        printf(" %f ",GJ[i][j]);
                    }
                    printf("  ");
                    for(k=0;k<n;k++) {
                        printf(" %f ",GS[i][k]);
                    }
                    printf("  ");
                    for(l=0;l<n;l++) {
                        printf(" %f ",fabs(GJ[i][l]-GS[i][l]));
                    }
                    printf("\n");
                }

                if(mGJ > mGS){

                    for(i=mGS;i<mGJ;i++) {
                        printf("   %d   :",i);
                        for(j=0;j<n;j++) {
                            printf(" %f ",GJ[i][j]);
                        }
                        printf("    ");
                        for(k=0;k<n;k++) {
                            printf("     -    ");
                        }
                        printf("    ");
                        for(l=0;l<n;l++) {
                            printf("     -    ");
                        }
                        printf("\n");
                    }
                }else if(mGJ<mGS){
                    for(i=mGS-mGJ-1;i<mGS;i++) {
                        printf("   %d   :",i);
                        for(j=0;j<n;j++) {
                            printf("     -    ");
                        }
                        printf("    ");
                        for(k=0;k<n;k++) {
                            printf(" %f ",GS[i][k]);
                        }
                        printf("    ");
                        for(l=0;l<n;l++) {
                            printf("     -    ");
                        }
                        printf("\n");
                    }
                }
            }
            else
            {
                printf("falhou. nao converge por nenhum dos metodos");

                printf("\nconfiguracao:");printf("\n");
                for (i = 0; i < AUTO_LINHAS_POR_COLUNAS; ++i)
                {
                    for (j = 0; j < AUTO_LINHAS_POR_COLUNAS; ++j)
                    {
                        printf("%.3f\t",a[i][j]);
                    }
                    printf("= %.3f\t",b[i]);
                    printf("\n");
                }
                printf("\nITERACAO--------------- Gauss-Jacobi --------------- Gauss-Siedell --------------- Diferencias--------------- \n");

                for(i=0;i<menor;i++) {
                    printf("   %d   :",i);
                    for(j=0;j<n;j++) {
                        printf(" %f ",GJ[i][j]);
                    }
                    printf("  ");
                    for(k=0;k<n;k++) {
                        printf(" %f ",GS[i][k]);
                    }
                    printf("  ");
                    for(l=0;l<n;l++) {
                        printf(" %f ",fabs(GJ[i][l]-GS[i][l]));
                    }
                    printf("\n");
                }

                if(mGJ > mGS){

                    for(i=mGS;i<mGJ;i++) {
                        printf("   %d   :",i);
                        for(j=0;j<n;j++) {
                            printf(" %f ",GJ[i][j]);
                        }
                        printf("    ");
                        for(k=0;k<n;k++) {
                            printf("     -    ");
                        }
                        printf("    ");
                        for(l=0;l<n;l++) {
                            printf("     -    ");
                        }
                        printf("\n");
                    }
                }else if(mGJ<mGS){

                    for(i=mGJ;i<mGS;i++) {
                        printf("   %d   :",i);
                        for(j=0;j<n;j++) {
                            printf("     -    ");
                        }
                        printf("    ");
                        for(k=0;k<n;k++) {
                            printf(" %f ",GS[i][j]);
                        }
                        printf("    ");
                        for(l=0;l<n;l++) {
                            printf("     -    ");
                        }
                        printf("\n");
                    }
                }
            }
        }
    }

    printf("\n---------------------------------------------------------------------------------------------------------------------------------");
}

void osDoisForcaBruta(){

    int i;
    int j;
    int q;
    int k;
    int mGJ;
    int mGS;
    int n;
    int l;
    int menor;

    float x[10];
    float y[10];
    // float a[10][10];
    // float b[10];

    float cGJ[10];
    float GJ[500][10];
    float GS[500][10];

    // vetor auxiliar. supoe-se que o programa nao vai ter que enfrentar sistemas com mais de 20 incognitas
    // para que facilitar o desenvolvimento e não termos que explicar alocação de memória dinâmica para nosso
    // companheiro que não é programador.
    float aux[20];
    float e;
    float cGS;
    float presGJ;
    float presGS;

    float swap_forca_bruta;
    int fc;

    int flag_gs_ok  = 0;
    int flag_gj_ok  = 0;
    int flag_os2_ok = 0;
    int config_count  = 0 ;

    //para força bruta, referente a trocas de linhas
    int swap1=0;
    int swap2=0;
    int swap3=0;
    //para força bruta, referente a trocas de colunas
    int swapc1=0;
    int swapc2=0;
    int swapc3=0;

    // Digite os coeficientes das incognitas em linhas
    float a[AUTO_LINHAS_POR_COLUNAS][AUTO_LINHAS_POR_COLUNAS] = {
        {   3.210    ,   7.890    ,       4.950    ,   -6.35   },
        {   8.050    ,   -4.70    ,       5.050    ,   1.250   },
        {   2.020    ,   7.770    ,       -3.04    ,   -6.72   },
        {   0.320    ,   9.050    ,       -4.77    ,   -4.78   },
    };
    // float a[AUTO_LINHAS_POR_COLUNAS][AUTO_LINHAS_POR_COLUNAS] = {
    //     {   100    ,   1    ,       2    ,   -3   },
    //     {   4    ,   200    ,       -5    ,   -6   },
    //     {   7    ,   8    ,       300    ,   -9   },
    //     {   10    ,   11    ,       -30    ,   400   },
    // };
    // float a[AUTO_LINHAS_POR_COLUNAS][AUTO_LINHAS_POR_COLUNAS] = {
    //     {   1    ,   3    ,       1   },
    //     {   5    ,   2    ,       2   },
    //     {   0    ,   6    ,       8   },
    // };

    // Digite as constantes do lado direito das equacoes
    float b[AUTO_LINHAS_POR_COLUNAS] = { 31.07, 38.27, 0.00, -20.67 };
    // float b[AUTO_LINHAS_POR_COLUNAS] = { -2    ,  3      ,        -6   };

    // a partir daqui o código está encapsulado dentro de um iterador de força bruta que serve
    // pra automáticamente testar convergência por todos as configurações possíveis do sistema
    // ingressado. Em outras palavras, garante-se não por métodos que se encontra a convergência,
    // mas por busca exaustiva através da força bruta.
    // o código não usa artifício avançados de programação, porque temos um companheiro que
    // aprendeu a programar neste trabalho, e não ao longo de anos, como nós de computação.

    // linhas
    label_forca_bruta:
    do
    {
        do
        {
            do
            {
                // início do código aqui
                config_count++;

                // Digite o numero de equacoes
                n = AUTO_LINHAS_POR_COLUNAS;
                // Digite o numero maximo de iteraçoes
                l = AUTO_MAX_ITE;
                // Digite a preciçao
                e = AUTO_ERRO;

                // // CHUTE inicial (automatico)
                // for(i=0;i<n;i++) {
                //     x[i] = 0;
                //     y[i]= x[i];
                //     //guardo o chute como iter 0
                //     GJ[0][i]= x[i];
                //     GS[0][i]= y[i];
                // }
                // manual
                GJ[0][0] = 2;
                GJ[0][1] = 3;
                GJ[0][2] = 8;
                GJ[0][3] = 5;
                GS[0][0] = GJ[0][0];
                GS[0][1] = GJ[0][1];
                GS[0][2] = GJ[0][2];
                GS[0][3] = GJ[0][3];
                x[0]     = GJ[0][0];
                x[1]     = GJ[0][1];
                x[2]     = GJ[0][2];
                x[3]     = GJ[0][3];
                y[0]     = GJ[0][0];
                y[1]     = GJ[0][1];
                y[2]     = GJ[0][2];
                y[3]     = GJ[0][3];



                //--------------------------------------------------------------------------------------
                /*Iteraciones de Gauss-Jacobi*/
                mGJ=1;

                label_os_dois_loop:
                for(i=0;i<n;i++) {
                    //guardo en aux a iteraçao ANTERIOR
                    aux[i]= x[i];
                    cGJ[i]=b[i];
                    for(j=0;j<n;j++) {
                        if(i!=j) {
                            cGJ[i]=cGJ[i]-a[i][j]*x[j];
                        }
                    }
                }

                // resultado de X_i de la iteración m
                for(i=0;i<n;i++) {
                    x[i]=cGJ[i]/a[i][i];
                    GJ[mGJ][i]= x[i];
                }

                mGJ++;

                /*Calculo do erro*/
                presGJ=precisao(aux, x, n);
                // Se alcancei a precisão ou cheguei ao número máximo de iterações termino (NÃO entro no if), se não, continuo iterando (entro no if)
                if((mGJ<=l) && (e <= presGJ) ){
                    goto label_os_dois_loop;
                }

                //------------------------------------------------------------------------------------------
                /*Iteraciones de Gauss-Siedel*/
                mGS=1;
                label_iterar_gauss_seidel:
                for(i=0;i<n;i++) {
                    //guardo en aux la iteraçao ANTERIOR
                    aux[i]= y[i];
                    cGS=b[i];
                    for(j=0;j<n;j++) {
                        if(i!=j) {
                            cGS=cGS-a[i][j]*y[j];
                        }
                    }
                    // resultado de X_i de la iteración m
                    y[i]=cGS/a[i][i];

                }

                for(q=0;q<n;q++) {
                    GS[mGS][q]= y[q];
                }

                mGS++;

                /*Calculo do erro*/
                presGS=precisao(aux, y, n);

                // Se alcancei a precisão ou cheguei ao número máximo de iterações termino (NÃO entro no if), se não, continuo iterando (entro no if)
                if((mGS<=l) && (e <= presGS) )
                {
                    goto label_iterar_gauss_seidel;
                }

                menor = getMenor(mGJ, mGS);
                if ((e > presGS) && (e <= presGJ) && (flag_gs_ok == 0) && (mGS < AUTO_MAX_ITE+10) )
                {
                    printf("\n\ncaso em que apenas GS converge!");
                    flag_gs_ok = 1;

                    printf("\n\nconfiguracao %d:",config_count);printf("\n");
                    for (i = 0; i < AUTO_LINHAS_POR_COLUNAS; ++i)
                    {
                        for (j = 0; j < AUTO_LINHAS_POR_COLUNAS; ++j)
                        {
                            printf("%.3f\t",a[i][j]);
                        }
                        printf("= %.3f\t",b[i]);
                        printf("\n");
                    }
                    printf("\nITERACAO--------------- Gauss-Jacobi --------------- Gauss-Siedell --------------- Diferencias--------------- \n");

                    for(i=0;i<menor;i++) {
                        printf("   %d   :",i);
                        for(j=0;j<n;j++) {
                            printf(" %f ",GJ[i][j]);
                        }
                        printf("  ");
                        for(k=0;k<n;k++) {
                            printf(" %f ",GS[i][k]);
                        }
                        printf("  ");
                        for(l=0;l<n;l++) {
                            printf(" %f ",fabs(GJ[i][l]-GS[i][l]));
                        }
                        printf("\n");
                    }
                    if(mGJ > mGS){
                        for(i=mGS;i<mGJ;i++) {
                            printf("   %d   :",i);
                            for(j=0;j<n;j++) {
                                printf(" %f ",GJ[i][j]);
                            }
                            printf("    ");
                            for(k=0;k<n;k++) {
                                printf("     -    ");
                            }
                            printf("    ");
                            for(l=0;l<n;l++) {
                                printf("     -    ");
                            }
                            printf("\n");
                        }
                    }else if(mGJ<mGS){
                        for(i=mGJ;i<mGS;i++) {
                            printf("   %d   :",i);
                            for(j=0;j<n;j++) {
                                printf("     -    ");
                            }
                            printf("    ");
                            for(k=0;k<n;k++) {
                                printf(" %f ",GS[i][k]);
                            }
                            printf("    ");
                            for(l=0;l<n;l++) {
                                printf("     -    ");
                            }
                            printf("\n");
                        }
                    }
                }
                else
                {
                    if ( (e <= presGS) && (e > presGJ) && (flag_gj_ok == 0) && (mGJ < AUTO_MAX_ITE+10) )
                    {
                        printf("\n\ncaso em que apenas GJ converge!");
                        flag_gj_ok = 1;

                        printf("\nconfiguracao %d:",config_count);printf("\n");
                        for (i = 0; i < AUTO_LINHAS_POR_COLUNAS; ++i)
                        {
                            for (j = 0; j < AUTO_LINHAS_POR_COLUNAS; ++j)
                            {
                                printf("%.3f\t",a[i][j]);
                            }
                            printf("= %.3f\t",b[i]);
                            printf("\n");
                        }
                        printf("\nITERACAO--------------- Gauss-Jacobi --------------- Gauss-Siedell --------------- Diferencias--------------- \n");

                        for(i=0;i<menor;i++) {
                            printf("   %d   :",i);
                            for(j=0;j<n;j++) {
                                printf(" %f ",GJ[i][j]);
                            }
                            printf("  ");
                            for(k=0;k<n;k++) {
                                printf(" %f ",GS[i][k]);
                            }
                            printf("  ");
                            for(l=0;l<n;l++) {
                                printf(" %f ",fabs(GJ[i][l]-GS[i][l]));
                            }
                            printf("\n");
                        }

                        if(mGJ > mGS){

                            for(i=mGS;i<mGJ;i++) {
                                printf("   %d   :",i);
                                for(j=0;j<n;j++) {
                                    printf(" %f ",GJ[i][j]);
                                }
                                printf("    ");
                                for(k=0;k<n;k++) {
                                    printf("     -    ");
                                }
                                printf("    ");
                                for(l=0;l<n;l++) {
                                    printf("     -    ");
                                }
                                printf("\n");
                            }
                        }else if(mGJ<mGS){

                            for(i=mGJ;i<mGS;i++) {
                                printf("   %d   :",i);
                                for(j=0;j<n;j++) {
                                    printf("     -    ");
                                }
                                printf("    ");
                                for(k=0;k<n;k++) {
                                    printf(" %f ",GS[i][j]);
                                }
                                printf("    ");
                                for(l=0;l<n;l++) {
                                    printf("     -    ");
                                }
                                printf("\n");
                            }
                        }
                    }
                    else
                    {
                        if ((e > presGS) && (e > presGJ) && (flag_os2_ok == 0) && (mGJ < AUTO_MAX_ITE+10) && (mGS < AUTO_MAX_ITE+10) )
                        {
                            printf("\n\ncaso em que os dois convergem!");
                            flag_os2_ok = 1;

                            printf("\nconfiguracao %d:",config_count);printf("\n");
                            for (i = 0; i < AUTO_LINHAS_POR_COLUNAS; ++i)
                            {
                                for (j = 0; j < AUTO_LINHAS_POR_COLUNAS; ++j)
                                {
                                    printf("%.3f\t",a[i][j]);
                                }
                                printf("= %.3f\t",b[i]);
                                printf("\n");
                            }
                            printf("\nITERACAO--------------- Gauss-Jacobi --------------- Gauss-Siedell --------------- Diferencias--------------- \n");

                            for(i=0;i<menor;i++) {
                                printf("   %d   :",i);
                                for(j=0;j<n;j++) {
                                    printf(" %f ",GJ[i][j]);
                                }
                                printf("  ");
                                for(k=0;k<n;k++) {
                                    printf(" %f ",GS[i][k]);
                                }
                                printf("  ");
                                for(l=0;l<n;l++) {
                                    printf(" %f ",fabs(GJ[i][l]-GS[i][l]));
                                }
                                printf("\n");
                            }

                            if(mGJ > mGS){

                                for(i=mGS;i<mGJ;i++) {
                                    printf("   %d   :",i);
                                    for(j=0;j<n;j++) {
                                        printf(" %f ",GJ[i][j]);
                                    }
                                    printf("    ");
                                    for(k=0;k<n;k++) {
                                        printf("     -    ");
                                    }
                                    printf("    ");
                                    for(l=0;l<n;l++) {
                                        printf("     -    ");
                                    }
                                    printf("\n");
                                }
                            }else if(mGJ<mGS){

                                for(i=mGJ;i<mGS;i++) {
                                    printf("   %d   :",i);
                                    for(j=0;j<n;j++) {
                                        printf("     -    ");
                                    }
                                    printf("    ");
                                    for(k=0;k<n;k++) {
                                        printf(" %f ",GS[i][j]);
                                    }
                                    printf("    ");
                                    for(l=0;l<n;l++) {
                                        printf("     -    ");
                                    }
                                    printf("\n");
                                }
                            }
                        }
                        else
                        {
                            // printf("fail.");

                            // printf("\nconfiguracao %d:",config_count);printf("\n");
                            // for (i = 0; i < AUTO_LINHAS_POR_COLUNAS; ++i)
                            // {
                            //     for (j = 0; j < AUTO_LINHAS_POR_COLUNAS; ++j)
                            //     {
                            //         printf("%.3f\t",a[i][j]);
                            //     }
                            //     printf("= %.3f\t",b[i]);
                            //     printf("\n");
                            // }
                            // printf("\nITERACAO--------------- Gauss-Jacobi --------------- Gauss-Siedell --------------- Diferencias--------------- \n");

                            // for(i=0;i<menor;i++) {
                            //     printf("   %d   :",i);
                            //     for(j=0;j<n;j++) {
                            //         printf(" %f ",GJ[i][j]);
                            //     }
                            //     printf("  ");
                            //     for(k=0;k<n;k++) {
                            //         printf(" %f ",GS[i][k]);
                            //     }
                            //     printf("  ");
                            //     for(l=0;l<n;l++) {
                            //         printf(" %f ",fabs(GJ[i][l]-GS[i][l]));
                            //     }
                            //     printf("\n");
                            // }

                            // if(mGJ > mGS){

                            //     for(i=mGS;i<mGJ;i++) {
                            //         printf("   %d   :",i);
                            //         for(j=0;j<n;j++) {
                            //             printf(" %f ",GJ[i][j]);
                            //         }
                            //         printf("    ");
                            //         for(k=0;k<n;k++) {
                            //             printf("     -    ");
                            //         }
                            //         printf("    ");
                            //         for(l=0;l<n;l++) {
                            //             printf("     -    ");
                            //         }
                            //         printf("\n");
                            //     }
                            // }else if(mGJ<mGS){

                            //     for(i=mGJ;i<mGS;i++) {
                            //         printf("   %d   :",i);
                            //         for(j=0;j<n;j++) {
                            //             printf("     -    ");
                            //         }
                            //         printf("    ");
                            //         for(k=0;k<n;k++) {
                            //             printf(" %f ",GS[i][j]);
                            //         }
                            //         printf("    ");
                            //         for(l=0;l<n;l++) {
                            //             printf("     -    ");
                            //         }
                            //         printf("\n");
                            //     }
                            // }
                        }
                    }
                }

                // printf("\n---------------------------------------------------------------------------------------------------------------------------------");
                // fim do código aqui

                //troca linha 2 com 3
                for (fc = 0; fc < AUTO_LINHAS_POR_COLUNAS; fc++)
                {
                    swap_forca_bruta = a[2][fc];
                    a[2][fc]         = a[3][fc];
                    a[3][fc]         = swap_forca_bruta;
                }
                swap_forca_bruta = b[2];
                b[2]             = b[3];
                b[3]             = swap_forca_bruta;
                // printf("\ntroca linha 2 com 3");
                swap1++;
            } while (swap1<2);
            swap1=0;

            // troca linha 1 com 2
            for (fc = 0; fc < AUTO_LINHAS_POR_COLUNAS; fc++)
            {
                swap_forca_bruta = a[1][fc];
                a[1][fc]         = a[2][fc];
                a[2][fc]         = swap_forca_bruta;
            }
            swap_forca_bruta = b[1];
            b[1]             = b[2];
            b[2]             = swap_forca_bruta;
            // printf("\ntroca linha 1 com 2");
            swap2++;
        } while (swap2<3);
        swap2=0;

        // troca linha 0 com 1
        for (fc = 0; fc < AUTO_LINHAS_POR_COLUNAS; fc++)
        {
            swap_forca_bruta = a[0][fc];
            a[0][fc]         = a[1][fc];
            a[1][fc]         = swap_forca_bruta;
        }
        swap_forca_bruta = b[0];
        b[0]             = b[1];
        b[1]             = swap_forca_bruta;
        // printf("\ntroca linha 0 com 1");
        swap3++;
    } while (swap3<4);
    swap3=0;

    goto label_forca_bruta_loop;

    // colunas
    do
    {
        do
        {
            do
            {
                // início do código aqui
                goto label_forca_bruta;
                // fim do código aqui
                label_forca_bruta_loop:

                //troca Coluna 2 com 3
                for (fc = 0; fc < AUTO_LINHAS_POR_COLUNAS; fc++)
                {
                    swap_forca_bruta = a[fc][2];
                    a[fc][2]         = a[fc][3];
                    a[fc][3]         = swap_forca_bruta;
                }
                // printf("\ntroca Coluna 2 com 3");
                swapc1++;
            } while (swapc1<2);
            swapc1=0;

            // troca Coluna 1 com 2
            for (fc = 0; fc < AUTO_LINHAS_POR_COLUNAS; fc++)
            {
                swap_forca_bruta = a[fc][1];
                a[fc][1]         = a[fc][2];
                a[fc][2]         = swap_forca_bruta;
            }
            // printf("\ntroca coluna 1 com 2");
            swapc2++;
        } while (swapc2<3);
        swapc2=0;

        // troca Coluna 0 com 1
        for (fc = 0; fc < AUTO_LINHAS_POR_COLUNAS; fc++)
        {
            swap_forca_bruta = a[fc][0];
            a[fc][0]         = a[fc][1];
            a[fc][1]         = swap_forca_bruta;
        }
        // printf("\ntroca Coluna 0 com 1");
        swapc3++;
    } while (swapc3<4);
    swapc3=0;

    printf("\nforam %d configuracoes, testadas ate %d iteracoes",config_count,AUTO_MAX_ITE);
}

int getMenor(int a, int b){
    if(a<b)
        return a;
    else
        return b;
}

float precisao(float *aux_j, float *x, int n)
{
    int i;
    double dif[n];
    double max_dif;
    float retorno_max_diff;

    for (i =0; i< n; i++)
    {
        //fabs dá o valor absoluto de um double
        dif[i] = fabs( ( x[i] - aux_j[i] ) );
    }

    max_dif = dif[0];

    for (i =1; i < n; i++)    {
        if (max_dif < dif[i])
        {
            max_dif = dif[i];
        }
    }


    retorno_max_diff = (float)max_dif;
    return retorno_max_diff;
}


void mostrarSolucao(float *x, int n, int m, float pres){
    int i;
    int max_x;
    float erroRelativo;
    printf("\n A Solucao e : \n");
    for(i=0;i<n;i++) {
        // mostro o resultado da iteração final
        printf("x(%d) = %f\n",i,x[i]);
    }

    max_x = x[0];
    for (i =1; i < n; i++)
    {
        if (max_x < fabs(x[i]))
        {
            max_x = fabs(x[i]);
        }
    }

    erroRelativo = (float)((double)pres/(double)max_x);
    //mostro o erro relativo na ultima iteraçao realizada
    printf("\n dr(%d): %f \n",m-1,erroRelativo);
}

