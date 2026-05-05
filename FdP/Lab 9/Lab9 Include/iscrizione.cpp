#include <iostream>
#include <cstring>
#include "Lab 9/Lab9 Include/iscrizione.h"

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

bool cerca(iscritti *list, const char * nome) {
  iscritti* node = list;

  while (node!=nullptr) {
    if (strcmp(node->name, nome)== 0)
      return true;
    node = node->next;
  }

  return false;
}

bool elimina(iscritti *&list, const char* nome) {
    iscritti* tmp, *toDel;
    // scorro finche' non trovo l'atleta con quel nome o finche' non finisce la lista
    for(toDel = list; (toDel!= nullptr) && (strcmp(toDel->name, nome) != 0); toDel = toDel->next)
        tmp = toDel;

    if (toDel == nullptr)
        return false;

    if(toDel == list) // eliminazione in testa
        list = toDel->next;
    else
        tmp->next = toDel->next;

    delete toDel;
    return true;
}