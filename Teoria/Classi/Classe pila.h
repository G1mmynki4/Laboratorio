#include <iostream>
#include  <cmath>

using namespace std;

class Complesso {
private:
  //double Re;
  //double Im;
  double arg;
  double mod;

public:
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