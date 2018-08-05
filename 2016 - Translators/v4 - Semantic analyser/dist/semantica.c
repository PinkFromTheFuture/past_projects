#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// pra usar a função to upper
#include <ctype.h>

#include "estruturas.h"
#include "semantica.h"


extern int g_line_counter;
extern int g_syntax_error_flag;

int g_symbol_table_size = 0;
symbol_table_struct *g_symbol_table_first_line;
char g_current_scope[255];
char g_expression_type[255];
int g_expression_factor_counter;
char g_typed_expression[4095][20];
char g_return_stmt_types[4095][20];
int g_return_stmt_lines[4095];
int g_return_stmt_count = 0;

// Verifica se uma função tem um \textit{return statement} sempre alcançavel, ou seja, verifica se há escopos de código condicionais e caso tenha, verifica se há um retorno no nível primário da função, ou em cada possível ramificação da função. Retorna 1 caso esteja OK e 0 em caso contrário
int recursivelyLookForReturnInCompoundStmt(NODE * root)
{
    NODE* aux = NULL;
    int retorno = 0;
    int retornoIf = 0;
    int retornoElse = 0;

    if (root != NULL)
    {
        // verifica se é um return statement:
        if ( 0 == strcmp(root->description, "ReturnStmt") )
            retorno = 1;

        aux = root->child;

        while ( NULL != aux && !retorno )
        {
            if ( 0 == strcmp(aux->description, "IF") )
            {
                // caso em que estou interessado, porque tem IF e ELSE. aux->brother->brother->brother->brother->brother é o que seria o ELSE
                if ( (NULL != aux->brother->brother->brother->brother->brother) && 0 == strcmp(aux->brother->brother->brother->brother->brother->description, "ELSE"))
                {
                    // aux->brother->brother->brother->brother é o CompoundStmt do IF
                    retornoIf = recursivelyLookForReturnInCompoundStmt(aux->brother->brother->brother->brother);
                    // aux->brother->brother->brother->brother->brother->brother é o CompoundStmt do ELSE
                    retornoElse = recursivelyLookForReturnInCompoundStmt(aux->brother->brother->brother->brother->brother->brother);
                    if (retornoIf && retornoElse)
                        return 1;
                    else
                        return 0;
                }
                else
                {
                    // retorno false no caso em que tem só um if, isso não faz com que um return seja alcançável, portanto não interessa
                    return 0;
                }
            }
            else
            {
                retorno = recursivelyLookForReturnInCompoundStmt(aux);

                aux = aux->brother;
            }
        }
    }

    return retorno;
}

void printSyntaxTree2(NODE* root, int identation_counter)
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
            printSyntaxTree2(aux, identation_counter + 1);
            aux = aux->brother;
        }
    }
}

char * getRvalueType(NODE * rvalue_node)
{
    int i = 0;
    int has_error = 0;
    // char base_type[10];

    // printf("rvalue_node:%s\n", rvalue_node->description);

    g_expression_factor_counter = 0;
    // chama a função recursiva que preenche a variavel global com os tipos dos atomos
    saveRvalueTypeRecursive(rvalue_node);

    // verifica se fazem sentido
    // if ( i < g_expression_factor_counter )
    // {
    //     strcpy(base_type, g_typed_expression[i]);
    //     i++;
    // }

    while ( i < (g_expression_factor_counter-1) )
    {
        // printf("%s OP %s\n", g_typed_expression[i], g_typed_expression[i+1]);
        if ( 0 != strcmp(g_typed_expression[i], g_typed_expression[i+1]) )
        {
            printf("Line %d: ERRO SEMANTICO! Nao e possivel fazer uma operacao entre %s e %s.\n", g_line_counter, g_typed_expression[i], g_typed_expression[i+1]);
            g_syntax_error_flag = 1;
            has_error = 1;
        }
        i++;
    }

    if (has_error)
        return "ERROR";
    else
        return g_typed_expression[i];
}

