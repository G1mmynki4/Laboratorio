//Teoria pg 223
#include <iostream>
//Th = theory (per non confondere le funzioni con quelle in "vettori.h"
using namespace std;

void stampaTh(const int v[], int n){
    if(n!=0){
        cout << "[";
        for (int i = 0; i < n;i++)
            cout <<"'"<< v[i]<<"'";
        cout << "]" << endl;
    }
}

void scambiavettoreTh(int vettore[], int x, int y)
{
    int lavoro = vettore[x];
    vettore[x] = vettore[y];
    vettore[y] = lavoro;
}


void SelectionSortTh(int vet[], int n){
    int min;
    for (int i = 0; i < n - 1;i++){
        min = i;
        for (int j = i + 1; j < n;j++)
            if(vet[j]<vet[min])
                min = j;
        scambiavettoreTh(vet, i, min);
    }
}

int main(){
    int v[] = {2, 26, 8, 2, 23};
    SelectionSortTh(v, 5);
    stampaTh(v, 5);

    return 0;
}