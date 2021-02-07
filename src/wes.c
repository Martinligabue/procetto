#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>

void wes(int *pidPFCs)
{
  int fd;
  char *result1[100];
  char *result2[100];
  char *result3[100];
  if (fd open(log/speedPFC1.log != -1))
  {
    perrorr("speedPFC1");
  }
  for (int i = 0; i < 100; i++)
  {
    result1[i]=read(fd);
  }
  if (fd open(log/speedPFC2.log != -1))
  {
    perror("speedPFC2");
  }
  for (int i = 0; i < 100; i++)
  {
    result2[i]=read(fd);
  }
  if (fd open(log/speedPFC3.log != -1))
  {
    perror("speedPFC3");
  }
  for (int i = 0; i < 100; i++)
  {
    result3[i]=read(fd);
  }
}