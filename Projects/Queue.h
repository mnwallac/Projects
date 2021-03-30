#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.h"

class Queue{
 public:
  Queue();
  ~Queue();
  int enqueue(int value);
  int dequeue();
  int sizeQueue();
  int printQueue();
 private:
  LinkedList * ll;
  int size;
};
#endif
