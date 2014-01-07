#include "processor.h"
#include "configuration.h"
#include "state.h"
#include "alu.h"
#include "io.h"

void Processor::load(int instructions [], int length){
  int i;
  if(length > MEMSIZE){
    throw "Instructions are beyond allowed size";
  }

  std::cout << "Hickory VM v" << VERSION << std::endl;
  std::cout << "Loading instruction set..." << std::endl;

  for(i=0; i<length; i++){
    std::cout << "ADDR " << i << "  ->  " << instructions[i] << std::endl;
    memory.stack[i] = instructions[i];
  }
}

int Processor::exec(){
  int state,
      opCode,
      operand,
      reg;

  accumulator = 0;
  
  while(memory.pointer < MEMSIZE){

    reg = memory.stack[memory.pointer]; //load into register

    opCode = reg / 100; //pick off operation code
    operand = reg % 100; //pick off operand

    state = tick(opCode, operand); //execute
    
    
    switch(state){
      case ST_HALT:
        return state;
        break;
      case ST_PNTR:
        break;
      case ST_CONT:
        memory.pointer++;
        break;
      default:
        throw "Statement Fault!";
        break;
    }
  }

  return 0;
}

int Processor::tick(int &opCode, int &operand){

  switch(opCode){
    
    case READ:
      return io.in(memory, operand);
      break;
    
    case WRITE:
      return io.out(memory, operand);
      break;
    



    case LOAD:
      return memory.load(operand, accumulator);
      break;

    case STORE:
      return memory.store(operand, accumulator);
      break;




    case ADD:
      return alu.add(memory,operand,accumulator);
      break;

    case SUBTRACT:
      return alu.subtract(memory,operand,accumulator);
      break;

    case DIVIDE:
      return alu.divide(memory,operand,accumulator);
      break;
    
    case MULTIPLY:
      return alu.multiply(memory,operand,accumulator);
      break;




    case BRANCH:
      return memory.branch(operand);
      break;

    case BRANCHNEG:
      return memory.branchneg(operand, accumulator);
      break;

    case BRANCHZERO:
      return memory.branchzero(operand, accumulator);
      break;

    case HALT:
      return halt(operand);
      break;

    default:
      return -1;
  }
}

int Processor::halt(int &operand){
  memory.stack[operand] = accumulator;
  return ST_HALT;
}

