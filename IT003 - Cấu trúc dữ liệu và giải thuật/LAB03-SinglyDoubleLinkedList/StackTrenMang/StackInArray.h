#pragma once
#ifndef StackArray
#include <iostream>
using namespace std;

#define MAX 100

class StackArray
{
private:
	int top; //chỉ số của phần tử trên cùng của ngăn xếp
	int arr[MAX];
public:
	StackArray();
	bool IsEmpty();
	bool IsFull();
	void Push(int);
	int Pop();
	int Peek();
};
#endif // !StackArray

