#include "HinhChuNhat.h"

int main()
{
	Point A, C;
    Rectangle ABCD(A, C);
	int choice;
	do
	{
        cout << "\nMENU\n";
        cout << "0: Dung chuong trinh\n";
        cout << "1. Nhap toa do 2 dinh duong cheo trong hinh chu nhat ABCD\n";
        cout << "2. Xuat toa do 2 dinh duong cheo trong hinh chu nhat ABCD\n";
        cout << "3: Tinh chu vi hinh chu nhat." << endl;
        cout << "4: Tinh dien tich hinh chu nhat." << endl;
        cout << "5: Sua toa do diem A" << endl;
        cout << "6: Sua toa do diem C" << endl;
        cout << "7: Di chuyen hinh chu nhat" << endl;
        cout << "Nhap lua chon tu 0-7 cua ban: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Nhan phim bat ki de thoat chuong trinh...\n";
            break;
        case 1:
            cout << "\n1. Nhap toa do 2 dinh duong cheo trong hinh chu nhat ABCD\n";
            ABCD.NhapHCN();
            break;
        case 2:
            cout << "\n2. Xuat toa do 2 dinh duong cheo trong hinh chu nhat ABCD\n";
            cout << ABCD;
            break;
        case 3:
            if (ABCD.KiemTraHCN()) 
            {
                double chuvi = ABCD.TinhChuViHCN();
                cout << "\n3. Chu vi cua hinh chu nhat ABCD la: " << chuvi << endl;
            }
            else 
            {
                cout << "Hai diem tren khong the tao thanh duong cheo cua hinh chu nhat, vui long thu lai." << endl;
            }
            break;
        case 4:
            if (ABCD.KiemTraHCN()) 
            {
                double dientich = ABCD.TinhDienTichHCN();
                cout << "\n4. Dien tich cua hinh chu nhat ABCD la: " << dientich << endl;
            }
            else 
            {
                cout << "Hai diem tren khong the tao thanh duong cheo cua hinh chu nhat, vui long thu lai." << endl;
            }
            break;
        case 5:
            cout << "\n5. Nhap toa do diem A\n";
            cin >> A;
            ABCD.SetA(A);
            break;
        case 6:
            cout << "\n6. Nhap toa do diem C\n";
            cin >> C;
            ABCD.SetB(C);
            break;
        case 7:
            cout << "\n7. Di chuyen hai dinh van giu nguyen hinh chu nhat\n";
            int a, b;
            cout << "Nhap x: ";
            cin >> a;
            cout << "Nhap y: ";
            cin >> b;
            ABCD.DiChuyenHCN(a, b);
            break;
        default:
            cout << "Lua chon cua ban khong hop le, vui long chon lai cac so tu 0-7." << endl;
            break;
        }
    } while (choice != 0);
	return 0;
}