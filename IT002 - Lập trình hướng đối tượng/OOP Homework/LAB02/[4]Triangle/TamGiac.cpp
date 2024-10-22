#include "TamGiac.h"
#include "Diem.h"

using namespace std;

int main()
{
	Point A, B, C;
	Triangle ABC(A, B, C);
	ABC.NhapTamGiac();
	ABC.XuatTamGiac();
	cout << "\nChu vi tam giac ABC la: " << ABC.TinhChuVi(ABC);
	cout << "\nDien tich tam giac ABC la: " << ABC.TinhDienTich(ABC);
	cout << "\n";
	return 0;
}