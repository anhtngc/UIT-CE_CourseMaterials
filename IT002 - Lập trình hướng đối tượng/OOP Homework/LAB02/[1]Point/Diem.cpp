#include "Diem.h"

int main()
{
// Khởi tạo điểm, nhập và xuất điểm
	Point A(2, -2.7), C;
	Point* B = new Point;
	cout << "Chuong trinh da khoi tao 2 diem cho ban: " << endl;
	cout << "Diem A";
	A.XuatDiem();
	cout << "\n";
	cout << "Diem B";
	B->XuatDiem();
	cout << "\n";
	int choice;
	cout << "\nBan co muon thay doi diem A?" << endl;
	cout << "1: Co" << endl;
	cout << "2: Khong" << endl;
	cin >> choice;
	double ax, ay;
	while (choice != 1 && choice != 2)
	{
		cout << "Ban chi duoc chon so (1 va 2) tuong ung voi 2 lua chon tren, moi ban chon lai: ";
		cin >> choice;
	}
	if (choice == 1)
	{
		cout << "Nhap hoanh do diem A: ";
		cin >> ax;
		cout << "Nhap tung do diem A: ";
		cin >> ay;
		A.SetX(ax);
		A.SetY(ay);
		cout << "Sau khi lay x = " << ax << " va y = " << ay << ", toa do diem A la A";
		A.XuatDiem();
		cout << "\n";
	}
	else if (choice == 2)
	{
		cout << "Toa do diem A";
		A.XuatDiem();
		cout << " duoc giu nguyen." << endl;
	}
	cout << "\nLam moi toa do diem B." << endl;
	B->NhapDiem();
	cout << "Diem B";
	B->XuatDiem();
	cout << " da duoc tao.\n";
	cout << "\nTao toa do diem C." << endl;
	C.NhapDiem();
	cout << "Diem C";
	C.XuatDiem();
	cout << " da duoc tao.\n";
// Menu thực hiện các phương thức khác
	int n;
	cout << "\nMENU" << endl;
	cout << "0: Dung chuong trinh" << endl;
	cout << "1: Di chuyen mot diem" << endl;
	cout << "2: Kiem tra 2 diem co toa do trung nhau khong" << endl;
	cout << "3: Tinh khoang cach giua hai diem" << endl;
	cout << "4: Lay doi xung 1 diem qua goc toa do" << endl;
	cout << "5: Tinh chu vi tam giac ABC" << endl;
	cout << "6: Tinh dien tich tam giac ABC" << endl;
	cout << "7: Phan loai tam giac ABC" << endl;
	cout << "Chon bai toan (tu 1 den 7) ban muon thuc hien: ";
	cin >> n;
	while (n != 0)
	{
		if (n == 1)
		{
			int move;
			cout << "\n1: Diem A" << endl;
			cout << "2: Diem B" << endl;
			cout << "3: Diem C" << endl;
			cout << "Chon diem ban muon di chuyen: ";
			cin >> move;
			while (move != 1 && move != 2 && move != 3)
			{
				cout << "Ban chi duoc chon so (1, 2 va 3) tuong ung voi 3 lua chon tren, moi ban chon lai: ";
				cin >> move;
			}
			double dx, dy;
			if (move == 1)
			{
				cout << "Di chuyen hoanh do diem A them/bot di: ";
				cin >> dx;
				cout << "Di chuyen tung do diem A them/bot di: ";
				cin >> dy;
				A.DiChuyenDiem(dx, dy);
				cout << "Sau khi di chuyen diem A (dx = " << dx << ", dy = " << dy << "), ta duoc diem A";
				A.XuatDiem();
				cout << "\n";
			}
			else if (move == 2)
			{
				cout << "Di chuyen hoanh do diem B them/bot di: ";
				cin >> dx;
				cout << "Di chuyen tung do diem B them/bot di: ";
				cin >> dy;
				B->DiChuyenDiem(dx, dy);
				cout << "Sau khi di chuyen diem B (dx = " << dx << ", dy = " << dy << "), ta duoc diem B";
				B->XuatDiem();
				cout << "\n";
			}
			else if (move == 3)
			{
				cout << "Di chuyen hoanh do diem C them/bot di: ";
				cin >> dx;
				cout << "Di chuyen tung do diem C them/bot di: ";
				cin >> dy;
				C.DiChuyenDiem(dx, dy);
				cout << "Sau khi di chuyen diem B (dx = " << dx << ", dy = " << dy << "), ta duoc diem C";
				C.XuatDiem();
				cout << "\n";
			}
			cout << "\nChon bai toan ban muon thuc hien: ";
			cin >> n;
		}
		if (n == 2)
		{
			int check;
			cout << "\n1: Diem A va diem B" << endl;
			cout << "2: Diem B va diem C" << endl;
			cout << "3: Diem A va diem C" << endl;
			cout << "Chon hai diem ban muon kiem tra trung nhau: ";
			cin >> check;
			while (check != 1 && check != 2 && check != 3)
			{
				cout << "Ban chi duoc chon so (1, 2 va 3) tuong ung voi 3 lua chon tren, moi ban chon lai: ";
				cin >> check;
			}
			if (check == 1)
			{
				if (B->KiemTraTrungNhau(A))
					cout << "Diem A va diem B trung nhau." << endl;
				else
					cout << "Diem A va diem B khong trung nhau." << endl;
			}
			if (check == 2)
			{
				if (B->KiemTraTrungNhau(C))
					cout << "Diem B va diem C trung nhau." << endl;
				else
					cout << "Diem B va diem C khong trung nhau." << endl;
			}
			if (check == 3)
			{
				if (A.KiemTraTrungNhau(C))
					cout << "Diem A va diem C trung nhau." << endl;
				else
					cout << "Diem A va diem C khong trung nhau." << endl;
			}
			cout << "\nChon bai toan ban muon thuc hien: ";
			cin >> n;
		}
		if (n == 3)
		{
			int distance;
			cout << "\n1: Khoang cach giua hai diem A va B" << endl;
			cout << "2: Khoang cach giua hai diem B va C" << endl;
			cout << "3: Khoang cach giua hai diem A va C" << endl;
			cout << "Chon khoang cach ma ban muon chuong trinh thuc hien: ";
			cin >> distance;
			while (distance != 1 && distance != 2 && distance != 3)
			{
				cout << "Ban chi duoc chon so (1, 2 va 3) tuong ung voi 3 lua chon tren, moi ban chon lai: ";
				cin >> distance;
			}
			if (distance == 1)
				cout << "Khoang cach giua hai diem A va B la: " << B->TinhKhoangCach(A) << endl;
			if (distance == 2)
				cout << "Khoang cach giua hai diem B va C la: " << B->TinhKhoangCach(C) << endl;
			if (distance == 3)
				cout << "Khoang cach giua hai diem A va C la: " << A.TinhKhoangCach(C) << endl;
			cout << "\nChon bai toan ban muon thuc hien: ";
			cin >> n;
		}
		if (n == 4)
		{
			int symmetric;
			cout << "\n1: Diem A" << endl;
			cout << "2: Diem B" << endl;
			cout << "3: Diem C" << endl;
			cout << "Chon diem ban muon lay doi xung qua goc toa do: ";
			cin >> symmetric;
			while (symmetric != 1 && symmetric != 2 && symmetric != 3)
			{
				cout << "Ban chi duoc chon so (1, 2 va 3) tuong ung voi 3 lua chon tren, moi ban chon lai: ";
				cin >> symmetric;
			}
			if (symmetric == 1)
			{
				A.LayDoiXung();
				cout << "Diem doi xung cua A qua goc toa do la A'";
				A.XuatDiem();
				cout << "\n";
			}
			if (symmetric == 2)
			{
				B->LayDoiXung();
				cout << "Diem doi xung cua B qua goc toa do la B'";
				B->XuatDiem();
				cout << "\n";
			}
			if (symmetric == 3)
			{
				C.LayDoiXung();
				cout << "Diem doi xung cua C qua goc toa do la C'";
				C.XuatDiem();
				cout << "\n";
			}
			cout << "\nChon bai toan ban muon thuc hien: ";
			cin >> n;
		}
		if (n == 5)
		{
			if (B->KiemTraTamGiac(A, C))
				cout << "\nChu vi cua tam giac ABC la " << B->TinhChuViTamGiac(A, C) << "." << endl;
			else
				cout << "\nKhong the tinh chu vi duoc vi ba diem A, B va C khong tao thanh mot tam giac." << endl;
			cout << "\nChon bai toan ban muon thuc hien: ";
			cin >> n;
		}
		if (n == 6)
		{
			if (B->KiemTraTamGiac(A, C))
				cout << "\nDien tich tam giac ABC la " << B->TinhDienTichTamGiac(A, C) << "." << endl;
			else
				cout << "\nKhong the tinh dien tich duoc vi ba diem A, B va C khong tao thanh mot tam giac." << endl;
			cout << "\nChon bai toan ban muon thuc hien: ";
			cin >> n;
		}
		if (n == 7)
		{
			if (B->KiemTraTamGiac(A, C))
				cout << "\nABC la " << B->PhanLoaiTamGiac(A, C) << endl;
			else
				cout << "\nKhong the phan loai duoc vi ba diem A, B va C khong tao thanh mot tam giac." << endl;
			cout << "\nChon bai toan ban muon thuc hien: ";
			cin >> n;
		}
		else if (n < 0 || n > 7)
		{
			cout << "\nBan chi duoc chon 7 lua chon trong bang MENU, moi ban chon lai: ";
			cin >> n;
		}
	}
	return 0;
}