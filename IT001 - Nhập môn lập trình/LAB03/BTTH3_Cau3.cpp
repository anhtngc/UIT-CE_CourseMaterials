/* viết chương trình in bảng cửu chương ra màn hình */

#include <iostream>

using namespace std;

int main()
{
    int n;
    for (int i = 1; i <= 10; i++)
    {
        cout << "bang cuu chuong " << i << endl;
        for (int j = 1; j <= 10; j++)
        cout << " " << i << " x " << j << " = " << j * i << endl;
    }
    return 0;
}
