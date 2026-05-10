#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{

    int codigo;
    char nome[50];
    struct no *next, *back;

}no;

struct no *topo, *corrente, *auxiliar;

void EnterData(){

    printf("\n Informe o codigo: ");
    scanf("%d", &corrente->codigo);

    printf("\n Informe o nome...: ");
    scanf("%s", corrente->nome);

}

void push(){

    corrente = (no*)malloc(sizeof(no));
    EnterData();

    if(topo == NULL){
        topo = corrente;
        auxiliar = corrente;
        corrente->back = NULL;
        corrente->next = NULL;

    }else{
        corrente->back = topo;
        topo->next = corrente;
        topo = corrente;
        topo->next = NULL;


    }

}

void pop(){

    if(topo == NULL){
        printf("Nao tem nenhum elemento na pilha");
    }else{

        auxiliar = topo;
        topo = topo->back;

        if(auxiliar->back == NULL){

            free(auxiliar);
            auxiliar=NULL;

        }else{

            topo->next = NULL;
            free(auxiliar);
            auxiliar = NULL;
        }

    }
    system("pause");

}

void top(){

    if(topo == NULL){
        printf("Nao tem nenhum elemento na pilha");
    }else{
        printf("\nCodigo do TOPO: %d", topo->codigo);
        printf("\nNome do TOPO: %s", topo->nome);

    }
    system("pause");

}

int main()
{
    auxiliar = NULL;
    corrente = NULL;
    topo = NULL;

    int op;

    do
    {
        system("cls");

        printf("\n======================");
        printf("\n Estrutura de dados - Pilha");
        printf("\n======================");

        printf("\n 1 - Push dados | Pilha");
        printf("\n 2 - Pop dados | Pilha");
        printf("\n 3 - Top dados | Pilha");
        printf("\n 0 - Sair");

        printf("\n======================");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &op);
        getchar();

        switch(op)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                top();
                break;

            case 0:
                printf("\n Saindo do sistema... \n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                system("pause");
        }

    } while(op != 0);

    return 0;
}
