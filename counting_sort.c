#include <stdio.h>
#include <stdlib.h>

void counting_sort(int *faltas, char **alunos, int n, int k);
void simple_counting_sort(int *faltas, char **alunos, int n, int k);

void print_array_int(int *a, int size);

int main(void){
	int faltas[12] = {8, 5, 2, 5, 1, 8, 3, 1, 2, 4, 7, 1};
	char *alunos[12] = {"Joao", "Jose", "Maria", "Paulo", "Ana", "Pedro", "Rita", "Carlos", "Roberto", "Joana", "Fernando", "Antonio"};

	printf("Simple:\n");
	simple_counting_sort(faltas, alunos, 12, 10);

	printf("\nCouting Sort:\n");
	counting_sort(faltas, alunos, 12, 10);
	
	return 0;
}

void counting_sort(int *faltas, char **alunos, int n, int k){
	int *count = (int *)malloc(k*sizeof(int));
	int *first_idx = (int *)malloc(k*sizeof(int));
	int *out_idx = (int *)malloc(n*sizeof(int));
	int i, total;
		
	for(i = 0; i < k; ++i){
		count[i] = 0;
	}
	printf("count = "); print_array_int(count, k);
	
	for(i = 0; i < n; ++i){
		++count[faltas[i]];
	}
	printf("count = "); print_array_int(count, k);
	
	total = 0;
	for(i = 0; i < k; ++i){
		first_idx[i] = total;
		total += count[i];
	}
	printf("first_idx = "); print_array_int(first_idx, k);
	
	for(i = 0; i < n; ++i){
		out_idx[first_idx[faltas[i]]] = i;
		first_idx[faltas[i]] = first_idx[faltas[i]] + 1;
	}
	printf("out_idx = "); print_array_int(out_idx, n);
	
	for(i = 0; i < n; ++i){
		printf("{%d, %s} ", faltas[out_idx[i]], alunos[out_idx[i]]);
	}
	printf("\n");
	
	free(count);
	free(first_idx);
	free(out_idx);
}

void simple_counting_sort(int *faltas, char **alunos, int n, int k){
	int *count = (int *)malloc(k*sizeof(int));
	int i, j;
	
	for(i = 0; i < k; ++i){
		count[i] = 0;
	}
	printf("count = "); print_array_int(count, k);
	
	for(i = 0; i < n; ++i){
		++count[faltas[i]];
	}
	printf("count = "); print_array_int(count, k);
	
	for(i = 0; i < k; ++i){
		for(j = 0; j < count[i]; ++j){
			printf("{%d, -} ", i);
		}
	}
	printf("\n");
	
	free(count);
}

void print_array_int(int *a, int size){
	int i;
	
	if(size <= 0) return;
	
	printf("[%d", a[0]);
	for(i = 1; i < size; ++i){
		printf(", %d", a[i]);
	}
	printf("]\n");
}
