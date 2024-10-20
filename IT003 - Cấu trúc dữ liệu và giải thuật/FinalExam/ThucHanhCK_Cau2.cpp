#include<iostream>

using namespace std;

struct node 
{
	int data;
	node* next;
};

node* createNode(int x) 
{
	node* p = new node;
	p->next = NULL;
	p->data = x;
	return p;
}

void printList(node* l) 
{
	node* p = l;
	while (p != NULL) 
	{
		cout << p->data << " ";
		p = p->next;
	}
}

node* addElement(node* p, int x) 
{
	node* temp = createNode(x);
	p->next = temp;
	return temp;
}

void remove(node*& p, int val) 
{
	if (p == NULL)
		return;
	node* current = p;
	node* previous = NULL;
	while (current != NULL && current->data != val) 
	{
		previous = current;
		current = current->next;
	}
	if (current == NULL)
		return;
	if (previous == NULL) 
		p = current->next;
	else 
		previous->next = current->next;
	delete current;
}

node* addHead(node* p, int x) 
{
	node* temp = new node;
	temp->data = x;
	temp->next = p;
	p = temp;
	return p;
}

void PrintNode(node* l) {
	node* current = l;
	while (current != NULL) 
	{
		cout << current->data << " ";
		current = current->next;
	}
}

int main() {
	int n, x, m;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	cout << "Nhap so lan thay giao goi: ";
	cin >> m;
	node* q = createNode(1);
	node* p = q;
	for (int i = 2; i <= n; i++) 
	{
		p = addElement(p, i);
	}
	cout << "\nNhap ma so sinh vien thay se goi" << endl;
	for (int i = 0; i < m; i++)
	{
		cout << "Lan goi thu " << i + 1 << ": ";
		cin >> x;
		if (x > 0 && x <= n)
		{
			remove(q, x);
			q = addHead(q, x);
		}
	}
	cout << "\nThu tu cac sinh vien sau " << m << " lan goi la: ";
	PrintNode(q);
	cout << endl;
	return 0;
}