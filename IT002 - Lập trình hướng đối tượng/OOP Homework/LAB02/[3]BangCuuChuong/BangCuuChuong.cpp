#include "BangCuuChuong.h"

int main()
{
	BangCuuChuong BCC;
	int choice;
	do
	{
		cout << "MENU:" << endl;
		cout << "0: Dung chuong trinh\n";
		cout << "1: Nhap Bang cuu chuong\n";
		cout << "2: In bang cuu chuong m (1 < m < 10)\n";
		cout << "3: In bang cuu chuong tu m den n (1 < m,n < 10)\n";
		cout << "4: In bang cuu chuong tong hop tu 1 den 10\n";
		cout << "5: In 3 bang cuu chuong tren \n";
		cout << "6: Thiet lap lai gia tri m, n\n";
		cout << "Nhap lua chon cua ban (tu 0 den 6): ";
		cin >> choice;
		switch (choice)
		{
		case 0:
		{
			cout << "\nNhan phim bat ky de thoat chuong trinh." << endl;
			return 0;
		}
		case 1: 
		{
			BCC.NhapBangCuuChuong();
			break;
		}
		case 2:
		{
			BCC.InBCCm();
			break;
		}
		case 3:
		{
			BCC.InBCCmn();
			break;
		}
		case 4:
		{
			BCC.InBCCtu1den10();
			break;
		}
		case 5:
		{
			BCC.XuatBangCuuChuong();
			break;
		}
		case 6:
		{
			int a, b;
			cout << "\nNhap lai m: ";
			cin >> a;
			cout << "Nhap lai n: ";
			cin >> b;
			BCC.SetMN(a, b);
			cout << "Sau khi thiet lap lai, ta co m = " << BCC.GetM() << " va n = " << BCC.GetN() << endl;
			cout << "\n";
			break;
		}
		default:
			cout << "Lua chon khong hop le. Vui long chon lai cac lua chon tu 0 den 3!\n";
			break;
		}
	} while (choice != 0);
	return 0;
}