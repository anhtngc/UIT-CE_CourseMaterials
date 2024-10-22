#pragma once
#ifndef _MONEY
#define _MONEY
#include <iostream>
using namespace std;

class MONEY
{
private:
	int dollar;
	int cent;
public:
	~MONEY();
	MONEY();
	MONEY(int, int);
	MONEY(const MONEY&);
	int GetDollar();
	int GetCent();
	void SetDollar(int);
	void SetCent(int);
	int To_VND(int);
	MONEY& operator++();
	friend istream& operator>>(istream& is, MONEY& m);
	friend ostream& operator<<(ostream& os, MONEY& m);
};

#endif // _MONEY
