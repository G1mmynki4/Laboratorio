#include "lib_vett.h"
#include <iostream>

const double pi = 3.14; //Collegamento INTERNO, non manda in conflitto il linker

static void stampa_lista(elem* p0) {  //"Static", questa funzione ha collegamento interno:
                                      // può essere invocata SOLO all'interno dell'unità di
                                      // compilazione in cui è definita.

}