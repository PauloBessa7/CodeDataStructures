#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char nome[50];
	int idade;
}Pessoa;

typedef struct no{
	Pessoa pessoa;
	struct no *proximo;
}No;

typedef struct{
	struct No *inicio;
	struct No *fim;
	int tam ;
}Fila;

void criarNo(Fila *fila);
Pessoa criarPessoa();
No* criar(No *node, Pessoa p);

int main(void){
	Fila *fila = {NULL,NULL,0};
	int i = 1;
	do{
		printf("Entre com as opcao:\n");
		printf("1 -> Criar\n");
		printf("2 -> Listar\n");
		printf("3 -> Deletar\n");	
		printf("Sua opcao -> ");
		int op;
		scanf("%d",&op);
		switch(op){
			case 1:
				criarNo(fila);
//				system("cls");
				break;
			case 2:
				system("cls");
				break;
			case 3:
				system("cls");
				break;
			default :
				i = 0;
				break;
		}
	}while(i);
	
	return 0;
}

void criarNo(Fila *fila){
	No *novo = (No*)malloc(sizeof(No));
	
	
}


Pessoa criarPessoa(){
	Pessoa p;
	printf("\n|Nome da Pessoa : ");
	scanf("%s",p.nome);
	
	printf("|Idade da Pessoa : ");
	scanf("%d",&p.idade);
	return p;
}

No* criar(No *node, Pessoa p){
	
}

