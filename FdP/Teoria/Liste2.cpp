///////////////////////////
///Inserimento in testa///
/////////////////////////
#include <iostream>

using namespace std;

struct elem {
  int inf;
  elem* pun;
};

void stampaLista(elem* p0) {
  elem* p = p0;

  while (p != nullptr) {
    cout<<p->inf<<' ';
    p = p->pun; //Avanzo il puntatore
  }
  cout<<endl;
}

void intesta(elem* &p0, int a) {
  elem* n = new elem;
  n->inf = a;
  n->pun = p0;
  p0 = n;
}

//Versione base
/*
void dealloca(elem* p0) {
  elem* p = p0, *q;
  while (p != nullptr) {
    q = p;
    p = p->pun;
    delete q;
    //p = p->pun;         //Comportamento non definito (errato)
    //delete p;
  }
}
*/

//Versione Robusta
void dealloca(elem* &p0) {
  elem* p = p0, *q;
  while (p != nullptr) {
    q = p;
    p = p->pun;
    delete q;
    //p = p->pun;         //Comportamento non definito (errato)
    //delete p;
  }
}

bool esttesta(elem* &p0, int &a) {
  //p0 = p0->pun;     //Bypass, dal punto di vista logico, del primo elemento
  if (p0 == nullptr)
    return false;

  a = p0->inf;
  elem* p = p0;
  p0 = p0->pun;
  delete p;
  return true;
}

void insfondo(elem* &p0, int &a) {
  elem* n = new elem;
  n->inf = a;
  n->pun = nullptr;

  elem* p = p0;
  elem* q = nullptr;
  while (p != nullptr) {
    q = p;
    p = p->pun;
  }
  if (p0 == nullptr)
    p0 = n;
  else
    q->pun = n;
}

bool estrazione(elem* &p0, int a) {
  elem* p = p0;
  elem* q = nullptr;

  while (p != nullptr && p->inf != a) {
    q = p;
    p = p->pun;
  }

  if (p == nullptr) // sia lista vuota che elemento non presente
    return false;

  if (a == p0->inf) {
    p0 = p0->pun;
    delete p0;
    return true;
  }

  a = p->inf;
  q->pun = p->pun;
  delete p;
}

void insordinato(elem* &p0, int a) {
  elem* n = new elem;
  n->inf = a;

  elem* p = p0;
  elem* q = nullptr;
  while (p != nullptr && p->inf < a) {
    q = p;
    p = p->pun;
  }
  if (p0 == nullptr) {    //Caso di lista vuota
    n->pun = nullptr;
    p0 = n;
    return;
  }

  if (p == nullptr) {
    if (q != nullptr) {   //Caso di inser. in fondo
      n->pun = nullptr;
      q->pun = n;
      return;
    }
    else { //Caso di inser. in testa con lista non vuota
      n->pun = p0;
      p0 = n;
      return;
    }
  }
  //Caso di inserimento in mezzo alla lista
  n->pun = p;
  q->pun = n;
}

int main() {

  elem* L1 = nullptr;
  stampaLista(L1);

  elem* n = new elem;
  n->inf = 3;
  n->pun = nullptr;

  L1 = n;
  stampaLista(L1);

  elem* n2 = new elem;
  n2->inf = 5;
  n2->pun = L1;

  L1 = n2;
  stampaLista(L1);

  elem* n3 = new elem;
  n3->inf = 7;
  n3->pun = L1;

  L1 = n3;
  stampaLista(L1);

  cout << endl;

  elem* L2 = nullptr;
  intesta(L2,4);
  stampaLista(L2);

  intesta(L2,5);
  stampaLista(L2);
  intesta(L2,6);
  stampaLista(L2);

  intesta(L2,7);
  stampaLista(L2);

  int val;
  if (esttesta(L2, val))
    cout << "Serviamo il numero " <<val<< endl;
  else
    cout << "Lista vuota" <<endl;
  cout << "Nuova lista L2: " << endl;
  stampaLista(L2);

  elem* L3 = nullptr;
  if (false)
    intesta(L3,1);
  stampaLista(L3);
  dealloca(L3);
  stampaLista(L3);

  return 0;
}