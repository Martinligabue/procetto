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
#include <signal.h>

void wes(void){
    int fd;
    char speed[8];
    if ((fd = open("log/speedPFC1.log", O_RDONLY)) == -1)
    {
        perror("wesPfc1");
        exit(1);
    }

    read(fd, speed, 8);
    close(fd);
    
}