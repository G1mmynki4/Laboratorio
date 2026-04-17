#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

//////////////////////////////////////
/// Classe N complessi            ///
////////////////////////////////////
class complesso {
  double re, im;
  //complesso(const complesso&);  //Mascheramento costruttore di copia
public:
  complesso(double r=0, double i=0){re = r; im=i;};

  double getRe(){ return re; };
  double getIm(){ return im; };
  void scrivi(){cout<<"("<<re<<","<<im<<")"<<endl;};

  //Override operatori
  friend complesso operator+(complesso a, char[]);
  operator double();
  operator int();
  operator bool();

};

complesso::operator double() { return re+im; };
complesso::operator int() { return static_cast<int>(re+im); };
complesso::operator bool() { return re != 0 && im != 0; };

/////////////////////////////////
///   Override di ostream    ///
///////////////////////////////



///Tramite questo override possiamo stampare il nostro complesso come se fosse un tipo predefinito;
ostream& operator<<(ostream& os, complesso z) { //os: output string: oggetto su cui opera la funzione, equivale al "cout";
  os<<'('<<z.getRe()<<','<<z.getIm()<<')';
  return os;
}

/////////////////////////////////
///   Override di istream    ///
///////////////////////////////
istream& operator>>(istream& is, complesso& z) {
  double re = 0, im = 0;
  char c = 0;

  is>>c;
  if (c != '(')is.clear(ios::failbit);
  else {
    is>>re>>c;

    if (c != ',')is.clear(ios::failbit);
    else {
      is>>im>>c;

      if (c != ')')is.clear(ios::failbit);
    }
  }

  z = complesso(re, im);

  return is;
}

int main() {

  complesso c1(3.2, 4);
  cout<<(double)c1<<endl;
  cout<<(int)c1<<endl;

  complesso c3;
  cin>>c3; //Inserisco da tastiera il complesso seguendo lo schema (re,im);

  cout<<c3;

  if (bool(c1)) {
    //...
  }

  /*//Sezione stringhe
  {
    stringa s4("Fondamenti");
    cout<<(bool)s4<<endl;

    if (bool(s4)) {
      cout<<"s4 ha lunghezza diversa da zero\n";
    }
  }
  */

  int n;
  int counter = 0;
  //-23 11 34 , 3.4 5.6

  while (cin>>n) {
    ++counter;
  }
  cout<<"La prima seq e' di "<<counter<<"numeri\n";

  //A questo punto il EOF bit è in posizione di fail poichè non riconosce la ",";
  //Per proseguire con il programma bisogna ripulire il cin;

  cin.clear(ios::eof()); //equivale a cin.clear()


  return 0;
}
