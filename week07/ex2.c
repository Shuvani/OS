#include <stdio.h>
#include <stdlib.h>

int main(){
	int N;
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
	free(a);
	return 0;
}