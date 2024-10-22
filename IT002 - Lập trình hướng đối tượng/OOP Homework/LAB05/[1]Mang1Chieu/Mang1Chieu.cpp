#include "Mang1Chieu.h"

int main()
{
	Mang1Chieu *A = new Mang1Chieu;
	int choice;
	cout << "MENU\n";
	cout << "0: Dung chuong trinh...\n";
	cout << "1: Nhap gia tri cac phan tu trong mang\n";
	cout << "2: Xuat gia tri cac phan tu trong mang\n";
	cout << "3: Liet ke cac so nguyen to trong mang\n";
	cout << "4: Dem so luong so chinh phuong trong mang\n";
	cout << "5: Tinh tong cac so hoan thien trong mang\n";
	cout << "6: Tinh trung binh cong cac so doi xung trong mang\n";
	cout << "7: Kiem tra tinh chan le cua mang\n";
	cout << "8: Tim gia tri phan tu chan nho nhat trong mang\n";
	cout << "9: Sap xep mang tang dan\n";
	cout << "10: Sap xep mang giam dan\n";
	cout << "11: Xoa phan tu tai vi tri bat ky\n";
	cout << "12: Them phan tu tai vi tri bat ky\n";
	cout << "13: Tim kiem phan tu co gia tri bat ky\n";
	cout << "14: Tao mot mang ngau nhien\n";
	do
	{
		cout << "\nHay chon yeu cau ban muon thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "\nNhan phim bat ki de thoat chuong trinh..." << endl;
			return 0;
		case 1:
			cout << "< NHAP MANG >" << endl;
			cin >> *A;
			break;
		case 2:
			cout << "< XUAT MANG >" << endl;
			cout << *A;
			break;
		case 3:
			A->LietKeSoNguyenTo();
			break;
		case 4:
			A->DemSoChinhPhuong();
			break;
		case 5: 
			A->TinhTongSoHoanThien();
			break;
		case 6:
			A->TinhTrungBinhSoDoiXung();
			break;
		case 7:
			A->KiemTraChanLe();
			break;
		case 8:
			A->TimPhanTuChanNhoNhat();
			break;
		case 9: 
			A->SapXepTangDan();
			cout << "Mang sau khi duoc sap xep tang dan: " << *A;
			break;
		case 10:
			A->SapXepGiamDan();
			cout << "Mang sau khi duoc sap xep giam dan: " << *A;
			break;
		case 11:
			int x;
			cout << "Nhap vi tri cua phan tu muon xoa: ";
			cin >> x;
			A->XoaPhanTu(x);
			cout << "Mang sau khi xoa phan tu tai vi tri " << x << ": " << *A;
			break;
		case 12:
			int y, vitri;
			cout << "Nhap phan tu muon them vao mang: ";
			cin >> y;
			cout << "Nhap vi tri muon chen phan tu " << y << " vao mang: ";
			cin >> vitri;
			A->ThemPhanTu(y, vitri);
			cout << "Mang sau khi da them phan tu " << y << " vao vi tri " << vitri << ": " << endl;
			cout << *A;
			break;
		case 13: 
			int z;
			cout << "Nhap phan tu muon tim kiem: ";
			cin >> z;
			A->DemViTriXXuatHien(z);
			break;
		case 14:
			A->TaoMangNgauNhien();
			break;
		default:
			cout << "Yeu cau khong hop le, hay nhap lai yeu cau (tu 0 den 14) trong menu!" << endl;
			break;
		}
	} while (choice != 0);
}