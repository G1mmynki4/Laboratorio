

struct Floors{
    bool *floor = nullptr;
    Floors *next;
};

class Palazzo2{
    int maxFloors;
    int floors;

    Floors* head;
    void addToStruct(Floors*& elem);
public:

    //Prima Parte
    Palazzo2(int maxFloors);
    Palazzo2(Palazzo2 &p);
    void aggiungi();
    void stampa();

    //Seconda Parte
    ~Palazzo2();
    void cambia(int fl, int wnd);
    int operator!();
    Palazzo2 operator%=(Palazzo2 p);
};