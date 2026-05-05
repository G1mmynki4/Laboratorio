#include <iostream>
#include <cstring>

using namespace std;

const double pi_greco = 3.14;

class complesso {

  //static const double pi_greco = 3.14;

  const double re;
  double& im;

public:
  complesso( double r = 0, double i = 0 )  : re(r), im(i) { } //Lista di inizializzazione
  /**Cosa succede nel costruttore:
   {
      const double re = r;
      double& im = i;
   }
*/

};


class stringa {
  char* str;
  stringa& operator=(const stringa&);

public:
  stringa(const char s[]);
};

class record {
  stringa nome;
  stringa cognome;
  int eta;

public:
  record(const char n[], const char c[], int e = 19) : nome(n),  cognome(c) { eta = e;}
  /*Comportamento implicito del costruttore
  {
    (*this).nome.stringa(n);
    (*this).cognome.stringa(n);
    eta = e;
  }
  */
};


int main() {
  complesso c1(-3.5, 5);  //(-3.5, xxx)
  complesso c2(8.3, 15);  //(8.3, xxx)

  double d3 = 3.5;
  double d4 = -5.6;

  complesso c3(-11.1, d3);  //(-11.1, 3.5);
  d3 = -4.5;
  //cout<<c3<<endl; //(-11.1, -4.5);

  {
    record r1("Mario", "Rossi");
    record r2("Luigi", "Bianchi");
    record r3("Ab", "Cd", 20);
  }

  return 0;
}