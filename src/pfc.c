#include "pfc.h"
#include "config.h"
#include <math.h>

int BIAS=DEFAULT_BIAS

void signalUserHandler(int signum) {
    if (signum == SIGUSR1){ //====?==?=?£££
        BIAS=1;
    }
}

void pfc(char *filePath, char *sentence, unsigned int connectionType){
    PFC *pPFC=malloc(sizeof(PFC));
}