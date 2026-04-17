#include <iostream>
using namespace std;

class Memory{
    char *matrix;
    int dim;
    int score;

    static int getTypeInt(char);
    static const char *getTypeStr(int);
    void rotate90();

public:
    //Prima Parte
    Memory(int);
    ~Memory();
    void inserisci(char, int, int, int, int);
    void riassumi();
    bool flip(int, int, int, int);
    friend ostream &operator<<(ostream &, const Memory &);

    //Seconda Parte
    Memory(const Memory &);
    Memory operator+(const Memory &);
    Memory &operator>>(int);
};