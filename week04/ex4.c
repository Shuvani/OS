#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
	char input[200];
	char ex[] = "exit";
	while (1){
		int i = 0;
		fgets(input, 200, stdin);
		while (input[i]!= '\0'){
			i++;
		}
		if (input[i-1] == '&'){
			pid_t pid;
			switch(pid = fork()) {
				case -1:
					perror("fork"); /* произошла ошибка */
					exit(1); /*выход из родительского процесса*/
				case 0:
					system(input);
					break;
			}
		}
		else if (strcmp(input, ex) == 0){
			break;
		} else system(input);
	}
	return 0;
}