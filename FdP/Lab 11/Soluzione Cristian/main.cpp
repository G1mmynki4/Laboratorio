#include <iostream>

#include "Palazzo.h"
using namespace std;
int main() {
  // PRIMA PARTE:
  cout << "Test del costruttore:" << endl;
  Palazzo p1(5);
  cout << p1 << endl;
  cout << "Test del costruttore di copia:" << endl;
  Palazzo p2(p1);
  cout << p2 << endl;
  cout << "Test della aggiungi:" << endl;
  p1.aggiungi();
  p1.aggiungi();
  cout << p1 << endl;

  // SECONDA PARTE:
  cout << "Test del distruttore:" << endl;
  {
    Palazzo p(20);
  }
  cout << "(p e' stato distrutto)" << endl;

  cout << endl << "Test della cambia:" << endl;
  p1.cambia(2, 1);
  p1.cambia(3, 3);
  cout << p1 << endl;
  cout << "Test operator! :" << endl;
  cout << !p1 << endl;
  cout << endl << "Test operator%= :" << endl;
  Palazzo p3(5);
  p3.aggiungi();
  p3.aggiungi();
  p1 %= p3;
  cout << p1 << endl;
  return 0;
}