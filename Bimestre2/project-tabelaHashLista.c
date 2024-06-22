#include <stdio.h>
#include <stdlib.h>

#define tam 11

typedef struct No{
	int num;
	struct No *proximo;
}No;

int hash(int valor){
	return valor % tam;
}

void inserir(int valor, No v[]){
	No* novo = malloc(sizeof(No));
	
	novo->proximo = NULL;
	novo->num = valor;
	
	int id = hash(valor);
	
	if(v[id].proximo == NULL){
		v[id].proximo = novo;
	}else{
		No* aux = v[id].proximo;
		while(aux->proximo != NULL){
			aux = aux->proximo;
		}
		aux->proximo = novo;
	}
}

void imprimir(No v[]){
	int a;
	for(a = 0 ; a < tam; a++){
		No* n = v[a].proximo;
		printf("Posicao %d : ",a);
		if(n != NULL){
			while(n != NULL){
				printf("%d -> ",n->num);
				n = n->proximo;
			}
			printf("null\n");
		}else{
			printf("null\n");
		}
	}
}


int main(void){
	
	No vet[tam] = {0};
	
	inserir(1,vet);
	inserir(2,vet);
	inserir(3,vet);
	inserir(4,vet);
	
	inserir(1,vet);
	inserir(2,vet);
	inserir(3,vet);
	inserir(4,vet);
	
	inserir(1,vet);
	inserir(2,vet);
	inserir(3,vet);
	inserir(4,vet);
	
	
	
	
	imprimir(vet);
	
	
	return 0;
}
