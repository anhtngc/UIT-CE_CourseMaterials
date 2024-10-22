#pragma once
#ifndef INT_DEFINITION
#include <iostream>
using namespace std;
class INTEGER
{
private:
	int data;
	static int count;
public:
	INTEGER();
	INTEGER(int);
	~INTEGER();
	static int GetCount() {
		return count;
	}
	int getData() const;
	void setData(int);
	INTEGER& operator=(int);
	INTEGER operator+(const INTEGER&) const;
	INTEGER operator-(const INTEGER&) const;
	INTEGER operator*(const INTEGER&) const;
	INTEGER operator/(const INTEGER&) const;
	INTEGER& operator++();
	INTEGER& operator--();
	bool operator==(const INTEGER&) const;
	bool operator>(const INTEGER&) const;
	bool operator<(const INTEGER&) const;
	friend ostream& operator<<(ostream&, const INTEGER&);
	friend istream& operator>>(istream&, INTEGER&);
};
#endif // !INT_DEFINITION

