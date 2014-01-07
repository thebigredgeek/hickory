#include "io.h"
#include "state.h"
#include "memory.h"
#include "registry.h"
#include <iostream>

IO::IO(){}

int IO::out(Registry &registry){
  std::cout << "& " << registry.instructionRegisterAddress << " >> " << registry.operand << std::endl;
  return ST_CONT;
}
int IO::in(Memory &memory, Registry &registry){
  std::cout << "& " << registry.instructionRegisterAddress << " << ";
  std::cin >> memory.stack[registry.operand];
  return ST_CONT;
}