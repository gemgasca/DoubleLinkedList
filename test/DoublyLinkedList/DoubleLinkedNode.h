//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLELINKEDNODE_H
#define LINKEDLIST_DOUBLELINKEDNODE_H

#include <iostream>
#include "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"
#include "ConstDoublyLinkedListIterator.h"
#include "ConstReverseDoublyLinkedListIterator.h"

//the class that represents a node in the list

template<typename T>
class DoublyLinkedList;
template<typename T>
class DoublyLinkedListIterator;
template<typename T>
class ConstDoublyLinkedListIterator;
template<typename T>
class ConstReverseDoublyLinkedListIterator;

template<typename T>
class DoubleLinkedNode{
    friend class DoublyLinkedList;
    friend class DoublyLinkedListIterator;
    friend class ConstDoublyLinkedListIterator;
    friend class ConstReverseDoublyLinkedListIterator;
public:
    T data;
    DoubleLinkedNode* next;
    DoubleLinkedNode* prev;

    DoubleLinkedNode() {}
    DoubleLinkedNode(T d): data(d), next(nullptr), prev(nullptr) {}

};

template<typename T>
DoublyLinkedNode<T>::DoublyLinkedNode(T data, T next, T prev) : data(data), next(next), prev(prev) {

}

template<typename T>
DoubleLinkedNode<T>::DoublyLinkedNode() {
    next = nullptr;
    prev = nullptr;
}

#endif //LINKEDLIST_DOUBLELINKEDNODE_H
