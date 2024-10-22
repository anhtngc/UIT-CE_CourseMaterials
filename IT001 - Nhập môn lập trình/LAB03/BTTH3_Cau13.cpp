/* nhập vào một số nguyên dương n. đếm số lượng chữ số chẵn/lẻ của số nguyên
dương n */

#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "nhap vao so nguyen duong n: ";
    cin >> n;
    if (n < 1)
    {
        do
        {
            cout << "nhap lai so nguyen duong n: ";
            cin >> n;
        } while (n < 1);
    }
    long temp = n;
    int count1 = 0, count2 = 0;
    if (n == 0)
        count1 = 1;
    while (temp != 0)
    {
        if (temp % 2 == 1)
        {
            count1++;
            temp = temp / 10;
        }
        else
        {
            if (temp % 2 == 0 || temp == 0)
            {
                count2++;
                temp = temp / 10;
            }
        }
    }
    cout << "n co " << count1 << " chu so le." << endl;
    cout << "n co " << count2 << " chu so chan." << endl;
}
