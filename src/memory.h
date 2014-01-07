#ifndef MEMORY_H
#define MEMORY_H

#include "configuration.h"
#include "registry.h"

class Memory{
  public:
    Memory();
    int stack [MEMSIZE];

    int load(Registry &registry);
    int store(Registry &registry);

    int branch(Registry &registry);
    int branchneg(Registry &registry);
    int branchzero(Registry &registry);

    void dump();
};

#endif