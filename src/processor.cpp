#include "processor.h"
#include "configuration.h"
#include "state.h"
void Processor::load(int instructions [], int length){
  int i;
  if(length > MEMSIZE){
    throw "Instructions are beyond allowed size";
  }

  std::cout << "Hickory VM v" << VERSION << std::endl;
  std::cout << "Loading instruction set..." << std::endl;

  for(i=0; i<length; i++){
    std::cout << "ADDR " << i << "  ->  " << instructions[i] << std::endl;
    memory[i] = instructions[i];
  }
}

int Processor::exec(){
  int state,
      opCode,
      operand,
      reg;

  pointer = 0;
  accumulator = 0;
  
  while(pointer < MEMSIZE){

    reg = memory[pointer]; //load into register

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
        pointer++;
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
      return read(operand);
      break;
    
    case WRITE:
      return write(operand);
      break;
    



    case LOAD:
      return load(operand);
      break;

    case STORE:
      return store(operand);
      break;




    case ADD:
      return add(operand);
      break;

    case SUBTRACT:
      return subtract(operand);
      break;

    case DIVIDE:
      return divide(operand);
      break;
    
    case MULTIPLY:
      return multiply(operand);
      break;




    case BRANCH:
      return branch(operand);
      break;

    case BRANCHNEG:
      return branchneg(operand);
      break;

    case BRANCHZERO:
      return branchzero(operand);
      break;

    case HALT:
      return halt(operand);
      break;

    default:
      return -1;
  }
}

int Processor::read(int &operand){
  std::cout << "&" << operand << " << ";
  std::cin >> memory[operand];
  return ST_CONT;
}

int Processor::write(int &operand){
  std::cout << "&" << operand << " >> " << memory[operand] << std::endl;
  return ST_CONT;
}

int Processor::load(int &operand){
  accumulator = memory[operand];
  return ST_CONT;
}

int Processor::store(int &operand){
  memory[operand] = accumulator;
  return ST_CONT;
}

int Processor::add(int &operand){
  accumulator += memory[operand];
  return ST_CONT;
}

int Processor::subtract(int &operand){
  accumulator -= memory[operand];
  return ST_CONT;
}

int Processor::divide(int &operand){
  accumulator /= memory[operand];
  return ST_CONT;
}

int Processor::multiply(int &operand){
  accumulator *= memory[operand];
  return ST_CONT;
}


int Processor::branch(int &operand){
  pointer = operand;
  return ST_PNTR;
}

int Processor::branchneg(int &operand){
  if(accumulator < 0){
    pointer = operand;
    return ST_PNTR;
  }
  return ST_CONT;
}

int Processor::branchzero(int &operand){
  if(accumulator == 0){
    pointer = operand;
    return ST_PNTR;
  }
  return ST_CONT;
}

int Processor::halt(int &operand){
  memory[operand] = accumulator;
  return ST_HALT;
}

