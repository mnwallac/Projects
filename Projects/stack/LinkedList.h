#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdlib.h>
#include <iostream> //for cout
#include <stdio.h> //for printf
#include <pthread.h>
#include <string.h>
#include "node.h"

class LinkedList{
 public:
  LinkedList();
  ~LinkedList();
  Node * setHead(Node * cNode);
  Node * getHead();
  int insertionAtEnd(Node * cNode, int value);
  int deletionAtEnd(Node * cNode);
  int getSize(Node * cNode);
  int printList(Node * cNode);
 private:
  Node * head;
};

#endif
