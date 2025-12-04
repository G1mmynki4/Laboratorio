#include <iostream>
#include "palazzo_class.h"

using namespace std;

Palazzo::Palazzo(int n) {
  maxFloor = n;
  floor = 0;

  palazzo = new bool*[maxFloor];
  palazzo[floor] = new bool[floor+1]; //Inizzializzo il primo piano con floor + 1 finestre di default
  palazzo[floor][0] = false;

  ++floor;
}

Palazzo::Palazzo(Palazzo &p) {
  this->maxFloor = p.maxFloor;
  this->floor = p.floor;

  this->palazzo = new bool *[maxFloor];
  for (int i = 0; i<floor; ++i) {

    this->palazzo[i] = new bool[i];

    for (int j = 0; j < i; ++j) {
      this->palazzo[i][j] = palazzo[i][j];
    }
  }

}


void Palazzo::aggiungi() {
  if (floor < maxFloor) {
    palazzo[floor] = new bool[floor+1];

    for (int i = 0; i<floor+1; ++i)
      palazzo[floor][i] = false;

    ++floor;
  }
}

void Palazzo::stampa() {
  cout<<"<"<<floor<<">"<<endl;

  for (int i = 0; i < floor; ++i) {
    cout<<"Piano "<<i+1<<": ";
    for (int j = 0; j < i+1; ++j) {
      if (palazzo[i][j])
        cout<<"Aperta ";
      else
        cout<<"Chiusa ";
    }
    cout<<endl;
  }
}

//Seconda parte
void Palazzo::cambia(int floor, int window) {
  if (palazzo[floor-1][window-1])
    palazzo[floor-1][window-1] = false;
  else
    palazzo[floor-1][window-1] = true;

}

Palazzo::~Palazzo() {
  for (int i = 0; i < floor; ++i) {
    delete[] palazzo[i];
  }
  delete[] palazzo;
}

