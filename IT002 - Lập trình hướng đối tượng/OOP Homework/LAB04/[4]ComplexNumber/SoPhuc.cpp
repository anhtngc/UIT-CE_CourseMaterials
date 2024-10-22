#include "SoPhuc.h"

using namespace std;

int main()
{
	SoPhuc SP1, SP2, SP3;
	cout << "THIET LAP SO PHUC THU NHAT:" << endl;
	cin >> SP1;
	cout << "\nTHIET LAP SO PHUC THU HAI:" << endl;
	cin >> SP2;
	cout << "\nHai so phuc vua nhap la: A = ";
	cout << SP1;
	cout << " va B = ";
	cout << SP2 << endl;
	int n;
	cout << "\nMENU" << endl;
	cout << "0: Dung chuong trinh" << endl;
	cout << "1: Nhap lai so phuc thu nhat" << endl;
	cout << "2: Nhap lai so phuc thu hai" << endl;
	cout << "3: Tong hai so phuc" << endl;
	cout << "4: Hieu hai so phuc" << endl;
	cout << "5: Tich hai so phuc" << endl;
	cout << "6: Thuong hai so phuc" << endl;
	cout << "7: Kiem tra hai so phuc co bang nhau" << endl;
	do
	{
		cout << "\nNhap ten bai toan ban muon lam: " << "";
		cin >> n;
		switch (n)
		{
		case 0:
			cout << "\nCHUONG TRINH KET THUC" << endl;
			cout << "Nhan phim bat ky de thoat chuong trinh" << endl;
			cout << "Da huy " << SoPhuc::GetCount() << " so phuc." << endl;
			return 0;
		case 1:
			cout << "Nhap lai phan so thu nhat" << endl;
			cin >> SP1;
			break;
		case 2:
			cout << "Nhap lai phan so thu hai" << endl;
			cin >> SP2;
			break;
		case 3:
			SP3 = SP1 + SP2;
			cout << "Tong hai so phuc la: " << SP3 << endl;
			break;
		case 4:
			SP3 = SP1 - SP2;
			cout << "Hieu 2 phan so la: " << SP3 << endl;
			break;
		case 5:
			SP3 = SP1 * SP2;
			cout << "Tich 2 phan so la: " << SP3 << endl;
			break;
		case 6:
			SP3 = SP1 / SP2;
			cout << "Thuong 2 phan so la: " << SP3 << endl;
			break;
		case 7:
			if (SP1 == SP2) {
				cout << SP1 << " = " << SP2 << endl;
			}
			else if (SP1 > SP2) {
				cout << SP1 << " > " << SP2 << endl;
			}
			else if (SP1 < SP2) {
				cout << SP1 << " > " << SP2 << endl;
			}
			break;
		default:
			cout << "\nLua chon khong hop le. Vui long chon lai tu 0 den 7!";
			break;
		}
	} while (n != 0);
	return 0;
}