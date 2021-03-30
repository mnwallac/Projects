#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <vector>
#include <unistd.h>
#include <fstream>
#include "../inc/Queue.hpp"
#include "../inc/FileReader.hpp"
#include "../inc/FileWriter.hpp"
#include "../inc/threads.hpp"

//struct for thread
typedef struct thread_info{
  int id;
  char * fileName;
  Queue<char *> * queue;
}thread_info;

//global variables
int countthread = 0;
pthread_mutex_t lock1;
pthread_mutex_t lock2;
int receiving = 1;

std::vector<Queue<char *> *> * queues;

//functionality writes text file's lines to queue
void * readerThreads(void * args){
  thread_info * info1 = (thread_info *)args;
  FileReader * file = new FileReader(info1->fileName, FILE_READ);
  
  int countqueue = 0;
  while(countqueue++ < file->numLines()){
    char * buf; //pushing lines to queue, aka enqueue

    file->readLine(&buf);
    pthread_mutex_lock(&lock1);
    info1->queue->enqueue(buf);
    pthread_mutex_unlock(&lock1);
  }

  file->close();
  pthread_mutex_lock(&lock1);
  ++countthread; //indicates thread has been completed
  pthread_mutex_unlock(&lock1);
  return 0;
}

//functionality writes queue's lines to outfiles
void * writerThreads(void * args){
  thread_info * info2 = (thread_info *)args;
  FileWriter * fileout = new FileWriter(info2->fileName, FILE_WRITE);
  do{
    while(info2->queue->sizeQueue() < 1){}
    char * buf;
    buf = (char *)malloc(sizeof(char) * 20);
    pthread_mutex_lock(&lock2);
    strcpy(buf, (char *)info2->queue->front());
    info2->queue->dequeue();
    pthread_mutex_unlock(&lock2);
    fileout->writeString(buf);
    }while(receiving || info2->queue->sizeQueue());

  fileout->close();
  pthread_mutex_lock(&lock2);
  ++countthread;
  pthread_mutex_unlock(&lock2);
  return 0;
}

//function writes text file's lines to queue
int launchReaders(){
  
  //char * textArr[] = {(char *)"test.txt", (char *)"dude.txt", (char *)"input.txt"};
  printf("Launching %d threads.\n", numthreads);
  pthread_t * threads;
  threads = (pthread_t *)malloc(sizeof(pthread_t) * numthreads);
  
  //for loop to push queues into vector
  int i;  
  for(i = 0; i < numthreads; ++i){
    thread_info * info1;
    info1 = (thread_info *)malloc(sizeof(thread_info) * 1);
    info1->id = i;
    info1->fileName = (char *)malloc(sizeof(char) * strlen(*(inFiles + i)));
    unsigned long j;
    for(j = 0; j < strlen(*(inFiles + i)); ++j){
      *(info1->fileName + j) = *(*(inFiles + i) + j);
      //info1->fileName[j] = textArr[i][j];
    }
    *(info1->fileName + j) = '\0';
    //info1->fileName[j] = '\0';
    info1->queue = queues->at(i);
    printf("(%d) %s\n", i, info1->fileName);
    pthread_create((threads + i), NULL, &readerThreads, (void *)info1);
  }
  return 0;
}

//function writes queue's lines to outfiles
int launchWriters(){
  printf("Launching %d new threads.\n", numthreads);
  pthread_t * threads;
  threads = (pthread_t *)malloc(sizeof(pthread_t) * numthreads);
  //char * textArr[] = {(char *)"outFiles/out1.txt", (char *)"outFiles/out2.txt", (char *)"outFiles/out3.txt", (char *)"outFiles/out4.txt"};
  
  //for loop to push queues into vector
  int i;   
  for(i = 0; i < numthreads; ++i){
    thread_info * info2;
    info2 = (thread_info *)malloc(sizeof(thread_info) * 1);
    info2->id = i;
    info2->fileName = (char *)malloc(sizeof(char) * strlen(outFiles[i]));
    unsigned long j;
    for(j = 0; j < strlen(*(outFiles + i)); ++j){
      *(info2->fileName + j) = *(*(outFiles + i) + j);
      //info2->fileName[j] = textArr[i][j];
    }
    *(info2->fileName + j) = '\0';
    //info2->fileName[j] = '\0';
    info2->queue = queues->at(i);
    printf("%s\n", info2->fileName);
    pthread_create((threads + i), NULL, &writerThreads, (void *)info2);
  }
  return 0;
}

