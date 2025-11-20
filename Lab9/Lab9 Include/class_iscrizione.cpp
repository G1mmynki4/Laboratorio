#include "class_iscrizione.h"
#include <iostream>
#include <cstring>

using namespace std;
const int DIM = 31;

void Iscrizione::init() {

  iscritti * head;
  head = nullptr;
}

bool Iscrizione::aggiungi(const char *nome, const int pettorale) {

  iscritti* new_node = new iscritti;
  strcpy(new_node->name, nome);
  new_node->pettorale = pettorale;
  new_node->next = nullptr;

  if (strlen(nome)>DIM) {
    cout<<"Nome troppo lungo\n";
    return false;
  }

  if (list == nullptr) {
    list = new_node;
    return true;
  }

  iscritti *node = list;
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

void Iscrizione::visualizza() {
  cout<<"Atleti iscritti: \n";

  if (list != nullptr) {
    iscritti* node = list;
    while (node != nullptr) {
      cout<<node->name<<", "<<node->pettorale<<endl;
      node = node->next;
    }
  } else{
    cout<<endl;
    return;
  }

}

bool Iscrizione::cerca(const char * nome) {
  iscritti* node = list;

  while (node!=nullptr) {
    if (strcmp(node->name, nome)== 0)
      return true;
    node = node->next;
  }
}

bool Iscrizione::elimina(const char* nome) {


}

