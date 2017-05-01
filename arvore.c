#include <stdio.h>
#include <stdlib.h>

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

void percorrerArvore(Arvore* arv) {
	if (arv != NULL) {

		printf("%d ", arv->dado);
		percorrerArvore(arv->esq);
		percorrerArvore(arv->dir);

	}
}

void arvorePreFixada(Arvore* arv) {
	if (arv != NULL) {
		printf("%d ", arv->dado);
		percorrerArvore(arv->esq);
		percorrerArvore(arv->dir);
	}
}

void arvoreCentral(Arvore* arv) {
	if (arv != NULL) {
		percorrerArvore(arv->esq);
		printf("%d ", arv->dado);
		percorrerArvore(arv->dir);
	}
}

void arvorePosFixada(Arvore* arv) {
	if (arv != NULL) {
		percorrerArvore(arv->esq);
		percorrerArvore(arv->dir);
		printf("%d ", arv->dado);
	}
}

int main() {
	int num;
	Arvore* arv;

	arv = init();

	for (int i = 0; i < 10; i++) {
		scanf("%d", &num);
		insereArvore(&arv, num);
	}

	printf("Arvore preenchida.\n");
	percorrerArvore(arv);

}
