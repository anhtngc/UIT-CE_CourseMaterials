#include<iostream>
#include<queue>

using namespace std;

struct NODE {
	int info;
	NODE* pNext;
};

struct LIST {
	NODE* pHead;
	NODE* pTail;
};

NODE* CreateNode(int x) {
	NODE* p;
	p = new NODE;
	if (p == NULL)
		exit(1);
	p->info = x;
	p->pNext = NULL;
	return p;
}

void CreateEmptyList(LIST& l) {
	l.pHead = NULL;
	l.pTail = NULL;
}

void AddTail(LIST& L, NODE* p) {
	if (L.pHead == NULL) {
		L.pHead = p;
		L.pTail = L.pHead;
	}
	else {
		L.pTail->pNext = p;
		L.pTail = p;
	}
}
void AddHead(LIST& L, NODE* p) {
	if (L.pHead == NULL) {
		L.pHead = p;
		L.pTail = L.pHead;
	}
	else {
		p->pNext = L.pHead;
		L.pHead = p;
	}
}
void CreateList(LIST& L, int& n)
{

	for (int i = 1; i <= n; i++)
	{
		AddTail(L, CreateNode(i));
	}
}
bool RemoveHead(LIST& L, int& x)
{
	NODE* p;
	if (L.pHead != NULL) {
		x = L.pHead->info;
		p = L.pHead;
		L.pHead = L.pHead->pNext;
		if (L.pHead == NULL)
			L.pTail = NULL;
		delete p;
		return 1;
	}
	return 0;
}
bool RemoveAfterQ(LIST& l, NODE* Q, int& x) {
	NODE* p;
	if (Q != NULL) {
		p = Q->pNext;
		if (p != NULL) {
			if (p == l.pTail)
				l.pTail = Q;
			Q->pNext = p->pNext;
			x = p->info;
			delete p;
		}
		return 1;
	}
	return 0;
}
bool RemoveX(LIST& L, int x) {
	NODE* Q, * p;
	Q = NULL;
	p = L.pHead;
	while (p != NULL && p->info != x) {
		Q = p;
		p = p->pNext;
	}
	if (p == NULL) return 0;
	if (Q != NULL) RemoveAfterQ(L, Q, x);
	else RemoveHead(L, x);
	return 1;
}
void PrintList(LIST& L) {
	cout << L.pTail->info << " ";
}

int main() {
	LIST L;
	CreateEmptyList(L);
	int n, m;
	cin >> n >> m;
	CreateList(L, n);
	queue<int> q;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		RemoveX(L, a);
		AddHead(L, CreateNode(a));
		q.push(L.pTail->info);
	}
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}