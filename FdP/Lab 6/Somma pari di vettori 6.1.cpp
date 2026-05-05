#include  <iostream>

using namespace std;

bool pari(const int *v, const int size) {//same as bool pari(int v[], int size)
  int somma = 0;
  for (int i = 0; i < size; i++)
    somma+=v[i];

  if (somma%2==0)
    return true;
  else
    return false;
}


int main() {
  int N = 10;
  int vector[N]={};

  cout<<"Inserisci i valori nell'array\n";

  for (int i=0; i<N; i++) {
    cout<<"Inserisci un numero ("<<i+1<<" su 10)\n";
    cin>>vector[i];
  }

  cout<<"La somma degli interi e': ";
  if (!pari(vector, N))
    cout<<"DISPARI\n";
  else
    cout<<"PARI\n";

  return 0;
}