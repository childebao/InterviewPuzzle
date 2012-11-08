#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ABS(a) (a > 0 ? a : -(a))
#define MAX(a, b) (a > b ? a : b)

int main() {
	int cases;
	long double ave_x = 0, ave_y = 0;
	long double min;
	unsigned int min_index = 0;
	unsigned long long int sum = 0;
	
	scanf("%d", &cases);
	
  long int x[cases], y[cases];
	
	for (int i=0; i<cases; i++) {
		scanf("%ld %ld", &(x[i]), &(y[i]));
		ave_x += (long double) x[i] / cases;
		ave_y += (long double) y[i] / cases;
	}
	
	min = sqrt((ave_x-x[0])*(ave_x-x[0]) + (ave_y-y[0])*(ave_y-y[0]));
	
	for (int i=1; i<cases; i++) {
		double diff = sqrt((ave_x-x[i])*(ave_x-x[i]) + (ave_y-y[i])*(ave_y-y[i]));
		if (diff < min) {
			min = diff;
			min_index = i;
		}
	}
	
	for (int i=0; i<cases; i++) {
		sum += MAX((ABS(x[min_index]-x[i])), (ABS(y[min_index]-y[i])));
	}
  
	printf("%llu\n", sum);
	
	return 0;
}