#include <iostream>

using namespace std;

const int CLEN = 20;
const int MLEN = 15;

class CasaDiCura{

    struct Meds{
        char mName[MLEN + 1];
        bool taken;
        int time;

        Meds *next;
    };

    struct Guest{
        int guestId;
        Meds* med;

        Guest *next;
    };

    char cName[CLEN + 1];
    int nGuests;
    Guest *head;

    void initGuest();

public:
    //Prima Parte
    CasaDiCura(const char *, int);
    friend ostream &operator<<(ostream &, const CasaDiCura &);
    bool aggiungiFarmaco(int, const char *, int);
    bool assumiFarmaci(int, int);

    //Seconda Parte
    CasaDiCura(const CasaDiCura &);
    ~CasaDiCura();
    CasaDiCura rimuoviFarmaco(const int, const char *);
};
