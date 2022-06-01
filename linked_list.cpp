//
// Created by Carlos R. Arias on 5/27/22.
//

/*
 * 1 sheet of letter sized paper written on both sides
 * 8.5 * 11 inches
 */

#include "linked_list.h"

#include <string>
#include <sstream>

using std::string;
using std::stringstream;

LinkedList::LinkedList() {
    _size = 0;
    _head = nullptr;
}

LinkedList::~LinkedList() {
    Node* toDelete = _head;
    Node* tmp = nullptr;
    while (toDelete != nullptr){
        if (toDelete->next != nullptr){
            tmp = toDelete->next;
            delete toDelete;
            toDelete = tmp;
        }else{
            delete toDelete;
            toDelete = nullptr;
        }
    }
}

LinkedList::LinkedList(const LinkedList &ll) {
    _head = nullptr;
    _size = 0;

//    bool e;
//    for (int i = 0; i < ll._size; ++i) {
//        Insert(ll.Get(i, e), i);
//    }
    if (ll.IsEmpty())
        return;
    Node* neo = nullptr;
    Node* myLast = nullptr;
    // Head process
    _head = new Node;
    _head->data = ll._head->data;
    _head->next = nullptr;
    _size++;

    myLast = _head;
    for (Node* tmp = ll._head->next; tmp != nullptr; tmp = tmp->next){
        neo = new Node;
        neo->data = tmp->data;
        neo->next = nullptr;
        myLast->next = neo;
        myLast = myLast->next;
        _size++;
    }

}

const LinkedList &LinkedList::operator=(const LinkedList &rhs) {
    return *this;
}
// https://github.com/csc2430-master/integer-linked-list

bool LinkedList::Insert(int element, size_t position) {
    if (position > _size)
        return false;
    Node* neo = new Node;
    neo->data = element;
    neo->next = nullptr;

    if (_head == nullptr){
        _head = neo;
    }else if (position == 0){
        neo->next = _head;
        _head = neo;
    }else{
        Node* tmp = _head;
        for (int i = 0; i < position - 1; ++i) {
            tmp = tmp->next;
        }
        neo->next = tmp->next;
        tmp->next = neo;
    }
    _size++;
    return true;
}

int LinkedList::Remove(size_t position) {
    return 0;
}

int LinkedList::Get(size_t position, bool& error) const {
    if (position >= _size){
        error = true;
        return 0;
    }
    error = false;
    Node* tmp =  _head;
    for (int i = 0; i < position; ++i) {
        tmp = tmp->next;
    }
    return tmp->data;
    return 0; // Wednesday
}

int LinkedList::IndexOf(int element) const {
    int index = 0;
    for (Node* tmp = _head; tmp != nullptr; tmp = tmp->next){
        if (tmp->data == element)
            return index;
        index++;
    }
    return -1;
}

void LinkedList::Clear() {
    Node* toDelete = _head;
    Node* tmp = nullptr;
    while (toDelete != nullptr){
        if (toDelete->next != nullptr){
            tmp = toDelete->next;
            delete toDelete;
            toDelete = tmp;
        }else{
            delete toDelete;
            toDelete = nullptr;
        }
    }
    _size = 0;
    _head = nullptr;
}

bool LinkedList::IsEmpty() const {
    return _head == nullptr;
}

size_t LinkedList::Size() {
    return _size;
}

string LinkedList::ToString() const {
    stringstream ss;
    ss << "<";
//    Node* tmp = _head;
//    for (int i = 0; i < _size; ++i) {
//        if (i != _size - 1)
//            ss << tmp->data << ", ";
//        else
//            ss << tmp->data;
//        tmp = tmp->next;
//    }
    for (Node* tmp = _head; tmp != nullptr; tmp = tmp->next)
        if (tmp->next != nullptr)
            ss << tmp->data << ", ";
        else
            ss << tmp->data;
    ss << ">";
    return ss.str();
}
