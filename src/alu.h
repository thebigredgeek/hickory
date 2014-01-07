#ifndef ALU_H
#define ALU_H

#include "memory.h"

class ALU {
  public:
    int add(Memory &memory, int &operand, int &accumulator);
    int subtract(Memory &memory, int &operand, int &accumulator);
    int divide(Memory &memory, int &operand, int &accumulator);
    int multiply(Memory &memory, int &operand, int &accumulator);
};

#endif