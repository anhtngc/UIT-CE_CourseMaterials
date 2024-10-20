#include <iostream>
#include <algorithm>

using namespace std;

bool check(long long days, long long a, long long k, long long b, long long m, long long n) {
	long long x = days / k;
	long long y = days / m;
	long long products = (days - x) * a + (days - y) * b;
	if (products >= n)
		return true;
	return false;
}


int main()
{
	long long a, k, b, m, n;
	cin >> a >> k >> b >> m >> n;
	int u = max(a, b);
	long long left = 0, right = (n / u) * 2;
	while (left <= right) {
		long long mid = (left + right) / 2;
		if (check(mid, a, k, b, m, n) == true)
		{
			right = mid - 1;
		}
		else left = mid + 1;
	}
	cout << left;
	return 0;
}