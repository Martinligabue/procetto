#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

char actionOnSocket(char* str, int action){
    int socket[2];
    char buf[9];

    if(socketpair(AF_UNIX, SOCK_STREAM, 0, socket) == -1){
        perror("socketCreate");
        exit(1);
    }

    if(action == 0){
        write(socket[0], &str, 8);
    }
    if(action == 1){
        read(socket[1], &buf, 8);
    }
    
    return *buf;
}