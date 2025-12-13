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
  case eColor::BLOCKED:
    return '=';
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

  maxHeight = 0;
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

    for (int r = maxHeight; r < 10; ++r) {
      if (this->mat[r][i] == eColor::NONE) {
        this->mat[r][i] = toEnum(color);
        return *this;
      }
    }
  }
  return *this;
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
/*
PuzzleBobble& PuzzleBobble::fire(int i, char color) {
  if (i>=0 && i<=5) {
    int count = 0; // add = 1;

    for (int r = maxHeight; r < 10; ++r) {
      if (this->mat[r][i] == eColor::NONE) {
        this->mat[r][i] = toEnum(color);
        //return *this;
      }

      for (int add = 1; add <= 5; ++add){
        if ((i + add) <= 5 && this->mat[r][i] == this->mat[r][i+add])
          count++;

        if ((i - add) >= 0 && this->mat[r][i] == this->mat[r][i-add])
          count++;

        if ((r - add) >= 0 && this->mat[r][i] == this->mat[r-add][i])
          count++;
      }
    }
  }
  return *this;
}
*/

PuzzleBobble& PuzzleBobble::scroll(){
  if(maxHeight < 10){
    
    for (int c = 0; c < 6; ++c)
      if (this->mat[9][c] != eColor::NONE)
        return *this;

    for (int r = 9; r > maxHeight; --r) {
      for (int c = 0; c < 6; ++c){

        if (this->mat[r - 1][c] != eColor::NONE){
          this->mat[r][c] = this->mat[r - 1][c];
          this->mat[r-1][c] = eColor::NONE;
        }
        
        if(r == (maxHeight + 1))
          this->mat[r-1][c] = eColor::BLOCKED;
      }
    }
    ++maxHeight;
    return *this;
  }
  return *this;
}
