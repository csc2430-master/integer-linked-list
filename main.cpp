#include "linked_list.h"

#include <iostream>

using std::cout;
using std::endl;

void PrintElement(const LinkedList& list, size_t position);

int main() {
    LinkedList list;
    cout << list.ToString() << endl;
    cout << "Insert(7, 7) " << list.Insert(7, 7) << endl;
    cout << list.ToString() << endl;
    cout << "Insert(5, 0) " << list.Insert(5, 0) << endl;
    cout << list.ToString() << endl;
    cout << "Insert(2, 1) " << list.Insert(2, 1) << endl;
    cout << list.ToString() << endl;
    cout << "Insert(3, 2) " << list.Insert(3, 2) << endl;
    cout << list.ToString() << endl;
    cout << "Insert(8, 0) " << list.Insert(8, 0) << endl;
    cout << list.ToString() << endl;
    cout << "Insert(4, 2) " << list.Insert(4, 2) << endl;
    cout << list.ToString() << endl;
    for (int i = 0; i < list.Size() + 1; ++i) {
        PrintElement(list, i);
    }
    cout << list.IndexOf(8) << endl;
    cout << list.IndexOf(5) << endl;
    cout << list.IndexOf(4) << endl;
    cout << list.IndexOf(2) << endl;
    cout << list.IndexOf(3) << endl;
    cout << list.IndexOf(7) << endl;

    LinkedList otherList = list;
    for (int i = 0; i < otherList.Size() + 1; ++i) {
        PrintElement(otherList, i);
    }



    return 0;
}
void PrintElement(const LinkedList& list, size_t position){
    bool error;
    int element = list.Get(position, error);
    if (error){
        cout << "Invalid Position" << endl;
    }else{
        cout << element << endl;
    }
}
