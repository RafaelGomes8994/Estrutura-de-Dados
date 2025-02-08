#include <stdio.h>
#include <stdlib.h>

/*Nó Cabeça em Listas Encadeadas  
          
O nó cabeça é um nó fictício que sempre aponta para o primeiro elemento da lista. Ele não armazena dados úteis, mas facilita a manipulação da lista, evitando casos especiais (como listas vazias ou inserções no início).

Questões:  
1. Implemente uma lista simplesmente encadeada com nó cabeça e crie funções para inserir no início e no fim.
2. Escreva uma função que imprima todos os elementos de uma lista com nó cabeça.
3. Crie uma função que remova um nó com um valor específico de uma lista com nó cabeça.
4. Implemente uma função que inverta a ordem dos nós em uma lista com nó cabeça.
5. Escreva um programa que leia números do usuário e os insira em uma lista com nó cabeça até que o usuário digite 0.*/

//1. Implemente uma lista simplesmente encadeada com nó cabeça e crie funções para inserir no início e no fim.

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct {
    No *cabeca;
} ListaEncadeada;

void inicializaLista(ListaEncadeada *lista){
    lista->cabeca = (No*)malloc(sizeof(No));
    lista->cabeca->prox = NULL;
}

void insereInicio(ListaEncadeada *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = lista->cabeca->prox;
    lista->cabeca->prox = novo;
}

void insereFim(ListaEncadeada *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    No *atual = lista->cabeca;
    while(atual->prox != NULL){
        atual = atual->prox;
    }
    atual->prox = novo;
}

//2. Escreva uma função que imprima todos os elementos de uma lista com nó cabeça.

void imprimeLista(ListaEncadeada *lista){
    No *atual = lista->cabeca->prox;
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

//3. Crie uma função que remova um nó com um valor específico de uma lista com nó cabeça.

void removeElemento(ListaEncadeada *lista, int valor){
    No *anterior = lista->cabeca;
    No *atual = lista->cabeca->prox;
    while(atual != NULL){
        if(atual->valor == valor){
            anterior->prox = atual->prox;
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}

//4. Implemente uma função que inverta a ordem dos nós em uma lista com nó cabeça.

void inverteLista(ListaEncadeada *lista){
    No *anterior = NULL;
    No *atual = lista->cabeca->prox;
    No *proximo;
    while(atual != NULL){
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }
    lista->cabeca->prox = anterior;
}

//5. Escreva um programa que leia números do usuário e os insira em uma lista com nó cabeça até que o usuário digite 0.

int main(){
    ListaEncadeada lista;
    inicializaLista(&lista);
    int valor;
    do {
        scanf("%d", &valor);
        if(valor != 0){
            insereFim(&lista, valor);
        }
    } while(valor != 0);
    imprimeLista(&lista);
    return 0;
}



