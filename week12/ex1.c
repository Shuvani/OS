#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int randomData = open("/dev/random", O_RDONLY);
    if (randomData < 0){
        close(randomData);
		exit(EXIT_FAILURE);
    }
    char myRandomData[21];
    size_t randomDataLen = 0;
    while (randomDataLen < sizeof myRandomData){
        ssize_t result = read(randomData, &myRandomData[randomDataLen], (sizeof myRandomData) - randomDataLen);
        randomDataLen += result;
    }
    close(randomData);
    for(int i=0; i<20; i++){
        printf("%c", myRandomData[i]);
    }
    return 0;
}