void saveRvalueTypeRecursive(NODE * root)
{
    NODE* aux = NULL;

    if (root != NULL)
    {
        if ( 0 == strcmp(root->description, "Identifier") )
        {
            strcpy(g_typed_expression[g_expression_factor_counter], getTypeFromTSByIdentifier(root->value, "VARIABLE", g_current_scope));
            g_expression_factor_counter++;
        }
        else
        {
            if (0 == strcmp(root->description, "TEXT"))
            {
                strcpy(g_typed_expression[g_expression_factor_counter], "STRING");
                g_expression_factor_counter++;
            }
            else
            {
                if (0 == strcmp(root->description, "NUMBER"))
                {
                    strcpy(g_typed_expression[g_expression_factor_counter], "INT");
                    g_expression_factor_counter++;
                }
                // else
                // {
                //     if ( 0 == strcmp(root->description, "+") || 0 == strcmp(root->description, "-") || 0 == strcmp(root->description, "*") || 0 == strcmp(root->description, "/") )
                //     {
                //         strcpy(g_typed_expression[g_expression_factor_counter], root->description);
                //     g_expression_factor_counter++;
                //     }
                // }
            }
        }

        aux = root->child;

        while (aux != NULL)
        {
            saveRvalueTypeRecursive(aux);
            aux = aux->brother;
        }
    }
}

int saveReturnStmtType(NODE * node)
{
    NODE * atom;

    atom = node->child->brother->child;
    // printf("node->description%s\n", node->description );
    // printf("atom%s\n", atom->description );

    // printf("\n-------------------------------------------------\n");
    // printSyntaxTree2(atom,1);

    if ( g_return_stmt_count == 0 )
    {
        // guardo na primeira posicao o escopo
        strcpy(g_return_stmt_types[0], g_current_scope);
    }
    else
    {
        if ( 0 != strcmp(g_return_stmt_types[0], g_current_scope) )
        {
            // guardo na primeira posicao o escopo e reinicio o contador
            strcpy(g_return_stmt_types[0], g_current_scope);
            g_return_stmt_count = 0;
        }
    }

    // incremento o contador para não pisar o escopo e guardo os valores.
    g_return_stmt_count++;
    saveExpressionType(atom);
    strcpy(g_return_stmt_types[g_return_stmt_count], g_expression_type);
    g_return_stmt_lines[g_return_stmt_count] = g_line_counter;

    return 0;
}

// Verifica se uma função tem ao menos um ``return statement'' e verifica o tipo de cada um deles.
int checkReturnStatementsTypes(char * return_type, char * function_identifier)
{
    int i = 0;
    int retorno = 0;

    // se o escopo guardado é diferente, signífica que não foram encontrados nenhum return statements
    if (0 != strcmp(g_return_stmt_types[i], function_identifier))
    {
        printf("Line %d: ERRO SEMANTICO! A funcao '%s' deve retornar '%s', porem ela nao tem nenhum return statement.\n", g_line_counter, function_identifier, return_type);
        g_syntax_error_flag = 1;
        return 1;
    }
    else
    {
        i++;
        while ( i <= g_return_stmt_count)
        {
            if (0 != strcmp(strToUpper(return_type), strToUpper(g_return_stmt_types[i])))
            {
                printf("Line %d: ERRO SEMANTICO! A funcao '%s' deve retornar '%s', porem este return statement e do tipo '%s'.\n", g_return_stmt_lines[i], function_identifier, return_type, g_return_stmt_types[i]);
                g_syntax_error_flag = 1;
                retorno = 1;
            }
            i++;
        }
    }

    return retorno;
}

void saveExpressionType(NODE* node)
{
    int i = 0;
    // printf("current line: %d, node->description = %s\n", g_line_counter, node->description);

    if (0 == strcmp(node->description, "Rvalue") || 0 == strcmp(node->description, "Addition"))
    {
        strcpy(g_expression_type, getRvalueType(node));
        // printf("1 current line: %d\n", g_line_counter);
    }
    else
    {
        if (0 == strcmp(node->description, "Attribution"))
        {
            // printf("node description: %s\n", node->description );
            // printf("node child description: %s\n", node->child->description);

            // printSyntaxTree2(node,1);
            // strcpy(g_expression_type, getRvalueType(node));
            saveExpressionType(node->child->brother->brother->child);
            // strcpy(g_expression_type, getTypeFromTSByIdentifier(node->child->value, "VARIABLE"));
            // printf("g_expression_type: %s\n", g_expression_type);
            // printf("2 current line: %d\n", g_line_counter);

        }
        else
        {
            if (0 == strcmp(node->description, "FunctionCall"))
            {
                // printf("3 current line: %d\n", g_line_counter);
                // printf("node description: %s\n", node->description );
                // printf("node child description: %s\n", node->child->description);
                // printf("node child value: %s\n", node->child->value);
                // printf("node child brother brother value: %s\n", node->child->brother->brother->value);
                // printf("node child brother desc: _%s_\n", node->child->brother->description);

                // verifica se eh um metodo de string ou chamada de funcao
                if (0 == strcmp(node->child->brother->description, "."))
                    strcpy(g_expression_type, getTypeByMethodIdentifier(node->child->brother->brother->value));
                else
                {
                    strcpy(g_expression_type, getTypeFromTSByIdentifier(node->child->value, "FUNCTION", "GLOBAL"));
                    i = 0;
                    while(g_expression_type[i])
                    {
                        g_expression_type[i] = toupper(g_expression_type[i]);
                        i++;
                    }
                }

                // printf("g_expression_type: %s\n", g_expression_type);
            }
            else
            {
                if (0 == strcmp(node->description, "StringConcat"))
                {
                    // printf("4 current line: %d\n", g_line_counter);
                    // printf("node description: %s\n", node->description );
                    // printf("node child description: %s\n", node->child->description);

                    // printSyntaxTree2(node, 1);
                    strcpy(g_expression_type, "STRING");
                }
            }
        }
    }
}

