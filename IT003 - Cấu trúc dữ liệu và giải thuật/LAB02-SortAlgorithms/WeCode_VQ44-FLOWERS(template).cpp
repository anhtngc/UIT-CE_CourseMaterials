#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nhapMang(vector<int>& arr, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
}
void shellSort(vector<int>& arr, int n) 
{
    int interval, i, j, temp;
    for (interval = n / 2; interval > 0; interval /= 2) 
    {
        for (i = interval; i < n; i++) 
        {
            temp = arr[i];
            for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) 
            {
                arr[j] = arr[j - interval];
            }
            arr[j] = temp;
        }
    }
}
int main() {
    int n, z;
    cin >> n >> z;
    vector<int>arr;
    nhapMang(arr, n);
    shellSort(arr, n);
    arr.emplace_back(0);
    while (z) {
        for (int i = 0; i < n; i++) 
        {
            if (z == 0) break;
            if (arr[i] != arr[i + 1] && arr[i] != -1) 
            {
                cout << arr[i] << " ";
                arr[i] = -1;
                z--;
            }
        }
    }
    return 0;
}