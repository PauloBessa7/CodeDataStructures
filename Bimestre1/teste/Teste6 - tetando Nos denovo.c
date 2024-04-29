#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[50];
	int idade;
}Pessoa;

typedef struct no{
	Pessoa p;
	struct no *proximo;	
}No;

Pessoa criarPessoa(){
	Pessoa p;
	printf("\n-> Escreva o nome da pessoa: ");
	char nome[50];
	scanf("%49s",nome);
	printf("\n-> Escreva a idade da pessoa: ");
	int idade;
	scanf("%d",&idade);
	
	strcpy(p.nome,nome);
	p.idade = idade;
	
	return p;
}

No* criar(No *node){
	No *novo = (No*)malloc(sizeof(No));
	Pessoa p = criarPessoa();
	novo->p = p;
	novo->proximo = node;
	return novo;
}

int main(void){
	No *topo = NULL; // serve apenas para guardar uma posicao de memoria que é um No
	
	topo = criar(topo);
	printf("\n|Nome da pessoa : %s\n|Idade da pessoa : %d\n|Posicao de memoria : %p\n\n", topo->p.nome, topo->p.idade, (void *)topo);
	
	topo = criar(topo);
	printf("\n|Nome da pessoa : %s\n|Idade da pessoa : %d\n|Posicao de memoria : %p\n\n", topo->p.nome, topo->p.idade, (void *)topo);


	

	
	
	
	
	
	return 0;
}
