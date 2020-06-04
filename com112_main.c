#include <stdio.h>
#include <stdlib.h>
#include "com112_file.h"
#include "com112_sort.h"
#include <stdbool.h>
#include <time.h>

void waiter()
{
    char str[50];
    while (1)
    {
        printf("\n\nDigite qualquer tecla e pressione enter para continuar!\n\n");
        scanf("%s", str);
        break;
    }
}

void relatorio(int var[], int tipo, int quantidade, double tempoBubble, int comparaBubble, int trocasBubble, double tempoSelection, int comparaSelection, int trocasSelection, double tempoInsertion, int comparaInsertion, int trocasInsertion, double tempoMerge, int comparaMerge, int trocasMerge, double tempoQuick, int comparaQuick, int trocasQuick)
{

    printf("Numero de elementos ordenados: %d\n", quantidade);
    printf("Metodo Bubble Sort               \n");
    printf("    Tempo de execucão: %f        \n", tempoBubble);
    printf("    Numero de comparacoes %d     \n", comparaBubble);
    printf("    Numero de movimentacoes: %d  \n", trocasBubble);
    printf("Metodo Selection Sort            \n");
    printf("    Tempo de execucão: %f        \n", tempoSelection);
    printf("    Numero de comparacoes %d     \n", comparaSelection);
    printf("    Numero de movimentacoes: %d  \n", trocasSelection);
    printf("Metodo Insertion Sort            \n");
    printf("    Tempo de execucão: %f        \n", tempoInsertion);
    printf("    Numero de comparacoes %d     \n", comparaInsertion);
    printf("    Numero de movimentacoes: %d  \n", trocasInsertion);
    printf("Metodo Merge Sort            \n");
    printf("    Tempo de execucão: %f        \n", tempoMerge);
    printf("    Numero de comparacoes %d     \n", comparaMerge);
    printf("    Numero de movimentacoes: %d  \n", trocasMerge);
    printf("Metodo Quick Sort            \n");
    printf("    Tempo de execucão: %f        \n", tempoQuick);
    printf("    Numero de comparacoes %d     \n", comparaQuick);
    printf("    Numero de movimentacoes: %d  \n", trocasQuick);

    escreverArquivoRelatorio(var, tipo, quantidade, tempoBubble, comparaBubble, trocasBubble, tempoSelection, comparaSelection, trocasSelection, tempoInsertion, comparaInsertion, trocasInsertion, tempoMerge, comparaMerge, trocasMerge, tempoQuick, comparaQuick, trocasQuick);
}

