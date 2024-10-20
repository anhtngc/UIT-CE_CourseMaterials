#include <iostream>
#include <math.h>
using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
};

Node* createNode(int key)
{
    Node* newNode = new Node;
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int key)
{
    if (root == NULL)
        return createNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    return root;
}

void LNR(Node* root) 
{
    if (root != NULL) {
        LNR(root->left);
        cout << root->key << " ";
        LNR(root->right);
    }
}

void LRN(Node* root) 
{
    if (root != NULL) {
        LRN(root->left);
        LRN(root->right);
        cout << root->key << " ";
    }
}

void NLR(Node* root) 
{
    if (root != NULL) {
        cout << root->key << " ";
        NLR(root->left);
        NLR(root->right);
    }
}

void NRL(Node* root) 
{
    if (root != NULL) {
        cout << root->key << " ";
        NRL(root->right);
        NRL(root->left);
    }
}

void RNL(Node* root) 
{
    if (root != NULL) {
        RNL(root->right);
        cout << root->key << " ";
        RNL(root->left);
    }
}

void RLN(Node* root) 
{
    if (root != NULL) {
        RLN(root->right);
        RLN(root->left);
        cout << root->key << " ";
    }
}

Node* search(Node* root, int X) 
{
    if (root == NULL || root->key == X)
        return root;
    if (root->key < X)
        return search(root->right, X);
    return search(root->left, X);
}

bool checkSoNguyenTo(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Tìm nút cha của một nút trên cây
Node* findParent(Node* root, Node* child) 
{
    if (root == NULL || root == child)
        return NULL;
    if (root->left == child || root->right == child)
        return root;
    if (child->key < root->key)
        return findParent(root->left, child);
    else
        return findParent(root->right, child);
}

// Xoá một nút trên cây
Node* deleteX(Node* root, int X) 
{
    Node* node = search(root, X);
    if (node == NULL)
        return root;
    Node* parent = findParent(root, node);
    if (parent == NULL) { // node là nút gốc
        if (node->left == NULL && node->right == NULL) 
        {
            delete node;
            return NULL;
        }
        else if (node->left == NULL) 
        {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == NULL) 
        {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        else {
            Node* successor = node->right;
            while (successor->left != NULL)
                successor = successor->left;
            node->key = successor->key;
            node->right = deleteX(node->right, successor->key);
            return node;
        }
    }
    if (node->left == NULL && node->right == NULL) { // node là lá
        if (parent->left == node)
            parent->left = NULL;
        else
            parent->right = NULL;
        delete node;
    }
    else if (node->left == NULL) { // node chỉ có con phải
        if (parent->left == node)
            parent->left = node->right;
        else
            parent->right = node->right;
        delete node;
    }
    else if (node->right == NULL) { // node chỉ có con trái
        if (parent->left == node)
            parent->left = node->left;
        else
            parent->right = node->left;
        delete node;
    }
    else { // node có cả hai con
        Node* successor = node->right;
        while (successor->left != NULL)
            successor = successor->left;
        node->key = successor->key;
        node->right = deleteX(node->right, successor->key);
    }
    return root;
}

// Đếm số nút trong cây nhị phân
int countNodes(Node* root) 
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Đếm số nút có đầy đủ hai cây con
int countFullNodes(Node* root) 
{
    if (root == NULL)
        return 0;
    int count = countFullNodes(root->left) + countFullNodes(root->right);
    if (root->left != NULL && root->right != NULL)
        count++;
    return count;
}

// Đếm số nút lá trong cây nhị phân
int countLeaves(Node* root) 
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}


int main() {
    Node* root = NULL;
    int n, choice;
    int count, fullcount, leavescount;
    cout << "MENU:\n";
    cout << "0: Dung chuong trinh\n";
    cout << "1: Nhap cay nhi phan\n";
    cout << "2: In cay nhi phan theo thu tu\n";
    cout << "3: Tim mot nut co khoa bang X tren cay\n";
    cout << "4: Xoa mot nut co khoa X la so nguyen to tren cay\n";
    cout << "5: Dem so nut trong cay\n";
    cout << "6: Dem so nut co day du 2 cay con\n";
    cout << "7: Dem so nut la\n";
    cout << "8: Tinh chieu cao cua cay\n";
    cout << "9: Ve cay nhi phan ra man hinh\n";
    do
    {
        cout << "\nHay nhap lua chon ban muon thuc hien: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "\nNhan phim bat ki de thoat chuong trinh..." << endl;
            return 0;
            break;
        case 1:
            cout << "Nhap so luong phan tu cua cay nhi phan: ";
            cin >> n;
            int val;
            for (int i = 0; i < n; i++) 
            {
                cout << "Nhap gia tri thu " << i + 1 << ": ";
                cin >> val;
                root = insert(root, val);
            }
            break;
        case 2:
            cout << "LNR: ";
            LNR(root);
            cout << endl;
            cout << "LRN: ";
            LRN(root);
            cout << endl;
            cout << "NLR: ";
            NLR(root);
            cout << endl;
            cout << "NRL: ";
            NRL(root);
            cout << endl;
            cout << "RNL: ";
            RNL(root);
            cout << endl;
            break;
        case 3:
            int x;
            cout << "Nhap phan tu muon tim kiem: ";
            cin >> x;
            if (search(root, x)) {
                cout << "Tim thay phan tu " << x << " trong cay nhi phan." << endl;
            }
            else {
                cout << "Khong tim thay phan tu " << x << " trong cay nhi phan." << endl;
            }
            break;
        case 4:
            int y;
            cout << "Nhap phan tu la so nguyen to ban muon xoa: ";
            cin >> y;
            if (checkSoNguyenTo(y)) 
            {
                root = deleteX(root, y);
                cout << "Phan tu " << y << " da duoc xoa khoi cay nhi phan.";
            }
            else {
                cout << "Phan tu " << y << " khong phai la so nguyen to.";
            }
            cout << endl;
            break;
        case 5:
            count = countNodes(root);
            cout << "So nut trong cay la: " << count << endl;
            break;
        case 6:
            fullcount = countFullNodes(root);
            cout << "So nut co day du hai cay con la: " << fullcount << endl;
            break;
        case 7: 
            leavescount = countLeaves(root);
            cout << "So nut la trong cay la: " << leavescount << endl;
            break;
        default:
            cout << "Lua chon khong phu hop. Hay chon lai!" << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}
