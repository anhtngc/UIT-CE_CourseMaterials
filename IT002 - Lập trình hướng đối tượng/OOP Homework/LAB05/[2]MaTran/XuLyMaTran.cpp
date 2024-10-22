#include "MATRAN.h"

MATRAN::~MATRAN()
{
	row = 0;
	col = 0;
	delete[]p;
	p = NULL;
	cout << "Da huy 1 ma tran" << endl;
}

MATRAN::MATRAN(int row, int col, int m)
{
	if (row == 0 || col == 0)
	{
		this->p = 0;
		p = NULL;
	}
	else
	{
		while (row <= 0 || col <= 0)
		{
			cout << "Nhap so dong (> 0): ";
			cin >> row;
			cout << "Nhap so cot (> 0):  ";
			cin >> col;
		}
		this->row = row, this->col = col;
		p = new int* [row];
		for (int i = 0; i < row; i++) {
			p[i] = new int[col];
			for (int j = 0; j < col; j++) {
				p[i][j] = m;
			}
		}
	}
}

int MATRAN::GetROW()
{
	return row;
}

int MATRAN::GetCOL()
{
	return col;
}

int** MATRAN::GetP()
{
	return p;
}

istream& operator>>(istream& in, MATRAN& m)
{
	if (m.p != NULL)
		m.~MATRAN();
	do {
		cout << "Nhap so dong (> 0): ";
		in >> m.row;
		cout << "Nhap so cot (> 0): ";
		in >> m.col;
	} while (m.row <= 0 || m.col <= 0);
	m.p = new int* [m.row];
	for (int i = 0; i < m.row; i++) {
		m.p[i] = new int[m.col];
		for (int j = 0; j < m.col; j++) {
			cout << "a[" << i << "][" << j << "] = ";
			in >> m.p[i][j];
		}
	}
	return in;
}

ostream& operator<<(ostream& out, MATRAN& m)
{
	if (m.p == NULL)
		out << "Ma tran rong" << endl;
	else
		for (int i = 0; i < m.row; i++)
		{
			for (int j = 0; j < m.col; j++)
			{
				out << m.p[i][j] << "	";
			}
			out << endl;
		}
	return out;
}

MATRAN& MATRAN::operator=(const MATRAN& m)
{
	row = m.row;
	col = m.col;
	p = new int* [row];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			p[i][j] = m.p[i][j];
	}
	return *this;
}

bool MATRAN::KiemTraSNT(int n)
{
	if (n < 2) return false;
	int sq = sqrt(n);
	for (int i = 2; i <= sq; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

void MATRAN::LietKeSoNguyenTo()
{
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			if (KiemTraSNT(this->p[i][j]))
				cout << this->p[i][j] << " ";
		}
	}
	cout << endl;
}

bool MATRAN::KiemTraSoChinhPhuong(int n)
{
	if (n < 1)
		return false;
	int i = 1;
	while (i * i <= n) {
		if (i * i == n)
			return true;
		i++;
	}
	return false;
}

int MATRAN::DemSoChinhPhuong()
{
	int count = 0;
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			if (KiemTraSoChinhPhuong(this->p[i][j]))
				count++;
		}
	}
	return count;
}

bool MATRAN::KiemTraSoHoanThien(int n)
{
	int temp = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0)
			temp = temp + i;
	}

	if (temp != 0 && temp == n)
		return true;
	else
		return false;
}

int MATRAN::TinhTongSoHoanThien(int k) //dòng thứ k
{
	int sum = 0;
	for (int j = 0; j < this->col; j++)
	{
		if (KiemTraSoHoanThien(this->p[k][j]))
		{
			sum += this->p[k][j];
		}
	}
	return sum;
}

bool MATRAN::KiemTraDoiXung(int n)
{
	int temp = n, sodao = 0, r = 0;
	while (temp != 0)
	{
		r = temp % 10;
		sodao = sodao * 10 + r;
		temp /= 10;
	}
	if (n == sodao)
		return true;
	else
		return false;
}

int MATRAN::TinhTBCSoDoiXung(int k) //cột thứ k
{
	int TBC = 0;
	int sum = 0;
	int count = 0;
	for (int i = 0; i < this->row; i++)
	{
		if (KiemTraDoiXung(this->p[i][k]))
		{
			count++;
			sum += this->p[i][k];
		}
	}
	TBC = sum / count;
	return TBC;
}

void MATRAN::SapXepTangDan(int k)
{
	for (int i = 0; i < this->col - 1; i++)
	{
		for (int j = i + 1; j < this->col; j++)
		{
			if (this->p[k][i] > this->p[k][j])
			{
				swap(this->p[k][i], this->p[k][j]);
			}
		}
	}
}

void MATRAN::TaoNgauNhienMaTran()
{
	srand(time(0));
	do {
		cout << "Nhap so dong (> 0): ";
		cin >> row;
		cout << "Nhap so cot (> 0): ";
		cin >> col;
	} while (row <= 0 || col <= 0);
	this->row = row;
	this->col = col;
	p = new int* [row];
	for (int i = 0; i < row; ++i) 
	{
		p[i] = new int[col];
		for (int j = 0; j < col; ++j) {
			p[i][j] = rand() % 100; // Giá trị ngẫu nhiên từ 0 đến 99
		}
	}
	cout << "Da tao ngau nhien mot ma tran gom " << row << " dong va " << col << " cot, hay chon lenh xuat ma tran de xem!" << endl;
}