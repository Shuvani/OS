#include <stdio.h>
#define n 6

void quik_sort(int *arr, int first, int last){
     if (first < last)
    {
        int left = first;
		int right = last;
		int middle = arr[(left + right) / 2];
        do{
            while (arr[left] < middle) left++;
            while (arr[right] > middle) right--;
            if (left <= right)
            {
                int tmp = arr[left];
                arr[left] = arr[right];
                arr[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        quik_sort(arr, first, right);
        quik_sort(arr, left, last);
    }
}

int main(){
	int a[n] = {1, 6, 4, 5, 2, 8};
	quik_sort(a, 0, n-1);
	for (int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}