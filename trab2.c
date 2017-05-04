#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tad-vetor.c"
#include "tad-arvore.c"

#define TAM_Q1 50
#define TAM_Q2 1000000

int main() {
    int num, i;
	int valores[TAM_Q1];
  	int vetor[TAM_Q2];
	Arvore* arv;
  	Arvore* arv2;
  	int chaves[30];
  	float tempoVet = 0, mediaVet = 0;
  	float tempoArv = 0, mediaArv = 0;
  	clock_t start;

	embaralhar(valores, TAM_Q1);
	arv = init();

	// Insere valores do vetor na árvore
	for (i = 0; i < TAM_Q1; i++) {
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

  	//questão2

  	arv2 = init();
  	embaralhar(vetor, TAM_Q2);

  	for (int i = 0; i < TAM_Q2; i++) {
		insereArvore(&arv2, vetor[i]);
	}

  	quickSort(vetor, TAM_Q2);

  	selecionaChaves(chaves, 30, vetor, TAM_Q2);

  	for (i = 0; i < 30; i++) {
      	start = clock();
    	buscaBinaria(vetor, TAM_Q2, chaves[i]);
      	tempoVet = (clock() - start) / (double) CLOCKS_PER_SEC;
        mediaVet += tempoVet;
        printf("\nChave: %d\nTempo de busca no vetor: %.15lf\n", chaves[i],tempoVet);

        //start = clock();
    	//buscaBinaria(vetor, TAM_Q2, chaves[i]);
      	//tempoArv = (clock() - start) / (double) CLOCKS_PER_SEC;
        //mediaArv+= tempoArv;
        //printf("Tempo de busca na árvore: %.15lf\n\n", tempoArv);
    }

    printf("\nTempo médio da Busca Binária no vetor: %.15lf\n\n", (mediaVet)/i);
    //printf("Tempo médio da Busca na Árvore:        %.15lf\n", (mediaArv)/i);
}
