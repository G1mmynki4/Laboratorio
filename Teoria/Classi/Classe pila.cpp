#include  <iostream>
#include "pila.h"

using namespace std;

class ClPila {
private:
  int stack[DIM]; //Membri dato della classe
  int top;

public:
  void initP(){top = -1;};  //Membri funzione della classe
  void azzera();
  bool full(){ return top == (DIM-1);};
  bool empty(){ return top == -1;};
  bool push(int val) {
    if (full())
      return false;
    ++top;
    stack[top] = val;
  }
};

void iniP(){};

int main() {
  ClPila st;
  st.initP();
  st.push(3);

  iniP();   //Funzione globale iniP()

  ClPila st2; //Oggetto di tipo classe Pila. Istanza, variabile
  st2.initP();
  st2.push(2);

  //Problema N4: non posso stampare la struct pila usando una sintassi a me familiare
  //ossia quella che uso per i tipi predefiniti;

  return 0;
}