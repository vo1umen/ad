// Übungsblatt 3
// Aufgabe 3
// Stephan Aures

#include <iostream>
#include <algorithm>
using namespace std;

/*-----------------------------------------*/
void InsertionSort(int a[], int n);
void InsertionSortMin(int a[], int n);
void BubbleSortMax(int a[], int n);
void SelectSortMax(int a[], int n);

int main()
{
    int a[] = {34, 45, 12, 34, 23, 18, 38, 17, 43, 51};
    int n = sizeof(a)/sizeof(a[0]);

    SelectSortMax(a, n);

    for (size_t i = 0; i < n; i++)
    {
        cout << a[i] << ", ";
    }
    

    return 0;
}

void InsertionSortMin(int a[], int n)
{
     int i, j, key;

     for (size_t j = n-1; j > 0; j--)
     {
         key = a[j-1];
         i = j;
         while (i <= n && a[i] < key)
         {
             a[i-1] = a[i];
             i = i+1;
         }
         a[i-1] = key;
     }
     
}

void BubbleSortMax(int a[], int n)
{
    for (size_t i = 0; i < n-1; i++)
    {
        for (size_t k = 0; k < n-i-1; k++)
        {
            if(a[k] > a[k+1])
            {
                int tmp = a[k];
                a[k] = a[k+1];
                a[k+1] = tmp;
            }
        }
    }
}

void SelectSortMax(int a[], int n)
{
    int max = 0;

    for (size_t i = n-1; i > 0; i--)
    {
        max = i;
        for (size_t k = 0; k < i; k++)
        {
            if(a[k] > a[max]) max = k;
        }
        int tmp = a[i];
        a[i] = a[max];
        a[max] = tmp;
    }
}