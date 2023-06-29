#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex_veiculos.h"

struct veiculo{
    char marca[10];
    char placa[8];
    int ano;
};


struct no
{
    Veiculo veiculo;
    struct no *prox;
};


struct lista_veiculos
{
    No *inicio;
    No *fim;
    int tamanho;
};

Lista_veiculos *criarListaEncadeada(){
    Lista_veiculos *lista_veiculos = (Lista_veiculos *)malloc(sizeof(Lista_veiculos));
    if(lista_veiculos == NULL){
        printf("nao foi possivel alocar memoria");
    } else{
        lista_veiculos->inicio = NULL;
        lista_veiculos->fim = NULL;
        lista_veiculos->tamanho = 0;
    }
    return lista_veiculos;
}

No* alocarNo(){
    No *no = (No*) malloc(sizeof(No));
    if (no == NULL){
        printf("nao foi possivel alocar memoria");
    }
    return no;
}

void inserirPrimeiroItem(Lista_veiculos *lista_veiculos, char marca[], char placa[], int ano){
    No *no=alocarNo();
    strcpy(no->veiculo.marca, marca);
    strcpy(no->veiculo.placa, placa);
    no->veiculo.ano = ano;
    no->prox = NULL;
    lista_veiculos->inicio = no;
    lista_veiculos->fim=no;
    printf("item inserido\n");
    lista_veiculos->tamanho++;
};

void inserirInicio(Lista_veiculos *lista_veiculos, char marca[], char placa[], int ano){
    No *no = alocarNo();
    strcpy(no->veiculo.marca, marca);
    strcpy(no->veiculo.placa, placa);
    no->veiculo.ano = ano;
    no->prox = lista_veiculos->inicio;
    lista_veiculos->inicio = no;
    printf("item inserido\n");
    lista_veiculos->tamanho++;
}

void inserirFinal(Lista_veiculos *lista_veiculos, char marca[], char placa[], int ano){
    No *no = alocarNo();
    strcpy(no->veiculo.marca, marca);
    strcpy(no->veiculo.placa, placa);
    no->veiculo.ano = ano;
    no->prox = NULL;
    lista_veiculos->fim->prox=no;
    lista_veiculos->fim=no;
    printf("item inserido\n");
    lista_veiculos->tamanho++;
}

 void inserirPos(Lista_veiculos *lista_veiculos, char marca[], char placa[], int ano, int pos){
    if(pos < 0 || pos > lista_veiculos->tamanho){
        printf("posicao invalida\n");
        return;
    }
    if(pos == 0){
        inserirInicio(lista_veiculos, marca, placa, ano);
        return;
    }
    if (pos == lista_veiculos->tamanho){
        inserirFinal(lista_veiculos, marca, placa, ano);
        return;
    }
    No *no = alocarNo();
    strcpy(no->veiculo.marca, marca);
    strcpy(no->veiculo.placa, placa);
    no->veiculo.ano = ano;
    No *anterior =NULL;
    No *atual = lista_veiculos->inicio;

    int i=0;
        while (i < pos) {
        anterior = atual;
        atual = atual->prox;
        i++;
    }
    no->prox = atual;
    anterior->prox = no;
    lista_veiculos->tamanho++;
    printf("item inserido");
}

void remover(Lista_veiculos *lista_veiculos, int pos) {
    if(pos < 0 || pos >= lista_veiculos->tamanho) {
        printf("posicao invalida\n");
        return;
    }
    No *anterior = NULL;
    No *atual = lista_veiculos->inicio;
    int i = 0;
    while (i<pos){
        anterior = atual;
        atual = atual->prox;
        i++;
    }
    if(anterior == NULL){
        lista_veiculos->inicio = atual->prox;
    } else{
        anterior->prox = atual->prox;
    }
    free(atual);
    lista_veiculos->tamanho--;
    printf("veiculo removido");
}

void removerPlaca(Lista_veiculos *lista_veiculos, char placa[8]) {
    No *anterior = NULL;
    No *atual = lista_veiculos->inicio;
    int pos = 0;
    while (atual != NULL && strcmp(atual->veiculo.placa, placa) != 0)
    {
        anterior = atual;
        atual = atual->prox;
        pos++;
    }

    if(atual == NULL){
        printf("veiculo nao encontrado!\n");
        return;
    }
    if(anterior == NULL){
        lista_veiculos->inicio = atual->prox;
    } else{
        anterior->prox = atual->prox;
    }
    free(atual);
    lista_veiculos->tamanho--;
    printf("\nveiculo com a placa %s removido com sucesso", placa);
}

int listaVazia(Lista_veiculos *lista_veiculos){
    return lista_veiculos->inicio == NULL?1:0;
}

void mostrar(Lista_veiculos *lista_veiculos){
    if(listaVazia(lista_veiculos)){
        printf("\nlista vazia");
    } else{
        No *aux=lista_veiculos->inicio;
        int a = 1;
        while (aux!=NULL){
            printf("\n veiculo %d", a);
            printf("\n marca: %s", aux->veiculo.marca);
            printf("\n placa: %s", aux->veiculo.placa);
            printf("\n ano: %d", aux->veiculo.ano);
            printf("\n");
            a++;
            aux = aux->prox;
        }
    }
}
