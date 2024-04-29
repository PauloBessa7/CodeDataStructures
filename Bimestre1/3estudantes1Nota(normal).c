#include <stdio.h>

int main(void){
	
	char nomes[3][10];
	int notas[3];
	int i =0;
	
	for(i;i<3;i++){
		printf("Digite o nome e nota do estudante: ");
		scanf("%s%d",&nomes[i],&notas[i]);
	}
	i = 0;
	for(i;i<3;i++){
		printf("\n%s\t%d",nomes[i],notas[i]);
	}
	
	
	
	

	
	
	return 0;
}
