#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int *a, int size);

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

	selection_sort(a, n);

	printf("Vetor ordenado:\n\t");
	for(i = 0; i < n; ++i){
		printf("%d ", a[i]);
	}
	printf("\n\n");

	free(a);

	return 0;
}

void selection_sort(int *a, int size){
	int i, j, min, aux;

	for(i=0; i<size-1; ++i){
		min = i;

		for(j= i+1; j < size; ++j){
			if(a[j] < a[min])
				min = j;
		}
		
		aux = a[min];
		a[min] = a[i];
		a[i] = aux;
	}
} 