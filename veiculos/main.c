#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex_veiculos.h"

void limpaBuffer() {
while(getchar() != '\n');
}

void menuInserir(Lista_veiculos *lista_veiculos){
    char marca[10];
    printf("\nDigite a marca a ser inserida: ");
    scanf("%s", marca);
    limpaBuffer();

    char placa[8];
    printf("\nDigite a placa a ser inserida: ");
    scanf("%s", placa);
    limpaBuffer();

    int ano;
    printf("\nDigite o ano do veiculo: ");
    scanf("%d", &ano);
    limpaBuffer();


    if(listaVazia(lista_veiculos)){
        inserirPrimeiroItem(lista_veiculos, marca, placa, ano);
    }
    else{
        int option;

            printf("\n1 - Inserir no inicio");
            printf("\n2 - Inserir no final");
            printf("\n3 - Inserir a partir de posicao: ");
            printf("\n4- Voltar");

            printf("\n Digite sua opção: ");
            scanf("%d", &option);

            switch (option)
            {
            case 1:
                inserirInicio(lista_veiculos, marca, placa, ano);
                break;
            case 2:
                inserirFinal(lista_veiculos, marca, placa, ano);
                break;
            case 3:
                int pos;
                printf("escolha posicao para alocar veiculo: ");
                scanf("%d", &pos);
                inserirPos(lista_veiculos, marca, placa, ano, pos);
                break;
            
            }
    }
}

int main()
{
    Lista_veiculos *lista_veiculos = criarListaEncadeada();


    int op;
    do
    {
        printf("\n1 - Inserir");
        printf("\n2 - Remover");
        printf("\n3 - Remover pela placa");
        printf("\n4 - Mostrar");
        printf("\n5 - Sair");

        printf("\n\nEscolha uma opcao: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            menuInserir(lista_veiculos);
            break;
        case 2:
            int pos;
            printf("\nescolha a posicao que deseja remover: ");
            scanf("%d",&pos);
            remover(lista_veiculos, pos);
            break;
        case 3:
            char placa[8];
            printf("digite a placa do veiculo que deseja remover: ");
            scanf("%s",placa);
            removerPlaca(lista_veiculos, placa);
            break;
        case 4:
            mostrar(lista_veiculos);
        default:
            break;
        }
    } while(op < 5);
    return 0;
} 