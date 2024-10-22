#include "PTBacNhat.h"

int main()
{
	int choice;
	do
	{
		cout << "MENU: " << endl;
		cout << "0: Dung chuong trinh." << endl;
		cout << "1: Giai phuong trinh 0x + 0 = 0" << endl;
		cout << "2: Giai phuong trinh 0x + 2 = 0" << endl;
		cout << "3: Giai phuong trinh bac nhat bat ky" << endl;
		cout << "Chon lua chon cua ban (tu 0 den 3): ";
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
			PTBacNhat fx;
			fx.XuatPhuongTrinh();
			fx.GiaiPhuongTrinh();
			break;
		}
		case 2:
		{
			PTBacNhat fx(0, 2);
			fx.XuatPhuongTrinh();
			fx.GiaiPhuongTrinh();
			break;
		}
		case 3:
		{
			PTBacNhat fx;
			fx.NhapHeSo();
			fx.XuatPhuongTrinh();
			fx.GiaiPhuongTrinh();
			break;
		}
		default:
		{
			cout << "Lua chon khong hop le. Vui long chon lai cac lua chon tu 0 den 3!\n";
			break;
		}
		}
	} while (choice != 0);
}