char * strToLower(char * input)
{
    int i = 0;
    while(input[i])
    {
        input[i] = tolower(input[i]);
        i++;
    }
    return input;
}

char * strToUpper(char * input)
{
    int i = 0;
    while(input[i])
    {
        input[i] = toupper(input[i]);
        i++;
    }
    return input;
}

// De acordo com a específicação de uma função, verifica se uma chamada para a função tem a quantidade de argumentos corretas e se os tipos desses argumentos estão corretos. Retorna 1 se tudo está OK e 0 em caso contrário.
int functionCallSemanticCheck(NODE * node)
{
    int retorno = 1;
    int i = 0;
    char formal_args_type[255][255];
    NODE * argumento_zero = node->child->brother->brother;
    symbol_table_struct *aux;
    int arg_count;
    int formal_arg_count;
    NODE * argumento;

    // conto a quantidade de argumentos passados:
    argumento = argumento_zero;
    arg_count = 0;
    while(NULL != argumento->child && 0 == strcmp(argumento->description, "ArgList"))
    {
        arg_count++;
        argumento = argumento->child;
    }
    // printf("argumento final : %s\n", argumento->description);
    // printf("numero de argumentos contados: _%d_\n", arg_count);

    // conto a quantidade de argumentos formais específicados pela função:
    aux = g_symbol_table_first_line;
    formal_arg_count = 0;
    if(0 < g_symbol_table_size)
    {
        while(aux != NULL)
        {
            if(0 == strcmp(aux->scope,node->child->value) && 0 == strcmp(aux->category,"VARIABLE") && 1 == aux->isFormalArg)
            {
                // printf("formal_arg: %s %s\n", aux->type, aux->name);
                strcpy(formal_args_type[formal_arg_count], aux->type);
                formal_arg_count++;
            }
            aux = aux->next;
        }
    }
    // printf("numero de argumentos formais contados: _%d_\n", formal_arg_count);

    // verifico se a quantidade de argumentos passados corresponde
    if (arg_count != formal_arg_count)
    {
        printf("Line %d: ERRO SEMANTICO! A funcao '%s' requer '%d' argumento(s). Foi passado '%d' argumento(s).\n", g_line_counter, node->child->value, formal_arg_count, arg_count);
        g_syntax_error_flag = 1;
        return 0;
    }

    // verifico se o tipo dos argumentos formais passados corresponde.
    if (i < arg_count)
    {
        // printf("%s %s\n", argumento->child->child->description, argumento->child->child->value);

        if (0 == strcmp(argumento->child->child->description, "Identifier"))
        {
            if (0 != strcmp(formal_args_type[i], getTypeFromTSByIdentifier(argumento->child->child->value, "VARIABLE", g_current_scope)))
            {
                retorno=0; printf("Line %d: ERRO SEMANTICO! O argumento formal %d da funcao '%s' e do tipo '%s', porem foi passado um argumento do tipo '%s'.\n", g_line_counter, i, node->child->value, formal_args_type[i], getTypeFromTSByIdentifier(argumento->child->child->value, "VARIABLE", g_current_scope));
                g_syntax_error_flag = 1;
            }
        }
        else
        {
            if (0 == strcmp(argumento->child->child->description, "TEXT"))
            {
                if (0 != strcmp(formal_args_type[i], "STRING"))
                {
                    retorno=0; printf("Line %d: ERRO SEMANTICO! O argumento formal %d da funcao '%s' e do tipo '%s', porem foi passado um argumento do tipo 'string'.\n", g_line_counter, i, node->child->value, formal_args_type[i]);
                    g_syntax_error_flag = 1;
                }
            }
            else
            {
                if (0 == strcmp(argumento->child->child->description, "NUMBER"))
                {
                    if (0 != strcmp(formal_args_type[i], "INT"))
                    {
                        retorno=0; printf("Line %d: ERRO SEMANTICO! O argumento formal %d da funcao '%s' e do tipo '%s', porem foi passado um argumento do tipo 'int'.\n", g_line_counter, i, node->child->value, formal_args_type[i]);
                        g_syntax_error_flag = 1;
                    }
                }
            }
        }

        i++;
        argumento = argumento->father;
    }
    while(i < arg_count)
    {
        if (0 == strcmp(argumento->brother->brother->child->child->description, "Identifier"))
        {
            if (0 != strcmp(formal_args_type[i], getTypeFromTSByIdentifier(argumento->brother->brother->child->child->value, "VARIABLE", g_current_scope)))
            {
                retorno=0;
                printf("Line %d: ERRO SEMANTICO! O argumento formal %d da funcao '%s' e do tipo '%s', porem foi passado um argumento do tipo '%s'.\n", g_line_counter, i, node->child->value, formal_args_type[i], getTypeFromTSByIdentifier(argumento->brother->brother->child->child->value, "VARIABLE", g_current_scope));
                g_syntax_error_flag = 1;
            }
        }
        else
        {
            if (0 == strcmp(argumento->brother->brother->child->child->description, "TEXT"))
            {
                if (0 != strcmp(formal_args_type[i], "STRING"))
                {
                    retorno=0;
                    printf("Line %d: ERRO SEMANTICO! O argumento formal %d da funcao '%s' e do tipo '%s', porem foi passado um argumento do tipo 'string'.\n", g_line_counter, i, node->child->value, formal_args_type[i]);
                    g_syntax_error_flag = 1;
                }
            }
            else
            {
                if (0 == strcmp(argumento->brother->brother->child->child->description, "NUMBER"))
                {
                    if (0 != strcmp(formal_args_type[i], "INT"))
                    {
                        retorno=0;
                        printf("Line %d: ERRO SEMANTICO! O argumento formal %d da funcao '%s' e do tipo '%s', porem foi passado um argumento do tipo 'int'.\n", g_line_counter, i, node->child->value, formal_args_type[i]);
                        g_syntax_error_flag = 1;
                    }
                }
            }
        }

        i++;
        // printf("%s %s\n", argumento->brother->brother->child->child->description, argumento->brother->brother->child->child->value);
        argumento = argumento->father;
    }
    // printf("argumento: %s %s\n", argumento->father->brother->brother->description, argumento->value);

    // printSyntaxTree2(node,1);
    // exit(1);
    // printf("\n");
    // printf("node->child->brother->brother->description: %s\n", node->child->brother->brother->description);
    // printf("\n\n\n\n\n");
    return retorno;
}

