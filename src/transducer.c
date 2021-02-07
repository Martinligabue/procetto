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

void transducer(){
    int fd;
    char buf[8];

    if((fd = open("data/speed.txt", O_RDONLY)) == -1){
        perror("openTransSpeed");
    }
    read (fd, buf, 8);
    close(fd);

    if((fd = open("log/speedPFC1.log", O_WRONLY)) == -1){
        perror("openTransLog");
    }
    write(fd, buf, 8);
    close(fd);
}