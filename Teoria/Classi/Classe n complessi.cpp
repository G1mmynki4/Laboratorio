#include  <iostream>
#include  <cmath>
#include "Teoria/Classi/Classe pila.h"

using namespace std;

int main() {

  Complesso c1;
  c1.init_Complex(4, 5); //E' lo stesso che scrivere Complesso::init_Complex(&c1, -4, 5);
  c1.scrivi_Complex(); //(4+5i)
  cout<<c1.getReal()<<endl;
  cout<<c1.getImag()<<endl;

  c1.scala(2.0);  //(16, 20)
  c1.scrivi_Complex();

  Complesso& tmp = c1.scala(2.0);  //(32, 40)
  tmp.scala(2.0); //(32, 40)

  c1.scrivi_Complex();  //(64, 80)

  c1.scala(2.0).scala(2.0);


  /*
  Complesso* cptr = &c1;
  cptr->init_Complex(-6, 3);
  c1.scrivi_Complex();
  */

  return 0;
}