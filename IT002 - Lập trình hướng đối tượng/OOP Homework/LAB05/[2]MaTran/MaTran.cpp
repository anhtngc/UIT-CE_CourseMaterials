#include "MATRAN.h"

int main()
{
    MATRAN m;
    cout << "MENU\n";
    cout << "0: Dung chuong trinh\n";
    cout << "1: Nhap gia tri cac phan tu ma tran\n";
    cout << "2: Xuat gia tri cac phan tu ma tran\n";
    cout << "3: Liet ke cac phan tu la so nguyen to cua ma tran\n";
    cout << "4: Dem so luong phan tu la so chinh phuong cua ma tran\n";
    cout << "5: Tinh tong cac so hoan thien tren dong k cua ma tran\n";
    cout << "6: Tinh trung binh cong cac phan tu la so doi xung tren cot k cua ma tran\n";
    cout << "7: Sap xep tang dan cac phan tu tren dong k cua ma tran\n";
    cout << "8: Tao ma tran ngau nhien\n";
    int choice;
    int k;
    do
    {
        cout << "\nNhap yeu cau ban muon chuong trinh thuc hien: ";
        cin >> choice;
        switch (choice) {
        case 0:
            cout << "\nCHUONG TRINH DA KET THUC" << endl;
            cout << "Nhan phim bat ky de thoat chuong trinh..." << endl;
            return 0;
        case 1:
            cout << "Nhap cac gia tri cac phan tu cho ma tran" << endl;
            cin >> m;
            break;
        case 2:
            cout << "Xuat gia tri cac phan tu ma tran" << endl;
            cout << m;
            break;
        case 3:
            cout << "Cac phan tu la so nguyen to cua ma tran gom: ";
            m.LietKeSoNguyenTo();
            break;
        case 4:
            cout << "So luong cac phan tu la so chinh phuong cua ma tran la: " << m.DemSoChinhPhuong() << endl;
            break;
        case 5:
            cout << "Nhap thu tu dong muon tinh tong so hoan thien: ";
            cin >> k;
            while (k < 0 || k > m.GetROW())
            {
                cout << "Nhap thu tu dong trong ma tran (" << "tu 0 den " << m.GetROW() - 1 << "): ";
                cin >> k;
            }
            cout << "Tong cac phan tu la so hoan thien tren dong " << k << " la: " << m.TinhTongSoHoanThien(k) << endl;
            break;
        case 6:
            cout << "Nhap thu tu cot muon tinh trung binh so doi xung cua ma tran: ";
            cin >> k;
            while (k < 0 || k > m.GetCOL())
            {
                cout << "Nhap thu tu dong trong ma tran (" << "tu 0 den " << m.GetCOL() - 1 << "): ";
                cin >> k;
            }
            cout << "Trung binh cong phan tu la so doi xung tren cot " << k << " la: " << m.TinhTBCSoDoiXung(k) << endl;
            break;
        case 7: 
            cout << "Nhap thu tu dong muon sap xep tang dan trong ma tran: ";
            cin >> k;
            while (k < 0 || k > m.GetROW())
            {
                cout << "Nhap thu tu dong trong ma tran (" << "tu 0 den " << m.GetROW() - 1 << "): ";
                cin >> k;
            }
            cout << "Sap xep tang dan tren dong " << k << " cua ma tran" << endl;
            m.SapXepTangDan(k);
            cout << m;
            break;
        case 8:
            m.TaoNgauNhienMaTran();
            break;
        default:
            cout << "\nLua chon khong hop le. Vui long chon lai mot lua chon tu 0 den 8!" << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}