#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "com112_file.h"
void abrirArquivoEntrada(int var[], int quantidade)
{
    FILE *arquivo;
    int i;
    arquivo = fopen("com112_entrada.txt", "wt");

    if (arquivo == NULL)
    {
        printf("ERRO AO ABRIR ARQUIVO!");
    }
    else
    {

        fprintf(arquivo, "%d\n", quantidade);
        for (i = 0; i < quantidade; i++)
        {
            fprintf(arquivo, "%d ", var[i]);
        }

        fclose(arquivo);
    }
}

void abrirArquivoSaida(int var[], int quantidade)
{
    FILE *arquivo;
    int i;
    arquivo = fopen("com112_saida.txt", "wt");

    if (arquivo == NULL)
    {
        printf("ERRO AO ABRIR ARQUIVO!");
    }
    else
    {

        fprintf(arquivo, "%d\n", quantidade);
        for (i = 1; i < quantidade + 1; i++)
        {
            fprintf(arquivo, "%d ", var[i]);
        }

        fclose(arquivo);
    }
}

int *lerArquivoEntrada(int *quant)
{
    FILE *arquivo;
    char *result;
    int *vet;
    arquivo = fopen("com112_entrada.txt", "rt");

    if (arquivo == NULL)
    {
        printf("ERRO AO ABRIR ARQUIVO!");
        fclose(arquivo);
        return NULL;
    }
    else
    {
        int cont = 0, quantidade, i;
        printf("Arquivo aberto com sucesso!\n");
        while (!feof(arquivo))
        {

            if (cont == 0)
            {
                //Lê a primeira linha do arquivo para verificar quantos números são
                fscanf(arquivo, "%d", &quantidade);
                cont++;
                //Aloca a quantidade de posições necessárias
                vet = malloc((quantidade) * sizeof(int));
                *quant = quantidade;
            }
            else
            {

                for (i = 0; i < quantidade; i++)
                {
                    //Lê cada número individualmente e guarda no vetor
                    fscanf(arquivo, "%d", &vet[i]);
                }
            }
        }
        fclose(arquivo);
        return vet;
    }
}

void escreverArquivoRelatorio(int var[],int tipo,int quantidade,double tempoBubble,int comparaBubble,int trocasBubble,double tempoSelection,int comparaSelection,int trocasSelection,double tempoInsertion,int comparaInsertion,int trocasInsertion,double tempoMerge,int comparaMerge,int trocasMerge,double tempoQuick,int comparaQuick,int trocasQuick)
{
    FILE *arquivo;
    int i;
    if (tipo == 1)
    {
        arquivo = fopen("com112_relatorio_crescente.txt", "wt");
    }
    else if (tipo == 2)
    {
        arquivo = fopen("com112_relatorio_decrescente.txt", "wt");
    }
    else if (tipo == 3)
    {
        arquivo = fopen("com112_relatorio_aleatorio.txt", "wt");
    }

    if (arquivo == NULL)
    {
        printf("ERRO AO ABRIR ARQUIVO!");
    }
    else
    {

        int q = var[0];
        fprintf(arquivo,"Numero de elementos ordenados: %d\n", quantidade);
        fprintf(arquivo,"Metodo Bubble Sort               \n");
        fprintf(arquivo,"    Tempo de execucão: %f        \n", tempoBubble);
        fprintf(arquivo,"    Numero de comparacoes %d     \n", comparaBubble);
        fprintf(arquivo,"    Numero de movimentacoes: %d  \n", trocasBubble);
        fprintf(arquivo,"Metodo Selection Sort            \n");
        fprintf(arquivo,"    Tempo de execucão: %f        \n", tempoSelection);
        fprintf(arquivo,"    Numero de comparacoes %d     \n", comparaSelection);
        fprintf(arquivo,"    Numero de movimentacoes: %d  \n", trocasSelection);
        fprintf(arquivo,"Metodo Insertion Sort            \n");
        fprintf(arquivo,"    Tempo de execucão: %f        \n", tempoInsertion);
        fprintf(arquivo,"    Numero de comparacoes %d     \n", comparaInsertion);
        fprintf(arquivo,"    Numero de movimentacoes: %d  \n", trocasInsertion);
        fprintf(arquivo,"Metodo Merge Sort            \n");
        fprintf(arquivo,"    Tempo de execucão: %f        \n", tempoMerge);
        fprintf(arquivo,"    Numero de comparacoes %d     \n", comparaMerge);
        fprintf(arquivo,"    Numero de movimentacoes: %d  \n", trocasMerge);
        fprintf(arquivo,"Metodo Quick Sort            \n");
        fprintf(arquivo,"    Tempo de execucão: %f        \n", tempoQuick);
        fprintf(arquivo,"    Numero de comparacoes %d     \n", comparaQuick);
        fprintf(arquivo,"    Numero de movimentacoes: %d  \n", trocasQuick);

        fclose(arquivo);
    }
}

void lerArquivoRelatorio()
{
    FILE *arquivo;
    char *result;
    arquivo = fopen("com112_relatorio.txt", "rt");

    if (arquivo == NULL)
    {
        printf("ERRO AO ABRIR ARQUIVO!");
        fclose(arquivo);
    }
    else
    {

        size_t t = 50;
        char *linha = malloc(t);
        printf("Arquivo aberto com sucesso!\n");
        while (!feof(arquivo))
        {
            getline(&linha, &t, arquivo);
            printf("%s", linha);
        }
    }
    fclose(arquivo);
}