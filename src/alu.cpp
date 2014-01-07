#include "alu.h"
#include "state.h"

ALU::ALU(){}

int ALU::add(Memory &memory, Registry &registry){
  registry.accumulator += memory.stack[registry.operand];
  return ST_CONT;
}

int ALU::subtract(Memory &memory, Registry &registry){
  registry.accumulator -= memory.stack[registry.operand];
  return ST_CONT;
}

int ALU::divide(Memory &memory, Registry &registry){
  registry.accumulator /= memory.stack[registry.operand];
  return ST_CONT;
}

int ALU::multiply(Memory &memory, Registry &registry){
  registry.accumulator *= memory.stack[registry.operand];
  return ST_CONT;
}