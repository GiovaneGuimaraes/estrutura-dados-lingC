#include <stdio.h>
#include <stdlib.h>
#include "arvorebinaria.h"


int main()
{
  Arvore *raiz = criarABB(); 

  int op;
  int elem;
  int encontra;
  do
  {

    printf("\n1 - Inserir");
    printf("\n2 - Remover");
    printf("\n3 - Em Ordem");
    printf("\n4 - Pre Ordem");
    printf("\n5 - Pos Ordem");
    printf("\n6 - Maior e menor numero da arvore");
    printf("\n7 - Localizar elemento");
    printf("\n8 - Mostrar quantidade de elementos na arvore");
    printf("\n9 - teste exercicio");
    printf("\n10 - Sair");
    printf("\n\nEscolha sua opcao: ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:

      printf("\nDigite o valor a ser inserido: ");
      scanf("%d", &elem);
      raiz = inserir(elem, raiz);
      break;

    case 2:
      printf("\nDigite o valor a ser removido: ");
      scanf("%d", &elem);
      raiz = remover(raiz, elem);

      break;
    case 3:
      (raiz == NULL) ? printf("Árvore vazia") : emordem(raiz);
      break;
    case 4:
      (raiz == NULL) ? printf("Árvore vazia") : preordem(raiz);
      break;
    case 5:
      (raiz == NULL) ? printf("Árvore vazia") : posordem(raiz);
      break;
    case 6:
      (raiz == NULL) ? printf("Árvore vazia") : maior(raiz), menor(raiz);
      break;
    case 7:
      printf("\nDigite o valor a ser localizado: ");
      scanf("%d", &encontra);
      localizarElem(raiz, encontra);
      break;
    case 8:
      int quantidade = contar(raiz);
      printf("a arvore possui %d elementos!\n", quantidade);
      break;
    case 9:
      (raiz == NULL) ? printf("Árvore vazia") : teste(raiz);
      break;
    }
  } while (op <= 9);

  return 0;
}