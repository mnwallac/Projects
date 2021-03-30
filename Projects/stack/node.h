#ifndef NODE_H
#define NODE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <pthread.h>

class Node{
public:
  Node();
  ~Node();
  int setValue(int x);
  int getValue();
  int setNextNode(Node * cNode);
  Node * getNextNode();
private:
  Node * next;
  int value;
};
#endif

