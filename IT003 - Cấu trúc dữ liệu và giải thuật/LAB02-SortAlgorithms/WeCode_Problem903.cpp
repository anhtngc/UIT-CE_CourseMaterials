#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) 
	{
		cin >> a[i];
	}
	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; i++) 
	{
		cin >> b[i];
	}
	vector<int> c(n + m);
	int i = 0, j = 0, k = 0;
	while (i < n && j < m) 
	{
		if (a[i] < b[j]) 
		{
			c[k++] = a[i++];
		}
		else 
		{
			c[k++] = b[j++];
		}
	}

	while (i < n) 
	{
		c[k++] = a[i++];
	}
	while (j < m) 
	{
		c[k++] = b[j++];
	}
	for (int i = 0; i < n + m; i++) 
	{
		cout << c[i] << " ";
	}
	cout << endl;
	return 0;
}