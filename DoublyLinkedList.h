/*
Moises Lopez
2297564
molopez@chapman.edu
350-02
Assignment 4
*/

#include <iostream>
#include "ListNode.h"

using namespace std;

template <class T>
class DoublyLinkedList{
  private:

  public:
    unsigned int size;
    ListNode<T> *front;
    ListNode<T> *back;

    DoublyLinkedList(); //constructor
    ~DoublyLinkedList(); //destructor

    void insertBack(T data);
    T removeFront();
    T getFront();

    int removeAtPos(int pos);

    unsigned int getSize();
    bool isEmpty();
    void printList();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
  size = 0;
  front = NULL;
  back = NULL;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){

}

template <class T>
void DoublyLinkedList<T>::insertBack(T d){
  //check if empty before removing
  ListNode<T> *node = new ListNode<T>(d);
  //if(size == 0)
  if(isEmpty())
    front = node;

  else {
    //not isEmpty
    back->next = node;
    node->prev = back;
  }

  back = node;
  ++size;
}

template <class T>
T DoublyLinkedList<T>::removeFront(){
  if(!isEmpty()){
    ListNode<T> *ft = front;
    //if the front is the lone node
    if(front->next = NULL){
      front = NULL;
      back = NULL;
    } else {
      front->next->prev = NULL;
      front = front->next;
    }

    T temp = ft->data;

    delete ft;
    size--;
    return temp;
  }

  else
    return T();
}

template <class T>
T DoublyLinkedList<T>::getFront(){
  return front->data;
}

template <class T>
void DoublyLinkedList<T>::printList(){
  ListNode<T> *curr = front;

  while(curr != NULL){
    cout << curr->data << endl;
    curr = curr->next;
  }
}

template <class T>
int DoublyLinkedList<T>::removeAtPos(int pos){
  int idx = 0;
  //need to keep track of the current
  ListNode<T> *curr = front;
  ListNode<T> *prev = front;

  while(idx != pos){
    //loop until i find the position
    prev = curr;
    curr = curr->next;
    ++idx;
  }

  // prev->next = curr->next;
  // curr->next->prev = prev;
  // curr->next = NULL;
  // curr->prev = NULL;
  // curr->data = NULL;
  //
  // delete curr;
  // size--;

  prev->next = curr->next;
  curr->next = NULL;
  int temp = curr->data;
  delete curr;
  size--;

  return temp;
}

template <class T>
unsigned int DoublyLinkedList<T>::getSize(){
  return size;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty(){
  return (size == 0);
}
