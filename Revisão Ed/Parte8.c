#include <stdio.h> 
#include <stdlib.h>

/*Nó Cabeça em Listas Circulares  
          
Em uma lista circular com nó cabeça, o último nó aponta de volta para o nó cabeça, formando um ciclo. O nó cabeça facilita a manipulação da lista, especialmente em operações de inserção e remoção.

Questões:  
1. Implemente uma lista circular com nó cabeça e crie funções para inserir no início e no fim.
2. Escreva uma função que imprima todos os elementos de uma lista circular com nó cabeça.
3. Crie uma função que remova um nó com um valor específico de uma lista circular com nó cabeça.
4. Implemente uma função que verifique se uma lista circular com nó cabeça está vazia.
5. Escreva um programa que simule um buffer circular usando uma lista circular com nó cabeça.*/

//1. Implemente uma lista circular com nó cabeça e crie funções para inserir no início e no fim.

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct {
    No *cabeca;
} ListaCircular;

void inicializaLista(ListaCircular *lista){
    lista->cabeca = (No*)malloc(sizeof(No));
    lista->cabeca->prox = lista->cabeca;
}

void insereInicio(ListaCircular *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = lista->cabeca->prox;
    lista->cabeca->prox = novo;
}

void insereFim(ListaCircular *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = lista->cabeca;
    No *atual = lista->cabeca;
    while(atual->prox != lista->cabeca){
        atual = atual->prox;
    }
    atual->prox = novo;
}

//2. Escreva uma função que imprima todos os elementos de uma lista circular com nó cabeça.

void imprimeLista(ListaCircular *lista){
    No *atual = lista->cabeca->prox;
    while(atual != lista->cabeca){
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

//3. Crie uma função que remova um nó com um valor específico de uma lista circular com nó cabeça.

void removeElemento(ListaCircular *lista, int valor){
    No *anterior = lista->cabeca;
    No *atual = lista->cabeca->prox;
    while(atual != lista->cabeca){
        if(atual->valor == valor){
            anterior->prox = atual->prox;
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}

//4. Implemente uma função que verifique se uma lista circular com nó cabeça está vazia.

int estaVazia(ListaCircular *lista){
    return lista->cabeca->prox == lista->cabeca;
}

//5. Escreva um programa que simule um buffer circular usando uma lista circular com nó cabeça.

int main(){
    ListaCircular buffer;
    inicializaLista(&buffer);
    int valor;
    do {
        printf("Digite um valor (0 para sair): ");
        scanf("%d", &valor);
        if(valor != 0){
            insereFim(&buffer, valor);
        }
    } while(valor != 0);
    imprimeLista(&buffer);
    do {
        printf("Digite um valor para remover (0 para sair): ");
        scanf("%d", &valor);
        if(valor != 0){
            removeElemento(&buffer, valor);
            imprimeLista(&buffer);
        }
    } while(valor != 0);
    return 0;
}


