#include <stdio.h>

int main(int argc, char *argv[]){
	int n;
	sscanf(argv[1], "%d", &n);
	for (int j = 1; j < (2*n); j=j+2){
		for (int f = 0; f < (2*n-j)/2; f++){
			printf("%c", ' ');
		}
		for (int s = 0; s < j; s++){
			printf("%c", '*');
		}
		for (int t = 0; t < (2*n-j)/2; t++){
			printf("%c", ' ');
		}
		printf("%c", '\n');
	}
	return 0;
}