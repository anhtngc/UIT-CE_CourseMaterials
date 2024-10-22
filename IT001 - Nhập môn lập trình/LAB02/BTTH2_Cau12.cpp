#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    do
    {
        cout << "nhap so nguyen duong n: ";
        cin >> n;
    } while (n <= 0);
    int i = sqrt(n);
    if (i * i == n)
        cout << n << " la so chinh phuong." << endl;
    else cout << n << " khong phai la so chinh phuong." << endl;
}
