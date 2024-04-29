#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
	
	char **Matnomes;
	int *notas;
	int i = 0; 
	

	Matnomes = malloc(3 * sizeof(char *));
	
	notas = malloc(3 * sizeof(int *));
	
	for( i ; i < 3 ; i++){
		Matnomes[i] = malloc(50 * sizeof(char));  
	}
	
	i = 0;
	for( i ; i < 3 ; i++){
		printf("\nNome e nota%d: ",(i+1));  
		scanf("%s%d",&Matnomes[i],&notas[i]);
	}

	
	
	
	
	
	return 0;
}
