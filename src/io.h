#ifndef IO_H
#define IO_H

#include "memory.h"
#include <iostream>

class IO {
  public:
    int out(Memory &memory, int &operand);
    int in(Memory &memory, int &operand);
};

#endif