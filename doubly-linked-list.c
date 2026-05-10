#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct no
{
    int codigo;
    char nome[50];
    struct no *next, *back;
} no;

struct no *corrente, *auxiliar, *inicio, *fim, *auxiliar2;

void EnterData()
{
    printf("\n Informe o codigo: ");
    scanf("%d", &corrente->codigo);
    printf("\n Informe o nome...:  ");
    scanf("%s", corrente->nome);
}

void Inserir()
{
    if (inicio == NULL){
        corrente = (no*)malloc(sizeof(no));
        corrente->next = NULL;
        corrente->back = NULL;
        auxiliar = corrente;
        inicio = corrente;
        fim = corrente;
        EnterData();
    } else {
        auxiliar = fim;
        corrente = (no*)malloc(sizeof(no));
        auxiliar->next = corrente;
        corrente->back = auxiliar;
        auxiliar = corrente;
        corrente->next = NULL;
        fim = corrente;
        EnterData();
    }
}

void exibir()
{
    if(inicio == NULL)
    {
        printf("\n Lista Vazia \n");
        system("pause");
        return;
    }

    auxiliar = inicio;
    printf("\n ============ REGISTROS ============\n");
    while(auxiliar != NULL)
    {
        printf("\n Codigo ..: %d", auxiliar->codigo);
        printf("\n Nome ....: %s\n", auxiliar->nome);
        auxiliar = auxiliar->next;
    }
    printf(" ===================================\n");
    system("pause");
}

void consulta()
{
    int k = 0;
    int achou = 0;
    char busca[100];

    if (inicio == NULL){
        printf("\n Lista Vazia \n");
        system("pause");
        return;
    }

    printf("\n Informe o nome a ser consultado\n");
    scanf("%s", busca);
    achou = 0;
    auxiliar = fim;

    while (auxiliar != NULL){
        k++;
        if (strcmp(auxiliar->nome, busca)==0){
            printf("\n O Elemento na posicao %d", k);
            system("Pause");
            achou = 1;
            break;
        } else{
            auxiliar = auxiliar->back;
        }
    }
    if(achou == 0){
        printf("\n Elemento nao consta na lista");
        system("Pause");
    }
}

void deletar()
{
    int busca;
    int achou = 0;

    if(inicio == NULL)
    {
        printf("\n >>>>>>> Lista vazia <<<<<<<");
        system("pause");
        return;
    }

    printf("Insira o codigo do registro a ser deletado: ");
    fflush(stdin);
    scanf("%d", &busca);
    auxiliar = inicio;

    /* Remove o primeiro no */
    if(auxiliar->codigo == busca){
        inicio = inicio->next;
        free(auxiliar);
        if(inicio != NULL)
            inicio->back = NULL;
        else
            fim = NULL;
        achou = 1;
        printf("\nElemento removido com sucesso no inicio da lista");
        system("pause");
    } else {

        corrente = auxiliar;
        auxiliar = auxiliar->next;

        while(auxiliar != NULL){

            /* Remove no do meio */
            if(auxiliar->codigo == busca && auxiliar->next != NULL){
                corrente->next = auxiliar->next;
                corrente = corrente->next;
                corrente->back = auxiliar->back;
                free(auxiliar);
                achou = 1;
                printf("\nElemento removido com sucesso no meio da lista");
                system("pause");
                break;

            /* Remove o ultimo no */
            } else if(auxiliar->codigo == busca && auxiliar->next == NULL){
                fim = corrente;
                corrente->next = NULL;
                free(auxiliar);
                achou = 1;
                printf("\nElemento removido com sucesso no fim da lista");
                system("pause");
                break;

            } else {
                corrente = corrente->next;
                auxiliar = auxiliar->next;
            }
        }
    }

    if(achou == 0){
        printf("\nElemento nao encontrado!\n");
        system("pause");
    }
}

void class_dup()
{
    corrente = (no*)malloc(sizeof(no));
    EnterData();
    auxiliar = inicio;
    int achou = 0;

    if(inicio == NULL){
        fim = corrente;
        inicio = corrente;
        corrente->next = NULL;
        corrente->back = NULL;
        achou = 1;
        printf("\nPrimeiro elemento inserido!\n");
        system("pause");

    } else if(strcmp(corrente->nome, auxiliar->nome) < 0){
        corrente->next = auxiliar;
        auxiliar->back = corrente;
        corrente->back = NULL;
        inicio = corrente;
        achou = 1;
        printf("\n Elemento antecede o primeiro elemento da lista");
        system("pause");

    } else {
        auxiliar2 = auxiliar->next;
        while(auxiliar2 != NULL){
            if(strcmp(corrente->nome, auxiliar->nome) >= 0 && strcmp(corrente->nome, auxiliar2->nome) <= 0){
                auxiliar->next = corrente;
                corrente->next = auxiliar2;
                auxiliar2->back = corrente;
                corrente->back = auxiliar;
                achou = 1;
                printf("\n Elemento inserido com sucesso no meio da lista");
                system("pause");
                break;
            } else {
                auxiliar = auxiliar->next;
                auxiliar2 = auxiliar2->next;
            }
        }

        if(achou == 0){
            auxiliar = fim;
            auxiliar->next = corrente;
            corrente->back = auxiliar;
            corrente->next = NULL;
            fim = corrente;
            printf("\n Elemento inserido no fim da lista");
            system("pause");
        }
    }
}

int main()
{
    auxiliar  = NULL;
    auxiliar2 = NULL;
    corrente  = NULL;
    inicio    = NULL;
    fim       = NULL;

    int op;

    do
    {
        system("cls");

        printf("\n======================");
        printf("\n Estrutura de dados");
        printf("\n======================");

        printf("\n 1 - Inserir Dados");
        printf("\n 2 - Exibir Dados");
        printf("\n 3 - Consultar Dados");
        printf("\n 4 - Deletar Registro");
        printf("\n 5 - Inserir Ordenado");
        printf("\n 7 - Sair");

        printf("\n======================");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &op);
        getchar();

        switch(op)
        {
            case 1:
                Inserir();
                break;

            case 2:
                exibir();
                break;

            case 3:
                consulta();
                break;

            case 4:
                deletar();
                break;

            case 5:
                class_dup();
                break;

            case 7:
                printf("\n Saindo do sistema... \n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                system("pause");
        }

    } while(op != 7);

    return 0;
}
