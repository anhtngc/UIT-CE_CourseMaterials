#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    float a,b,c;
    cout << "nhap so thuc a: ";
    cin >> a;
    cout << "nhap so thuc b: ";
    cin >> b;
    cout << "nhap so thuc c: ";
    cin >> c;
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0) cout << "phuong trinh co vo so nghiem." << endl;
            else cout << "phuong trinh vo nghiem." << endl;
        }
        else cout << "phuong trinh co nghiem duy nhat: " << -c/b << endl;
    }
    else
    {
        float x1,x2,delta;
        delta=b*b-4*a*c;
        if (delta < 0) cout << "phuong trinh vo nghiem." << endl;
        else
                if (delta == 0) cout << "phuong trinh co nghiem kep: x1 = x2 = " << -b/(2*a) << endl;
                else cout << "phuong trinh co hai nghiem phan biet: x1 = " << (-b+sqrt(delta))/(2*a)
                      << " va x2 = " << (-b-sqrt(delta))/(2*a) << endl;
    }
    return 0;
}
