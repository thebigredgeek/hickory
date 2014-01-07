#ifndef REGISTRY_H
#define REGISTRY_H

#include <string>
class Registry{
  public:
    Registry();
    void dump();
    void pick();
    int accumulator;
    int instructionRegisterAddress;
    int instructionRegisterValue;
    int operationCode;
    int operand;
};

#endif