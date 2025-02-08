#include <stdio.h>
#include <stdlib.h>

/*Lista Circular 
        
Uma lista circular é uma variação da lista encadeada onde o último nó aponta de volta para o primeiro, formando um ciclo. Isso é útil em aplicações como buffers circulares.

Questões:
1. Implemente uma lista circular e crie funções para inserir no início e no fim.
2. Escreva uma função que imprima todos os elementos de uma lista circular.
3. Crie uma função que remova um nó com um valor específico de uma lista circular.
4. Implemente uma função que verifique se uma lista encadeada é circular.
5. Escreva um programa que simule um buffer circular usando uma lista circular.*/

//1. Implemente uma lista circular e crie funções para inserir no início e no fim.

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
} ListaCircular;

void inicializaLista(ListaCircular *lista){
    lista->inicio = NULL;
}

void insereInicio(ListaCircular *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    if(lista->inicio == NULL){
        novo->prox = novo;
    } else {
        novo->prox = lista->inicio;
        No *atual = lista->inicio;
        while(atual->prox != lista->inicio){
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    lista->inicio = novo;
}

void insereFim(ListaCircular *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    if(lista->inicio == NULL){
        novo->prox = novo;
        lista->inicio = novo;
    } else {
        novo->prox = lista->inicio;
        No *atual = lista->inicio;
        while(atual->prox != lista->inicio){
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

//2. Escreva uma função que imprima todos os elementos de uma lista circular.

void imprimeLista(ListaCircular *lista){
    if(lista->inicio == NULL){
        return;
    }
    No *atual = lista->inicio;
    do {
        printf("%d ", atual->valor);
        atual = atual->prox;
    } while(atual != lista->inicio);
    printf("\n");
}

//3. Crie uma função que remova um nó com um valor específico de uma lista circular.

void removeValor(ListaCircular *lista, int valor){
    if(lista->inicio == NULL){
        return;
    }
    No *anterior = NULL;
    No *atual = lista->inicio;
    do {
        if(atual->valor == valor){
            if(anterior == NULL){
                if(atual->prox == atual){
                    lista->inicio = NULL;
                } else {
                    No *ultimo = atual;
                    while(ultimo->prox != atual){
                        ultimo = ultimo->prox;
                    }
                    lista->inicio = atual->prox;
                    ultimo->prox = atual->prox;
                }
                free(atual);
                return;
            } else {
                anterior->prox = atual->prox;
                free(atual);
                return;
            }
        }
        anterior = atual;
        atual = atual->prox;
    } while(atual != lista->inicio);
}

//4. Implemente uma função que verifique se uma lista encadeada é circular.

int ehCircular(ListaCircular *lista){
    if(lista->inicio == NULL){
        return 0;
    }
    No *atual = lista->inicio;
    do {
        atual = atual->prox;
    } while(atual != lista->inicio && atual != NULL);
    return atual == lista->inicio;
}

//5. Escreva um programa que simule um buffer circular usando uma lista circular.

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
    return 0;
}
