#ifndef ALU_H
#define ALU_H

#include "memory.h"

class ALU {
  public:
    ALU();
    int add(Memory &memory, Registry &registry);
    int subtract(Memory &memory, Registry &registry);
    int divide(Memory &memory, Registry &registry);
    int multiply(Memory &memory, Registry &registry);
};

#endif