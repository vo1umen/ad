// Übungsblatt 1
// Aufgabe 2
// Stephan Aures

#include <iostream>
#include <cmath>
using namespace std;

/*-----------------------------------------*/

int main()
{
    const size_t N = 100000;
    bool prim[N+1];
    prim[0] = false;
    prim[1] = false;

    
    for (size_t i = 2; i < N; i++)
    {
        prim[i] = true;
    }
    
    
    for (size_t i = 2; i <= N/2; i++)
    {
        for (size_t k = 2; k <= N/i; k++)
        {
            prim[i*k] = false;
        }
        
    }

    for (size_t i = 0; i < N; i++)
    {
        if (prim[i])
        {
            cout << i << ", ";
        }
        
    }
    

    return 0;
}