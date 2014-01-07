#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "compiler.h"

void Compiler::compile(int (&output)[MEMSIZE], std::string &filepath){
  int counter = 0;

  std::string word;

  std::ifstream fileStream;

  fileStream.open(filepath);


  if(fileStream.is_open()){

      while(!fileStream.eof()){

        getline(fileStream,word);

        sterilize(word);

        output[counter] = atoi(word.c_str());

        counter ++;
      }
  
  }

}

void Compiler::sterilize(std::string &word){
  std::string::iterator end_pos;
  
  if(word.find("#") != std::string::npos){ //parse out comments
    word = word.substr(0, word.find("#")); 
  }
  

  end_pos = std::remove(word.begin(), word.end(), ' ');
  word.erase(end_pos, word.end());
}