#ifndef STM_FLOOR_H
#define STM_FLOOR_H

struct Floor {
 public:
  unsigned long int windows_number = 1;
  bool* windows = nullptr;
  Floor* next = nullptr;

  Floor(unsigned long N, Floor* next);
  Floor(const Floor& other);
  ~Floor();

 private:
};

#endif  // STM_FLOOR_H
