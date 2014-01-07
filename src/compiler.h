#include "configuration.h"

class Compiler {
  public:
    void compile(int (&output)[MEMSIZE], std::string &filePath);
  private:
    void sterilize(std::string &word);
};