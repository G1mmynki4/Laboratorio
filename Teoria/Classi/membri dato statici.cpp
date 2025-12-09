#include <iostream>
#include <cstring>

using namespace std;

class complesso {

  static int quante; //Membro dati associato ALLA CLASSE e non alle singole istanze;

  const double re;
  double& im;

public:
  complesso( double r = 0, double i = 0 )  : re(r), im(i) { ++quante; } //Lista di inizializzazione
  ~complesso(){quante = quante - 1;}

  static int stampa_quante(){return quante;} //La keyword "static" all'inizio della dichiarazione di funzione membro
                                             //la obbliga a lavorare solo su elementi statici.

  //Le funzioni membro statiche NON HANNO PUNTATORE THIS, perchè può accedere solo a elementi statici
  //e non a funzioni membro, in quanto non agiscono sui membri classe.

};

//Complesso.cpp
int complesso::quante = 0;  //Definire e iniziaizzare un membro dati statico
                            //Va fatto AL DI FUORI DELLA DICHIARAZIONE




int main() {
  complesso c1(-3.5, 5);  //(-3.5, xxx)

  //cout<<c1.stampa_quante()<<endl; //1
  cout<<complesso::stampa_quante()<<endl; //1

  {
    complesso c2(8.3, 15);
    //cout<<c2.stampa_quante()<<endl; //2;
    cout<<complesso::stampa_quante()<<endl; //2
  }
  //cout<<c1.stampa_quante()<<endl; //1
  cout<<complesso::stampa_quante()<<endl; //1

  return 0;
}