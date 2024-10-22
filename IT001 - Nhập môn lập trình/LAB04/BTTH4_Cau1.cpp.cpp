#include <iostream>
#include <math.h>

using namespace std;

int sodaonguoc(int n)
{
    int temp = 0;
    while (n!= 0)
    {
        temp  = temp * 10 + n % 10;
        n = n / 10;
    }
    return temp;
}

int sochinhphuong(int n)
{
    int i = 0;
    while (i * i <= n)
    {
        if (i * i == n)
        {
            return 1;
        }
        ++i;
    } return 0;
}

int ktsnt(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int tongcacchusole(int n)
{
    int tong = 0, temp;
    while (n != 0)
    {
        temp = n % 10;
        if (temp % 2 != 0)
            tong = tong + temp;
        n /= 10;
    }
    return tong;
}

int tongsnt(int n)
{
    int i,s = 0;
    for (i = 2; i < n; i++)
    {
        if (ktsnt(i) == 1)
            s = s + i;
    }
    return s;
}

int tongscp(int n)
{
    int i = 1;
    int s = 0;
    while (i < sqrt(n))
    {
        s = s + i*i;
        i++;
    }
    return s;
}

int tonguocso(int n)
{
    int s = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
            s = s + i;
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
    else cout << "so dao nguoc cua " << n << " la: " << sodaonguoc(n) << endl;
    if (sochinhphuong(n) == 1)
    {
        cout << n << " la so chinh phuong." << endl;
    }
    else cout << n << " khong la so chinh phuong." << endl;
    if (ktsnt(n) == 1)
    {
        cout << n << " la so nguyen to." << endl;
    }
    else cout << n << " khong la so nguyen to." << endl;
    cout << "tong cac chu so le cua " << n << " la: " << tongcacchusole(n) << endl;
    cout << "tong cac so nguyen to nho hon " << n << " la: " << tongsnt(n) << endl;
    cout << "tong cac so chinh phuong nho hon " << n << " la: " << tongscp(n) << endl;
    cout << "tong cac uoc so nho hon " << n << " la: " << tonguocso(n) << endl;
}
