#include  <iostream>
#include "Lab9 Include/iscrizione.h"
using namespace std;

//Da completare
int main() {
  iscritti* L;
  init(L);
  visualizza(L);
  aggiungi(L, "mario.bianchi", 24);
  aggiungi(L, "sergio.rossi", 6);
  aggiungi(L, "sergio.rossi", 4); // gia' presente
  aggiungi(L, "gianni.verdi", 32);
  aggiungi(L, "luigi.neri", 6); // gia' presente
  visualizza(L);
  return 0;
}