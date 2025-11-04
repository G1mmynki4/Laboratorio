#include <iostream>

using namespace std;

void stampaMatrice3col(int M[][3], int R) {
  for (int r=0; r<R; ++r){
    for (int c=0; c<3; ++c)
      cout<<M[r][c]<<" ";
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

//RICORDA
//////////////////////////////////////////////////////////////////
////In memoria le colonne vengono memorizzate orizzontalmente////
////////////////////////////////////////////////////////////////

/*
int main() {
  const int R1 = 2;
  const int C1 = 3;

  int m1[2][3]= {{1,2,3},
                 {4,5,6}
                };  //Matrice 2 righe 3 colonne

  int m2[5][3]= {111, 222, 333, 444, 555, 0};

  m1[0][0] = 1;  //Altro metodo di definizione
  //cout<<m1[0][0];//11

  //int m[2][3] => int m[*][3]
  //stampaMatrice3col(m1, 2);
  //stampaMatrice3col(m2, 5);

  int* p = &m1[0][0];

  //for (int k=0; k<R1*C1; ++k)
  //  cout<<*(p+k)<<" ";
  stampa_matrice(p,R1, C1);
  return 0;
}*/

int main() {

  const int N = 5;
  int vett[N];

  vett[4] = 6;

  int len;
  cin>>len;

  int* vettDin; //punt int allocato sullo stack

  vettDin = new int[len]; //Creare un vettore senza nome in memoria dinamica tramite
                          //l'operatore "new"
  for (int i=0; i<len; ++i)
    vettDin[i] = i;
  for (int i = 0; i<len; ++i)
    cout<<vettDin[i];
  //...
  delete[] vettDin;     //Dealloca dalla memoria dinamica il vett senza nome
                        //allocato precedentemente

  return 0;
}