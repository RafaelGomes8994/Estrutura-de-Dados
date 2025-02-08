#include <stdio.h>
#include <stdlib.h>

/*Lista Duplamente Encadeada e Multilista 
        
Uma lista duplamente encadeada permite navegação para frente e para trás, pois cada nó contém ponteiros para o próximo e o anterior. Multilistas são estruturas mais complexas que permitem múltiplas relações entre elementos.

Questões:
1. Implemente uma lista duplamente encadeada e crie funções para inserir no início e no fim.
2. Escreva uma função que imprima os elementos de uma lista duplamente encadeada em ordem reversa.
3. Crie uma função que remova um nó com um valor específico de uma lista duplamente encadeada.
4. Implemente uma função que insira um nó em uma posição específica de uma lista duplamente encadeada.
5. Escreva um programa que simule uma multilista para armazenar informações sobre alunos e disciplinas.*/

//1. Implemente uma lista duplamente encadeada e crie funções para inserir no início e no fim.

typedef struct No {
    int valor;
    struct No *prox;
    struct No *ant;
} No;

typedef struct {
    No *inicio;
    No *fim;
} ListaDupla;

void inicializaLista(ListaDupla *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
}

void insereInicio(ListaDupla *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = lista->inicio;
    novo->ant = NULL;
    if(lista->inicio != NULL){
        lista->inicio->ant = novo;
    } else {
        lista->fim = novo;
    }
    lista->inicio = novo;
}

void insereFim(ListaDupla *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = lista->fim;
    if(lista->fim != NULL){
        lista->fim->prox = novo;
    } else {
        lista->inicio = novo;
    }
    lista->fim = novo;
}

//2. Escreva uma função que imprima os elementos de uma lista duplamente encadeada em ordem reversa.

void imprimeReverso(ListaDupla *lista){
    No *atual = lista->fim;
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->ant;
    }
    printf("\n");
}

//3. Crie uma função que remova um nó com um valor específico de uma lista duplamente encadeada.

void removeValor(ListaDupla *lista, int valor){
    No *atual = lista->inicio;
    while(atual != NULL){
        if(atual->valor == valor){
            if(atual->ant != NULL){
                atual->ant->prox = atual->prox;
            } else {
                lista->inicio = atual->prox;
            }
            if(atual->prox != NULL){
                atual->prox->ant = atual->ant;
            } else {
                lista->fim = atual->ant;
            }
            free(atual);
            return;
        }
        atual = atual->prox;
    }
}

//4. Implemente uma função que insira um nó em uma posição específica de uma lista duplamente encadeada.

void inserePosicao(ListaDupla *lista, int valor, int posicao){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    No *atual = lista->inicio;
    for(int i = 1; i < posicao; i++){
        if(atual == NULL){
            free(novo);
            return;
        }
        atual = atual->prox;
    }
    if(atual != NULL){
        novo->prox = atual;
        novo->ant = atual->ant;
        if(atual->ant != NULL){
            atual->ant->prox = novo;
        } else {
            lista->inicio = novo;
        }
        atual->ant = novo;
    } else {
        novo->prox = NULL;
        novo->ant = lista->fim;
        if(lista->fim != NULL){
            lista->fim->prox = novo;
        } else {
            lista->inicio = novo;
        }
        lista->fim = novo;
    }
}

//5. Escreva um programa que simule uma multilista para armazenar informações sobre alunos e disciplinas.

typedef struct Disciplina {
    char nome[50];
    struct Disciplina *prox;
} Disciplina;

typedef struct Aluno {
    char nome[50];
    Disciplina *disciplinas;
    struct Aluno *prox;
} Aluno;

typedef struct {
    Aluno *alunos;
    Disciplina *disciplinas;
} Multilista;

void inicializaMultilista(Multilista *multilista){
    multilista->alunos = NULL;
    multilista->disciplinas = NULL;
}

void insereAluno(Multilista *multilista, char nome[50]){
    Aluno *novo = (Aluno*)malloc(sizeof(Aluno));
    strcpy(novo->nome, nome);
    novo->disciplinas = NULL;
    novo->prox = multilista->alunos;
    multilista->alunos = novo;
}

void insereDisciplina(Multilista *multilista, char nome[50]){
    Disciplina *nova = (Disciplina*)malloc(sizeof(Disciplina));
    strcpy(nova->nome, nome);
    nova->prox = multilista->disciplinas;
    multilista->disciplinas = nova;
}

void inscreveAluno(Multilista *multilista, char nomeAluno[50], char nomeDisciplina[50]){
    Aluno *aluno = multilista->alunos;
    while(aluno != NULL && strcmp(aluno->nome, nomeAluno) != 0){
        aluno = aluno->prox;
    }
    if(aluno == NULL){
        printf("Aluno não encontrado!\n");
        return;
    }
    Disciplina *disciplina = multilista->disciplinas;
    while(disciplina != NULL && strcmp(disciplina->nome, nomeDisciplina) != 0){
        disciplina = disciplina->prox;
    }
    if(disciplina == NULL){
        printf("Disciplina não encontrada!\n");
        return;
    }
    Disciplina *nova = (Disciplina*)malloc(sizeof(Disciplina));
    strcpy(nova->nome, disciplina->nome);
    nova->prox = aluno->disciplinas;
    aluno->disciplinas = nova;
}

void imprimeMultilista(Multilista *multilista){
    Aluno *aluno = multilista->alunos;
    while(aluno != NULL){
        printf("Aluno: %s\n", aluno->nome);
        Disciplina *disciplina = aluno->disciplinas;
        while(disciplina != NULL){
            printf("Disciplina: %s\n", disciplina->nome);
            disciplina = disciplina->prox;
        }
        aluno = aluno->prox;
    }
}

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
    
    Multilista multilista;
    inicializaMultilista(&multilista);
    insereAluno(&multilista, "João");
    insereAluno(&multilista, "Maria");
    insereDisciplina(&multilista, "Matemática");
    insereDisciplina(&multilista, "Português");
    inscreveAluno(&multilista, "João", "Matemática");
    inscreveAluno(&multilista, "Maria", "Português");
    imprimeMultilista(&multilista);
    
    return 0;
}
