#include "alu.h"
#include "state.h"

int ALU::add(Memory &memory, int &operand, int &accumulator){
  accumulator += memory.stack[operand];
  return ST_CONT;
}

int ALU::subtract(Memory &memory, int &operand, int &accumulator){
  accumulator -= memory.stack[operand];
  return ST_CONT;
}

int ALU::divide(Memory &memory, int &operand, int &accumulator){
  accumulator /= memory.stack[operand];
  return ST_CONT;
}

int ALU::multiply(Memory &memory, int &operand, int &accumulator){
  accumulator *= memory.stack[operand];
  return ST_CONT;
}