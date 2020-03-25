// Übungsblatt 1
// Aufgabe 3
// Stephan Aures

#include <iostream>
using namespace std;

/*-----------------------------------------*/

struct Matrix
{
    int a[2][2];
    int row = 2;
    int col = 2;
    int anz = 0;
};

void Init();
void Print();
void Input();
void Add(int M);
void Mult(int M);

Matrix m1;

int main()
{
    //Init();
    
    Input();
    Add(2);
    Print();
    Mult(2);
    Print();

    return 0;
}

void Init()
{
    for (size_t i = 0; i < m1.row; i++)
    {
        for (size_t k = 0; k < m1.col; k++)
        {
            m1.a[i][k] = 0;
        }  
    } 
}

void Print()
{
    for (size_t i = 0; i < m1.row; i++)
    {
        for (size_t k = 0; k < m1.col; k++)
        {
            cout << m1.a[i][k] << " ";
            if(k == m1.col-1)
            cout << endl;
        }  
    } 
}

void Input()
{
    for (size_t i = 0; i < m1.row; i++)
    {
        for (size_t k = 0; k < m1.col; k++)
        {
            cin >> m1.a[i][k];
        }  
    } 
}

void Add(int M)
{
    for (size_t i = 0; i < m1.row; i++)
    {
        for (size_t k = 0; k < m1.col; k++)
        {
            m1.a[i][k] += M;
        }  
    } 
}

void Mult(int M)
{
    for (size_t i = 0; i < m1.row; i++)
    {
        for (size_t k = 0; k < m1.col; k++)
        {
            m1.a[i][k] *= M;
        }  
    } 
}