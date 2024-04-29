#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[50];
	int idade;
}Pessoa;

typedef struct no{
	Pessoa pessoa;
	struct No *proximo;
}No;

void imprimir(No *node) {
    No *no = node;
    do {
        printf("|Posicao de memoria: %p\t\tPosicao de memoria que aponta: %p\n|Nome Pessoa: %s\n", no, no->proximo, no->pessoa.nome);
        printf("\n\n");
        
        if(no->proximo == NULL){
            break;
        } else {
            no = no->proximo;
        }
    } while(1);
}


No* criar(No *node){
	No *novo = (No*)malloc(sizeof(No));
	Pessoa novaP;
	
	printf("-> Nome da pessoa : ");
	char nomee[50];
	scanf(" %49[^\n]", novaP.nome);

	
	
	printf("-> idade da pessoa : ");
	scanf("%d",&novaP.idade);
	
	novo->pessoa = novaP;
	novo->proximo = node;
	
	system("cls");
	
	return novo;
}

No* remover(No *node){
	No *anterior;
	if(node != NULL){
		anterior = node->proximo;
		free(node);
		return anterior;
	}else{
		printf("\n\nNAO FOI POSSIVEL REMOVER\n\n");
		return NULL;
	}
	
}

int main(void){
	No *topo = NULL;
	
	while(1){
		
		int op = NULL;
		printf("| 1 -> Criar pessoa\n| 2 -> Listar pessoas\n| 3 -> remover pessoa da lista\n| opcao --> ");
		scanf("%d",&op);
		
		switch(op){
			case 1:
				system("cls");
				topo = criar(topo);
				break;
			case 2:
				system("cls");
				imprimir(topo);
				break;
			case 3:
				system("cls");
				topo = remover(topo);
				break;
			default:
				system("cls");
				break;
		}
		
	}
	return 0;
}
