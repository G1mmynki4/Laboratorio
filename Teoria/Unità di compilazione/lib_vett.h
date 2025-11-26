#pragma once

extern const double pi; //Dichiarata ma non definita, definizione in "lib_vett.cpp", reso possibile mediante "extern"

void ordina_vettore(int[], int);
void stampa_vettore(int[], int);

struct  elem {  //Collegamento interno
  int inf;
  elem* next;
};
