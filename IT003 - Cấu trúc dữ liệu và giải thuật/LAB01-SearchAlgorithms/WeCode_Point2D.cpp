#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Point {
public:
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

bool cmp(Point a, Point b) {
    if (a.x == b.x) {
        return a.y > b.y;
    }
    return a.x < b.x;
}

int main() {
    // create an array of points
    Point p;
    vector<Point> points;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p.x >> p.y;
        points.push_back(p);
    }
    // sort the array using custom comparison function
    sort(points.begin(), points.end(), cmp);

    // print the sorted array
    for (auto p : points) {
        cout << p.x << " " << p.y << "\n";
    }
    cout << endl;

    return 0;
}