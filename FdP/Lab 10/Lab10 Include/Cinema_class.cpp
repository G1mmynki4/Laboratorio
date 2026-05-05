#include "Cinema_class.h"
#include <iostream>
#include <cstring>

using namespace std;
char c = 'A';

//Definizione Costruttore
Cinema::Cinema(int n, int p, char s[]) {

  if(strlen(s) < nDIM-1)
    strcpy(nome, s);
  else{
    cerr << "Il nome del cinema supera il numero massimo di caratteri consentito\n";
    strcpy(nome, "\0");
  }

  //Assegno i posti per fila
  if(p <= 9)
    posti = p;
  else{
    cerr << "\nIl numero di posti massimi per fila consentito e' 9\n";
    posti = 9;
  }

  //Assegno le file totali
  if(n <= 26)
    ftot = n;
  else{
    cerr << "\nIl numero massimo di file e' 26\n";
    ftot = 26;
  }

  //Creo una matrice lineare booleana che contiene file e posti
  matr = new bool[ftot*posti];

  for (int i=0; i<posti*ftot;++i)
    matr[i] = 0;


}

//Definizione distruttore
Cinema::~Cinema(){

  delete[] matr;
}

bool Cinema::prenota(char l, int j) {
  int fila = l-'A';

  //Error handling
  if(fila>ftot-1){
    cerr << "Impossibile prenotare in una fila inesistente\n";
    return false;
  }
  if(j < 0)
    j = -j;
  if(j>posti){
    cerr << "Impossibile prenotare un posto inesistente \n";
    return false;
  }

  //Prenotazione posti
  if (!matr[posti*fila + (j-1)]) {
    matr[posti*fila + (j-1)] = 1;
    //DEBUG TEXTcout<<"Prenotato posto"<<posti*fila + (j)<<endl;
    return true;
  }
  return false;
 }


bool Cinema::cancella(char l, int j) {
  int fila = l-'A';

  //Error handling
  if(fila>ftot-1){
    cerr << "Impossibile cancellare in una fila inesistente\n";
    return false;
  }

  if(j < 0)
    j = -j;

  if(j>posti){
    cerr << "Impossibile cancellare un posto inesistente \n";
    return false;
  }

  //Cancellazione posti
  if (matr[posti*fila + (j-1)]) {
    matr[posti*fila + (j-1)] = 0;
    //DEBUG TEXT cout<<"Cancellato posto"<<posti*fila + (j-1)<<endl;
    return true;
  }
  return false;
 }

void Cinema::stampa() {

  if(strlen(nome) == 0)
    cout<<"\nNome del cinema: ERROR"<<nome<<endl;
  else
    cout<<"\nNome del cinema: "<<nome<<endl;
  cout<<" ";

  //Print del numero di posti per fila
  for (int i = 0; i<posti; ++i)
    cout<<i+1;

  cout<<"\n";

  //Print della lettera della fila e dei posti occupati
  for (int fila = 0; fila < ftot; ++fila){
    cout << static_cast<char>(c + fila);

    for (int i = 0; i < this->posti; ++i){
       if(matr[fila*posti + i]!=0)
         cout << "*"; // fila*posti + i<<"*";
       else
         cout << " "; // fila*posti + i<<" ";
    }
    cout << endl;
  }
    cout << endl;
 }


//Inizio  seconda parte
int Cinema::quantiLiberi(){
  int out = 0;

  for (int i = 0; i < posti * ftot; ++i)
    if(!matr[i])
      ++out;
      
  return out;
}

bool Cinema::prenotaAdiacenti(int k){
  int adiac = 0, kfila; //kfila è la variabile che conterrà il valore della fila con sufficienti posti adiac. disp.

  for (int fila = 0; adiac < k && fila < ftot; ++fila){
    //Inizializzo adiac a zero ogni volta che passo ad una nuova fila
    adiac = 0;
    //Salvo il valore della fila corrente in una variabile utilizzabile al di fuori del ciclo for.
    kfila = fila;
    for (int i = 0; adiac < k && i < this->posti; ++i){

       if(!matr[fila*posti + i] && adiac < k)
         ++adiac;
        else
          adiac = 0;
    }
  }

  if(adiac >= k){
    for (int i = 1; i <= adiac; ++i)  //in questo caso i = 1 perchè la fun. prenota() scala in automatico di 1 il valore del posto passato. In quel caso j
      prenota(('A' + kfila), i);

    return true;
  }
  else
    return false;
  /*
  if(adiac >= k){
    for (int i = 0; i < adiac; ++i)
      matr[kfila * posti + i] = 1;

    return true;
  }
  else
    return false;
    */
}