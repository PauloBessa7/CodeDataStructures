#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int a ;
	struct no *node;	
}No;

int main(void){
	No no1;
	no1.a = 10;
	No no2;
	No no3;
	
	no1.node = &no2;
	no2.a = 20;
	no2.node = &no3;
	no3.a = 30;
	
	printf("O node %p aponta para o node %p\nO node %p aponta para o node %p\nO node %p aponta para o node %p\n",&no1,&no2,&no2,&no3,&no3,no3.node);
	
	return 0;
}
