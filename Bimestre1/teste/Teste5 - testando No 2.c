#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char nome[50];
    struct no *proximo;
} No;

No* criar(No *node) {
    No *novo = (No*)malloc(sizeof(No)); // Aloca memória dinamicamente para o novo nó
    
    if (novo == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        exit(1);
    }
    
    printf("\nNome: ");
    char nomee[50];
    scanf("%49s", nomee);
    strcpy(novo->nome, nomee);
    
    novo->proximo = node;
    
    return novo;
}

No* remover(No *node) {
    // Verifica se o nó é nulo
    if (node == NULL) {
        return NULL;
    }
    
    No *proximo = node->proximo; // Salva o próximo nó
    
    free(node); // Libera a memória do nó atual
    
    return proximo; // Retorna o próximo nó, que agora será o novo primeiro nó da lista (ou NULL, se não houver próximo nó)
}

int main(void) {
    No *topo = NULL;
    printf("Posicao de memoria de topo : %p", topo);
    topo = criar(topo);
    printf("Posicao de memoria de topo : %p", topo);
    topo = criar(topo);
    printf("Posicao de memoria de topo : %p", topo);
    topo = criar(topo);
    printf("Posicao de memoria de topo : %p", topo);

    if (topo != NULL) {
        printf("\nNome do node : %s", topo->nome);
        topo = remover(topo);
        printf("\nNome do node : %s", topo->nome);
        topo = remover(topo);
        printf("\nNome do node : %s", topo->nome);
        topo = remover(topo);
        printf("\nNome do node : %s", topo->nome);
    }
    
    return 0;
}
