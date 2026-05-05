#include <iostream>
using namespace std;

int f(int a){
  a *= 2;
  return a;
}

int main(){
  int n;
  n=2;

  int*p;
  p = &n;
  *p = 5;

  int& r=n;
  r = 9;

  int m = f(n);
  cout << n << " " << m << endl;
  int dim;
  cin >> dim;
  if(dim <= 0)
    dim = 3;
  int* q = new int[dim];

  for(int i = 0; i < dim; ++i)
    cin >> q[i];

  return 0;
}