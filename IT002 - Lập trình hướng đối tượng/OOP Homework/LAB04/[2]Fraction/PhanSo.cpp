#include "PhanSo.h"

int main()
{
	PhanSo PS1, PS2;
	cout << "THIET LAP PHAN SO THU NHAT" << endl;
	cin >> PS1;
	cout << "THIET LAP PHAN SO THU HAI" << endl;
	cin >> PS2;
	cout << "\nHai phan so vua duoc nhap la: ";
	cout << PS1 << " va " << PS2 << endl;
	int n;
	cout << "\nMENU:";
	cout << "0: Dung chuong trinh" << endl;
	cout << "1: Nhap lai phan so thu nhat" << endl;
	cout << "2: Nhap lai phan so thu hai" << endl;
	cout << "3: Tong hai phan so" << endl;
	cout << "4: Hieu hai phan so" << endl;
	cout << "5: Tich hai phan so" << endl;
	cout << "6: Thuong hai phan so" << endl;
	cout << "7: Kiem tra hai phan so co bang nhau" << endl;
	cout << "8: Tang phan so thu nhat len 1 don vi" << endl;
	cout << "9: Giam phan so thu hai xuong 1 don vi" << endl;
	do
	{
		cout << "\nNhap ten bai toan ban muon lam: ";
		cin >> n;
		switch (n) {
		case 0:
			cout << "\nCHUONG TRINH DA KET THUC" << endl;
			cout << "Nhan phim bat ki de thoat chuong trinh" << endl;
			cout << "Da huy " << PhanSo::GetCount() << " phan so." << endl;
			return 0;
		case 1:
			cout << "Nhap lai phan so thu nhat" << endl;
			cin >> PS1;
			break;
		case 2:
			cout << "Nhap lai phan so thu hai" << endl;
			cin >> PS2;
			break;
		case 3:
			cout << "Tong hai phan so: " << PS1 + PS2 << endl;
			break;
		case 4:
			cout << "Hieu hai phan so: " << PS1 - PS2 << endl;
			break;
		case 5:
			cout << "Tich hai phan so: " << PS1 * PS2 << endl;
			break;
		case 6: 
			cout << "Thuong hai phan so: " << PS1 / PS2 << endl;
			break;
		case 7:
			if (PS1 == PS2) {
				cout << PS1 << " = " << PS2 << endl;
			}
			else if (PS1 > PS2) {
				cout << PS1 << " > " << PS2 << endl;
			}
			else {
				cout << PS1 << " < " << PS2 << endl;
			}
			break;
		case 8:
			cout << "Sau khi tang phan so thu nhat len 1 don vi, ta co PS1 = " << PS1++ << endl;
			break;
		case 9:
			cout << "Sau khi giam phan so thu hai xuong 1 don vi, ta co PS2 = " << PS2++ << endl;
			break;
		default:
			cout << "\nLua chon khong hop le, vui long chon lai tu 0 den 9!" << endl;
			break;
		} 
	} while (n != 0);
	return 0;
}