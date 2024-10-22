#include <iostream>
#include <math.h>

using namespace std;

void nhapmang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "nhap a[" << i << "] = ";
        cin >> a[i];
    }
    cout << "\n";
}

void xuatmang(int a[], int n)
{
    cout << "mang vua duoc tao la: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "   ";
    }
    cout << "\n" << endl;
}

void dem(int a[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0 && a[i] % 7 == 0)
            dem++;
    }
    cout << "co " << dem << " gia tri duong chia het cho 7 trong mang." << "\n" << endl;
}

void tong(int a[], int n)
{
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
            tong = tong + a[i];
    }
    cout << "tong cac gia tri am trong mang la: " << tong << "\n" << endl;
}

void sapxep(int a[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    cout << "mang sau khi sap xep giam dan: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << "   ";
    cout << "\n" << endl;
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

void maxsnt(int arr[], int n)
{
	int songuyento;
	int maxsnt = 0;
    cout << "so nguyen to lon nhat trong mang la: ";
	for (int i = 0; i < n; i++)
	{
		songuyento = arr[i];
		if (ktsnt(songuyento) == 1)
		{
			if (arr[i] >= maxsnt)
			{
				maxsnt = arr[i];
			}
		}
	}
	cout << maxsnt;
	cout << "\n" << endl;
}

int main()
{
    int n;
    cout << "nhap so phan tu trong mang: ";
    cin >> n;
    int a[n];
    nhapmang(a,n);
    xuatmang(a,n);
    dem(a,n);
    tong(a,n);
    sapxep(a,n);
    maxsnt(a,n);
    return 0;
}
