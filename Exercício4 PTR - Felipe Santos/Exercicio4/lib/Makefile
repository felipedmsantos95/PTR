all:SISTEMA SIMULACAO LIBIN LIBOUT LIBX
	ar -cr libsistema.a sistema.o simulacao.o libIn.o libOut.o libX.o
SISTEMA:
	gcc -c sistema.c -lm -o sistema.o -I ../include
SIMULACAO:
	gcc -c simulacao.c -lm -o simulacao.o -I ../include
LIBIN:
	gcc -c libIn.c -lm -o libIn.o -I ../include
LIBOUT:
	gcc -c libOut.c -lm -o libOut.o -I ../include
LIBX:
	gcc -c libX.c -lm -o libX.o -I ../include
