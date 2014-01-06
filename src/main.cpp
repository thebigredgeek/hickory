#include "processor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main(int argc, char *argv[]){
  if(argc > 1){

    int instructions [100],
        counter = 0;

    std::string temp,
           path(argv[1]);

    std::ifstream fileStream;
    std::string::iterator end_pos;
    
    fileStream.open(path);

    Processor VM;

    if(fileStream.is_open()){

      while(!fileStream.eof()){
      
        getline(fileStream,temp);

        if(temp.find("#") != std::string::npos){ //parse out comments
          temp = temp.substr(0, temp.find("#")); 
        }
        
        end_pos = std::remove(temp.begin(), temp.end(), ' ');
        temp.erase(end_pos, temp.end());

        instructions[counter] = atoi(temp.c_str());

        counter ++;
      }

      VM.load(instructions, 10);
      VM.exec();
    }
  }
  return 0;
}