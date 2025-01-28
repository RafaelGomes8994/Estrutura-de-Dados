#include <stdio.h>

//Exemplo de Lista Encadeada usando nó cabeça

typedef struct no{
int dado;
struct no *proxNo;
}tipoNo;

typedef struct {
  tipoNo *inicio;
  tipoNo *fim;
  int quant;
  }tipoLista;

void inicializa(tipoLista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->quant = 0;
}

int insereListaVazia(tipoLista *lista, int valor){
tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo));
if(novoNo == NULL)
    return 0;
novoNo->dado = valor;
novoNo->proxNo = NULL;
lista->inicio = novoNo;
lista->fim = novoNo;
lista->quant++;
}

int insereNaFrente(tipoLista *lista, int valor){
tipoNo *novoNo;
if(lista->inicio == NULL)
    insereListaVazia(&lista ,valor);
else{
    novoNo = (tipoNo*)malloc(sizeof(tipoNo));
    if(novoNo==NULL)
        return 0;
    novoNo->dado = valor;
    novoNo->proxNo = lista->inicio;
    lista->inicio = novoNo;
    return 1;
}
}

/*Função de exibição da lista simplesmente encadeada*/
int exibeLista(tipoLista *lista){
tipoNo *atual;  //Variável que será usada para percorrer a lista*/
if(lista->inicio == NULL)
    return 0;
atual = lista->inicio;
printf("\nLista encadeada: ");
while(atual !=NULL){
    printf("%8d",atual->dado);
    atual = atual->proxNo;
    }
return 1;
}

void main(){
tipoLista lista;
inicializa(&lista);
int leitor;
printf("Digite um elemento: ");
scanf("%d",&leitor);
int resp = insereListaVazia(&lista, leitor);
if(!resp)
   printf("Memoria nao alocada!");
printf("Elemento guardado: %d",lista.inicio->dado);
printf("\nDigite outro elemento para inserir na frente: ");
scanf("%d",&leitor);
resp = insereNaFrente(&lista,leitor);
exibeLista(&lista);
printf("\nDigite outro elemento para inserir no fim: ");
scanf("%d",&leitor);
//resp = insereNoFim(&lista, leitor);
exibeLista(&lista);

}#include <stdio.h>

//Exemplo de Lista Encadeada usando nó cabeça

typedef struct no{
int dado;
struct no *proxNo;
}tipoNo;

typedef struct {
  tipoNo *inicio;
  tipoNo *fim;
  int quant;
  }tipoLista;

void inicializa(tipoLista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->quant = 0;
}

int insereListaVazia(tipoLista *lista, int valor){
tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo));
if(novoNo == NULL)
    return 0;
novoNo->dado = valor;
novoNo->proxNo = NULL;
lista->inicio = novoNo;
lista->fim = novoNo;
lista->quant++;
}

int insereNaFrente(tipoLista *lista, int valor){
tipoNo *novoNo;
if(lista->inicio == NULL)
    insereListaVazia(&lista ,valor);
else{
    novoNo = (tipoNo*)malloc(sizeof(tipoNo));
    if(novoNo==NULL)
        return 0;
    novoNo->dado = valor;
    novoNo->proxNo = lista->inicio;
    lista->inicio = novoNo;
    return 1;
}
}

/*Função de exibição da lista simplesmente encadeada*/
int exibeLista(tipoLista *lista){
tipoNo *atual;  //Variável que será usada para percorrer a lista*/
if(lista->inicio == NULL)
    return 0;
atual = lista->inicio;
printf("\nLista encadeada: ");
while(atual !=NULL){
    printf("%8d",atual->dado);
    atual = atual->proxNo;
    }
return 1;
}

void main(){
tipoLista lista;
inicializa(&lista);
int leitor;
printf("Digite um elemento: ");
scanf("%d",&leitor);
int resp = insereListaVazia(&lista, leitor);
if(!resp)
   printf("Memoria nao alocada!");
printf("Elemento guardado: %d",lista.inicio->dado);
printf("\nDigite outro elemento para inserir na frente: ");
scanf("%d",&leitor);
resp = insereNaFrente(&lista,leitor);
exibeLista(&lista);
printf("\nDigite outro elemento para inserir no fim: ");
scanf("%d",&leitor);
//resp = insereNoFim(&lista, leitor);
exibeLista(&lista);

}