// Übungsblatt 3
// Aufgabe 4
// Stephan Aures

#include <random>
#include <chrono>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 160000

/*-----------------------------------------*/
void BubbleSortMax(unsigned int a[]);

int main()
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,1000000);

    unsigned int a[MAX];
    for (size_t i = 0; i < MAX; i++)
    {
        a[i] = distribution(generator);
    }
    
    auto start = std::chrono::high_resolution_clock::now();
    BubbleSortMax(a);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
/*
    for (size_t i = 0; i < MAX; i++)
    {
        cout << a[i] << ", ";
    }
*/
    cout << endl << "Duration: " << duration.count() << " s" << endl;
    
    return 0;
}

void BubbleSortMax(unsigned int a[])
{
    for (size_t i = 0; i < MAX-1; i++)
    {
        for (size_t k = 0; k < MAX-i-1; k++)
        {
            if(a[k] > a[k+1])
            {
                unsigned int tmp = a[k];
                a[k] = a[k+1];
                a[k+1] = tmp;
            }
        }
    }
}