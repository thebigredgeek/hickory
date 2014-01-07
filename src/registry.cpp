#include "registry.h"
#include <iostream>
#include <iomanip>

Registry::Registry(){
  accumulator = 0;
  instructionRegisterAddress = 0;
  instructionRegisterValue = 0;
  operationCode = 0;
  operand = 0;
}

void Registry::pick(){
  operationCode = instructionRegisterValue / 100;
  operand = instructionRegisterValue % 100;
}
void Registry::dump(){
  std::cout << std::endl << "REGISTERS:" << std::endl;

  std::cout << "accumulator                   " << std::setfill('0') << std::setw(5) << std::internal << std::showpos << accumulator << std::endl;

  std::cout << "instructionRegisterAddress    " << "   " << std::setfill('0') << std::setw(2) << std::noshowpos << instructionRegisterAddress << std::endl;

  std::cout << "instructionRegisterValue      " << std::setfill('0') << std::setw(5) << std::internal << std::showpos << instructionRegisterValue << std::endl;

  std::cout << "operationCode                 " << "   " << std::setfill('0') << std::setw(2) << std::noshowpos << operationCode << std::endl;

  std::cout << "operand                       " << "   " << std::setfill('0') << std::setw(2) << std::noshowpos << operand << std::endl;
}