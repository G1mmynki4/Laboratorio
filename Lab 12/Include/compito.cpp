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

PuzzleBobble& PuzzleBobble::fire(int col, char color) {
  //Check if the colon is valid
  if(col < 0 && col > 5)
    return *this;

  //Check if the color to fire is valid
  if (toEnum(color)==eColor::NONE && toEnum(color)==eColor::BLOCKED)
    return *this;

  //Check if there's enough space
  if(this->mat[9][col] != eColor::NONE)
    return *this;
  
  int row;
  for (row = 8; row >= maxHeight; --row) {
    if (this->mat[row][col] != eColor::NONE)
      break;
  }

  row++;
  this->mat[row][col] = toEnum(color);

  //Seconda parte
  int count = bubble_check(row, col, false);
  if(count >= 3)
    bubble_check(row, col, true);

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
int PuzzleBobble::bubble_check(int row, int col, bool isAdiac){
  int cont = 1;
  char color = toChar(mat[row][col]);

  if(isAdiac)
    mat[row][col] = eColor::NONE;

  //Check for adiac bubbles in height
  for (int i = row-1; i >= maxHeight; --i){
    if(toChar(this->mat[i][col]) == color){
      cont++;
      if (isAdiac)
        this->mat[i][col] = eColor::NONE;
    }
    else
      break;
  }

  //Check for adiac. bubbles to right
  for (int i = col + 1; i < 6; ++i){
    if(toChar(this->mat[row][i]) == color){
      cont++;
      if(isAdiac)
        this->mat[row][i] = eColor::NONE;
    }
    else
      break;
  }

  //Check for adiac. bubbles to left
  for (int i = col - 1; i >= 0; --i){
    if(toChar(this->mat[row][i]) == color){
      cont++;
      if(isAdiac)
        this->mat[row][i] = eColor::NONE;
    }
    else
      break;
  }

  return cont;
}

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

PuzzleBobble& PuzzleBobble::compact(){
  for (int r = maxHeight; r < 10; ++r)
    for (int c = 0; c < 6; ++c){

      if( r+1 >= 10 )
        break;

      if(this->mat[r][c] == eColor::NONE){
        this->mat[r][c] = this->mat[r + 1][c];
        this->mat[r + 1][c] = eColor::NONE;
      }
    }
  
  return *this;
}