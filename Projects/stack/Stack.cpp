#include "Stack.h"
//using namespace std;

Stack::Stack(){
  this->ll = new LinkedList();
  this->size = 0;
}

Stack::~Stack(){
}

int Stack::push(int value){
  if(this->size == 0){
    this->ll->getHead()->setValue(value);
    ++size;
    return 0;
  }
  this->ll->insertionAtEnd(this->ll->getHead(), value);
  ++size;
  return 0;
}

int Stack::pop(){
  this->ll->deletionAtEnd(this->ll->getHead());
  --size;
  return 0;
}

int Stack::sizeStack(){
  return this->ll->getSize(this->ll->getHead());
}

int Stack::printStack(){
  return this->ll->printList(this->ll->getHead());
}

int main(){
  printf("%s\n", "BEGIN!");
  Stack * stack = new Stack();
  int i;
  for(i = 0; i < 4; ++i){
    stack->push(i);
  }
  printf("\n%s\n", "STACK:");
  stack->printStack();
  printf("NUMBER OF NODES:\n%d\n", stack->sizeStack());
  stack->push(69);
  stack->push(609);
  stack->pop();
  printf("\n%s\n", "STACK:");
  stack->printStack();
  printf("NUMBER OF NODES:\n%d\n\n", stack->sizeStack());
  return 0;
}
