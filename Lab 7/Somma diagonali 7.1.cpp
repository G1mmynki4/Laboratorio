#include <iostream>

using namespace std;

const int DIM = 4;

int somma_diag(const int mat[][DIM]){

  int somma;
  for (int i = 0; i < DIM; ++i)
    for (int j = 0; j < DIM; ++j)
      if ((j == i) || (j + i == DIM - 1)) // Diag principale = (j==i), Diag secondaria = (j+1==DIM-1)
        somma += mat[i][j];

  return somma;
}

void stampa_matrice(int mat[], int R, int C) {

    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
            cout << mat[r * C + c] << " "; // Le [] valgono da dereference
        cout << endl;
    }
}

int main(){
    int matrix[DIM][DIM], somma;
    int *p = &matrix[0][0];

    cout << "Inserisci 9 interi\n";
    for (int r = 0; r < DIM;++r){
        for (int c = 0; c < DIM; ++c)
            cin >> matrix[c][r];
    }

    somma = somma_diag(matrix);
    cout << "La somma degli elementi sulle diagonali vale: " << somma << endl;

    cout << "Matrice di partenza:\n";
    stampa_matrice(p, DIM, DIM);

    return 0;
}