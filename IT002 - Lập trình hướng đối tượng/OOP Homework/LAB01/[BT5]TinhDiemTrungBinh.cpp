// Viết chương trình nhập họ tên, điểm toán, điểm văn của một học sinh. Tính điểm trung bình và xuất kết quả.

#include <iostream>
#include <vector>

using namespace std;

struct Student
{
	char name[100];
	double math, literature;
};

void GetInformation(Student& x)
{

	cout << "Student's name: ";
	cin.getline(x.name, 100);
	cout << "Point in mathematics: ";
	cin >> x.math;
	while (x.math < 0 || x.math > 10)
	{
		cout << "Enter the point in mathematics again: ";
		cin >> x.math;
	}
	cout << "Point in literature: ";
	cin >> x.literature;
	while (x.literature < 0 || x.literature > 10)
	{
		cout << "Enter the point in literature again: ";
		cin >> x.literature;
	} 
}

double AverageScore(Student x)
{
	return (x.math + x.literature) / 2;
}

int main()
{
	Student x;
	double dtb;
	GetInformation(x);
	dtb = AverageScore(x);
	cout << "\nStudent " << x.name << " has the Mathematics and Literature point average is: " << dtb << endl;
	cout << "\n";
	return 0;
}
