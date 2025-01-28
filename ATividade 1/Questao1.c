/* 1)Guarde N n�meros em um vetor alocado dinamicamente. Exiba a
m�dia dos n�meros lidos e os m�ltiplos de 6 digitados. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
setlocale(LC_ALL, "Portuguese");
    int N, count = 0;
    printf("Quantos números deseja armazenar? ");
    scanf("%d", &N);

    // Aloca memória para o vetor dinamicamente
    int *numeros = (int *)malloc(N * sizeof(int));
    if (numeros == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    int soma = 0;
    printf("Digite %d números:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &numeros[i]);
        soma += numeros[i];
    }

    double media = (double)soma / N;
    printf("Média dos números: %.2f\n", media);
    printf("Múltiplos de 6 digitados: ");
    for (int i = 0; i < N; i++) {
        if (numeros[i] % 6 == 0) {
            printf("%d ", numeros[i]);
            count++;
        }
    }

    if (count == 0) printf("Nenhum Múltiplo de 6.");
    printf("\n");

    free(numeros); // Libera memória alocada
    return 0;
}