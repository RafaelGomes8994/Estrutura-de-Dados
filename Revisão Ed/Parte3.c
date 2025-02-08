include <stdio.h>
#include <stdlib.h>
/*Listas lineares são estruturas de dados que armazenam elementos em uma sequência. Podem ser implementadas como arrays (vetores) ou listas encadeadas. As operações básicas incluem inserção, remoção e busca.

Questões:
1. Implemente uma lista linear usando um vetor e crie funções para inserir, remover e buscar elementos.
2. Escreva um programa que leia 5 números do usuário, armazene-os em uma lista linear e imprima a lista.
3. Crie uma função que receba uma lista linear e retorne o número de elementos pares.
4. Implemente uma função que inverta a ordem dos elementos em uma lista linear.
5. Escreva um programa que remova todos os elementos duplicados de uma lista linear. */

//1. Implemente uma lista linear usando um vetor e crie funções para inserir, remover e buscar elementos.

#define MAX 100

typedef struct {
    int vetor[MAX];
    int tamanho;
} ListaLinear;

void inicializaLista(ListaLinear *lista){
    lista->tamanho = 0;
}

void insereElemento(ListaLinear *lista, int elemento){
    if(lista->tamanho < MAX){
        lista->vetor[lista->tamanho] = elemento;
        lista->tamanho++;
    } else {
        printf("Lista cheia!\n");
    }
}

void removeElemento(ListaLinear *lista, int elemento){
    int posicao = -1;
    for(int i=0; i<lista->tamanho; i++){
        if(lista->vetor[i] == elemento){
            posicao = i;
            break;
        }
    }
    if(posicao != -1){
        for(int i=posicao; i<lista->tamanho-1; i++){
            lista->vetor[i] = lista->vetor[i+1];
        }
        lista->tamanho--;
    } else {
        printf("Elemento não encontrado!\n");
    }
}

int buscaElemento(ListaLinear *lista, int elemento){
    for(int i=0; i<lista->tamanho; i++){
        if(lista->vetor[i] == elemento){
            return i;
        }
    }
    return -1;
}

//2. Escreva um programa que leia 5 números do usuário, armazene-os em uma lista linear e imprima a lista.

int main(){
    ListaLinear lista;
    inicializaLista(&lista);
    int num;
    for(int i=0; i<5; i++){
        printf("Digite um número: ");
        scanf("%d", &num);
        insereElemento(&lista, num);
    }
    printf("Lista: ");
    for(int i=0; i<lista.tamanho; i++){
        printf("%d ", lista.vetor[i]);
    }
    printf("\n");
    return 0;
}

//3. Crie uma função que receba uma lista linear e retorne o número de elementos pares.

int elementosPares(ListaLinear *lista){
    int pares = 0;
    for(int i=0; i<lista->tamanho; i++){
        if(lista->vetor[i] % 2 == 0){
            pares++;
        }
    }
    return pares;
}

//4. Implemente uma função que inverta a ordem dos elementos em uma lista linear.

void inverteLista(ListaLinear *lista){
    int inicio = 0;
    int fim = lista->tamanho - 1;
    while(inicio < fim){
        int temp = lista->vetor[inicio];
        lista->vetor[inicio] = lista->vetor[fim];
        lista->vetor[fim] = temp;
        inicio++;
        fim--;
    }
}

//5. Escreva um programa que remova todos os elementos duplicados de uma lista linear.

void removeDuplicados(ListaLinear *lista){
    for(int i=0; i<lista->tamanho; i++){
        for(int j=i+1; j<lista->tamanho; j++){
            if(lista->vetor[i] == lista->vetor[j]){
                removeElemento(lista, lista->vetor[i]);
                j--;
            }
        }
    }
}

