//Author: Craig Einstein
#include "../inc/FileMeta.hpp"

int FileMeta::close(){
  try{
    fclose(this->file);
    this->file = 0;
    this->fileName = 0;
    this->currentPosition = -1;
    this->currentLine = -1;
    this->fileOpen = 0;
    return 0;
  }catch(...){
    printf("CLOSE FILE ERROR: There was an error closing the file!\n");
    return 1;
  }
}

int FileMeta::open(char * _fileName){
  this->reset();
  if(this->fileOpen){
    printf("Please close the file for this object before opening a new one!\n");
    return 1;
  }

  try{
    this->file = fopen(_fileName, this->fileOption);
    this->fileName = _fileName;
    this->currentPosition = 0;
    this->currentLine = 0;
    this->fileOpen = 1;
    return 0;
  }catch(...){
    printf("An error has occurred whilst trying to open the file!\n");
    if(this->fileOption[0] == 'r'){
      printf("The file is not readable!\n");
    }
  }
  return 1;
}

int FileMeta::reset(){
  fclose(this->file);
  free(fileName);
  currentPosition = -1;
  currentLine = 0;
  return 0;
}

long FileMeta::numLines(){
  long temp = ftell(this->file);
  //move to beginning of file
  fseek(this->file, 0, SEEK_SET);
  char c;
  long count = 0;
  do{
    c = fgetc(this->file);
    if(c == '\n' || c == '\r'){
      ++count;
    }
  }while(c != -1);
  fsetpos(this->file, (const fpos_t *)&temp);
  return count;
}

int FileMeta::lineLength(long _line){
  long linePos = getLinePosition(_line);
  if(linePos == -1){
    return -1;
  }
  long temp = ftell(this->file);
  //go to line position
  fseek(this->file, linePos, SEEK_SET);
  int count = 0;
  char c;
  //get size of line
  do{
    c = fgetc(this->file);
    if(c != EOF){
      ++count;
    }
  }while(c != EOF && c != '\0' && c != '\r' && c != '\n');
  //restore original position
  fseek(this->file, temp, SEEK_SET);
  return count;
}

//return -1 if line not in file
long FileMeta::getLinePosition(long _line){
  long temp = ftell(this->file);
  //move to beginning of file
  fseek(this->file, 0, SEEK_SET);
  char c;
  long count = 0;
  //count whilst cycling through file
  do{
    c = fgetc(this->file);
    if(c == '\n' || c == '\r'){
      ++count;
    }
  }while(c != -1 && count != _line); //position outside file
  if(c == -1){
    printf("ERROR: Line not in file!\n");
    return -1;
  }
  long ret = ftell(this->file);
  fsetpos(this->file, (const fpos_t *)&temp);
  return ret;
}

long FileMeta::getLineFromPosition(long _position){
  if(_position == 0){
    return 0;
  }
  long i;
  //cycle through lines until position is greater than _position
  for(i = 0; i < this->numLines(); ++i){
    if(getLinePosition(i) > _position){
      return i-1;
    }
  }
  printf("getLineFromPosition Error: That position is not in the file!\n");
  return -1;
}

long FileMeta::getCurrentPosition(){
  return this->currentPosition;
}

long FileMeta::getCurrentLine(){
  return this->currentLine;
}

int FileMeta::hasFileOpen(){
  return this->fileOpen;
}

char * FileMeta::getFileName(){
  return this->fileName;
}

char * FileMeta::getFileOption(){
  return this->fileOption;
}
