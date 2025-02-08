#include <stdio.h>
#include <stdlib.h>

/*Uma lista simplesmente encadeada é uma estrutura de dados dinâmica onde cada elemento (nó) contém um valor e um ponteiro para o próximo nó. A inserção e remoção são mais eficientes que em vetores, mas o acesso é sequencial.

Questões:
1. Implemente uma lista simplesmente encadeada e crie funções para inserir no início, no fim e em uma posição específica.
2. Escreva uma função que imprima todos os elementos de uma lista encadeada.
3. Crie uma função que remova um nó com um valor específico da lista.
4. Implemente uma função que inverta a ordem dos nós em uma lista encadeada.
5. Escreva um programa que leia números do usuário e os insira em uma lista encadeada até que o usuário digite 0. */

//1. Implemente uma lista simplesmente encadeada e crie funções para inserir no início, no fim e em uma posição específica.

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} ListaEncadeada;

void inicializaLista(ListaEncadeada *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
}

void insereInicio(ListaEncadeada *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;
    if(lista->fim == NULL){
        lista->fim = novo;
    }
}

void insereFim(ListaEncadeada *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    if(lista->fim != NULL){
        lista->fim->prox = novo;
    }
    lista->fim = novo;
    if(lista->inicio == NULL){
        lista->inicio = novo;
    }
}

void inserePosicao(ListaEncadeada *lista, int valor, int posicao){
    if(posicao < 0){
        printf("Posição inválida!\n");
        return;
    }
    if(posicao == 0){
        insereInicio(lista, valor);
    } else {
        No *atual = lista->inicio;
        for(int i=0; i<posicao-1; i++){
            if(atual == NULL){
                printf("Posição inválida!\n");
                return;
            }
            atual = atual->prox;
        }
        if(atual == NULL){
            printf("Posição inválida!\n");
            return;
        }
        No *novo = (No*)malloc(sizeof(No));
        novo->valor = valor;
        novo->prox = atual->prox;
        atual->prox = novo;
        if(atual == lista->fim){
            lista->fim = novo;
        }
    }
}

//2. Escreva uma função que imprima todos os elementos de uma lista encadeada.

void imprimeLista(ListaEncadeada *lista){
    No *atual = lista->inicio;
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

//3. Crie uma função que remova um nó com um valor específico da lista.

void removeElemento(ListaEncadeada *lista, int valor){
    No *anterior = NULL;
    No *atual = lista->inicio;
    while(atual != NULL){
        if(atual->valor == valor){
            if(anterior == NULL){
                lista->inicio = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            if(atual == lista->fim){
                lista->fim = anterior;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}

//4. Implemente uma função que inverta a ordem dos nós em uma lista encadeada.

void inverteLista(ListaEncadeada *lista){
    No *anterior = NULL;
    No *atual = lista->inicio;
    No *proximo;
    lista->fim = lista->inicio;
    while(atual != NULL){
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }
    lista->inicio = anterior;
}

//5. Escreva um programa que leia números do usuário e os insira em uma lista encadeada até que o usuário digite 0.

int main(){
    ListaEncadeada lista;
    inicializaLista(&lista);
    int num;
    do {
        printf("Digite um número (0 para sair): ");
        scanf("%d", &num);
        if(num != 0){
            insereFim(&lista, num);
        }
    } while(num != 0);
    printf("Lista: ");
    imprimeLista(&lista);
    return 0;
}



