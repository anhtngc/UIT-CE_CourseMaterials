/* nhập vào một số nguyên dương n. hãy cho biết các chữ số có tăng dần hay
giảm dần không? */

#include <iostream>

using namespace std;

void check(int n)
{
	int st = n % 10, ss, kt1 = 0, kt2 = 0;
	n = n / 10;
	while (n != 0)
	{
		ss = n % 10;
		if (st < ss) kt1 = 1;
		if (st > ss) kt2 = 1;
		st = ss;
		n = n / 10;
	}
	if (kt1 == 0 && kt2 == 1) cout << " la so tang dan" << endl;
	if (kt2 == 0 && kt1 == 1) cout << " la so giam dan" << endl;
	if (kt1 == 1 && kt2 == 1 || kt1 == 0 && kt2 == 0) cout << " la so khong tang va khong giam." << endl;
}

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
    cout << n;
    check(n);
    return 0;
}
