#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void GetArray(int n, vector<int>& arr)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

int BinarySearch(vector<int>& arr, int left, int right, int find)
{
    int middle;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (arr[middle] == find)
            return 1;
        if (find > arr[middle])
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1;
}

int main()
{
    int n, index;
    cin >> n >> index;
    vector<int> arr(n);
    GetArray(n, arr);
    sort(arr.begin(), arr.end());
    int find;
    int result;
    for (int i = 0; i < index; i++)
    {
        cin >> find;
        result = BinarySearch(arr, 0, n - 1, find);
        if (result == 1)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}