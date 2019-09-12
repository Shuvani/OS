#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>


int main(){
	pid_t pid;
	int n = 8;
	switch(pid = fork()) {
		case -1:
			perror("fork"); /* произошла ошибка */
			exit(1); /*выход из родительского процесса*/
		case 0:
			printf("Hello from child [%d - %d]\n", pid, n);
			break;
		default:
			printf("Hello from parent [%d - %d]\n", pid, n);
		return 0;
	}
}
 