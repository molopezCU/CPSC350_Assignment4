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
class GenQueue{
  private:

  public:
    unsigned int numElements;
    ListNode<T> *front;
    ListNode<T> *back;

    GenQueue(); //constructor
    ~GenQueue(); //destructor

    void enqueue(T d);
    T dequeue();

    T tFront();
    T tBack();

    void printQ();
    bool isEmpty();
    unsigned int getSize();
};

template <class T>
GenQueue<T>::GenQueue(){
  numElements = 0;
  front = NULL;
  back = NULL;
}

template <class T>
GenQueue<T>::~GenQueue(){

}

template <class T>
void GenQueue<T>::enqueue(T d){
  ListNode<T> *node = new ListNode<T>(d);

  if(numElements == 0)
    front = node;
  else{
    back->next = node;
    node->prev = back;
  }

  back = node;
  ++numElements;
}

template <class T>
T GenQueue<T>::dequeue(){
  if(!isEmpty()){
    ListNode<T> *node = front;

    T temp = node->data;

    //if the node is the only one in the queue
    if(front->next == NULL)
    {
      front = NULL;
      back = NULL;
    }
    //if the node is not the only one in the queue
    else
    {
      front->next->prev = NULL;
      front = front->next;
    }

    delete node;
    --numElements;
    return temp;
  }
  else
    return T();
}

template <class T>
T GenQueue<T>::tFront(){
  return front->data;
}

template <class T>
T GenQueue<T>::tBack(){
  return back->data;
}

template <class T>
void GenQueue<T>::printQ(){
  ListNode<T> *curr = front;

  while(true){
    if(curr != NULL){
      cout << curr->data << endl;
      curr = curr->next;
    }

    else
      break;
  }
}

template <class T>
bool GenQueue<T>::isEmpty(){
  return (numElements == 0);
}

template <class T>
unsigned int GenQueue<T>::getSize(){
  return numElements;
}
