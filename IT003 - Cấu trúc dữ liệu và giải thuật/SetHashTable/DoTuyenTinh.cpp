#include <iostream>

using namespace std;

#define nullkey -1
#define MAX 10000

struct NODE {
	int key; // khóa của node trên bảng băm 
};

typedef NODE HASHTABLE[MAX];

int TableSize;

int HF(int key) {
	return key % MAX;
}

int HF_LinearProbing(int key, int i) {
	return (HF(key) + i) % TableSize;
}

void CreateHashTable(HASHTABLE& HT, int CurrentSize) {
	for (int i = 0; i < TableSize; i++)
		HT[i].key = nullkey;
	CurrentSize = 0; // số node hiện có khởi động bằng 0
}

int isEmpty(const HASHTABLE& HT, int CurrentSize) {
	return CurrentSize == 0 ? true : false;
}

int isFull(const HASHTABLE& HT, int CurrentSize) {
	return CurrentSize == TableSize - 1 ? true : false;
}

int Search(const HASHTABLE& HT, const int& CurrentSize, int k) {
	int b = HF(k), i = 0;
	while (HT[b].key != k && HT[b].key != nullkey) {
		b = HF_LinearProbing(k, ++i);
	}
	if (HT[b].key == k) //tìm thấy
		return b;
	return -1; // không tìm thấy
}

int Insert(HASHTABLE& HT, int& CurrentSize, int k) {
	if (isFull(HT, CurrentSize)) return -2; // HashTable đầy
	int b = HF(k), i = 0;
	while (b < TableSize && HT[b].key != k && HT[b].key != nullkey) {
		b = HF_LinearProbing(k, ++i);
	}
	if (HT[b].key == k)
		return -1; // giá trị k tồn tại trong mảng
	HT[b].key = k;
	CurrentSize += 1;
	return b;
}


int main() {
	int {};
	HASHTABLE H;
	int k;
	cin >> TableSize;
	CreateHashTable(H, Size);
	cin >> k;
	if (Search(H, Size, k) != -1)
		cout << "Found " << k << ".";
	else cout << "Not Found " << k << ".";
	return 0;
}
