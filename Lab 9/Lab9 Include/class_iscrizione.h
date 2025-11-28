#pragma once
#include <iostream>

struct iscritti {
  char name[31];
  int pettorale;
  iscritti* next;
};

class Iscrizione {
private:
  iscritti* list;
public:
  void init();
  bool aggiungi(const char*, const int);
  bool cerca(const char*);
  bool elimina(const char*);
  void visualizza();
};
