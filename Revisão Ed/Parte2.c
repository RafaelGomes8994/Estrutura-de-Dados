/*Complexidade de Algoritmos 
        
A complexidade de algoritmos mede o desempenho de um algoritmo em termos de tempo (complexidade temporal) e espaço (complexidade espacial). É comum usar a notação Big-O para descrever o pior caso de um algoritmo.

Questões:
1. Dado um algoritmo com complexidade O(n), explique o que acontece com o tempo de execução se o tamanho da entrada dobrar.
2. Analise a complexidade do seguinte código e explique por quê:
               c
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {
           printf("%d ", i + j);
       }
   }
               
3. Escreva um algoritmo para encontrar o maior elemento em um vetor e determine sua complexidade.
4. Dado um algoritmo com complexidade O(log n), explique por que ele é mais eficiente que um algoritmo O(n) para entradas grandes.
5. Implemente uma busca binária em um vetor ordenado e analise sua complexidade. */

// 1. Dado um algoritmo com complexidade O(n), explique o que acontece com o tempo de execução se o tamanho da entrada dobrar.

// Se o algoritmo tem complexidade O(n), isso significa que o tempo de execução é proporcional ao tamanho da entrada. Portanto, se o tamanho da entrada dobrar, o tempo de execução também dobrará.

// 2. Analise a complexidade do seguinte código e explique por quê:

// A complexidade do código é O(n^2), pois tem dois loops aninhados que percorrem o vetor de tamanho n. O tempo de execução é proporcional a n^2, o que significa que o tempo aumenta quadrado com o tamanho da entrada.

// 3. Escreva um algoritmo para encontrar o maior elemento em um vetor e determine sua complexidade.

int maiorElemento(int *vetor, int tam){
    int maior = vetor[0];
    for(int i=1; i<tam; i++){
        if(vetor[i] > maior){
            maior = vetor[i];
        }
    }
    return maior;
}

// A complexidade do algoritmo é O(n), pois ele percorre o vetor uma vez para encontrar o maior elemento.

// 4. Dado um algoritmo com complexidade O(log n), explique por que ele é mais eficiente que um algoritmo O(n) para entradas grandes.

// Um algoritmo com complexidade O(log n) tem um crescimento logarítmico, o que significa que o tempo de execução aumenta de forma mais lenta à medida que o tamanho da entrada aumenta. Por outro lado, um algoritmo O(n) tem um crescimento linear, o que resulta em um aumento mais rápido do tempo de execução para entradas grandes. Portanto, um algoritmo com complexidade O(log n) é mais eficiente para entradas grandes.

// 5. Implemente uma busca binária em um vetor ordenado e analise sua complexidade.

int buscaBinaria(int *vetor, int tam, int chave){
    int inicio = 0;
    int fim = tam - 1;
    while(inicio <= fim){
        int meio = (inicio + fim) / 2;
        if(vetor[meio] == chave){
            return meio;
        } else if(vetor[meio] < chave){
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

// A complexidade da busca binária é O(log n), pois a cada iteração o tamanho do intervalo de busca é reduzido pela metade. Isso resulta em um tempo de execução mais eficiente para vetores ordenados em comparação com a busca linear.
