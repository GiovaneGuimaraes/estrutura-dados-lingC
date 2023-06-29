#include <stdio.h>
#include <stdlib.h>
#include "arvorebinaria.h"

struct arvore
{
  int valor;
  Arvore *esq;
  Arvore *dir;
};

Arvore *criarABB()
{
  return NULL;
}

Arvore *inserir(int x, Arvore *p)
{
  if (p == NULL)
  {
    p = (Arvore *)malloc(sizeof(Arvore));
    p->valor = x;
    p->dir = NULL;
    p->esq = NULL;
  }
  else
  {
    if (x < p->valor)
      p->esq = inserir(x, p->esq);
    if (x > p->valor)
      p->dir = inserir(x, p->dir);
    if (x == p->valor)
      printf("Valor já existe");
  }
  return p;
}

Arvore *remover(Arvore *r, int elemento)
{
  
  if (r == NULL)
    return r;

  else if (elemento > r->valor)
    r->dir = remover(r->dir, elemento);
  else if (elemento < r->valor)
    r->esq = remover(r->esq, elemento);
  else
  {
    if (r->esq == NULL && r->dir == NULL)
    {
      free(r);
      r = NULL;
    }
    else if (r->esq == NULL)
    {
      Arvore *p = r->dir;
      free(r);
      return p;
    }
    else if (r->dir == NULL)
    {
      Arvore *p = r->esq;
      free(r);
      return p;
    }
    else
    { //procura o menor valor da sub-árvore da dir
      Arvore *p = r->dir;
      while (p->esq)
        p = p->esq;
     
      r->valor = p->valor; 
      r->dir = remover(r->dir,p->valor);
 
    }
  }

  return r;
}

void emordem(Arvore *p)
{
  if (p != NULL)
  {
    emordem(p->esq);
    printf("%d ", p->valor);
    emordem(p->dir);
  }
}

void preordem(Arvore *p)
{

  if (p != NULL)
  {
    printf("%d ", p->valor);
    preordem(p->esq);
    preordem(p->dir);
  }
}

void posordem(Arvore *p)
{
  if (p != NULL)
  {
    posordem(p->esq);
    posordem(p->dir);
    printf("%d ", p->valor);
  }
}

int contar(Arvore *p)
{
  if (p == NULL)
    return 0;
  else
    return 1 + contar(p->esq) + contar(p->dir);
}

int maior(Arvore *p)
{
  if (p == NULL)
  {
    printf("A árvore está vazia.");
    return -1;
  }
  else
  {
    while (p->dir != NULL)
      p = p->dir;

    printf("\nO maior elemento da arvore é: %d", p->valor);
  }
}

int menor(Arvore *p){
  if (p == NULL)
  {
    printf("A árvore está vazia.");
    return -1;
  }
  else
  {
    while (p->esq != NULL)
      p = p->esq;

    printf("\nO menor elemento da arvore é: %d", p->valor);
  }  
}

void localizarElem(Arvore *r, int elem){

  if (r == NULL){
    printf("O elemento nao existe\n");
    return;
  }

  if(r->valor == elem){
    printf("numero na arvore: %d\n", r->valor);
    //verificar se tem filhos
    if(r->esq != NULL){
      printf("filho a esquerda: %d\n", r->esq->valor);
    } else{
      printf("nao a filho a esquerda!\n");
    }
    if(r->dir != NULL){
      printf("filho a direita: %d\n", r->dir->valor);
    } else{
      printf("nao a filho a direita!\n");
    }
    return;
  }

  if(elem < r->valor){
    localizarElem(r->esq, elem);
  } else{
    localizarElem(r->dir, elem);
  }
}

void teste(Arvore *raiz){
  Arvore *aux;
  Arvore *aux2;

  aux = raiz -> dir -> dir;
  aux -> esq = NULL;
  aux2 = raiz;
  while (aux2 -> esq -> esq != NULL)
  aux2 = aux2 -> esq;
  aux2 -> dir = NULL;

  printf("\nfeito\n");

}

// void contar(Arvore *p)
// {
//   int conta = 0;
//   while(p != NULL)
//   {
//     contar(p->esq);
//     //printf("%d ", p->valor);
//     conta++;
//     contar(p->dir);
//   }
//   printf("A arvore tem %d elementos!\n",conta);
// }