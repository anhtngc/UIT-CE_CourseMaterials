#include "MATRANVUONG.h"

int main()
{
    MATRANVUONG m;
    cout << "MENU\n";
    cout << "0: Dung chuong trinh\n";
    cout << "1: Nhap gia tri cac phan tu cua ma tran\n";
    cout << "2: Xuat gia tri cac phan tu cua ma tran\n";
    cout << "3: Liet ke gia tri cac phan tu le nam tren duong cho chinh cua ma tran\n";
    cout << "4: Dem so luong cac phan tu co ky tu cuoi la 3 nam tren duong cheo phu cua ma tran\n";
    cout << "5: Kiem tra xem co ton tai phan tu am o nua mang vuong phia tren duong cheo chinh khong\n";
    cout << "6: Tim phan tu chan dau tien ơ nua mang vuong phia duoi duong cheo phu cua ma tran\n";
    cout << "7: Sap xep giam dan cac phan tu tren duong cheo phu cua ma tran\n";
    cout << "8: Tao mot ma tran vuong ngau nhien\n";
    int choice;
    int findx;
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
            cin >> m;
            break;
        case 2: 
            cout << "Xuat gia tri cac phan tu cua ma tran vuong:" << endl;
            cout << m;
            break;
        case 3:
            cout << "Cac phan tu la so le tren duong cheo chinh gom: ";
            m.LietKeSoLeTrenDCheoChinh();
            break;
        case 4:
            cout << "So luong cac so co ky tu so cuoi la 3 o mang duoi duong cheo phu cua ma tran la: " << m.DemSoLuongPhanTuCoKyTuSoCuoiLa3() << endl;
            break;
        case 5:
            if (m.KiemTraNuaMang()) {
                cout << "Nua mang vuong tren duong cheo chinh co gia tri am." << endl;
            }
            else
                cout << "Nua mang vuong tren duong cheo chinh khong co gia tri am." << endl;
            break;
        case 6:
            findx = m.TimPhanTuChanMangVuongPhiaDuoiDCheoPhu();
            if (m.TimPhanTuChanMangVuongPhiaDuoiDCheoPhu() != -1)
            {
                cout << "Gia tri chan dau tien o nua mang vuong phia duoi duong cheo phu cua ma tran la: " << findx;
            }
            else
                cout << "Khong co gia tri chan o nua duoi duong cheo phu cua ma tran. " << endl;
            break;
        case 7:
            cout << "Sau khi sap xep giam dan cac phan tu tren duong cheo phu cua ma tran, ta duoc ma tran vuong moi: " << endl;
            m.SapXepGiamDanCacPhanTuNamTrenDCheoPhu();
            cout << m;
            break;
        case 8:
            m.TaoNgauNhienMaTranVuong();
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai lua chon tu 0 den 8!" << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}