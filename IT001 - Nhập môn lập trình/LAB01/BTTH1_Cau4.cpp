#include <iostream>
using namespace std;
int main()
{
    int N,a,b;
    cout<<"Nhap so nguyen N gom 2 chu so: ";
    cin>>N;
    a=N/10;
    b=N%10;
    cout<<"Tong cac chu so nguyen N: " << a << "+" << b << "=" << a+b;
}
