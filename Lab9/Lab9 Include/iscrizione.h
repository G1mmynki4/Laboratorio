#pragma once

struct iscritti {
  char name[31];
  int pettorale;
  iscritti* next;
};

void init(iscritti* &);
bool aggiungi(iscritti* &, const char*, const int);
void visualizza(iscritti*);