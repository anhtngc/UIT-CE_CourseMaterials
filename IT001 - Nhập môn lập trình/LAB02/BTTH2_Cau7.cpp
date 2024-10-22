#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char a;
    cout << "nhap mot chu cai: ";
    cin >> a;
    if (a >= 'A' && a <= 'Z')
    {
        char k = char(a) + 32;
        cout << "Chu in thuong cua " << a << " la: " << char(k) << endl;
    }
    else
    {
        if (a >= 'a' && a <= 'z' )
        {
            char k = char(a) - 32;
            cout << "Chu in hoa cua " << a << " la: " << char(k) << endl;
        }
    }
    return 0;
}
