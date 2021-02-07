#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "pfc.h"
#include "transducer.h"
#include "pipe.h"


char* actionOnPipe (char *str, int action){
    int fD[2];
    char buf[9];
    pipe(fD);
    if(action == 0){
        close(fD[1]);
        write(fD[0], str, 8);
        close(fD[0]);
    }
    if(action == 1){
        close(fD[0]);
        read(fD[1], buf, 8);
        close(fD[1]);
    }
    return buf;
}
