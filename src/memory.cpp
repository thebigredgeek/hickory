#include "memory.h"
#include "state.h"

int Memory::load(int &operand, int &accumulator){
  accumulator = stack[operand];
  return ST_CONT;
}
int Memory::store(int &operand, int &accumulator){
  stack[operand] = accumulator;
  return ST_CONT;
}
int Memory::branch(int &operand){
  pointer = operand;
  return ST_PNTR;
}
int Memory::branchneg(int &operand, int &accumulator){
  if(accumulator < 0){
    pointer = operand;
    return ST_PNTR;
  }
  return ST_CONT;
}
int Memory::branchzero(int &operand, int &accumulator){
  if(accumulator == 0){
    pointer = operand;
    return ST_PNTR;
  }
  return ST_CONT;
}