#include <iostream.h>
#include <stdlib.h>
#define max 100
typedef struct {
    int n;
    char a;
    char b;
    char c;
}nhom;
typedef nhom elem;
#include "stack.cpp"
void main()
{
    stack s;
    nhom bo;
    char A;
    char B;
    char C;
    int N;
    int m;
    cout << "Nhap so: "; cin >> m;
    createstack(s);
    bo.n = m; bo.a = 'A'; bo.b = 'B'; bo.c = 'C';
    push(s, bo);
    do
    {
        pop(s, bo);
        A = bo.a; B = bo.b; C = bo.c;
        if (bo.n == 1)
            cout << "\nChuyen " << bo.a << " qua " << bo.c;
        else
        {
            N = bo.n;
            bo.n = N - 1; bo.a = B; bo.b = A; bo.c = C;
            push(s, bo);
            bo.n = 1; bo.a = A; bo.b = ' '; bo.c = C;
            push(s, bo);
            bo.n = N - 1; bo.a = A; bo.b = C; bo.c = B;
            push(s, bo);
        }
    } while (!emptystack(s));

}