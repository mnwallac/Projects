#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.hpp"

template <class T> 
class Queue{
 public:
  Queue<T>(){
    this->ll = new LinkedList<T>();
    this->size = 0;
  };

  ~Queue<T>(){
  };

  int enqueue(T value){
    if(this->size == 0){
      this->ll->getHead()->setValue(value);
      ++size;
      return 0;
    }
    this->ll->insertionAtEnd(this->ll->getHead(), value);
    ++size;
    return 0;
  };

  T dequeue(){
    if(this->size == 1){
      Node<T> * temp;
      Node<T> * head = new Node<T>();;
      temp = this->ll->getHead();
      this->ll->setHead(head);
      --size;
      T val = temp->getValue();
      free(temp);
      return val;
    }
    Node<T> * temp;
    temp = this->ll->getHead();
    this->ll->setHead(this->ll->getHead()->getNextNode());
    --size;
    T val = temp->getValue();
    //int val = temp->getValue();
    free(temp);
    return val;
  };

  T front(){
    return this->ll->getHead()->getValue();
  };
  
  int sizeQueue(){
    return size;
    //return this->ll->getSize(this->ll->getHead());
  };

  T printQueue(){
    return this->ll->printList(this->ll->getHead());
  };

 private:
  LinkedList<T> * ll;
  int size;
};
#endif
