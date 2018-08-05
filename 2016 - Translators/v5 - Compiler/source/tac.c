#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// pra usar a função to upper
#include <ctype.h>

#include "estruturas.h"
#include "semantica.h"
#include "tac.h"
#include "infix_to_postfix.h"

extern char g_input_file_name[255];
extern char g_current_scope[255];
extern int g_line_counter;

quadrupla * g_primeira_quadrupla = NULL;
tac_table_entry_struct * g_primeira_tac_table = NULL;
int g_quadrupla_index = 0;
char g_infix[255] = "";
char g_pilha_postfix[255][255];
int g_topo_pilha_postfix = -1;
int g_current_tac_label = 0;
char g_tac_label_pile[255][255];
int g_label_pile_top = -1;

void pushPilhaTacLabels(char * elem)
{
    strcpy(g_tac_label_pile[++g_label_pile_top], elem);
}

char * popTacLabel()
{
    return(g_tac_label_pile[g_label_pile_top--]);
}

char * getLabelForLoop()
{
    char * start_label = (char *) malloc (sizeof(char) * 255);
    char * end_label = (char *) malloc (sizeof(char) * 255);
    char current_tac_label_string[15];

    strcpy(start_label, "__begin__loop__label__");
    sprintf(current_tac_label_string, "%d", g_current_tac_label);
    strcat(start_label, current_tac_label_string);
    strcat(start_label, "__");

    strcpy(end_label, "__end__loop__label__");
    strcat(end_label, current_tac_label_string);
    strcat(end_label, "__");

    pushPilhaTacLabels(end_label);
    pushPilhaTacLabels(start_label);
    pushPilhaTacLabels(end_label);

    g_current_tac_label++;

    return start_label;
}

char * getLabelForIfElse()
{
    char * else_label = (char *) malloc (sizeof(char) * 255);
    char * end_label = (char *) malloc (sizeof(char) * 255);
    char current_tac_label_string[15];

    strcpy(else_label, "__else__label__");
    sprintf(current_tac_label_string, "%d", g_current_tac_label);
    strcat(else_label, current_tac_label_string);
    strcat(else_label, "__");

    strcpy(end_label, "__end__ifelse__label__");
    strcat(end_label, current_tac_label_string);
    strcat(end_label, "__");

    pushPilhaTacLabels(end_label);
    pushPilhaTacLabels(else_label);
    pushPilhaTacLabels(end_label);
    pushPilhaTacLabels(else_label);

    g_current_tac_label++;

    return else_label;
}

void printSyntaxTree3(NODE* root, int identation_counter)
{
    NODE* aux = NULL;
    int i=0;

    if (root != NULL)
    {
        for(i = 0; i < identation_counter; i++) { printf("|   "); }

        printf("%s %s\n", root->description, root->value);

        aux = root->child;

        // chamada recursiva para imprimir os filhos.
        while (aux != NULL)
        {
            printSyntaxTree3(aux, identation_counter + 1);
            aux = aux->brother;
        }
    }
}

