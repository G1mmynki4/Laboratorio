#include <iostream>

using namespace std;

int ptr_function(int* ptr) {
  cout<<"Dentro ptr_function(), valore puntatore: "<<ptr<<endl;
  cout<<"Dentro ptr_function(), valore oggetto puntato: "<<*ptr<<endl;

  if ((*ptr % 2)== 0)
    return *ptr*(*ptr);
  else if ((*ptr % 3) == 0)
    return *ptr*(*ptr)*(*ptr);
  else
    return *ptr;
}


int main() {
  int n;

  cout<<"Inserisci un numero\n";
  cin>>n;

  cout<<"Indirizzo di memoria di n: "<<&n<<endl;

  int res = ptr_function(&n);
  cout<<"Il risultato e': "<<res<<endl;

  return 0;
}