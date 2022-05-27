//
// Created by Carlos R. Arias on 5/27/22.
//

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

int LinkedList::Get(size_t position) const {
    return 0; // Wednesday
}

int LinkedList::IndexOf(int element) const {
    return 0; // Wednesday
}

void LinkedList::Clear() {
 // Wednesday
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