// função que cria um arquivo de saída cujo nome é o mesmo do arquivo de entrada com a extensão
// .tac concatenada a ele. Após isso imprime no arquivo de saída a tabela de símbolos TAC,
// conforme informação contida na tabela TAC e por fim imprime a seção de código TAC, conforme
// informação contida nas quádruplas;
void printTacCode()
{
    tac_table_entry_struct * tac_table_entry;

    char output_file_name[255];
    strcpy(output_file_name, g_input_file_name);
    strcat(output_file_name, ".tac");

    FILE * output_file_pointer = fopen (output_file_name, "w+");

    quadrupla *quad = g_primeira_quadrupla;

    fprintf(output_file_pointer, "\n.table\n\n");

    if(NULL == g_primeira_tac_table)
    {
        g_primeira_tac_table = (tac_table_entry_struct*) malloc (sizeof(tac_table_entry_struct));
        g_primeira_tac_table->index = -1;
    }

    tac_table_entry = g_primeira_tac_table;

    while(tac_table_entry->index != -1){

        fprintf(output_file_pointer,"%s %s",strToLower(tac_table_entry->type),tac_table_entry->name);

        if(strcmp(tac_table_entry->value, "-") != 0){
            fprintf(output_file_pointer," = %s",tac_table_entry->value);
        }

        fprintf(output_file_pointer,"\n");

        tac_table_entry = tac_table_entry->next;
    }


    fprintf(output_file_pointer, "\n\n.code\n");

    if(NULL != g_primeira_quadrupla)
    {
        while(-1 != quad->index)
        {
            if(0 == strcmp(quad->op, "function"))
                fprintf(output_file_pointer, "\n%s:\n", quad->arg1);

            if(0 == strcmp(quad->op, "return"))
                fprintf(output_file_pointer, "return %s\n", quad->arg1);

            if(0 == strcmp(quad->op, "param"))
                fprintf(output_file_pointer, "param %s\n", quad->arg1);

            if(0 == strcmp(quad->op, "call"))
                fprintf(output_file_pointer, "call %s, %s\n", quad->arg1, quad->arg2);

            if(0 == strcmp(quad->op, "="))
                fprintf(output_file_pointer, "mov %s, %s\n", quad->result, quad->arg1);

            if(0 == strcmp(quad->op, "=[1]"))
                fprintf(output_file_pointer, "mov %s[%s], %s\n", quad->result, quad->arg1, quad->arg2);

            if(0 == strcmp(quad->op, "=[2]"))
                fprintf(output_file_pointer, "mov %s, %s[%s]\n", quad->result, quad->arg1, quad->arg2);

            if(0 == strcmp(quad->op, "add") || 0 == strcmp(quad->op, "sub") || 0 == strcmp(quad->op, "mul") || 0 ==strcmp(quad->op, "div"))
                fprintf(output_file_pointer, "%s %s, %s, %s\n", quad->op, quad->result, quad->arg1, quad->arg2);

            if(0 == strcmp(quad->op, "label"))
                fprintf(output_file_pointer, "mov $0, $0 //this is a dummy line, to prevent two labels in a row.\n");
                fprintf(output_file_pointer, "%s:\n", quad->arg1);

            if(0 == strcmp(quad->op, "jump"))
                fprintf(output_file_pointer, "jump %s\n", quad->arg1);

            if(0 == strcmp(quad->op, "sleq"))
                fprintf(output_file_pointer, "sleq %s, %s, %s\n", quad->result, quad->arg1, quad->arg2);

            if(0 == strcmp(quad->op, "seq"))
                fprintf(output_file_pointer, "seq %s, %s, %s\n", quad->result, quad->arg1, quad->arg2);

            if(0 == strcmp(quad->op, "slt"))
                fprintf(output_file_pointer, "slt %s, %s, %s\n", quad->result, quad->arg1, quad->arg2);

            if(0 == strcmp(quad->op, "brz"))
                fprintf(output_file_pointer, "brz %s, %s\n", quad->arg1, quad->arg2);

            if(0 == strcmp(quad->op, "brnz"))
                fprintf(output_file_pointer, "brnz %s, %s\n", quad->arg1, quad->arg2);

            if(0 == strcmp(quad->op, "push"))
                fprintf(output_file_pointer, "push %s\n", quad->arg1);

            if(0 == strcmp(quad->op, "pop"))
                fprintf(output_file_pointer, "pop %s\n", quad->arg1);

            quad = quad->next;
        }
        fprintf(output_file_pointer, "\n");
    }

    fclose(output_file_pointer);
    printf("\n\nO arquivo %s contem o codigo intermediario em formato executavel. \n\n", output_file_name);
}

