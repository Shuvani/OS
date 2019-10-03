#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(x, y) (x) > (y) ? (y) : (x) 

void *realloc1(void *ptr, size_t size){
	if (ptr = NULL){
		ptr = (int*)malloc(size);
		return ptr;
	}
	if (size == 0){
		free(ptr);
		return NULL;
	}
	void *new_ptr = malloc(size);
	memcpy(new_ptr, ptr, min(sizeof(*ptr), size));
	printf("sizeof %d\n",(int)sizeof(*ptr));
	/*...*/
	return ptr;
}

int main(){
	int N, M;
	int *a;
	scanf("%d", &N);
	a = (int*)malloc(N*sizeof(int));
	for (int i = 0; i < N; i++){
		a[i] = i;
	}
	for(int i=0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
	scanf("%d", &M);
	a = (int*)realloc1(a, M*sizeof(int));
	for(int i=0; i < M; i++)
    {
        printf("%d ", a[i]);
    }
	free(a);
	return 0;
}