/* Nhập vào số tiền. Hãy tính và in ra số tờ tiền tương ứng của các mệnh giá giảm dần: 500k,
200k, 100k, 50k. (giả sử đổi hết mệnh giá lớn, phần dư mới đổi sang mệnh giá nhỏ hơn). */

#include <iostream>

using namespace std;

int main() {
    int money, count = 0;
    cout << "Enter amount of money: ";
    cin >> money;
    cout << "\n";
    int values[] = { 500000, 200000, 100000, 50000, 20000, 10000, 5000, 2000, 1000 };
    int num_values = sizeof(values) / sizeof(values[0]);
    int bills;
    for (int i = 0; i < num_values; i++) 
    {
        bills = money / values[i];
        if (bills != 0) 
        {
            cout << "Need " << bills << " bills of " << values[i] << endl;
            money %= values[i];
            count += bills;
        }
    }
    cout << "\nSum of bills are: " << count << endl;
    return 0;
}