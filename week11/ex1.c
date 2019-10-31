#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h> 
#include<string.h>
#include <stdio.h>
//int open(const char *filename, int access, unsigned mode)
// int fstat(int fd, struct stat *buf);
// void *mmap(void *addr, size_t length, int prot, int flags,int fd, off_t offset);

int main(){
	unsigned char src[25]="This is a nice day";
	int fd = open("ex1.txt", O_RDWR);
	struct stat st;
	if(fstat(fd, &st) < 0){
		close(fd);
		exit(EXIT_FAILURE);
	}
	
	size_t fsize = (size_t)st.st_size;
	unsigned char* dataPtr = (unsigned char*)mmap(NULL, fsize + 1, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	ftruncate(fd, 18);
	memcpy (dataPtr, src, 18);
	
	close(fd);
	munmap(dataPtr, fsize + 1);
	return 0;
}