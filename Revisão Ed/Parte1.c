include <stdio.h>
include <stdlib.h>
/*Revisão de Ponteiros e Alocação Dinâmica de Memória
        
Ponteiros são variáveis que armazenam endereços de memória. Eles são fundamentais para manipular estruturas de dados dinâmicos, como listas encadeadas e árvores. A alocação dinâmica de memória permite que você reserve espaço em tempo de execução, usando funções como malloc, calloc, realloc e free.

Questões:
1. Crie um programa que aloque dinamicamente um vetor de inteiros de tamanho 10, preencha-o com valores de 1 a 10 e imprima os valores.
2. Escreva uma função que receba dois ponteiros para inteiros e troque os valores das variáveis apontadas por eles.
3. Crie um programa que aloque dinamicamente uma matriz 3x3 de inteiros, preencha-a com valores sequenciais e imprima a matriz.
4. Escreva uma função que receba um ponteiro para um vetor de inteiros e seu tamanho, e retorne a soma dos elementos.
5. Crie um programa que aloque dinamicamente uma string, leia uma palavra do usuário e imprima a palavra invertida.*/

//1. Crie um programa que aloque dinamicamente um vetor de inteiros de tamanho 10, preencha-o com valores de 1 a 10 e imprima os valores.

int main(){
    int *vetor;
    vetor = (int*)malloc(10*sizeof(int));
    for(int i=0; i<10; i++){
        vetor[i] = i+1;
        printf("%d ", vetor[i]);
    }
    free(vetor);
    return 0;
}
//2. Escreva uma função que receba dois ponteiros para inteiros e troque os valores das variáveis apontadas por eles.

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

///3. Crie um programa que aloque dinamicamente uma matriz 3x3 de inteiros, preencha-a com valores sequenciais e imprima a matriz.

int main(){
    int **matriz;
    matriz = (int**)malloc(3*sizeof(int*));
    for(int i=0; i<3; i++){
        matriz[i] = (int*)malloc(3*sizeof(int));
    }
    int cont = 1;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            matriz[i][j] = cont;
            cont++;
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    for(int i=0; i<3; i++){
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}
//4. Escreva uma função que receba um ponteiro para um vetor de inteiros e seu tamanho, e retorne a soma dos elementos.

int soma(int *vetor, int tam){
    int s = 0;
    for(int i=0; i<tam; i++){
        s += vetor[i];
    }
    return s;
}
//5. Crie um programa que aloque dinamicamente uma string, leia uma palavra do usuário e imprima a palavra invertida.

int main(){
    char *palavra;
    palavra = (char*)malloc(50*sizeof(char));
    scanf("%s", palavra);
    for(int i=49; i>=0; i--){
        if(palavra[i] != '\0'){
            printf("%c", palavra[i]);
        }
    }
    free(palavra);
    return 0;
}
