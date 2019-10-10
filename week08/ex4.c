#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#define N 26214400

int main(){
	for(int i=0; i<10; i++){
		int *a = malloc(N*sizeof(int));
		for (int i = 0; i < N; i++){
			a[i] = 0;
		}
		struct rusage this_procces;
		getrusage(RUSAGE_SELF, &this_procces);
		printf("%ld\n", this_procces.ru_maxrss);
		sleep(1);
	}
	return 0;
}