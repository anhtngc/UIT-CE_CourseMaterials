// Viết chương trình nhập vào một ngày. Tìm ngày kế tiếp và xuất kết quả.

#include <iostream>

using namespace std;

struct Date
{
    int day, month, year;
};

void GetInformation(Date& x, int& ValidDate)
{
    cout << "Day: ";
    cin >> x.day;
    cout << "Month: ";
    cin >> x.month;
    cout << "Year: ";
    cin >> x.year;
    switch (x.month)
    {
    case 1:     // January
    case 3:     // March
    case 5:     // May
    case 7:     // July
    case 8:     // August
    case 10:    // October
    case 12:    // December
        ValidDate = 31;
        break;
    case 4:     // April
    case 6:     // June
    case 9:     // September
    case 11:    // November
        ValidDate = 30;
        break;
    case 2:     // February
        if ((x.year % 4 == 0 && x.year % 100 != 0) || x.year % 400 == 0)    // leap year
        {
            ValidDate = 29;
        }
        else
        {
            ValidDate = 28;
        }
        break;
    default: ValidDate = 0;
    }
    if (ValidDate == 0 || x.year < 1 || (ValidDate != 0 && (x.day > ValidDate || x.day < 1)))
    {
        cout << "Day, month or year is invalid. Please enter it again!" << "\n";
        GetInformation(x, ValidDate);
    }
}

void NextDay(Date x, Date& y, int n)
{
    if (x.day < n)
    {
        y.day = x.day + 1;
        y.month = x.month;
        y.year = x.year;
    }
    else if (x.month != 12)
    {
        y.day = 1;
        y.month = x.month + 1;
        y.year = x.year;
    }
    else
    {
        y.day = 1;
        y.month = 1;
        y.year = x.year + 1;
    }
}

int main()
{
    Date D1, D2;
    int ValidDate;
    GetInformation(D1, ValidDate);
    NextDay(D1, D2, ValidDate);
    cout << "\nThe next date is: " << D2.day << "/" << D2.month << "/" << D2.year << endl;
    return 0;
}
