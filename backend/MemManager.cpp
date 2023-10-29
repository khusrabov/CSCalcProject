#include "MemManager.hpp"
#include <iostream>

MemManager::MemManager(): registers(8), circ_stack(7) {};

FNum& MemManager::RegAt(int index) { return registers[index]; }

FNum MemManager::StackAt(int index) { return circ_stack[index]; }

void MemManager::RotateLeft() {
  circ_stack[0] = registers[0];
  FNum temp = circ_stack[0];
  for (int i = 0; i < 6; ++i) {
    circ_stack[i] = circ_stack[i + 1];
  }
  circ_stack[6] = temp;
  registers[0] = circ_stack[0];
}

void MemManager::RotateRight() {
  circ_stack[0] = registers[0];
  FNum temp = circ_stack[6];
  for (int i = 6; i > 0; --i) {
    circ_stack[i] = circ_stack[i - 1];
  }
  circ_stack[0] = temp;
  registers[0] = circ_stack[0];
}

// Sets all registers and circ_buff elements to zero
void MemManager::ClearAll() {
  for (int i = 0; i < 8; ++i) {
    registers[i] = 0.0f;
  }
  for (int i = 0; i < 7; ++i) {
    circ_stack[i] = 0.0f;
  }
}

// Sets only x(0) register to zero
void MemManager::ClearX() {
  registers[0] = 0.0f;
}