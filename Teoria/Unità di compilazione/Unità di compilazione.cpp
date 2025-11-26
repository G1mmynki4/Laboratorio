#include  <iostream>
//#include "pila.h"
#include "lib_vett.h"

using namespace std;

static int a;
extern int b; //Dichiaro una variabile senza definirla

//const double pi;       //Collegamento INTERNO, per condividerla si mette nell'header, variabile globale
                        // TUTTE le var. globali hanno classe di mem. "statica"

//int n; //0
int *p; //nullptr

void fun(){
  static int n = 0; //Variabile PERSISTENTE: static ha l'effetto di modificare la classe di
                    //memorizzazione di "n" da "automatica" a "statica" (Definita e inizializzata UNA SOLA VOLTA)
  ++n;
  cout << "La variabile e' stata chiamata: " << n << endl;//1, 2, 3->n incrementa ad ogni chiamata di funzione
}

int main() {
  cout<<pi<<endl; //Dichiarato in "lib_vett.h"

  /*pila st;
  initP(st); //Problema uno, non invocare subito questa funzione sarebbe un errore grave

  push(st, 13);
  st.top = -10; //Problema 2, l'utente può porre la pila in uno stato inconsistente ERRORE GRAVISSIMO

  azzera_pila(st); //Problema 3,
*/


  return 0;
}