#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct no
{
    int valor;
    struct no *prox;
};

struct fila
{
    int cont;
    No *ini;
    No *fim;
};


Fila *criarFila()
{
    Fila *fila = (Fila*)malloc (sizeof(Fila));
    fila->cont = 0;
    fila->ini = NULL;
    fila->fim = NULL;
    return fila;
}

void enfileirar(Fila *fila, int x)
{
    No *no = (No *)malloc(sizeof(No));
    no->valor = x;
    no->prox = NULL;

    if (fila->cont == 0)
    {
        fila->ini = no;
        fila->fim = no;
    }
    else
    {
        fila->fim->prox = no;
        fila->fim = no;
    }
    fila->cont++;
}

int desenfileirar(Fila *f)
{
    if (f->cont > 0)
    {
        No *aux = f->ini;
        int valor = f->ini->valor;
        f->ini = f->ini->prox;
        f->cont--;
        free(aux);
        return valor;
    }
}

int quantidadeElementos(Fila *f)
{
    return f->cont;
}