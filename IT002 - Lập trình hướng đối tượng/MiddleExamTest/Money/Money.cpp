#include "MONEY.h"

int main()
{
    MONEY m;
    int choice;
    int x;
    int tygia;
    int VND;
    cout << "MENU CLASS MONEY" << endl;
    cout << "0: Dung chuong trinh" << endl;
    cout << "1: Nhap MONEY" << endl;
    cout << "2: Xuat MONEY" << endl;
    cout << "3: Thay doi gia tri dollar" << endl;
    cout << "4: Thay doi gia tri cent" << endl;
    cout << "5: Doi sang VND voi ty gia bat ky" << endl;
    cout << "6: Tang len 1 cent" << endl;
    do
    {
        cout << "\nNhap bai toan ban muon lam: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "CHUONG TRINH DA KET THUC" << endl;
            cout << "Nhan phim bat ky de thoat chuong trinh" << endl;
            return 0;
        case 1:
            cout << "Nhap gia tri MONEY: " << endl;
            cin >> m;
            break;
        case 2:
            cout << "Gia tri MONEY vua nhap: ";
            cout << m;
            break;
        case 3:
            int x;
            cout << "Nhap gia tri dollar can thay doi: ";
            cin >> x;
            m.SetDollar(x);
            cout << "Sau khi thay doi dollar, MONEY hien tai la: " << m;
            break;
        case 4:
            cout << "Nhap gia tri cent can thay doi: ";
            cin >> x;
            m.SetCent(x);
            cout << "Sau khi thay doi cent, MONEY hien tai la: " << m;
            break;
        case 5:
            cout << "Nhap ty gia bat ky ban muon doi MONEY sang VND: ";
            cin >> tygia;
            cout << "1 cent = " << tygia << " VND" << endl;
            VND = m.To_VND(tygia);
            cout << "Sau khi doi sang VND, ta duoc: " << VND << " VND" << endl;
            break;
        case 6: 
            ++m;
            cout << "Sau khi tang money len 1 cent" << endl;
            cout << m;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long nhap lai cac lua chon tu 0 den 6!" << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}