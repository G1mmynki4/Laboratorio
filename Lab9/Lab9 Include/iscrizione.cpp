#include <iostream>
#include <cstring>
#include "Lab9/Lab9 Include/iscrizione.h"

using namespace std;

const int DIM = 31;

void init(iscritti* &head) {
  head = nullptr;
}

bool aggiungi(iscritti *&head, const char* nome, int pettorale) {

  iscritti* new_node = new iscritti;
  strcpy(new_node->name, nome);
  new_node->pettorale = pettorale;
  new_node->next = nullptr;

  if (strlen(nome)>DIM) {
    cout<<"Nome troppo lungo\n";
    return false;
  }

  if (head == nullptr) {
    head = new_node;
    return true;
  }

  iscritti *node = head;
  iscritti*p = nullptr;
  while (node!=nullptr) {
    if (strcmp(node->name, nome)==0 || node->pettorale == pettorale)
      return false;
    p = node;
    node = node->next;
  }

  p->next = new_node;
  return true;
}

void visualizza(iscritti *head) {
  cout<<"Atleti iscritti: \n";

  if (head != nullptr) {
    iscritti* node = head;
    while (node != nullptr) {
      cout<<node->name<<", "<<node->pettorale<<endl;
      node = node->next;
    }
  } else{
      cout<<endl;
      return;
  }
}

//Da completare


