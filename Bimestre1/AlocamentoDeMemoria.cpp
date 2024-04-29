#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
	int i , tam , *vet;
	
	printf("Informe o tamalho de memoria: ");
	scanf("%d",&tam);
	srand(time(NULL));
	
	vet = (int *)malloc(tam * sizeof(int));
	
	
	if(vet){
		printf("Memoria alocada com sucesso");
		
		for(i = 0; i< tam ; i++){
			*(vet + i) = rand() % 100;
		}
		
		printf("\n%p , %d ", vet, tam);
		
		
		//vet = (int *)realloc(vet,tam);
		
		//printf("\n%p , %d ", vet, tam);
		
	}else{
		printf("Erro em alocar memoria");
	}
	printf("\n\n\n");
	for(i = 0 ; i < tam ; i++){
		printf("%d --> ", *(vet + i));
	}
	
	//nao sie
//	alocar um vetor em tempo de execução malloc
//	vet = malloc (tam * sizeof(int));
// srand(time(null))
	
	
	
	return 0;
}
