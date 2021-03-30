#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

class Node{
 public:
  Node();
  ~Node();
  int setValue(int x);
  int getValue();
  int setNextNode(Node * cNode);//
  Node * getNextNode();
 private:
  Node * next;
  int value;
};
#endif
