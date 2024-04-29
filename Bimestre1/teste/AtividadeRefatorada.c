#include <stdio.h>
#include <stdlib.h>


typedef struct no_pilha {
    char letra;
    struct no_pilha *proximo;
} No;


typedef struct {
    No *topo; 
} Pilha;


void inserir_topo(Pilha *pilha , char letra) {
    No *novo = malloc(sizeof(No));
    
    novo->letra = letra;
    
	novo->proximo = pilha->topo;

	pilha->topo = novo;
	
}

void verificar_sequenciaGenetica(Pilha *pilha){
	Pilha *aux = pilha;
	
	while(aux != NULL){
		char motivoGenetico[2];
		
		motivoGenetico[0] = aux->topo->letra;
		motivoGenetico[1] = aux->topo->proximo->letra;
		motivoGenetico[2] = aux->topo->proximo->proximo->letra;
		
		printf("%c%c%c\n" ,motivoGenetico[0],motivoGenetico[1],motivoGenetico[2] );
		
		aux->topo = aux->topo->proximo;
	}
	
}

void imprimir_pilha(Pilha *pilha){
  Pilha *aux = pilha;
  while(aux != NULL){
    printf("%c ", aux->topo->letra);
    aux->topo = aux->topo->proximo;
  }
}

int main(void) {
    Pilha pilha; 
    pilha.topo = NULL; 
    
    char sequencia_genetica[20] = {'G', 'A', 'U', 'U', 'C', 'G', 'A', 'U', 'U', 'A', 'C', 'G', 'U', 'A', 'U', 'C', 'G', 'A', 'U', 'U'};
  	
  	int a ; // responsavel por iterar na hora de fazer a pilha
	for(a = sizeof(sequencia_genetica) / sizeof(char) ; a >= 0 ; a-- ){
    	inserir_topo(&pilha , sequencia_genetica[a]);
    }	
    
    imprimir_pilha(&pilha);
    
    verificar_sequenciaGenetica(&pilha);

    return 0;
}

