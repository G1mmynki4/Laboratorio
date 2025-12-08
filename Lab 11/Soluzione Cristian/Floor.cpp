#include "Floor.h"

Floor::Floor(unsigned long N, Floor* next)
    : windows_number{N}, next{next}, windows{new bool[N]{}} {}

Floor::Floor(const Floor& other)
    : windows_number{other.windows_number},
      windows{new bool[other.windows_number]{}} {
  for (unsigned long i = 0; i < other.windows_number; i++) {
    windows[i] = other.windows[i];
  }
}

Floor::~Floor() { delete[] windows; }
