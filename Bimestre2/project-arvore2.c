#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int valor;
	struct no *direita, *esquerda;
	int altura;
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

NoArv* novoNo(int x){
	NoArv *novo = malloc(sizeof(NoArv));
	
	if(novo){
		novo->valor = x;
		novo->esquerda = NULL;
		novo->direita = NULL;
		novo->altura = 0;
	}else{
		printf("\Erro ao alocar memória.\n");
	}
	return novo;
}

int maior(int a,int b){
	return (a > b)? a:b;
}

int alturaNo(NoArv *no){
	if (no == NULL){
		return -1;
	}else{
		return no->altura;
	}
}

int fatorBalanceamento(NoArv *no){
	if(no){
		return (alturaNo(no->esquerda) - alturaNo(no->direita));
	}else{
		return 0;
	}
}

NoArv* rotacaoEsquerda(NoArv *r){
	NoArv *y, *f;
	
	y = r->direita;
	f = y->esquerda;
	
	y->esquerda = r;
	r->direita = f;
	
	r->altura = maior(alturaNo(r->esquerda) , alturaNo(r->direita)) + 1;
	y->altura = maior(alturaNo(y->esquerda) , alturaNo(y->direita)) + 1;
	
	return y;
}

NoArv* rotacaoDireita(NoArv *r){
	NoArv *y, *f;
	
	y = r->esquerda;
	f = y->direita;
	
	y->direita = r;
	r->esquerda = f;
	
	r->altura = maior(alturaNo(r->esquerda) , alturaNo(r->direita)) + 1;
	y->altura = maior(alturaNo(y->esquerda) , alturaNo(y->direita)) + 1;
	
	return y;
}

NoArv* rotacaoDupla(NoArv *r){
	r->direita = rotacaoDireita(r->direita);
	return rotacaoEsquerda(r);
}

NoArv* balancear(NoArv *raiz){
	int fb = fatorBalanceamento(raiz);
	
	if(fb < -1 && fatorBalanceamento(raiz->direita) <= 0){
		raiz = rotacaoEsquerda(raiz);
	}else if(fb > 1 && fatorBalanceamento(raiz->esquerda) >= 0){
		raiz = rotacaoDireita(raiz);
	}else if(fb > 1 && fatorBalanceamento(raiz->esquerda) < 0){
		raiz = rotacaoEsquerda(raiz);
	}else if(fb <- 1 && fatorBalanceamento(raiz->direita) > 0){
		raiz = rotacaoDupla(raiz);
	}
	
	return raiz;
}

NoArv* inserir(NoArv *raiz, int x){
	if(raiz == NULL){
		return novoNo(x);
	}else{
		if(x < raiz->valor){
			raiz->esquerda = inserir(raiz->esquerda, x);
		}else if(x > raiz->valor){
			raiz->direita = inserir(raiz->direita, x);
		}else{
			printf("\nFalhou a insercao de %d.\n",x);
		}
		
		raiz->altura = maior(alturaNo(raiz->esquerda), alturaNo(raiz->direita)) + 1;
		raiz = balancear(raiz);
	}
}

NoArv* remover(NoArv *raiz, int chave){
	if(raiz == NULL){
		printf("\nValor nao encontrado\n");
		return NULL;
	}else{
		if(raiz->valor == chave){
			if(raiz->esquerda != NULL && raiz->direita != NULL){
				free(raiz);
				printf("\nElemento folha removido: %d\n", chave);
			}else{
				if(raiz->esquerda == NULL && raiz->direita == NULL){
					NoArv *aux = raiz->esquerda;
					while(aux->direita != NULL){
						aux = aux->direita;
					}
					raiz->valor = aux->valor;
					aux->valor = chave;
					printf("\nElemento trocado: %d\n",chave);
					raiz->esquerda = remover(raiz->esquerda, chave);
					return raiz;
				}else{
					NoArv *aux;
					if(raiz->esquerda != NULL){
						aux = raiz->esquerda;
					}else{
						aux = raiz->direita;
					}
					free(raiz);
					printf("\nEelemento nao sei ksksk");
				}
			}
		}
		raiz->altura = maior(alturaNo(raiz->esquerda), alturaNo(raiz->direita)) + 1;
		raiz = balancear(raiz);
		return raiz;
	}
}

void imprimir(NoArv *raiz, int nivel){
	int i;
	if(raiz){
		imprimir(raiz->direita, nivel + 1);
		printf("\n\n");
		
		for(i = 0; i < nivel; i++){
			printf("\t");
		}
		
		printf("%d ", raiz->valor);
		imprimir(raiz->esquerda, nivel + 1);
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
	

	return 0;
}
