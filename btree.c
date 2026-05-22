#include<stdlib.h>
#include<stdio.h>

typedef struct nodo
{
    int codigo;
    char nome[50];
    struct nodo* next;   // Direita
    struct nodo* back;   // Esquerda
} nodo;

struct nodo *corrente, *auxiliar, *raiz;

void EnterData()
{
    printf("\n Informe o codigo: ");
    scanf("%d", &corrente->codigo);
    // REMOVIDO o '&' de corrente->nome
    printf(" Informe o nome...:  ");
    scanf("%49s", corrente->nome);
}


void btree_check(){
    int aloca = 0;
    while(aloca == 0){

        if(corrente->codigo > auxiliar->codigo){

            printf("\nFOI PARA DIREITA do nodo %d\n", auxiliar->codigo);

            if(auxiliar->next == NULL){
                auxiliar->next = corrente;
                printf("\nALOCADO A DIREITA do nodo %d\n", auxiliar->codigo);
                aloca = 1;
                system("pause");
            }else{
                auxiliar = auxiliar->next;
            }





        }else if(corrente->codigo < auxiliar->codigo){

           printf("\nFOI PARA ESQUERDA do nodo %d\n", auxiliar->codigo);


            if(auxiliar->back == NULL){
                auxiliar->back = corrente;
                printf("\nALOCADO A ESQUERDA do nodo %d\n", auxiliar->codigo);
                aloca = 1;
                system("pause");
            }else{
                auxiliar = auxiliar->back;
            }

        }else{

            printf("\nCHAVE DUPLICADA!");
            printf("\nInsira uma chave unica!\n");
            system("pause");
            break;

        }



    }




}

void Inserir()
{
    corrente = (nodo*)malloc(sizeof(nodo));
    corrente->next = NULL;
    corrente->back = NULL;

    EnterData();

    if(raiz == NULL)
    {
        raiz = corrente;
        auxiliar = corrente;
        printf("\nELEMENTO ALOCADO NA RAIZ!\n");
        system("pause");
    }
    else
    {
        auxiliar = raiz;
        btree_check();
    }
}

int main ()
{
    auxiliar = NULL;
    corrente = NULL;
    raiz = NULL;

    int op;

    do
    {
        system("cls"); // Se estiver no Linux/Mac, use system("clear");

        printf("\n======================================================");
        printf("\n Estrutura de dados - Arvore Multi-direcional");
        printf("\n======================================================");
        printf("\n 1 - Inserir");
        printf("\n 0 - Sair\n");
        printf("======================================================\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &op);
        getchar();

        switch (op)
        {
            case 1:
                Inserir();
                break;
            case 0:
                printf("\nSaindo do sistema...\n");
                break;
            default:
                printf("\nOpção invalida!\n");
                system("pause");
        }
    } while (op != 0);

    return 0;
}
