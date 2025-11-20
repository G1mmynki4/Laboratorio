#include <iostream>
using namespace std;

//////////////////////
///Funzioni InLine///
////////////////////

//Definizione
//Quando una funzione è dichiarata come "funzione InLine", in fase di traduzione del programma
//(compilazione, linking), il compilatore sostituisce SE POSSIBILE la chiamata di questa funzione con il corpo
//della funzione stessa.


//Come si dichiara una funzione InLine?
//Si dichiara semplicemente scrivendo prima del tipo di ritorno la parola "inline"
//inline double square(double x){ return x*x; }


//Perchè se possibile?
//Il compilatore non rispetta l'istruzione "inline" quando la funzione è troppo grossa,
//sostituire il corpo della funzione ad ogni chiamata aumenterebbe di troppo le dimensioni del codice.
//andando a causare "CodeBloat" ovvero l'espansione incontrollata delle dimensioni del programma sul disco
//provocando un calo delle prestazioni in runtime;


//Quali sono i vantaggi?
//Evita il costo della chiamata di funzione, ovvero:
//->Salvataggio dell'indirizzo dell'istruzione da eseguire.
//->Passaggio dei parametri.
//->Passare all'indirizzo della funzione chiamata.
//->Creare lo "StackFrame".
//->Gestire il ritorno al chiamante.

//Di solito le "InLine" sono funzioni piccole con poche istruzioni senza cicli;

//Inline e Classi
//Tutte le funzioni membro definite all'interno della classe sono di default "InLine".