//
// Created by mfbut on 2/16/2019.
//

#ifndef TESTDOUBLELINKEDLIST_CONSTREVERSEDOUBLYLINKEDLISTITERATOR_H
#define TESTDOUBLELINKEDLIST_CONSTREVERSEDOUBLYLINKEDLISTITERATOR_H

#include "DoubleLinkedNode.h"
#inlcude "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"
#include "ConstDoublyLinkedListIterator.h"

template<typename T>
class DoubleLinkedNode;
template<typename T>
class DoublyLinkedList;
template<typename T>
class DoublyLinkedListIterator;
template<typename T>
class ConstDoublyLinkedListIterator;

template<typename T>
class ConstReverseDoublyLinkedListIterator {
    friend class DoubleLinkedNode;
    friend class DoublyLinkedList;
    friend class DoublyLinkedListIterator;
    friend class ConstDoublyLinkedListIterator;
//you must implement at least the methods below
  //you are free to add (and will likely need to add)
  //more members and methods

  //copy constructor
  ConstReverseDoublyLinkedListIterator(const ConstReverseDoublyLinkedListIterator& orig);

  //are the two iterators equal?
  //they are if they are over the same doubly linked list
  //and (they are referring to the same element in the list
  //or they are out of bounds)
  bool operator==(const ConstReverseDoublyLinkedListIterator<T>& rhs) const{
      if ((this.list == rhs.list && this.node == rhs.node) || (rhs = nullptr && this == nullptr)){
          return true;
      }
      return false;
  }

  //are the two iterators different?
  bool operator!=(ConstReverseDoublyLinkedListIterator<T>& rhs) const{
      return !(*this == rhs);
  }

  //is the iterator safe to dereference?
  operator bool() const{
      return (this != nullptr);
  }

  //go to the next element
  ConstReverseDoublyLinkedListIterator<T>& operator++(){
      this.node = this -> prev;
      return this;
  }
  const ConstReverseDoublyLinkedListIterator<T> operator++(int){
      DoublyLinkedListIterator* temp = this;
      this.node = this -> prev;
      return temp;
  }

  //go to the previous element
  ConstReverseDoublyLinkedListIterator<T>& operator--(){
      this.node = this -> next;
      return this;
  }
  const ConstReverseDoublyLinkedListIterator<T> operator--(int){
      DoublyLinkedListIterator* temp = this;
      this.node = this -> next;
      return temp;
  }

  //get a const reference to the value
  const T& operator*() const{
      return this.node -> data;
  }

};

#endif //TESTDOUBLELINKEDLIST_CONSTREVERSEDOUBLYLINKEDLISTITERATOR_H
