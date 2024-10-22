#include "DaThuc.h"

int main()
{
	DaThuc DT1, DT2;
	int choice;
	int x, vitri;
	double giatri;
	cout << "MENU\n";
	cout << "0. Dung chuong trinh\n";
	cout << "1. Nhap da thuc thu nhat\n";
	cout << "2. Nhap da thuc thu hai\n";
	cout << "3. Xuat da thuc thu nhat\n";
	cout << "4. Xuat da thuc thu hai\n";
	cout << "5. Tinh gia tri cua da thuc thu nhat tai x bat ky\n";
	cout << "6. Cong hai da thuc\n";
	cout << "7. So sanh hai da thuc\n";
	cout << "8. Gan gia tri da thuc thu nhat cho da thuc thu hai\n";
	cout << "9. Thay doi he so tai vi tri bat ky cho da thuc thu hai\n";
	do
	{
		cout << "\nNhap lua chon ban muon chuong trinh thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "\nCHUONG TRINH DA DUNG" << endl;
			cout << "Nhan phim bat ky de thoat chuong trinh..." << endl;
			cout << "Da huy " << DaThuc::GetCount() << " da thuc\n";
			break;
		case 1:
			cout << "1. Nhap da thuc thu nhat" << endl;
			cin >> DT1;
			break;
		case 2:
			cout << "2. Nhap da thuc thu hai" << endl;
			cin >> DT2;
			break;
		case 3:
			cout << "Da thuc thu nhat la: " << DT1;
			break;
		case 4:
			cout << "Da thuc thu hai la: " << DT2;
			break;
		case 5:
			cout << "Nhap gia tri x muon thay vao da thuc thu nhat: ";
			cin >> x;
			cout << "Sau khi thay x = " << x << " vao da thuc thu nhat, ta duoc gia tri: " << DT1.Tinh(x) << endl;
			break;
		case 6:
			cout << "Sau khi cong hai da thuc, ta duoc da thuc moi: " << DT1 + DT2;;
			break;
		case 7:
			if (DT1 == DT2) {
				cout << "Hai da thuc trung nhau." << endl;
			}
			else {
				cout << "Hai da thuc khong trung nhau." << endl;
			}
			break;
		case 8: 
			DT2 = DT1;
			cout << "Sau khi gan da thuc thu nhat cho da thuc thu hai, ta duoc da thuc thu hai: " << DT2;
			break;
		case 9:
			cout << "Chon vi tri (bac) ban muon thay doi he so: ";
			cin >> vitri;
			DT2.GetHeSo(vitri);
			cout << "Nhap gia tri ban muon thay doi he so thanh: ";
			cin >> giatri;
			DT2.SetHeSo(vitri, giatri);
			cout << "Sau khi thay doi he so bac " << vitri << " thanh " << giatri << " ta duoc da thuc: " << DT2;
			break;
		default:
			cout << "Lua chon chua phu hop. Vui long chon lai lua chon tu 0 den 9 trong bang menu!" << endl;
			break;
		}
	} while (choice != 0);
	return 0;
}