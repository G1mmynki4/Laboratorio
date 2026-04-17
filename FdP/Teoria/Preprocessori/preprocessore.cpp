#include  <iostream>
using namespace std;

/**
 **Definizione di simboli con associato un valore, mediante il preprocessore
 **/
#define konst 40  //Preprocessore, definito con il simbolo "#"

/**
 **Definizione di Macro
 **/
#define MAX(A,B) ((A)>(B) ? (A):(B))  //Attenzione alle parentesi

/**
 **Compilazione condizionale
 **/
#define DEBUG_LEVEL 1

//Forme concise
#define LINUX     //Commentare questa riga e scommentare l'altra per compilare sotto "WINDOWS"
//#define WINDOWS

//#ifdef sta per #if defined identifier
//#ifndef sta per #if not defined identifier

int main() {
  int x = konst;
  cout<<x<<endl;

  //Macro
  int y;
  y = 9 + MAX(2,5);
  cout<<y<<endl;

  //Compilazione condizionale
  //In questo caso viene compilata solo la sezione definita dal valore di DEBUG_LEVEL corrente, le altre non vengono compilate;
#if DEBUG_LEVEL == 2
  cout<<i<<j; //Debug di i e j
#elif DEBUG_LEVEL == 1
  cout<<1;
#else
  //DEBUG_LEVEL = 0 ;
  //Nessuna cout;
#endif

  //Forme concise
#ifdef LINUX
  system("CLEAR");
#elif defined WINDOWS
  system("CLS");
#else
  cout<<"Os non supportato \n";
  exit(1);
#endif

  return 0;
}