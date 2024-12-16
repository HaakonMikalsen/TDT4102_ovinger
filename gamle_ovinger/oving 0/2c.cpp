#include <iostream>
using namespace std;

int fibonacci(int n)
{
    int a = 0;
    int b = 1;
    cout << "Fibonachi numbers: \n";
    for (int i = 1; i <= n; i++)
    {
        cout << i << ":" << b << "\n";
        int temp = b;
        b += a;
        a = temp;
    }
    cout << "---- \n";
    return b;
}

int main()
{
    int n = 10;
    cout << fibonacci(n);
}