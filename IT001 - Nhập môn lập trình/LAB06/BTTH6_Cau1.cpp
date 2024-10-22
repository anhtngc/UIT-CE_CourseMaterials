#include <iostream>

using namespace std;

void nhapmang(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> arr[i];
    }
    cout << "\n";
}

void xuatmang(int *arr, int n)
{
    cout << "Xuat mang: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n" << endl;
}

void tong(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    cout << "Tong cac phan tu trong mang la: " << sum << "\n" << endl;
}

void giamdan(int *arr, int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "Mang sau khi sap xep giam dan: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << "\n" << endl;
}

int main()
{
    int n;
    cout << "Nhap so phan tu trong mang: ";
    cin >> n;
    int *arr = new int;
    nhapmang(arr, n);
    xuatmang(arr, n);
    tong(arr, n);
    giamdan(arr, n);
}
