#include <stdio.h>
#include <stdlib.h>
int main(void){
	
	int **mat, i ,j ;
	
	mat = (int **)malloc(5 * sizeof(int *));
	i = 0;
	j = 0;
	
	for( j = 0; j < 5 ; j++){
		mat[j] = (int *)malloc( 5 * sizeof(int ));
		for(i = 0; i < 5 ; i++){
			mat[j][i]= i + j;
		}
	}
	
//	for (j = 0; j < 5; j++) {
//        mat[j] = (int *)malloc(5 * sizeof(int));
//        for (i = 0; i < 5; i++) {
//            mat[j][i] = i + j;
//        }
//    }
	
	i = 0;
	j = 0;
	
	for( j = 0 ; j < 5 ; j++){
		
		for(i = 0; i < 5 ; i++){
			printf("%d ",mat[j][i]);
		}
		
		printf("\n");
	}
	
	return 0;
}
