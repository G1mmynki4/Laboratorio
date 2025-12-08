#ifndef STM_PALAZZO_H
#define STM_PALAZZO_H
#include <iosfwd>

#include "Floor.h"

class Palazzo {
 private:
  const unsigned long MAX_HEIGHT;
  unsigned long floors_number;

  Floor* head;
  Floor* tail;

  // Helper per deallocare la memoria (DRY principle)
  void clear();

 public:
  // 1 solo piano (1 finestra aperta true)
  Palazzo(unsigned long N);

  // deep copy del palazzo
  Palazzo(const Palazzo& other);

  // deep delete della struttura dati
  ~Palazzo();

  // aggiunge un piano del palazzo
  bool aggiungi();

  // aggiunge un piano del palazzo
  bool aggiungi(const Floor& floor);

  // operatore per l' output stream
  friend std::ostream& operator<<(std::ostream& os, const Palazzo& p);

  // operator di assegnamento (Rule of Three)
  Palazzo& operator=(const Palazzo& other);

  // PARTE 2

  bool cambia(unsigned long i, unsigned long j);

  unsigned long operator!() const;

  Palazzo& operator%=(const Palazzo& p1);
};

#endif  // STM_PALAZZO_H
