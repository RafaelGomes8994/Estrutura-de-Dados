#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar a lista dinâmica
typedef struct {
    char** data;      // Array de ponteiros para strings
    size_t size;      // Tamanho atual da lista
    size_t capacity;  // Capacidade total alocada
} StringList;

// Função para criar e inicializar a lista
StringList* createList() {
    StringList* list = malloc(sizeof(StringList));
    list->capacity = 10;  // Capacidade inicial
    list->size = 0;
    list->data = malloc(list->capacity * sizeof(char*));
    return list;
}

// Função para adicionar um elemento à lista
void addElement(StringList* list, const char* value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;  // Dobra a capacidade se necessário
        list->data = realloc(list->data, list->capacity * sizeof(char*));
    }
    list->data[list->size] = strdup(value);  // Aloca e copia a string
    list->size++;
}

// Função para remover um elemento pelo valor
void removeByValue(StringList* list, const char* value) {
    for (size_t i = 0; i < list->size; i++) {
        if (strcmp(list->data[i], value) == 0) {
            free(list->data[i]);  // Libera a memória da string removida
            for (size_t j = i; j < list->size - 1; j++) {
                list->data[j] = list->data[j + 1];  // Desloca os elementos
            }
            list->size--;
            return;
        }
    }
}

// Função para remover um elemento pelo índice
void removeByIndex(StringList* list, size_t index) {
    if (index < list->size) {
        free(list->data[index]);  // Libera a memória da string removida
        for (size_t i = index; i < list->size - 1; i++) {
            list->data[i] = list->data[i + 1];  // Desloca os elementos
        }
        list->size--;
    }
}

// Função para verificar se a lista contém um valor
int contains(StringList* list, const char* value) {
    for (size_t i = 0; i < list->size; i++) {
        if (strcmp(list->data[i], value) == 0) {
            return 1;  // Verdadeiro
        }
    }
    return 0;  // Falso
}

// Função para encontrar o índice de um valor
int indexOf(StringList* list, const char* value) {
    for (size_t i = 0; i < list->size; i++) {
        if (strcmp(list->data[i], value) == 0) {
            return (int)i;  // Retorna o índice
        }
    }
    return -1;  // Não encontrado
}

// Função de comparação para ordenação
int compareStrings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

// Função para ordenar a lista
void sortList(StringList* list) {
    qsort(list->data, list->size, sizeof(char*), compareStrings);
}

// Função para liberar a memória da lista
void freeList(StringList* list) {
    for (size_t i = 0; i < list->size; i++) {
        free(list->data[i]);  // Libera cada string
    }
    free(list->data);  // Libera o array de ponteiros
    free(list);        // Libera a estrutura
}

int main() {
    // **Criação da lista**
    StringList* nomes = createList();

    // **Adição de elementos**
    addElement(nomes, "Alice");
    addElement(nomes, "Bob");
    addElement(nomes, "Charlie");

    // **Acesso a elementos**
    printf("Primeiro nome: %s\n", nomes->data[0]);  // Alice
    printf("Segundo nome: %s\n", nomes->data[1]);   // Bob

    // **Remoção de elementos**
    removeByValue(nomes, "Bob");  // Remove pelo valor
    removeByIndex(nomes, 0);      // Remove pelo índice (remove Alice)

    // **Iteração sobre a lista**
    printf("Nomes restantes:\n");
    for (size_t i = 0; i < nomes->size; i++) {
        printf("%s\n", nomes->data[i]);  // Exibe os nomes restantes
    }

    // **Métodos úteis**
    // Verifica se a lista contém um elemento específico
    int contemCharlie = contains(nomes, "Charlie");
    printf("A lista contém Charlie? %s\n", contemCharlie ? "Sim" : "Não");

    // Encontra o índice de um elemento
    int indiceDeCharlie = indexOf(nomes, "Charlie");
    printf("Índice de Charlie: %d\n", indiceDeCharlie);

    // Ordena a lista
    sortList(nomes);
    printf("Lista ordenada:\n");
    for (size_t i = 0; i < nomes->size; i++) {
        printf("%s\n", nomes->data[i]);
    }

    // Libera a memória
    freeList(nomes);
    return 0;
}