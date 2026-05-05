#pragma once

struct iscritti {
  char name[31];
  int pettorale;
  iscritti* next;
};

void init(iscritti* &);
bool aggiungi(iscritti* &, const char*, const int);
bool elimina(iscritti *&, const char *);
bool cerca(iscritti *, const char*);
void visualizza(iscritti*);