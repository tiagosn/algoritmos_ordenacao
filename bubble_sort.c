
/* Bubble sort */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int n, int *vet);
void bubble_sort_rec(int n, int *vet);

/*
 * Parametros:
 * 		./bubble_sort <tamanho_vetor>
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

	//bubble_sort(n, a);
	bubble_sort_rec (n, a);

	printf("Vetor ordenado:\n\t");
	for(i = 0; i < n; ++i){
		printf("%d ", a[i]);
	}
	printf("\n\n");

	free(a);

	return 0;
}

void bubble_sort(int n, int *vet) {
  long c, d, t;
 
  for (c = 0 ; c < ( n - 1 ); c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (list[d] > list[d+1])
      {
        /* Swapping */
 
        t         = list[d];
        list[d]   = list[d+1];
        list[d+1] = t;
      }
    }
  }
}

void bubble_sort_rec(int n, int *vet) {
	int i;
	int aux, flag = 0;

	for (i = 0; i < n-1; i++) {
		if (vet[i] > vet[i+1]) {
			aux = vet[i];
			vet[i] = vet[i + 1];
			vet[i + 1] = aux;
			flag = 1;
		}
	}

	if (flag != 0)
		bubble_sort_rec(n-1, vet);
}
