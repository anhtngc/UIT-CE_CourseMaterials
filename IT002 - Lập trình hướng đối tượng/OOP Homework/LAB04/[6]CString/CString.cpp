#include "CString.h"

int main()
{
	CString S1, S2;
	int choice;
	cout << "MENU\n";
	cout << "0. Dung chuong trinh\n";
	cout << "1. Nhap chuoi 1\n";
	cout << "2. Nhap chuoi 2\n";
	cout << "3. Xuat chuoi 1\n";
	cout << "4. Xuat chuoi 2\n";
	cout << "5. Gan gia tri chuoi 1 sang chuoi 2\n";
	cout << "6. So sanh hai chuoi vua nhap\n";
	cout << "7. Cong hai chuoi vua nhap\n";
	do
	{
		cout << "Nhap lua chon ban muon thuc hien: ";
		cin >> choice;
		cin.ignore();
		switch (choice) 
		{
		case 0:
			cout << "\nCHUONG TRINH DA KET THUC" << endl;
			cout << "Nhan phim bat ky de thoat chuong trinh..." << endl;
			cout << "Da huy " << CString::GetCount() << " chuoi ky tu." << endl;
			return 0;
		case 1:
			cout << "Nhap chuoi thu nhat: ";
			cin >> S1;
			cout << endl;
			break;
		case 2:
			cout << "Nhap chuoi thu hai: ";
			cin >> S2;
			cout << endl;
			break;
		case 3:
			cout << "Chuoi 1: " << S1 << endl;
			cout << endl;
			break;
		case 4:
			cout << "Chuoi 2: " << S2 << endl;
			cout << endl;
			break;
		case 5:
			S2 = S1;
			cout << "Sau khi gan chuoi 1 cho chuoi 2, ta duoc chuoi 2: " << S2 << endl;
			cout << endl;
			break;
		case 6: 
			if (S1 == S2) {
				cout << "Chuoi " << S1 << " va chuoi " << S2 << " giong nhau." << endl;
			}
			else if (S1 > S2) {
				cout << "Chuoi " << S1 << " lon hon chuoi " << S2 << endl;
			}
			else if (S1 < S2) {
				cout << "Chuoi " << S1 << " nho hon chuoi " << S2 << endl;
			}
			else {
				cout << "Khong the so sanh hai chuoi tren!" << endl;
			}
			cout << endl;
			break;
		case 7:
			cout << "Sau khi cong hai chuoi, ta duoc chuoi: " << S1 + S2 << endl;
			cout << endl;
			break;
		default:
			cout << "Lua chon khong hop le. Vui long chon lai lua chon tu 0 den 7!" << endl;
			break;
		}
	} while (choice != 0);
	return 0;
}