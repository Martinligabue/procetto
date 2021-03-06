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
#include "transducer.h"
#include "wes.h"
#include "pfcds.h"

#define CLOCK 1

int main(int argc, char *argv[])
{
    int pidPfc[5];
    struct gll oldGll;
    oldGll.lat = 0;
    oldGll.offset = 0;

    pidPfc[0] = fork();
    if (pidPfc[0] == 0)
    {   
        while (1)
        {   
            oldGll = pfc(argv[1], oldGll, 1);
            sleep(CLOCK);
        }
    }


    pidPfc[1] = fork();
    if (pidPfc[1] == 0)
    {
        while (1)
        {
            oldGll = pfc(argv[1], oldGll, 2);
            sleep(CLOCK);
        }
    }
    

    pidPfc[2] = fork();
    if (pidPfc[2] == 0)
    {
        while (1)
        {
            oldGll = pfc(argv[1], oldGll, 3);
            sleep(CLOCK);
        }
    }

    pidPfc[3] = fork();
    if (pidPfc[3] == 0)
    {
        while (1)
        {
            transducer();
            sleep(CLOCK);
        }
    }
    
    pidPfc[4] = fork();
    if (pidPfc[4] == 0)
    {
        while (1)
        {
            wes();
            sleep(CLOCK);
        }
    }



    return 0;
}


