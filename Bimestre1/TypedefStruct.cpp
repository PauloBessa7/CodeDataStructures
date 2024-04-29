#include <stdio.h>

typedef struct{
	int dia, mes , ano;
}Data;
    			 
void imprimir

(Data *x){
//	printf("%d",x.dia);
//	printf("%d",x.mes); --> método errado 
//	printf("%d",x.ano);

	printf("%d   %d   %d",x->dia,x->mes,x->ano);
	// seria o mesmo que printf("%d   %d   %d",x.(*dia),x.(*mes),x.(*ano)); ou quase isso	
}


int main(){
	
	Data data;
	Data *p;
	
	p = &data;
	
	data.dia = 7;
	data.mes = 2;
	data.ano = 2023;
	
	printf("Endereco de data: %p\tConteudo de p: %p\n",&data,p);
	
	imprimir(p);
	
	//ponteiro para ponteiro para ponteiro .......
	
	return 0;
	
}
