#include <iostream>
using namespace std;

int fib(int n);

int main()
{
    int fibo = 0;

    cout << "Bis zu welcher Stelle soll die Fibonacci-Zahlenfolge ausgegeben werden?" << " ";
    cin >> fibo;

    cout << fib(fibo);

    return 0;
}

int fib(int n)
{
    int i=2, res = 1, vg = 1, vvg = 1;
    while (i<n)
    {
        res = vg + vvg;
        vg = vvg;
        vvg = res;
        i++;
    }
    return res;
}