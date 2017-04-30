#include <stdio.h>
#include <stdlib.h>

int cont = 0;

typedef struct Arvore
{
	int dado;
	struct Arvore* esq;
	struct Arvore* dir;
} Arvore;


void insereArvore(Arvore *arv, int dado){
	printf("abriu");
	if(arv == NULL){
		Arvore* aux = (Arvore*) malloc(sizeof(Arvore));
		aux->dado = dado;
		aux->esq = NULL;
		aux->dir = NULL;
		arv = aux;
		printf("dado: %d\n", dado);
		printf("arvore dado: %d\n", arv->dado);
		// cont++;
	}
	printf("fechou");
	// if(dado < arv->dado){
	// 	insereArvore(arv->esq, dado);
	// }
	// if(dado > arv->dado){
	// 	insereArvore(arv->dir, dado);
	// }
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

	// Iniciar árvore
	a1 = NULL;

	for(int i = 0; i < 10; i++){
		printf("Digite um número: ");
		scanf("%d", &num);
		insereArvore(a1, num);
		printf("%d\n", a1->dado);
		// percorrerArvore(a1);
		printf("Nos da arvore: %d\n", cont);
	}
	percorrerArvore(a1);
	return 0;
}
