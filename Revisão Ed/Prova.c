/*1) Questões Teóricas
a) Implementação de Listas Lineares e Vantagens/Desvantagens
Implementação com Vetor (Array):

Vantagens:

Acesso direto a qualquer elemento em O(1).

Simplicidade de implementação.

Uso eficiente de memória (não há overhead de ponteiros).

Desvantagens:

Tamanho fixo, o que pode levar a desperdício de memória ou necessidade de redimensionamento.

Inserções e remoções no meio do vetor são ineficientes (O(n)).

Implementação com Lista Encadeada:

Vantagens:

Tamanho dinâmico, podendo crescer conforme necessário.

Inserções e remoções são eficientes (O(1) no início/fim, O(n) no meio).

Desvantagens:

Acesso sequencial, com complexidade O(n) para acessar um elemento específico.

Uso de memória extra para armazenar ponteiros.

b) Diferença entre Pilha e Fila e Exemplos de Utilidade
Pilha (LIFO - Last In, First Out):

Funcionamento: O último elemento inserido é o primeiro a ser removido.

Exemplo de Utilidade:

Undo/Redo em editores de texto: As ações são armazenadas em uma pilha, e a última ação é a primeira a ser desfeita.

Chamadas de funções em programas: O sistema usa uma pilha para gerenciar o retorno de funções.

Fila (FIFO - First In, First Out):

Funcionamento: O primeiro elemento inserido é o primeiro a ser removido.

Exemplo de Utilidade:

Filas de impressão: Os documentos são impressos na ordem em que foram enviados.

Processamento de tarefas: Em sistemas operacionais, as tarefas são processadas na ordem de chegada.*/

//2) Lista Duplamente Encadeada
//a) Especificação de um Nó da Lista

typedef struct aluno{
    char nome[30];
    float notafinal;
    int quantFaltas;
    struct aluno *prox;
    struct aluno *ant;
}aluno;

//b) Função para Remover um Aluno por Nome

int removeAluno(aluno **inicio, char *nome) {
    // Verifica se a lista está vazia
    if (*inicio == NULL) {
        printf("Lista vazia\n");
        return 0;
    }

    aluno *atual = *inicio;
    
    // Procura o aluno com o nome especificado
    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        atual = atual->prox;
    }
    
    // Se o aluno não foi encontrado
    if (atual == NULL) {
        printf("Aluno não encontrado\n");
        return 0;
    }
    
    // Ajusta o ponteiro do nó anterior, se existir
    if (atual->ant != NULL) {
        atual->ant->prox = atual->prox;
    } else {
        // Se estiver removendo o primeiro nó, atualiza o início da lista
        *inicio = atual->prox;
    }
    
    // Ajusta o ponteiro do nó seguinte, se existir
    if (atual->prox != NULL) {
        atual->prox->ant = atual->ant;
    }
    
    free(atual);
    return 1;
}
//4) Pilha com Lista Circular Simplesmente Encadeada
//a) Função para Empilhar (Push)

typedef struct No{
    char nome [30];
    float pesoAt;
    float altAt;
    struct No *prox;
}No

void push (No *topo, char *nome, float peso, float altura ) {
    No *novo = (No*)malloc(sizeof(No));
    strcpy(novo->nome, nome);
    novo->pesoAt = peso;
    novo->altAt = altura;
    novo->prox = topo->prox;
    topo->prox = novo;
}

//b) Função para Desempilhar (Pop)

int pop(No **pilha, char *nome, float *peso, float *altura) {
    if (*pilha == NULL) return 0; // Pilha vazia

    No *removido = *pilha;
    *pilha = removido->prox;
    strcpy(nome, removido->nome);
    *peso = removido->pesoAt;
    *altura = removido->altAt;
    free(removido);
    return 1; // Sucesso
}

