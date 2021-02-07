CC=gcc

NAME_EXE=run
PREFIX_GLOBAL=src/
PREFIX_PFC=$(PREFIX_GLOBAL)/
PREFIX_TRANS=$(PREFIX_GLOBAL)/
PREFIX_FMAN=$(PREFIX_GLOBAL)/
PREFIX_WES=$(PREFIX_GLOBAL)/
PREFIX_PFCDS=$(PREFIX_GLOBAL)/
PREFIX_UTIL=$(PREFIX_GLOBAL)/
BINDIR=bin/
LOGDIR=log/
TMPDIR=tmp/

run: all
	@ echo "Run"
	@ ./$(NAME_EXE)

all: clean install 

clean:
	@ echo "Clean temporary files and directories"
	@ rm -rf $(BINDIR) $(LOGDIR) $(TMPDIR)

install: precompile main
	@ echo "Package binaries on run"
	@ $(CC) $(BINDIR)*.o -o $(NAME_EXE) -lm

main: pfc transducer fman wes pfcds config
	@ echo "Compile main"
	@ $(CC) -c $(PREFIX_GLOBAL)main.c -o $(BINDIR)main.o

pfc: utility config 
	@ echo "Compile pfc"
	@ $(CC) -c $(PREFIX_PFC)pfc.c -o $(BINDIR)pfc.o
	#@ $(CC) -c $(PREFIX_PFC)structure.c -o $(BINDIR)structure.o

transducer: utility config
	@ echo "Compile transducer"
	#@ $(CC) -c $(PREFIX_TRANS)transducer.c -o $(BINDIR)transducer.o

fman: config
	@ echo "Compile failure manager"
	#@ $(CC) -c $(PREFIX_FMAN)fman.c -o $(BINDIR)fman.o

wes: config
	@ echo "Compile wes"
	#@ $(CC) -c $(PREFIX_WES)wes.c -o $(BINDIR)wes.o

pfcds: precompile
	@ echo "Compile pfc disconnect switch"
	#@ $(CC) -c $(PREFIX_PFCDS)pfcds.c -o $(BINDIR)pfcds.o

utility: precompile
	@ echo "Compile utilities"
	#@ $(CC) -c $(PREFIX_UTIL)string.c -o $(BINDIR)string.o
	#@ $(CC) -c $(PREFIX_UTIL)angles.c -o $(BINDIR)angles.o
	#@ $(CC) -c $(PREFIX_UTIL)connection.c -o $(BINDIR)connection.o

config: precompile
	@ echo "Compile constants"
	@ $(CC) -c $(PREFIX_GLOBAL)config.c -o $(BINDIR)config.o

precompile:
	@ echo "Create binaries and logs directory"
	@ mkdir $(BINDIR)
	@ mkdir $(LOGDIR)
	@ mkdir $(TMPDIR)
