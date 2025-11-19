const int DIM = 5;

struct pila{
    int st[DIM];
    int top;
};

void initP(pila &pila);
bool isFull(pila &pila);
bool isEmpty(pila &pila);
bool push(pila &pila, int);
void azzera_pila(pila &pila);