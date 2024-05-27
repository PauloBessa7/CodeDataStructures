#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do nó
typedef struct No {
    int valor;
    struct No *esquerda, *direita;
} No;

// Função para criar um novo nó
No* novoNo(int valor);


// Função para inserir um novo nó na árvore
No* inserir_v1(No* raiz, int valor);


// Função para buscar um nó na árvore
No* buscar(No* raiz, int valor);


// Função para encontrar o nó com o valor mínimo
No* minValorNo(No* no);


// Função para remover um nó da árvore
No* remover(No* raiz, int valor);


// Função de impressão em pré-ordem
void imprimirPreOrdem(No* raiz);


// Função de impressão em ordem
void imprimirEmOrdem(No* raiz);


// Função de impressão em pós-ordem
void imprimirPosOrdem(No* raiz);

// Função de imrpessão pre-ordem
//int b = a;
//		
//		for(a ; a > 0 ; a--){
//			printf("\t");
//		}
//        printf("%d ", raiz->valor);
//        
//        printf("\n");
//
//        imprimirPreOrdem2(raiz->esquerda, b++);
//        
//        imprimirPreOrdem2(raiz->direita, b--);


//	if (raiz != NULL) {
//		printf("%d ",raiz->valor);
//		
//		imprimirPreOrdem2(raiz->esquerda, a++);
//        imprimirPreOrdem2(raiz->direita, a);
//        
//    }

void imprimirPreOrdem2(No* raiz, int a){
	if (raiz != NULL) {
		int b = a;
		
		for(a ; a > 0 ; a--){
			printf("\t");
		}
        printf("%d ", raiz->valor);
        
        printf("\n");

        imprimirPreOrdem2(raiz->esquerda, b++);
        
        imprimirPreOrdem2(raiz->direita, b--);
    }  
    
}
void imprimirPreOrdem3(No* raiz, int a){
	if (raiz != NULL) {
		imprimirPreOrdem3(raiz->direita, a++);
		printf("%d ",raiz->valor);  
    }  
}

char* imprimir(No* raiz, char* a) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        
        // Converter o valor do nó para uma string e concatenar
        char buffer[12]; // Buffer para armazenar o valor convertido
        sprintf(buffer, "%d ", raiz->valor);
        strcat(a, buffer);
        
        // Atualizar o ponteiro 'a' após a concatenação
        a += strlen(buffer);
        
        // Chamar recursivamente para os filhos esquerdo e direito
        a = imprimir(raiz->esquerda, a);
        a = imprimir(raiz->direita, a);
    }
    return a;
}


int main() {
    No* arv = NULL;
    int a = 1;
    int i = 0;
    char resultado[1000] = "";
    int valores[] = {4, 2, 6, 7, 5, 1, 3};
    //, 8, 9, 10, 11, 12

    for (i = 0; i < sizeof(valores) / sizeof(valores[0]); i++) {
        arv = inserir_v1(arv, valores[i]);
    }

    printf("Impressao em pre-ordem: ");
    imprimirPreOrdem(arv);
    printf("\n");

    printf("Impressao em ordem: ");
    imprimirEmOrdem(arv);
    printf("\n");

    printf("Impressao em pos-ordem: ");
    imprimirPosOrdem(arv);
    printf("\n");

    // Teste de busca
    int valorParaBuscar = 400;
    No* buscado = buscar(arv, valorParaBuscar);
    if (buscado != NULL) {
        printf("Valor %d encontrado na arvore.\n", valorParaBuscar);
    } else {
        printf("Valor %d nao encontrado na arvore.\n", valorParaBuscar);
    }

    // Teste de remoção
    int valorParaRemover = 9;
    arv = remover(arv, valorParaRemover);
    printf("arvore apos remocao do valor %d: \n", valorParaRemover);
    imprimirEmOrdem(arv);
    printf("\n");
    
	printf("\n\n=======================\n\n");
	
	imprimirPreOrdem2(arv, a);

	
	
	
//	
//	imprimirPreOrdem2(arv, a);
//	
//	printf("\n\n=======================\n\n");
//	
//	imprimir(arv,resultado);
//	printf("\n\n=======================\n\n");
//	
//	printf("\nString resultante: %s\n", resultado);
//	
    return 0;
}

void imprimirPreOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        imprimirPreOrdem(raiz->esquerda);
        imprimirPreOrdem(raiz->direita);
    }
}

No* remover(No* raiz, int valor) {
    if (raiz == NULL) {
        return raiz;
    }
    if (valor < raiz->valor) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = remover(raiz->direita, valor);
    } else {
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        No* temp = minValorNo(raiz->direita);
        raiz->valor = temp->valor;
        raiz->direita = remover(raiz->direita, temp->valor);
    }
    return raiz;
}

No* minValorNo(No* no) {
    No* atual = no;
    while (atual && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    }
    if (valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);
    }
    return buscar(raiz->direita, valor);
}

No* inserir_v1(No* raiz, int valor) {
    if (raiz == NULL) {
        return novoNo(valor);
    }
    if (valor < raiz->valor) {
        raiz->esquerda = inserir_v1(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir_v1(raiz->direita, valor);
    }
    return raiz;
}
No* novoNo(int valor) {
    No* no = (No*)malloc(sizeof(No));
    no->valor = valor;
    no->esquerda = no->direita = NULL;
    return no;
}

void imprimirPosOrdem(No* raiz) {
    if (raiz != NULL) {
        imprimirPosOrdem(raiz->esquerda);
        imprimirPosOrdem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

void imprimirEmOrdem(No* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimirEmOrdem(raiz->direita);
    }
}

