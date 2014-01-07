#include "processor.h"
#include "configuration.h"
#include "compiler.h"
#include <string>

int main(int argc, char *argv[]){
  if(argc > 1){

    int instructions [MEMSIZE];

    std::string path(argv[1]);

    Compiler compiler;
    Processor VM;

    compiler.compile(instructions, path);

    VM.load(instructions, 10);
    VM.exec();
    
  }
  return 0;
}