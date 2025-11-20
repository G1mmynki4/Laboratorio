#include <iostream>
#include "Lab9 Include/class_iscrizione.h"

using namespace std;


int main() {
  Iscrizione L;
  L.init();
  L.visualizza();
  L.aggiungi("mario.bianchi", 24);
  L.aggiungi("sergio.rossi", 6);
  L.aggiungi("sergio.rossi", 4); // gia' presente
  L.aggiungi("gianni.verdi", 32);
  L.aggiungi("luigi.neri", 6); // gia' presente
  L.visualizza();
  //cout << L.cerca("mario.bianchi") << endl;
  //L.elimina("mario.bianchi");
  //cout << L.cerca("mario.bianchi") << endl;
  //L.visualizza();
  return 0;
}