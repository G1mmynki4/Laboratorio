#include <iostream>
#include <cstring>

using namespace std;

/**
 * Costruttore di copia:
 * A differenza del costr. classico è un particolare tipo di costr. che interviene
 * tra due oggetti della stessa classe. E' un costruttore PREDEFINITO (di default), "Costruttore di copia default".
 */
class esempio {
  int a;
  double b;

public:
  esempio(const esempio& e) {   //Ovviamente non ha tipo di ritorno
                                //Essendo un costr. di copia deve avere valori passati per RIFERIMENTO.
   /*this->a*/ a= e.a;
    /*this->b*/b= e.b;
  }                             //Ha il ruolo di effettuare una copia membro a membro.

  esempio(double a1, double b1) { //Costruttore normale.
    a = a1;
    b = b1;
  };
};

/**
 * Esistono 3 casi in cui si invoca il costr. di copia
 * 1) viene invocato automaticamente dal compil. ogni volta che serve inizializzare un oggetto creato in quel momento.
 * oggetto classe viene inizializzato con un altro oggetto classe PREESISTENTE.
 */

esempio e2(3, 2.5);
esempio e1 = e2;  //e1(e2); interviene il costr. di copia

/**
 * 2) Passo un oggetto classe PER VALORE ad una funzione.
 */

void fun(esempio ec) {  //Passaggio per valore (copia)
  //.....
}

//nel main
int main()
{
  esempio e1(2, 1.3);

  fun(e1);  //Si invoca il costr. di copia perchè stiamo inizializzando un nuovo oggetto dentro la fun.
}


/**
 * 3) La funzione ritorna un oggetto per valore.
 */
esempio fun2(esempio ec) {
  //......
  return ec;
}

int main2() {
  esempio e1(1,3.4);

  esempio e2 = fun2(e1);  //Si invoca il c di copia perchè stiamo copiando il ritorno di una fun di tipo esempio
                                //per inizializzare un nuovo membro.
}



//////////////////////////////////////////////////////////////////////////////////
///Classe che prevede allocazione in memoria dinamica e quindi un distruttore.///
///////////////////////////////////////////////////////////////////////////////


/**
 * In questo caso NON SI PUO' utilizzare il cost di copia di default del compilatore ma bisogna specificarlo manualmente.
 */
class stringa {
  char* str;
public:
  stringa(const char s[]);  //Costruttore normale
  ~stringa();
};

//!!!!!
//In questo primo caso usiamo il costr di copia di default del compilatore.
//!!!!!
stringa::stringa(const char s[]) {
  str = new char[strlen(s)+1];
  strcpy(str, s);
}

 stringa::~stringa() {
  delete[] str;
}
////////////////////////////////////////////
//Fine dichiarazione e definizione classe//
//////////////////////////////////////////

//Inizio programma esempio
void fun3(stringa sc) {
  //....;
}

int main3() {
  stringa s1("Fondamenti");
  fun3(s1);

  return 0;
}

/**
 * Mem. Stack contiene s1.str e contiene anche sc.str

 * Mem. Heap contiene il new char["Fondamenti \0"];
 *
 * Quando invoco fun, il cost di copia default fa una copia membro a membro quindi:
 * sc.str = s1.str (che contiene l'indirizzo di memoria di "F")
 *
 * Quando la funzione termina, prima di tutto si elimina tutta l'area di mem din che contiene l'array["Fondamenti"]
 * poi si elimina anche sc, quindi al termine non avrò più sc, l'area di mem è stata svuotata
 * e quindi avrò che s1.str punterà ad un area NON ALLOCATA creando SCRITTURE ERRATE in parti sconosciute di memoria.
 * Quindi è un COMPORTAMENTO NON DEFINITO. creando un PUNTATORE PENDENTE (ptr che esiste sullo stack e punta in un area
 * di mem dinamica inesistente).
 *
 *

Per risolvere il problema dobbiamo ridefinire il COSTRUTTORE DI COPIA
*/
class stringa2 {

  char* str2;
public:
  stringa2(const stringa2& s2);  //Costruttore di copia Ridefinito dall'utente, sovrascrivendo quello default del compilatore.

  stringa2(const char s[]);  //Costruttore normale
  ~stringa2();
};

stringa2::stringa2(const stringa2& s2) {
  str2 = new char[strlen(s2.str2)+1];
  strcpy(str2, s2.str2);
}


stringa2::stringa2(const char s[]) {
  str2 = new char[strlen(s)+1];
  strcpy(str2, s);
}
////////////////////////////////////////////
//Fine dichiarazione e definizione classe//
//////////////////////////////////////////


/**
 * Mem stack. s1.str
 *
 * Mem heap s1.str->"Fondamenti", sc.str->"Fondamenti"
 *
 * In questo caso al termine della funzione viene eliminato solo sc e l'area di mem dinamica puntata da sc
 */


/**
 * Se non si vuole che il cost di copia non venga invocato si può inibire l'invocazione
 * Per impedire l'utilizzo del costruttore di copia lo si può dichiarare nella
 * SEZIONE PRIVATA della classe e quindi non si potranno creare oggetti copia di quelli pre esistenti.
 *
 * Esempio
 * In una classe persona, non è possibile avere 2 persone con gli stessi dati e parametri.
 */
