#include  <iostream>

namespace uno {
  int i = 2, j = 3;
}

namespace tre {
  int cout = 5;
}

int i = 3, j = 4; //Spazio globale


int main() {

  //int i= 5, j = 2;
  std::cout<<"Hello World"<<std::endl;
  tre::cout = 3;
  std::cout<<tre::cout<<std::endl;

  using namespace std;
  cout<<i<<endl;  //5
  cout<<::i<<endl;//3

  using uno::i;
  cout<<i<<endl; //2

}