#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct no
{
    int codigo;
    char nome[50];
    int index;
    struct no* next;
} no;

struct no *corrente, *auxiliar, *fim, *inicio;

int i = 0;

void EnterData()
{

    printf("\n Informe o codigo: ");
    scanf("%d", &fim->codigo);

    printf("\n Informe o nome...: ");
    scanf("%s", fim->nome);

    fim->index = i;
    i++;
}
 int c = 0;
void enqueue()
{

    if(inicio == NULL){ //Lista está vazia, primeiro elemento a ser inserido

        fim = (no*)malloc(sizeof(no));
        EnterData();

        auxiliar = fim;
        inicio = fim;

        fim->next = NULL;
        c++;

        printf("\nInserido o primeiro elemento na Fila\n");
        system("pause");

    }else if(c > 5){

        printf("\nQueue is full...");
        system("pause");

    }else{

        fim = (no*)malloc(sizeof(no));
        EnterData();

        auxiliar->next = fim;
        auxiliar=fim;
        fim->next = NULL;
        c++;
        printf("\nInsreido com Sucesso elemento na FILA\n");
        system("pause");

    }

}

void dequeue(){

    if(inicio == NULL){
        printf("\nNenhum Elemento na Fila\n");
        system("pause");
        return;
    }else{

        auxiliar = inicio;
        inicio = inicio->next;
        free(auxiliar);
        c--;

        printf("\nElemento excluido do comeco da FILA\n");
        system("pause");


    }

}

void seaqueue(){


    if(inicio == NULL){
        printf("\nNenhum Elemento na Fila\n");
        system("pause");
        return;
    }else{

        int iCodigo, achou =0;

        printf("Pesquise a posicao do Elemento da lista: ");
        scanf("%i", &iCodigo);

        auxiliar = inicio;

        while(auxiliar != NULL){

            if(auxiliar->codigo == iCodigo){
                printf("\nO No de codigo: %i esta na posicao: %i",auxiliar->codigo,auxiliar->index);
                achou=1;
                system("pause");
            }
            auxiliar=auxiliar->next;

        }

        if(achou == 0){
            printf("\nNao existe elementos com esse codigo\n");
            system("pause");
        }
    }
}



int main()
{
    auxiliar = NULL;
    corrente = NULL;
    inicio = NULL;
    fim = NULL;

    int op;

    do
    {
        system("cls");

        printf("\n======================");
        printf("\n Estrutura de dados - Fila");
        printf("\n======================");

        printf("\n 1 - Inserir Dados - Enqueue");
        printf("\n 2 - Remove Dados- Dequeue");
        printf("\n 3 - Pesquisar Posicao do elemento - Seaqueue");
        printf("\n 0 - Sair");

        printf("\n======================");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &op);
        getchar();

        switch(op)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                seaqueue();
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
