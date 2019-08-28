#include <stdio.h>

int main(int argc, char *argv[]){
	int n;
	sscanf(argv[1], "%d", &n);
	if (n==1){
		for (int i = 0; i < 7; i++){
			for (int j = 0; j < i+1; j++){
				printf("%c", '*');
			}
			printf("%c", '\n');
		}
	}
	else if (n==2){
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < i+1; j++){
				printf("%c", '*');
			}
			printf("%c", '\n');
		}
		for (int i = 0; i < 3; i++){
			for (int j = 4; j > i+1; j--){
				printf("%c", '*');
			}
			printf("%c", '\n');
		}
	}
	else{
		for (int i = 0; i < 7; i++){
			printf("%s\n", "*******");
		}
	}
	return 0;
}