int methodCallSemanticCheck(NODE * node, char * var_id, char * method_id, char * scope)
{
    int retorno = 1;
    int i = 0;
    char formal_args_type[255][255];
    NODE * argumento_zero = node->child->brother->brother->brother->brother;
    int arg_count;
    int formal_arg_count;
    NODE * argumento;

    // verifica se o identificador relacionado com a função é uma string
    if ( 0 != strcmp("STRING", getTypeFromTSByIdentifier(var_id, "VARIABLE", scope)) && 0 != strcmp("STRING", getTypeFromTSByIdentifier(var_id, "VARIABLE", scope)) )
    {
        printf("Line %d: ERRO SEMANTICO! A variavel '%s' nao e uma string para que se possam usar o metodo '%s'.\n", g_line_counter, var_id, method_id);
        retorno = 0;
        g_syntax_error_flag = 1;
    }

    // verifico se é um método válido, específicado pela linguagem
    if (0 == strcmp("ERROR", getTypeByMethodIdentifier(method_id)))
    {
        printf("Line %d: ERRO SEMANTICO! O metodo '%s' nao e um metodo valido.\n", g_line_counter, method_id);
        g_syntax_error_flag = 1;
        return 0;
    }

    // conto a quantidade de argumentos passados:
    argumento = argumento_zero;
    arg_count = 0;
    while(NULL != argumento->child && 0 == strcmp(argumento->description, "ArgList"))
    {
        arg_count++;
        argumento = argumento->child;
    }
    // printf("argumento final : %s\n", argumento->description);
    // printf("numero de argumentos contados: _%d_\n", arg_count);

    // verifico se tem a quantidade correta de argumentos.
    formal_arg_count = getFormalArgCountByMethodIdentifier(method_id);
    if (arg_count != formal_arg_count)
    {
        printf("Line %d: ERRO SEMANTICO! O metodo '%s' requer '%d' argumento(s). Foi passado '%d' argumento(s).\n", g_line_counter, method_id, formal_arg_count, arg_count);
        g_syntax_error_flag = 1;
        return 0;
    }

    // vou embora se não tem argumentos formais pra esse método.
    if (formal_arg_count == 0)
        return retorno;

    // preencho o vetor de tipos de argumentos pro método sendo tratado
    fillFormalArgsTypesByMethodIdentifier(formal_args_type, method_id);

    // verifico se os argumentos tem tipo correto.
    if (i < arg_count)
    {
        // printf("%s %s\n", argumento->child->child->description, argumento->child->child->value);

        if (0 == strcmp(argumento->child->child->description, "Identifier"))
        {
            if (0 != strcmp(formal_args_type[i], getTypeFromTSByIdentifier(argumento->child->child->value, "VARIABLE", g_current_scope)))
            {
                retorno=0; printf("Line %d: ERRO SEMANTICO! O argumento formal %d da funcao '%s' e do tipo '%s', porem foi passado um argumento do tipo '%s'.\n", g_line_counter, i, node->child->value, formal_args_type[i], getTypeFromTSByIdentifier(argumento->child->child->value, "VARIABLE", g_current_scope));
                g_syntax_error_flag = 1;
            }
        }
        else
        {
            if (0 == strcmp(argumento->child->child->description, "TEXT"))
            {
                if (0 != strcmp(formal_args_type[i], "STRING"))
                {
                    retorno=0; printf("Line %d: ERRO SEMANTICO! O argumento formal %d da funcao '%s' e do tipo '%s', porem foi passado um argumento do tipo 'string'.\n", g_line_counter, i, node->child->value, formal_args_type[i]);
                    g_syntax_error_flag = 1;
                }
            }
            else
            {
                if (0 == strcmp(argumento->child->child->description, "NUMBER"))
                {
                    if (0 != strcmp(formal_args_type[i], "INT"))
                    {
                        retorno=0; printf("Line %d: ERRO SEMANTICO! O argumento formal %d da funcao '%s' e do tipo '%s', porem foi passado um argumento do tipo 'int'.\n", g_line_counter, i, node->child->value, formal_args_type[i]);
                        g_syntax_error_flag = 1;
                    }
                }
            }
        }

        i++;
        argumento = argumento->father;
    }
    while(i < arg_count)
    {
        if (0 == strcmp(argumento->brother->brother->child->child->description, "Identifier"))
        {
            if (0 != strcmp(formal_args_type[i], getTypeFromTSByIdentifier(argumento->brother->brother->child->child->value, "VARIABLE", g_current_scope)))
            {
                retorno=0;
                g_syntax_error_flag = 1;
                printf("Line %d: ERRO SEMANTICO! O argumento formal %d da funcao '%s' e do tipo '%s', porem foi passado um argumento do tipo '%s'.\n", g_line_counter, i, node->child->value, formal_args_type[i], getTypeFromTSByIdentifier(argumento->brother->brother->child->child->value, "VARIABLE", g_current_scope));
            }
        }
        else
        {
            if (0 == strcmp(argumento->brother->brother->child->child->description, "TEXT"))
            {
                if (0 != strcmp(formal_args_type[i], "STRING"))
                {
                    retorno=0;
                    g_syntax_error_flag = 1;
                    printf("Line %d: ERRO SEMANTICO! O argumento formal %d da funcao '%s' e do tipo '%s', porem foi passado um argumento do tipo 'string'.\n", g_line_counter, i, node->child->value, formal_args_type[i]);
                }
            }
            else
            {
                if (0 == strcmp(argumento->brother->brother->child->child->description, "NUMBER"))
                {
                    if (0 != strcmp(formal_args_type[i], "INT"))
                    {
                        retorno=0;
                        g_syntax_error_flag = 1;
                        printf("Line %d: ERRO SEMANTICO! O argumento formal %d da funcao '%s' e do tipo '%s', porem foi passado um argumento do tipo 'int'.\n", g_line_counter, i, node->child->value, formal_args_type[i]);
                    }
                }
            }
        }

        i++;
        // printf("%s %s\n", argumento->brother->brother->child->child->description, argumento->brother->brother->child->child->value);
        argumento = argumento->father;
    }

    return retorno;
}

