/*2) Crie um struct que guarde nome, idade e peso um atletas. Em um
vetor, alocado dinamicamente, guarde os dados de N atletas. Exiba uma
listagem dos dados dos atletas cadastrados. Ao final exiba a média dos
pesos e quantos atletas são menores de idade.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int idade;
    float peso;
} Atleta;

int main() {
    int N, menores = 0;
    float somaPesos = 0;
    printf("Quantos atletas deseja cadastrar? ");
    scanf("%d", &N);

    // Aloca memória para o vetor de atletas dinamicamente
    Atleta *atletas = (Atleta *)malloc(N * sizeof(Atleta));
    if (atletas == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        printf("Atleta %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]s", atletas[i].nome);
        printf("Idade: ");
        scanf("%d", &atletas[i].idade);
        printf("Peso: ");
        scanf("%f", &atletas[i].peso);
        somaPesos += atletas[i].peso;
        if (atletas[i].idade < 18) menores++;
    }

    printf("\nLista de atletas cadastrados:\n");
    for (int i = 0; i < N; i++) {
        printf("Nome: %s, Idade: %d, Peso: %.2f kg\n", atletas[i].nome, atletas[i].idade, atletas[i].peso);
    }

    printf("\nMédia dos pesos: %.2f kg\n", somaPesos / N);
    printf("Número de atletas menores de idade: %d\n", menores);

    free(atletas);
    return 0;
}
