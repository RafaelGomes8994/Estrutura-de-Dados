#include <stdlib.h>
#include <stdio.h>
//b) Implemente uma função em C que insira um elemento em uma lista simplesmente encadeada, mantendo a ordem crescente dos valores.
typedef struct No{
    int valor;
    struct No *prox;
}No;

void insereElemento(No *inicio, int valor){ // função que insere um elemento na lista
    No *novo = (No*)malloc(sizeof(No)); // aloca um novo nó
    novo -> valor = valor; // pega o valor que quer inserir
    if (inicio == NULL){ // se a lista estiver vazia
        inicio = novo; // o inicio recebe o novo
    }else if (valor < inicio -> valor){ // se o valor for menor que o inicio
        novo -> prox = inicio; // o proximo do novo recebe o inicio
        inicio = novo; // o inicio recebe o novo
    }else{ // se não
        No *atual = inicio; // cria um ponteiro para o inicio
        while (atual -> prox != NULL && atual -> prox -> valor < valor){ // enquanto o proximo do atual for diferente de NULL e o valor do proximo do atual for menor que o valor
            atual = atual -> prox; // o atual recebe o proximo
        }
        novo -> prox = atual -> prox; // o proximo do novo recebe o proximo do atual
        atual -> prox = novo; // o proximo do atual recebe o novo
    } 
}

// c) Escreva uma função para inverter uma lista simplesmente encadeada sem criar uma nova lista.

void inverteLista(No *inicio){ // função que inverte a lista
    No *anterior = NULL; // cria um ponteiro para o nó anterior
    No *atual = inicio; // cria um ponteiro para o inicio
    No *proximo = NULL; // cria um ponteiro para o proximo
    while (atual != NULL){ // enquanto o atual for diferente de NULL
        proximo = atual -> prox; // o proximo recebe o proximo do atual
        atual -> prox = anterior; // o proximo do atual recebe o anterior
        anterior = atual; // o anterior recebe o atual
        atual = proximo; // o atual recebe o proximo
    }
    inicio = anterior; // o inicio recebe o anterior
}

