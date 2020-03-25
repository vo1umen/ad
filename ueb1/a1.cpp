// Übungsblatt 1
// Aufgabe 1
// Stephan Aures

#include <iostream>
using namespace std;

/*-----------------------------------------*/

int ggT(int a,int b);
int ggTr(int a, int b);
int kgV(int a, int b);

int main()
{
    int a, b = 0;

    cout << "Geben Sie eine Zahl fuer a ein:" << endl;
    cin >> a;
    cout << "Geben Sie eine Zahl fuer b ein:" << endl;
    cin >> b;

    //cout << "ggT: " << ggT(a, b) << endl;
    //cout << "ggTr: " << ggTr(a, b) << endl;
    cout << "kgV: " << kgV(a, b) << endl;

    return 0;
}


int ggT(int a, int b)
{
    int r = 0;
    do
    {
        r = a % b;
        a = b;
        b = r;

    } while (r != 0);

    return(a);
}

int ggTr(int a, int b)
{
    if(a == b) return(a);
    else
    {
        if(a > b) return(ggTr(a - b, b));
        else return(ggTr(b - a, a));
    }
}

int kgV(int a, int b)
{
    if(a == b) return(a);
    else
    {
        return((a * b) / ggT(a, b));
    }
}