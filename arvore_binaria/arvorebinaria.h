typedef struct arvore Arvore;

Arvore *criarABB();
Arvore *inserir(int x, Arvore *p);
Arvore *remover(Arvore *r, int elemento);
void emordem(Arvore *p);
void preordem(Arvore *p);
void posordem(Arvore *p);
int contar(Arvore *p);

int maior(Arvore *p);
int menor(Arvore *p);
void localizarElem(Arvore *r, int elem);
//void contar(Arvore *p);

void teste(Arvore *raiz);