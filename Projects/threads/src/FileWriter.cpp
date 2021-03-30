//Author: Craig Einstein
#include "../inc/FileWriter.hpp"

//constructors
FileWriter::FileWriter(){
  this->file = 0;
  this->fileName = 0;
  this->fileOption = 0;
  this->currentPosition = -1;
  this->currentLine = -1;
  this->fileOpen = 0;
}

FileWriter::FileWriter(const char * _fileName){
  this->file = fopen(_fileName, "w");
  this->fileName = (char *)_fileName;
  this->fileOption = (char *)"w";
  this->currentPosition = 0;
  this->currentLine = 0;
  this->fileOpen = 1;
}

FileWriter::FileWriter(writeOptions _option){
  char * option;
  this->checkOption(&option, _option);
  this->file = 0;
  this->fileName = 0;
  this->fileOption = option;
  this->currentPosition = -1;
  this->currentLine = -1;
  this->fileOpen = 0;
}

FileWriter::FileWriter(const char * _fileName, writeOptions _option){
  char * option;
  this->checkOption(&option, _option);
  this->file = fopen(_fileName, option);
  this->fileName = (char *)_fileName;
  this->fileOption = option;
  this->currentPosition = 0;
  this->currentLine = 0;
  this->fileOpen = 1;

}

int FileWriter::changeFileOption(writeOptions _option){
  char * option;
  this->checkOption(&option, _option);
  return 0;
}

int FileWriter::writeString(const char * _str){

  try{
    fputs(_str, this->file);
    fputs("\0", this->file);
  }catch(...){
    printf("Some error has occured!\n");
    return 1;
  }
  this->currentPosition += strlen(_str);
  return 0;
}

//will be implemented when needed
int FileWriter::insertStringAtPos(const char * _str, long _pos){
  return 0;
}

int FileWriter::insertStringAtLine(const char * _str, long _line){
  return 0;
}

int FileWriter::deleteCharacterAtPos(long _pos){
  return 0;
}

int FileWriter::deleteLine(long _line){
  return 0;
}

//assigns a file opening type
int FileWriter::checkOption(char ** _optBuf, writeOptions _option){
  *_optBuf = (char *)malloc(sizeof(char) * 2);
  switch(_option){
  case FILE_WRITE:
    *_optBuf = (char *)"w\0";
    break;
  case FILE_APPEND:
    *_optBuf = (char *)"a+";
    break;
  default:
    printf("ERROR: Incorrect write option, defaulting to 'w'\n");
  }

  return 0;
}
