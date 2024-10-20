#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

struct DONTHUC {
	int somu;
	double heso;

	DONTHUC(double _heso = 0, int _somu = 0) {
		heso = _heso;
		somu = _somu;
	}

	DONTHUC& operator = (const DONTHUC& rhs) {
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node {
	DONTHUC* data;
	Node* next;

	Node(DONTHUC* _data = nullptr) {
		this->data = _data;
		this->next = nullptr;
	}

};

struct DATHUC {
	Node* head;
	Node* tail;
	DATHUC() {
		this->head = nullptr;
		this->tail = nullptr;
	}
};


void Nhap(DATHUC& B, double hes, int smu) {
	DONTHUC* t = new DONTHUC;
	t->heso = hes;
	t->somu = smu;
	Node* p = new Node(t);
	if (hes != 0) {
		if (B.head != NULL) {
			(B.tail)->next = p;
			B.tail = p;
		}
		else {
			B.head = p;
			B.tail = p;
		}
	}
}

void Xuat(DATHUC B) {
	Node* q = B.head;
	if (B.head == NULL) {
		cout << 0;
		return;
	}

	while (q != NULL) {
		if (q->data->heso == 1 && q->data->somu != 0) cout << "x";
		else {
			if (q->data->heso == -1 && q->data->somu != 0) cout << "-x";
			else {
				cout << q->data->heso;
				if (q->data->somu != 0) cout << "x";
			}
		}
		if (q->data->somu != 0 && q->data->somu != 1) cout << "^" << q->data->somu;
		if (q->next != NULL && q->next->data->heso > 0) cout << "+";
		q = q->next;
	}

}
double TinhDaThuc(DATHUC B, double x) {
	Node* p = B.head;
	double s = 0;
	while (p != NULL) {
		s += (p->data->heso) * pow(x, p->data->somu);
		p = p->next;
	}
	return s;
}


int main() {
	DATHUC B;
	int N;

	cin >> N;
	for (int test = 0; test < N; test++) {
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B, heso, somu);
	}


	cout << "Da thuc vua nhap la: "; Xuat(B);
	double x; cin >> x;
	cout << "\nVoi x=" << x << ", gia tri da thuc la: "
		<< setprecision(2) << fixed << TinhDaThuc(B, x);
	return 0;
}
