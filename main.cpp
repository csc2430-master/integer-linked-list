#include "linked_list.h"

#include <iostream>

using std::cout;
using std::endl;

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

    return 0;
}
