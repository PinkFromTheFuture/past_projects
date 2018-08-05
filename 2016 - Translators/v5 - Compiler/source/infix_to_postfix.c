#define SIZE 255            /* Size of Stack */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char s[SIZE][SIZE];
int top=-1;       /* Global declarations */

void push(char * elem)
{                       /* Function for PUSH operation */
    // s[++top]=elem;
    strcpy(s[++top], elem);
}

char * pop()
{                      /* Function for POP operation */
    return(s[top--]);
}

int pr(char * elem)
{                 /* Function for precedence */
    if(0 == strcmp(elem, "#")) return 0;
    if(0 == strcmp(elem, "+")) return 1;
    if(0 == strcmp(elem, "-")) return 1;
    if(0 == strcmp(elem, "*")) return 2;
    if(0 == strcmp(elem, "/")) return 2;
    return -1;
}

char * infix_to_postfix(char * infix)
{                         /* Main Program */
    // char infix[255];
    char * ch;
    char * postfixed = (char *) malloc (sizeof(char) * 255);
    // char elem;
    // int i=0,k=0;
    // printf("\n\nRead the Infix Expression ? ");
    // scanf("%s",infix);
    push("#");
    strcpy(postfixed, "");

    ch = strtok(infix, " ");

    while( NULL != ch)
    {
        if( 0 == strcmp(ch, "(")) push(ch);
        else
            if(0 != strcmp(ch, "#") && 0 != strcmp(ch, "+") && 0 != strcmp(ch, "-") && 0 != strcmp(ch, "*") && 0 != strcmp(ch, "/") )
            {
                // adiciona um espaço antes se não é o primeiro caractere
                if (0 != strcmp(postfixed, ""))
                    strcat(postfixed, " ");
                strcat(postfixed, ch);
            }
            else
                if( 0 == strcmp(ch, ")"))
                {
                    while( 0 != strcmp(s[top], "("))
                    {
                        strcat(postfixed, " ");
                        strcat(postfixed, pop());
                    }
                    // elem=pop(); /* Remove ( */
                    pop(); /* Remove ( */
                }
                else
                {       /* Operator */
                    while( pr(s[top]) >= pr(ch) )
                    {
                        strcat(postfixed, " ");
                        strcat(postfixed, pop());
                    }
                    push(ch);
                }
        ch = strtok (NULL, " ");
    }
    while( 0 != strcmp(s[top], "#"))     /* Pop from stack till empty */
    {
        strcat(postfixed, " ");
        strcat(postfixed, pop());
    }
    // postfixed[k]='\0';          /* Make postfixed as valid string */
    // printf("\n\nGiven Infix Expn: %s  Postfix Expn: %s\n",infix,postfixed);
    return postfixed;
}