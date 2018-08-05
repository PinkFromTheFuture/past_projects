/* Eduardo Furtado  09/0111575


Variaveis nao usadas, ou alocadas e nao utilizadas, ignore-as. Estive sem tempo para lidar com elas.

O programa compila e roda, qualquer problema, entre em contato, por favor, antes de tirar nota.
Ha sempre a chance de ser enviado um arquivo errado, ou memso corrompido

eduardofurtadO@live.fr

*/


#include <stdio.h>
#include <stdlib.h>


typedef struct tipopilha
{
    char  letra;
    float valor;
    struct tipopilha *prox;
} pilha;

typedef struct tipofila
{
    char dado;
    struct tipofila *prox;
} fila;




void IniPilha(pilha **ep)
{
    *ep = NULL;
}

void IniFila(fila **ef)
{
    *ef = NULL;
}


int VaziaPilha(pilha *p)
{
    return (p==NULL);
    /*1 pilha vazia, 0 pilha nao vazia*/
}

int VaziaFila(fila *f)
{
    return (f==NULL);
    /*1 fila vazia, 0 fila nao vazia*/
}

char TopoLetra(pilha *p)
{
    return p->letra;
}

float TopoValor(pilha *p)
{
    return p->valor;
}

char FrenteFila(fila *f)
{
    return f->dado;
}

void InsereFila(fila **ef, char dadonovo)
{
    fila *f1, *f2;

    f1 = malloc(sizeof(fila));
    f1->dado = dadonovo;
    f1->prox = NULL;
    if(*ef == NULL)
    {
        *ef = f1;
    }
    else
    {
        f2 = *ef;
        while(f2->prox != NULL)
        {
            f2 = f2->prox;
        }
        f2->prox = f1;
    }
}

char RetiraFila(fila **ef)
{
    char saida;
    fila *f1;

    f1 = *ef;
    *ef = f1->prox;
    saida = f1->dado;
    free(f1);

    return saida;
}

void InserePilha(pilha **ep, char charnovo, float valornovo)
{
    pilha *p1;

    p1 = malloc(sizeof(pilha));
    p1->valor = valornovo;
    p1->letra = charnovo;
    p1->prox = *ep;
    *ep = p1;
}

float RetiraPilha(pilha **ep)
{
    pilha *p1;
    float saida;

    p1 = *ep;
    *ep = p1->prox;
    saida= p1->valor;
    free(p1);

    return saida;
}

char RetiraLetra(pilha **ep){
    char saida;
    pilha *p1;

    p1 = *ep;
    *ep = p1->prox;
    saida = p1->letra;
    free(p1);
    return saida;
}

void AvaliaExpressaoParentetizada ()
{
    pilha *p1, *p2;
    char car,oi;
    int i,cont = 0,multi;
    FILE *arq, *arq2;
    float aux = 0,aux2;
    int a,b;


    void ResolveOperacao ()
    {
        char op, caux;
        float c1, c2;
        float x,y;


        if (VaziaPilha (p2))
        {
            if (VaziaPilha (p1))
            {
                caux = 0+'0';
                InserePilha (&p1,0+'0',0);
            }
        }
        else
        {
            op = RetiraLetra (&p2);
            x = RetiraPilha (&p1);
            y = RetiraPilha (&p1);
            switch (op)
            {
            case '+' :
                InserePilha (&p1, 0,y+x);
                break;
            case '-' :
                InserePilha (&p1,0, y-x);
                break;
            case '*' :
                InserePilha (&p1,0, y*x);
                break;
            case '/' :
                InserePilha (&p1, 0,y/x);
                break;
            }
        }
    }


    IniPilha (&p1);
    IniPilha (&p2);
    arq = fopen ("s3.txt", "r");
    arq2 = fopen ("s3.txt", "r");
    while((car = getc (arq2)) != '\n');
    while ((car = getc (arq)) != ('\n'))
    {
        if ((car>='A')&&(car<='Z'))
        {
            cont++;
            aux = 0;

            multi = 0;
            for ( b = 0; b<cont;b++){
                  fscanf (arq2,"%c %f",&car,&aux);
            }
            InserePilha (&p1, car,aux);
        }
        else if (car == ')'){

            ResolveOperacao ();
        }
        else if ((car != '(') && (car != 32)){
            InserePilha (&p2, car,0);
        }
    }
    ResolveOperacao ();
    fclose (arq);
    fclose (arq2);
    printf("\n\nSAIDA: %.2f \n", RetiraPilha (&p1));
}



int main ()
{
    printf("Aluno Eduardo Furtado, 09/0111575");
    AvaliaExpressaoParentetizada ();
    getchar();

    return 0;
}
