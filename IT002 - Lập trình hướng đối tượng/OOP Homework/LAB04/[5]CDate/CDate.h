#pragma once
#ifndef _CDate
#include <iostream>
using namespace std;
class CDate
{
private:
	int day;
	int month;
	int year;
	static int count;
public:
	CDate();
	CDate(int, int, int);
	~CDate();
	static int GetCount() {
		return count;
	}
	CDate operator+(int);
	CDate operator-(int);
	CDate operator++();
	CDate operator--();
	int setThuTuChoNgay();
	int DaysInAYear(int);
	int operator-(CDate&);
	int daysInAMonth(int, int);
	friend istream& operator>>(istream&, CDate&);
	friend ostream& operator<<(ostream&, CDate&);
};
#endif // !_CDate

