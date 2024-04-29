#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char nome[50];
    struct no *proximo;
} No;

No* criar(No *node) {
    No *novo = (No*)malloc(sizeof(No)); // Aloca mem�ria dinamicamente para o novo n�
    
    if (novo == NULL) {
        printf("Erro: N�o foi poss�vel alocar mem�ria.\n");
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
    // Verifica se o n� � nulo
    if (node == NULL) {
        return NULL;
    }
    
    No *proximo = node->proximo; // Salva o pr�ximo n�
    
    free(node); // Libera a mem�ria do n� atual
    
    return proximo; // Retorna o pr�ximo n�, que agora ser� o novo primeiro n� da lista (ou NULL, se n�o houver pr�ximo n�)
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
