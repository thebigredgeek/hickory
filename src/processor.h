#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "operations.h"
#include "configuration.h"
#include "memory.h"
#include "alu.h"
#include "io.h"
#include "registry.h"

class Processor {
  public:
    Processor();
    void load(int instructions [], int length);
    int exec();

  private:
    int accumulator;
    Memory memory;
    ALU alu;
    IO io;
    Registry registry;

    int tick();

    int halt();
};

#endif