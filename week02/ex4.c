#include <stdio.h>

void separate(int *first,int *second){
	int buf;
	buf = *first;
	*first = *second;
	*second = buf;
}
int main(){
	int first, second;
	printf("Enter the first number:");
	scanf("%d", &first);
	printf("Enter the second number:");
	scanf("%d", &second);
	separate(&first, &second);
	printf("first number:%d\nsecond number:%d", first, second);
}