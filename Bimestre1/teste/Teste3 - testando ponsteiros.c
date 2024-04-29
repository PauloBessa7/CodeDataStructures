#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[50];
}Pessoa;

void trocaInt(int *a,int *b);
void trocaObj(Pessoa *p1,Pessoa *p2);

int main(void){
	
// Exemplo de codigo para um metodo que faz a troca de dois int por referencia de ponteiro
// *a -> "valor que o pondeiro a aponta"
//	int a,b;
//	a = 5;
//	b = 10;
//	trocaInt(&a,&b);
	
// Exemplo de codigo para um metodo que faz a troca de dois struct por referencia de ponteiro	
//	Pessoa p1;
//	Pessoa p2;
//	trocaObj(&p1,&p2);
//	printf("\nDepois da Troca:    Nome 1: %s \t\tNome 2: %s", p1.nome, p2.nome);
	
	
	
	return 0;
}

void trocaInt(int *a,int *b){
	printf("Antes da troca a = %d\tb = %d",*a,*b);
	int t = *a;
	*a = *b;
	*b = t;
	printf("\nAntes da troca a = %d\tb = %d",*a,*b);
}

void trocaObj(Pessoa *p1, Pessoa*p2){
	
	char nome1[50];
	char nome2[50];
	printf("Nome pessoa 1: ");
	scanf("%49s",nome1);
	printf("Nome pessoa 2: ");
	scanf("%49s",nome2);
	strcpy(p1->nome,nome1);
	strcpy(p2->nome,nome2);
	
	Pessoa troca;
	printf("\nAntes da Troca:     Nome 1: %s \t\tNome 2: %s", p1->nome, p2->nome);
	strcpy(troca.nome,p1->nome);
	*p1 = *p2;
	*p2 = troca;
}




