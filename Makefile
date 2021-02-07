run: all
	@ echo "Run"
	@ ./run G18.txt

all: clean install 

clean:
	@ echo "Clean temporary files and directories"
	@ rm -rf bin/ log/ tmp/

install: precompile main
	@ echo "Package binaries on run"
	@ clang bin/*.o -o run -lm

main: pfc transducer fman wes pfcds config
	@ echo "Compile main"
	@ gcc -Wall -c main.c
	@ gcc -Wall -c pfc.c
	@ gcc -o run pfc.o main.o lm
