#include <iostream>
using namespace std;

// Working on Arrays;

void heapSort(int *A, int size_A);
void buildHeap(int *A, int size_A);
void extract(int *A, int& last);

void swap(int* A, int i, int j){
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}


void down(int* A, int fath, int last){

    int son = 2 * fath + 1;
    if(son == last)
        if(A[son] > A[fath])
            swap(A, fath, last);
    
    if(son < last){
        if(A[son] < A[son + 1])
            ++son;

        if(A[son] > A[fath]){
            swap(A, fath, son);
            down(A, son, last);
        }
    }
}


void buildHeap(int* A, int size_A){
        for (int i = size_A / 2; i >= 0; --i) //Partiamo da metà array, ovvero dall'ultimo dei padri, l'altra metà sono FOGLIE,
        down(A, i, size_A);
}


void extract(int* A, int& last){

    swap(A, 0, last--); //  Porto la radice(n più grande) in ultima pos e diminuisco last(-- POSTFISSO) in modo da rimuovere
                        //  l'ultima casella dall'Heap;

    down(A, 0, last);   // Riordino la nuova radice;
}


void heapSort(int *A, int size_A){
    buildHeap(A, size_A - 1);

    int last = size_A - 1;

    while(last > 0) //Dopo aver creato l'Heap ordino "A" tramite la extract
        extract(A, last);
        
} // Complessità O(nlogn);


void printArray(const int*A, const int size_A){

    for (int i = 0; i < size_A; ++i)
        cout << A[i] << "\t";
    cout << endl;
}


int main(){

    int size;

    cout << "Inserisci dimensione array\n";
    cin >> size;

    int* A = new int[size];
    for (int i = 0; i < size; ++i){
        cout << "Inserisci dato: " << i + 1 << "/ " << size << endl;
        cin >> A[i];
    }

    printArray(A, size);
    heapSort(A, size);
    printArray(A, size);

    return 0;
}