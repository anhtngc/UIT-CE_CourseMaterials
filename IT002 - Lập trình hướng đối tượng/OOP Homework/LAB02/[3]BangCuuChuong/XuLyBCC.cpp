#include "BangCuuChuong.h"

BangCuuChuong::BangCuuChuong(int m, int n)
{
	if (m < 2 || m > 9 || n < 2 || n > 9)
		NhapBangCuuChuong();
	else
	{
		this->m = m;
		this->n = n;
	}
}

int BangCuuChuong::GetM()
{
	return m;
}

int BangCuuChuong::GetN()
{
	return n;
}

void BangCuuChuong::SetM(int m)
{
	while (m < 2 || m > 9)
	{
		cout << "Nhap m (1 < m < 10): ";
		cin >> m;
	}
	this->m = m;
}

void BangCuuChuong::SetN(int n)
{
	while (n < 2 || n > 9)
	{
		cout << "Nhap n (1 < n < 10): ";
		cin >> n;
	}
	this->n = n;
}

void BangCuuChuong::SetMN(int m, int n)
{
	*this = BangCuuChuong(m, n);
}

void BangCuuChuong::NhapBangCuuChuong()
{
	do
	{
		cout << "\nNhap gia tri m,n (1 < m,n < 10) de thao tac voi chuong trinh." << endl;
		cout << "Nhap m: ";
		cin >> m;
		cout << "Nhap n: ";
		cin >> n;
	} while (m < 2 || m > 9 || n < 2 || n > 9);
	cout << endl;
}

void BangCuuChuong::InBCCtu1den10()
{
	cout << "\nBANG CUU CHUONG TU 1 DEN 10:" << endl;
	cout << "	";
	for (int i = 1; i <= 10; i++)
	{
		cout << i << "	";
	}
	cout << endl;
	cout << "	+--------------------------------------------------------------------------+\n";
	for (int i = 1; i <= 10; i++)
	{
		cout << "	";
		for (int j = 1; j <= 10; j++)
		{
			cout << i * j << "	";
		}
		cout << endl;
	}
}

void BangCuuChuong::InBCCmn()
{
	cout << "\nBANG CUU CHUONG TU " << m << " DEN " << n << endl;
	for (int j = 1; j <= 10; j++)
	{
		for (int i = m; i <= n; i++)
		{
			cout << i << " x " << j << " = " << i * j << "	";
		}
		cout << endl;
	}
}

void BangCuuChuong::InBCCm()
{
	cout << "\nBANG CUU CHUONG " << m << ":" << endl;
	for (int i = 1; i <= 10; i++)
	{
		cout << m << " x " << i << " = " << m * i << endl;
	}
}
void BangCuuChuong::XuatBangCuuChuong()
{
	InBCCm();
	InBCCmn();
	InBCCtu1den10();
}