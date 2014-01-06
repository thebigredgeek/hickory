#include "processor.h"

void Processor::load(int mem [], int length){
  int i;
  if(length > MEMSIZE){
    throw "Instructions are beyond allowed size";
  }

  for(i=0; i<length; i++){
    memory[i] = mem[i];
  }
}

int Processor::exec(){
  int state,
      verb,
      noun;

  pointer = 0;
  accumulator = 0;
  
  while(pointer < MEMSIZE && state > 0){

    
    verb = memory[pointer] / 100;
    noun = memory[pointer] % 100;

    state = tick(verb, noun);
    
    pointer++;
  }

  return state;
}

int Processor::tick(int &verb, int &noun){
  int result = 1;

  switch(verb){
    
    case READ:
      result = read(noun);
      break;
    
    case WRITE:
      result = write(noun);
      break;
    



    case LOAD:
      result = load(noun);
      break;

    case STORE:
      result = store(noun);
      break;




    case ADD:
      result = add(noun);
      break;

    case SUBTRACT:
      result = subtract(noun);
      break;

    case DIVIDE:
      result = divide(noun);
      break;
    
    case MULTIPLY:
      result = multiply(noun);
      break;




    case BRANCH:
      result = branch(noun);
      break;

    case BRANCHNEG:
      result = branchneg(noun);
      break;

    case BRANCHZERO:
      result = branchzero(noun);
      break;

    case HALT:
      result = halt(noun);
      break;

    default:
      result = -1;

  }

  return result;
}

int Processor::read(int &noun){
  std::cout << "&" << noun << " << ";
  std::cin >> memory[noun];
  return 1;
}

int Processor::write(int &noun){
  std::cout << "&" << noun << " >> " << memory[noun] << std::endl;
  return 1;
}

int Processor::load(int &noun){
  accumulator = memory[noun];
  return 1;
}

int Processor::store(int &noun){
  memory[noun] = accumulator;
  return 1;
}

int Processor::add(int &noun){
  accumulator += memory[noun];
  return 1;
}

int Processor::subtract(int &noun){
  accumulator -= memory[noun];
  return 1;
}

int Processor::divide(int &noun){
  accumulator /= memory[noun];
  return 1;
}

int Processor::multiply(int &noun){
  accumulator *= memory[noun];
  return 1;
}


int Processor::branch(int &noun){
  pointer = noun;
  return 1;
}

int Processor::branchneg(int &noun){
  if(accumulator < 0){
    pointer = noun;
    return 2;
  }
  return 1;
}

int Processor::branchzero(int &noun){
  if(accumulator == 0){
    pointer = noun;
    return 2;
  }
  return 1;
}

int Processor::halt(int &noun){
  memory[noun] = accumulator;
  return 0;
}

