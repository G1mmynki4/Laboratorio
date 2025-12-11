
class Palazzo {

  int maxFloor = 0;
  int floor;
  bool** palazzo = nullptr;

public:
  //Prima parte
  Palazzo(int n);
  Palazzo(Palazzo &p);

  void aggiungi();
  void stampa();

  //Seconda parte
  ~Palazzo();
  int operator!();
  void cambia(int i, int j);
  void operator%=(Palazzo p);
};

