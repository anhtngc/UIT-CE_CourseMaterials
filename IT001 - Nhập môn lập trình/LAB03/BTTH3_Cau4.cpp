/* tìm số nguyên dương n nhỏ nhất sao cho: 1 + 2 + ... + n > 1000 */

#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int sum = 0;
    while (sum < 1000)
    {
        n++;
        sum = sum + n;
    }
    cout << "n nguyen duong nho nhat thoa yeu cau de bai la: " << n << endl;
}
