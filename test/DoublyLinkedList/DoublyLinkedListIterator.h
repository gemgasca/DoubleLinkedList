//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H
#define LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H

#include "DoubleLinkedNode.h"
#include "DoublyLinkedList.h"
#include "ConstDoublyLinkedListIterator.h"
#include "ConstReverseDoublyLinkedListIterator.h"

template<typename T>
class DoubleLinkedNode;
template<typename T>
class DoublyLinkedList;
template<typename T>
class ConstDoublyLinkedListIterator;
template<typename T>
class ConstReverseDoublyLinkedListIterator;

template<typename T>
class DoublyLinkedListIterator {
    friend class DoubleLinkedNode;
    friend class DoublyLinkedList;
    friend class ConstDoublyLinkedListIterator;
    friend class ConstReverseDoublyLinkedListIterator;
  //you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods

 public:
  DoublyLinkedListIterator(const DoublyLinkedListIterator& orig);

  //are the two iterators equal?
  //they are if they are over the same doubly linked list
  //and (they are referring to the same element in the list
  //or they are out of bounds)
  bool operator==(const DoublyLinkedListIterator<T>& rhs) const{
      if ((this.list == rhs.list && this.node == rhs.node) || (rhs = nullptr && this == nullptr)){
          return true;
      }
      return false;
  }

  //are the two iterators different?
  bool operator!=(const DoublyLinkedListIterator<T>& rhs) const{
      return !(this == rhs);
  }

  //is the iterator safe to dereference?
  operator bool() const{
      return (this != nullptr);
  }

  //go to the next element
  DoublyLinkedListIterator<T>& operator++() {   // pre
      this.node = this -> next;
      return this;
  }
  const DoublyLinkedListIterator<T> operator++(int){    / post
      DoublyLinkedListIterator* temp = this;
      this.node = this -> next;
      return temp;
  }

  //go to the previous element
  DoublyLinkedListIterator<T>& operator--(){    // pre
        this.node = this -> prev;
        return this;
    }
  const DoublyLinkedListIterator<T> operator--(int){    // post
      DoublyLinkedListIterator* temp = this;
      this.node = this -> prev;
      return temp;
  }

  //get a const reference to the value
  const T& operator*() const{
      return this.node -> data;
  }

  //get a non const iterator
  T& operator*(){
      return this.node -> data;
  }

private:
    DoublyLinkedListIterator* list;
    DoubleLinkedNode* node;
};

#endif //LINKEDLIST_GENERICDOUBLYLINKEDLISTITERATOR_H
