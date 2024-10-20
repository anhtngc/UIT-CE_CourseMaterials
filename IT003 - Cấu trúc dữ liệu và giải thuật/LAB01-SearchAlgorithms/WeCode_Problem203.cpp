#include <iostream>

using namespace std;

int main()
{
	double a, b;
	cin >> a;
	cin >> b;
	if (a == 0 && b == 0)
		cout << "ℝ";
	else if (a == 0)
		cout << "Ø";
	else cout << "{" << -(b + 0.0) / a << "}";
}