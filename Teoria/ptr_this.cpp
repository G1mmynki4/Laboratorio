#include <iostream>

using namespace std;

class ProvaThis{
private:
  int a;
  public:
  void init(int val) {
    a = val;
  }

  void Init(int a) {
    this->a = a;  //this->a distingue la "a" del campo privato dell'oggetto dal valore passato alla funzione

  }
  // void init(ProvaThis* const this, int val)
  ProvaThis& elevaRef() { a*= a; return *this; }
  ProvaThis eleva() { a *= a; return *this; }
  void stampa() {cout<<a<<endl;}
  void InitdefEsterna(int val);
};

void ProvaThis::InitdefEsterna(int val) { //::->"Operatore di risoluzione di visibilità"
  ProvaThis::a = val;
}


int main() {
  ProvaThis p1;
  p1.init(5); //init(&p1, 5); ->chiamata

  //->Dentro la "init" a=val; Di quale a sto parlando?
  //del valore a del membro "this": this->a = val, oppure (*this).a = val;

  //Funzione init() opera sull'oggetto p1, entra in gioco il puntatore "this"
  //Ovvero un ptr COSTANTE predefinito che contiene l'indirizzo dell'oggetto classe
  //su cui il metodo è stato invocato passato come primo argomento implicito ad una funzione membro

  /////////////////////////////////
  //Utilizzo esplicito di "this"//
  ///////////////////////////////

  //Necessario quando la funzione deve esplicitamente utilizzare l'indirizzo dell'oggetto su cui la funz. opera
  //Es. La funzione deve restituire l'oggetto stesso oppure una copia, (per riferimento, per valore)

  //1) ProvaThis& elevaRef(){
  //    a* = a;
  //    return *this; //Restituisco per riferimento
  //}

  //2) ProvaThis eleva(){
  //    a* = a;
  //    return *this; //Restituisco per valore (copia dell'oggetto)(manca la &)
  //}



  //1) Riferimento
  //p2 a = 4 //Dopo avere invocato una volta eleva(),
  //p2 a = 16 //Dopo avere invocato nuovamente eleva()
  //Invocando la stampa stampo il campo a di p2, cioè 16;

  ProvaThis p2;
  p2.init(2);
  p2.elevaRef().elevaRef();
  p2.stampa();



  //2) Per Valore (copia dell'oggetto su cui è stata invocata)
  //p3 a = 2 //->Invoco p2.eleva()-> p2 a = 4
  //tmp a = 4 (copia di p2 dopo averlo modificato) e sulla quale agisce la seconda invocazione di eleva() "tmp.eleva()"
  //tmp2 a = 16
  //Appena invoco stampa() su p2, essa stamperà "4";

  ProvaThis p3;
  p3.init(3);
  p3.eleva().eleva();
  p3.stampa();

  return 0;
}