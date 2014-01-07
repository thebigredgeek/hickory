#include "memory.h"
#include "configuration.h"
#include "state.h"
#include "registry.h"
#include <iostream>
#include <iomanip>

Memory::Memory(){
  int i;

  for(i = 0; i < MEMSIZE; i++){
    stack[i] = 0;
  }
}

int Memory::load(Registry &registry){
  registry.accumulator = stack[registry.operand];
  return ST_CONT;
}
int Memory::store(Registry &registry){
  stack[registry.operand] = registry.accumulator;
  return ST_CONT;
}
int Memory::branch(Registry &registry){
  registry.instructionRegisterAddress = registry.operand;
  return ST_PNTR;
}
int Memory::branchneg(Registry &registry){
  if(registry.accumulator < 0){
    registry.instructionRegisterAddress = registry.operand;
    return ST_PNTR;
  }
  return ST_CONT;
}
int Memory::branchzero(Registry &registry){
  if(registry.accumulator == 0){
    registry.instructionRegisterAddress = registry.operand;
    return ST_PNTR;
  }
  return ST_CONT;
}
void Memory::dump(){
  int x,
      y,
      temp = MEMSIZE,
      numDigits = 0;

  if (temp < 10) {
      numDigits = 1;
  }
  else{
    while (temp > 0) {
        temp /= 10;
        numDigits++;
    } 
  }

  std::cout << std::endl << "MEMORY:" << std::endl;

  std::cout << std::setfill(' ') << std::setw(numDigits - 1) << "    ";

  for(x = 0; x < 10; x++){
    std::cout << std::setfill(' ') << std::setw(5) << std::noshowpos << x << " ";
  }
  
  std::cout << std::endl;

  for(y = 0; y < MEMSIZE; y+=10){
    std::cout << std::setfill(' ') << std::setw(numDigits - 1) << std::noshowpos << y << " ";
    for(x = 0; x < 10; x++){
      std::cout  << " " << std::setfill('0') << std::setw(5) << std::internal << std::showpos << stack[y+x];
    }
    std::cout << std::endl;
  }
}