//aloca memória para uma nova entrada na no fim da tabela de quádruplas e preenche essa entrada com os dados de uma nova quádrupla. Retorna 1 se tudo ocorrer bem
int addQuadrupla(char * op, char * arg1, char * arg2, char * result)
{
    quadrupla * quad;

    if(NULL == g_primeira_quadrupla)
    {
        g_primeira_quadrupla = (quadrupla *) malloc (sizeof(quadrupla));
        g_primeira_quadrupla->index = -1;
    }

    quad = g_primeira_quadrupla;

    while(-1 != quad->index)
    {
        quad = quad->next;
    }

    strcpy(quad->op,op);
    strcpy(quad->arg1,arg1);
    strcpy(quad->arg2,arg2);
    strcpy(quad->result,result);

    quad->index = g_quadrupla_index;
    g_quadrupla_index++;

    quad->next = (quadrupla *) malloc (sizeof(quadrupla));
    quad->next->index = -1;

    return 1;
}

// função auxiliar para o desenvolvimento, imprime a tabela de quádruplas na saída padrão;
void printQuadruplas()
{
    quadrupla * quad;

    if(NULL != g_primeira_quadrupla)
    {
        printf("\n\nquadruplas:\n");

        quad = g_primeira_quadrupla;
        while(-1 != quad->index)
        {
            printf("op: %-13s arg1: %-28s arg2: %-28s result: %s\n", quad->op, quad->arg1, quad->arg2, quad->result);
            quad = quad->next;
        }
    }
}

// Inicializa a tabela TAC se não estiver inicializada. Em seguida aloca memória
// para uma nova entrada na no fim da tabela TAC e preenche essa entrada. Os
// parâmetros são o nome, tipo, valor e escopo da entrada a ser inserida;
void addTacTableEntry(char * name, char * type, char * value, char * scope)
{
    tac_table_entry_struct * tac_table_entry;
    int index = 0;
    char inputName[200];

    // printf("name:%s\n", name);
    // printf("type:%s\n", type);
    // printf("value:%s\n", value);
    // printf("scope:%s\n", scope);

    if(NULL == g_primeira_tac_table)
    {
        g_primeira_tac_table = (tac_table_entry_struct*) malloc (sizeof(tac_table_entry_struct));
        g_primeira_tac_table->index = -1;
    }

    tac_table_entry = g_primeira_tac_table;
    while(-1 != tac_table_entry->index)
    {
        index++;
        tac_table_entry = tac_table_entry->next;
    }

    if (0 == strcmp(type, "STRING"))
    {
        strcpy(inputName, concatenateScopeWithVariable(scope, name));
        strcat(inputName, " []");
        strcpy(tac_table_entry->name, inputName);
        strcpy(tac_table_entry->type, "char");
        if (0 != strcmp(value, "-"))
            strcpy(tac_table_entry->value, value);
        else
            strcpy(tac_table_entry->value, "\"\"");
    }
    else
    {
        strcpy(inputName, concatenateScopeWithVariable(scope, name));
        strcpy(tac_table_entry->name, inputName);
        strcpy(tac_table_entry->type, type);
        strcpy(tac_table_entry->value, value);
    }

    tac_table_entry->index = ++index;

    tac_table_entry->next = (tac_table_entry_struct*) malloc (sizeof(tac_table_entry_struct));
    tac_table_entry->next->index = -1;
}

void printTacTableEntries()
{
    tac_table_entry_struct * tac_table_entry;

    if(NULL == g_primeira_tac_table)
    {
        g_primeira_tac_table = (tac_table_entry_struct*) malloc (sizeof(tac_table_entry_struct));
        g_primeira_tac_table->index = -1;
    }

    tac_table_entry = g_primeira_tac_table;

    printf("\n\nTAC TABLE:\n");

    while(tac_table_entry->index != -1)
    {
        printf("NAME: %-20s | TYPE: %-7s | VALUE: %-20s\n",tac_table_entry->name,tac_table_entry->type,tac_table_entry->value);
        tac_table_entry = tac_table_entry->next;
    }
}

