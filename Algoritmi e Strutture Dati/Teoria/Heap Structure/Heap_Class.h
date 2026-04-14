#pragma once

class Heap{

    int *HeapVec;
    int dim;
    int last;           // Indice dell'ultimo elemento del vettore Heap;

    void up(int i);     // Indice dell'elemento da far risalire;
    void down(int i);   // Indice dell'elemento da far scendere;
    void swap(int i, int j);

public:
    Heap(int n): dim(n){

        HeapVec = new int[dim];
        last = -1;

    } // Inizializzo un array di dimensione n, imponendo come ultimo elemento dell'Heap quello inesistente, ovvero per convenzione -1;
;
    ~Heap();

    void Insert(int n); // Informazione da inserire;
    int Extract();     // Senza parametri visto che estraiamo la radice (elemento più grande);
};