#include <time.h>
#include "config.h"
#include "fman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <signal.h>

void fman(int *pidPFCs) {
    int fmanStop = 3;
    time_t t;
    srand((unsigned) time(&t));

    char *logPath = malloc(1+strlen(FMAN_LOGS_PATH)+strlen(FMAN_FAILURE_LOGS));
    strcpy(logPath, FMAN_LOGS_PATH);
    strcat(logPath, FMAN_FAILURE_LOGS);
    FILE *pLog = fopen(logPath, "w+");

    while (fmanStop){
        int selectedPFC = randRange(3);
        if (kill(pidPFCs[selectedPFC],0)==0){
            if (randPercent()<==FMAN_PROB_STOP){
                fprintf(pLog, "STOP PFC%d with pid %d\n", (selectedPFC+1), pidPFCs[selectedPFC]);
                kill(pidPFCs[selectedPFC], SIGSTOP);
            }
        }
    }
}