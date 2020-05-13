#include <iostream>
using namespace std;

int fibr(int n);

int main()
{
    int fibo = 0;

    cout << "Bis zu welcher Stelle soll die Fibonacci-Zahlenfolge ausgegeben werden?" << " ";
    cin >> fibo;

    cout << fibr(fibo);

    return 0;
}

int fibr(int n)
{
    if(n==0 || n==1 || n==2) return 1;
    return fibr(n-1)+fibr(n-2);
}