// concatenateScopeWithVariable(char *, char *) - Função auxiliar para a função
// addTacTableEntry(). Recebe uma string com nome de escopo e uma string com o
// identificador de uma variável e retorna uma string com ambos concatenados, separados por ``_''
char * concatenateScopeWithVariable(char * scope, char * variable)
{
    char * concatenated_string = (char *) malloc (sizeof(char) * 255);

    strcpy(concatenated_string, scope);
    strcat(concatenated_string, "_");
    strcat(concatenated_string, variable);

    return concatenated_string;
}

char * getValueOrIdentifier(NODE * node)
{
    if (0 == strcmp(node->description, "Identifier"))
        return concatenateScopeWithVariable(g_current_scope, node->value);
    else
        return node->value;
}

void saveInFixExpression(NODE * node)
{
    if (0 != strcmp(node->description, "Factor"))
    {
        saveInFixExpression(node->child);
    }

    // nesse ponto, tenho um fator da expressão. guardo ele...
    if (0 == strcmp(node->description, "Factor"))
    {
        //se é o primeiro elemento eu copio, se não eu concateno no final
        if (0 == strcmp(g_infix, ""))
            strcpy(g_infix, node->child->value);
        else
        {
            strcat(g_infix, " ");
            strcat(g_infix, node->child->value);
        }
    }

    // agora vejo cada elemento pra ver se tem irmãos (subo na árvore). se tem, adiciono o símbolo aritmético e continuo...
    if (NULL != node->brother)
    {
        strcat(g_infix, " ");
        strcat(g_infix, node->brother->description);
        saveInFixExpression(node->brother->brother);
    }
}

void pushPilhaPostfix(char * elem)
{
    strcpy(g_pilha_postfix[++g_topo_pilha_postfix], elem);
}

char * popPilhaPostfix()
{
    return(g_pilha_postfix[g_topo_pilha_postfix--]);
}

char * generateTacFromPostFixedExpression(char * postfix)
{
    char * token;
    char * referencia = (char *) malloc (sizeof(char) * 255);
    // separa a string pelos espaços:
    token = strtok(postfix, " ");

    // inicializo a pilha com um caractere inválido da linguagem

    while( NULL != token)
    {
        sprintf(referencia, "$%d", g_quadrupla_index);
        // se é um factor, gero o código com referencia e adiciono na pilha
        if (0 != strcmp(token, "#") && 0 != strcmp(token, "+") && 0 != strcmp(token, "-") && 0 != strcmp(token, "*") && 0 != strcmp(token, "/"))
        {
            // se o primeiro char é uma letra, é um identifier. se não é número?
            if ( (token[0] >= 'a' && token[0] <= 'z') || (token[0] >= 'A' && token[0] <= 'Z' ) )
                addQuadrupla("=", concatenateScopeWithVariable(g_current_scope, token), "", referencia);
            else
                addQuadrupla("=", token, "", referencia);
            pushPilhaPostfix(referencia);
        }
        // se não é um factor, gero o código da operação desempilhando os argumentos e empilhando a referência à resposta
        else
        {
            if (0 == strcmp(token, "+"))
            {
                addQuadrupla("add", popPilhaPostfix(), popPilhaPostfix(), referencia);
            }
            else
            {
                if (0 == strcmp(token, "-"))
                {
                    addQuadrupla("sub", popPilhaPostfix(), popPilhaPostfix(), referencia);
                }
                else
                {
                    if (0 == strcmp(token, "*"))
                    {
                        addQuadrupla("mul", popPilhaPostfix(), popPilhaPostfix(), referencia);
                    }
                    else
                    {
                        if (0 == strcmp(token, "/"))
                        {
                            addQuadrupla("div", popPilhaPostfix(), popPilhaPostfix(), referencia);
                        }
                    }
                }
            }
            pushPilhaPostfix(referencia);
        }

        token = strtok (NULL, " ");
    }

    return referencia;
}

