makeRun:
	@ echo "Compila"
	gcc -Wall -c src/main.c -o tmp/main.o
	gcc -Wall -c src/pfc.c -o tmp/pfc.o
	gcc -Wall -c src/transducer.c -o tmp/trans.o
	gcc -Wall -c src/pipe.c -o tmp/pipe.o
	
	@ echo "Linka"
	gcc tmp/*.o -o run -lm
run: all
	@ echo "Run"
	@ ./run