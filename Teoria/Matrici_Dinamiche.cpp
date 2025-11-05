#include <iostream>

using namespace std;

void allocaDinMatrice(int** &mat, int R, int C) {
  mat = new int *[R];
  for (int r=0; r<R;++r)
    mat[r] = new int[C];

}

void DeallocaDinMatrice(int** &mat, int R, int C) {
  for (int r=0; r<R;++r)
    delete[] mat[r];
  delete[] mat;
  mat=nullptr; //optional

}

void stampaDinMatrice(int** mat, int R, int C) {
  for (int r=0; r<R; ++r){
      for (int c = 0; c<C; ++c)
        cout<<mat[r][c];
      cout<<endl;
  }
}

void stampa_matrice(int mat[], int R, int C) {

  for (int r=0; r<R; r++){
    for (int c=0; c<C; c++)
      cout<<mat[ r*C + c ]<<" "; // Le [] valgono da dereference
    cout<<endl;
  }
}

void stampa_matrice(int** mat, int R, int C) {

  for (int r=0; r<R; r++){
    for (int c=0; c<C; c++)
      cout<<mat[ r*C + c ]<<" "; // Le [] valgono da dereference
    cout<<endl;
  }
}


int main() {
  int i=5, j=7, k=9;

  int**p = new int *; //alloca un puntatore senza nome sull'heap e ne restituisce l'indirizzo in p

  *p = &i;
  cout<<**p<<endl; //5
  delete p;
/*
  int**q = new int *[3]; //Vettore dinamico senza nome di 3 puntatori interi

  q[0] = &i;
  q[1] = &j;
  q[2] = &k;

  cout<<*q[0]<<endl; //5(i)
  cout<<*q[1]<<endl; //7(j)
  cout<<*q[2]<<endl; //9(k)

  cout<<*(q[0]+0)<<endl; //5(i)
  cout<<*(q[1]+0)<<endl; //7(j)
  cout<<*(q[2]+0)<<endl; //9(k)

  cout<<q[0][0]<<endl; //5(i)...
*/
  int nRighe = 3;
  int** q = new int*[nRighe]; //Alloco il direttorio
  for (int r=0; r<nRighe; ++r)
    q[r] = new int[r+1];

  int h = 1;
  for (int r=0; r<nRighe; ++r)
    for (int c = 0; c<=r; ++c)
      q[r][c] = ++h;

  for (int r=0; r<nRighe; ++r)
    delete[]q[r]; //Dealloco i singoli vettori riga senza nome

  delete[]q; //Dealloco il direttorio

  int** matrDin = nullptr;
  allocaDinMatrice(matrDin, 3, 4);

  int R = 5, C = 7;
  int* matrDinLinearizzata = new int[R*C];
  stampa_matrice(matrDinLinearizzata, R, C);

  delete[] matrDinLinearizzata;

  return 0;
}