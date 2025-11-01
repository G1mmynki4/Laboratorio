#include <iostream>
#include "VectorLib/vettori.h" //funzione stampa()

using namespace std;

void concatenaLab6(const int* v1, const int* v2, const int n1, const int n2, int* v3) {
  int j = 0;
  for (int i=0; i<n1; i++) {
    v3[j] = v1[i];
    ++j;
  }
  for (int k=0; k<n2; k++) {
    v3[j] = v2[k];
    ++j;
  }
}

int main() {
  int n1=5, n2=5, n3=n1+n2;

  int vec1[n1] = {0, 1, 2, 3, 4};
  int vec2[n2] = {5, 6, 7, 8, 9};
  int vec3[n3];

  concatenaLab6(vec1, vec2, n1, n2, vec3);
  stampa(vec3, n3);

  return 0;
}