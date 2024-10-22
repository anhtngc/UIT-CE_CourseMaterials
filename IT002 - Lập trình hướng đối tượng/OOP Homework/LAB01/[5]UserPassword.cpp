// Nhập vào username và password. Nếu nhập sai quá 3 lần thì in thông báo lỗi, ngược lại hiển thị câu chào username.

#include <iostream>

using namespace std;

int main()
{
	string username = "TranNgocAnh";
	string password = "22520077";
	string in_user, in_pass;
	for (int i = 0; i <= 2; i++)
	{
		cout << "User: ";
		cin >> in_user;
		cout << "Password: ";
		cin >> in_pass;
		if (in_user == username && in_pass == password)
		{
			cout << "\nWelcome " << username << "!" << endl;
			return 0;
		}
		else if (i < 2)
		{
			cout << "The username or password is incorrect. Please try to enter it again!" << endl;;
		}
	}
	cout << "\nFAIL!" << endl;
	cout << "You have tried 3 times. Exit the program and try later!" << endl;
	return 0;
}