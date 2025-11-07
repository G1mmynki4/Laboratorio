#include <iostream>

using namespace std;

const int DIM = 6;

void componenti_negative(int* vector, int vDim, int* &hVector, int &hDim){
    hDim = 0;
    for (int i = 0; i < vDim; ++i)
        if(vector[i]<0)
            hDim ++;
    hVector = new int[hDim];

    int j = 0;
    for (int i = 0; i < vDim; ++i){
        if(vector[i]<0)
        {
            hVector[j] = vector[i];
            j++;
        }
    }
}

int main(){

    int vector[DIM];
    int *hVector = nullptr;
    int hDim;

    cout << "Inserisci valori interi nel vettore\n\n";
    for (int i = 0; i < DIM; ++i){
        cout << "Inserisci un numero [" << i + 1 << "/" << DIM << "]\n";
        cin >> vector[i];
    }

    cout << "\nVettore di partenza con componenti positive e negative:\n";
    cout << "{";
    for (int i = 0; i < DIM; ++i)
        cout <<vector[i] << ", ";
    cout << "}"<<endl;

    componenti_negative(vector, DIM, hVector, hDim);

    cout << "\nVettore dinamico con elementi negativi:\n";
    cout << "{";
    for (int i = 0; i < hDim; ++i)
        cout << hVector[i] << ", ";
    cout << "}"<<endl;

    cout << "\nDealloco vettore dinamico.\n";
    delete[] hVector;

    return 0;
}