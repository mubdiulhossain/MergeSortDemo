#include <iostream>
#include <cstdlib>
#include <random>
#include <chrono>
#include <cmath>
#include "MergeSort.h"
#include "windows.h"
//Hossain, Mohammad Mubdiul
using namespace std;

bool isSorted = false;
double timeTakenToSort = 0.0;

inline const char * const BoolToString(bool b);
int getInput(string text, int start, int end);
void printArray(MergeSort& mergeSort);
void generateArrays(MergeSort& mergeSort);
void PerformSort(MergeSort& mergeSort);
void findKthElement(MergeSort& mergeSort);
int main()
{
    MergeSort mergeSort;
    int input;
    string inputString;
    do
    {
        system("CLS");
        cout << "Merge Sort Menu" << endl;
        cout << endl;
        cout << "Current Size: " << mergeSort.getSize() <<endl;
        if(mergeSort.getSize()==0)
        {
            cout << "1. Generate numbers" << endl;
            cout << "2. Exit" << endl;
        }
        else
        {
            double byte = mergeSort.getMemorySize();
            double kilobyte = byte / 1024;
            double megabyte = kilobyte / 1024;

            if(byte>1048576)
            {
                cout << "Memory allocated size: "<< megabyte <<" MB" << endl;
            }
            else
            {
                if(byte>1024)
                {
                    cout << "Memory allocated size: "<< kilobyte <<" KB" << endl;
                }
                else
                {
                    cout << "Memory allocated size: "<< byte <<" bytes" << endl;
                }
            }
            cout << endl;
            if(isSorted)
            {
                cout << "Last Sorting duration: " <<timeTakenToSort<< "s"<<endl;
                cout << endl;
                cout <<"Smallest Number: "<< mergeSort.getArray()[0]<< endl;
                cout <<"Largest Number: "<< mergeSort.getArray()[mergeSort.getSize()-1]<< endl;
                cout << endl;
            }
            cout << "1. Generate numbers" << endl;
            cout << "2. Show "<<BoolToString(isSorted)<<" list of numbers " << endl;
            cout << "3. Sort list (Merge Sort)" << endl;
            cout << "4. Find K-th element" << endl;
            cout << "5. Empty List" << endl;
            cout << "6. Exit" << endl;
        }

        cout << endl;
        cout << "Enter number: ";
        cin >> inputString;
        if(mergeSort.getSize()==0)
        {
            input = getInput(inputString,1,2);
            if(input == 1)
            {
                generateArrays(mergeSort);
                isSorted = false;
            }
            else
            {
                if (input == 2)
                {
                    input = 2*3;
                }
            }
        }
        else
        {
            input = getInput(inputString,1,6);
            if(input == 1)
            {
                generateArrays(mergeSort);
                isSorted = false;
            }
            else
            {
                if (input == 2)
                {
                    printArray(mergeSort);
                }
                else
                {
                    if (input == 3)
                    {
                        PerformSort(mergeSort);
                    }
                    else
                    {
                        if(input==4)
                        {
                            findKthElement(mergeSort);
                        }
                        else
                        {
                            if(input==5)
                            {
                                mergeSort.generateArrays(0);
                                cout << "List Cleared..."<< endl;
                                system("PAUSE");
                            }
                        }
                    }
                }
            }
        }
    }
    while(input!=6);
    return 0;
}
inline const char * const BoolToString(bool b) // to convert boolean to text
{
    return b ? "sorted" : "unsorted";
}
int getInput(string text, int start, int end) //function to convert input text to int and check correct input
{
    int convert = atoi(text.c_str());
    if (convert == 0 || convert < start || convert > end)
    {
        cout << "Error Input! Enter correct number: ";
        cin >> text;
        return getInput(text,start,end);
    }
    else
    {
        return convert;
    }
}
void generateArrays(MergeSort& mergeSort) //generate random numbers
{
    int n=0;
    cout << "Enter Array Size: ";
    cin >> n;

    if(n<1 || n>100000000)
    {
        cout<<"Limit is 1-100000000(100 Million). ";
    }
    else
    {
        mergeSort.generateArrays(n);
        cout << "Number Generated. ";
    }
    system("PAUSE");
}
void printArray(MergeSort& mergeSort)
{
    if(mergeSort.getSize()==0)
    {
        cout << "List is empty ";
    }
    else
    {
        for (int i=0; i < mergeSort.getSize(); i++)
        {
            cout << mergeSort.getArray()[i]<<" ";
        }
        cout << endl;
    }
    system("PAUSE");
}
void PerformSort(MergeSort& mergeSort)
{
    if(mergeSort.getSize()==0)
    {
        cout << "List is empty ";
        isSorted = false;
    }
    else
    {
        auto start = chrono::system_clock::now();
        mergeSort.PerformMergeSort(mergeSort.getArray(), 0, mergeSort.getSize()-1);
        auto end = chrono::system_clock::now();
        chrono::duration<double> duration = end - start;
        timeTakenToSort = duration.count();
        isSorted = true;
        cout << "List is Sorted. Duration: "<< timeTakenToSort <<"s"<<endl;
    }
    system("PAUSE");
}
void findKthElement(MergeSort& mergeSort)
{
    if(mergeSort.getSize()==0)
    {
        cout << "List is empty ";
    }
    else
    {
        int k;
        cout<<"Enter K: ";
        cin>> k;

        if(k-1>mergeSort.getSize()||k-1<0)
        {
            cout << "List range is 1 - " << mergeSort.getSize() <<endl;
        }
        else
        {
            if(!isSorted)
            {
                cout<<"List is not sorted, Sorting..."<<endl;
                PerformSort(mergeSort);
            }
            int element = mergeSort.getArray()[k-1];
            cout << k <<" no. element is: "<<element<<endl;
        }
    }
    system("PAUSE");
}

