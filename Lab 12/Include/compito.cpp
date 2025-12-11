#include <iostream>
#include "compito.h"

using namespace std;
//Private part
char PuzzleBobble::toChar(const eColor c) {
  switch (c) {
  case eColor::RED:
    return 'R';
    break;
  case eColor::GREEN:
    return 'G';
    break;
  case eColor::BLUE:
    return 'B';
    break;
  case eColor::YELLOW:
    return 'Y';
    break;
  default:
    return 'N';
    break;
  }
}

PuzzleBobble::eColor PuzzleBobble::toEnum(const char c) {
  switch (c) {
  case 'R':
    return eColor::RED;
    break;
  case 'G':
    return eColor::GREEN;
    break;
  case 'B':
    return eColor::BLUE;
    break;
  case 'Y':
    return eColor::YELLOW;
    break;
  default:
    return eColor::NONE;
    break;
  }
}

//Prima parte
PuzzleBobble::PuzzleBobble() {
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 6; ++j)
      mat[i][j] = eColor::NONE;
  }
}

ostream& operator<<(ostream& os, const PuzzleBobble& pb) {
  os<<"========"<<endl;
  for (int r = 0; r < 10; ++r) {
    os<<"|";
    for (int c = 0; c < 6; ++c) {
      if (pb.toChar(pb.mat[r][c]) == 'N')
        os<<" ";
      else
        os<<pb.toChar(pb.mat[r][c]);
    }
    os<<"|"<<endl;
  }
  os<<"========"<<endl;

  return os;
}

PuzzleBobble& PuzzleBobble::fire(int i, char color) {
  if (i>=0 && i<=5) {

    for (int r = 0; r < 10; ++r) {
      if (this->mat[r][i] == eColor::NONE) {
        this->mat[r][i] = toEnum(color);
        return *this;
      }

    }
  }
}

PuzzleBobble::operator int() const {
  int h;
  for (int r = 0; r < 10; r++) {
    for (int c = 0; c < 6; ++c)
      if (this->mat[r][c] != eColor::NONE) {
        ++h;
        break;
      }
  }
  return h;
}


//Seconda parte

