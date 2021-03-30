//Author: Craig Einstein
#ifndef FILEMETA_H
#define FILEMETA_H
#include <stdio.h> //for printf
#include <stdlib.h>
#include <string.h>

class FileMeta{
 protected:

  FILE * file;
  char * fileName;
  char * fileOption;     //the read or write option
  long currentPosition;  //current byte in file
  long currentLine;      //current line in file
  int fileOpen;          //does the object have a file open (1 = yes, 0 = no)

 public:

  int close();
  int open(char * _fileName);
  int reset();
  long numLines(); //number of lines in a file
  int lineLength(long _line); //length of a certain line

  long getLinePosition(long _line); //returns byte position of the start of a line in a file
  long getLineFromPosition(long _position); //find the line of a byte position is on

  //access to class data
  char * getFileName();
  char * getFileOption();
  long getCurrentPosition();
  long getCurrentLine();
  int hasFileOpen();
};

#endif
