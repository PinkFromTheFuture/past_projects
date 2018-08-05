#!/bin/bash

echo "removendo arquivos gerados anteriormente..."
rm $1.yy.c
rm $1.o
echo "remocao: DONE!"


echo "Flex, para gerar o arquivo $1.yy.c"
flex $1
flex -o $1.yy.c $1;
echo ""
echo "Flex: DONE!"
echo ""

echo "gcc, para gerar o arquivo $1.o"
gcc $1.yy.c -lfl -o $1.o
echo ""
echo "gcc: DONE!"
echo ""

echo "executando o analisador lexico:"
./$1.o < $2