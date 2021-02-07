maketest:
	@ echo "Compila"
	gcc -Wall -c src/main.c -o /tmp/main.o
	gcc -Wall -c src/pfc.c -o /tmp/pfc.o
	gcc -Wall -c src/transducer.c -o /tmp/trans.o
	@ echo "Linka"
	gcc -o test log/*.o -lm
