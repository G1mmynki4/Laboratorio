#include <iostream>
#include "Lab10 Include/Cinema_class.h"

using namespace std;
int main(){
 // PRIMA PARTE
 Cinema c(3,7 ,"Moderno");

 c.prenota('A',4);
 c.prenota('C',1);
 c.prenota('C',2);
 c.prenota('C',3);
 c.prenota('C',4);
 c.prenota('C',5);
 c.prenota('C',6);
 c.prenota('C',7);
 c.prenota('B',4);
 c.stampa();

 c.cancella('B',4);
 c.stampa();

 // SECONDA PARTE
 cout << "Il numero di posti liberi in c e': " << c.quantiLiberi() << endl;
 c.prenotaAdiacenti(4);
 c.stampa();


//Test dell'error handler
 cout << "\n------Inizio sezione test error handler-------\n";
 Cinema c2(30, 10, "qwertyuiopasdfghjklzxcvbnm1234567ewerdsfdsfeerwe"); // Superiore a (nDIM -1) caratteri;

 c2.prenota(27, 10);
 c2.stampa();
 c2.prenota(26, 9);
 c2.prenota(25, 7);
 for (int i = 0; i < 26; ++i)
     c2.prenotaAdiacenti(9);

 c2.stampa();
 c2.cancella('Z', 10);
 c2.stampa();
 return 0;
}
