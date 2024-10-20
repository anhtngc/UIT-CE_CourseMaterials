#include "StackInArray.h"

StackArray::StackArray()
{
	top = -1;
}

bool StackArray::IsEmpty()
{
	return top == -1;
}

bool StackArray::IsFull()
{
	return top == MAX - 1;
}

void StackArray::Push(int value)
{
	if (IsFull())
	{
		cout << "Stack da day. Khong the chen them phan tu." << endl;
		return;
	}
	top++;
	arr[top] = value;
}

int StackArray::Pop()
{
	if (IsEmpty()) {
		cout << "Stack rong. Khong the lay phan tu." << endl;
		return -1;
	}
	int temp = arr[top];
	top--;
	return temp;
}

int StackArray::Peek()
{
	if (IsEmpty()) 
	{
		cout << "Stack rong. Khong the lay phan  tu tren cung cua ngan xep ma khong xoa no (peek)." << endl;
		return -1;
	}
	return arr[top];
}