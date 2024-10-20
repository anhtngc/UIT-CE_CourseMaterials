#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a[0] >> a[1];
    int s = a[0] - a[1];
    int min_index_C = a[0], max_index_L = a[1];
    for (int i = 2; i < n; i++) {
        cin >> a[i];
        if (i % 2 == 0)
        {
            s += a[i];
            if (a[i] < min_index_C)
            {
                min_index_C = a[i];
            }
        }
        else
        {
            s -= a[i];
            if (a[i] > max_index_L)
            {
                max_index_L = a[i];
            }
        }
    }
    if (max_index_L > min_index_C)
    {
        s += 2 * (max_index_L - min_index_C);
    }
    cout << s << endl;
    return 0;
}