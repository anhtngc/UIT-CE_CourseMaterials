#include <iostream>
#include <algorithm>

using namespace std;

struct node
{
	int data;
	struct node* Next;
};

typedef struct tagList
{
	node* head;
	node* tail;
} list;

void CreateList(list& l) 
{
	l.head = NULL;
	l.tail = NULL;
}

node* CreateNode(int x) 
{
	node *p;
	p = new node;
	p->data = x;
	p->Next = NULL;
	return p;
}

void AddTail(list &l, node* p) 
{
	if (l.head == NULL) 
	{
		l.head = p;
		l.tail = p;
	}
	else 
	{
		l.tail->Next = p;
		l.tail = p;
	}
}

//Tạo một node có khóa bằng x và thêm vào đầu danh sách liên kết đơn
void CreateNodeX(node*& head, int x, list &l)
{
	node *p = new node;
	p->data = x;
	p->Next = head;
	head = p;
	cout << "Danh sach don sau khi them vao: ";
	cout << x << "  ";
	for (p = l.head; p != NULL; p = p->Next)
		cout << p->data << "  ";
}

void GetList(list& l, int n)
{
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x < 0)
		{
			cout << "Moi nut phai la so nguyen duong, vui long nhap lai: ";
			cin >> x;
		}
		node *p = new node;
		p = CreateNode(x);
		AddTail(l, p);
	}
}

void RemoveHead(list& l)
{
	node *p;
	if (l.head != NULL)
	{
		p = l.head;
		l.head = p->Next;
		delete p;
		if (l.head == NULL)
			l.tail = NULL;
	}
}

void RemoveTail(list& l)
{
	for (node *k = l.head; k != NULL; k = k->Next)
	{
		if (k->Next == l.tail)
		{
			delete l.tail;
			k->Next = NULL;
			l.tail = k;
		}
	}
}

//Xóa một node có khóa bằng x trong danh sách liên kết đơn
void DeleteNode(int x, list &l) 
{
	node *p, *q;
	node *k = l.head;
	/*if (l.head->data == x)
	{
		RemoveHead(l);
		return;
	}
	if (l.tail->data == x)
	{
		RemoveTail(l);
		return;
	}
	for (node *k = l.head; k != NULL; k = k->Next)
	{
		if (k->data == x) 
		{
			p->Next = k->Next;
			delete k;
			return;
		}
		p = k;
	}*/
	p = l.head;
	q = l.tail;
	while (p != NULL)
	{
		q = p;
		p = p->Next;
	}
	if (p == NULL)
		cout << "Khong tim thay " << x << " trong danh sach de xoa.";
	else
	{
 		if (q == NULL)
			RemoveHead(l);
		else
		{
			q->Next = p->Next;
			if (p == l.tail)
			{
				l.tail = q;
				delete p;
			}
		}
	}
	cout << "Danh sach don sau khi xoa phan tu " << x << " la: ";
	for (k = l.head; k != NULL; k = k->Next)
		cout << k->data << "  ";
}

//Liệt kê tất cả thành phần dữ liệu trong danh sách liên kết đơn
void PrintList(list &l) 
{
	node *p = new node;
	cout << "\nDanh sach don ban vua nhap la: ";
	for (p = l.head; p != NULL; p = p->Next)
		cout << p->data << "  ";
}

//Tìm 1 phần tử có khóa bằng x trong danh sách liên kết đơn
node* SearchNodeX(node* head, int x)
{
	node* temp = head;
	while (temp != NULL) 
	{
		if (temp->data == x) 
		{
			return temp;
		}
		temp = temp->Next;
	}
	return NULL;
}

//Sắp xếp tăng dần theo thành phần dữ liệu
void SelectionSort(node* head) 
{
	node *current = head;
	while (current != NULL)
	{
		node* min = current;
		node* nextNode = current->Next;
		while (nextNode != NULL) {
			if (nextNode->data < min->data) {
				min = nextNode;
			}
			nextNode = nextNode->Next;
		}
		int temp = current->data;
		current->data = min->data;
		min->data = temp;
		current = current->Next;
	}
}

//Chèn 1 phần tử vào danh sách và vẫn giữ nguyên vị trí tăng dần
void InsertNode_Sort(list&l, node *q, node *p)
{
	if (q != NULL)
	{
		p->Next = q->Next;
		q->Next = p;
		if (l.tail == q)
			l.tail = p;
	}	
}

int main()
{
	node* head = NULL;
	list danhsach;
	int n;
	cout << "Nhap so phan tu ban muon tao trong danh sach: ";
	cin >> n;
	CreateList(danhsach);
	GetList(danhsach, n);
	PrintList(danhsach);
	cout << endl;
	int x;
	cout << "\nNhap phan tu ban muon chen vao dau danh sach: ";
	cin >> x;
	CreateNodeX(head, x, danhsach);
	int element;
	cout << "\nNhap phan tu ban muon xoa trong danh sach: ";
	cin >> element;
	DeleteNode(element, danhsach);
	int index;
	cout << "\nNhap phan tu ban muon tim trong danh sach:";
	cin >> index;
	node *pFound = SearchNodeX(head, index);
	if (pFound == NULL)
	{
		cout << "\nKhong tim thay " << index << " trong danh sach da nhap." << endl;
	}
	else
	{
		cout << "\nDa tim thay " << index << " trong danh sach da nhap.";
	}
	/*SelectionSort(head);
	node* pos;
	InsertNode_Sort(danhsach, head, pos);*/
}