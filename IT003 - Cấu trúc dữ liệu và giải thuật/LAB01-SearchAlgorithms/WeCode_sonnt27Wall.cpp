#include <iostream>
#include <vector>
#define MAX 1000000000
#define ll long long

using namespace std;
bool check(vector<int> a, vector<int> b, int k) {
    b.push_back(0);
    for (auto i : a) {
        if (i < k && b.empty()) return false;
        while (i + b.back() < k) {
            b.pop_back();
            if (b.empty()) return false;
        }
        if (i < k) b.pop_back();
    }
    return true;
}

int solve(vector<int> a, vector<int> b)
{

    reverse(b.begin(), b.end());

    int l = 0, r = 1000000000;
    while (l < r) {
        int g = (l + r + 1) / 2;
        if (check(a, b, g)) l = g;
        else r = g - 1;
    }

    return r;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    int minC = solve(a, b);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < minC)
            count++;
    }
    cout << minC << " " << count << "\n" << endl;

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < m)
        {
            if (a[i] >= minC)
            {
                break;
            }
            else
            {
                int l = a[i] + b[j];
                if (l >= minC)
                {
                    cout << i + 1 << " " << j + 1 << "\n" << endl;
                    j++;
                    break;
                }
                else
                    j++;
            }
        }
    }
    return 0;
}