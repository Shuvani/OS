#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void *printing(void *arg){
	sleep(1);
	printf("id of the thread %d, I'm the thread number %d\n", (int) pthread_self(), (int) arg);
	sleep(1);
	return(NULL);
}

int main(int argc, char **argv){
	if (argc == 1){
		printf("User is a fool. Specify N\n");
		exit(1);
	}
	
	int N = atoi(argv[1]);
	
	pthread_t array_of_threads[N];
	
	for(int i=0; i<N; i++){
		printf("Thread %d is created\n", i);
		pthread_create(&array_of_threads[i], NULL, printing, i);
		pthread_join(array_of_threads[i], NULL);
		printf("Thread %d is over\n", i);
	}	
	return 0;
}