#include <stdio.h>
#include <stdlib.h>

struct page{
    int number;
    unsigned char page_counter;
	char R;
};

int main(int argc, char *argv[]){

	if (argc < 3)
		exit(1);

	int N = atoi(argv[1]);
	FILE *inputfile = fopen(argv[2], "r");
	
	/* Table Initialization: */

	struct page pagetable[N];
	for (int i = 0; i < N; i++){
		pagetable[i].number = -1;
		pagetable[i].R = 0;
		pagetable[i].page_counter = 0;
	}

	/* Main Algorithm: */
	int hits = 0, misses = 0; 
	int pageaddres;
	while (fscanf(inputfile, "%d", &pageaddres) != EOF){
		char isfound = 0;

		for (int i = 0; i < N; i++){
			pagetable[i].page_counter >>= 1;
			pagetable[i].page_counter += pagetable[i].R * 128;
			pagetable[i].R = 0;

			if (pagetable[i].number == pageaddres){
				isfound = 1;
				pagetable[i].R = 1;
			}
		}

		if (isfound){
			hits++;
			continue;
		}else{
			misses++;

			int minpc = __INT_MAX__, minpcI;
			for (int i = 0; i < N; i++){
				if(pagetable[i].number == -1){
					minpcI = i;
					break;
				}else if(pagetable[i].page_counter < minpc){
					minpc = pagetable[i].page_counter;
					minpcI = i;
				}
			}

			pagetable[minpcI].page_counter = 0;
			pagetable[minpcI].R = 1;
			pagetable[minpcI].number = pageaddres;
		}
	}

	printf("%g\n", (double)hits/misses);

	return 0;
}