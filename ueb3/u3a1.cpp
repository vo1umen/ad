// Übungsblatt 3
// Aufgabe 1
// Stephan Aures

#include <iostream>
#include <algorithm>
using namespace std;

/*-----------------------------------------*/

int MaxTeilSum_2d(int a[][4], int r);

int main()
{
    int a[3][4]=
    {
        {-13, 25, 45, 9},
        { 34, 12, -22, -18},
        {-77, 122, 53, 54}
    };

    cout << MaxTeilSum_2d(a, 3);


    return 0;
}


int MaxTeilSum_2d(int a[][4], int r)
{
    int sum;
    int max = 0;
    int SIZE = 4*r;
    int tmp[12] = {0};
    int h = 0;

    for (size_t i = 0; i < r; i++)
    {
        for (size_t k = 0; k < 4; k++)
        {
            tmp[h] = a[i][k];
            h++;
        }
    }
    
    for (size_t i = 0; i < r; i++)
    {
        sum=0;
        for (size_t j = i; j < 12; j++)
        {
            sum += tmp[j];
            if(sum > max) max = sum;
        }
    }
    return max;
}