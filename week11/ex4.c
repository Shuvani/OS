#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h> 
#include<string.h>
#include <stdio.h>

int main(){
	int fd = open("ex1.txt", O_RDWR);
	struct stat st;
	if(fstat(fd, &st) < 0){
		close(fd);
		exit(EXIT_FAILURE);
	}
	size_t fsize = (size_t)st.st_size;
	unsigned char* dataPtr = (unsigned char*)mmap(NULL, fsize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	
	int fd2 = open("ex1.memcpy.txt", O_CREAT | O_RDWR | O_TRUNC);
	ftruncate(fd2, fsize);
	struct stat st2;
	if(fstat(fd2, &st2) < 0){
		printf("%c", 'F');
		close(fd2);
		exit(EXIT_FAILURE);
	}
	size_t fsize2 = (size_t)st2.st_size;
	lseek(fd2, 0, SEEK_SET);
	unsigned char* dataPtr2 = (unsigned char*)mmap(NULL, fsize2, PROT_READ | PROT_WRITE, MAP_SHARED, fd2, 0);

	memcpy (dataPtr2, dataPtr, fsize);
	
	close(fd);
	close(fd2);
	munmap(dataPtr, fsize);
	munmap(dataPtr2, fsize2);
	return 0;
}