#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quick_sort(int *a, int size);
void quick_sort_rec(int *a, int first, int last);

/*
 * Parametros:
 * 		./quick_sort <tamanho_vetor>
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

	quick_sort(a, n);

	printf("Vetor ordenado:\n\t");
	for(i = 0; i < n; ++i){
		printf("%d ", a[i]);
	}
	printf("\n\n");

	free(a);

	return 0;
}

void quick_sort(int *a, int size){
	quick_sort_rec(a, 0, size - 1);
}

void quick_sort_rec(int *a, int first, int last){
	if(last - first <= 0) return;
		
	int pivot_idx = first;
	int pivot_val = a[pivot_idx];
	int aux, i, div = first;
	
	a[pivot_idx] = a[last];
	a[last] = pivot_val;
	
	for(i = first; i < last; ++i){
		if(a[i] <= pivot_val){
			aux = a[i];
			a[i] = a[div];
			a[div] = aux;
			
			++div;
		}
	}
	
	a[last] = a[div];
	a[div] = pivot_val;
	
	quick_sort_rec(a, first, div - 1);
	quick_sort_rec(a, div + 1, last);
}
