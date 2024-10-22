#include <iostream>

using namespace std;

void nhapmang(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
    cout << endl;
}

void xuatmang(int a[], int n)
{
    cout << "Mang 1 chieu vua duoc tao: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "   ";
    }
    cout << "\n" << endl;
}

void tong(int a[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s = s + a[i];
    }
    cout << "Tong cua cac phan tu trong mang la: " << s << "\n" << endl;
}

void dem(int n, int x, int a[])
{
    cout << "Nhap phan tu x: ";
    cin >> x;
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            dem++;
    }
    cout << "Phan tu " << x << " xuat hien " << dem << " lan." << "\n" << endl;
}

void sochan(int n, int a[])
{
    cout << "Cac phan tu so chan cua mang la: ";
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0 && a[i] < 20)
            cout << a[i] << "   ";
    }
    cout << "\n" << endl;
}

int min(int n, int a[])
{
    int min = a[0];
    int temp = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            temp = i;
        }
    }
    return temp;
}

void daonguoc(int n, int a[])
{
    cout << "Day dao nguoc cua mang la: ";
    for(int i = n - 1; i >= 0; i--)
    {
        cout << a[i] << "   ";
    }
    cout << "\n" << endl;
}

int main()
{
    int n;
    cout << "Nhap so phan tu trong mang: ";
    cin >> n;
    int a[n];
    nhapmang(n,a);
    xuatmang(a,n);
    tong(a,n);
    int x;
    dem(n,x,a);
    sochan(n,a);
    cout << "Vi tri phan tu nho nhat la: " << "a[" << min(n,a) << "]" << "\n" << endl;
    daonguoc(n,a);
}

