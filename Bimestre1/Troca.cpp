#include <stdio.h>
void troca(int *a, int*b){
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
	printf("\n\nPosiacao a : %p\tPosiacao b : %p\tPosiacao aux : %p\t(fazendo a troca)",&a,&aux,&b);
}

int main(void){
	int a = 10;
	int b =7;
	printf("%d -> %d",a,b);
	printf("\n\nPosiacao a : %p\tPosiacao b : %p\t(antes da troca)",&a,&b);
	troca(&a,&b);
	printf("\n\nPosiacao a : %p\tPosiacao b : %p\t(depois da troca)",&a,&b);
	printf("\n%d -> %d",a,b);
	
	
	
	return 0;
}