// Gera as quadruplas para cada argumento e retorna a quantidade deles
int addQuadruplasForArgs(NODE * node)
{
    int retorno = 0;
    // printf("\n\n----\n\n");
    // printSyntaxTree3(node, 1);

    // verifica se realmente há algum argumento formal para essa função. se não tem, vai embora :)
    if(NULL == node->child)
        return 0;

    if (0 != strcmp(node->description, "Factor"))
        retorno += addQuadruplasForArgs(node->child);

    // nesse ponto, tenho um fator da expressão. gero o código dele...
    if (0 == strcmp(node->description, "Factor"))
    {
        // se o primeiro char é uma letra, é um identifier. se não é número?
        if ( (node->child->value[0] >= 'a' && node->child->value[0] <= 'z') || (node->child->value[0] >= 'A' && node->child->value[0] <= 'Z' ) )
            addQuadrupla("param", concatenateScopeWithVariable(g_current_scope, node->child->value), "", "");
        else
            addQuadrupla("param", node->child->value, "", "");
        retorno++;
    }

    // agora vejo cada elemento pra ver se tem irmãos (subo na árvore). se tem, chamada recursiva pra continuar fazendo push dos parametros!
    // if (0 != strcmp(node->brother->description, NULL))
    if (NULL != node->brother && 0 == strcmp(node->brother->description, ","))
    {
        retorno += addQuadruplasForArgs(node->brother->brother);
    }

    return retorno;
}


//chama a função addQuadrupla() para diferentes casos referentes ao tipo de expressões
// booleanas usadas em condicionais. Seus parametros são a parte esquerda da comparação,
// o operador de comparação e a parte direita da comparação;
void addQuadruplaForComparison(char * esquerda, char * operador, char * direita)
{

    char * referencia = (char *) malloc (sizeof(char) * 255);

    sprintf(referencia, "$%d", g_quadrupla_index);
    if(0 == strcmp(operador, "=="))
    {
        addQuadrupla("seq", esquerda, direita, referencia);
    }
    if(0 == strcmp(operador, "<"))
    {
        addQuadrupla("slt", esquerda, direita, referencia);
    }
    if(0 == strcmp(operador, ">"))
    {
        addQuadrupla("slt", direita, esquerda, referencia);
    }
    if(0 == strcmp(operador, "<="))
    {
        addQuadrupla("sleq", esquerda, direita, referencia);
    }
    if(0 == strcmp(operador, ">="))
    {
        addQuadrupla("sleq", direita, esquerda, referencia);
    }
    if(0 == strcmp(operador, "!="))
    {
        addQuadrupla("seq", esquerda, direita, referencia);
        addQuadrupla("brnz", popTacLabel(), referencia, "");
        // retorna porque esse caso foi o único diferente, em que compara se é igual, mas salta só se é diferente.
        return ;
    }

    addQuadrupla("brz", popTacLabel(), referencia, "");

}

