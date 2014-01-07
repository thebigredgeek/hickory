#include "configuration.h"

class Compiler {
  public:
    Compiler();
    void compile(int (&output)[MEMSIZE], std::string &filePath);
  private:
    void sterilize(std::string &word);
};