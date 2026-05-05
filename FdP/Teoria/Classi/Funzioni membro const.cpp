#include <iostream>

using namespace std;

class complesso {

  double re;
  double im;

public:
  complesso( double r, double i )  : re(r), im(i) { } //Lista di inizializzazione
  ~complesso(){ }

  void scrivi_1(){ re*= 5;};
  double reale(){return re;}

  //Funzioni membro costanti
  double cReale()const{return re;}
  void scrivi()const {
    cout<<"("<<re<<","<<im<<")"<<endl;
  };

  /**
     Nota: Scrivere "const" prima della funzione "const void fun()" permette alla funzione di ritornare un VALORE COSTANTE, ma signigica che la fun sia costante
     Per rendere una funzione costante bisogna mettere la keyword "const" DOPO LA DICHIARAZIONE, (prima della definizione)
     Es. void scrivi()const{...}
  **/

};


int main() {
  const complesso c1(-3.4, 4.5);
  c1.scrivi_1();  //(-3.4, 4.5) //Impedisce la comp. perchè all'interno di stampa() io potrei star modificando i valori di "c1" che è const.
  c1.reale(); //La funzione non è const, quindi non può essere invocata su membri const.
  c1.cReale();
  c1.scrivi();


  complesso c2(5.6, 9.4);

  c2.scrivi_1();  //
  c1.scrivi_1();  //Impedisce la comp. perchè all'interno di stampa() io potrei star modificando i valori di "c1" che è const.
}