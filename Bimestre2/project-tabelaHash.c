#include <stdio.h>


#define TAM 31

void inicia(int t[]){
	int a = 0;
	
	for(a = 0; a < TAM; a++){
		t[a] = 0;
	}
}

int hash(int chave){
	return chave % TAM;
}

void inserir(int valor, int t[]){
	int id = hash(valor);
	
	while(t[id] != 0){
		id = hash(id + 1);
	}
	
	t[id] = valor;
}

int busca(int chave,int t[]){
	int id = hash(chave);
	while(t[id] != 0){
		if(t[id] == chave){
			return t[id];
		}else{
			id = hash(id + 1);
		}
	}
	
	return 0;
}

void imprimir(int t[]){
	int i;
	for(i = 0 ; i < TAM; i++){
		if(t[i] != 0){
			printf("%d = %d\n",i, t[i]);
		}
	}
}

void deletar(int valor ,int t[]){
	int id = hash(valor);
	
	while(t[id] != 0){
		if(t[id] == valor){
			t[id] = 0;
		}else{
			id = hash(valor + 1);
		}
	}
}
int main(void){
	
	int tabela[31];
	
	inicia(tabela);
	
	inserir(125, tabela);
	inserir(125, tabela);
	inserir(54, tabela);
	inserir(3011, tabela);
	inserir(253, tabela);
	inserir(182, tabela);
	inserir(407, tabela);
	inserir(277, tabela);
	
	imprimir(tabela);
	printf("==============================\n");
	
//	int a = busca(125, tabela);
//	printf("\n%d\n",a);
	 
	deletar(277, tabela);
	
	imprimir(tabela);
	return 0;
}
