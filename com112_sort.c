#include <stdio.h>
#include <math.h>
void bubbleSort(int arr[],int n,int* compara,int* trocas)
{
    int i, j;
    printf("Unsorted Array: ");
    for(i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    for (i = 0; i < n ; i++){

        // Os últimos i elementos estão no lugar certo
        for (j = 0; j < n - i - 1; j++)
        {
            
            (*compara)++;
            if (arr[j] > arr[j + 1])
            {
                int aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
                (*trocas)++;
            }
        }
    }
}

void selectionSort(int arr[],int n,int* compara,int* trocas)
{
    int i, j, min_idx,aux;
    // Move um item por vez
    for (i = 0; i < n-1; i++)
    {
        // Acha o menor elemento no array desordenado
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            (*compara)++;
            if (arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }

        // Troca o minimo elemento encontrado pra posicao correta
        if (min_idx != i)
        {
            (*trocas)++;
            aux = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = aux;
        }
    }

    
}

void insertionSort(int arr[],int n,int* compara,int* trocas)
{
    int i, key, j;

    for (i = 1; i < n; i++)
    {

        
        j = i ;

        (*compara)++;
        while (j > 0 && arr[j-1] > arr[j])
        {
            key = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = key;
            j--;

            (*compara)++;
            (*trocas)++;
        }
        
    }
}

void merge(int arr[], int l, int m, int r,int quantidade,int* compara,int* trocas)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    //Cria arrays temporarios
    int L[n1], R[n2];

    //Copia as informacoes do array para os respectivos vetor L[] e R[] para fazer a junção
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
        (*trocas)++;
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
        (*trocas)++;
    }

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Indice inicial do primeiro subarray
    j = 0; // Indice inicial do segundo subarray
    k = l; // Indice inicial do array misturado

    while (i < n1 && j < n2)
    {
        (*compara)++;
        if (L[i] <= R[j])
        {
            (*trocas)++;
            arr[k] = L[i];
            i++;
        }
        else
        {
            (*trocas)++;
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copia os elementos restantes de L[] se existir */
    while (i < n1)
    {
        (*trocas)++;
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copia os elementos restantes de R[] se existir */
    while (j < n2)
    {
        (*trocas)++;
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right,int quantidade,int* compara,int* trocas)
{
    if (left < right)
    {

        int middle = left + (right - left) / 2;

        // Ordena a primeira e segunda metade
        mergeSort(arr, left, middle,quantidade,compara,trocas);
        mergeSort(arr, middle + 1, right,quantidade,compara,trocas);

        merge(arr, left, middle, right,quantidade,compara,trocas);
    }
    
}

/* esta função considera o primeiro elemento como pivô (André Backes)
os dados estatísticos estão corretos */
int particiona(int *vet, int inicio, int fim, int *comp, int *mov)
{
    int esq, dir, pivo, aux;

    esq = inicio;
    dir = fim;

    pivo = vet[inicio];

    while (esq < dir)
    {
        while (vet[esq] <= pivo)
        { // comentei e deixei como no livro
            esq++;
            (*comp) += 1;
        }

        while (vet[dir] > pivo)
        { // comentei e deixei como no livro
            dir--;
            (*comp) += 1;
        }

        if (esq < dir)
        {
            aux = vet[esq];
            vet[esq] = vet[dir];
            vet[dir] = aux;

            (*mov) += 1;
        }
    }

    if (inicio != dir)
    { // adicionei esse if, pois estava trocando um elemento com ele mesmo
        vet[inicio] = vet[dir];
        (*mov) +=1;
    }

    if (vet[dir] != pivo)
    { // adicionei esse if, pois estava trocando um elemento com ele mesmo
        vet[dir] = pivo;
        (*mov) += 1;
    }

    return dir;
}


void quickSort(int arr[], int low, int high,int* compara,int* trocas)
{
    if (low < high)
    {
        
        //pi é apenas um indíce de particionamento, o lemento da posicão pi está no lugar certo
        int pi = particiona(arr, low, high,compara, trocas);

        //Separadamente o algoritmo ordena os elementos de antes da partição e de depois
        quickSort(arr, low, pi - 1,compara,trocas);
        quickSort(arr, pi + 1, high,compara,trocas);
    }
    
}