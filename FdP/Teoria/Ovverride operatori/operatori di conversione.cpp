#include <iostream>
#include <cstring>
using namespace std;

class stringa {
  char* str;
public:
  stringa(char[]);
  stringa(char ch) {
    str = new char [2];
    str[0] = ch;
    str[1] = '\0';
  }

  stringa& operator=(stringa dx) {  //ssx = (sx=dx)
    if (&(*this) == &(dx)) //Test aliasing: se l'indirizzo di dx e quello di sx coincidono allora sono lo stesso oggett. Equivale a if(this == &dx)
      return *this;

    delete[] this->str;
    this->str = new char[strlen(dx.str)+1];
    strcpy(this->str, dx.str);

    return * this;  //sx
  }


  void scrivi();

  //Ocverride operatori
  stringa operator+(const stringa&);
  operator bool(){return strlen(str)!=0;};

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

  void scrivi(){cout<<"("<<re<<","<<im<<")"<<endl;};

  //Override operatori
  friend complesso operator+(complesso a, char[]);
  operator double();
  operator int();
  operator bool();

};

complesso::operator double() { return re+im; };
complesso::operator int() { return static_cast<int>(re+im); };
complesso::operator bool() { return re != 0 && im != 0; };



int main() {

  complesso c1(3.2, 4);
  cout<<(double)c1<<endl;
  cout<<(int)c1<<endl;

  if (bool(c1)) {
   //...
  }

  //Sezione stringhe
  {
    stringa s4("Fondamenti");
    cout<<(bool)s4<<endl;

    if (bool(s4)) {
      cout<<"s4 ha lunghezza diversa da zero\n";
    }
  }


  return 0;
}
