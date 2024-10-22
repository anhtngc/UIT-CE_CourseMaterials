#include "MATRANVUONG.h"

MATRANVUONG::~MATRANVUONG()
{
	n = 0;
	delete[]p;
	p = NULL;
	cout << "Da huy 1 ma tran vuong" << endl;
}

MATRANVUONG::MATRANVUONG(int n, int m)
{
	if (n == 0)
	{
		this->p = 0;
		p = NULL;
	}
	else
	{
		while (n <= 0)
		{
			cout << "Nhap n (> 0) la so cap cua ma tran: ";
			cin >> n;
		}
		this->n = n;
		p = new int* [n];
		for (int i = 0; i < n; i++) {
			p[i] = new int[n];
			for (int j = 0; j < n; j++) {
				p[i][j] = m;
			}
		}
	}
}

int MATRANVUONG::GetN()
{
	return n;
}

int** MATRANVUONG::GetP()
{
	return p;
}

istream& operator>>(istream& in, MATRANVUONG& m)
{
	if (m.p != NULL)
		m.~MATRANVUONG();
	do {
		cout << "Nhap n (> 0) la so cap cua ma tran: ";
		in >> m.n;
	} while (m.n <= 0);
	m.p = new int* [m.n];
	for (int i = 0; i < m.n; i++) {
		m.p[i] = new int[m.n];
		for (int j = 0; j < m.n; j++) {
			cout << "a[" << i << "][" << j << "] = " << "";
			in >> m.p[i][j];
		}
	}
	return in;
}

ostream& operator<<(ostream& out, MATRANVUONG& m)
{
	if (m.p == NULL)
		out << "Ma Tran Rong" << endl;
	else
		for (int i = 0; i < m.n; i++)
		{
			for (int j = 0; j < m.n; j++)
			{
				out << m.p[i][j] << "	";
			}
			out << endl;
		}
	return out;
}

MATRANVUONG& MATRANVUONG::operator=(const MATRANVUONG& m)
{
	n = m.n;
	p = new int* [n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			p[i][j] = m.p[i][j];
	}
	return *this;
}

void MATRANVUONG::LietKeSoLeTrenDCheoChinh()
{
	for (int i = 0; i < this->n; i++)
	{
		if (this->p[i][i] % 2 != 0)
		{
			cout << this->p[i][i] << " ";
		}
	}
	cout << endl;
}

int MATRANVUONG::DemSoLuongPhanTuCoKyTuSoCuoiLa3() //trên đường chéo phụ
{
	int count = 0;
	for (int i = 0; i < this->n; i++)
	{
		for (int j = 0; j < this->n; j++)
		{
			if (i + j == n - 1 && p[i][j] % 10 == 3)
				count++;
		}
	}
	return count;
}

bool MATRANVUONG::KiemTraNuaMang()
{
	for (int i = 0; i < this->n; i++)
	{
		for (int j = i; j < this->n; j++)
		{
			if (p[i][j] < 0)
				return true;
		}
	}
	return false;
}

int MATRANVUONG::TimPhanTuChanMangVuongPhiaDuoiDCheoPhu()
{
	int find_num = -1;
	for (int i = 0; i < this->n; i++)
	{
		for (int j = 0; j < this->n; j++)
		{
			if (i + j >= this->n && p[i][j] % 2 == 0)
				find_num = p[i][j];
			return find_num;
		}
	}
	return find_num;
}

void MATRANVUONG::SapXepGiamDanCacPhanTuNamTrenDCheoPhu()
{
	for (int i = 0; i < this->n - 1; i++)
	{
		for (int j = i; j < this->n; j++)
		{
			if (p[i][n - 1 - i] < p[j][n - 1 - j])
			{
				int temp = p[i][n - 1 - i];
				p[i][n - 1 - i] = p[j][n - 1 - j];
				p[j][n - 1 - j] = temp;
			}
		}
	}
}

void MATRANVUONG::TaoNgauNhienMaTranVuong()
{
	srand(time(0));
	do {
		cout << "Nhap n (> 0) la so cap cua ma tran: ";
		cin >> n;
	} while (n <= 0);
	p = new int* [n];
	for (int i = 0; i < n; i++) {
		p[i] = new int[n];
		for (int j = 0; j < n; ++j) {
			p[i][j] = rand() % 100; // Giá trị ngẫu nhiên từ 0 đến 99
		}
	}
	cout << "Da tao ngau nhien mot ma tran vuong cap " << n << ", hay chon lenh xuat de xem!" << endl;
}