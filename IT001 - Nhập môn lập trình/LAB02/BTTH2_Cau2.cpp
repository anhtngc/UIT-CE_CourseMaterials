#include <iostream>
using namespace std;
int main()
{
    int a,b,c,max;
    cout << "nhap so nguyen a: ";
    cin >> a;
    cout << "nhap so nguyen b: ";
    cin >> b;
    cout << "nhap so nguyen c: ";
    cin >> c;
    max = a;
    if (b > max)
    {
        if (c > max)
            max = c;
        else max = b;
    }
    else
    {
        if (c > max)
            max = c;
        else max = a;
    }
    cout << "gia tri nho nhat trong ba so a, b, c la: " << max << endl;
}
