#include <stdio.h>

int main(void){
	
	int i,vet[5] = {0,1,2,3,4};
	
	for(i=0 ; i<5; i++){
		printf("Endereco : %p \tValor : %d\n", vet + i, *(vet + i));
	}
	
//	Um vetor sempre vai ser um ponteiro
//	%p , vet -> ele aponta o conteudo que esta em vet ( seria igual a &vet[0])
//	%d , *vet -> vai me apontar o conteudo que aquela posicao de memoria da variavel vet aponta (seria igual a vet[0])
//	%p , vet + i -> ele aponta o conteudo que esta em vet ( seria igual a &vet[i])
//	%d , *vet + i-> vai me apontar o conteudo que aquela posicao de memoria da variavel vet aponta (seria igual a vet[i])
	return 0;
}
