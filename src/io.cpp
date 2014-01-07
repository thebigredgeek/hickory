#include "io.h"
#include "state.h"
#include "memory.h"
#include <iostream>

int IO::out(Memory &memory, int &operand){
  std::cout << "& " << memory.pointer << " >> " << operand << std::endl;
  return ST_CONT;
}
int IO::in(Memory &memory, int &operand){
  std::cout << "& " << memory.pointer << " << ";
  std::cin >> memory.stack[operand];
  return ST_CONT;
}