#include <stdio.h>
#include <stdlib.h>

/*Pilha e Fila 
        
-  Pilha (LIFO):  O último elemento inserido é o primeiro a ser removido.
-  Fila (FIFO):  O primeiro elemento inserido é o primeiro a ser removido.

Questões:
1. Implemente uma pilha usando um vetor e crie funções para push, pop e verificar se a pilha está vazia.
2. Escreva um programa que use uma pilha para inverter uma string.
3. Implemente uma fila usando uma lista encadeada e crie funções para enqueue, dequeue e verificar se a fila está vazia.
4. Crie uma função que verifique se uma expressão matemática está balanceada usando uma pilha.
5. Escreva um programa que simule uma fila de impressão usando uma fila.*/

//1. Implemente uma pilha usando um vetor e crie funções para push, pop e verificar se a pilha está vazia.

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void inicializaPilha(Pilha *pilha){
    pilha->topo = -1;
}

int pilhaVazia(Pilha *pilha){
    return pilha->topo == -1;
}

void push(Pilha *pilha, int valor){
    if(pilha->topo == MAX - 1){
        printf("Pilha cheia!\n");
        return;
    }
    pilha->topo++;
    pilha->dados[pilha->topo] = valor;
}

int pop(Pilha *pilha){
    if(pilhaVazia(pilha)){
        printf("Pilha vazia!\n");
        return -1;
    }
    int valor = pilha->dados[pilha->topo];
    pilha->topo--;
    return valor;
}

//2. Escreva um programa que use uma pilha para inverter uma string.

void inverteString(char *string){
    Pilha pilha;
    inicializaPilha(&pilha);
    for(int i = 0; string[i] != '\0'; i++){
        push(&pilha, string[i]);
    }
    for(int i = 0; !pilhaVazia(&pilha); i++){
        string[i] = pop(&pilha);
    }
}

//3. Implemente uma fila usando uma lista encadeada e crie funções para enqueue, dequeue e verificar se a fila está vazia.

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

void inicializaFila(Fila *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}

int filaVazia(Fila *fila){
    return fila->inicio == NULL;
}

void enqueue(Fila *fila, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    if(fila->fim != NULL){
        fila->fim->prox = novo;
    } else {
        fila->inicio = novo;
    }
    fila->fim = novo;
}

int dequeue(Fila *fila){
    if(filaVazia(fila)){
        printf("Fila vazia!\n");
        return -1;
    }
    No *removido = fila->inicio;
    int valor = removido->valor;
    fila->inicio = removido->prox;
    if(fila->inicio == NULL){
        fila->fim = NULL;
    }
    free(removido);
    return valor;
}

//4. Crie uma função que verifique se uma expressão matemática está balanceada usando uma pilha.

int estaBalanceada(char *expressao){
    Pilha pilha;
    inicializaPilha(&pilha);
    for(int i = 0; expressao[i] != '\0'; i++){
        if(expressao[i] == '('){
            push(&pilha, '(');
        } else if(expressao[i] == ')'){
            if(pilhaVazia(&pilha)){
                return 0;
            }
            pop(&pilha);
        }
    }
    return pilhaVazia(&pilha);
}

//5. Escreva um programa que simule uma fila de impressão usando uma fila.

int main(){
    Fila fila;
    inicializaFila(&fila);
    enqueue(&fila, 1);
    enqueue(&fila, 2);
    enqueue(&fila, 3);
    printf("%d\n", dequeue(&fila));
    printf("%d\n", dequeue(&fila));
    printf("%d\n", dequeue(&fila));
    printf("%d\n", dequeue(&fila));
    return 0;
}

