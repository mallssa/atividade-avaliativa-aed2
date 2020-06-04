#include<stdbool.h>
#ifndef COM112_FILE_H
#define COM112_FILE_H

void abrirArquivoEntrada(int var[],int quantidade);
int* lerArquivoEntrada(int* quant);
void abrirArquivoSaida(int var[],int quantidade);
void escreverArquivoRelatorio(int var[],int tipo,int quantidade,double tempoBubble,int comparaBubble,int trocasBubble,double tempoSelection,int comparaSelection,int trocasSelection,double tempoInsertion,int comparaInsertion,int trocasInsertion,double tempoMerge,int comparaMerge,int trocasMerge,double tempoQuick,int comparaQuick,int trocasQuick);
void lerArquivoRelatorio();

#endif