// Übungsblatt 6
// Aufgabe 3
// Stephan Aures

#include <random>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

/*-----------------------------------------*/

void PrintQueue(queue <int> q);

int main()
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1,49);

    queue <int> lottozahlen;

    for (size_t i = 1; i <= 50; i++)
    {
        lottozahlen.push(distribution(generator));
    }

    PrintQueue(lottozahlen);
    
    
    return 0;
}

void PrintQueue(queue <int> qu)
{
    queue <int> q = qu;
    while (!q.empty())
    {
        cout << q.front() << ", ";
        qu.pop();
    } cout << endl; 
}