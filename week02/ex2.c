#include <stdio.h>
#include <string.h>

int main(){
	int length;
	char str [100];
	char buff;
	fgets(str, 100, stdin);
	length = strlen(str)-1;
	char str2[length];
	str2[length] = str[100];
	for (int i = 0; i < length; i++){
		str2[i] = str[length-1-i];
	}
	printf("%s", str2);
	return 0;
}
