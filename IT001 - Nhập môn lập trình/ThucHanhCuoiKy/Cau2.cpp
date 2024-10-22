#include <iostream>

using namespace std;

#define ROW 100
#define COL 100

void nhapmang(int arr[][COL], int& m, int& n)
{
	cout << "nhap so dong : ";
	cin >> m;
	cout << "nhap so cot : ";
	cin >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "arr[" << i << "][" << j << "] = ";
			cin >> arr[i][j];
		}
	}
	cout << "\n" << endl;
}
void xuatmang(int arr[][COL], int m, int n)
{
	cout << "mang da tao:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "\n" << endl;
	}
}
void giatriduong(int arr[][COL], int m, int n)
{
	int i, j;
	int giatriduong = arr[0][0];
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			giatriduong = arr[i][j];
			if (arr[i][j] > 0)
			{
				break;
			}
		}
		if (arr[i][j] > 0)
		{
			break;
		}
	}
	cout << "gia tri duong dau tien trong ma tran la: " << giatriduong << "\n" << endl;
}
void solanxuathien(int arr[][COL], int m, int n)
{
	int x;
	int count = 0;
	cout << "nhap gia tri x = " << "";
	cin >> x;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == x)
			{
				count++;
			}
		}
	}
	cout << "so lan xuat hien " << x << " la: " << count << "\n" << endl;
}
void trungbinhnhansoduong(int arr[][COL], int m, int n)
{
	int tich = 1;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] >= 1)
			{
				tich *= arr[i][j];
			}
		}
	}
	cout << "trung binh nhan cac so duong la: " << float(tich) / float((m * n)) << "\n" << endl;
}
void dongchuagiatrile(int arr[][COL], int m, int n)
{
	int giatrile;
	cout << "dong chua gia tri le la dong: " << "";
	for (int i = 0; i < m; i++)
	{
		giatrile = arr[i][0];
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] % 2 != 0)
			{
				giatrile = arr[i][j];
			}
		}
		if (giatrile % 2 != 0)
		{
			cout << i << " ";
		}
	}
	cout << "\n";
}

int main()
{
	int arr[ROW][COL];
	int nRow, nCol;
	cout << "nhap vao ma tran: " << endl;
	nhapmang(arr, nRow, nCol);
	xuatmang(arr, nRow, nCol);
	giatriduong(arr, nRow, nCol);
	solanxuathien(arr, nRow, nCol);
	trungbinhnhansoduong(arr, nRow, nCol);
	dongchuagiatrile(arr, nRow, nCol);
	cout << "\n" << endl;
	return 0;
}
