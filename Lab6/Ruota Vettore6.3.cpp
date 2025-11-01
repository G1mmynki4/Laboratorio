#include <iostream>
#include "VectorLib/vettori.h"

using namespace std;

void ruotaVettoreExc(int v[], int s, int k){

    for (int i = 0; i < k; i++)
    {
        int ultimo = v[s-1];
        for (int j = s-1; j > 0; j--)
            v[j] = v[j - 1];

        v[0] = ultimo;
    }

}

int main(){

    const int SIZE = 10;
    int vector[SIZE], n=0;

    cout << "Inserisci elementi vettore\n";
    for (int i = 0; i < SIZE; i++){
        cout << "Inserisci un numero intero (" << i + 1 << ")\n";
        cin >> vector[i];
    }

    cout << "Inserisci numero di passi\n";
    cin >> n;

    ruotaVettoreExc(vector, SIZE, n);

    stampa(vector,SIZE);
    return 0;
}