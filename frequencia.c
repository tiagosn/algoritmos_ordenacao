#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b){
  return (*(int*)a - *(int*)b);
}

int main(void){
	int n, i, last, out;
	int *a;
	
	scanf("%d", &n);
	
	a = (int *)malloc(sizeof(int) * n);
	
	for(i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	
	qsort (a, n, sizeof(int), compare);
	
	last = -1;
	out = 0;
	for(i = 0; i < n; ++i){
		if(a[i] != last){
			++out;
			last = a[i];
		}
	}
	
	printf("%d\n", out);
	
	return 0;
}
