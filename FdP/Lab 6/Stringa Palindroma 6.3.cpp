#include <iostream>
#include <cstring>

using namespace std;

bool palindroma(const char* v) {
  int ultimo = strlen(v)-1;
  int primo = 0;

  while (primo < ultimo) {
    if (v[primo]!=v[ultimo])
      return false;
    primo++;
    ultimo--;
  }
  return true;
}

int main() {
  const int size = 40;
  char parola[size];

  cout<<"Inserisci una parola (max 40 caratteri)\n";
  cin.getline(parola,size); //Più sicuro di cin>> in quanto evita il buffer overflow
  //cin>>parola;

  if (palindroma(parola))
    cout<<"La parola e' palindroman\n";
  else
    cout<<"La parola non e' palindroma \n";

  return 0;
}