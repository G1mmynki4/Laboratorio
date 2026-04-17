#include <iostream>

using namespace std;

/**
 * Funzione che richiama se stessa
*/

int fattoriale (int n) {
  if (n == 0)
    return 1;

  return n * fattoriale(n-1);
}

int main() {

  int n = fattoriale(3);
  cout<<n<<endl;

  return 0;
}

/**Funzionamento di base della ricorsione
//Memoria Stack
  In questo caso fatt(3) chiama fatt(2) che chiama fatt(1) che chiama fatt(0) che restituisce 1*fatt(0) = 1
  e quindi fatt(1)= 1 * 1-> fatt(2) = 2*1 = 2-> fatt(3) = 3*2 = 6; quindi la funzione in ritorno si aspetta il ritorno di se stessa, il quale
  sarà un numero definito solo quando si richiama fatt(0), ovvero appena si percorre al contrario l'esecuzione.
*/

/**Struttura di un algoritmo ricorsivo
 La ricorsione è sempre gestita da una variabile di controllo
 In base alla var di contr. si possono distinguere 2 casi:

  1)Caso Base (uno o più):
    E' quel caso che porta al termine della ricorsione

  2)Passo di ricorsione (uno o più):
    Il caso in cui la funzione ricorsiva chiama se stessa passando un nuovo valore della var di contr.
    ovvero tutti quei casi in cui la var di contr. ha un valore diverso da quello specificato nei Casi Base.
 */

//////////////////////////
///Esempi di algoritmi///
////////////////////////

/*Massimo Comune Divisore
    Algoritmo di Euclide
*/
int mcd(int alfa, int beta) {
  //Caso Base
  if (beta == 0)
    return alfa;

  //Passo ricorsivo
  return mcd(beta, alfa%beta);
}

/*Somma dei primi n interi positivi*/
int somma(int n) {
  //Caso Base
  if (n == 0)
    return 0;

  //Passo ricorsivo
  return n = n+somma(n-1);
}

/*Serie di Fibonacci*/
//Ogni numero è la somma dei due che lo precedono, in questo caso le posizioni iniziano da 1;
int fibonacci(int n) {
  //Casi Base
  if (n == 1)
    return 0;
  if (n == 2)
    return 1;

  //Passo Ricorsivo
  return fibonacci(n-1)+fibonacci(n-2);
}

/**Approccio Ricorsivo vs Iterativo
  Per qualunque problema risolvibile in modo ricorsivo esiste anche il modo
  iterativo e viceversa

**Svantaggi del modo Ricorsivo
  1) Consumo di memoria
  2) Prestazioni minori, causate dall'avvio ripetitivo di nuovi stack frames

**Vantaggi del modo Ricorsivo
  1) Maggiore semplicità con meno righe di codice
 */