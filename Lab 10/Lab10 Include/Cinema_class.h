#pragma once


class Cinema {
  char nome[31];

  int posti;
  int ftot; //File totali

  bool* matr = nullptr; //Matrice che contiene file e posti
public:
  Cinema(int n, int p, char s[]);

  bool prenota(char l, int j);
  bool cancella(char l, int j);
  void stampa();
};