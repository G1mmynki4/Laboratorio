#include "vettori.h"

void stampa(const int v[], int n){
  if(n!=0){
    cout << "[";
    for (int i = 0; i < n;i++)
      cout <<"'"<< v[i]<<"'";
    cout << "]" << endl;
  }
}

void scambiavettore(int vettore[], int x, int y)
{
  int lavoro = vettore[x];
  vettore[x] = vettore[y];
  vettore[y] = lavoro;
}

void SelectionSort(int vet[], int n){
  int min;
  for (int i = 0; i < n - 1;i++){
    min = i;
    for (int j = i + 1; j < n;j++)
      if(vet[j]<vet[min])
        min = j;
    scambiavettore(vet, i, min);
  }
}

void concatena(const int* v1, const int* v2, const int n1, const int n2, int* v3) {
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