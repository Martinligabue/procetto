#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/wait.h>
#include <math.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "pfc.h"

int main (int argc, char *argv[]){
    int i = 57, pidPfc[3];
    struct gll oldGll;
    oldGll.lat = 0;

    pidPfc[0] = fork();
    if (pidPfc[0] == 0){
        while(1){
            oldGll = pfc(argv[1], i, oldGll, 1);
            i += 414;
            sleep(1);
        }
    }

    pidPfc[1] = fork();
    if(pidPfc[1] == 0){
        while(1){
            oldGll = pfc(argv[1], i, oldGll, 2);
            i += 414;
            sleep(1);
        }
    }

    pidPfc[2] = fork();
    if(pidPfc[2] == 0){
        while(1){
            oldGll = pfc(argv[1], i, oldGll, 3);
            i += 414;
            sleep(1);
        }
    }
    
    
    return 0;
}
