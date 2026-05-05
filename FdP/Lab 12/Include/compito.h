
#include <ostream>
using namespace std;

class PuzzleBobble {
  enum eColor {
    RED,    //0
    GREEN,  //1
    BLUE,   //2
    YELLOW, //3
    NONE,   //4
    BLOCKED //5
  };

  static char toChar(const eColor c);

  static eColor toEnum(const char c);

  int bubble_check(int rows, int cols, bool isAdiac); //Seconda parte

  eColor mat[10][6];

  int maxHeight;

public:
  //Prima parte
  PuzzleBobble();
  PuzzleBobble& fire(int i, char color);
  friend ostream &operator<<(ostream& os, const PuzzleBobble& pb);
  operator int() const;

  //Seconda parte
  PuzzleBobble &scroll();
  PuzzleBobble &compact();
};
