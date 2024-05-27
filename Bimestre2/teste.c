#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da árvore
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// Estrutura de um nó da fila
typedef struct FilaNo {
    No* no;
    struct FilaNo* prox;
} FilaNo;

// Estrutura da fila
typedef struct {
    FilaNo* frente;
    FilaNo* tras;
} Fila;

// Função para criar um novo nó da árvore
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para inicializar a fila
Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->frente = NULL;
    fila->tras = NULL;
    return fila;
}

// Função para verificar se a fila está vazia
int filaVazia(Fila* fila) {
    return (fila->frente == NULL);
}

// Função para enfileirar um nó
void enfileirar(Fila* fila, No* no) {
    FilaNo* novoFilaNo = (FilaNo*)malloc(sizeof(FilaNo));
    novoFilaNo->no = no;
    novoFilaNo->prox = NULL;
    if (fila->tras != NULL) {
        fila->tras->prox = novoFilaNo;
    }
    fila->tras = novoFilaNo;
    if (fila->frente == NULL) {
        fila->frente = novoFilaNo;
    }
}

// Função para desenfileirar um nó
No* desenfileirar(Fila* fila) {
    if (filaVazia(fila)) {
        return NULL;
    }
    FilaNo* filaNo = fila->frente;
    No* no = filaNo->no;
    fila->frente = filaNo->prox;
    if (fila->frente == NULL) {
        fila->tras = NULL;
    }
    free(filaNo);
    return no;
}

// Função para imprimir os nós da árvore em sequência por nível
void imprimirPorNivel(No* raiz) {
    if (raiz == NULL) {
        return;
    }
    Fila* fila = criarFila();
    enfileirar(fila, raiz);
    while (!filaVazia(fila)) {
        No* atual = desenfileirar(fila);
        printf("%d ", atual->valor);
        if (atual->esquerda != NULL) {
            enfileirar(fila, atual->esquerda);
        }
        if (atual->direita != NULL) {
            enfileirar(fila, atual->direita);
        }
    }
    free(fila);
}

// Função principal para demonstrar o algoritmo
int main() {
    // Exemplo de inicialização de uma árvore binária
    No* raiz = criarNo(4);
    raiz->esquerda = criarNo(2);
    raiz->direita = criarNo(3);
    raiz->esquerda->esquerda = criarNo(4);
    raiz->esquerda->direita = criarNo(5);
    raiz->direita->esquerda = criarNo(6);
    raiz->direita->direita = criarNo(7);

    // Imprimir a árvore por nível
    imprimirPorNivel(raiz);

    return 0;
}

