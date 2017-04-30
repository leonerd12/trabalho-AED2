#include <stdio.h>
#include <stdlib.h>

typedef struct Arvore
{
	int dado;
	struct Arvore* esq;
	struct Arvore* dir;
}Arvore;

void init(Arvore *a){
	a = NULL;
}

Arvore* insereArvore(Arvore *arv, int dado){
	if(arv == NULL){
		Arvore* aux = (Arvore*) malloc(sizeof(Arvore));
		aux->dado = dado;
		aux->esq = NULL;
		aux->dir = NULL;
		return aux;
	}
	if(dado < arv->dado){
		arv->esq = insereArvore(arv->esq, dado);
	}
	if(dado > arv->dado){
		arv->dir = insereArvore(arv->dir, dado);
	}
	return arv;
}

//em ordem
void percorrerArvore(Arvore *arv){
	if (arv == NULL) return;
	percorrerArvore(arv->esq);
	printf("%d\n", arv->dado);
	percorrerArvore(arv->dir);
}

int main(){
	int num;
	Arvore *a1;
	init(a1);
	for(int i = 0; i < 10; i++){
		printf("Digite um número: ");
		scanf("%d", &num);
		a1 = insereArvore(a1, num);
	}
	percorrerArvore(a1);
	return 0;
}
