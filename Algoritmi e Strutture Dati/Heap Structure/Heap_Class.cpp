#include <iostream>
#include "Heap_Class.h"

using namespace std;

////////////////////////////////
///   DEFINIZIONE DI HEAP   ///
//////////////////////////////
/*
    Albero Binario quasi bilanciato:
        -I nodi dell'ultimo livello addossati a SINISTRA;
        -In ogni SubTree l'etichetta della Root è >= a quella di TUTTI i discendenti

    Grazie a queste proprietà l'heap si può memorizzare in Array che rispettano il seguente schema di indici:
        -Figlio Sinistro: 2i + 1;
        -Figlio Destro:   2i - 1;
        -Padre:        (i-1) / 2;

    Su un Heap sono possibili le seguenti operazioni:
        -Inserimento di un nodo;
        -Estrazione dell'elemento maggiore, ovvero la radice;
*/

// Heap::Heap definito nella classe con lista di inizalizzazione;

Heap::~Heap(){
    delete[] HeapVec;

} // Non utilizzando puntatori basta semplicemente eliminare l'array per liberare correttamente la memoria;

void Heap::swap(int i, int j){

    int tmp = HeapVec[i];
    HeapVec[i] = HeapVec[j];
    HeapVec[j] = tmp;
}

void Heap::Insert(int inf){
    if(last > dim-2)
        return;

    HeapVec[++last] = inf; // Incremento prima last e poi inserisco l'informazione nell'ultimo posto dell'array heap;
    up(last);              // Chiamo la funzione di riordinamento per far risalire il nodo (se necessario);

} // Inserimento di un nodo in ultima posizione di deafault e riordinamento per risalita;

void Heap::up(int i){
    if(i > 0){
        int son = i;
        int father = (i - 1) / 2;

        if(HeapVec[son] > HeapVec[father]){ //Se inf di son > father allora il padre scende e il figlio sale;

            swap(son, father); // Scambio il nodo figlio con il padre;
            up(father);        // Richiamo la funzione sul nodo contente la nuova informazione;
        }
    }

} // La complessità è O(logn) perchè ogni chiamata sale di un livello;

int Heap::Extract(){
    int res = HeapVec[0]; // Restituisco la radice;

    HeapVec[0] = HeapVec[last--]; // Metto al primo posto l'ultimo elemento e decremento last, NOTA:(--postfisso);

    down(0); // Chiamo il riordinamento verso il basso per riposizionare correttamente la nuova radice;
    return res;

} // Tolgo la radice, la sostituisco con l'ultimo elemendo dell'Heap e riordino verso il basso la nuova radice;

void Heap::down(int i){

    int son = 2 * i + 1; // Figlio SINISTRO;

    if(son == last){ // Se ho non ho figlio DESTRO allora son è l'ultimo elemento del vettore;

        if(HeapVec[son] > HeapVec[i])
            swap(son, i);

    }else
        if(son < last){ //Vuol dire che allora esiste anche il figlio DESTRO

            if (HeapVec[son] < HeapVec[son + 1]) // Se è più grande DX allora prendiamo il suo indice(visto che il padre deve essere il più grande);
                ++son;

            if(HeapVec[son] > HeapVec[i]){
                swap(i, son);

                down(son); // Richiamo il riordinamento sul nuovo nodo (nel caso non avesse figli allora fallisce il primo if);
            }
        }
}// La complessità è O(log n)
