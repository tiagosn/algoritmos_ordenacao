#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int *a, int size);
void insertion_sort_rec(int *a, int end, int size);

/*
 * Parametros:
 * 		./selection_sort <tamanho_vetor>
 */

int main(int argc, char **argv){
	int n = atoi(argv[1]);
	int *a = (int*)malloc(n*sizeof(int));
	int i;

	srand(time(NULL));

	srand(100);

	for(i = 0; i < n; ++i){
		a[i] = rand()%100;
	}

	printf("\nVetor original:\n\t");
	for(i = 0; i < n; ++i){
		printf("%d ", a[i]);
	}
	printf("\n\n");

	//insertion_sort(a, n);
	insertion_sort_rec(a, 1, n);

	printf("Vetor ordenado:\n\t");
	for(i = 0; i < n; ++i){
		printf("%d ", a[i]);
	}
	printf("\n\n");

	free(a);

	return 0;
}

void insertion_sort(int *a, int size){
	int i, j, value;

	for (i=1; i<size; ++i){
		value = a[i];
		j=i-1;
		while(j >= 0 && a[j] > value){
			a[j+1] = a[j];
			--j;
		}
		a[j+1] = value;
	}
} 

void insertion_sort_rec(int *a, int end, int size){

	int j, value;
	value = a[end];
	j=end-1;
	while(j >= 0 && a[j] > value){
		a[j+1] = a[j];
		--j;
	}
	a[j+1] = value;
	
	if(end < (size -1))
		 insertion_sort_rec(a,++end,size);
}