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

int LinkedList::insertion(Node * cNode, int value, int index){
  if(cNode->getNextNode() == NULL){
    Node * newNode = new Node();
    newNode->setNextNode(NULL);
    cNode->setNextNode(newNode);
    newNode->setValue(value);
    return 1;
  }
  if(index == 0){
    Node * newNode = new Node();
    newNode->setNextNode(cNode->getNextNode());
    cNode->setNextNode(newNode);
    newNode->setValue(value);
    return 0;
  }
  return this->insertion(cNode->getNextNode(), value, index-1);
}

int LinkedList::deletion(Node * cNode, int index){
  if(cNode->getNextNode() == NULL){
    return 1;
  }
  if(index == 1){
    Node * temp;
    temp = (cNode->getNextNode());
    cNode->setNextNode(cNode->getNextNode()->getNextNode());
    free(temp);
    return 0;
  }
  return this->deletion(cNode->getNextNode(), index-1);
}

int LinkedList::deletionAtHead(Node * cNode){
  if(head == cNode){
    Node * temp;
    temp = (cNode->getNextNode());
    free(cNode);
    return 0;
  }
  return this->deletionAtHead(cNode->getNextNode());
  /*  
  1)need to delete front
  2)temp node to maintain l.l.
  3)this is unfinished and wrong lol!
  4)
  5)
  */
}

//INSERTION WITHOUT RECURSION
  /*int i;
  for(i = 0; i < index; ++i){
    if(cNode->getNextNode() == NULL){
      return 1;
    }
    cNode = cNode->getNextNode();
  }
  Node * newNode = new Node();
  newNode->setNextNode(cNode->getNextNode());
  cNode->setNextNode(newNode);
  newNode->setValue(value);
  return 0;*/
//INSERTION WITHOUT RECURSION

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

//OLD MAIN FOR LINKED LIST
/*//Node node;
  int sCount = 0;
  int uCount = 0;
  Node * node = new Node();
  node->setValue(25);
  printf("SHOULD BE 25 (VALUE = %d)\n", node->getValue());
  if(node->getValue() == 25){
    ++sCount;
    printf("SUCCESSFUL\n");
  }else{
    ++uCount;
    printf("UNSUCCESSFUL\n");
  }
  printf("%f%% of tests passed\n", (((float)sCount/((float)sCount + (float)uCount))) * 100);
  return 0;*/
//OLD MAIN FOR LINKED LIST
 
