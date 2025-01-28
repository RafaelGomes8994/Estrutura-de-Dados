/*3) Construa um programa que armazene nome, matrícula e média de
até N alunos e dê ao usuário a possibilidade de ver a listagem dos
alunos em ordem alfabética ou em ordem de classificação. Obs: uma
vez que os dados sejam digitados, o usuário deve poder ver as listagens
quantas vezes ele desejar.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int matricula;
    float media;
} Aluno;

// Função para comparar por nome (ordem alfabética)
int compareNome(const void *a, const void *b) {
    return strcmp(((Aluno *)a)->nome, ((Aluno *)b)->nome);
}

// Função para comparar por média (ordem de classificação)
int compareMedia(const void *a, const void *b) {
    float diff = ((Aluno *)b)->media - ((Aluno *)a)->media;
    return (diff > 0) - (diff < 0); // Retorna -1, 0 ou 1
}

int main() {
    int N;
    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &N);

    Aluno *alunos = (Aluno *)malloc(N * sizeof(Aluno));
    if (alunos == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]s", alunos[i].nome);
        printf("Matrícula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Média: ");
        scanf("%f", &alunos[i].media);
    }

    int opcao;
    do {
        printf("\nEscolha a listagem desejada:\n");
        printf("1 - Ordem alfabética\n");
        printf("2 - Ordem de classificação\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            qsort(alunos, N, sizeof(Aluno), compareNome);
            printf("\nLista em ordem alfabética:\n");
            for (int i = 0; i < N; i++) {
                printf("Nome: %s, Matrícula: %d, Média: %.2f\n", alunos[i].nome, alunos[i].matricula, alunos[i].media);
            }
        } else if (opcao == 2) {
            qsort(alunos, N, sizeof(Aluno), compareMedia);
            printf("\nLista em ordem de classificação:\n");
            for (int i = 0; i < N; i++) {
                printf("Nome: %s, Matrícula: %d, Média: %.2f\n", alunos[i].nome, alunos[i].matricula, alunos[i].media);
            }
        }
    } while (opcao != 0);

    free(alunos); // Libera memória alocada
    return 0;
}
