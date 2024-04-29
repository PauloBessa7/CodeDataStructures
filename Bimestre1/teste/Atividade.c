#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char letra;
    struct No *proximo;	
} No;

typedef struct {
    No *topo;
} Pilha;

typedef struct {
    struct No *primeiro;
} Fila;

typedef struct trinca{
	char trin[4];
	struct trinca *proximo;
}Trinca;

typedef struct {
	int index;
	Trinca *proximo;
}Lista;



void inserir_topo(Pilha *pilha, char letra) { // inserir no inicio no topo da pilha
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    novo->letra = letra;
    novo->proximo = pilha->topo; 
    pilha->topo = novo;
}

void inserir_fim(Fila *fila, int num) { // inserir no fim da fila
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    novo->letra = num;
    novo->proximo = NULL;

    if (fila->primeiro == NULL) {
        fila->primeiro = novo;
    } else {
        No *aux = fila->primeiro;
        while (aux->proximo != NULL) {
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
}

void inserir_topo_lista(Lista *lista, char trinca[]) {  // in
    printf("%c", trinca[0]);
    printf("%c", trinca[1]);
    printf("%c", trinca[2]);
    printf("%c", trinca[3]);

    Trinca *novo = malloc(sizeof(Trinca));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }

    novo->trin[0] = trinca[0];
    novo->trin[1] = trinca[1];
    novo->trin[2] = trinca[2];
    novo->trin[3] = trinca[3];
    novo->proximo = lista->proximo;
    lista->index = lista->index+1;
    lista->proximo = novo;
}

void imprimir_pilha(Pilha pilha) { // imprimir os valores da pilha
    while (pilha.topo != NULL) {
        printf("%c ", pilha.topo->letra);
        pilha.topo = pilha.topo->proximo;
    }
}

void imprimir_fila(Fila fila) { // imprimir os valores da fila
    while (fila.primeiro != NULL) {
        printf("%d ", fila.primeiro->letra);
        fila.primeiro = fila.primeiro->proximo;
    }
}

void imprimir_lista(Lista lista) {
    Trinca *atual = lista.proximo; 

    while (atual != NULL) {
        printf("%s ", atual->trin); 
        atual = atual->proximo; // 
    }
    printf("\n");
}

int verificaMotivoGenetico(char trinca[]) { // verirficar se a trinca é um motivo genetico
    if (strcmp(trinca, "AAA") == 0) {
        printf("O Motivo genetico eh  Lisina -> 'AAA'\t\t");
        return 1;
    }
    
    if (strcmp(trinca, "CCU") == 0) {
        printf("O Motivo genetico eh Prolina 'CCU'\t\t");
        return 1;
    }
    
    if (strcmp(trinca, "UUU") == 0) {
        printf("O Motivo genetico eh Fenilalanina 'UUU'\t\t");
        return 1;
    }
    printf("A sequencia genetica NAO eh um motivo genetico\t");
    return 0;
}

void verificarSequencia(Pilha pilha, Fila *fila, Lista *lista) { // verificar cada posicao de trinca da pilha/sequenciaGenetica
    int posicaoTrinca = 0;
    while (pilha.topo != NULL) {
        int verifica = 0;
		char trinca[4]; // Aumentado para 4 para armazenar a trinca completa
        if (pilha.topo->proximo != NULL && pilha.topo->proximo->proximo != NULL) {
             
            trinca[0] = pilha.topo->letra;
            trinca[1] = pilha.topo->proximo->letra;
            trinca[2] = pilha.topo->proximo->proximo->letra;
            trinca[3] = '\0'; // Adicionando terminador nulo

            printf("\n%s\t", trinca);
            verifica = verificaMotivoGenetico(trinca);
        }

        if (verifica == 1) {
            pilha.topo = pilha.topo->proximo->proximo->proximo;
            printf("%d ", posicaoTrinca);
            inserir_fim(fila, posicaoTrinca);

			inserir_topo_lista(lista , trinca );

            posicaoTrinca += 3;
        } else {
            pilha.topo = pilha.topo->proximo;
            printf("%d ", posicaoTrinca);
            posicaoTrinca += 1;
        }
    }
}

int main(void) {
    Pilha pilha;
    pilha.topo = NULL;
    
    Fila fila;
    fila.primeiro = NULL;
    
    Lista lista;
    lista.proximo = NULL;
    
    
    char sequenciaGenetica[] = { // insersir valores por hardcode
        'A', 'G', 'U', 'C', 'A', 'A', 'G', 'C', 'C', 'U',
        'U', 'A', 'A', 'A', 'C', 'C', 'U', 'C', 'U', 'U',
        'U', 'A', 'A', 'A', 'C', 'C', 'G', 'U', 'U', 'U'
    };
    
    int a;
    for (a = sizeof(sequenciaGenetica) / sizeof(char) - 1; a >= 0; a--) {
        inserir_topo(&pilha, sequenciaGenetica[a]);
    }

    verificarSequencia(pilha, &fila, &lista);

    printf("\n\nPilha da sequencia genetica: \t");
    imprimir_pilha(pilha);

    printf("\n\nPosicao dos motivos geneticos: \t");
    imprimir_fila(fila);
    
    printf("\n\nLista da sequencia de motivosGeneticos: ");
    imprimir_lista(lista);
    
    
    
    return 0;
}

