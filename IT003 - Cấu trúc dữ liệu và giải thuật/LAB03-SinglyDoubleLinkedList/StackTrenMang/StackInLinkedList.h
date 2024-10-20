#pragma once
#ifndef StackDSLK
#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
};

class StackDSLK
{
private:
	Node* top; //con trỏ trỏ tới phần tử trên cùng của ngăn xếp
public:
	StackDSLK();
	bool IsEmpty();
	void Push(int);
	int Pop();
	int Peek();
};
#endif // !StackDSLK