void makeTacForStringAttribution(NODE * node)
{
    char * referencia0 = (char *) malloc (sizeof(char) * 255);
    char * referencia1 = (char *) malloc (sizeof(char) * 255);
    char * referencia2 = (char *) malloc (sizeof(char) * 255);
    char * referencia3 = (char *) malloc (sizeof(char) * 255);
    char * referencia4 = (char *) malloc (sizeof(char) * 255);
    char * referencia5 = (char *) malloc (sizeof(char) * 255);
    char * referencia6 = (char *) malloc (sizeof(char) * 255);
    char * referencia7 = (char *) malloc (sizeof(char) * 255);
    char * aux = (char *) malloc (sizeof(char) * 255);
    char * label = (char *) malloc (sizeof(char) * 255);
    char * a = (char *) malloc (sizeof(char) * 255);
    char * b = (char *) malloc (sizeof(char) * 255);

    // printSyntaxTree3(node,1);
    strcpy(b, node->child->value);
    node = node->child->brother->brother->child->child->child->child->child->child;
    strcpy(a, node->value);

    // mov $0, &a
    sprintf(referencia0, "$%d", g_quadrupla_index);
    g_quadrupla_index++;
    strcpy(aux, "&");
    strcat(aux, concatenateScopeWithVariable(g_current_scope, a));
    addQuadrupla("=", aux, "", referencia0);
    // mov $1, &b
    sprintf(referencia1, "$%d", g_quadrupla_index);
    g_quadrupla_index++;
    strcpy(aux, "&");
    strcat(aux, concatenateScopeWithVariable(g_current_scope, b));
    addQuadrupla("=", aux, "", referencia1);
    // mov $2, 0 // posicao
    sprintf(referencia2, "$%d", g_quadrupla_index);
    g_quadrupla_index++;
    addQuadrupla("=", "0", "", referencia2);
    // troca:
    sprintf(label, "__string__attribution__label__%d", g_quadrupla_index);
    addQuadrupla("label", label, "", "");
    // mov $3, $0[$2]
    sprintf(referencia3, "$%d", g_quadrupla_index);
    g_quadrupla_index++;
    addQuadrupla("=[2]", referencia0, referencia2, referencia3);

    // push $3
    addQuadrupla("push", referencia3, "", "");
    // pop $4
    sprintf(referencia4, "$%d", g_quadrupla_index);
    g_quadrupla_index++;
    addQuadrupla("pop", referencia4, "", "");

    // mov $1[$2], $4
    addQuadrupla("=[1]", referencia2, referencia4, referencia1);

    // add $2, $2, 1
    addQuadrupla("add", referencia2, "1", referencia2);
    // mov $5, $1[$2]
    sprintf(referencia5, "$%d", g_quadrupla_index);
    g_quadrupla_index++;
    addQuadrupla("=[2]", referencia1, referencia2, referencia5);

    // mov $6, '\0'
    sprintf(referencia6, "$%d", g_quadrupla_index);
    g_quadrupla_index++;
    addQuadrupla("=", "'\\0'", "", referencia6);
    // seq $7, $5, $6
    sprintf(referencia7, "$%d", g_quadrupla_index);
    g_quadrupla_index++;
    addQuadrupla("seq", referencia5, referencia6, referencia7);
    // brz troca, $7
    addQuadrupla("brz", label, referencia7, "");
}

