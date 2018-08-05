#!/bin/bash
clear;

echo "removendo arquivos gerados anteriormente..."
rm 090111575.yy.c
rm 090111575.o
rm 090111575.tab.c
rm 090111575.tab.h
rm 090111575.output
echo "remocao: DONE!"
echo ""

echo "bison, para gerar os arquivos 090111575.tab.c e 090111575.tab.h"
bison -o 090111575.tab.c -t -d -v 090111575.y;
echo ""
echo "bison: DONE!"
echo ""

echo "Flex, para gerar o arquivo 090111575.yy.c"
flex -o 090111575.yy.c 090111575.l;
echo ""
echo "Flex: DONE!"
echo ""

echo "gcc, para gerar o executavel 090111575.o"
gcc -Wall 090111575.tab.c 090111575.yy.c -lfl -o 090111575.o
echo ""
echo "gcc: DONE!"
echo ""

echo "executando o analisador lexico e sintatico:"
./090111575.o < $1