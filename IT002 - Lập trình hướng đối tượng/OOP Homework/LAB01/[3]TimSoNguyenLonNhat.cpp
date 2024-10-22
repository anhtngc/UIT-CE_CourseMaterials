// Tìm số lớn nhất trong 3 số nguyên.

#include <iostream>

using namespace std;

struct Number
{
	int a, b, c;
};

void GetInformation(Number& n)
{
	cout << "Enter 3 integers: " << endl;
	cin >> n.a >> n.b >> n.c;
}

int CheckMax(Number& n)
{
	return (n.a > n.b) ? ((n.a > n.c) ? n.a : n.c) : ((n.b > n.c) ? n.b : n.c);
}

int main()
{
	Number n;
	int number;
	GetInformation(n);
	number = CheckMax(n);
	cout << "\nThe largest integer out of them is: " << number << endl;
	return 0;
}