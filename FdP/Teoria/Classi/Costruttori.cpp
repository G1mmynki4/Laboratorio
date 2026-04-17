#include <iostream>
#include <cmath>
#include <cstring>

//To be completed
using namespace std;

const int DIM = 100;  //Lunghezza logica max.

class Complesso {
private:
  //double Re;
  //double Im;
  double arg;
  double mod;

public:
  //Complesso(double arg, double mod);//Costruttore "Funzione senza ritorno con lo stesso nome della classe
                                    //che viene invocata automaticamente dopo la dichiarazione di un nuovo membro"

  Complesso(double arg = 0, double mod = 0){}; //Costruttore default, può essere omesso durante la dichiarazione del membro.
  void init_Complex(double r, double i){ mod = sqrt(r*r + i*i); arg = atan2(i,r);};
  void scrivi_Complex(){cout<<mod*cos(arg)<<"+"<<"i"<<mod*sin(arg)<<endl;}
  double getReal(){return mod*cos(arg);};
  double getImag(){return mod*sin(arg);};

  Complesso& scala(double s) {
    mod *= s;
    return *this;
  }
};

Complesso somma(Complesso a, Complesso b) {
  Complesso C(0,0);
  C.init_Complex(a.getReal()+b.getReal(), a.getImag()+b.getImag());

  return C;
}

/////////////////////
///Classi stringa///
///////////////////

class stringa_lun_fissata {
  char str[DIM + 1];
public:

};

class stringa { //Stringhe a dimensione qualsiasi (dinamica).
  char* str;  //Puntatore allocato sullo stack.

public:
  stringa(){str = nullptr;};    //Costruttore default; mi permette di allocare senza inizializzare: rende possibile scrivere stringa.s1;
  stringa(const char cstr[]) {  //Costruttore, alloca lo spazio in dinamica e copia l'input nel vettore allocato sull'heap.
    str = new char[strlen(cstr+1)];
    strcpy(str, cstr);
  }

  ~stringa() {  //Distruttore
    delete[] str;
  }

  void scrivi() {
    cout<<str<<endl;
  }

};



int main() {
  Complesso c1(90.0, 10.0);  //Incluso di costruttore, equivale a c1.Complesso(1.0, -1.0)
                                     //Non si può dichiarare un membro senza utilizzare il costr. (a meno che non sia un costr. default).
  c1.init_Complex(1, 2);
  c1.scrivi_Complex();

  Complesso c2; //Costruttore inizializzato di default a (0, 0);
  Complesso c3 = 3.0; //Equivale a c3(3.0, 0) ma è un metodo sconsigliato.


  //COSTRUTTORE DI COPIA
  /*
   *Particolare costruttore che ha UN SOLO ARGOMENTO,
   *avente lo stesso tipo della classe.
   *Viene invocato ogni volta che si intende inizializzare un nuovo membro.
  */
  Complesso c4(c1);
  c4.scrivi_Complex();


  //Classe stringa
  {
    stringa s1("Ciao");
    s1.scrivi();

    //Deallocazione di s1.str "Ciao", il distr. viene invocato automaticamente all'uscita da un blocco.
    //s1.~stringa();  //Sintassi non standard, non si può invocare il distr. arbitrariamente.

    stringa s2("Fondamenti");
    s2.scrivi();

    stringa * ps1 = new stringa;  //la sintassi senza definizione è resa possibile dal costruttore default
    delete ps1;   //Prima di deallocare il ptr, viene automaticamente invocato il distr per deallocare lo spazio occupato
                  //Sull'heap dalla new.
  }

  //s2.scrivi();  //Errore, s2 è stato deallocato alla fine del blocco e con lui anche lo spazio occupato sull'heap tramite il distr.

  return 0;
}