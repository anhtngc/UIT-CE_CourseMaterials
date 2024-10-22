/* nhập vào một số nguyên dương n. đếm số lượng chữ số, tính tổng các chữ số
của số nguyên dương n. */

#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "nhap so nguyen duong n: ";
    cin >> n;
    if (n < 1)
    {
        do
        {
            cout << "n phai la so nguyen duong, xin hay nhap lai: ";
            cin >> n;
        } while (n < 1);
    }
    int dem = 0, sum = 0;
    while (n != 0)
    {
        sum = sum + n % 10;
        n = n / 10;
        dem++;
    }
    cout << "n co tong cong " << dem << " chu so" << endl;
    cout << "tong cac chu so cua n la: " << sum << endl;
}