// chama a função addQuadrupla() para diferentes casos referentes ao tipo de expressões.
// Seu parâmetro é um nodo da árvore sintática anotada. Retorna a referencia pra uma
// variavel temporária com o valor da expressão resolvida. Se chama recursivamente;
char * addQuadruplasForExpressions(NODE * node)
{
    int arg_count = 0;
    char arg_count_str[20] = "";
    char postfix[255] = "";
    char * referencia = (char *) malloc (sizeof(char) * 255);

    // printf("current line: %d, node->description = %s\n", g_line_counter, node->description);
    // printf("\n\n----\n\n");
    // printf("chamada:\n");
    // printSyntaxTree3(node, 1);
    // printf(".\n");
    // printf("\n\n----\n\n");

    // printf("node->child->description:%s\n", node->child->description);

    if (0 == strcmp(node->child->description, "Rvalue") || 0 == strcmp(node->child->description, "Addition"))
    {
            //obténho a expressão infixada
            saveInFixExpression(node->child);
            // printf("\ninfixed expression: _%s_\n\n", g_infix);

            // converto a expressão em uma expressão pós-fixada.
            strcpy(postfix, infix_to_postfix(g_infix));
            // printf("\npostfixed expression: _%s_\n\n", postfix);

            //gero código
            strcpy(referencia, generateTacFromPostFixedExpression(postfix));

            //reseto a variavel g_infix
            strcpy(g_infix, "");
            return referencia;
    }
    else
    {
        if (0 == strcmp(node->child->description, "Attribution"))
        {
            if (0 == strcmp(getTypeFromTSByIdentifier(node->child->child->value, "VARIABLE", g_current_scope), "STRING"))
            {
                // printSyntaxTree3(node,1);
                if (0 != strcmp(node->child->child->brother->brother->child->description, "StringConcat") && 0 != strcmp(node->child->child->brother->brother->child->description, "FunctionCall"))
                    makeTacForStringAttribution(node->child);
                return "";
            }

            // printf(".%s.\n", node->child->child->brother->brother->child->description);

            if (0 == strcmp(node->child->child->brother->brother->child->description, "FunctionCall"))
            {
                strcpy(referencia, addQuadruplasForExpressions(node->child->child->brother->brother));
                addQuadrupla("=", referencia, "", concatenateScopeWithVariable(g_current_scope, node->child->child->value));
                return referencia;
            }

            // faço uma chamada recursiva que resolve a expressão e retorna a referencia a ela.
            strcpy(referencia, addQuadruplasForExpressions(node->child->child->brother->brother));
            //gero o código da atribuição:
            addQuadrupla("=", referencia, "", concatenateScopeWithVariable(g_current_scope, node->child->child->value));
            return referencia;
        }
        else
        {
            if (0 == strcmp(node->child->description, "FunctionCall"))
            {
                // verifica se eh um metodo de string ou chamada de funcao
                if (0 != strcmp(node->child->child->brother->description, "."))
                {
                    // conta o número de argumentos que recebe e adiciona a quadrupla correspondente.
                    arg_count = addQuadruplasForArgs(node->child->child->brother->brother);
                    sprintf(arg_count_str, "%d", arg_count);
                    sprintf(referencia, "$%d", g_quadrupla_index);
                    addQuadrupla("call", node->child->child->value, arg_count_str, referencia);
                    addQuadrupla("pop", referencia, "", "");

                    return referencia;
                }
            }
            else
            {
                if (0 == strcmp(node->child->description, "StringConcat"))
                {
                    // printf("ainda nao implementado!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
                    // printf("ainda nao implementado!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
                    // printf("ainda nao implementado!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
                    // printf("4 current line: %d\n", g_line_counter);
                    // printf("node description: %s\n", node->description );
                    // printf("node child description: %s\n", node->child->description);

                    // printSyntaxTree2(node, 1);
// -------------                    strcpy(g_expression_type, "STRING");
                }
            }
        }
    }
    return 0;
}

//chama a função addQuadrupla() para diferentes casos referentes ao tipo do fator
//de um ``ReturnStmt''. Seu parâmetro é um nodo da árvore sintática anotada;
void addReturnQuadrupla(NODE * factor)
{
    // printSyntaxTree3(factor, 1);

    if(0 == strcmp(factor->child->description,"TEXT"))
    {
    // printf("nao implementado ainda!!!!!!!!!!!!!!\n");
    //         addQuadrupla("return",factor->child->value,"","");
        printf("warning L:%d - consulte a documentacao para saber mais sobre a geracao de codigo relacionado com strings.\n", g_line_counter);
    }
    else
    {
        if(0 == strcmp(factor->child->description,"NUMBER")){
            addQuadrupla("return",factor->child->value,"","");
        }
        else
        {
            if(strcmp(factor->child->description,"Identifier") == 0){
                addQuadrupla("return", concatenateScopeWithVariable(g_current_scope, factor->child->value), "", "");
            }
        }
    }
}


// o código abaixo foi resolutado de 2 caminhos diferentes de tentativas de gerar código para expressões!
// char * getRvalueValueRecursive(NODE * node)
// {

//     char * result1 = (char *) malloc (sizeof(char) * 255);
//     char * result2 = (char *) malloc (sizeof(char) * 255);
//     char * rvalue_value = (char *) malloc (sizeof(char) * 255);
//     char * retorno = (char *) malloc (sizeof(char) * 255);
//     NODE * aux = node;
//     NODE * aux2 = node;

