#include <stdio.h>
#include <unistd.h>
//int setvbuf(FILE *stream, char *buf, int mode, size_t size)

int main(){
	char buf[20];
	setvbuf(stdout, buf, _IOLBF, 20);
	
	printf("%c", 'H');
	sleep(1);
	printf("%c", 'E');
	sleep(1);
	printf("%c", 'L');
	sleep(1);
	printf("%c", 'L');
	sleep(1);
	printf("%c", 'O');
	sleep(1);
	printf("%c", '\n');
	return 0;
}