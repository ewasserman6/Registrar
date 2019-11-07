using namespace std;
#include <cstddef>

template <class T>
class DoublyLinkedList{
private:
  DoublyLinkedList<T> *front;
  DoublyLinkedList<T> *back;
  unsigned int size;

public:
  DoublyLinkedList();
  ~DoublyLinkedList();

  void insertFront(T d);
  void insertBack(T d);
  DoublyLinkedList<T>* remove(T d);
  T removeFront();
  T removeBack();
  T deletePos(int pos); //removeAt()

  bool isEmpty();
  void printList();
  unsigned int getSize();

};

// DoublyLinkedList implementation
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
  size = 0;
  front = NULL;
  back = NULL;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
  // research it
  // HINT: you will have to iterate through the list

}

template <class T>
void DoublyLinkedList<T>::insertFront(T d){
  DoublyLinkedList<T> *node = new DoublyLinkedList<T>(d);

  if(size == 0){   // or size == 0
    // if we have an empty ListNode
    back = node;
  }
  else{
    // not an empty list
    front-> prev = node;
    node->next = front;
  }
  front = node;
  size ++;
}

template <class T>
T DoublyLinkedList<T>::removeFront(){
  // check if it's empty before proceeding
  DoublyLinkedList<T> *ft = front;

  if(size == 1){ // size == 1 or if front-> == NULL or if front = back
    // one node in the List
    back = NULL;
  }
  else{
    // list has more than one node in the list
    front -> next -> prev = NULL;
  }
  front = front -> next;
  ft -> next = NULL; // get rid of arrows pointer
  int temp = ft-> data;
  delete ft;
  size --;

  return temp;

}


template <class T>
void DoublyLinkedList<T>::insertBack(T d){
  DoublyLinkedList<T> *node = new DoublyLinkedList<T>(d);

  if(isEmpty()){   // or size == 0
    // if we have an empty ListNode
    front = node;
  }
  else{
    // not an empty list
    back-> next = node;
    node->prev = back;
  }
  back = node;
  size ++;
}

template <class T>
DoublyLinkedList<T>* DoublyLinkedList<T>::remove(T d){ // aka int key
  // check if empty before attempting to remove
  DoublyLinkedList<T> *curr = front;
  while(curr->data != d){
    //lets look for the key/value to be removed
    curr = curr->next;

    if (curr == NULL){ // means value we are looking for does not exist in the list
      return NULL;
    }

    // we found the node/ value to be removed
    if(curr == front){
      // node to be moved is the front
      front = curr -> next;
    }
    else{
      // its not the front
      curr -> prev -> next = curr -> next;

    }

    if (curr == back){
      back = curr -> prev;
    }

    else{
      // not the back
      curr -> next -> prev = curr -> prev;
    }
    curr -> next = NULL;
    curr -> prev = NULL;

    size --;
    return curr;
  }
}

template <class T>
bool DoublyLinkedList<T>::isEmpty(){
  return(front == -1);
}
