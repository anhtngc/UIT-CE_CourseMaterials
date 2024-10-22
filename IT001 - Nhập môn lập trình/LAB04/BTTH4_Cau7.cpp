/* viết chương trình tính giai thừa bằng đệ quy */

#include <iostream>

using namespace std;

int giaithua(int n)
{
    if (n == 0)
        return 1;
    return n * giaithua(n - 1);
}

int main()
{
    int n;
    cout << "nhap n: ";
    cin >> n;
    if (n < 0)
    {
        do
        {
            cout << "n phai la so khong am, xin hay nhap lai: ";
            cin >> n;
        } while (n < 0);
    }
    cout << n << "! = " << giaithua(n) << endl;
}
