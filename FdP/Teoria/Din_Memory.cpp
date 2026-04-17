#include  <iostream>

using namespace std;

//Es per casa
//Dato un vettore molto grande, restituire
//un nuovo vettore contenente solo gli interi pari
//assumendo che siano pochi.

void allocaMemoria(int* &DinVet, int len) {
  DinVet = new int[len];
}

void deallocaMemoria(int* &DinVet) {
  delete[] DinVet;
}

void estendiVettore(int* &DinVet, const int len, const int n) {
  int* nuovo = nullptr;
  nuovo = new int[len+1];

  for (int i=0; i<len; i++) {
    nuovo[i] = DinVet[i];
  }
  nuovo[len] = n;
  delete[] DinVet;
  DinVet = nuovo;
}

int main() {
  int* vettDin = nullptr;

  int len;
  cout<<"Inserisci dimensione\n";
  cin>>len;

  allocaMemoria(vettDin, len);
  cout<<vettDin;

  //5 Elementi
  estendiVettore(vettDin, len, 56);
  ++len;
  //6 Elementi [1,2,3,4,5,56]
  //stampaVettore(vettDin, len);

  deallocaMemoria(vettDin);

  return 0;
}