#include <iostream>
#include <cstring>

using namespace std;

const unsigned int MAX_DIM = 31;

struct record {
  char nome[MAX_DIM];
  char cognome[MAX_DIM];
  int eta;
};

struct elem {
  char nome[MAX_DIM];
  char cognome[MAX_DIM];
  int eta;
  elem* pun;

  //elem inf2; //VIETATO
};

int main() {
  record r1, r2; //Fa le veci di un tipo ma non è un tipo dall'utente

  strcpy(r1.nome, "Mario");
  strcpy(r1.cognome, "Rossi");
  r1.eta = 44;

  r2 = r1; //Ricopiatura membro a membro

  //r2.nome = r1.nome; //Impossibile copiare su un array char
  r2.eta = r1.eta;

  cout<<r2.nome; //Mario, nonostante la copia tra array char non esista, la ricopiatura membro a membro uguaglia tutto implicitamente.

  record* p = &r1;
  cout<<(*p).eta<<endl;//44
  cout<<p->eta<<endl; //Operatore freccia //44
  cout<<p->nome<<endl;

  record* q = nullptr;
  q = new record[5];
  q[0].eta = 66; //==(*q)->eta == (*(q+0)).eta == (*q).eta

  strcpy(q[0].nome, "Giovanni");
  strcpy(q[0].cognome, "Verdi");
  q[0].eta = 66;

  strcpy(q[1].nome, "Giovanni");
  strcpy(q[1].cognome, "Verdi");
  q[1].eta = 16;

  delete[]q;

  elem* L1 = nullptr; //Lista vuota

  L1 = new elem; //Lista con un elemento
  strcpy(L1->nome, "prova");
  strcpy((*L1).cognome, "prova");

  return 0;
}