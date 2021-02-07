#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <math.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "pfc.h"

struct gll pfc(char *path, int offset, struct gll oldGll, int flag)
{
    struct gll newGll;
    int gDesc;
    char buf[45], buf2[10];
    double speed;
    gDesc = open(path, O_RDONLY);
    if (gDesc == -1)
    {
        perror("open");
        exit(1);
    }

    lseek(gDesc, offset, SEEK_SET);
    read(gDesc, &buf, 45);
    close(gDesc);

    for (int i = 7, j = 0; i < 16; i++, j++)
    {
        buf2[j] = buf[i];
    }
    newGll.lat = atof(buf2);
    newGll.latDirection = buf[17];

    for (int i = 19, j = 0; i < 29; i++, j++)
    {
        buf2[j] = buf[i];
    }
    newGll.lon = atof(buf2);
    newGll.lonDirection = buf[30];

    for (int i = 0; i < 10; i++)
    {
        buf2[i] = '\0';
    }

    for (int i = 32, j = 0; i < 38; i++, j++)
    {
        buf2[j] = buf[i];
    }
    newGll.time = atoi(buf2);

    for (int i = 0; i < 10; i++)
    {
        buf2[i] = '\0';
    }

    for (int i = 39, j = 0; i < 43; i++, j++)
    {
        buf2[j] = buf[i];
    }
    newGll.valid = buf2;
    if (oldGll.lat != 0)
    {
        speed = calcolateSpeed(oldGll, newGll);
        //speed = speed / (newGll.time - oldGll.time);
    }
    else
    {
        speed = 0;
    }

    //printf("Figlio : %d speed: %f\n", flag, speed);
    comunication(flag, speed);
    return newGll;
}

double degreesToRadians(double a)
{
    return a * 0.01745329; //aaaaaaaAAAAAA
}

double calcolateSpeed(struct gll oldGll, struct gll newGll)
{
    double degLat = degreesToRadians(oldGll.lat - newGll.lat);
    double degLon = degreesToRadians(oldGll.lon - newGll.lon);

    newGll.lat = degreesToRadians(newGll.lat);
    oldGll.lat = degreesToRadians(oldGll.lat);

    double a = sin(degLat / 2) * sin(degLat / 2) + sin(degLon / 2) * sin(degLon / 2) * cos(newGll.lat) * cos(oldGll.lat);
    double c = atan2(sqrt(a), sqrt(1 - a));
    c = 2 * c;
    return 6371 * c;
}

void comunication(int flag, double speed)
{
    char strSpeed[10];
    int fileD, fPipe[2];
    sprintf(strSpeed, "%f\n", speed);
    switch (flag)
    {
    case 1:
        fileD = open("speed.txt", O_WRONLY);
        write(fileD, strSpeed, 8);
        close(fileD);
        break;
    case 2:
        
    default:
        break;
    }
}