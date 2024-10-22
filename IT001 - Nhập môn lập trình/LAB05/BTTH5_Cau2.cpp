#include <iostream>

using namespace std;

#define ROW 100
#define COL 100

void nhapmang(int arr[][COL], int& m, int& n)
{
	cout << "Nhap so dong : ";
	cin >> m;
	cout << "Nhap so cot : ";
	cin >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> arr[i][j];
		}
	}
	cout << "\n";
}

void xuatmang(int arr[][COL], int m, int n)
{
	cout << "Mang da duoc tao:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "\n" << endl;
	}
}

void min(int arr[][COL], int m, int n)
{
    int min = arr[0][0];
    int t1 = 0, t2 =0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
                t1 = i;
                t2 = j;
            }
        }
    }
    cout << "Phan tu nho nhat trong ma tran la: " << "a[" << t1 << "][" << t2 << "]" << "\n" << endl;
}

void tamgiactren(int arr[][COL], int m, int n)
{
    cout << "Cac phan tu nam tren duong cheo chinh: " << endl;
    for (int i = 0; i < m; i++)
    {
        cout << "a[" << i << "][" << i << "] = " << arr[i][i] << endl;
    }
    cout << "Cac phan tu nam phia tren duong cheo chinh la: ";
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cout << arr[i][j] << "  ";
        }
    }
    cout << "\n" << endl;
}

void mindong(int arr[][COL], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        int min = arr[i][0];
        cout << "Gia tri nho nhat cua dong " << i << " la: ";
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
        cout << min << endl;
    }
    cout << "\n";
}

void maxcot(int arr[][COL], int m, int n)
{
    for (int j = 0; j < n; j++)
    {
        int max = arr[0][j];
        cout << "Gia tri lon nhat cua cot " << j << " la: ";
        for (int i = 0; i < m; i++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
        cout << max << endl;
    }
    cout << "\n";
}

void tong(int arr1[][COL], int arr2[][COL], int m, int n, int a, int b)
{
    int s[ROW][COL];
    if (m != a || n != b)
    {
        cout << "Hai ma tran khong cung kich co!";
        cout << "\n< Hay nhap lai ma tran B co cung kich co voi ma tran A! >" << endl;
        nhapmang(arr2, a, b);
        xuatmang(arr2, a, b);
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            s[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    cout << "Tong cua hai ma tran la: \n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << s[i][j] << "\t";
        }
        cout << "\n" << endl;
    }
}

void tich(int arr1[][COL], int arr2[][COL], int m, int n, int a, int b)
{
    int s[ROW][COL];
    if (m != b)
    {
        cout << "\So cot cua ma tran A khong bang so dong cua ma tran B nen khong the thuc hien phep nhan.";
        cout << "\n< Hay nhap lai ma tran B co so dong bang so cot ma tran A! >" << endl;
        nhapmang(arr2, a, b);
        xuatmang(arr2, a, b);
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < b; j++)
        {
            int temp = 0;
            for (int k = 0; k < n; k++)
            {
                temp = temp + arr1[i][k] * arr2[k][j];
            }
            s[i][j] = temp;
        }
    }
    cout << "Tich cua hai ma tran la: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << s[i][j] << "\t";
        }
        cout << "\n" << endl;
    }
}

int main()
{
    int arr1[ROW][COL];
	int nRow, nCol;
	cout << "< Nhap mot ma tran >" << endl;
	nhapmang(arr1, nRow, nCol);
	xuatmang(arr1, nRow, nCol);
	min(arr1, nRow, nCol);
	if (nRow != nCol)
    {
        cout << "Ma tran da tao khong phai ma tran vuong nen khong co duong cheo chinh.";
        cout << "\n< Hay nhap lai mot ma tran vuong >" << endl;
        nhapmang(arr1, nRow, nCol);
        xuatmang(arr1, nRow, nCol);
        tamgiactren(arr1, nRow, nCol);
    }
        else
        {
            tamgiactren(arr1, nRow, nCol);
        }
	mindong(arr1, nRow, nCol);
	maxcot(arr1, nRow, nCol);
	cout << "< Nhap ma tran A >" << endl;
	nhapmang(arr1, nRow, nCol);
	xuatmang(arr1, nRow, nCol);
    int arr2[ROW][COL];
	int aRow, aCol;
	cout << "< Nhap ma tran B >" << endl;
	nhapmang(arr2, aRow, aCol);
	xuatmang(arr2, aRow, aCol);
	tong(arr1, arr2, nRow, nCol, aRow, aCol);
	cout << "< Nhap lai ma tran A >" << endl;
	nhapmang(arr1, nRow, nCol);
	xuatmang(arr1, nRow, nCol);
	cout << "< Nhap lai ma tran B >" << endl;
	nhapmang(arr2, aRow, aCol);
	xuatmang(arr2, aRow, aCol);
	tich(arr1, arr2, nRow, nCol, aRow, aCol);
}
