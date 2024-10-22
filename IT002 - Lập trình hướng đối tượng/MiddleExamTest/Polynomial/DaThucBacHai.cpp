#include "DaThucBacHai.h"

int main()
{
	Polynomial DT1, DT2, DT3;
	int choice;
	double x, y;
	cout << "MENU:\n";
	cout << "0: Dung chuong trinh\n";
	cout << "1: Nhap da thuc bac hai thu nhat (F1)\n";
	cout << "2: Nhap da thuc bac hai thu hai (F2)\n";
	cout << "3: Xuat da thuc bac hai thu nhat\n";
	cout << "4: Xuat da thuc bac hai thu hai\n";
	cout << "5: Xac dinh gia tri F1 khi x bat ky\n";
	cout << "6: Cong hai da thuc tren\n";
	cout << "7: Thay doi gia tri he so a cua da thuc thu nhat\n";
	do
	{
		cout << "\nHay nhap lua chon ban muon thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "\nNhan phim bat ky de thoat chuong trinh..." << endl;
			return 0;
		case 1:
			cin >> DT1;
			break;
		case 2:
			cin >> DT2;
			break;
		case 3:
			cout << "Da thuc thu nhat co dang: ";
			cout << DT1;
			break;
		case 4:
			cout << "Da thuc thu hai co dang: ";
			cout << DT2;
			break;
		case 5:
			cout << "Nhap gia tri x ban muon thay vao F1: ";
			cin >> x;
			cout << "Khi thay x = " << x << " vao da thuc thu nhat, F1 co gia tri: " << DT1.TinhF0(x) << endl;
			break;
		case 6: 
			DT3 = DT1.operator+(DT2);
			cout << "Sau khi cong hai da thuc ta duoc: " << DT3;
			break;
		case 7:
			cout << "Nhap gia tri cua he so a ban muon thay doi: ";
			cin >> y;
			DT1.SetA(y);
			DT1.GetA();
			cout << "Da thuc da duoc thay doi thanh: " << DT1;
			break;
		default:
			cout << "\nLua chon khong hop le, vui long nhap lai mot lua chon khac tu 0 den 7!" << endl;
			break;
		}
	} while (choice != 0);
	return 0;
}