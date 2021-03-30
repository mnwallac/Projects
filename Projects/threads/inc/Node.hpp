#ifndef NODE_H
#define NODE_H
#include <iostream> //for cout
#include <stdio.h> //for printf
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

template <class T> 
class Node{
 public:
  Node<T>(){
    this->next = NULL;
  };


  ~Node<T>(){
  };

  void * setValue(T x){
    this->value = x;
    return 0;
  };

  T getValue(){
    return this->value;
  };

  int setNextNode(Node<T> * cNode){
    this->next = cNode;
    return 0;
  };

  Node<T> * getNextNode(){
    return this->next;
  };

private:
  Node<T> * next;
  T value;

};
#endif
