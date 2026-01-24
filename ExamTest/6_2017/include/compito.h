#include <iostream>
using namespace std;


class Anfiteatro{
    struct Cols{
        int nRows;
        Cols *next;
    };

    Cols *head;

public:
    //Prima Parte
    Anfiteatro(const int);
    void aggiungiMattonelle(const int);
    void aggiungiColonna(const int);
    friend ostream &operator<<(ostream &, const Anfiteatro &);

    //Seconda Parte
    ~Anfiteatro();
    void togliColonna(const int j);
    Anfiteatro &operator=(const Anfiteatro &);
};