#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"



int main()
{
    Grafo *grafo = inicializaGrafo();

    grafo = insere_vertice(grafo, 1);
    grafo = insere_vertice(grafo, 2);
    grafo = insere_vertice(grafo, 3);
    grafo = insere_vertice(grafo, 4);
    grafo = insere_vertice(grafo, 5);
    grafo = insere_vertice(grafo, 6);
    grafo = insere_vertice(grafo, 7);
    grafo = insere_vertice(grafo, 8);
   
    insere_aresta(grafo, 1, 2);
    insere_aresta(grafo, 1, 3);
    insere_aresta(grafo, 2, 4);
    insere_aresta(grafo, 2, 5);
    insere_aresta(grafo, 3, 6);
    insere_aresta(grafo, 3, 7);
    insere_aresta(grafo, 4, 8);
    insere_aresta(grafo, 5, 8);
    insere_aresta(grafo, 6, 8);
    insere_aresta(grafo, 7, 8);

    imprime(grafo);
    printf("\nBusca por largura\n");
    busca_largura(grafo, 8);

    printf("\nBusca por profundidade \n");
    buscaProfundidade(grafo, 8);



    return 0;
}