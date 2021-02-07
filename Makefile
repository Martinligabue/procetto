maketest:
	gcc -Wall -c src/main.c
	gcc -Wall -c src/pfc.c
	gcc -Wall -c src/transducer.c
	
	gcc -o test main.o pfc.o transducer.o -lm