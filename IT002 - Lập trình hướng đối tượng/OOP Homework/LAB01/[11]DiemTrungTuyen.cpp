/* Nhập điểm chuẩn và điểm 3 môn thi, mã khu vực (A, B, C), mã đối tượng (1, 2, 3) của thí sinh.
Hiển thị kết quả “Trúng tuyển” nếu tổng điểm thi 3 môn cộng với điểm ưu tiên khu vực và
điểm ưu tiên đối tượng lớn hơn hoặc bằng điểm chuẩn và không có môn nào bị điểm liệt (0
điểm). Trong đó, điểm ưu tiên khu vực và điểm ưu tiên đối tượng được tình như sau:
• Khu vực A: cộng 1.5 điểm
• Khu vực B: cộng 1 điểm
• Khu vực C: cộng 0.5 điểm
• Đối tượng 1: cộng 1.5 điểm
• Đối tượng 2: cộng 1 điểm
• Đối tượng 3: cộng 0.5 điểm */

#include <iostream>

using namespace std;

struct ThiSinh
{
	string sbd;
	double diem1, diem2, diem3;
	int doituong;
	char khuvuc;
};

void DienThongtin(ThiSinh& x)
{
	cout << "So bao danh cua thi sinh: ";
	cin >> x.sbd;
	cout << "Diem mon thi thu nhat: ";
	cin >> x.diem1;
	while (x.diem1 < 0 && x.diem1 > 10)
	{
		cout << "Diem thi mon thu nhat khong hop le, hay nhap lai: ";
		cin >> x.diem1;
	}
	cout << "Diem mon thi thu hai: ";
	cin >> x.diem2;
	while (x.diem2 < 0 && x.diem2 > 10)
	{
		cout << "Diem thi mon thu hai khong hop le, hay nhap lai: ";
		cin >> x.diem2;
	}
	cout << "Diem mon thi thu ba: ";
	cin >> x.diem3;
	while (x.diem3 < 0 && x.diem3 > 10)
	{
		cout << "Diem thi mon thu ba khong hop le, hay nhap lai: ";
		cin >> x.diem3;
	}
	cout << "Ma khu vuc cua thi sinh (A, B, C): ";
	cin >> x.khuvuc;
	while (x.khuvuc != 'A' && x.khuvuc != 'B' && x.khuvuc != 'C')
	{
		cout << "Ma khu vuc khong hop le, hay nhap lai: ";
		cin >> x.khuvuc;
	}
	cout << "Ma doi tuong cua thi sinh (1, 2, 3): ";
	cin >> x.doituong;
	while (x.doituong != 1 && x.doituong != 2 && x.doituong != 3)
	{
		cout << "Ma doi tuong khong hop le, hay nhap lai: ";
		cin >> x.doituong;
	}
}

double TongDiem(ThiSinh x)
{
	double kv, dt;
	if (x.khuvuc == 'A')
	{
		kv = 1.5;
	}
	else if (x.khuvuc = 'B')
	{
		kv = 1.0;
	}
	else kv = 0.5;
	if (x.doituong == 1)
	{
		dt = 1.5;
	}
	else if (x.doituong == 2)
	{
		dt = 1.0;
	}
	else dt = 0.5;
	return x.diem1 + x.diem2 + x.diem3 + kv + dt;
}

int main()
{
	ThiSinh x;
	int diemchuan;
	cout << "Nhap diem chuan cua nganh: ";
	cin >> diemchuan;
	DienThongtin(x);
	double diemthi = TongDiem(x);
	if (x.diem1 == 0 || x.diem2 == 0 || x.diem3 == 0)
	{
		cout << "\nBan co diem liet. Chung toi rat tiec phai thong bao rang ban khong trung tuyen vao Truong Dai hoc Cong nghe Thong tin, DHQG-HCM." << endl;
		return 0;
	}
	else cout << "\nTong diem thi cua ban la: " << diemthi << endl;
	if (diemthi >= diemchuan)
	{
		cout << "Chuc mung thi sinh co so bao danh " << x.sbd << " da trung tuyen vao Truong Dai hoc Cong nghe Thong tin, DHQG-HCM." << endl;
	}
	else cout << "Thi sinh co so bao danh " << x.sbd << " khong trung tuyen vao Truong Dai hoc Cong nghe Thong tin, DHQG-HCM." << endl;
	return 0;
}