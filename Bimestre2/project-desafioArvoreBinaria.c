#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* direita;
    struct no* esquerda;
} No;

void adicionar(No** arv, int valor);
No* adicionarFolha(No* arv, int valor);
void imprimir(No* arv, int espaco);
void deletar(No** no, int valor);
void imprimir_in_ordem(No* arv);
void imprimir_pre_ordem(No* arv);
void imprimir_pos_ordem(No* arv);
void atualizar(No* arv, int antigo, int novo);

int main(void) {
    No* arv = NULL;
	
    adicionar(&arv, 50);
    adicionar(&arv, 80);
    adicionar(&arv, 26);
    adicionar(&arv, 226);
    adicionar(&arv, 74);
    adicionar(&arv, 24);
    adicionar(&arv, 28);
    adicionar(&arv, 29);
    adicionar(&arv, 25);
    adicionar(&arv, 23);
    adicionar(&arv, 27);
    adicionar(&arv, 72);
    adicionar(&arv, 75);
    adicionar(&arv, 227);
    adicionar(&arv, 225);
    
    printf("\tValores adicionados : ");
    imprimir_in_ordem(arv);
    
    printf("\n\n\tA Arvore esta da seguinte maneira : \n\n");
    imprimir(arv,1);
	printf("==============================================================");
    int op, valor, novo_valor;
do {
    printf("\n\n1 - Deletar\n2 - Adicionar\n3 - Mudar numero\n4 - Imprimir arvore\n5 - Imprimir em ordem\n6 - Imprimir pre ordem\n7 - Imprimir pos ordem\n0 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &op);

    switch (op) {
        case 1:
            printf("Digite o valor a ser deletado: ");
            scanf("%d", &valor);
            deletar(&arv, valor);
            break;
        case 2:
            printf("Digite o valor a ser adicionado: ");
            scanf("%d", &valor);
            adicionar(&arv, valor);
            break;
        case 3:
            printf("Digite o valor a ser mudado: ");
            scanf("%d", &valor);
            printf("Digite o novo valor: ");
            scanf("%d", &novo_valor);
            atualizar(arv, valor, novo_valor);
            break;
        case 4:
            imprimir(arv, 0);
            break;
        case 5:
            imprimir_in_ordem(arv);
            break;
        case 6:
            imprimir_pre_ordem(arv);
            break;
        case 7:
            imprimir_pos_ordem(arv);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
    }
} while (op != 0);


    return 0;
}

void adicionar(No** arv, int valor) {
    if (*arv == NULL) {
        *arv = (No*)malloc(sizeof(No));
        (*arv)->valor = valor;
        (*arv)->direita = NULL;
        (*arv)->esquerda = NULL;
    } else if (valor < (*arv)->valor) {
        adicionar(&((*arv)->esquerda), valor);
    } else {
        adicionar(&((*arv)->direita), valor);
    }
}

No* adicionarFolha(No* arv, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->direita = NULL;
    novo->esquerda = NULL;
    return novo;
}

void imprimir(No* no, int espaco) {
    if (no == NULL)
        return;
    int a = espaco;
    espaco = espaco + 1;
    imprimir(no->direita, espaco);
    for(a; a > 0; a--) {
        printf("\t");
    }
    printf("%d\n", no->valor);
    imprimir(no->esquerda, espaco);
}

No* encontrarMinimo(No* no) {
    while (no->esquerda != NULL) no = no->esquerda;
    return no;
}

void deletar(No** arv, int valor) {
    if (*arv == NULL) return;

    if (valor < (*arv)->valor) {
        deletar(&((*arv)->esquerda), valor);
    } else if (valor > (*arv)->valor) {
        deletar(&((*arv)->direita), valor);
    } else {
        if ((*arv)->esquerda == NULL) {
            No* temp = (*arv)->direita;
            free(*arv);
            *arv = temp;
        } else if ((*arv)->direita == NULL) {
            No* temp = (*arv)->esquerda;
            free(*arv);
            *arv = temp;
        } else {
            No* temp = encontrarMinimo((*arv)->direita);
            (*arv)->valor = temp->valor;
            deletar(&((*arv)->direita), temp->valor);
        }
    }
}

void imprimir_in_ordem(No* arv) {
    if (arv != NULL) {
        imprimir_in_ordem(arv->esquerda);
        printf("%d ", arv->valor);
        imprimir_in_ordem(arv->direita);
    }
}

void imprimir_pre_ordem(No* arv) {
    if (arv != NULL) {
        printf("%d ", arv->valor);
        imprimir_pre_ordem(arv->esquerda);
        imprimir_pre_ordem(arv->direita);
    }
}

void imprimir_pos_ordem(No* arv) {
    if (arv != NULL) {
        imprimir_pos_ordem(arv->esquerda);
        imprimir_pos_ordem(arv->direita);
        printf("%d ", arv->valor);
    }
}

void atualizar(No* arv, int antigo, int novo) {
    deletar(&arv, antigo);
    adicionar(&arv, novo);
}

