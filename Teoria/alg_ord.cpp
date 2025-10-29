//Teoria pg 223
#include <iostream>

using namespace std;

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

int main(){
    int v[] = {2, 26, 8, 2, 23};
    SelectionSort(v, 5);
    stampa(v, 5);

    return 0;
}