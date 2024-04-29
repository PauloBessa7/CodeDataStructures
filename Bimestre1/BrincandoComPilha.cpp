#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int **mat,*vet;
	int sum = 1;
	mat = (int **)malloc( 5 * sizeof(int *));
	for(int a = 0; a < 5 ; a++){
		*(mat + a) = (int *)malloc( 5 * sizeof(int));
		for(int b = 0 ; b < 5 ; b++){
			*(*(mat + a)+b) = sum;
			sum += 1;
			printf("%d\t ",mat[a][b]);
		}
		printf("\n");
	}
	
	for(int a = 0 ; a < 5 ; a++){
		
	}
	
	return 0;
}
