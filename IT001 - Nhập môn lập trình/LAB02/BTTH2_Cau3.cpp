#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "nhap mot so nguyen bat ky: ";
    cin >> n;
    switch(n)
    {
        case 1: cout << "so mot" << endl;
        break;
        case 2: cout << "so hai" << endl;
        break;
        case 3: cout << "so ba" << endl;
        break;
        case 4: cout << "so bon" << endl;
        break;
        case 5: cout << "so nam" << endl;
        break;
        case 6: cout << "so sau" << endl;
        break;
        case 7: cout << "so bay" << endl;
        break;
        case 8: cout << "so tam" << endl;
        break;
        case 9: cout << "so chin" << endl;
        break;
        default: cout << "khong doc duoc" << endl;
    }
    return 0;
}
