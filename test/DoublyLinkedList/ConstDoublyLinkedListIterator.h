//
// Created by mfbut on 2/16/2019.
//

#ifndef TESTDOUBLELINKEDLIST_CONSTDOUBLYLINKEDLISTITERATOR_H
#define TESTDOUBLELINKEDLIST_CONSTDOUBLYLINKEDLISTITERATOR_H

#include "DoubleLinkedNode.h"
#inlcude "DoublyLinkedList.h"
#include "ConstReverseDoublyLinkedListIterator.h"
#include "DoublyLinkedListIterator.h"

template<typename T>
class DoubleLinkedNode;
template<typename T>
class DoublyLinkedList;
template<typename T>
class DoublyLinkedListIterator;
template<typename T>
class ConstReverseDoublyLinkedListIterator;

template<typename T>
class ConstDoublyLinkedListIterator {
    friend class DoubleLinkedNode;
    friend class DoublyLinkedList;
    friend class DoublyLinkedListIterator;
    friend class ConstReverseDoublyLinkedListIterator;
    //you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods

 public:
    ConstDoublyLinkedListIterator(const DoublyLinkedNode<T>* node, const DoublyLinkedList<T> list);
    ConstDoublyLinkedListIterator(const ConstDoublyLinkedListIterator& orig);

  //are the two iterators equal?
  //they are if they are over the same doubly linked list
  //and (they are referring to the same element in the list
  //or they are out of bounds)
  bool operator==(const ConstDoublyLinkedListIterator<T>& rhs) const{
      if ((rhs.list == this -> list && rhs.node == this -> node) || (rhs == nullptr && this = nullptr)){
          return true;
      }
      return false;
  }

  //are the two iterators different?
  bool operator!=(const ConstDoublyLinkedListIterator<T>& rhs) const{
      return !(*this == rhs);
  }

  //is the iterator safe to dereference?
  operator bool() const{
      return (this != nullptr);
  }

  //go to the next element
  ConstDoublyLinkedListIterator<T>& operator++() { //pre
      this.node = this -> next;
      return this;
  }
  const ConstDoublyLinkedListIterator<T> operator++(int) {//post
      DoublyLinkedListIterator* temp = this;
      this.node = this -> next;
      return temp;
  }

  //go to the previous element
  ConstDoublyLinkedListIterator<T>& operator--() {//pre
      this.node = this -> prev;
      return this;
  }
  const ConstDoublyLinkedListIterator<T> operator--(int) { //post
      DoublyLinkedListIterator* temp = this;
      this.node = this -> prev;
      return temp;
  }

  //get a const reference to the value
  const T& operator*() const{
      return this.node -> data;
  }

private:
    DoublyLinkedNode<T> *node;
    DoublyLinkedList<T> list;
};

#endif //TESTDOUBLELINKEDLIST_CONSTDOUBLYLINKEDLISTITERATOR_H
