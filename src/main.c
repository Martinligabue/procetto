
#include "main.h"
#include "config.h"
#include "pfc.h"
#include "transducer.h"
#include "fman.h"
#include "wes.h"
#include "pfcds.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/un.h>
#include <sys/wait.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char *argv[]){
    char* g18Path = extractG18FromArgument(argc, argv);
    int processCount = 0;

    
}