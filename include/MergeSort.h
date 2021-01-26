#ifndef MERGESORT_H
#define MERGESORT_H
//Hossain, Mohammad Mubdiul
//1161303847

class MergeSort
{
    private:
        unsigned long int* arrays;
        int arraySize;
        double memorySize;
        void Merge(unsigned long int a[], int p, int m, int r);
    public:
        MergeSort();
        void PerformMergeSort(unsigned long int a[], int p, int r);
        void generateArrays(int arraySize);
        double getMemorySize();
        unsigned long int* getArray();
        int getSize();
        virtual ~MergeSort();
};

#endif // MERGESORT_H