int identifierSemanticCheck(char * identifier, char * category, char * scope)
{
    char * type = getTypeFromTSByIdentifier(identifier, category, scope);
    int retorno = 1;

    // printf("identificador: _%s_ scopo: %s\n", identifier, scope);

    if (0 == strcmp(type, "ERROR") && 0 == strcmp(category,"VARIABLE"))
    {
        printf("Line %d: ERRO SEMANTICO! A variavel '%s' nao foi declarada.\n", g_line_counter, identifier);
        retorno = 0;
        g_syntax_error_flag = 1;
    }
    else if(0 == strcmp(type, "ERROR") && 0 == strcmp(category,"FUNCTION"))
    {
        printf("Line %d: ERRO SEMANTICO! A funcao '%s' nao existe.\n", g_line_counter, identifier);
        retorno = 0;
        g_syntax_error_flag = 1;
    }

    return retorno;
}

char * getTypeByMethodIdentifier(char * identifier)
{
    char * retorno = "ERROR";

    if (0 == strcmp(identifier,"kmpPreprocess"))
        return "STRING";
    else if (0 == strcmp(identifier,"kmpSearch"))
        return "STRING";

    return retorno;
}

int getFormalArgCountByMethodIdentifier(char * identifier)
{
    int retorno = -1;

    if (0 == strcmp(identifier,"kmpPreprocess"))
        return 0;
    else if (0 == strcmp(identifier,"kmpSearch"))
        return 1;

    return retorno;
}

