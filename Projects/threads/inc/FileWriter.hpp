//Author: Craig Einstein
#ifndef FILEWRITER_H
#define FILEWRITER_H
#include "FileMeta.hpp"

typedef enum writeOptions{
  FILE_WRITE,
  FILE_APPEND
}writeOptions;

class FileWriter: public FileMeta{
 public:

  FileWriter();
  FileWriter(const char * _fileName);
  FileWriter(writeOptions _option);
  FileWriter(const char * _fileName, writeOptions _option);
  
  int changeFileOption(writeOptions _option);
  int writeString(const char * _str);
  
  //will be implemented if needed
  int insertStringAtPos(const char * _str, long _pos);
  int insertStringAtLine(const char * _str, long _line);
  int deleteCharacterAtPos(long _pos);
  int deleteLine(long _line);

 private:
  //used to check that a valid opening option was used
  int checkOption(char ** _optBuf, writeOptions _option);
};

#endif
  
