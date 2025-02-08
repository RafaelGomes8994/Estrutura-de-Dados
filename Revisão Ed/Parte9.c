#include <stdio.h>
#include <stdlib.h>

/*Nó Cabeça em Listas Duplamente Encadeadas  
          
Em uma lista duplamente encadeada com nó cabeça, o nó cabeça aponta para o primeiro e o último nó da lista. Isso facilita operações como inserção no início e no fim, além de permitir navegação em ambas as direções.

Questões:  
1. Implemente uma lista duplamente encadeada com nó cabeça e crie funções para inserir no início e no fim.
2. Escreva uma função que imprima os elementos de uma lista duplamente encadeada com nó cabeça em ordem reversa.
3. Crie uma função que remova um nó com um valor específico de uma lista duplamente encadeada com nó cabeça.
4. Implemente uma função que insira um nó em uma posição específica de uma lista duplamente encadeada com nó cabeça.
5. Escreva um programa que simule uma lista de tarefas usando uma lista duplamente encadeada com nó cabeça.*/

//1. Implemente uma lista duplamente encadeada com nó cabeça e crie funções para inserir no início e no fim.

typedef struct No {
    int valor;
    struct No *prox;
    struct No *ant;
} No;

typedef struct {
    No *cabeca;
} ListaDupla;

void inicializaLista(ListaDupla *lista){
    lista->cabeca = (No*)malloc(sizeof(No));
    lista->cabeca->prox = lista->cabeca;
    lista->cabeca->ant = lista->cabeca;
}

void insereInicio(ListaDupla *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = lista->cabeca->prox;
    novo->ant = lista->cabeca;
    lista->cabeca->prox->ant = novo;
    lista->cabeca->prox = novo;
}

void insereFim(ListaDupla *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = lista->cabeca;
    novo->ant = lista->cabeca->ant;
    lista->cabeca->ant->prox = novo;
    lista->cabeca->ant = novo;
}

//2. Escreva uma função que imprima os elementos de uma lista duplamente encadeada com nó cabeça em ordem reversa.

void imprimeReverso(ListaDupla *lista){
    No *atual = lista->cabeca->ant;
    while(atual != lista->cabeca){
        printf("%d ", atual->valor);
        atual = atual->ant;
    }
    printf("\n");
}

//3. Crie uma função que remova um nó com um valor específico de uma lista duplamente encadeada com nó cabeça.

void removeValor(ListaDupla *lista, int valor){
    No *atual = lista->cabeca->prox;
    while(atual != lista->cabeca){
        if(atual->valor == valor){
            atual->ant->prox = atual->prox;
            atual->prox->ant = atual->ant;
            free(atual);
            return;
        }
        atual = atual->prox;
    }
}

//4. Implemente uma função que insira um nó em uma posição específica de uma lista duplamente encadeada com nó cabeça.

void inserePosicao(ListaDupla *lista, int valor, int posicao){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    No *atual = lista->cabeca;
    for(int i = 0; i < posicao; i++){
        if(atual->prox == lista->cabeca){
            printf("Posição inválida!\n");
            free(novo);
            return;
        }
        atual = atual->prox;
    }
    novo->prox = atual->prox;
    novo->ant = atual;
    atual->prox->ant = novo;
    atual->prox = novo;
}

//5. Escreva um programa que simule uma lista de tarefas usando uma lista duplamente encadeada com nó cabeça.

int main(){
    ListaDupla lista;
    inicializaLista(&lista);
    insereInicio(&lista, 1);
    insereFim(&lista, 2);
    insereInicio(&lista, 3);
    insereFim(&lista, 4);
    imprimeReverso(&lista);
    removeValor(&lista, 2);
    imprimeReverso(&lista);
    inserePosicao(&lista, 5, 2);
    imprimeReverso(&lista);
    return 0;
}

