#include "Queue.h"
//using namespace std;

Queue::Queue(){
  this->ll = new LinkedList();
  this->size = 0;
}

Queue::~Queue(){
}

int Queue::enqueue(int value){
  if(this->size == 0){
    this->ll->getHead()->setValue(value);
    ++size;
    return 0;
  }
  this->ll->insertionAtEnd(this->ll->getHead(), value);
  ++size;
  return 0;
}

int Queue::dequeue(){
  if(this->size == 1){
    Node * temp;
    Node * head = new Node();;
    temp = this->ll->getHead();
    this->ll->setHead(head);
    --size;
    int val = temp->getValue();
    free(temp);
    return val;
  }
  Node * temp;
  temp = this->ll->getHead();
  this->ll->setHead(this->ll->getHead()->getNextNode());
  --size;
  int val = temp->getValue();
  free(temp);
  return val;
}

int Queue::sizeQueue(){
  return this->ll->getSize(this->ll->getHead());
}

int Queue::printQueue(){
  return this->ll->printList(this->ll->getHead());
}
