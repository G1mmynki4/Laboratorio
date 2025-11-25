#include <iostream>
#include <cmath>

//To be completed
using namespace std;

class Complex {
  double Re, Im;
public:
  Complex(double Re, double Im);  //Costruttore: "Funzione senza ritorno con lo stesso nome della classe
                                  //che viene invocata automaticamente dopo la dichiarazione di un nuovo membro"
};

class Complesso {
private:
  //double Re;
  //double Im;
  double arg;
  double mod;

public:
  Complesso(double arg, double mod);//Costruttore "Funzione senza ritorno con lo stesso nome della classe
                                    //che viene invocata automaticamente dopo la dichiarazione di un nuovo membro"
  void init_Complex(double r, double i){ mod = sqrt(r*r + i*i); arg = atan2(i,r);};
  void scrivi_Complex(){cout<<mod*cos(arg)<<"+"<<"i"<<mod*sin(arg)<<endl;}
  double getReal(){return mod*cos(arg);};
  double getImag(){return mod*sin(arg);};

  Complesso& scala(double s) {
    mod *= s;
    return *this;
  }
};

Complesso somma(const Complesso& a, const Complesso& b) {
  Complesso C;
  C.init_Complex(a.getReal()+b.getReal(), a.getImag()+b.getImag());

  return C;
}
int main() {

  return 0;
}