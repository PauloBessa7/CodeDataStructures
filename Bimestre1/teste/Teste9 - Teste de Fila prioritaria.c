#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int valor;
	struct no *proximo;
}No;

//void inserir(No **fila, int num){
//	No *aux , *novo = malloc (sizeof(No));
//	if(novo){
//		novo->valor = num;
//		novo->proximo = NULL;
//		if(*fila == NULL){
//			*fila = novo;
//		}else{
//			aux = *fila;
//			while(aux->proximo){
//				aux = aux->proximo;
//			}
//			aux->proximo->proximo = novo;
//		}
//	}else{
//		printf("\nErro ao alocar memória.\n");
//	}
//}
void inserirp(No **fila,int num){
	No *aux, *novo = malloc (sizeof(No));	
	if(novo){
		novo->valor = num;
		novo->proximo = NULL;
		if(*fila == NULL){
			*fila = novo;
		}else{
			if(num > 59){
				if((*fila)->valor < 60){
					novo->proximo = *fila;
					*fila = novo;
				}else{
					aux = *fila;
					while(aux->proximo && aux->proximo->valor > 59){
						aux = aux->proximo;
					}
					novo->proximo = aux->proximo;
					aux->proximo = novo;
				}
			}else{
				
			}
		}
	}
}



int main(void){
	
	
	
	return 0;
}
