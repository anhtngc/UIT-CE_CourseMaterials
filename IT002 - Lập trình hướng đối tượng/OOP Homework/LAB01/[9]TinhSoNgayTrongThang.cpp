// Tính số ngày trong tháng ứng với tháng và năm được nhập vào

#include <iostream>

using namespace std;

struct Date
{
    int day, month, year;
};

void GetInformation(Date& d)
{
    cout << "Month: ";
    cin >> d.month;
    while (d.month > 12 || d.month < 1)
    {
        cout << "Invalid month, enter a valid month (from 1 to 12): ";
        cin >> d.month;
    }
    cout << "Year: ";
    cin >> d.year;
    while (d.year < 0)
    {
        cout << "Invalid year, enter a valid year: ";
        cin >> d.year;
    }
}

int DaysInMonth(Date& d)
{
    int days = 0;
    switch (d.month) 
    {
        case 1:     // January
        case 3:     // March
        case 5:     // May
        case 7:     // July
        case 8:     // August
        case 10:    // October
        case 12:    // December
            days = 31;
            break;
        case 4:     // April
        case 6:     // June
        case 9:     // September
        case 11:    // November
            days = 30;
            break;
        case 2:     // February
            if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)    // leap year
            { 
                days = 29;
            }
            else 
            {
                days = 28;
            }
            break;
    }
    return days;
}

int main()
{
    Date d;
    int day;
    GetInformation(d);
    day = DaysInMonth(d);
    cout << "\n" << d.month << "/" << d.year << " has " << day << " days." << endl;
    return 0;
}

