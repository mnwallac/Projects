#ifndef STACK_H
#define STACK_H
#include <iostream> //for cout
#include <stdio.h> //for printf
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "LinkedList.h"

class Stack{
 public:
  Stack();
  ~Stack();
  int push(int value);
  int pop();
  int sizeStack();
  int printStack();
 private:
  LinkedList * ll;
  int size;
};

#endif
