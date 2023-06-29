typedef struct vizinho Vizinho;
typedef struct grafo Grafo;

Grafo *inicializaGrafo();
void imprime(Grafo *g);
void libera_vizinhos(Vizinho *v);
void libera(Grafo *g);
Grafo *busca_vertice(Grafo *g, int x);
Vizinho *busca_aresta(Grafo *g, int v1, int v2);
Grafo *insere_vertice(Grafo *g, int x);
void insere_um_sentido(Grafo *g, int v1, int v2);
void insere_aresta_digrafo(Grafo *g, int v1, int v2);
void insere_aresta(Grafo *g, int v1, int v2);
void retira_um_sentido(Grafo *g, int v1, int v2);
void retira_aresta(Grafo *g, int v1, int v2);
void retira_aresta_digrafo(Grafo *g, int v1, int v2);
void busca_largura(Grafo *g, int x);
//void busca_profundidade(Grafo *g, int valor);
void buscaProfundidade(Grafo *g, int valor);