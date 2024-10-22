#include "CDate.h"

int main()
{
	CDate Date;
	CDate Date1, Date2, Date3, Date4, Date5, Date6;
	int diff;
	int choice;
	cout << "MENU:\n";
	cout << "0: Dung chuong trinh\n";
	cout << "1: Nhap ngay, thang, nam\n";
	cout << "2: Xuat ngay, thang, nam\n";
	cout << "3: Cong them n ngay\n";
	cout << "4: Tru di n ngay\n";
	cout << "5: Them 1 ngay\n";
	cout << "6: Bot 1 ngay\n";
	cout << "7: Tinh so ngay chenh lech giua 2 moc thoi gian\n";
	do
	{
		cout << "\nNhap lua chon cua ban: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "\nNhan phim bat ki de thoat chuong trinh..." << endl;
			cout << "Da huy " << CDate::GetCount() << " ngay." << endl;
			return 0;
		case 1:
			cin >> Date;
			break;
		case 2:
			cout << "Ngay " << Date << " da duoc tao." << endl;
			break;
		case 3:
			int plus;
			cout << "3. Nhap so ngay ban muon cong them vao ngay da tao: ";
			cin >> plus;
			Date1 = Date.operator+(plus);
			cout << "Sau khi cong them, ta duoc ngay " << Date1 << endl;
			break;
		case 4:
			int minus;
			cout << "4. Nhap so ngay ban muon tru di vao ngay da tao: ";
			cin >> minus;
			Date2 = Date.operator-(minus);
			cout << "Sau khi tru di, ta duoc ngay " << Date2 << endl;
			break;
		case 5:
			Date3 = Date.operator++();
			cout << "5. Sau khi cong them mot ngay, ta duoc ngay " << Date3 << endl;
			break;
		case 6:
			Date4 = Date.operator--();
			cout << "6. Sau khi tru di mot ngay, ta duoc ngay " << Date4 << endl;
			break;
		case 7:
			cout << "7. Nhap thoi diem thu nhat: " << endl;
			cin >> Date5;
			cout << "Nhap thoi diem thu hai: " << endl;
			cin >> Date6;
			diff = Date5.operator-(Date6);
			cout << "Hai thoi diem vua nhap chenh lech nhau " << diff << " ngay." << endl;
			break;
		default:
			cout << "Lua chon khong hop le, vui long chon lai cac lua chon tu 0-7: " << endl;
			break;
		}
	} while (choice != 0);
	return 0;
}