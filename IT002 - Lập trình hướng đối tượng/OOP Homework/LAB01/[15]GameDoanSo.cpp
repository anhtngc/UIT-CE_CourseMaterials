/* Viết chương trình mô phỏng trò chơi đoán số mà máy phát sinh.Nếu đoán đúng thì hiển thị chúc mừng,
nếu nhỏ hơn hoặc lớn hơn thì thông báo cho người dùng biết mà đoán lại. */

#include <iostream>

using namespace std;

void Game(int& guess)
{
	srand(time(0));
	int random = rand() % 100 + 1;
	int number;
	int count = 0, score = 10;
	while (true)
	{
		cout << "Guess a number: ";
		cin >> guess;
		if (guess == random)
		{
			cout << "\nCongratulations! You guess right, the number is: " << random << endl;
			cout << "You have tried " << count << " times and your score is: " << score << " point." << endl;
			break;
		}
		else if (guess > random)
		{
			cout << "Wrong! Guess a number lower than " << guess << "!" << endl;
			count++;
			score--;
		}
		else if (guess < random)
		{
			cout << "Wrong! Guess a number higher than " << guess << "!" << endl;
			count++;
			score--;
		}
		if (score == 0)
		{
			cout << "\nYou lose :(" << endl;
			cout << "You have tried 10 times, please try to play again." << endl;
		}
	}
}

int main()
{
	int guess;
	Game(guess);
	cout << "\nWanna play the game again? Choose between two option (number) below." << endl;
	int again;
	cout << "1: YES" << endl;
	cout << "2: NO" << endl;
	cin >> again;
	while (again != 1 && again != 2)
	{
		cout << "You must choose between two option (number) below:" << endl;
		cout << "1: YES" << endl;
		cout << "2: NO" << endl;
		cin >> again;
	}
	if (again == 1)
	{
		Game(guess);
	}
	else cout << "\nSee you again! Please enter to exit the game." << endl;
	return 0;
}