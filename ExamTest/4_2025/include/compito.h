#include <iostream>
using namespace std;

struct Libri{
        char b_name[31];
        bool isUsed;
        Libri *next;
};

struct Scaffale{
    char s_name[21];
    unsigned int max;
    unsigned int nBook;

    Libri *ptr;
    Scaffale *next;
};

class LibreriaDigitale{
    Scaffale *head;

public:
    //Prima parte
    LibreriaDigitale();
    void aggiungiScaffale(char sname[], unsigned int capacity);
    bool aggiungiLibro(char nScaffale[], char bname[], bool isUsed);
    friend ostream &operator<<(ostream &os, const LibreriaDigitale &ld);

    //Seconda parte
    LibreriaDigitale(LibreriaDigitale &ld);
    ~LibreriaDigitale();
    void rimuoviLibro(char nscaffale[], char title[]);

    //LibreriaDigitale operator~() const;
    //LibreriaDigitale &operator!();
};