typedef struct no No;

typedef struct veiculo Veiculo;

typedef struct lista_veiculos Lista_veiculos;

Lista_veiculos* criarListaEncadeada();
void inserirPrimeiroItem(Lista_veiculos *lista, char marca[], char placa[], int ano);
void inserirInicio(Lista_veiculos *lista_veiculos, char marca[], char placa[], int ano);
void inserirFinal(Lista_veiculos *lista_veiculos, char marca[], char placa[], int ano);
void inserirPos(Lista_veiculos *Lista_veiculos, char marca[], char placa[], int ano, int pos);
void remover (Lista_veiculos *lista, int pos);
void removerPlaca(Lista_veiculos *lista_veiculos, char placa[8]);
void mostrar (Lista_veiculos *lista);
int listaVazia(Lista_veiculos *lista);