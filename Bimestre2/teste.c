#include <stdio.h>
#include <stdlib.h>

// Estrutura do n� da �rvore
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// Estrutura de um n� da fila
typedef struct FilaNo {
    No* no;
    struct FilaNo* prox;
} FilaNo;

// Estrutura da fila
typedef struct {
    FilaNo* frente;
    FilaNo* tras;
} Fila;

// Fun��o para criar um novo n� da �rvore
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Fun��o para inicializar a fila
Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->frente = NULL;
    fila->tras = NULL;
    return fila;
}

// Fun��o para verificar se a fila est� vazia
int filaVazia(Fila* fila) {
    return (fila->frente == NULL);
}

// Fun��o para enfileirar um n�
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

// Fun��o para desenfileirar um n�
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

// Fun��o para imprimir os n�s da �rvore em sequ�ncia por n�vel
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

// Fun��o principal para demonstrar o algoritmo
int main() {
    // Exemplo de inicializa��o de uma �rvore bin�ria
    No* raiz = criarNo(4);
    raiz->esquerda = criarNo(2);
    raiz->direita = criarNo(3);
    raiz->esquerda->esquerda = criarNo(4);
    raiz->esquerda->direita = criarNo(5);
    raiz->direita->esquerda = criarNo(6);
    raiz->direita->direita = criarNo(7);

    // Imprimir a �rvore por n�vel
    imprimirPorNivel(raiz);

    return 0;
}

