//Author: Craig Einstein
#ifndef FILEREADER_H
#define FILEREADER_H
#include "FileMeta.hpp"

typedef enum readOptions{
  FILE_READ
}readOptions;

class FileReader: public FileMeta{
 public:
  FileReader();
  FileReader(const char * _fileName);
  FileReader(readOptions _option);
  FileReader(const char * _fileName, readOptions _option);
  
  int readFromPos(char ** _buf, long _pos);
  
  //reads a line without changing file metadata
  int specificReadLine(char ** _buf, long _line);
  int printString(long _pos);
  int printSpecificLine(long _line);

  int readLine(char ** _buf);
  int printLine();
  
  int checkOption(char ** _optBuf, readOptions _option);
};

#endif
