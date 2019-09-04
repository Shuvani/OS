#include <stdio.h>
#define N 10

void bubble_sort(int a[ ], int n) {
    int temp;
	for (int k = 0; k < n-1; k++){
		for(int i = 0; i < n-1-k; i++) {
			if(a[i] > a[i+1] ) {
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
			}
		}
	}
}

int main() {
	int a[N] = {5, 1, 4, 2 , 8, 16, 3, 24, 25, 6};
	bubble_sort(a, N);
	for (int i = 0; i < N; i++){
		printf("%d\n", a[i]);
	}
	return 0;
}