#include "iostream"
using namespace std;

const int MAX_L = 40;

class OggettiViaggio
{
    struct Objects{
        char descr[MAX_L + 1];
        bool isTaken;

        Objects *next;
    };

    Objects *head;

public:
    //Prima Parte
    OggettiViaggio();
    OggettiViaggio(const OggettiViaggio &);

    friend ostream &operator<<(ostream &, const OggettiViaggio&);
    void aggiungi(const char *);
    void prendi(const char *);
    void viaggia();
};

