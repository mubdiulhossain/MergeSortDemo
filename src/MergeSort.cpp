#include "MergeSort.h"
#include <random>
#include <chrono>
MergeSort::MergeSort()
{
    arrays = nullptr;
    arraySize = 0;
    memorySize = 0;
}

MergeSort::~MergeSort()
{
    delete arrays;
}
void MergeSort::PerformMergeSort(unsigned long int a[], int p, int r)
{
    if (p < r)
    {
        int m = p+(r-p)/2;

        PerformMergeSort(a, p, m);
        PerformMergeSort(a, m+1, r);

        Merge(a, p, m, r);
    }
}
void MergeSort::Merge(unsigned long int a[], int p, int m, int r)
{
    int i, j, k;
    int n1 = m - p + 1;
    int n2 =  r - m;

    unsigned long int *L = (unsigned long int*) malloc(n1*sizeof(unsigned long int));
    unsigned long int *R = (unsigned long int*) malloc(n2*sizeof(unsigned long int));

    for (i = 0; i < n1; i++)
    {
        L[i] = a[p + i];
    }
    for (j = 0; j < n2; j++)
    {
         R[j] = a[m + 1+ j];
    }
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);

}
void MergeSort::generateArrays(int arraySize)
{
    free(arrays);
    arrays = (unsigned long int*) malloc(arraySize * sizeof(unsigned long int));
    std::random_device rd;
    srand (time(0));
    static std::mt19937 gen(rand() % RAND_MAX);
    std::uniform_int_distribution<> distribution(1, 100000000);
    for (int i = 0; i < arraySize; i++)
    {
        arrays[i] = distribution(gen);
    }
    this->arraySize = arraySize;
    this->memorySize = arraySize * sizeof(unsigned long int);
}
unsigned long int* MergeSort::getArray()
{
    return arrays;
}
double MergeSort::getMemorySize()
{
    return memorySize;
}
int MergeSort::getSize()
{
    return arraySize;
}
