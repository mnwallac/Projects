#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.hpp"


template <class T> 
class LinkedList{
 public:
  LinkedList<T>(){
    this->head = new Node<T>();
  };

  ~LinkedList<T>(){
  };

  Node<T> * setHead(Node<T> * cNode){
    this->head = cNode;
    return 0;
  };

  Node<T> * getHead(){
    return this->head;
  };

  int insertionAtEnd(Node<T> * cNode, T value){
    if(cNode->getNextNode() == NULL){
      Node<T> * newNode = new Node<T>();
      cNode->setNextNode(newNode);
      cNode->getNextNode()->setValue(value);
      return 0;
    }
    return this->insertionAtEnd(cNode->getNextNode(), value);
  };

  int deletionAtEnd(Node<T> * cNode){
    if(cNode->getNextNode() == NULL){
      return 1;
    }
    if(cNode->getNextNode()->getNextNode() == NULL){
      delete cNode->getNextNode();
      cNode->setNextNode(NULL);
      return 0;
    }
    return this->deletionAtEnd(cNode->getNextNode());
  };

  int insertion(Node<T> * cNode, T value, T index){
    if(cNode->getNextNode() == NULL){
      Node<T> * newNode = new Node<T>();
      newNode->setNextNode(NULL);
      cNode->setNextNode(newNode);
      newNode->setValue(value);
      return 1;
    }
    if(index == 0){
      Node<T> * newNode = new Node<T>();
      newNode->setNextNode(cNode->getNextNode());
      cNode->setNextNode(newNode);
      newNode->setValue(value);
      return 0;
    }
    return this->insertion(cNode->getNextNode(), value, index-1);
  };

  int deletion(Node<T> * cNode, T index){
    if(cNode->getNextNode() == NULL){
      return 1;
    }
    if(index == 1){
      Node<T> * temp;
      temp = (cNode->getNextNode());
      cNode->setNextNode(cNode->getNextNode()->getNextNode());
      free(temp);
      return 0;
    }
    return this->deletion(cNode->getNextNode(), index-1);
  };
  
  int deletionAtHead(Node<T> * cNode){
    if(head == cNode){
      Node<T> * temp;
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
  };

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

  int printList(Node<T> * cNode){
    if(cNode == NULL){
      std::cout << "NULL" << std::endl;
      return 0;
    }
    std::cout << cNode->getValue() << "->";
    return printList(cNode->getNextNode());
  };

  int getSize(Node<T> * cNode){
    if(cNode == NULL){
      return 0;
    }
    return 1 + getSize(cNode->getNextNode());
  };

private:
  Node<T> * head;
};

#endif



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
