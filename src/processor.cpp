#include "processor.h"
#include "configuration.h"
#include "state.h"
#include "alu.h"
#include "io.h"

Processor::Processor(){
  accumulator = 0;
}

void Processor::load(int instructions [], int length){
  int i,
      j;
  if(length > MEMSIZE){
    throw "Instructions are beyond allowed size";
  }

  std::cout << "Hickory VM v" << VERSION << std::endl;
  std::cout << "Loading instruction set..." << std::endl;
  for(i=0; i<length; i++){
    memory.stack[i] = instructions[i];
  }
}

int Processor::exec(){
  int state;

  std::cout << "Starting execution..." << std::endl;

  registry.accumulator = 0;
  registry.instructionRegisterAddress = 0;


  std::cout << "Initial State > " << registry.instructionRegisterAddress << "  " << MEMSIZE << std::endl;
  
  while(registry.instructionRegisterAddress < MEMSIZE){

    registry.instructionRegisterValue = memory.stack[registry.instructionRegisterAddress]; //load into register

    registry.pick();

    state = tick(); //execute
    
    switch(state){
      case ST_HALT:
        return state;
        break;
      case ST_PNTR:
        break;
      case ST_CONT:
        registry.instructionRegisterAddress++;
        break;
      default:
        throw "Statement Fault!";
        break;
    }
  }

  return 0;
}

int Processor::tick(){

  switch(registry.operationCode){
    
    case READ:
      return io.in(memory, registry);
      break;
    
    case WRITE:
      return io.out(registry);
      break;
    



    case LOAD:
      return memory.load(registry);
      break;

    case STORE:
      return memory.store(registry);
      break;




    case ADD:
      return alu.add(memory,registry);
      break;

    case SUBTRACT:
      return alu.subtract(memory,registry);
      break;

    case DIVIDE:
      return alu.divide(memory,registry);
      break;
    
    case MULTIPLY:
      return alu.multiply(memory,registry);
      break;




    case BRANCH:
      return memory.branch(registry);
      break;

    case BRANCHNEG:
      return memory.branchneg(registry);
      break;

    case BRANCHZERO:
      return memory.branchzero(registry);
      break;

    case HALT:
      return halt();
      break;

    default:
      return -1;
  }
}

int Processor::halt(){
  if(registry.operand == 1){
    registry.dump();
    memory.dump(); 
  }

  return ST_HALT;
}

