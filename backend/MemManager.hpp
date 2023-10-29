#include "FNum.hpp"
#include <vector>

class MemManager {
 public:
  MemManager();

  FNum& RegAt(int index);

  FNum StackAt(int index);

  void RotateLeft();

  void RotateRight();

  void ClearAll();

  void ClearX();

 private:
  std::vector<FNum> registers;
  std::vector<FNum> circ_stack;
};