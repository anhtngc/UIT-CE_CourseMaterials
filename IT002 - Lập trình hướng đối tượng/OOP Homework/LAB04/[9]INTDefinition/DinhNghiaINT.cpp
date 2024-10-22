#include "DinhNghiaINT.h"

int main()
{
	INTEGER a, b, tong, hieu, thuong, tich;
	int choice;
	cout << "Nhap so nguyen a: ";
	cin >> a;
	cout << "Nhap so nguyen b: ";
	cin >> b;
	cout << "Hai so nguyen vua nhap la: " << a << " va " << b << endl;
	cout << "\nMENU:" << endl;
	cout << "0. Dung chuong trinh\n";
	cout << "1. Gan gia tri cua a cho b\n";
	cout << "2. In ra man hinh ket qua tong, hieu, tich, thuong cua hai so nguyen a va b\n";
	cout << "3. Tang a len 1 don vi\n";
	cout << "4. Giam b xuong 1 don vi\n";
	cout << "5. So sanh hai so nguyen vua nhap\n";
	cout << "6. Nhap lai so nguyen a\n";
	cout << "7. Nhap lai so nguyen b\n";
	do
	{
		cout << "\nNhap lua chon ban muon chuong trinh thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "\nCHUONG TRINH DA DUNG" << endl;
			cout << "Nhan phim bat ky de thoat chuong trinh..." << endl;
			cout << "Da huy " << INTEGER::GetCount() << " so nguyen" << endl;
			return 0;
			break;
		case 1:
			b = a;
			cout << "Sau khi gan gia tri cua a cho b, ta duoc b = " << b << endl;
			break;
		case 2:
			tong = a + b;
			hieu = a - b;
			thuong = a / b;
			tich = a * b;
			cout << "Tong cua hai so nguyen: " << tong << endl;
			cout << "Hieu cua hai so nguyen: " << hieu << endl;
			cout << "Tich cua hai so nguyen: " << tich << endl;
			cout << "Thuong cua hai so nguyen: " << thuong << endl;
			break;
		case 3:
			cout << "Sau khi tang a len 1 don vi, ta co a = " << ++a << endl;
			break;
		case 4:
			cout << "Sau khi giam b xuong 1 don vi, ta co b = " << --b << endl;
			break;
		case 5:
			if (a == b) {
				cout << "So nguyen a va b bang nhau." << endl;
			}
			else if (a > b) {
				cout << "So nguyen a lon hon so nguyen b." << endl;
			}
			else {
				cout << "So nguyen a nho hon so nguyen b." << endl;
			}
			break;
		case 6:
			cout << "Nhap lai so nguyen a: ";
			cin >> a;
			break;
		case 7:
			cout << "Nhap lai so nguyen b: ";
			cin >> b;
			break;
 		default:
			cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
			break;
		}
	} while (choice != 0);
	return 0;
}