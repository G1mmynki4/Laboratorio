#include "iostream"
using namespace std;

const int MAX_L = 40;

class OggettiViaggio
{
    struct Object{
        char descr[MAX_L + 1];
        bool isTaken;

        Object *next;
    };

    Object *head;

public:
    //Prima Parte
    OggettiViaggio();
    OggettiViaggio(const OggettiViaggio &);
    friend ostream &operator<<(ostream &, const OggettiViaggio&);
    void aggiungi(const char *);
    void prendi(const char *);
    void viaggia();

    //Seconda Parte
    ~OggettiViaggio();
    void rimuovi(const char *);
    OggettiViaggio& operator+=(const OggettiViaggio&);
    OggettiViaggio operator!()const;
};

