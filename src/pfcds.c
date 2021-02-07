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


void pfcDs (char* error, int pid[], int i){
    int fd;
    char *buf;
    if((fd = open("log/switch.log", O_WRONLY) == -1))
    {
        perror("openSwitch.log");
        exit(1);
    }

    if (strcmp(error, "error")){
        if (kill(pid[i], 0) == 0)
        {
            buf = ("The process that caused the error is running\n");
            write(fd, buf, strlen(buf));
            close(fd);
        }
        else
        {
            buf = ("The process that caused the error and is not running\n");
            write(fd, buf, strlen(buf));
            close(fd);
        }
    }

    if (strcmp(error, "emergency")){
        for(i=0; i<3; i++)
        {
            kill(pid[i], SIGINT);
        }
        write(fd, "All processes terminated\n", 25);
        close(fd);
        exit(1);
    }
}
