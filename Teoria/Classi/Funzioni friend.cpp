#include <iostream>
#include <cmath>

using namespace std;

class VettCompl;  //Definizione incompleta. Permette la compilazione in riga 26.

class Complesso {
private:
  double Re;
  double Im;
  double arg;
  double mod;

public:
  Complesso(double arg = 0, double mod = 0){}; //Costruttore default, può essere omesso durante la dichiarazione del membro.

  void init_Complex(double r, double i){ mod = sqrt(r*r + i*i); arg = atan2(i,r); Re = r; Im = i;};
  void scrivi_Complex(){cout<<mod*cos(arg)<<"+"<<"i"<<mod*sin(arg)<<endl;}
  double getReal(){return mod*cos(arg);};
  double getImag(){return mod*sin(arg);};

  //Funzioni friend, funzione che può accedere direttamente in lettura e scrittura agli elementi privati di classe
  friend Complesso Somma(const Complesso& a, const Complesso& b);

  friend VettCompl;
  //friend VettCompl::moduloQuadro(); //Serve per rendere "friend" una specifica funzione della classe secondaria
                                      //In questo caso non compila perchè la classe second. è definita sotto quella primaria. (Ez fix: Scambia la definizione di classe)

};

class VettCompl {
  Complesso vett[10];
public:
  double moduloQuadro();
};


Complesso Somma(const Complesso& a, const Complesso& b) {
  Complesso s(a.Re + b.Re, a.Im + b.Im);  //La funz. può accedere DIRETTAMENTE agli elementi PRIVATI "Re" e "Im".
  return s;
}