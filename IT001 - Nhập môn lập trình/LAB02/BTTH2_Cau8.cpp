#include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    int tg;
    cout << "nhap a: ";
    cin >> a;
    cout << "nhap b: ";
    cin >> b;
    cout << "nhap c: ";
    cin >> c;
    for (int i=0;i<=3;i++)
    {
        if (a > b)
        {
            tg = a;
            a = b;
            b = tg;
        }
        else if (b > c)
        {
            tg = b;
            b = c;
            c = tg;
        }
        else if (a>c)
        {
            tg = a;
            a = c;
            c = tg;
        }
    }
    cout << "Day so duoc sap theo thu tu tang dan: " << a << ", " << b << ", " << c << endl;
    return 0;
}