int fillFormalArgsTypesByMethodIdentifier(char formal_args_type[255][255], char * identifier)
{
    int retorno = 1;

    if (0 == strcmp(identifier,"kmpPreprocess"))
    {
        strcpy(formal_args_type[0], "\0");
        return 0;
    }
    if (0 == strcmp(identifier,"kmpSearch"))
    {
        strcpy(formal_args_type[0], "STRING");
        return 0;
    }

    return retorno;
}


char* getTypeFromTSByIdentifier(char * identifier, char * category, char * scope)
{
    symbol_table_struct *aux = g_symbol_table_first_line;
    char * retorno = "ERROR";

    if(0 < g_symbol_table_size)
    {
        while(aux != NULL)
        {
            // printf("aux name _%s_ com identifier _%s_\n",aux->name , identifier );
            // printf("aux category _%s_ com category _%s_\n",aux->category , category );
            // printf("aux scope _%s_ com scope _%s_\n",aux->scope , scope );
            if(0 == strcmp(aux->name, identifier) && 0 == strcmp(aux->category,category) && 0 == strcmp(aux->scope,scope))
            {
                return aux->type;
            }
            aux = aux->next;
        }
    }

    return retorno;
}



// busca na tabela de símmbolos pela presença de uma função main
int isMainFunctionPresent()
{
    symbol_table_struct *aux = g_symbol_table_first_line;
    int retorno = 0;

    if(0 < g_symbol_table_size)
    {
        while(aux != NULL)
        {
            if(0 == strcmp(aux->name,"main") && 0 == strcmp(aux->category,"FUNCTION"))
            {
                retorno = 1;
            }
            aux = aux->next;
        }
    }

    return retorno;
}

int verifyDuplicateFunction(data_for_the_symbol_table* data){
    symbol_table_struct *aux = g_symbol_table_first_line;
    int retorno = 0;

    if(0 < g_symbol_table_size)
    {
        while(aux != NULL)
        {
            if(0 == strcmp(aux->name,data->name) && 0 == strcmp(aux->category,"FUNCTION"))
            {
                retorno = 1;
            }
            aux = aux->next;
        }
    }

    return retorno;
}

int verifyDuplicateVariable(data_for_the_symbol_table* data, char * scope){

    symbol_table_struct *aux = g_symbol_table_first_line;
    int retorno = 0;

    // printf("name %s. scope %s.\n", data->name, scope);

    if(0 < g_symbol_table_size)
    {
        while(aux != NULL)
        {
            if(0 == strcmp(aux->name,data->name) && 0 == strcmp(aux->category,"VARIABLE") && 0 == strcmp(aux->scope,scope))
            {
                retorno = 1;
            }
            aux = aux->next;
        }
    }

    return retorno;
}