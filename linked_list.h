//
// Created by Carlos R. Arias on 5/27/22.
//

#ifndef INTEGER_LINKED_LIST_LINKED_LIST_H
#define INTEGER_LINKED_LIST_LINKED_LIST_H

#include <string>
using std::string;

struct Node{
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* _head;
    size_t _size;
public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList& ll);
    const LinkedList& operator=(const LinkedList& rhs);
    bool Insert(int element, size_t position);
    int Remove(size_t position);
    int Get(size_t position, bool& error)const;
    int IndexOf(int element)const;
    void Clear();
    bool IsEmpty()const;
    size_t Size();
    string ToString()const;
};


#endif //INTEGER_LINKED_LIST_LINKED_LIST_H
