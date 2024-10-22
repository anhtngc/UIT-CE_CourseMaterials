/* nhập vào một số nguyên dương n. tính S = 13 + 23 +......+ n3 */

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
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        s = s + i*10 + 3;
    }
    cout << "s = " << s << endl;
}
