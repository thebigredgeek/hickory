#include "processor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

int main(int argc, char *argv[]){
  if(argc > 1){

    int instructions [100],
        counter = 0;

    std::string temp,
           path(argv[1]);

    std::ifstream fileStream;
    
    fileStream.open(path);

    Processor VM;

    if(fileStream.is_open()){

      while(!fileStream.eof()){
      
        getline(fileStream,temp);

        instructions[counter] = atoi(temp.c_str());

        counter ++;
      }

      VM.load(instructions, 10);
      VM.exec();
    }
  }
  return 0;
}