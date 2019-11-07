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


#include "ListNode.h"

// This class will be used to generate a Queue as a template class
// We will be passing in Students as objects into a queue using this class

template <class T>
class GenQueue{
public:
  ListNode<T> *head;
  ListNode<T> *tail;
  unsigned int size;

  GenQueue();
  ~GenQueue();
  void insert(T d);
  T deleteNode();
  T getHead();
  T getTail();
  void returnQueue();
  unsigned int getSize();
  bool isEmpty();
};


template <class T>
GenQueue<T>::GenQueue(){
  size = 0;
  head = NULL;
  tail = NULL;
}

template <class T>
GenQueue<T>::~GenQueue(){

}

template <class T>
void GenQueue<T>::insert(T d){
  ListNode<T> *node = new ListNode<T>(d);
  // check if empty
  if(size == 0){
    head = node;
  }
  else{
    tail->next = node;
    node->prev = tail;
  }
  tail = node;
  ++size;
}

template <class T>
T GenQueue<T>::deleteNode(){
  // check if empty
  if(!isEmpty()){
    ListNode<T>* oldHead = head;
    T oldNode = oldHead->data;

    // if theres only one element
    if(head->next == NULL){
      head = NULL;
      tail = NULL;
    }
    // if theres more than one element
    else{
      head->next->prev = NULL;
      head = head->next;
    }

    delete oldHead;
    size --;
    return oldNode;

  }
  else{
    return T();
  }
}

template <class T>
T GenQueue<T>::getHead(){
  return head->data;

}

template <class T>
T GenQueue<T>::getTail(){
  return tail->data;
}

template <class T>
void GenQueue<T>::returnQueue(){
  ListNode<T> *curr = head;
  while(true){
    if(curr==NULL){
      break;
    }
    cout << curr->data << endl;
    curr = curr->next;
  }
}

template <class T>
unsigned int GenQueue<T>::getSize(){
  return size;
}

template <class T>
bool GenQueue<T>::isEmpty(){
  return(size==0);
}