//     printf("a\n");
//     while (0 != strcmp(aux->description, "Factor"))
//     {
//         aux = aux->child;
//     }

//     sprintf(result1, "$%d", g_quadrupla_index);
//     addQuadrupla("=",getValueOrIdentifier(aux->child),"", result1);
//     sprintf(result2, "$%d", g_quadrupla_index);

//     // sobe de novo e busca algum nodo com irmão, pra resolver a parte do irmão da expressão.
//     while (0 != strcmp(aux->description, "Rvalue") && NULL != aux->father)
//     {
//         aux = aux->father;
//         if (aux->brother != NULL)
//         {
//             if (0 == strcmp(aux->brother->description, "+"))
//             {
//                 rvalue_value = getRvalueValueRecursive(aux->brother->brother);
//                 sprintf(result2, "$%d", g_quadrupla_index);
//                 addQuadrupla("add", result1, rvalue_value, result2);
//             }
//             if (0 == strcmp(aux->brother->description, "-"))
//             {
//                 addQuadrupla("sub", result1, getRvalueValueRecursive(aux->brother->brother), result2);
//             }
//             if (0 == strcmp(aux->brother->description, "*"))
//             {
//                 aux2 = aux->brother->brother;
//                 while (0 != strcmp(aux2->description, "Factor"))
//                 {
//                     aux2 = aux2->child;
//                 }
//                 addQuadrupla("mul", result1, getValueOrIdentifier(aux2->child), result2);
//             }
//             else
//             {
//                 if (0 == strcmp(aux->brother->description, "/"))
//                 {
//                     addQuadrupla("div", result1, getRvalueValueRecursive(aux->brother->brother), result2);
//                 }
//             }
//         }
//     }
//     // strcpy(retorno,result2);
//     // strcpy(result1,result2);
//     // sprintf(result2, "$%d", g_quadrupla_index);

//     sprintf(retorno, "$%d", g_quadrupla_index);

//     printf("retornando:\n");
//     printf("result1:%s\n", result1);
//     printf("result1:%s\n", result1);
//     printf("retorno:%s\n", retorno);
//     return result2;
// }

// expr_tree_node_struct * addNodeToExprTree(char * value, expr_tree_node_struct * father, expr_tree_node_struct * left, expr_tree_node_struct * right)
// {
//     expr_tree_node_struct * node;

//     node = (expr_tree_node_struct *) malloc (sizeof(expr_tree_node_struct));

//     strcpy(node->value , value);

//     node->father = father;
//     node->left = left;
//     node->right = right;
//     return node;
// }

// void buildTreeRecursive(NODE * node)
// {
//     expr_tree_node_struct * expr_tree_node;
//     if (0 != strcmp(node->description, "Factor"))
//     {
//         buildTreeRecursive(node->child);
//     }

//     // nesse ponto, tenho o fator da expressão. guardo ele na árvore. o pai vai ser o g_expr_tree_current e left e right são NULL
//     expr_tree_node = addNodeToExprTree(node->child->value, g_expr_tree_current, NULL, NULL);

//     //se é o primeiro nodo, asigno ele como raiz e como o nodo em que estou usando pra trbalhar.
//     if (NULL == g_expr_tree_root)
//     {
//         g_expr_tree_root = expr_tree_node;
//         g_expr_tree_current = expr_tree_node;
//     }
//     else
//     {
//         // se estou no else, é porque devo adicionar como filho esquerdo se não existir, ou direito se já tiver um esquerdo.
//         if(NULL == g_expr_tree_current->left)
//         {
//             g_expr_tree_current->left = expr_tree_node;
//         }
//         else
//         {
//             g_expr_tree_current->right = expr_tree_node;
//         }
//     }

//     // agora vejo cada elemento pra ver se tem irmãos (subo na árvore). se tem, adiciono na árvore...
//     if (NULL != node->brother)
//     {
//         /* code */
//     }
// }