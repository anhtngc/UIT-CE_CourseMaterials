#include <iostream>
using namespace std;
int main()
{
    int a,b,c,min;
    cout << "nhap so nguyen a: ";
    cin >> a;
    cout << "nhap so nguyen b: ";
    cin >> b;
    cout << "nhap so nguyen c: ";
    cin >> c;
    min = a;
    if (b < min)
    {
        if (c < min)
            min = c;
        else min = b;
    }
    else
    {
        if (c < min)
            min = c;
        else min = a;
    }
    cout << "gia tri nho nhat trong ba so a, b, c la: " << min << endl;
}
