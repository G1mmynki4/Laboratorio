#include "vettori.h"

void stampa(const int v[], int size){
  if(size!=0){
    cout << "[";
    for (int i = 0; i < size;i++)
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

void ruotaVettore(int v[], int size, int passi){

    for (int i = 0; i < passi; i++)
    {
        int ultimo = v[size-1];
        for (int j = size-1; j > 0; j--)
            v[j] = v[j - 1];

        v[0] = ultimo;
    }

}

void SelectionSort(int vet[], int size){
  int min;
  for (int i = 0; i < size - 1;i++){
    min = i;
    for (int j = i + 1; j < size;j++)
      if(vet[j]<vet[min])
        min = j;
    scambiavettore(vet, i, min);
  }
}

void concatena(const int* v1, const int* v2, const int size1, const int size2, int* v3) {
  int j = 0;
  for (int i=0; i<size1; i++) {
    v3[j] = v1[i];
    ++j;
  }
  for (int k=0; k<size2; k++) {
    v3[j] = v2[k];
    ++j;
  }
}