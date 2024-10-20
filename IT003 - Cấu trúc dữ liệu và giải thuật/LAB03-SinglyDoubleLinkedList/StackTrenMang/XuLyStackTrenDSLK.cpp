#include "StackInLinkedList.h"

StackDSLK::StackDSLK()
{
	top = NULL;
}

bool StackDSLK::IsEmpty()
{
	return top = NULL;
}

void StackDSLK::Push(int value)
{
	Node* newNode = new Node();
	newNode->data = value;
	newNode->next = top;
	top = newNode;
}

int StackDSLK::Pop()
{
    if (IsEmpty()) 
    {
        cout << "Stack rong. Khong the lay phan tu." << endl;
        return -1;
    }
    int temp = top->data;
    Node* tempNode = top;
    top = top->next;
    delete tempNode;
    return temp;
}

int StackDSLK::Peek()
{
    if (IsEmpty()) 
    {
        cout << "Stack rong. Khong the lay phan tu." << endl;
        return -1;
    }
    return top->data;
}