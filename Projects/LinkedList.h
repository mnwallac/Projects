#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "node.h"
//using namespace std;

class LinkedList{
 public:
  LinkedList();
  ~LinkedList();
  Node * setHead(Node * cNode);//
  Node * getHead();
  int insertionAtEnd(Node * cNode, int value);
  int deletionAtEnd(Node * cNode);
  int insertion(Node * cNode, int value, int index);
  int deletion(Node * cNode, int index);
  int deletionAtHead(Node * cNode);
  int getSize(Node * cNode);
  int printList(Node * cNode);
 private:
  Node * head;
};
#endif
