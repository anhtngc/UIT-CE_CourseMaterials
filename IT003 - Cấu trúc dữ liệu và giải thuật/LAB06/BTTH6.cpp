#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>

const int Max = 20;
const int maxValue = 1000;

using namespace std;

struct Matrix
{
    int n;
    int a[Max][Max];
};

struct CANH
{
    int x, y; 
};

CANH ck[Max];       
int m;              
int b[100];         

int daxet;          
int trongmin[Max];  

int nhap(Matrix& ke, const char* Filename)
{
    ifstream f(Filename);
    if (!f.is_open())
    {
        cout << "Khong tim thay file: " << Filename << endl;
        return 0;
    }

    f >> ke.n;
    for (int i = 0; i < ke.n; i++)
        for (int j = 0; j < ke.n; j++)
            f >> ke.a[i][j];

    f.close();
    return 1;
}


void xuat(const Matrix& ke)
{
    cout << "\n*******Do thi Vua nhap*******";
    for (int i = 0; i < ke.n; i++)
    {
        cout << "\n        ";
        for (int j = 0; j < ke.n; j++)
            cout << " " << ke.a[i][j];
    }
    cout << endl;
}


int kiemtravohuong(const Matrix& ke)
{
    for (int i = 0; i < ke.n; i++)
        for (int j = i + 1; j < ke.n; j++)
            if (ke.a[i][j] != ke.a[j][i])
                return 0;
    return 1;
}

int tinhbacvohuong(const Matrix& ke, int dinh)
{
    int bac = 0;
    for (int i = 0; i < ke.n; i++)
    {
        if (ke.a[dinh][i] != 0)
            bac++;
    }
    return bac;
}

void tinhbacvohuong(const Matrix& ke, int dinh, int& bacvao, int& bacra)
{
    bacvao = bacra = 0;
    for (int i = 0; i < ke.n; i++)
    {
        if (ke.a[i][dinh] != 0)
            bacvao++;

        if (ke.a[dinh][i])
            bacra++;
    }
}

void thamdinh(int v)
{
    cout << v + 1 << " ";
}

void DFS(int v, const Matrix& ke, int chuaxet[], int truoc[])
{
    thamdinh(v);
    chuaxet[v] = 0;
    for (int u = 0; u < ke.n; u++)
    {
        if (ke.a[v][u] != 0 && chuaxet[u])
        {
            truoc[u] = v;
            DFS(u, ke, chuaxet, truoc);
        }
    }
}

void duyetDFS(int v, const Matrix& ke, int chuaxet[], int truoc[])
{
    for (int i = 0; i < ke.n; i++)
        chuaxet[i] = 1;
    DFS(v, ke, chuaxet, truoc);
}

void BFS(int v, const Matrix& ke, int chuaxet[], int truoc[])
{
    int queue[maxValue];
    int L, R;
    L = R = 0;
    queue[R++] = v;
    chuaxet[v] = 0;
    while (L < R)
    {
        int x = queue[L++];
        thamdinh(x);
        for (int u = 0; u < ke.n; u++)
        {
            if (ke.a[x][u] != 0 && chuaxet[u])
            {
                truoc[u] = x;
                chuaxet[u] = 0;
                queue[R++] = u;
            }
        }
    }
}

void duyetBFS(int v, const Matrix& ke, int chuaxet[], int truoc[])
{
    for (int i = 0; i < ke.n; i++)
        chuaxet[i] = 1;
    BFS(v, ke, chuaxet, truoc);
}

void duongdi(int s, int f, int truoc[])
{
    if (truoc[f] == -1)
    {
        cout << "\nKhong co duong di tu " << s + 1 << " den " << f + 1;
        return;
    }
    cout << "\nDuong di tu " << s + 1 << " den " << f + 1 << " la: ";
    cout << f + 1 << " ";
    int u = truoc[f];
    while (u != s)
    {
        cout << u + 1 << " ";
        u = truoc[u];
    }
    cout << s + 1;
}

void Timduongdi(int s, int f, const Matrix& ke)
{
    int queue[maxValue], chuaxet[maxValue], truoc[maxValue];
    int L, R;
    L = R = 0;
    for (int i = 0; i < ke.n; i++)
        chuaxet[i] = 1;
    queue[R++] = s;
    chuaxet[s] = 0;
    truoc[s] = -1;
    while (L < R)
    {
        int x = queue[L++];
        for (int u = 0; u < ke.n; u++)
        {
            if (ke.a[x][u] != 0 && chuaxet[u])
            {
                truoc[u] = x;
                if (u == f)
                {
                    duongdi(s, f, truoc);
                    return;
                }
                chuaxet[u] = 0;
                queue[R++] = u;
            }
        }
    }
    cout << "\nKhong co duong di tu " << s + 1 << " den " << f + 1;
}

int Tim(int u, int a[])
{
    while (a[u] > 0)
        u = a[u];
    return u;
}

