Elaborado por:
Leandro Ramalho - 10/0033571
Eduardo Furtado - 09/0111575


versões do ambiente:

gcc --version
gcc (SUSE Linux) 4.8.3 20140627 [gcc-4_8-branch revision 212064]
Copyright (C) 2013 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

g++ --version
g++ (SUSE Linux) 4.8.3 20140627 [gcc-4_8-branch revision 212064]
Copyright (C) 2013 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.



só compila:

killall -9 print;killall -9 servidor;clear;g++ -Wall remove_postergado.c -o remove_postergado;g++ -Wall shutdown_postergado.c -o shutdown_postergado;g++ -Wall lista_postergados.c -o lista_postergados;g++ -Wall executa_postergado.c -o executa_postergado ;gcc print.c -o print; g++ -Wall servidor.c -o servidor;



compilação e execução:

killall -9 print;killall -9 servidor;clear;g++ -Wall remove_postergado.c -o remove_postergado;g++ -Wall shutdown_postergado.c -o shutdown_postergado;g++ -Wall lista_postergados.c -o lista_postergados;g++ -Wall executa_postergado.c -o executa_postergado ;gcc print.c -o print; g++ -Wall servidor.c -o servidor;./executa_postergado ./print 0:1 1; ./executa_postergado ./print 0:2 3; ./executa_postergado ./print 0:1 2;./servidor



util: 

watch -n 1 'ps -aux |egrep "servidor|print"'

ps -aux | grep print;ps -aux | grep servidor


****************** MAIS INFORMAÇÕES NO ARQUIVO DE ESPECIFICAÇÃO ******************
