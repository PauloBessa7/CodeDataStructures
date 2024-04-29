#include <stdio.h>
#include <stdlib.h>

void maiorMenor(int *maior , int *menor,int tam, int *vet){
	*maior = *vet;
	*menor = *vet;
	
	for(int a = 1 ; a < tam ; a++){
		if(*menor > *(vet + a)){
			*menor = *(vet + a);
		}
		if(*maior < *(vet + a)){
			*maior = *(vet + a);
		}	
	}	
}



int main(void){
	int menor, maior, v[10] = {45, 89, 10 , 15 , 72, 7, 81, 90, 8, 4};
	
	printf("Menor: %d\tMaior: %d\n",menor,maior);
	maiorMenor(&maior, &menor,10,v);
	
	printf("Menor: %d\tMaior: %d\n",menor,maior);
	
	
	
	return 0;
}
