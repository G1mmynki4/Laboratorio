#include "Cinema_class.h"
#include <iostream>
#include <cstring>

using namespace std;
char c = 'A';

//Definizione Costruttore
Cinema::Cinema(int n, int p, char s[]) {

  if(strlen(s) < nDIM-1)
    strcpy(nome, s);

  //Creo una matrice lineare booleana che contiene file e posti
  matr = new bool[n*p];

  if(p<=9)
    posti = p;
  else
    cerr << "Il numero di posti massimi per fila consentito e' 7\n";
  posti = 7;

  //Assegno le file totali
  ftot = n;

  for (int i=0; i<posti*ftot;++i)
    matr[i] = 0;


}

//Definizione distruttore
Cinema::~Cinema(){

  delete[] matr;
}

bool Cinema::prenota(char l, int j) {
  int fila = l-'A';
  //cout<<endl;
  //cout<<"Fila prenota = "<<fila<<endl;

  if (!matr[posti*fila + (j-1)]) {
    matr[posti*fila + (j-1)] = 1;
    cout<<"Prenotato posto"<<posti*fila + (j-1)<<endl;
    return true;
  }
  return false;
 }


bool Cinema::cancella(char l, int j) {
  int fila = l-'A';
  //cout<<endl;
  //cout<<"Fila prenota = "<<fila<<endl;

  if (matr[posti*fila + (j-1)]) {
    matr[posti*fila + (j-1)] = 0;
    //cout<<"Cancellato posto"<<posti*fila + (j-1)<<endl;
    return true;
  }
  return false;
 }

void Cinema::stampa() {

  cout<<"Nome del cinema: "<<nome<<endl;
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