#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int valor;
	struct no *direita, *esquerda;
}NoArv;

NoArv* inserir_v1(NoArv *raiz, int num){
	if(raiz == NULL){
		NoArv *aux = malloc(sizeof(NoArv));
		
		aux->valor = num;
		aux->esquerda = NULL;
		aux->direita = NULL;
		
		return aux;
	}else{
		if(num < raiz->valor){
			raiz->esquerda = inserir_v1(raiz->esquerda, num);
		}else{
			raiz->direita = inserir_v1(raiz->direita, num);
		}
		
		return raiz;
	}
}

void inserir_v2(NoArv **raiz, int num){
	if(*raiz == NULL){
		*raiz = malloc(sizeof(NoArv));
		(*raiz)->valor = num;
		(*raiz)->esquerda = NULL;
		(*raiz)->direita = NULL;
	}else{
		if(num < (*raiz)->valor){
			inserir_v2(&((*raiz)->esquerda),num);
		}else{
			inserir_v2(&((*raiz)->direita),num);
		}
	}
}

void inserir_v3(NoArv **raiz, int num){
	NoArv *aux = *raiz;
	while(aux){
		if(num < aux->valor)
			raiz = &aux->esquerda;
		else
			raiz = &aux->direita;
		aux = *raiz;
	}
	aux = malloc(sizeof(NoArv));
	aux->valor = num;
	aux->esquerda = NULL;
	aux->direita = NULL;
	*raiz = aux;
}

void imprimir_pre_ordem(NoArv *raiz){
	if(raiz){
		imprimir_pre_ordem(raiz->esquerda);
		printf("%d ",raiz->valor);
		imprimir_pre_ordem(raiz->direita);
	}
}

void imprimir_in_ordem(NoArv *raiz){
	if(raiz){
		imprimir_in_ordem(raiz->esquerda);
		printf("%d ",raiz->valor);
		imprimir_in_ordem(raiz->direita);
	}
}

void imprimir_pos_ordem(NoArv *raiz){
	if(raiz){
		imprimir_pos_ordem(raiz->esquerda);
		imprimir_pos_ordem(raiz->direita);
		printf("%d ",raiz->valor);
	}
}

int main(void){
	NoArv *raiz = NULL;
	
	int opcao , valor;
	
	do{
		printf("\n0 - Sair\n1 - Inserir\n2 - imprimir\n");
		scanf("%d",&opcao);
		
		switch(opcao){
			case 1:
				printf("\nValor : ");
				scanf("%d",&valor);
				inserir_v3(&raiz, valor);
				break;
			case 2:
				imprimir_in_ordem(raiz);
				printf("\n");
				imprimir_pre_ordem(raiz);
				printf("\n");
				imprimir_pos_ordem(raiz);
				printf("\n");
		}
	}while(opcao != 0);
	
//	do{
//		printf("\n0 - Sair\n1 - Inserir\n2 - imprimir\n");
//		scanf("%d",&opcao);
//		
//		switch(opcao){
//			case 1:
//				printf("\nValor : ");
//				scanf("%d",&valor);
//				inserir_v2(&raiz, valor);
//				break;
//			case 2:
//				imprimir_in_ordem(raiz);
//				printf("\n");
//				imprimir_pre_ordem(raiz);
//				printf("\n");
//				imprimir_pos_ordem(raiz);
//				printf("\n");
//		}
//	}while(opcao != 0);
	
//	raiz = inserir_v1(raiz,24);
//	raiz = inserir_v1(raiz,241);
//	raiz = inserir_v1(raiz,214);
//	raiz = inserir_v1(raiz,4);
//	raiz = inserir_v1(raiz,2);
//	raiz = inserir_v1(raiz,84);
//	
//	
//	imprimir_pre_ordem(raiz);
//	printf("\n");
//	imprimir_in_ordem(raiz);
//	printf("\n");
//	imprimir_pos_ordem(raiz);
	
	
	
	return 0;
}
