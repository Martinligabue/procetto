#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>


void wes(void)
{
  int fd;
  char result1[9];
  char result2[9];
  char result3[9];

  if ((fd = open("log/speedPFC1.log", O_RDONLY)) == -1)
  {
    perror("speedWesPFC1");
    exit(1);
  }
  read(fd, &result1, 8);
  close(fd);

  if ((fd = open("log/speedPFC2.log", O_RDONLY)) == -1)
  {
    perror("speedWesPFC2");
    exit(1);
  }
  read(fd, &result2, 8);
  close(fd);

  if ((fd = open("log/speedPFC3.log", O_RDONLY)) == -1)
  {
    perror("speedWesPFC3");
    exit(1);
  }
  read(fd, &result3, 8);
  close(fd);


  if(strcmp(result1, result2) && strcmp(result1, result3)){
    printf("Wes: OK\n");
  }
  else{
    printf("Wes: non ok\n");
  }
}