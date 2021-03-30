//Author: Craig Einstein
#include "../inc/FileReader.hpp"
#include <string.h>
#include <vector>

//constructors
FileReader::FileReader(){
  this->file = 0;
  this->fileName = 0;
  this->fileOption = 0;
  this->currentPosition = -1;
  this->currentLine = -1;
  this->fileOpen = 0;
}

FileReader::FileReader(const char * _fileName){
  try{
    this->file = fopen(_fileName, "r");
  }catch(...){
    printf("This file does not exist!\nInitializing empty object instead");
  this->file = 0;
  this->fileName = 0;
  this->currentPosition = -1;
  this->currentLine = -1;
  this->fileOpen = 0;
  return;
  }

  this->fileName = (char *)_fileName;
  this->fileOption = (char *)"r";
  this->currentPosition = 0;
  this->currentLine = 0;
  this->fileOpen = 1;
}

FileReader::FileReader(readOptions _option){
  char * option;
  this->checkOption(&option, _option);
  this->file = 0;
  this->fileName = 0;
  this->fileOption = option;
  this->currentPosition = -1;
  this->currentLine = -1;
  this->fileOpen = 0;
}

FileReader::FileReader(const char * _fileName, readOptions _option){
  char * option;
  option = (char *)malloc(sizeof(char) * 1);
  switch(_option){
  case FILE_READ:
    option = (char *)"r";
    break;
  default:
    printf("ERROR: Incorrect read option, defaulting to 'r'\n");
    option = (char *)"r";
  }
  this->file = fopen(_fileName, option);
  this->fileOption = option;
  this->fileName = (char *)_fileName;
  this->currentPosition = 0;
  this->currentLine = 0;
  this->fileOpen = 1;
}

//read string starting from pos into buf wihtout updating metadata
int FileReader::readFromPos(char ** _buf, long _pos){

  long temp = this->currentPosition;
  
  if(fseek(this->file, _pos, SEEK_SET) < 0){
    printf("ERROR: This position is not in the file!\n");
    return 1;
  }

  std::vector<char> strArr;
  //read characters from line and put them into vector
  char c = fgetc(this->file);
  while(c != '\0' && c != EOF){
    strArr.push_back(c);
    if(c == '\n' || c == '\r'){
      ++this->currentLine;
      break;
    }
    c = fgetc(this->file);
  }
  
  if(c == EOF){
    return EOF;
  }

  unsigned long s = strArr.size();
  this->currentPosition += (long)s; //update current position
  *_buf = (char *)malloc(sizeof(char) * (s + 1));

  int i;
  for(i = 0; i < strArr.size(); ++i){
    *(*_buf + i) = strArr[i];
  }
  *(*_buf + i) = '\0';

  //clears the vector
  strArr.clear();
  return 0;
}

//reads a specific line in a file
int FileReader::specificReadLine(char ** _buf, long _line){
  if(_line < 0){
    printf("Please choose a non-negative value!\n");
    return 1;
  }
  //to return to original position
  long tempPos = this->currentPosition;
  long curLine = this->currentLine;

  long linePos = this->getLinePosition(_line);
  if(linePos == -1){
    return 1;
  }
  fseek(this->file, linePos, SEEK_SET);
  //read string at line
  long ret = this->readLine(_buf);

  //restore original values
  this->currentLine = curLine;
  this->currentPosition = tempPos;

  return ret;
}

int FileReader::readLine(char ** _buf){
  return this->readFromPos(_buf, ftell(this->file));
}

int FileReader::printLine(){
  char * buf;
  if(this->readLine(&buf) != EOF){
    printf("%s", buf);
    free(buf);
    return 0;
  }

  return EOF;
}

int FileReader::printString(long _pos){
  char * buf;
  if(!this->readFromPos(&buf, _pos)){
    printf("%s", buf);
    free(buf);
  }
  return 0;
}

int FileReader::printSpecificLine(long _line){
  char * buf;
  if(!this->specificReadLine(&buf, _line)){
    printf("%s", buf);
    free(buf);
  }
  return 0;
}

int FileReader::checkOption(char ** _optBuf, readOptions _option){
  *_optBuf = (char *)malloc(sizeof(char) * 2);
  switch(_option){
  case FILE_READ:
    *_optBuf = (char *)"r";
    break;
  default:
    printf("ERROR: Incorrect read option, defaulting to 'r'\n");
    *_optBuf = (char *)"r";
  }
  return 0;
}
