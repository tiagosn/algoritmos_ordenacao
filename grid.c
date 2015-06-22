#include <stdio.h>
#include <stdlib.h>

int bubble_count(int *v, int n){
	int aux;
	int count = 0;
	int i, j;
	for(i=n-1; i >= 1; i--){
 		for(j=0; j < i ; j++) {
			if(v[j]>v[j+1]) {
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
				count++;				
			}
		}
	}

	return count;
}

int main(void){
	int n, i, result;	
	int *ini, *fim, *aux;

	while(scanf("%d", &n) != EOF){
		ini = (int*)malloc(sizeof(int)*n);
		fim = (int*)malloc(sizeof(int)*n);

		for(i = 0; i < n; ++i){
			scanf("%d", &ini[i]);
		}

		for(i = 0; i < n; ++i){
			scanf("%d", &fim[i]);
		}

		//Preparo o vetor para realizar o BubbleSort
		aux = (int*)malloc(sizeof(int)*n);
		for(i = 0; i < n; ++i){
			aux[i] = ini[fim[i]-1];
		}

		result = bubble_count(aux, n);

		printf("%d\n", result);

		free(ini);
		free(fim);
		free(aux);
	}
	return 0;
}
