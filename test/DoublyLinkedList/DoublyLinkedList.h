//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLYLINKEDLIST_H
#define LINKEDLIST_DOUBLYLINKEDLIST_H

#include <vector>
#include <memory>
#include "DoubleLinkedNode.h"
#include "DoublyLinkedListIterator.h"
#include "ConstDoublyLinkedListIterator.h"
#include "ReverseDoublyLinkedListIterator.h"

template<typename T>
class DoubleLinkedNode;
template<typename T>
class DoublyLinkedListIterator;
template<typename T>
class ConstDoublyLinkedListIterator;
template<typename T>
class ConstReverseDoublyLinkedListIterator;

template<typename T>
class DoublyLinkedList {
    friend class DoubleLinkedNode;
    friend class DoublyLinkedListIterator;
    friend class ConstDoublyLinkedListIterator;
    friend class ConstReverseDoublyLinkedListIterator;

 public:
  using Node_Ptr = DoubleLinkedNode<T>*;

  using iterator =  /*put the type of your iterator here*/;
  using const_iterator =  /*put the type of your const iterator here*/;
  using reverse_iterator = /*put the type of your reverse iterator here*/;
  using const_reverse_iterator = /*put the type of your const reverse iterator here*/;

  //create a Doubly Linked List that has the same values
  //as in the vector and in the same order
  explicit DoublyLinkedList(const std::vector<T>& values){
      DoublyLinkedList list;
      for (auto elem: values){
          list.push_back(elem);
      }
  }


  //create an empty DoublyLinkedList
  DoublyLinkedList()

  virtual ~DoublyLinkedList(){
      Node_Ptr curr = head;
      Node_Ptr prev = head;
      while(curr){
          curr = curr -> next;
          delete prev;
          prev = curr;
      }
      delete prev;
  }

  //remove all of the elements from your list
  void clear(){
      node* currNode = head;
      node* temp = head;
      while (currNode)
      {
          currNode = currNode -> next;
          delete temp;
          temp = currNode;
      }
      delete temp;
      head = nullptr;
      tail = nullptr;
  }

  //get a reference to the front element in the list
  const T& front() const{
      return head;
  }
  T& front(){
      return head;
  }

  //get a reference to the last element in the list
  const T& back() const{
      return tail;
  }
  T& back(){
      return tail;
  }

  //add a value to the front of the list
  void push_front(const T& value){
      DoubleLinkedNode* currNode = new DoublyLinkedNode(value);
      if (head == nullptr)
      {
          head = currNode;
          tail = currNode;
      }
      else
      {
          head -> prev = currNode;
          currNode -> next = head;
          head = currNode;
      }
      len++;
  }

  //add a value to the back of the list
  void push_back(const T& value){
      DoubleLinkedNode* currNode = new DoubleLinkedNode(value);
      if (head)
      {
          tail -> next = currNode;
          currNode -> prev = tail;
          currNode -> next = nullptr;
      }
      else
      {
          head = currNode;
          tail = currNode;
      }
      len++;
  }

  //is the list empty?
  bool empty() const{
      if (head == nullptr && tail == nullptr){
          return true;
      }
      return false;
  }

  //return the number of elements in the list
  int size() const{
      return len;
  }

  //return a constant bidirectional iterator to the front of the list
  const_iterator begin() const{
      return head;
  }
  const_iterator end() const{
      return tail;
  }

  //return a nonconstant bidirectional iterator to the front of the list
  iterator begin(){
      return head;
  }
  iterator end(){
      return tail;
  }

  const_reverse_iterator crbegin() const;
  const_reverse_iterator crend() const;

  reverse_iterator rbegin();
  reverse_iterator rend();

  //insert the value at the position in the list
  //I promise not to use the iterator again after the insertion is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And the iterator was pointing to the 9 and we wanted to
  //insert -22 the result would be
  //1 <-> 22 <-> 9 <-> 17
  void insert(iterator& position, const T& value){
    DoubleLinkedNode* newNode;
    newNode.data = value;
    newNode.next = position;
    newNode.prev = position -> prev;
    position -> prev -> next = newNode;
    position -> prev = newNode;
  }

  //remove the element at the position pointed to
  //by the iterator.
  //I promise not to use the iterator again after the erase is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And when the wanted to erase the iterator was at the 9
  //1 <-> 17
  void erase(iterator& position){
      position -> prev -> next = position -> next;
      position -> next -> prev = position -> prev;
      delete position;

  }

 private:
  Node_Ptr head;
  Node_Ptr tail;
  int len;
};

//write to the stream each element in the list in order
//with a space in between them
template<typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& doublyLinkedList){
    node* currNode = doublyLinkedList.head;
    while (currNode){
        out << currNode -> data << " ";
        currNode = currNode -> next;
    }
    std::cout << std::end;
    return out;
}

//read elements from the stream as long as it is good
// or until a newline (\n) is encountered
//if a newline is encountered it should be consumed
template<typename T>
std::istream& operator>>(std::istream& in, DoublyLinkedList<T>& doublyLinkedList){
    T data;
    char c = in.peek();
    while(c != "\n" || c != EOF){
        in >> data;
        doublyLinkedList.push_back(data);
        c = in.peek();
    }
    return in;
}

#endif //LINKEDLIST_DOUBLYLINKEDLIST_H