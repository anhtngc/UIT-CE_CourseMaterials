/* nhập 2 số nguyên dương a và b, tìm ước số chung lớn nhất và bội số chung
nhỏ nhất của a và b */

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int a, b;
    cout << "nhap so nguyen duong a: ";
    cin >> a;
    if (a < 1)
    {
        do
        {
            cout << "a la so nguyen duong, xin hay nhap lai: ";
            cin >> a;
        } while (a < 1);
    }
    cout << "nhap so nguyen duong b: ";
    cin >> b;
    if (b < 1)
    {
        do
        {
            cout << "b la so nguyen duong, xin hay nhap lai: ";
            cin >> b;
        } while (b < 1);
    }
    int ucln = 1, min;
    if (a < b)
        min = a;
        else
            min = b;
        for (int i = 1; i <= min; i++)
        {
            if (a % b == 0 && b % i == 0)
                ucln = i;
        }
    cout << "uoc chung lon nhat cua " << a << " va " << b << " la: " << ucln << endl;
    int bcnn, max;
    if (a > b)
        max = a;
        else
            max = b;
    int j = max;
    while (1)
    {
        if(j % a == 0 && j % b == 0)
            {
                bcnn = j;
                break;
            }
            j += max;
    }
    cout << "boi chung nho nhat cua " << a << " va " << b << " la: " << bcnn << endl;
}
