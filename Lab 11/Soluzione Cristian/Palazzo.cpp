#include "Palazzo.h"

#include <ostream>

void Palazzo::clear() {
  Floor* tmp = head;
  while (tmp != nullptr) {
    Floor* next = tmp->next;
    delete tmp;
    tmp = next;
  }
  head = nullptr;
  tail = nullptr;
  floors_number = 0;
}

Palazzo::Palazzo(unsigned long N) : MAX_HEIGHT{N} {
  if (MAX_HEIGHT > 0) {
    head = new Floor(1, nullptr);
    head->windows[0] = false;
    tail = head;
    floors_number = 1;
  }
}

Palazzo::Palazzo(const Palazzo& other)
    : MAX_HEIGHT{other.MAX_HEIGHT},
      floors_number{0},
      head{nullptr},
      tail{nullptr} {
  Floor* tmp = other.head;

  while (tmp != nullptr) {
    Floor* new_node = new Floor(*tmp);

    if (head == nullptr) {
      head = new_node;
      tail = new_node;
    } else {
      tail->next = new_node;
      tail = new_node;
    }
    floors_number++;
    tmp = tmp->next;
  }
}

Palazzo::~Palazzo() { clear(); }

bool Palazzo::aggiungi() {
  if (this->floors_number == this->MAX_HEIGHT) return false;

  Floor* new_floor = new Floor(floors_number + 1, nullptr);

  if (this->tail == nullptr) {
    this->head = new_floor;
    this->tail = new_floor;

  } else {
    this->tail->next = new_floor;
    this->tail = new_floor;
  }
  this->floors_number++;
  return true;
}

bool Palazzo::aggiungi(const Floor& floor) {
  if (this->floors_number == this->MAX_HEIGHT) return false;
  if (floor.windows_number != this->floors_number + 1) return false;

  Floor* new_floor = new Floor(floor);

  this->floors_number++;

  if (this->tail == nullptr) {
    this->head = new_floor;
    this->tail = new_floor;

  } else {
    this->tail->next = new_floor;
    this->tail = new_floor;
  }

  this->floors_number++;
  return true;
}

std::ostream& operator<<(std::ostream& os, const Palazzo& p) {
  Floor* current_floor = p.head;
  unsigned int floor_counter = 0;

  os << '<' << p.floors_number << '>' << std::endl;
  while (current_floor != nullptr) {
    floor_counter++;

    os << "Piano " << (floor_counter) << ": ";

    for (int j = 0; j < current_floor->windows_number; ++j) {
      os << (current_floor->windows[j] ? "Aperta" : "Chiusa");

      if (j < current_floor->windows_number - 1) {
        os << " ";
      }
    }

    os << std::endl;

    current_floor = current_floor->next;
  }

  return os;
}
Palazzo& Palazzo::operator=(const Palazzo& other) {
  if (this == &other) return *this;

  clear();

  Floor* tmp = other.head;
  while (tmp != nullptr) {
    Floor* new_node = new Floor(*tmp);
    if (head == nullptr) {
      head = new_node;
      tail = new_node;
    } else {
      tail->next = new_node;
      tail = new_node;
    }
    floors_number++;
    tmp = tmp->next;
  }
  return *this;
}

bool Palazzo::cambia(unsigned long i, unsigned long j) {
  if (i == 0 || j == 0) return false;

  Floor* current = head;
  unsigned long floor_counter = 1;

  while (current != nullptr && floor_counter < i) {
    current = current->next;
    floor_counter++;
  }

  if (current == nullptr) return false;

  if (j > current->windows_number) return false;

  current->windows[j - 1] = !current->windows[j - 1];

  return true;
}
unsigned long Palazzo::operator!() const {
  unsigned long total_open = 0;
  Floor* current = head;

  while (current != nullptr) {
    for (unsigned long i = 0; i < current->windows_number; ++i) {
      if (current->windows[i] == true) {
        total_open++;
      }
    }

    current = current->next;
  }

  return total_open;
}

Palazzo& Palazzo::operator%=(const Palazzo& p1) {
  if (this->floors_number != p1.floors_number) {
    return *this;  // Leave p unaltered
  }

  Floor* this_floor = this->head;
  Floor* other_floor = p1.head;

  while (this_floor != nullptr && other_floor != nullptr) {
    for (unsigned long i = 0; i < this_floor->windows_number; ++i) {
      if (other_floor->windows[i] == false) {
        this_floor->windows[i] = false;
      }
    }

    this_floor = this_floor->next;
    other_floor = other_floor->next;
  }

  return *this;
}