#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
	string name;
	float diemToan, diemVan;
public:
	Student();
	Student(string, float, float);
	void NhapThongTin();
	void XuatThongTin();
	float TinhDiemTrungBinh();
	string XepLoaiHocSinh();
};

Student::Student()
{
	diemToan = 0;
	diemVan = 0;
	name = "";
}

Student::Student(string name, float diemToan, float diemVan)
{
	this->name = name;
	this->diemToan = diemToan;
	this->diemVan = diemVan;
}

void Student::NhapThongTin()
{
	cout << "Nhap ho va ten hoc sinh: ";
	getline(cin, name);
	cout << "Nhap diem Toan: ";
	cin >> diemToan;
	cout << "Nhap diem Van: ";
	cin >> diemVan;
}

void Student::XuatThongTin()
{
	cout << "Ho ten: " << name << "  |  ";
	cout << "Diem Toan: " << diemToan << "  |  ";
	cout << "Diem Van: " << diemVan << "  ";
}

float Student::TinhDiemTrungBinh()
{
	return (diemToan + diemVan) / 2;
}

string Student::XepLoaiHocSinh()
{
	float DTB = TinhDiemTrungBinh();
	if (DTB >= 8.0)
		return "Gioi";
	else if (DTB >= 6.5)
		return "Kha";
	else if (DTB > 5.0)
		return "Trung binh";
	else
		return "Yeu";
}

int main()
{
	Student HS;
	HS.NhapThongTin();
	cout << "\nThong tin hoc sinh: " << endl;
	HS.XuatThongTin();
	cout << endl;
	cout << "Diem trung binh: " << HS.TinhDiemTrungBinh() << endl;
	cout << "Xep loai: " << HS.XepLoaiHocSinh() << endl;
	return 0;
}