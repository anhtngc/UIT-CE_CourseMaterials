#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    bool appeared[1000001] = { false };
    for (int i = 0; i < n; i++)
    {
        string code;
        cin >> code;
        int hash = 0;
        for (char c : code)
        {
            hash = (hash * 10 + (c - '0')) % 1000001;
        }
        appeared[hash] = true;
    }
    int count = 0;
    for (bool a : appeared)
    {
        if (a) count++;
    }
    cout << count << endl;
    return 0;
}