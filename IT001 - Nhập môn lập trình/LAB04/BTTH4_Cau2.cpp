#include <iostream>
#include <math.h>

using namespace std;

int s1(int n)
{
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        s = s + i;
    }
    return s;
}

int s2(int n)
{
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        s = s + i*i;
    }
    return s;
}

float s3(int n)
{
    float s = 0;
    for (int i = 1; i <= n; i++)
    {
        s = s + 1.0/i;
    }
    return s;
}

long s4(int n)
{
    long s = 0;
    long temp = 1;
    for (int i = 1; i <= n; i++)
    {
        temp = temp * i;
        s = s + temp;
    }
    return s;
}

long s5(int n)
{
    long s = 1;
    for (int i = 1; i <= n; i++)
    {
        s = s * i;
    }
    return s;
}

int main()
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
        cout << "s1 = 1 + 2 + 3 + ... + n = " << s1(n) << endl;
        cout << "s2 = 1^2 + 2^2 + 3^2 + ... + n^2 = " << s2(n) << endl;
        cout << "s3 = 1 + 1/2 + ... + 1/n = " << s3(n) << endl;
        cout << "s4 = 1! + 2! + 3! + ... + n! = " << s4(n) << endl;
        cout << "s5 = 1 * 2 * 3 * ... * n = " << s5(n) << endl;
    }
}
