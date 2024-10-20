#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 1e5 + 5;
int n;

struct Point
{
    int x, y, z;
} P[MAX_N], tmp[MAX_N];

void Quick(int l, int r)
{
    if (l >= r)
        return;
    int i = l, j = r;
    int pivot = P[(l + r) >> 1].y;
    while (i <= j)
    {
        while (P[i].y < pivot) i++;
        while (P[j].y > pivot) j--;
        if (i <= j)
        {
            swap(P[i], P[j]);
            i++;
            j--;
        }
    }
    Quick(l, j);
    Quick(i, r);
}

void QuickSorting(int l, int r)
{
    if (l >= r)
        return;
    int i = l, j = r;
    int pivot = P[(l + r) >> 1].z;
    while (i <= j)
    {
        while (P[i].z < pivot) i++;
        while (P[j].z > pivot) j--;
        if (i <= j)
        {
            swap(P[i], P[j]);
            i++;
            j--;
        }
    }
    QuickSorting(l, j);
    QuickSorting(i, r);
}

void Merge(int l, int mid, int r)
{
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (P[i].x < P[j].x)
        {
            tmp[k++] = P[i++];
        }
        else if (P[i].x > P[j].x)
        {
            tmp[k++] = P[j++];
        }
        else
        {
            if (P[i].y > P[j].y)
            {
                tmp[k++] = P[i++];
            }
            else if (P[i].y < P[j].y)
            {
                tmp[k++] = P[j++];
            }
            else
            {
                if (P[i].z < P[j].z)
                {
                    tmp[k++] = P[i++];
                }
                else
                {
                    tmp[k++] = P[j++];
                }
            }
        }
    }
    while (i <= mid)
    {
        tmp[k++] = P[i++];
    }
    while (j <= r)
    {
        tmp[k++] = P[j++];
    }
    for (i = l, j = 0; i <= r; i++, j++)
    {
        P[i] = tmp[j];
    }
}

void MergeSorting(int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    MergeSorting(l, mid);
    MergeSorting(mid + 1, r);
    Merge(l, mid, r);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> P[i].x >> P[i].y >> P[i].z;
    }
    Quick(1, n);
    MergeSorting(1, n);
    for (int i = 1; i <= n; i++)
    {
        cout << P[i].x << " " << P[i].y << " " << P[i].z << endl;
    }
    return 0;
}