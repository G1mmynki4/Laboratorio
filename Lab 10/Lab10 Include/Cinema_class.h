#pragma once

const int nDIM = 31;
class Cinema {
  char nome[nDIM];

  int posti;
  int ftot; //File totali

  bool* matr = nullptr; //Matrice che contiene file e posti
public:
  Cinema(int n, int p, char s[]);
  ~Cinema();

  bool prenota(char l, int j);
  bool cancella(char l, int j);
  void stampa();
};