void showVector(int vet[])
{
    int i, quantidade = vet[0] + 1;
    for (i = 1; i < quantidade; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n\n\n");
}

double calculaTempo(double time1, double time2)
{
    return ((time2 - time1) / CLOCKS_PER_SEC);
}

void copiaVetor(int arr[], int vet1[], int vet2[], int vet3[], int vet4[], int vet5[], int quantidade)
{
    int i;
    for (i = 0; i < quantidade; i++)
    {
        vet1[i] = arr[i];
        vet2[i] = arr[i];
        vet3[i] = arr[i];
        vet4[i] = arr[i];
        vet5[i] = arr[i];
    }
}

int *menu(int vet[], int tipo, int quantidade)
{
    int op;
    int trocasSelection = 0, comparaSelection = 0;
    int trocasBubble = 0, comparaBubble = 0;
    int trocasInsertion = 0, comparaInsertion = 0;
    int trocasMerge = 0, comparaMerge = 0;
    int trocasQuick = 0, comparaQuick = 0;
    double tempoSelection, tempoBubble, tempoInsertion, tempoMerge, tempoQuick;
    double tempo1, tempo2;
    int *vetorBubble = malloc(quantidade * sizeof(int));
    int *vetorSelection = malloc(quantidade * sizeof(int));
    int *vetorInsertion = malloc(quantidade * sizeof(int));
    int *vetorMerge = malloc(quantidade * sizeof(int));
    int *vetorQuick = malloc(quantidade * sizeof(int));
    copiaVetor(vet, vetorBubble, vetorSelection, vetorInsertion, vetorMerge, vetorQuick, quantidade);
    while ((op != 1) && (op != 2) && (op != 3) && (op != 4) && (op != 5) && (op != 6))
    {
        printf("\e[H\e[2J");
        printf("\n\n\n\n\n");
        printf("                    ==========Metodos de ordenacao==========\n");
        printf("                    =         1 - Bubble Sort              =\n");
        printf("                    =         2 - Selection Sort           =\n");
        printf("                    =         3 - Insertion Sort           =\n");
        printf("                    =         4 - Merge Sort               =\n");
        printf("                    =         5 - Quick Sort               =\n");
        printf("                    =         6 - Relatorio                =\n");
        printf("                    ========================================\n");
        printf("\n");

        printf("              Entre com a opcao desejada (Digite o numero da opcao): ");

        scanf("%d", &op);

        switch (op)
        {
        case 1:
            tempo1 = clock();
            bubbleSort(vetorBubble, quantidade, &comparaBubble, &trocasBubble);
            tempo2 = clock();
            tempoBubble = calculaTempo(tempo1, tempo2);
            printf("\nVetor ordenado através do BubbleSort!\n");
            printf("\nquantidade = %d", quantidade);
            printf("\ncomparacao = %d", comparaBubble);
            printf("\ntroca = %d", trocasBubble);
            return vetorBubble;
            break;
        case 2:
            tempo1 = clock();
            selectionSort(vetorSelection, quantidade, &comparaSelection, &trocasSelection);
            tempo2 = clock();
            printf("\nVetor ordenado através do SelectionSort!\n");
            tempoSelection = calculaTempo(tempo1, tempo2);
            printf("\nquantidade = %d", quantidade);
            printf("\ncomparacao = %d", comparaSelection);
            printf("\ntroca = %d", trocasSelection);
            return vetorSelection;
            break;
        case 3:
            tempo1 = clock();
            insertionSort(vetorInsertion, quantidade, &comparaInsertion, &trocasInsertion);
            tempo2 = clock();
            printf("\nVetor ordenado através do InsertionSort!\n");
            tempoInsertion = calculaTempo(tempo1, tempo2);
            printf("\nquantidade = %d", quantidade);
            printf("\ncomparacao = %d", comparaInsertion);
            printf("\ntroca = %d", trocasInsertion);
            return vetorInsertion;
            break;
        case 4:
            tempo1 = clock();
            mergeSort(vetorMerge, 0, quantidade - 1, quantidade, &comparaMerge, &trocasMerge);
            tempo2 = clock();
            printf("\nVetor ordenado através do MergeSort!\n");
            tempoMerge = calculaTempo(tempo1, tempo2);
            printf("\nquantidade = %d", quantidade);
            printf("\ncomparacao = %d", comparaMerge);
            printf("\ntroca = %d", trocasMerge);
            return vetorMerge;
            break;
        case 5:
            tempo1 = clock();
            quickSort(vetorQuick, 0, quantidade - 1, &comparaQuick, &trocasQuick);
            tempo2 = clock();
            printf("\nVetor ordenado através do Quick Sort!\n");
            tempoQuick = calculaTempo(tempo1, tempo2);
            printf("\nquantidade = %d", quantidade);
            printf("\ncomparacao = %d", comparaQuick);
            printf("\ntroca = %d", trocasQuick);
            return vetorQuick;
            break;
        case 6:
            tempo1 = clock();
            bubbleSort(vetorBubble, quantidade, &comparaBubble, &trocasBubble);
            tempo2 = clock();
            tempoBubble = calculaTempo(tempo1, tempo2);

            // printf("\nquantidade = %d", quantidade);
            // printf("\ncomparacao = %d", comparaBubble);
            // printf("\ntroca = %d", trocasBubble);

            tempo1 = clock();
            selectionSort(vetorSelection, quantidade, &comparaSelection, &trocasSelection);
            tempo2 = clock();

            tempoSelection = calculaTempo(tempo1, tempo2);

            // printf("\nquantidade = %d", quantidade);
            // printf("\ncomparacao = %d", comparaSelection);
            // printf("\ntroca = %d", trocasSelection);

            tempo1 = clock();
            insertionSort(vetorInsertion, quantidade, &comparaInsertion, &trocasInsertion);
            tempo2 = clock();
            tempoInsertion = calculaTempo(tempo1, tempo2);

            // printf("\nquantidade = %d", quantidade);
            // printf("\ncomparacao = %d", comparaInsertion);
            // printf("\ntroca = %d", trocasInsertion);

            tempo1 = clock();
            mergeSort(vetorMerge, 0, quantidade - 1, quantidade, &comparaMerge, &trocasMerge);
            tempo2 = clock();
            tempoMerge = calculaTempo(tempo1, tempo2);

            // printf("\nquantidade = %d", quantidade);
            // printf("\ncomparacao = %d", comparaMerge);
            // printf("\ntroca = %d", trocasMerge);

            tempo1 = clock();
            quickSort(vetorQuick, 0, quantidade - 1, &comparaQuick, &trocasQuick);
            tempo2 = clock();
            tempoQuick = calculaTempo(tempo1, tempo2);

            // printf("\nquantidade = %d", quantidade);
            // printf("\ncomparacao = %d", comparaQuick);
            // printf("\ntroca = %d", trocasQuick);
            waiter();

            relatorio(vetorBubble, tipo, quantidade, tempoBubble, comparaBubble, trocasBubble, tempoSelection, comparaSelection, trocasSelection, tempoInsertion, comparaInsertion, trocasInsertion, tempoMerge, comparaMerge, trocasMerge, tempoQuick, comparaQuick, trocasQuick);

            break;
        }
    }
    return vetorBubble;
}

int main()
{
    int op, i, opOrd = 0, type = 0, quantidade;
    int *vetor;
    int cont = 0;
    while (op != 4)
    {
        printf("\e[H\e[2J");
        printf("\n\n\n\n\n");
        printf("                    ==========Metodos de ordenacao==========\n");
        printf("                    =                                      =\n");
        printf("                    =         1 - Metodos de Ordenacao     =\n");
        printf("                    =         2 - Gerar Numeros            =\n");
        printf("                    =         3 - Creditos                 =\n");
        printf("                    =         4 - Sair                     =\n");
        printf("                    =                                      =\n");
        printf("                    ========================================\n");
        printf("\n");

        printf("              Entre com a opcao desejada (Digite o numero da opcao): ");
        scanf("%d", &op);

        if (op == 1)
        {

            if (cont == 0)
            {
                vetor = lerArquivoEntrada(&quantidade);
                cont++;
            }
            int *result = menu(vetor, type, quantidade);

            printf("\n\n");
            abrirArquivoSaida(result, quantidade);
            waiter();
        }

        else if (op == 2)
        {
            while ((opOrd != 1) && (opOrd != 2) && (opOrd != 3))
            {
                printf("\e[H\e[2J");
                printf("\n\n\n\n\n");
                printf("                    ==============Gerar Numeros=============\n");
                printf("                    =                                      =\n");
                printf("                    =             1 - Crescente            =\n");
                printf("                    =             2 - Decrescente          =\n");
                printf("                    =             3 - Aleatório            =\n");
                printf("                    =                                      =\n");
                printf("                    ========================================\n");
                printf("\n");

                printf("              Entre com a opcao desejada (Digite o numero da opcao): ");
                scanf("%d", &opOrd);
            }

            int quant, i;
            int *vet;
            bool result_of_archive;
            printf("\e[H\e[2J");
            printf("Entre com a quant de numeros a serem gerados: ");
            scanf("%d", &quant);
            vet = malloc(quant * sizeof(vet));
            switch (opOrd)
            {
            case 1:
                for (i = 0; i < quant; i++)
                {
                    vet[i] = i; // troquei 1000 por quant, pois se colocar 1000 fica com muitos números repetidos
                }
                type = 1;
                printf("Numeros gerados de forma crescente:\n");
                break;
            case 2:
                for (i = 0; i <= quant - 1; i++)
                {
                    vet[i] = (quant - 1 - i);
                }
                type = 2;
                printf("Numeros gerados de forma decrescente:\n");
                break;
            case 3:
                for (i = 0; i < quant; i++)
                {
                    vet[i] = rand() % quant; // troquei 1000 por quant, pois se colocar 1000 fica com muitos números repetidos
                }
                type = 3;
                printf("Numeros gerados de forma aleatoria:\n");
                break;
            }

            opOrd = 0;
            for (i = 0; i < quant; i++)
            {
                printf("%d ", vet[i]);
            }
            printf("\n");

            abrirArquivoEntrada(vet, quant);

            waiter();
            free(vet);
            cont = 0;
        }
        else if (op == 3)
        {
            printf("\e[H\e[2J");
            printf("                    ==========Creditos======================\n");
            printf("                    =                                      =\n");
            printf("                    =                                      =\n");
            printf("                    =         Marcelo Magalhaes Silva      =\n");
            printf("                    =         2020004243                   =\n");
            printf("                    =         COM112                       =\n");
            printf("                    ========================================\n");
            waiter();
        }
    }

    return 0;
}