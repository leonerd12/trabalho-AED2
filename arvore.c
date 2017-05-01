#include <stdio.h>
#include <stdlib.h>

#define TAM_Q1 50
#define TAM_Q2 1000000

typedef struct arvore {
	int dado;
	struct arvore* esq;
	struct arvore* dir;
} Arvore;

Arvore* init() {
	return NULL;
}

void insereArvore(Arvore** arv, int dado) {
	if (*arv == NULL) {
		*arv = (Arvore*) malloc(sizeof(Arvore));
	    (*arv)->esq = NULL;
	    (*arv)->dir = NULL;
	    (*arv)->dado = dado;
	}
	else {
		if (dado < (*arv)->dado) {
			insereArvore(&(*arv)->esq, dado);
		}
		else {
			insereArvore(&(*arv)->dir, dado);
		}
	}
}

void arvorePreFixada(Arvore* arv) {
	if (arv != NULL) {
		printf("%d ", arv->dado);
		arvorePreFixada(arv->esq);
		arvorePreFixada(arv->dir);
	}
}

void arvoreCentral(Arvore* arv) {
	if (arv != NULL) {
		arvoreCentral(arv->esq);
		printf("%d ", arv->dado);
		arvoreCentral(arv->dir);
	}
}

void arvorePosFixada(Arvore* arv) {
	if (arv != NULL) {
		arvorePosFixada(arv->esq);
		arvorePosFixada(arv->dir);
		printf("%d ", arv->dado);
	}
}

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

int main() {
	int num;
	int valores[TAM_Q1];
	Arvore* arv;

	embaralhar(valores, TAM_Q1);
	arv = init();

	// Insere valores do vetor na árvore
	for (int i = 0; i < TAM_Q1; i++) {
		insereArvore(&arv, valores[i]);
	}

	printf("\n>> Arvore preenchida com os valores na seguinte ordem:\n");
	imprimeVetor(valores, TAM_Q1);

	printf("\n>> Caminhamento em pre-ordem:\n");
	arvorePreFixada(arv);
	printf("\n");

	printf("\n>> Caminhamento ordem:\n");
	arvoreCentral(arv);
	printf("\n");

	printf("\n>> Caminhamento em pos-ordem:\n");
	arvorePosFixada(arv);
	printf("\n\n");
}
