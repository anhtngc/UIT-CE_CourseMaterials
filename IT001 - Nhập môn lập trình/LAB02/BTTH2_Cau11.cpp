#include <iostream>
using namespace std;
int main()
{
    int s,t1,t2,t3;
    cout << "nhap so km da di duoc: ";
    cin >> s;
    t1 = 15000 + (s - 1) * 13500;
    t2 = t1 + (s - 5) * 11000;
    t3 = t2 *(90 / 100);
    if (s > 1)
    {
        if (2 <= s <=5) cout << "so tien phai tra la: " << t1 << "d" << endl;
        else
            if (6 <= s <= 120) cout << "so tien phai tra la: " << t2 << "d" << endl;
            else cout << "so tien phai tra la: " << t3 << "d" << endl;
    }
    else cout << "so tien phai tra la 15000d" << endl;
    return 0;
}
