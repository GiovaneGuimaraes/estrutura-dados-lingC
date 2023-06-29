#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "fila.h"

struct vizinho
{
    int id_vizinho;
    Vizinho *prox;
};

struct grafo
{
    int id_vertice;
    int visitado;
    Vizinho *prim_vizinho;
    Grafo *prox;
};


Grafo *inicializaGrafo()
{
    return NULL;
}

void imprime(Grafo *g)
{
    while (g != NULL)
    {
        printf("Vértice %d\n", g->id_vertice);
        printf("Vizinhos: ");
        Vizinho *v = g->prim_vizinho;
        while (v != NULL)
        {
            printf("%d ", v->id_vizinho);
            v = v->prox;
        }
        printf("\n\n");
        g = g->prox;
    }
}

void libera_vizinhos(Vizinho *v)
{
    while (v != NULL)
    {
        Vizinho *temp = v;
        v = v->prox;
        free(temp);
    }
}

void libera(Grafo *g)
{
    while (g != NULL)
    {
        libera_vizinhos(g->prim_vizinho);
        Grafo *temp = g;
        g = g->prox;
        free(temp);
    }
}

Grafo *busca_vertice(Grafo *g, int x)
{
    while ((g != NULL) && (g->id_vertice != x))
    {
        g = g->prox;
    }
    return g;
}

Vizinho *busca_aresta(Grafo *g, int v1, int v2)
{
    Grafo *pv1 = busca_vertice(g, v1);
    Grafo *pv2 = busca_vertice(g, v2);
    Vizinho *resp = NULL;
    // verifica se ambos os vértices existem
    if ((pv1 != NULL) && (pv2 != NULL))
    {
        // percorre a lista de vizinhos de v1 procurando por v2
        resp = pv1->prim_vizinho;
        while ((resp != NULL) && (resp->id_vizinho != v2))
        {
            resp = resp->prox;
        }
    }
    return resp;
}

Grafo *insere_vertice(Grafo *g, int x)
{
    Grafo *p = busca_vertice(g, x);
    if (p == NULL)
    {
        p = (Grafo *)malloc(sizeof(Grafo));
        p->id_vertice = x;
        p->visitado = 0;
        p->prox = g;
        p->prim_vizinho = NULL;
        g = p;
    }
    return g;
}

// Para grafo orientado
void insere_um_sentido(Grafo *g, int v1, int v2)
{
    Grafo *p = busca_vertice(g, v1);
    Vizinho *nova = (Vizinho *)malloc(sizeof(Vizinho));
    nova->id_vizinho = v2;
    nova->prox = p->prim_vizinho;
    p->prim_vizinho = nova;
}

void insere_aresta_digrafo(Grafo *g, int v1, int v2)
{
    Vizinho *v = busca_aresta(g, v1, v2);
    if (v == NULL)
    {
        insere_um_sentido(g, v1, v2);
    }
}

void insere_aresta(Grafo *g, int v1, int v2)
{
    Vizinho *v = busca_aresta(g, v1, v2);
    if (v == NULL)
        insere_um_sentido(g, v1, v2);
    insere_um_sentido(g, v2, v1);
}

void retira_um_sentido(Grafo *g, int v1, int v2)
{
    Grafo *p = busca_vertice(g, v1);
    if (p != NULL)
    {
        Vizinho *ant = NULL;
        Vizinho *atual = p->prim_vizinho;
        while ((atual) && (atual->id_vizinho != v2))
        {
            ant = atual;
            atual = atual->prox;
        }
        if (ant == NULL) // v2 era o primeiro nó da lista
            p->prim_vizinho = atual->prox;
        else
            ant->prox = atual->prox;
        free(atual);
    }
}

void retira_aresta(Grafo *g, int v1, int v2)
{
    Vizinho *v = busca_aresta(g, v1, v2);
    if (v != NULL)
    {
        retira_um_sentido(g, v1, v2);
        retira_um_sentido(g, v2, v1);
    }
}

void retira_aresta_digrafo(Grafo *g, int v1, int v2)
{
    Vizinho *v = busca_aresta(g, v1, v2);
    if (v != NULL)
    {
        retira_um_sentido(g, v1, v2);
    }
}

void buscaProfundidade(Grafo *g, int valor) {
    Grafo *v = busca_vertice(g, valor);
    if (v == NULL) {
        return;
    }

    printf("Vértice: %d\n", valor);
    v->visitado = 1;

    Vizinho *viz = v->prim_vizinho;
    while (viz != NULL) {
        if (busca_vertice(g, viz->id_vizinho)->visitado != 1) {
            buscaProfundidade(g, viz->id_vizinho);
        }
        viz = viz->prox;
    }
    
}

void busca_largura(Grafo *g, int valor)
{
    Fila *fila=criarFila();

    enfileirar(fila, valor);
    busca_vertice(g, valor)->visitado=1;
    
    while (quantidadeElementos(fila) > 0)
    {
        int valor = desenfileirar(fila);
        Grafo *g2 = busca_vertice(g, valor);
        printf("Vértice: %d \n", valor);
        Vizinho *v = g2->prim_vizinho;
        while (v != NULL)
        {
            if (busca_vertice(g, v->id_vizinho)->visitado != 1)
            {
                enfileirar(fila, v->id_vizinho);
                busca_vertice(g, v->id_vizinho)->visitado = 1;
            }
            v = v->prox;
        }
       
    }

    while (g != NULL)
    {
        g->visitado = 0;
        g = g->prox;
    }
}



// void busca_profundidade(Grafo *g, int valor) {
    
//     Fila *fila=criarFila();

//     enfileirar(fila, valor);
//     busca_vertice(g, valor)->visitado=1;
//      while (quantidadeElementos(fila) > 0)
//     {
//         int valor = desenfileirar(fila);
//         Grafo *v = busca_vertice(g, valor);
//         printf("Vértice: %d \n", valor);
//         v->visitado = 1;
//         Vizinho *viz = v->prim_vizinho;
//         while (viz != NULL) {
//             if (busca_vertice(g, viz->id_vizinho)->visitado != 1) {
//                 busca_profundidade(g, viz->id_vizinho);
//             }
//             viz = viz->prox;
//         }
//     }

// }

