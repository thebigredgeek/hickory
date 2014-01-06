#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <iostream>
#include "operations.h"
#include "configuration.h"

class Processor {
  public:
    void load(int instructions [], int length);
    int exec();

  private:
    int accumulator;
    int memory [MEMSIZE];
    int pointer;

    int tick(int &opCode, int &operand);

    int read(int &operand);
    int write(int &operand);

    int load(int &operand);
    int store(int &operand);
    
    int add(int &operand);
    int subtract(int &operand);
    int divide(int &operand);
    int multiply(int &operand);

    int branch(int &operand);
    int branchneg(int &operand);
    int branchzero(int &operand);
    int halt(int &operand);
};

#endif