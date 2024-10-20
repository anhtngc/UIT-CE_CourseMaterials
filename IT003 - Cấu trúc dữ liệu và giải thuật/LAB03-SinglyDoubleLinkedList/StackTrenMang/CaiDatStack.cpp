#include <iostream>
#include "StackInArray.h"
#include "StackInLinkedList.h"

using namespace std;

int main() {
    StackArray SA;
    SA.Push(1);
    SA.Push(2);
    SA.Push(3);
    while (!SA.IsEmpty()) {
        cout << SA.Pop() << " ";
    }
    cout << endl;
    StackDSLK SN;
    SN.Push(4);
    SN.Push(5);
    SN.Push(6);
    while (!SN.IsEmpty()) {
        cout << SN.Pop() << " ";
    }
    cout << endl;

    return 0;
}
