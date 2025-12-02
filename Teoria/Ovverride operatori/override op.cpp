#include <iostream>
#include <cstring>
using namespace std;

//To be completed
class stringa {
  char* str;
public:
  stringa(char[]);
  stringa(char ch) {
    str = new char [2];
    str[0] = ch;
    str[1] = '\0';
  }

  void scrivi();

  stringa& operator=(stringa dx) {  //ssx = (sx=dx)

    if (&(*this) == &(dx)) //Test aliasing: se l'indirizzo di dx e quello di sx coincidono allora sono lo stesso oggett. Equivale a if(this == &dx)
      return *this;

    delete[] this->str;
    this->str = new char[strlen(dx.str)+1];
    strcpy(this->str, dx.str);

    return * this;  //sx
  }

  stringa operator+(const stringa&);

};

void stringa::scrivi() {

}

stringa::stringa(char[]) {

}




//////////////////////////////////////
/// Classe N complessi            ///
////////////////////////////////////
class complesso {
  double re, im;
  //complesso(const complesso&);  //Mascheramento costruttore di copia
public:
  complesso(double r=0, double i=0){re = r; im=i;};

  //friend complesso operator+(complesso a, complesso b);
  friend complesso operator*(complesso a, complesso b); //Come funzione globale (Necessita di "friend" per accedere ai membri privati)

  complesso operator+(complesso b) { //Come funzione membro

    complesso c(this->re + b.re, this->im + b.im);
    return c;
  }

  complesso operator-(){
    complesso ris(-re, -im);
    return ris;
  }
  void scrivi(){cout<<"("<<re<<","<<im<<")"<<endl;};

  friend complesso operator+(complesso a, char[]);

};


/*
complesso operator+(complesso a, complesso b) { //Otteniamo un override di "+" scrivendo semplicemente "operator" seguito dall'operatore da assegnare
  complesso c(a.re+b.re, a.im+b.im);
  return c;
}
complesso operator*(complesso a, complesso b) { //Otteniamo un override di "*" scrivendo semplicemente "operator" seguito dall'operatore da assegnare

  complesso c(a.re+b.re, a.im+b.im);  //Da implementare correttamente
  return c;
}
*/

complesso operator+(complesso a, char str[]) { //Otteniamo un override di "+" scrivendo semplicemente "operator" seguito dall'operatore da assegnare
  complesso c(a.re+strlen(str), a.im+strlen(str));
  return c;
}

int main() {
  complesso c1(3,2);
  complesso c2(13, 12);
  //complesso c3(c1) ;  //Chiamata del costruttore di copia, errore:Costr di copia mascherato

  complesso c3;

  //c3 = somma(c1, somma(c1,c2));
  //dobbiamo riuscire a scrivere una cosa del genere

  //c3= c1+c2; //Equivare a c3= operator+(c1,c2);
  c3.scrivi();

  //c3=(c1+(c3*c3));
  c3.scrivi();
  //c3= (c1+c2) +c2;
  c3.scrivi();

  //Alcuni operatori possono essere ridefiniti SOLO COME funzione MEMBRO
  c2=c1;  //Solo come fun membro


  //Non esistono di default
  //c2+= c1;  //Solo come fun membro
  //c2*= c1;  //Solo come fun membro

  complesso c4;
  c1.scrivi();
  c4 = c1 + complesso(3, 5.6);
  c4.scrivi();

  c4 = c1 + "Ciao";
  c4.scrivi();

  c4 = c1 + 5.6;  //Compila perchè equivale a c4 = c1 + complesso(5.6, 0);


  stringa s1("Ciao");
  {
    stringa s2("Mondo");
    s2=s1;

    s2 = s1 = s2; //a = (b = c);

    stringa& s3 = s1;
    s3.operator=(s1);

    //s2.~stringa();
  }
  s1.scrivi();

  s1 = s1;

  stringa s4("Fondamenti");
  stringa s5("Qualcosa");

  s5 = s4 + stringa("Programmazione");
  s5.scrivi();

  s5 = s4 + 'a';

  return 0;
}
