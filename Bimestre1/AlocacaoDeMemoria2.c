#include <stdio.h>
#include <stdlib.h>



//comando free para liberar memoria
int main(void){
	
	int i , tam , *vet;
	
	printf("Informe o tamalho de memoria: ");
	scanf("%d",&tam);
	srand(time(NULL));
	
	vet = (int *)malloc(tam * sizeof(int));
	
	
		if(vet){
		printf("Memoria alocada com sucesso");
		printf("\n\n\n");
		for(i = 0; i< tam ; i++){
			*(vet + i) = rand() % 100;
			printf("%d --> ",*(vet + i));
		}
		printf("\n\n\n");
		printf("\n%p , %d ", vet, tam);
		
		
		//vet = (int *)realloc(vet,tam);
		
		//printf("\n%p , %d ", vet, tam);
		
		
		free(vet);
	}else{
		printf("Erro em alocar memoria");
	}
	
	printf("\n\n\n");
	for(i = 0 ; i < tam ; i++){
		printf("%d --> ", *(vet + i));
	}
//	
//	printf("\n\n\n");
//	
//	free(vet);
//		for(i = 0 ; i < tam ; i++){
//		printf("%d --> ", *(vet + i));
//	}
	
	
	return 0;
	
}
