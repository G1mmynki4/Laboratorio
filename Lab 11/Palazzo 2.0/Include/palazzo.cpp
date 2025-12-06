#include <iostream>
#include "palazzo.h"

using namespace std;

//Private functions
void Palazzo2::addToStruct(Floors*& elem){
    Floors *new_floor = new Floors;

    new_floor->floor = new bool[floors];
    new_floor->next = nullptr;

    Floors* node = elem;
    Floors *tmp = nullptr;

    while(node != nullptr){
        tmp = node;
        node = node->next;
    }
    tmp->next = new_floor;
}


//Public functions
Palazzo2::Palazzo2(int n){
    maxFloors = n;
    floors = 0;

    Floors *new_floor = new Floors;

    new_floor->floor = new bool[floors + 1];
    new_floor->floor[floors] = false;
    new_floor->next = nullptr;

    head = new_floor;

    ++floors;
}

Palazzo2::Palazzo2(Palazzo2& p){
    this->maxFloors = p.maxFloors;
    this->floors = p.floors;

    Floors *new_floor = new Floors;

    new_floor->floor = new bool[floors + 1];
    new_floor->floor[floors] = false;
    new_floor->next = nullptr;

    this->head = new_floor;

    for (int i = 0; i < this->floors; ++i)
        addToStruct(this->head);

    for (int i = 0; i < this->floors; ++i){
        if(p.head->floor[i])
            this->head->floor[i] = true;
        else
            this->head->floor[i] = false;
    }  

}

Palazzo2::~Palazzo2(){
    Floors* current = head;
    Floors* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next;

        delete[] current->floor;
        delete current;

        current = nextNode;
    }

    head = nullptr;
}

void Palazzo2::aggiungi(){
    if(floors < maxFloors){
        ++floors;
        addToStruct(head);

        for (int i = 0; i < floors; ++i)    //Chiudo tutte le finestre direttamente alla creazione del piano
            head->floor[i] = false;

    }

}

void Palazzo2::stampa(){
    cout << "<" << floors << ">" << endl;

    for (int i = 0; i < floors; ++i){
        cout << "Piano " << i + 1 << ": ";
        for (int j = 0; j <= i; ++j){
            if(head->floor[j])
                cout << "Aperta ";
            else
                cout << "Chiusa ";
        }
        cout << endl;
    }
}

//Seconda Parte (To be Implemented)