void Ghep(int u, int v, int a[])
{
    if (a[u] < a[v])
    {
        a[u] += a[v];
        a[v] = u;
    }
    else
    {
        a[v] += a[u];
        a[u] = v;
    }
}

void Kruskal(const Matrix& ke)
{
    int a[Max];
    for (int i = 0; i < ke.n; i++)
        a[i] = -1;
    int daxet = 0;
    m = 0;
    int min;
    while (daxet < ke.n - 1)
    {
        min = maxValue;
        int x, y;
        for (int i = 0; i < ke.n; i++)
            for (int j = 0; j < ke.n; j++)
            {
                if (ke.a[i][j] != 0 && ke.a[i][j] < min)
                {
                    int u = Tim(i, a);
                    int v = Tim(j, a);
                    if (u != v)
                    {
                        min = ke.a[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        if (min == maxValue)
        {
            cout << "\nDo thi khong lien thong";
            return;
        }
        ck[m].x = x;
        ck[m].y = y;
        m++;
        Ghep(Tim(x, a), Tim(y, a), a);
        daxet++;
    }
}

void kq(const Matrix& ke)
{
    cout << "\nCay khung ngan nhat cua do thi: ";
    int tong = 0;
    for (int i = 0; i < m; i++)
    {
        cout << "\nDinh " << ck[i].x + 1 << " va dinh " << ck[i].y + 1;
        tong += ke.a[ck[i].x][ck[i].y];
    }
    cout << "\nTong trong so cua cay khung nho nhat: " << tong;
}
void DuyetDinh(Matrix ke, int j)
{
    b[j] = daxet;
    for (int k = 0; k < ke.n; k++)
    {
        if (b[k] == 0 && ke.a[j][k] != 0)
            DuyetDinh(ke, k);
    }
}

void ktlienthong(Matrix ke)
{
    for (int i = 0; i < ke.n; i++)
        b[i] = 0;
    for (int j = 0; j < ke.n; j++)
    {
        if (b[j] == 0)
        {
            daxet++;
            DuyetDinh(ke, j);
        }
    }
}

void prim(Matrix ke)
{
    int label[Max];
    int min, i, j;
    CANH canh;
    for (i = 0; i < ke.n; i++)
        label[i] = 0;
    label[0] = 1;
    m = 0;
    while (m < ke.n - 1)
    {
        min = maxValue;
        for (j = 0; j < ke.n; j++)
        {
            if (label[j] == 0)
            {
                for (i = 0; i < ke.n; i++)
                {
                    if (label[i] != 0 && ke.a[i][j] != 0)
                    {
                        if (min == maxValue || min > ke.a[i][j])
                        {
                            canh.x = i;
                            canh.y = j;
                            min = ke.a[i][j];
                        }
                    }
                }
            }
        }
        trongmin[m] = min;
        ck[m] = canh;
        m++;
        label[canh.y] = 1;
    }
}

void tsprim()
{
    int ts = 0;
    cout << "\n + Cac canh cay khung theo Prim :\n\n   ";
    for (int i = 0; i < m; i++)
        cout << " (" << ck[i].x + 1 << "," << ck[i].y + 1 << ")";
    cout << "\n\n + Cay khung co trong so tuong ung la:\n\n";
    for (int j = 0; j < m; j++)
    {
        cout << setw(6) << trongmin[j];
        ts += trongmin[j];
    }
    cout << "\n\n + Tong trong so cua cay la: " << ts;
}


int main()
{
    Matrix ke;
    int chuaxet[maxValue];
    int truoc[maxValue];
    if (!nhap(ke, "Data.txt"))
        return 1;
    xuat(ke);
    int dinh;
    cout << "Nhap dinh can tinh bac: ";
    cin >> dinh;
    cout << "Bac cua dinh " << dinh << " la: " << tinhbacvohuong(ke, dinh - 1) << endl;
    cout << "Cac dinh ke voi dinh " << dinh << " la: ";
    for (int i = 0; i < ke.n; i++)
        if (ke.a[dinh - 1][i] != 0)
            cout << i + 1 << " ";
    cout << endl;
    cout << "\nDFS: ";
    duyetDFS(0, ke, chuaxet, truoc);
    cout << "\nBFS: ";
    duyetBFS(0, ke, chuaxet, truoc);
    cout << endl;
    cout << "----------Kruskal-----------" << endl;
    int s, f;
    cout << "\nNhap dinh bat dau: ";
    cin >> s;
    cout << "Nhap dinh ket thuc: ";
    cin >> f;
    Timduongdi(s - 1, f - 1, ke);
    Kruskal(ke);
    kq(ke);
    daxet = 0;
    ktlienthong(ke);
    cout << "\n\nSo thanh phan lien thong cua do thi: " << daxet;
    prim(ke);
    tsprim();
    return 0;
}