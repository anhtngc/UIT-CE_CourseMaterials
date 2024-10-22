#include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    do
    {
        cout << "nhap so nguyen duong a: ";
        cin >> a;
    } while(a <= 0);
    do
    {
        cout << "nhap so nguyen duong b: ";
        cin >> b;
    } while(b <= 0);
    do
    {
        cout << "nhap so nguyen duong c: ";
        cin >> c;
    } while(c <= 0);
    if (a+b>c && b+c>a && a+c>b)
    {
        if (a*a==b*b+c*c || b*b==a*a+c*c || c*c==b*b+a*a)
            cout << "day la tam giac vuong." << endl;
        else
            if (a*a<b*b+c*c || b*b<a*a+c*c || c*c<b*b+a*a)
                cout << "day la tam giac nhon." << endl;
            else cout << "day la tam giac tu." << endl;
    }
    else cout << "day khong phai ba canh cua tam giac." << endl;
    return 0;
}
