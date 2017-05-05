#ifndef TADARVORE_H
#define TADARVORE_H

typedef struct arvore {
	int dado;
	struct arvore* esq;
	struct arvore* dir;
} Arvore;

Arvore* init() {
	return NULL;
}

void insereArvore(Arvore** arv, int dado);
void arvorePreFixada(Arvore* arv);
void arvoreCentral(Arvore* arv);
void arvorePosFixada(Arvore* arv);
int buscaArv(Arvore* arv, int chave);

#endif
