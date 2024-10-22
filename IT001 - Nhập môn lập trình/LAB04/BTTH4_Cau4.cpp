/* viết hàm tính chu vi và diện tích hình chữ nhật khi biết độ dài 2 cạnh. sau đó
vẽ hình chữ nhật ra màn hình bằng các dấu *. hàm tính chu vi, diện tích và hàm vẽ hình
chữ nhật phải độc lập nhau. */


#include <iostream>

using namespace std;

float chuvi(float a, float b)
{
    return (a + b) * 2;
}

float dientich(float a, float b)
{
    return a * b;
}

int hinhve(float a, float b)
{
    for (int i = 1; i <= b; i++)
    {
        for (int j = 1; j <= a; j++)
        {
            if (i == 1 || j == 1 || i == b || j == a)
            {
                cout << " * ";
            }
            else cout << "   ";
        }
        cout << endl;
    }
}

int main()
{
    float a, b;
    cout << "nhap chieu dai: ";
    cin >> a;
    cout << "nhap chieu rong: ";
    cin >> b;
    if (a < 1 || b < 1)
    {
        do
        {
            cout << "chieu dai phai la so duong, hay nhap lai: ";
            cin >> a;
            cout << "chieu rong phai la so duong, hay nhap lai: ";
            cin >> b;
        } while (a < 1 || b < 1);
    }
    else
    {
        cout << "chu vi hinh chu nhat: " << chuvi(a,b) << endl;
        cout << "dien tich hinh chu nhat: " << dientich(a,b) << endl;
        cout << "hinh chu nhat " << a << " x " << b << " co dang:" << endl << hinhve(a,b);
    }
}

