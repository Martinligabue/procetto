makeRun:
	@ echo "Compila"
	gcc -Wall -c src/main.c -o tmp/main.o
	gcc -Wall -c src/pfc.c -o tmp/pfc.o
	gcc -Wall -c src/transducer.c -o tmp/trans.o
	gcc -Wall -c src/pipe.c -o tmp/pipe.o
<<<<<<< HEAD
	gcc -Wall -c src/socket.c -o tmp/socket.o

=======
	gcc -Wall -c src/wes.c -o tmp/wes.o
	
>>>>>>> 4b5258f908a54da5a719ce13beb81fb5dee2be3a
	@ echo "Linka"
	gcc tmp/*.o -o run -lm
run: all
	@ echo "Run"
	@ ./run