// Übungsblatt 6
// Aufgabe 1
// Stephan Aures

#include <random>
#include <chrono>
#include <algorithm>
#include <iostream>
using namespace std;

#define SIZE 10
#define MAX 10

/*-----------------------------------------*/
void CountSort(unsigned int a[], int n, int k);

int main()
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,MAX);

    unsigned int a[SIZE];
    for (size_t i = 0; i < SIZE; i++)
    {
        a[i] = distribution(generator);
    }
    
    auto start = std::chrono::high_resolution_clock::now();

    cout << "Unsortiert: \n";
    for (size_t i = 0; i < SIZE; i++)
    {
        cout << a[i] << ", ";
    }cout << endl;

    CountSort(a, SIZE, MAX);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    cout << "Sortiert: \n";
    for (size_t i = 0; i < SIZE; i++)
    {
        cout << a[i] << ", ";
    }

    cout << endl << "Duration: " << duration.count() << " ns" << endl;
    
    return 0;
}

void CountSort(unsigned int a[], int n, int k)
{
    int i,j=1, max = 0, *bin = new int[k](), *tmp = new int[k]();

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        max = a[i];
    }

    for(i=0;i<n;i++) bin[a[i]]++;

    for (size_t i = 1; i <= max; i++)
    {
        bin[i] += bin[i-1];
    }

    for (int i = n - 1; i >= 0; i--) 
    {
        tmp[bin[a[i]] - 1] = a[i];
        bin[a[i]]--;
    }

    for (int i = 0; i < n; i++) 
    {
        a[i] = tmp[i];
    }

    delete [] bin, tmp;
}