// Übungsblatt 9
// Aufgabe 3
// Stephan Aures

/*-----------------------------------------*/
#include <iostream>
#include<math.h>

#define size 11
using namespace std;

class hashtable
{
    int arr[size] = {};
    int collisions = 0;
public:
    hashtable(){}
    ~hashtable(){};

    int hashfunc(int val)
    {
        return val % size;
    }

    void linearprobing(int value)
    {
        int index = hashfunc(value);

        while(arr[index] != 0)
        {
            index++;
            if(index==size){
                index=0;
            }
            collisions++;
        }
        arr[index]=value;
    }

    void squareprobing(int value)
    {
        int col=0;
        int c1=1,c2=3;
        int index = hashfunc(value + col * c1 + c2 * pow(col,2));

        while(arr[index] != 0)
        {
            col++;
            collisions++;
            index = hashfunc(value + col * c1 + c2 * pow(col,2));
        }
        arr[index] = value;
    }

    void doublehashing(int value)
    {
        int col = 0;
        int h1 = value;
        int h2 = 1 + (value % (size - 1));
        int index = value % size;

        while(arr[index] != 0)
        {
            col++;
            collisions++;
            index = (h1 + col * h2) % size;
        }
        arr[index] = value;
    }

    void print()
    {
        for(auto &a : arr)
        {
            cout << "[ " << a << " ]" << endl;
        }
        cout << endl <<"Number of collisions: " << collisions;
    }
};

int main() 
{
    hashtable hash;
    int values[] = {10,22,31,4,15,28,17,88,59};

    int in;
    cout << "Choose probing:" << endl << "-----------------------------" << endl;
    cout <<"1 = linear probing" << endl; cout << "2 = square probing" << endl; cout << "3 = double hashing" << endl;
    cout << endl << endl;

    cin>>in;
    switch(in)
    {
        case 1: for(auto &a : values)
        {
            hash.linearprobing(a);
        }
        break;

        case 2: for(auto &a : values)
        {
            hash.squareprobing(a);
        }
        break;

        case 3: for(auto &a : values)
        {
            hash.doublehashing(a);
        }
        break;

        default: cout << "wrong input" << endl;
    }
    hash.print();
    return 0;
}
    /*
    1. Lineares Probieren 
    7 Kollisionen

    2. Quadratisches Probieren 
    14 Kollisionen

    3. Doppeltes Hashing mit h1(s) = s und h2(s) = 1 + (s mod (m − 1)) 
    7 Kollisionen
    */