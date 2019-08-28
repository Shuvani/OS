#include <stdio.h>
#include <float.h>
#include <limits.h>

int main(){
	int i;
	float f;
	double d;
	i = INT_MAX;
	f = FLT_MAX;
	d = DBL_MAX;
	printf("Size_of_int = %lu, Size_of_float = %lu, Size_of_double = %lu\n", sizeof(i), sizeof(f), sizeof(d));
	printf("int = %d, float = %f, double = %f\n", i, f, d);
	return 0;
}
