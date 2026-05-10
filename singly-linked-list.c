#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct no
{
    int codigo;
    char nome[50];
    struct no* next;
} no;

struct no *corrente, *auxiliar, *auxiliar2, *inicio;

void EnterData()
{
    printf("\n Informe o codigo: ");
    scanf("%d", &corrente->codigo);

    printf("\n Informe o nome...: ");
    scanf("%s", corrente->nome);
}

void Inserir()
{
    int achou = 0;

    corrente = (no*)malloc(sizeof(no));
    EnterData();
    auxiliar = inicio;


    if(corrente == NULL){
        printf("Erro de memoria\n");
        return;
    }

    if(inicio == NULL){ //Lista está vazia, primeiro elemento a ser inserido

        auxiliar = corrente;
        inicio = corrente;

        corrente->next = NULL;
        achou = 1;

        printf("\nInstalado o primeiro No na memoria\n");
        system("pause");

    }else if(strcmp(corrente->nome, auxiliar->nome) < 0){ //Usamos o strcmp para encadear os Nós em ordem alfabética, de acordo com o < 0 (tabela ASCII)

        corrente->next = auxiliar;
        inicio = corrente;

        achou = 1;
        printf("\nO Elemento precede o primeiro elemento da lista\n");
        system("pause");
    }else {
        //Aqui usamos o auxiliar2 para encadear no meio, caso o No que queremos encadear agora, for "maior" que o de trás (auxiliar) e "menor" que o da frente
        //(auxiliar2) nós encadeamos entre o aux1 e 2
        auxiliar2 = auxiliar->next;
        while(auxiliar2 != NULL){
            if(strcmp(corrente->nome, auxiliar->nome)>=0 && strcmp(corrente->nome, auxiliar2->nome) < 0){
                auxiliar->next = corrente;
                corrente->next = auxiliar2;
                achou = 1;
                printf("\nInserido com sucesso no meio na lista\n");
                system("pause");
                break;
            } else {
                auxiliar = auxiliar->next;
                auxiliar2 = auxiliar2->next;
            }
        }
    }
    if(achou == 0 && strcmp(corrente->nome, auxiliar->nome)>=0)
    {
        //caso ele não entre em nenhuma condição la em cima, quer dizer que ele não é "menor" que nenhum, logo deve ir por ultimo
        auxiliar->next = corrente;
        corrente->next = NULL;
        printf("\nElemento inserido no final da lista\n");
        system("pause");
    }

}

void consulta()
{
    if(inicio == NULL)
    {
        printf("\nSem cadastro na lista\n");
        system("pause");
    }
    else
    {
        auxiliar = inicio;
        //Usamos esse while para correr toda a lista simplesmente encadeada, mostrando todos os registros
        while(auxiliar != NULL)
        {
            printf("\n Codigo ..: %d", auxiliar->codigo);
            printf("\n Nome ....: %s\n", auxiliar->nome);

            auxiliar = auxiliar->next; //essa linha é o que está andando
        }

        system("pause");
    }
}

void pesquisa() //Mesma lógica do consultar, mas printamos apenas se a pesquisa corresponder
{
    if(inicio == NULL)
    {
        printf("\nSem cadastro na lista\n");
        system("pause");
    }
    else
    {
        int codigoPesquisa;

        printf("\nInsira o codigo a ser pesquisado: ");
        scanf("%d", &codigoPesquisa);

        auxiliar = inicio;

        while(auxiliar != NULL)
        {
            if(codigoPesquisa == auxiliar->codigo)
            {
                printf("\n Codigo ..: %d", auxiliar->codigo);
                printf("\n Nome ....: %s\n", auxiliar->nome);
                break;
            }

            auxiliar = auxiliar->next;
        }

        if(auxiliar == NULL)
        {
            printf("\nRegistro nao encontrado!\n");
        }

        system("pause");
    }
}


void deletar()
{
    if(inicio == NULL)
    {
        printf("\n >>>>>>> Lista vazia <<<<<<<\n");
        system("pause");
    }
    else
    {
        int codigoDeleta;

        printf("\nInsira o codigo do registro a ser deletado: ");
        scanf("%d", &codigoDeleta);

        corrente = inicio;
        auxiliar = inicio;

        while(auxiliar != NULL)
        {
            if(codigoDeleta == auxiliar->codigo)
            {
                if(auxiliar == corrente)
                {
                    inicio = auxiliar->next;
                }
                else
                {
                    corrente->next = auxiliar->next;
                }

                printf("\n Codigo %d removido\n", auxiliar->codigo);

                free(auxiliar);
                break;
            }
            else if(auxiliar != corrente)
            {
                corrente = corrente->next;
                auxiliar = auxiliar->next;
            }
            else
            {
                auxiliar = auxiliar->next;
            }
        }

        if(auxiliar == NULL)
        {
            printf("\nRegistro nao encontrado!\n");
        }

        system("pause");
    }
}

void atualizar()
{
    if(inicio == NULL)
    {
        printf("\nSem cadastro na lista");
        system("pause");
    }
    else
    {
        int codigoAtualizar;

        printf("\nInsira o codigo do registro a ser atualizado: ");
        scanf("%d", &codigoAtualizar);

        auxiliar = inicio;

        while(auxiliar != NULL)
        {
            if(codigoAtualizar == auxiliar->codigo)
            {
                printf("\nRegistro encontrado!\n");

                printf("\nNovo codigo: ");
                scanf("%d", &auxiliar->codigo);

                printf("\nNovo nome: ");
                scanf("%s", auxiliar->nome);

                printf("\nRegistro atualizado com sucesso!\n");
                break;
            }

            auxiliar = auxiliar->next;
        }

        if(auxiliar == NULL)
        {
            printf("\nRegistro nao encontrado!\n");
        }

        system("pause");
    }
}

int main()
{
    auxiliar = NULL;
    corrente = NULL;
    inicio = NULL;

    int op;

    do
    {
        system("cls");

        printf("\n======================");
        printf("\n Estrutura de dados");
        printf("\n======================");

        printf("\n 1 - Inserir Dados");
        printf("\n 2 - Consultar Dados");
        printf("\n 3 - Pesquisar Codigo");
        printf("\n 4 - Deletar Registro");
        printf("\n 5 - Atualizar Registro");
        printf("\n 0 - Sair");

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
                consulta();
                break;

            case 3:
                pesquisa();
                break;

            case 4:
                deletar();
                break;

            case 5:
                atualizar();
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
