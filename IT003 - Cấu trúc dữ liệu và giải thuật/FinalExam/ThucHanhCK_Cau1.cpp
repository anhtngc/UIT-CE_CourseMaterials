#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> XuLyChuoi(string S, string T) // hàm tìm các vị trí xuất hiện của xâu T trong xâu S
{
	vector<int> bienco;
	int m = S.length();
	int n = T.length();
	for (int i = 0; i <= m - n; i++)
	{
		int j;
		for (j = 0; j < n; j++)
		{
			if (S[i + j] != T[j])
				break;
		}
		if (j == n)
			bienco.push_back(i + 1);
	}
	return bienco;
}

int main()
{
	string S, T;
	getline(cin, S);
	getline(cin, T);
	vector<int> vitri = XuLyChuoi(S, T);
	if (vitri.empty())
		cout << "\nNO" << endl;
	else
	{
		cout << "\nYES" << endl;
		for (int i = 0; i < vitri.size(); i++)
		{
			cout << vitri[i] << " ";
		}
		cout << endl;
	}
	return 0;
}