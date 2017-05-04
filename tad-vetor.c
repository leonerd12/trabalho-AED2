#include <stdio.h>
#include <stdlib.h>
#include "tad-vetor.h"

void embaralhar(int vet[], int tam) {
	int temp, novaPosicao;

	// Gera vetor com valores de 1 à 'tam'
	for (int i = 0; i < tam; i++) {
		vet[i] = i+1;
	}

	// Embaralha os valores do vetor
	for (int i = 0; i < tam; i++) {
		novaPosicao = rand() % tam;
		temp = vet[i];
		vet[i] = vet[novaPosicao];
		vet[novaPosicao] = temp;
	}
}

void imprimeVetor(int vet[], int tam) {
	for (int i = 0; i < tam; i++) {
		printf("%d ", vet[i]);
	}
	printf("\n");
}

void selecionaChaves(int chaves[], int n, int vet[], int tam) {
    int i, posicao;
    for (i = 0; i < n; i++) {
        posicao = rand() % tam; // Sorteia posição no intervalo 0 - tam
        chaves[i] = vet[posicao];
    }
}

void quickSortInterno(int vet[], int inicio, int fim) {
    int pivot;
    int temp;
    int i,j;

    if (fim - inicio > 0) {
        i = inicio;
        j = fim;
        pivot = vet[(i + j) / 2];

        do {
            while (vet[i] < pivot) i++;
            while (vet[j] > pivot) j--;
            if (i <= j) {
                temp = vet[i];
                vet[i] = vet[j];
                vet[j] = temp;
                i++;
                j--;
            }
        } while (i <= j);

        if (inicio < j) quickSortInterno(vet, inicio, j);
        if (i < fim) quickSortInterno(vet, i, fim);
    }
}

void quickSort(int vet[], int tam) {
    quickSortInterno(vet, 0, tam-1);
}

int buscaBinaria(int vet[], int tam, int chave) {
    int meio, inicio = 0, fim = tam -1;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (chave > vet[meio]) {
            inicio = meio + 1;
        }
        else if (chave < vet[meio]) {
            fim = meio - 1;
        }
        else {
            return meio;
        }
    }
    return -1;
}
