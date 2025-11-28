#include  <iostream>
using namespace std;

int triplica(int* const ptr) {
  return *ptr*3;

}

int main() {
  int n;

  cout<<"Inserisci un numero intero\n";
  cin>>n;

  cout<<"Il triplo del valore inserito vale: "<<triplica(&n)<<endl;
  return 0;
}