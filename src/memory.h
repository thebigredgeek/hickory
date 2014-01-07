#ifndef MEMORY_H
#define MEMORY_H

#include "configuration.h"
class Memory{
  public:
    int stack [MEMSIZE];
    int pointer;

    int load(int &operand, int &accumulator);
    int store(int &operand, int &accumulator);

    int branch(int &operand);
    int branchneg(int &operand, int &accumulator);
    int branchzero(int &operand, int &accumulator);
};

#endif