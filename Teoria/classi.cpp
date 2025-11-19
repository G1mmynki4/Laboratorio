#include  <iostream>
//#include "pila.h"

using namespace std;

const int DIM = 5;
class pila {
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

class Complesso {
private:
  double Re;
  double Im;

public:
  void init_Complex(double r, double i){ Re = r; Im = i;};
  void scrivi_Complex(){cout<<"("<<Re<<"+"<<Im<<"i"<<")"<<endl;}
  double getReal(){return Re;};
  double getImag(){return Im;};
};


void iniP(){};

int main() {
 /* pila st;
  st.initP();
  st.push(3);

  iniP();   //Funzione globale iniP()

  pila st2; //Oggetto di tipo classe Pila. Istanza, variabile
  st2.initP();
  st2.push(2);*/

  Complesso c1;
  c1.init_Complex(-4, 5); //E' lo stesso che scrivere Complesso::init_Complex(&c1, -4, 5);
  c1.scrivi_Complex();
  cout<<c1.getReal()<<endl;
  cout<<c1.getImag()<<endl;

  Complesso* cptr = &c1;
  cptr->init_Complex(-6, 3);
  c1.scrivi_Complex();


  //Problema N4: non posso stampare la struct pila usando una sintassi a me familiare
  //ossia quella che uso per i tipi predefiniti;

  return 0;
}