int numFiles(char * fileNames){
  if(*(fileNames) == '\0'){
    return 0;
  }
  int i = 0;
  int count = 0;
  while(*(fileNames + i) != '\0'){
    if(*(fileNames + i) ==  ','){
      if(*(fileNames + (i + 1)) == '\0'){
	break;
      }
      if(!i){
	++i;
	continue;
      }
      if(*(fileNames + (i - 1)) == ','){
	++i;
	continue;
      }
      ++count;
    }
    ++i;
  }
  if(*(fileNames + (i - 1)) != ','){
    ++count;
  }
  return count;
}

int itoa(int val, char * str, int base){
  int i = 0;
  if(val == 0){
    *(str) = 48;
    *(str + 1) = '\0';
    return 0;
  }
  while(val != 0){
    *(str + i++) = (val % base) + 48;
    val /= base;
  }
  int j = 0;
  while(j < i/2){
    SWAP(*(str + j), *(str + (i - j - 1)));
    ++j;
  }
  *(str + i) = '\0';
  return 0;
}

int init(char * _configFile){
  FileReader * fR = new FileReader(_configFile, FILE_READ);
  int count = 0;
  char * fNamesStr;
  while(count < fR->numLines()){
    switch(count){
    case 0:
      fR->readLine(&fNamesStr);
      *(fNamesStr + strlen(fNamesStr) - 1) = '\0';
      numthreads = numFiles(fNamesStr);
      break;
    default:
      printf("%s\n", "Line not implemented!");
    }
    ++count;
  }
  //printf("%d\n", numthreads);
  printf("\nFiles successfully found:\n%s\n", fNamesStr);
  inFiles = (char **)malloc(sizeof(char *) * numthreads);
  outFiles = (char **)malloc(sizeof(char *) * numthreads);
  char * token = strtok(fNamesStr, ",");
  int i = 0;
  printf("\n");
  do{
    //for inFiles
    *(inFiles + i) = (char *)malloc(sizeof(char) * strlen(token));
    printf("INFILE: %s\n", token);
    strcpy(*(inFiles + i), token);
    token = strtok(NULL, ",");

    //for outFiles
    char * buf = (char *)malloc(sizeof(char) * 8);
    itoa(i, buf, 10);
    *(outFiles + i) = (char *)malloc(sizeof(char) * (strlen(buf) + 20));
    strcpy(*(outFiles + i), (char *)"outFiles/out_");
    //strcat(*(outFiles + i), (char *)"out_");
    strcat(*(outFiles + i), buf);
    strcat(*(outFiles + i), (char *)".txt");
    printf("OUTFILE: %s\n", *(outFiles + i));
    ++i;
  }while(token != NULL);
  return 0;
}

int main(int argc, char ** argv){
  
  std::cout << "\nBeginning application..." << std::endl;
  
  if(argc < 2){
    printf("Missing required argument(s)... (.txt or #)\n");
    return 1;
  }

  init(argv[1]);
  numthreads = atoi(argv[2]);
  
  system("mkdir outFiles");
  queues = new std::vector<Queue<char *> *>();
  int i;
  for(i = 0; i < numthreads; ++i){
    queues->push_back(new Queue<char *>());
  }
  
  //functionality
  printf("\n");
  launchReaders();
  printf("\n");
  launchWriters();
  printf("\n");

  //semaphor
  if(countthread < (numthreads * 2)){
    receiving = 0;
  }
  
  pthread_exit(NULL);
  return 0;
}

