/* in ra n phần tử của dãy fibonacci */

#include <iostream>

using namespace std;

int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return n;
    else return fibonacci(n - 1) + fibonacci(n - 2);
}

int main ()
{
    int n;
    cout << "nhap so nguyen duong n: ";
    cin >> n;
    if (n < 1)
    {
        do
        {
            cout << "n phai la so nguyen duong, xin hay nhap lai: ";
            cin >> n;
        } while (n < 1);
    }
    else
    {
        cout << n << " so dau tien cua day fibonacci la: ";
        for (int i = 0; i <= n; i++)
            cout << fibonacci(i) << "  ";
    }
}
