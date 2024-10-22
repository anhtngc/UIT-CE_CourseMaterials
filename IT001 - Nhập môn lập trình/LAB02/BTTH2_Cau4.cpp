#include <iostream>
using namespace std;
int main()
{
    float a,b;
    cout << "nhap a: ";
    cin >> a;
    cout << "nhap b: ";
    cin >> b;
    if (a == 0)
    {
        if (b == 0)
            cout << "phuong trinh co vo so nghiem." << endl;
        else cout << "phuong trinh vo nghiem." << endl;
    }
    else cout << "phuong trinh co nghiem duy nhat: x = " << -b/a << endl;
}
