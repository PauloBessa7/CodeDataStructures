#include <stdio.h>
#include <stdlib.h>

#define tam 11

typedef struct No{
	int num;
	struct No *proximo;
}No;

typedef struct{
	int tamanho;
	No *inicio;
}Lista;

void iniciarLista(Lista *v){
	v->inicio = NULL;
	v->tamanho = 0;
}

void iniciarTabela(Lista v[]){
	int a;
	for(a = 0; a < tam; a++){
		iniciarLista(&v[a]);
	}
}

int hash(int valor){
	return valor % tam;
}

void inserir_lista(int valor,Lista *l){
	No* novo = malloc(sizeof(No));
	
	novo->proximo = NULL;
	novo->num = valor;
	
	if(l->inicio == NULL){
		l->inicio = novo;
		l->tamanho ++;
	}else{
		No* aux = l->inicio;
		while(aux->proximo != NULL){
			aux = aux->proximo;
		}
		aux->proximo = novo;
	}
}

void inserir(int valor, Lista v[]){
	
	int id = hash(valor);
	
	inserir_lista(valor, &v[id]);
	
}

void imprimir(Lista v[]){
	int a;
	for(a = 0; a < tam; a++){
		if(v[a].inicio != NULL){
			printf("Posicao %d tam(%d): ",a,v[a].tamanho);
			No* aux = v[a].inicio;
			while(aux != NULL){
				printf("%d ->  ",aux->num);
				aux = aux->proximo;
			}
			printf("null\n",a);
		}else{
			printf("Posicao %d tam(0): null\n",a);
		}
	}
}
int main(void){
	
	Lista vet[tam];
	
	iniciarTabela(vet);
	
	inserir(1,vet);
	inserir(1,vet);
	inserir(2,vet);
	
	inserir(11,vet);
	inserir(12,vet);
	inserir(2432,vet);
	
	inserir(761,vet);
	inserir(912,vet);
	inserir(88,vet);
	
	
	imprimir(vet);

	
	
	
	return 0;
}
