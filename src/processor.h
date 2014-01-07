#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "operations.h"
#include "configuration.h"
#include "memory.h"
#include "alu.h"
#include "io.h"

class Processor {
  public:
    void load(int instructions [], int length);
    int exec();

  private:
    int accumulator;
    Memory memory;
    ALU alu;
    IO io;

    int tick(int &opCode, int &operand);

    int halt(int &operand);
};

#endif