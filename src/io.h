#ifndef IO_H
#define IO_H

#include "memory.h"
#include "registry.h"
#include <iostream>

class IO {
  public:
    IO();
    int out(Registry &registry);
    int in(Memory &memory, Registry &registry);
};

#endif