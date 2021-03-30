#include "LinkedList.h"
//using namespace std;

LinkedList::LinkedList(){
  this->head = new Node();
}

LinkedList::~LinkedList(){
}

Node * LinkedList::setHead(Node * cNode){
  this->head = cNode;
  return 0;
}

Node * LinkedList::getHead(){
  return this->head;
}

int LinkedList::insertionAtEnd(Node * cNode, int value){
  if(cNode->getNextNode() == NULL){
    Node * newNode = new Node();
    cNode->setNextNode(newNode);
    cNode->getNextNode()->setValue(value);
    return 0;
  }
  return this->insertionAtEnd(cNode->getNextNode(), value);
}

int LinkedList::deletionAtEnd(Node * cNode){
  if(cNode->getNextNode() == NULL){
    return 1;
  }
  if(cNode->getNextNode()->getNextNode() == NULL){
    delete cNode->getNextNode();
    cNode->setNextNode(NULL);
    return 0;
  }
  return this->deletionAtEnd(cNode->getNextNode());
}

int LinkedList::getSize(Node * cNode){
  if(cNode == NULL){
    return 0;
  }
  return 1 + getSize(cNode->getNextNode());
}

int LinkedList::printList(Node * cNode){
  if(cNode == NULL){
    printf("NULL\n");
    return 0;
  }
  printf("%d->", cNode->getValue());
  return printList(cNode->getNextNode());
}

/*int main(){
  printf("%s\n", "BEGIN!");
  LinkedList * linkedlist = new LinkedList();
  linkedlist->getHead()->setValue(69);
  int i;
  for(i = 0; i < 4; ++i){
    linkedlist->insertionAtEnd(linkedlist->getHead(), i);
  } 
  printf("\n%s\n", "LINKED LIST:");
  linkedlist->printList(linkedlist->getHead());
  printf("NUMBER OF NODES:\n%d\n\n", linkedlist->getSize(linkedlist->getHead()));
  return 0;
  }*/
