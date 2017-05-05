#include <stdio.h>
#include <stdlib.h>
#include "tad-arvore.h"

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

void buscaArv(Arvore* raiz, int chave){
	if(raiz != NULL){
		if(raiz->dado == chave){
			printf("achou\n");
		}else if(chave < raiz->dado){
			buscaArv(raiz->esq, chave);
		}else if(chave > raiz->dado){
			buscaArv(raiz->dir, chave);
		}
	}
	// return -1;
}
