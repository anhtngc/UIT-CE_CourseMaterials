#include <iostream>
using namespace std;

int main() {
    int n, m;
    double trace = 0.0;
    cin >> m >> n;
    if (m != n)
    {
        trace = 0;
    }
    else
    {
        double A[100][100];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> A[i][j];
                if (i == j) {
                    trace += A[i][j];
                }
            }
        }
    }
    cout << trace << endl;
    return 0;
}