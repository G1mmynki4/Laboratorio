#include <iostream>

using namespace std;

void init_ptr(int* &ptr) {
  ptr=nullptr;
}

int main() {
  int k = 5;
  int* ptk;

  cout<<"Valore ptr non inizializzato: "<<ptk<<endl;
  ptk = &k;

  cout<<"\nValore di K: "<<k<<endl;
  cout<<"Valore di ptr -> K: "<<ptk<<endl;

  init_ptr(ptk);
  cout<<"\nValore di ptr inizializzato a nullptr: "<<ptk<<endl;

  return 0;
}