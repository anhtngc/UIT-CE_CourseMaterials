#include <iostream>
#include <string.h>

using namespace std;

void nhapxuatchuoi(char s[])
{
    cout << "Nhap chuoi: ";
    cin.getline(s, 100);
    cout << "Chuoi vua nhap: " << s << "\n" << endl;
}

void inhoa(char s[])
{
    cout << "Cac ki tu in hoa trong chuoi la: ";
    for (int i = 0; i < (int)strlen(s); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            cout << s[i] << " ";
        }
    }
    cout << "\n" << endl;
}

void daonguoc(char s[])
{
    cout << "Chuoi sau khi duoc dao nguoc: ";
    for (int i = (int)strlen(s); i >= 0; i--)
    {
        cout << s[i];
    }
    cout << "\n" << endl;
}

void xenke(char s[])
{
    cout << "Chuoi duoc in lai voi vi tri chan in hoa con vi tri le in thuong: ";
    for (int i = 0; i < (int)strlen(s); i++)
    {
        if (i == 0 || i % 2 == 0)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                cout << s[i];
            else
            {
                char temp1 = toupper(s[i]);
                cout << temp1;
            }
        }
        else
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                cout << s[i];
            else
            {
                char temp2 = tolower(s[i]);
                cout << temp2;
            }
        }
    }
    cout << "\n" << endl;
}

void dem(char x, char s[])
{
    cout << "Nhap mot ki tu bat ki: ";
    cin >> x;
    int count = 0;
    for (int i = 0; i < (int)strlen(s); i++)
    {
        if (s[i] == x)
            count++;
    }
    cout << "Ki tu " << x << " xuat hien " << count << " lan trong chuoi." << "\n" << endl;
}

void kituxuathiennhieunhat(char s[])
{
    int count[100], n = 0;
    int number;
    for (int i = 0; i < (int)strlen(s); i++)
    {
        number = 1;
        for (int j = i + 1; j < (int)strlen(s); j++)
        {
            if (s[i] == s[j])
            {
                number++;
            }
        }
        count[i] = number;
    }
    int maxchar = count[0];
    for (int i = 0; i < (int)strlen(s); i++)
    {
        if (count[i] > maxchar)
        {
            maxchar = count[i];
        }
    }
    for (int i = 0; i < (int)strlen(s); i++)
    {
        if (count[i] == maxchar)
        {
            cout << "Ki tu " << s[i] << " la ki tu xuat hien nhieu nhat trong chuoi (" << count[i] << " lan)." << endl;
        }
    }
    cout << "\n";
}

void kituxuathienmotlan(char s[])
{
    char c[100];
    int counted = 0, count[100];
    cout << "Ki tu xuat hien 1 lan trong chuoi la: ";
    for (int i = 0; i < (int)strlen(s); i++)
    {
        bool already_counted = false;
        for (int j = 0; j < counted; j++)
        {
            if (s[i] == c[j])
                already_counted = true;
        }
        if (already_counted) continue;
        int number = 0;
        for (int j = 0; j < (int)strlen(s); j++)
        {
            if (s[i] == s[j])
                number++;
        }
        count[i] = number;
    }
    for (int i = 0; i < (int)strlen(s); i++)
    {
        if (count[i] == 1)
            cout << s[i];
    }
    cout << "\n";
}

int main()
{
    char s[100];
    nhapxuatchuoi(s);
    inhoa(s);
    daonguoc(s);
    xenke(s);
    char x;
    dem(x,s);
    kituxuathiennhieunhat(s);
    kituxuathienmotlan(s);
}
