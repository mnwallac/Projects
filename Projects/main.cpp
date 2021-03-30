#include "Queue.h"

int main(){ 
  Queue * queue = new Queue();
  printf("%s\n", "BEGIN!");
  for(int i = 1; i <= 4; ++i){
    queue->enqueue(i);
  }
  printf("\n%s\n", "QUEUE: ");
  queue->printQueue();
  printf("Number of nodes:%d\n\n", queue->sizeQueue());
  queue->enqueue(69);
  queue->enqueue(609);
  queue->dequeue();
  //  printf("%d\n", queue->sizeQueue());
  queue->dequeue();
  queue->enqueue(11);
  queue->enqueue(22);
  queue->dequeue();
  printf("QUEUE:\n");
  queue->printQueue();
  printf("Number of nodes:%d\n\n", queue->sizeQueue());
  //queue->printQueue();
  return 0;
}

//OLD MAIN BUT NEWER FOR LINKED LIST
  /*LinkedList * linkedlist = new LinkedList();
  linkedlist->getHead()->setValue(69);
  int i;
  for(i = 1; i <= 4; ++i){
    linkedlist->insertionAtEnd(linkedlist->getHead(), i);
  }
  printf("\n%s\n", "Values of nodes: ");
  linkedlist->printList(linkedlist->getHead());
  printf("Number of nodes:%d\n\n", linkedlist->getSize(linkedlist->getHead()));
  linkedlist->insertion(linkedlist->getHead(), 11, 1);
  linkedlist->insertion(linkedlist->getHead(), 22, 3);
  //linkedlist->deletion(linkedlist->getHead(), 3);
  linkedlist->deletionAtEnd(linkedlist->getHead());
  linkedlist->deletionAtHead(linkedlist->getHead());
  
  printf("\n%s\n", "Values of nodes: ");
  linkedlist->printList(linkedlist->getHead());
  printf("Number of nodes:%d\n\n", linkedlist->getSize(linkedlist->getHead()));
  return 0;
}
//printf("%lu+%lu=\n", sizeof(int), sizeof(LinkedList::Node_t *));
//printf("%lu\n", sizeof(LinkedList::Node_t));*/
  
//OLD MAIN BUT NEWER FOR LINKED LIST
