#include <iostream>
#include <vector>

using namespace std;

void GetArray(int n, vector<int>& arr)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> arr[i];
	}
	cout << "\n";
}

void ShowArray(int n, vector<int>& arr)
{
	cout << "Mang vua duoc tao: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "	";
	}
	cout << "\n" << endl;
}

void BinarySearch(vector<int>& arr, int n, int x)
{
	int left = 0, right = n - 1;
	int mid;
	do
	{
		mid = (left + right) / 2;
		if (arr[mid] == x)
		{
			cout << "Gia tri can tim nam o vi tri a[" << mid << "]";
			break;
		}
		else
		{
			if (arr[mid] < x)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
	} while (left <= right);
	if (left > right)
	{
		cout << "Khong tim thay gia tri can tim trong mang." << endl;
	}
	cout << "\n";
}

void InterpolationSearch(vector<int>& arr, int n, int x)
{
	int left = 0, right = n - 1;
	int mid;
	while (left <= right)
	{
		mid = left + (right - left) * (x - arr[left]) / (arr[right] - arr[left]);
		if (arr[mid] == x)
		{
			cout << "Gia tri can tim nam o vi tri a[" << mid << "]";
			break;
		}
		else
		{
			if (arr[mid] < x)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
	}
	if (left > right)
	{
		cout << "Khong tim thay gia tri can tim trong mang." << endl;
	}
	cout << "\n";
}

void LinearSearch(vector<int>& arr, int n, int x)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (arr[i] == x)
		{
			cout << "Gia tri can tim nam o vi tri a[" << i << "]";
		}
	}
	if (i > n)
	{
		cout << "Khong tim thay gia tri can tim trong mang." << endl;
	}
	cout << "\n";
}

int main()
{
	int n, algo;
	cout << "Nhap so phan tu trong mang: ";
	cin >> n;
	vector<int> arr(n);
	GetArray(n, arr);
	ShowArray(n, arr);
	cout << "0: Dung chuong trinh" << endl;
	cout << "1: Binary Search" << endl;
	cout << "2: Interpolation Search" << endl;
	cout << "3: Linear Search" << endl;
	cout << "\nChon thuat toan tim kiem: ";
	cin >> algo;
	while (algo != 0)
	{
		int x;
		cout << "Nhap gia tri can tim: ";
		cin >> x;
		if (algo == 1)
		{
			BinarySearch(arr, n, x);
		}
		if (algo == 2)
		{
			InterpolationSearch(arr, n, x);
		}
		if (algo == 3)
		{
			LinearSearch(arr, n, x);
		}
		cout << "\nChon thuat toan can dung: ";
		cin >> algo;
	}
}