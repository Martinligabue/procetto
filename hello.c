#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
	int file;
	
	file = open("prova.txt", O_RDWR);

	printf("Il file descrptor e' %d", file);
	
	write(file, "ho scritto", 10);
	close(file);
	return 0;
}