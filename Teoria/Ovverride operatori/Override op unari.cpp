#include  <iostream>

using namespace std;

/**
 E' una definizione di funzione: ~ -> operator~
 Esistono 6 modi diversi per la ridefinizione classificati in 2 gruppi:
  *3 prevedono ridef. come funzione MEMBRO della classe
  *3 prevedono la ridef. come funzione GLOBALE, affinchè la fun globale possa operare sugli attributi classe
     su cui è invocato deve essere dichiarata come "FRIEND" e necessita del passaggio di un argomento esplicito.


 -Ridefinizione di operatore unario: come dichiarare la funzione operator?
  Membro o globale?
    *Nel caso generale non cambia, entrambi i metodi sono equivalenti.
    *Nel caso di operatore BINARIO la scelta è più vincolata
 */
//Esempio
class complesso;
complesso operator+(const complesso& c1, int a);  //Non mi permette di fare a + c1, ma solo c1 + a;

///Per permettere il contrario, l'operatore va ridefinito come funzione MEMBRO

//Nella dichiarazione di classe: friend operator+(int a);
complesso::operator+(int a); //In questo caso il primo argomento è il ptr this, mentre il secondo è l'intero da sommare.

//Chiamata funzione
  complesso c2;
  c2 + 3;
  int a = 2;
  a+c2;


/**
  Quale metodo dei 6 va scelto?

    *All'interno di un dato gruppo di modi(fun membro o fun globale), entrambe le prime soluzioni(A e A1) modificano l'oggetto classe passato
     come operando e restituiscono "VOID"

    *Le seconde soluzioni(B e B1) NON MODIFICANO l'oggetto passato e restituiscono, come risultato dell'operazione
     un NUOVO OGGETTO, in questo caso l'oggetto operando viene passato per VALORE

    *Le terze soluzioni(C e C1) invece MODIFICANO l'oggetto, ma differenza delle prime, restituiscono un RIFERIMENTO all'oggetto
     modificato

  Nota:
    Le soluzioni B/B1 e C/C1 possono essere utilizzate contemporaneamente poichè hanno signatura differente;
    Ovviamente non si possono fare coesistere funzioni appartenenti a 2 gruppi differenti: non si può implementare sia A che A1...
 */

/**
  Nel caso di operatore POST-FISSO (c1 ++), in caso volessi usare entrambe le opzioni, dovrei definire nuovamente
  una funzione operator++(), sta volta passando un argomento in più di tipo INTERO utilizzato dal compilatore come
  DISCRIMINANTE tra i metodi di invocazione:
    *c1++(come prefisso: funzione senza int)
    *++c1(come postfisso: funzione con discrim. int)

  *Come fun. mebro, va passato un altro argomento intero, necessario per discriminare il prefisso dal postfisso
   Nella classe:
      void operator++(int);

  *Come fun. globale, oltre all'oggetto classe va passato anche un intero;
   Nella classe:
      friend operator++(complesso& c1, int a)

   Nel blocco globale:
      complesso::operator+(complesso& c1, int a)

  Questo stratagemma ci permette di usare entrambi i metodi di invocazione:
    ++c1 e c1++;
 */