/*
Sammie Walker
Eric Wasserman
2315055
2300841
ewasserman@chapman.edu
swalker@chapman.edu
CPSC 350 - 03
Assignment 4
*/

#include <iostream>
using namespace std;

template <class T>
class ListNode{
public:
  T data;
  ListNode<T> *next;
  ListNode<T> *prev;

  ListNode();
  ListNode(T d);
  ~ListNode();

};

template <class T>
ListNode<T>::ListNode(){}

template <class T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL; // null pointer
  prev = NULL;
}

template <class T>
ListNode<T>::~ListNode(){
  if(next!=NULL){
    next = NULL;
    prev = NULL;

    delete next;
    delete prev;

  }
}
