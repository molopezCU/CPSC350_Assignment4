/*
Moises Lopez
2297564
molopez@chapman.edu
350-02
Assignment 4
*/

#include <iostream>

using namespace std;

template <class T>
class ListNode{
  private:

  public:
    T data;
    ListNode<T> *next;
    ListNode<T> *prev;

    ListNode(); //constructor
    ListNode(T data);
    ~ListNode(); //destructor
};

template <class T>
ListNode<T>::ListNode(){

}

template <class T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::~ListNode(){
  if(next != NULL){
    next = NULL;
    prev = NULL;

    delete next;
    delete prev;
  }
}
