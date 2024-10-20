#include <iostream>

using namespace std;

#define M 100
struct NODE {
	int key; 
	NODE *pNext;
};

// Khai báo kiểu con trỏ chỉ node
typedef NODE *NODEPTR;

// Khai báo mảng HAST TABLE chưa M con trỏ đầu của HASH TABLE
NODEPTR HASHTABLE[M];

void InitHASHTABLE() {
	for (int i = 0; i < M; i++)
		HASHTABLE[i] = NULL;
}

int HF(int key) {
	return key % M;
}

bool isEmpty(int i) {
	return(HASHTABLE[i] == NULL ? 1 : 0);
}

bool isEmpty() {
	for (int i = 0; i < M; i++) {
		if (HASHTABLE[i] != NULL)
			return 0;
	}
	return 1;
}

void InsertList(NODEPTR& list, int k)
{
	NODEPTR newNode = new NODE{ k , NULL };
	if (list == NULL)
	{
		list = newNode;
	}
	else
	{
		NODEPTR p = list;
		while (p != NULL && p->pNext != NULL)
			p = p->pNext;
		p->pNext = newNode;
	}
}

void InsertX(int k) {
	int i = HF(k);

	// Phép toán thêm khóa k vào danh sách liên kết HASHTABLE[i]
	InsertList(HASHTABLE[i], k);
}

void pop(int i) {
	NODEPTR p = HASHTABLE[i];
	HASHTABLE[i] = p->pNext;
	delete p;
}

void delAfterQ(int i, NODEPTR q, NODEPTR p) {
	q->pNext = p->pNext;
	delete p;
}

void Remove(int k) {
	NODEPTR q, p;
	int i = HF(k);
	p = HASHTABLE[i];
	q = p;
	while (p != NULL && p->key != k) {
		q = p;  // Lưu lại địa chỉ của phần tử trước đó
		p = p->pNext;
	}
	if (p == NULL) cout << "\n Không có nút có khóa " << k;
	else if (p == HASHTABLE[i])
		pop(i); // Nút cần xóa là phần tử đầu của DSLK
	else
		delAfterQ(i, q, q); // Xóa nút sau nút q
}

NODEPTR Search(int k) {
	int i = HF(k);
	NODEPTR p = HASHTABLE[i];
	while (p != NULL && k != p->key)
		p = p->pNext;
	return p;
}

// Duyệt các phần tử trong HASHTABLE thứ i
void traverseHASHTABLE(int i) {
	NODEPTR p = HASHTABLE[i];
	while (p != NULL) {
		cout << p->key << "\t";
		p = p->pNext;
	}
}

// Duyệt toàn bộ bảng băm
void traverse() {
	for (int i = 0; i < M; i++) {
		cout << endl << "Butket " << i << ": ";
		traverseHASHTABLE(i);
	}
}