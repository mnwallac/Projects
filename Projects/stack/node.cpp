#include "node.h"
//using namespace std;

Node::Node(){
  this->next = NULL;
}

Node::~Node(){
}

int Node::setValue(int x){
  this->value = x;
  return 0;
}

int Node::getValue(){
  return this->value;
}

int Node::setNextNode(Node * cNode){
  this->next = cNode;
  return 0;
}

Node * Node::getNextNode(){
  return this->next;
}

/*int main(){
  printf("%s\n", "Yo, Mikeyday!");
  Node * node = new Node();
  node->setValue(69);
  printf("Nodes:\n");
  printf("%d\n", node->getValue());  
  return 0;
  }*/
