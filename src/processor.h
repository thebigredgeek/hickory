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

    int tick(int &verb, int &noun);

    int read(int &noun);
    int write(int &noun);

    int load(int &noun);
    int store(int &noun);
    
    int add(int &noun);
    int subtract(int &noun);
    int divide(int &noun);
    int multiply(int &noun);

    int branch(int &noun);
    int branchneg(int &noun);
    int branchzero(int &noun);
    int halt(int &noun);
};

#endif