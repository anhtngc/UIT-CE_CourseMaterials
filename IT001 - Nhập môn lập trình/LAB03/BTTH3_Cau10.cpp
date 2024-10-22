/* nhập vào một số nguyên dương n. tính S = 1 + 1/2 + ... + 1/n. */

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
    float s = 0;
    for (int i = 1; i <= n; i++)
    {
        s = s + 1.0/i;
    }
    cout << "s = " << s << endl;
}
